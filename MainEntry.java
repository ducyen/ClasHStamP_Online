import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class MainEntry extends JFrame {

    private static final long serialVersionUID = 1L;
    private JTextArea outputTextArea;
    private JPanel topPanel;
    private JPanel bottomPanel;
    private JScrollPane scrollPane;
    private ImageLoader imageLoader;
    private JComboBox<String> selectSampleBox;

    public MainEntry() {
        setTitle("Model Driven Development Tool");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setExtendedState(JFrame.MAXIMIZED_BOTH);
        setUndecorated(true);

        topPanel = new JPanel(new BorderLayout());
        JPanel leftPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        JLabel sampleNameLabel = new JLabel("Sample Name");
        selectSampleBox = new JComboBox<>();
        populateSampleBox();

        JLabel selectDiagramEditorLabel = new JLabel("Select Diagram Editor");
        JComboBox<String> selectDiagramEditorBox = new JComboBox<>(new String[]{"edu", "com"});

        JButton launchDiagramEditorButton = new JButton("Launch Diagram Editor");
        launchDiagramEditorButton.addActionListener(new ActionListener() {
            private final JButton button = launchDiagramEditorButton;
            @Override
            public void actionPerformed(ActionEvent e) {
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
                                button.setEnabled(true); // Enable the button
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
        });

        JLabel selectLanguageLabel = new JLabel("Select Language");
        JComboBox<String> selectLanguageBox = new JComboBox<>(new String[]{"C", "Cpp", "CSharp", "Java"});
        JButton generateCodeButton = new JButton("Generate Code");
        generateCodeButton.addActionListener(new ActionListener() {
            private final JButton button = generateCodeButton;
            @Override
            public void actionPerformed(ActionEvent e) {
                button.setEnabled(false); // Disable the button
                outputTextArea.setText(""); // Clear the text area

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
                                button.setEnabled(true); // Enable the button
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
        });

        JButton startSimulatorButton = new JButton("Start Simulator");
        startSimulatorButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String directoryPath = "./samples/" + selectSampleBox.getSelectedItem() +"/TransImg";
                imageLoader = new ImageLoader(directoryPath);
                
                bottomPanel.removeAll();
                bottomPanel.add(imageLoader.getContentPane());
                bottomPanel.revalidate();
                bottomPanel.repaint();

                // Start the external console application
                try {
                    String osName = System.getProperty("os.name").toLowerCase();
                    ProcessBuilder process;
                    String scriptPath = "./start_xterm.sh";
                    String arguments = (String)selectSampleBox.getSelectedItem();
                    if (osName.contains("windows")) {
                        process = new ProcessBuilder("D:/cygwin64/bin/bash", "-c", scriptPath + " " + arguments);
                    } else {
                        process = new ProcessBuilder(scriptPath, arguments);
                    }
                    process.start();
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
        });

        leftPanel.add(sampleNameLabel);
        leftPanel.add(selectSampleBox);
        leftPanel.add(selectDiagramEditorLabel);
        leftPanel.add(selectDiagramEditorBox);
        leftPanel.add(launchDiagramEditorButton);
        leftPanel.add(selectLanguageLabel);
        leftPanel.add(selectLanguageBox);
        leftPanel.add(generateCodeButton);
        leftPanel.add(startSimulatorButton);

        JButton quitButton = new JButton("Quit");
        quitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        JPanel rightPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        rightPanel.add(quitButton);

        topPanel.add(leftPanel, BorderLayout.WEST);
        topPanel.add(rightPanel, BorderLayout.EAST);

        outputTextArea = new JTextArea();
        outputTextArea.setEditable(false);
        scrollPane = new JScrollPane(outputTextArea);
        scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);

        bottomPanel = new JPanel(new BorderLayout());
        bottomPanel.add(scrollPane, BorderLayout.CENTER);

        add(topPanel, BorderLayout.NORTH);
        add(bottomPanel, BorderLayout.CENTER);
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

    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            MainEntry app = new MainEntry();
            app.setVisible(true);
        });
    }
}
