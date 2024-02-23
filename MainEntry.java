import javax.swing.*;
import java.awt.*;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;

public class MainEntry extends JFrame {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JLabel imageLabel;
    private JPanel topPanel;

    public MainEntry() {
        setTitle("Fullscreen Swing Application");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setExtendedState(JFrame.MAXIMIZED_BOTH);
        setUndecorated(true);

        topPanel = new JPanel(new FlowLayout());
        JLabel sampleNameLabel = new JLabel("Sample Name");
        JComboBox<String> selectSampleBox = new JComboBox<>(new String[]{"Option 1", "Option 2", "Option 3"});
        JButton launchDiagramEditorButton = new JButton("Launch Diagram Editor");
        JLabel selectLanguageLabel = new JLabel("Select Language");
        JComboBox<String> selectLanguageBox = new JComboBox<>(new String[]{"C", "C++", "C#", "Java"});
        JButton generateCodeButton = new JButton("Generate Code");

        topPanel.add(sampleNameLabel);
        topPanel.add(selectSampleBox);
        topPanel.add(launchDiagramEditorButton);
        topPanel.add(selectLanguageLabel);
        topPanel.add(selectLanguageBox);
        topPanel.add(generateCodeButton);

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

    private void updateImage() {
        ImageIcon imageIcon = new ImageIcon("path/to/your/image.jpg"); // Replace with your image path
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
