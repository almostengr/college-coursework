
import javax.swing.*;
import java.awt.event.*;

public class ExampleJFrame2 {

    public static void main(String[] args) {
	JFrame frame = new JFrame("My Frame 2");

	frame.addWindowListener(new MyWindowListener( ));
	
	frame.setSize(200,200);	
	frame.setVisible(true);
    }
}


class MyWindowListener extends WindowAdapter {
        public void windowClosing (WindowEvent e) {
		 System.exit(0);
	}
}
