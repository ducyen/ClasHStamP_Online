import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;

public class Main extends JFrame {

    private static final long serialVersionUID = 1L;
    private JTextArea outputTextArea;
    private JComboBox<String> selectSampleBox;
    private JComboBox<String> selectDiagramEditorBox;
    private JComboBox<String> selectLanguageBox;
    private JButton generateCodeButton;
    private JFrame bottomPanelFrame;
    private JScrollPane outputTextScrollPane;
    private ImageLoader imageLoader;
    private Rectangle screenSize;
    private Process xtermProcess;
    private long xtermPid = -1; // Initialize with an invalid PID


    public Main() {
        setTitle("Model Driven Development Tool");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(4, 2, 5, 5)); // 6 rows, 2 columns, 5px gaps

        // Get the maximum available screen bounds excluding taskbar and insets
        GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
        
        // Get the screen size        
        screenSize = ge.getMaximumWindowBounds();
        
        Timer timer = new Timer(1000, new ActionListener() {
            private Rectangle lastSize = GraphicsEnvironment.getLocalGraphicsEnvironment().getMaximumWindowBounds();

            @Override
            public void actionPerformed(ActionEvent e) {
            	screenSize = ge.getMaximumWindowBounds();
                if (!screenSize.equals(lastSize)) {
                    adjustLayout();
                    lastSize = screenSize;
                }
            }
        });
        timer.start();        
        
        JLabel sampleNameLabel = new JLabel("Sample Name");
        selectSampleBox = new JComboBox<>();
        populateSampleBox();

        selectDiagramEditorBox = new JComboBox<>(new String[]{"uml", "edu", "com"});

        JButton launchDiagramEditorButton = new JButton("Launch Diagram Editor");
        launchDiagramEditorButton.addActionListener(this::launchDiagramEditor);

        JLabel selectLanguageLabel = new JLabel("Select Language");
        selectLanguageBox = new JComboBox<>(new String[]{"C", "Cpp", "CSharp", "Java"});

        generateCodeButton = new JButton("Generate Code");
        generateCodeButton.addActionListener(this::generateCode);

        JButton startSimulatorButton = new JButton("Start Simulator");
        startSimulatorButton.addActionListener(this::startSimulator);

        add(sampleNameLabel);
        add(selectSampleBox);

        add(launchDiagramEditorButton);
        add(selectDiagramEditorBox);

        add(selectLanguageLabel);
        add(selectLanguageBox);
        
        add(generateCodeButton);
        add(startSimulatorButton);

        pack(); // Adjust the frame size to fit the components
        setLocationRelativeTo(null); // Center the frame
        setVisible(true);

        // Initialize the bottom panel frame
        bottomPanelFrame = new JFrame("Output");
        outputTextArea = new JTextArea();
        outputTextArea.setEditable(false);
        outputTextScrollPane = new JScrollPane(outputTextArea);
        outputTextScrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        outputTextScrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        bottomPanelFrame.add(outputTextScrollPane);
        bottomPanelFrame.setSize(800, 600); // Set the size of the bottom panel frame
        bottomPanelFrame.setLocationRelativeTo(null); // Center the bottom panel frame
        bottomPanelFrame.setVisible(true);
        
        adjustLayout();
        
