
import java.awt.*;
import javax.swing.*;

public class ExampleJLabel {

    public static void main(String[] args) {

	JFrame frame = new JFrame("JLabel example");
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	JPanel panel = (JPanel)frame.getContentPane();

	panel.setLayout(new GridLayout(2,3));
	
	panel.add(new JLabel("This is a label"));
	panel.add(new JLabel("Second label"));
	panel.add(new JLabel("Third label"));
	panel.add(new JLabel("Fourth label"));
	panel.add(new JLabel("Fifth label"));
	panel.add(new JLabel("This is the last label"));

	frame.pack();

	frame.setVisible(true);

    }

}
