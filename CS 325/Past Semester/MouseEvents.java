import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MouseEvents extends JApplet {

    public void init () {
        getContentPane().add(new MyPanel());

        addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e) {
                showStatus("Mouse pressed");
                System.out.println("Mouse pressed: " + e);
            }
            public void mouseReleased(MouseEvent e) {
                showStatus("Mouse released");
                System.out.println("Mouse released: " + e);
            }
            public void mouseClicked(MouseEvent e) {
                showStatus("Mouse clicked");
                System.out.println("Mouse clicked: " + e);
            }
            public void mouseEntered(MouseEvent e) {
                showStatus("Mouse entered");
                System.out.println("Mouse entered: " + e);
            }
            public void mouseExited(MouseEvent e) {
                showStatus("Mouse exited");
                System.out.println("Mouse exited: " + e);
            }
        });

        addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseMoved(MouseEvent e) {
                showStatus("Mouse moved");
                System.out.println("Mouse moved: " + e);
            }
            public void mouseDragged(MouseEvent e) {
                showStatus("Mouse dragged");
                System.out.println("Mouse dragged: " + e);
            }
        });
    }
}

class MyPanel extends JPanel {

    public void paint (Graphics g) {
        g.drawRect(0,0,getWidth()-1,getHeight()-1);
        g.setFont(new Font("Monospaced",Font.BOLD,64));
        g.drawString ("Mouse events",10,100);
    }
}