        setAlwaysOnTop(true);
        
        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            if (xtermPid != -1) {
                Path pidFile = Paths.get("./xterm.pid");
                try {
                    Runtime.getRuntime().exec("pkill -P " + xtermPid);
                    Files.deleteIfExists(pidFile);
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
        }));        
    }


    private void populateSampleBox() {
        File samplesDir = new File("samples");
        File[] directories = samplesDir.listFiles(File::isDirectory);
        if (directories != null) {
            Arrays.sort(directories);
            for (File dir : directories) {
                selectSampleBox.addItem(dir.getName());
            }
        }
    }

    private void launchDiagramEditor(ActionEvent e) {
        JButton button = (JButton) e.getSource();
        button.setEnabled(false); // Disable the button

        // Launch the target application
        try {
            // Determine the OS and set the appropriate command
            String osName = System.getProperty("os.name").toLowerCase();
            Process process;
            String scriptPath = "./astah-" + selectDiagramEditorBox.getSelectedItem() + "/astah-run.sh";
            String filePath = "./samples/" + selectSampleBox.getSelectedItem() + "/Design.asta";
            if (osName.contains("windows")) {
                process = new ProcessBuilder("D:/cygwin64/bin/bash", "-c", scriptPath + " " + filePath).start();
            } else {
                process = new ProcessBuilder(scriptPath, filePath).start();
            }

            // Monitor the status of the launched application
            new Thread(() -> {
                try {
                    int exitCode = process.waitFor(); // Wait for the process to exit
                    if (exitCode == 0) {
                        // The application exited successfully
                        SwingUtilities.invokeLater(() -> button.setEnabled(true)); // Enable the button
                    }
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }
            }).start();

        } catch (IOException ex) {
            ex.printStackTrace();
            button.setEnabled(true); // Enable the button in case of an error
        }
    }

    private void generateCode(ActionEvent e) {
        JButton button = (JButton)e.getSource();
        button.setEnabled(false); // Disable the button
        outputTextArea.setText(""); // Clear the text area
        
        bottomPanelFrame.add(outputTextScrollPane);
        if (imageLoader != null) {
        	bottomPanelFrame.remove(imageLoader.getContentPane());
        }

        // Launch the target application
        try {
            String osName = System.getProperty("os.name").toLowerCase();
            Process process;
            String scriptPath = "./run_C.sh";
            String argument = (String)selectSampleBox.getSelectedItem();
            if (osName.contains("windows")) {
                process = new ProcessBuilder("D:/cygwin64/bin/bash", "-c", scriptPath + " " + argument).start();
            } else {
                process = new ProcessBuilder(scriptPath, argument).start();
            }                    

            // Read and display the error output in a separate thread
            BufferedReader errorReader = new BufferedReader(new InputStreamReader(process.getErrorStream()));
            new Thread(() -> {
                try {
                    String errorLine;
                    while ((errorLine = errorReader.readLine()) != null) {
                        final String finalErrorLine = errorLine;
                        SwingUtilities.invokeLater(() -> {
                            outputTextArea.append("Error: " + finalErrorLine + "\n");
                            outputTextArea.setCaretPosition(outputTextArea.getDocument().getLength());
                        });
                    }
                } catch (IOException e0) {
                    e0.printStackTrace();
                }
            }).start();

            // Read and display the output of the process
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            new Thread(() -> {
                try {
                    String line;
                    while ((line = reader.readLine()) != null) {
                        final String finalLine = line;
                        SwingUtilities.invokeLater(() -> {
                            outputTextArea.append(finalLine + "\n"); // Append to the text area
                            outputTextArea.setCaretPosition(outputTextArea.getDocument().getLength()); // Auto-scroll to the bottom
                        });
                    }
                } catch (IOException e0) {
                    e0.printStackTrace();
                }
            }).start();

            // Monitor the status of the launched application
            new Thread(() -> {
                try {
                    int exitCode = process.waitFor(); // Wait for the process to exit
                    if (exitCode == 0) {
                        SwingUtilities.invokeLater(() -> button.setEnabled(true)); // Enable the button
                    }
                } catch (InterruptedException e0) {
                    e0.printStackTrace();
                }
            }).start();

        } catch (IOException e1) {
            e1.printStackTrace();
            button.setEnabled(true); // Enable the button in case of an error
        }
    }
    
    private void startSimulator(ActionEvent e) {
        JButton button = (JButton)e.getSource();
        button.setEnabled(false); // Disable the button
        
        // Switch to the ImageLoader view in the bottom panel
        String directoryPath = "./samples/" + selectSampleBox.getSelectedItem() + "/TransImg";
        imageLoader = new ImageLoader(directoryPath);

        // Add the ImageLoader content to the bottom panel

        // Add the bottom panel to the new frame and make it visible
        bottomPanelFrame.remove(outputTextScrollPane);
        bottomPanelFrame.add(imageLoader.getContentPane());
        bottomPanelFrame.setVisible(true);

        // Calculate the size and position for the xterm console
        int consoleWidth = 80; // 80 characters
        int consoleHeight = 25; // 25 characters
        int xOff = Math.min(screenSize.width - getWidth(), screenSize.width - 80 * 6 - 24); // Horizontal offset
        int yOff = getHeight() + 24; // Vertical offset (top-right corner)
        
        // Start the external console application
        try {
            String osName = System.getProperty("os.name").toLowerCase();
            ProcessBuilder processBuilder;
            String scriptPath = "./start_xterm.sh";
            String geometry = consoleWidth + "x" + consoleHeight + "+" + xOff + "+" + yOff;
            String arguments = (String)selectSampleBox.getSelectedItem();
            if (osName.contains("windows")) {
                processBuilder = new ProcessBuilder("bash", "-c", scriptPath + " " + arguments + " " + geometry);
            } else {
            	processBuilder = new ProcessBuilder(scriptPath, arguments, geometry);
            }
            xtermProcess = processBuilder.start();

            // Wait for the PID file to be updated
            Path pidFile = Paths.get("./xterm.pid");
            String pidString = "";
            while (pidString.isEmpty()) {
                try {
                    Thread.sleep(100); // Wait for 100 milliseconds
                    if (Files.exists(pidFile)) {
                        pidString = Files.readAllLines(pidFile).get(0);
                    }
                } catch (InterruptedException e0) {
                    Thread.currentThread().interrupt(); // Restore the interrupted status
                    break;
                }
            }
            if (!pidString.isEmpty()) {
                xtermPid = Long.parseLong(pidString);
            }
            
            // Monitor the status of the launched application
            new Thread(() -> {
                try {
                    int exitCode = xtermProcess.waitFor(); // Wait for the process to exit
                    if (exitCode == 0) {
                        SwingUtilities.invokeLater(() -> button.setEnabled(true)); // Enable the button
                        Files.deleteIfExists(pidFile);
                    }
                } catch (InterruptedException | IOException e0) {
                    e0.printStackTrace();
                }
            }).start();
        } catch (IOException | NumberFormatException ex) {
            ex.printStackTrace();
            button.setEnabled(true); // Enable the button in case of an error
       }
    }
    
    private void adjustLayout() {
        int width = (int) (screenSize.width - getWidth());
        int height = screenSize.height;

        bottomPanelFrame.setSize(width, height);
        bottomPanelFrame.setLocation(0, 0);
        
        setLocation(width, 0);
    }
    
    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            MainEntry app = new MainEntry();
            app.setVisible(true);
        });
    }
}
