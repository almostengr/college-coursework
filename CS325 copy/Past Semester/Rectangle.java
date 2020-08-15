
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class Rectangle {

    public static void main(String[ ] args) {
        final JFrame frame = new JFrame("Rectangle");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        final MyComponent picture = new MyComponent( );
        picture.setPreferredSize(new Dimension(401,401));

        JPanel controls = new JPanel( );
        controls.setLayout(new FlowLayout( ));

        controls.add(new JLabel("Width:", JLabel.RIGHT));
        final JTextField width = new JTextField("0",3);
        controls.add(width);

        controls.add(new JLabel("Height:", JLabel.RIGHT));
        final JTextField height = new JTextField("0",3);
        controls.add(height);

        JPanel content = (JPanel)frame.getContentPane( );
        content.setLayout(new BorderLayout( ));
        content.add(picture, BorderLayout.CENTER);
        content.add(controls, BorderLayout.SOUTH);

        ActionListener action = new ActionListener( ) {
            public void actionPerformed(ActionEvent evt) {
                int w=Integer.parseInt(width.getText( ));
                int h=Integer.parseInt(height.getText( ));
                picture.draw(w,h);
            }
        };

        height.addActionListener(action);
        width.addActionListener(action);

        frame.pack( );
        frame.setVisible(true);
    }
}

class MyComponent extends JComponent {

    private int width=0, height=0;

    public void draw(int w, int h) {
        width=w; height=h;
	repaint( ); 
    }

    public void paintComponent(Graphics g) {
	g.setColor(Color.green);
        g.fillRect(0, 0, width, height);
	g.setColor(Color.magenta);
	for (int k=0; k<=4; k++) {
        	g.drawLine(0,100*k,400,100*k);
		g.drawLine(100*k,0,100*k,400);
	}
    }
}
