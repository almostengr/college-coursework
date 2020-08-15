
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class ExampleJPanel {

    public static void main(String[] args) {
	JFrame frame = new JFrame("JPanel example");
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	JPanel p0 = new JPanel();
	p0.setBackground(Color.blue);
	p0.setPreferredSize(new Dimension(30,30));

	JPanel p1 = new JPanel();
	p1.setBackground(Color.green);
	p1.setPreferredSize(new Dimension(30,30));

	JPanel p2 = new JPanel();
	p2.setPreferredSize(new Dimension(90,50));
	p2.setBackground(Color.red);
	p2.add(p0);
	p2.add(p1);

	JPanel p3 = new JPanel();
	p3.setBackground(Color.cyan);
	p3.setPreferredSize(new Dimension(30,30));

	JPanel p4 = new JPanel();
	p4.setBackground(Color.magenta);
	p4.setPreferredSize(new Dimension(30,30));

	JPanel p5 = new JPanel();
	p5.setPreferredSize(new Dimension(90,50));
	p5.setBackground(Color.yellow);
	p5.add(p3);
	p5.add(p4);

	JPanel p6 = new JPanel();
	p6.setBackground(Color.orange);
	p6.setPreferredSize(new Dimension(30,30));

	JPanel p7 = new JPanel();
	p7.setBackground(Color.black);
	p7.setPreferredSize(new Dimension(30,30));

	JPanel p8 = new JPanel();
	p8.setBackground(Color.pink);
	p8.setPreferredSize(new Dimension(30,30));

	JPanel p9 = new JPanel();
	p9.setPreferredSize(new Dimension(90,90));
	p9.setBackground(Color.white);
	p9.add(p6);
	p9.add(p7);
	p9.add(p8);

	Container c = frame.getContentPane();
	c.setLayout(new FlowLayout());
	c.setPreferredSize(new Dimension(200,200));
	c.setBackground(Color.gray);
	c.add(p2);
	c.add(p5);
	c.add(p9);

       	frame.pack();	
	frame.setVisible(true);
    }
}
