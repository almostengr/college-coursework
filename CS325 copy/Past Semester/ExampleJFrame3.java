
import javax.swing.*;
import java.awt.event.*;

public class ExampleJFrame3 {

    public static void main(String[] args) {
	JFrame frame = new JFrame("My Frame 3");

	frame.addWindowListener(new WindowAdapter () {
		public void windowClosing (WindowEvent e) {
		    System.exit(0);
		}
	    });
	
	frame.setSize(200,200);	
	frame.setVisible(true);
    }
}
