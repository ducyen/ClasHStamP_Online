import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.io.File;
import java.util.Arrays;

public class MainEntry extends JFrame {

    private static final long serialVersionUID = 1L;
    private JLabel imageLabel;
    private JPanel topPanel;
    private JComboBox<String> selectSampleBox;

    public MainEntry() {
        setTitle("Fullscreen Swing Application");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setExtendedState(JFrame.MAXIMIZED_BOTH);
        setUndecorated(true);

        topPanel = new JPanel(new BorderLayout());
        JPanel leftPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        JLabel sampleNameLabel = new JLabel("Sample Name");
        selectSampleBox = new JComboBox<>();
        populateSampleBox();
        JButton launchDiagramEditorButton = new JButton("Launch Diagram Editor");
        JLabel selectLanguageLabel = new JLabel("Select Language");
        JComboBox<String> selectLanguageBox = new JComboBox<>(new String[]{"C", "C++", "C#", "Java"});
        JButton generateCodeButton = new JButton("Generate Code");

        leftPanel.add(sampleNameLabel);
        leftPanel.add(selectSampleBox);
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
