import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class MainEntry extends JFrame {

    private static final long serialVersionUID = 1L;
    private JLabel imageLabel;
    private JPanel topPanel;
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

        JLabel selectDiagramEditorLabel = new JLabel("Select Digram Editor");
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

                // Launch the target application
                try {
                    String osName = System.getProperty("os.name").toLowerCase();
                    Process process;
                    String scriptPath = "./samples/" + selectSampleBox.getSelectedItem() + "/run_" + selectLanguageBox.getSelectedItem() + ".sh " + selectSampleBox.getSelectedItem();
                    if (osName.contains("windows")) {
                        process = new ProcessBuilder("D:/cygwin64/bin/bash", "-c", scriptPath).start();
                    } else {
                        process = new ProcessBuilder(scriptPath).start();
                    }
                    
                    BufferedReader errorReader = new BufferedReader(new InputStreamReader(process.getErrorStream()));
                    
					// Read and display the error output in a separate thread
					new Thread(() -> {
					    try {
					        String errorLine;
					        while ((errorLine = errorReader.readLine()) != null) {
					            System.out.println("Error: " + errorLine + "\n");
					        }
					    } catch (IOException e0) {
					        e0.printStackTrace();
					    }
					}).start();                    

                    // Read and display the output of the process
                    BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
                    String line;
                    while ((line = reader.readLine()) != null) {
                        System.out.println(line);
                    }

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

        leftPanel.add(sampleNameLabel);
        leftPanel.add(selectSampleBox);
        leftPanel.add(selectDiagramEditorLabel);
        leftPanel.add(selectDiagramEditorBox);
        leftPanel.add(launchDiagramEditorButton);
        leftPanel.add(selectLanguageLabel);
        leftPanel.add(selectLanguageBox);
        leftPanel.add(generateCodeButton);

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

        JPanel bottomPanel = new JPanel(new BorderLayout());
        imageLabel = new JLabel();

        bottomPanel.add(imageLabel, BorderLayout.CENTER);

        add(topPanel, BorderLayout.NORTH);
        add(bottomPanel, BorderLayout.CENTER);

        addComponentListener(new ComponentAdapter() {
            @Override
            public void componentResized(ComponentEvent e) {
                updateImage();
            }
        });
    }

    private void populateSampleBox() {
        File samplesDir = new File("samples");
        File[] directories = samplesDir.listFiles(File::isDirectory);
        if (directories != null) {
            Arrays.sort(directories); // Sort directories alphabetically
            for (File dir : directories) {
                selectSampleBox.addItem(dir.getName());
            }
        }
    }

    private void updateImage() {
        ImageIcon imageIcon = new ImageIcon("D:/Workspace/EmuSense/ClasHStamP_online/samples/AllNotations/TransImg/Design/Model/ContextImpl/MainStm.png");
        Image image = imageIcon.getImage().getScaledInstance(getWidth(), getHeight() - topPanel.getHeight(), Image.SCALE_SMOOTH);
        imageLabel.setIcon(new ImageIcon(image));
    }

    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            MainEntry app = new MainEntry();
            app.setVisible(true);
        });
    }
}
