package TransImg;

import java.nio.file.attribute.BasicFileAttributes;
import java.nio.file.FileVisitResult;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.SimpleFileVisitor;
import java.nio.file.WatchService;
import java.nio.file.WatchEvent;
import java.nio.file.WatchKey;
import java.nio.file.StandardWatchEventKinds;
import java.nio.file.FileSystems;
import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class ImageLoader extends JFrame {

    /**
	 * serialVersionUID
	 */
	private static final long serialVersionUID = 1L;
    private final String directoryPath;
    private Map<WatchKey, Path> keyPathMap;

    public ImageLoader(String directoryPath) {
        this.directoryPath = directoryPath;
        keyPathMap = new HashMap<>();
        initUI();
        updatePanelImages();
        startDirectoryWatchService();
    }

	private void initUI() {
		setTitle("Image Viewer");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		imagePanel = new JPanel(new FlowLayout(FlowLayout.LEFT));

		JScrollPane scrollPane = new JScrollPane(imagePanel);
		scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);

		add(scrollPane);

		setSize(800, 600);
		setLocationRelativeTo(null);
	}

	private JPanel imagePanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
	private void loadImagesFromDirectoryRecursively(File directory) {
		File[] files = directory.listFiles();
		if (files != null) {
			for (File file : files) {
				if (file.isDirectory()) {
					loadImagesFromDirectoryRecursively(file);
				} else if (file.getName().toLowerCase().endsWith(".png")) {
					try {
						//System.out.println("Loading image: " + file.getAbsolutePath()); // Debugging
						BufferedImage image = ImageIO.read(file);
						if (image != null) {
							JLabel oldLabel = null;
							for (Component component: imagePanel.getComponents()) {
								System.out.println("Checking " + component.getName() + " in " + Thread.currentThread().getId());
								if (component instanceof JLabel) {
									JLabel label = (JLabel)component;
									if (label.getName().compareToIgnoreCase(file.getAbsolutePath()) == 0) {
										oldLabel = label;
										break;
									}
								}
							}
							int newWidth = image.getWidth() * 90 / 100;
							int newHeight = image.getHeight() * 90 / 100;
							if (file.getAbsolutePath().contains("Visualized_")) {
								newWidth = 400;
								newHeight = 400;
							}
							BufferedImage scaledImage = new BufferedImage(newWidth, newHeight, BufferedImage.TYPE_INT_RGB);
							Graphics2D graphics = scaledImage.createGraphics();
							graphics.drawImage(image, 0, 0, newWidth, newHeight, null);
							graphics.dispose();									
							if (oldLabel == null) {
								System.out.println("Add label: " + file.getAbsolutePath()); // Debugging
								JLabel newLabel = new JLabel(new ImageIcon(scaledImage));
								newLabel.setName(file.getAbsolutePath());
								imagePanel.add(newLabel);
							} else {
								oldLabel.setIcon(new ImageIcon(scaledImage));
							}
						}
					} catch (IOException e) {
						System.err.println("Failed to load image: " + file.getAbsolutePath()); // Debugging
						e.printStackTrace();
					}
				}
			}
		}
	}
	
	private void updatePanelImages() {
		loadImagesFromDirectoryRecursively(new File(directoryPath));

		// Refresh the layout
		imagePanel.revalidate();
		imagePanel.repaint();
	}

	private Thread watchThread;
    private void startDirectoryWatchService() {
    	if (watchThread == null) {
	        watchThread = new Thread(() -> {
	            try (WatchService watchService = FileSystems.getDefault().newWatchService()) {
	                Path path = Paths.get(directoryPath);
	                registerAll(path, watchService);
	                
	                while (true) {
	                    WatchKey key;
	                    try {
	                        key = watchService.take();
	                    } catch (InterruptedException x) {
	                        return;
	                    }
	
	                    Path dir = keyPathMap.get(key);
	                    for (WatchEvent<?> event : key.pollEvents()) {
	                        WatchEvent.Kind<?> kind = event.kind();
	
	                        if (kind == StandardWatchEventKinds.OVERFLOW) {
	                            continue;
	                        }
	
	                        // Context for directory entry event is the file name of entry
							@SuppressWarnings("unchecked")
							WatchEvent<Path> ev = (WatchEvent<Path>) event;
	                        Path name = ev.context();
	                        Path child = dir.resolve(name);
	
	                        if (child.toString().endsWith(".png")) {
	                        	System.out.println("SwingUtilities.invokeLater(this::updatePanelImages) in thread " + Thread.currentThread().getId() );
	                            SwingUtilities.invokeLater(this::updatePanelImages);
	                        }
	
	                        if (Files.isDirectory(child)) {
	                            registerAll(child, watchService);
	                        }
	                    }
	
	                    boolean valid = key.reset();
	                    if (!valid) {
	                        keyPathMap.remove(key);
	                        if (keyPathMap.isEmpty()) {
	                            break;
	                        }
	                    }
	                }
	            } catch (IOException ex) {
	                ex.printStackTrace();
	            }
	        });
    	}
        watchThread.start();
    }

    private void registerAll(final Path start, final WatchService watcher) throws IOException {
        Files.walkFileTree(start, new SimpleFileVisitor<Path>() {
            @Override
            public FileVisitResult preVisitDirectory(Path dir, BasicFileAttributes attrs) throws IOException {
                WatchKey key = dir.register(watcher, StandardWatchEventKinds.ENTRY_CREATE,
                        StandardWatchEventKinds.ENTRY_DELETE, StandardWatchEventKinds.ENTRY_MODIFY);
                keyPathMap.put(key, dir);
                return FileVisitResult.CONTINUE;
            }
        });
    }

    public static void main(String[] args) {
    	if (args.length == 0) {
    		System.out.println("usage: java ImageLoader path/to/TransImg");
    		return;
    	}
        EventQueue.invokeLater(() -> {
            String directoryPath = args[0]; // Replace with your directory path
            ImageLoader frame = new ImageLoader(directoryPath);
            frame.setVisible(true);
        });
    }
}



