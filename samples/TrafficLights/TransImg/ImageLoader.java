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
import java.nio.file.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class ImageLoader extends JFrame {

    private ArrayList<BufferedImage> images;
    private JPanel panel;
    private final String directoryPath;
    private Map<WatchKey, Path> keyPathMap;

    public ImageLoader(String directoryPath) {
        this.directoryPath = directoryPath;
        images = new ArrayList<>();
        keyPathMap = new HashMap<>();
        initUI();
        startDirectoryWatchService();
    }

    private void loadImagesFromDirectory(File directory) {
        File[] files = directory.listFiles();
        if (files != null) {
            for (File file : files) {
                if (file.isDirectory()) {
                    loadImagesFromDirectory(file);
                } else if (file.getName().endsWith(".png")) {
                    try {
                        BufferedImage image = ImageIO.read(file);
                        if (image != null) {
                            images.add(image);
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    private void initUI() {
        setTitle("Image Viewer");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        panel = new DoubleBufferedPanel();
        panel.setLayout(new FlowLayout(FlowLayout.LEFT));
        updatePanelImages();

        JScrollPane scrollPane = new JScrollPane(panel);
        scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);

        add(scrollPane);

        setSize(800, 600);
        setLocationRelativeTo(null);
    }

    // Custom JPanel with double buffering
    private class DoubleBufferedPanel extends JPanel {
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            // Custom painting code here if needed
        }

        public DoubleBufferedPanel() {
            super(true); // Enable double buffering
        }
    }


	private void updatePanelImages() {
		// Clear existing images from the list
		images.clear();

		// Remove all components from the panel
		panel.removeAll();

		// Reload images from the directory
		loadImagesFromDirectory(new File(directoryPath));

		// Add reloaded images to the panel
		for (BufferedImage image : images) {
			JLabel label = new JLabel(new ImageIcon(image));
			panel.add(label);
		}

		// Refresh the panel to show updated images
		panel.revalidate();
		panel.repaint();
	}

    private void startDirectoryWatchService() {
        Thread watchThread = new Thread(() -> {
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
                        WatchEvent<Path> ev = (WatchEvent<Path>) event;
                        Path name = ev.context();
                        Path child = dir.resolve(name);

                        if (child.toString().endsWith(".png")) {
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
        EventQueue.invokeLater(() -> {
            String directoryPath = "Design"; // Replace with your directory path
            ImageLoader frame = new ImageLoader(directoryPath);
            frame.setVisible(true);
        });
    }
}
