import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class Example extends JFrame {
  public Example() {
    setTitle("Me");
    setSize(500,500);
    setVisible(true);

    GridBagLayout gbl = new GridBagLayout();
    setLayout(gbl);

    GridBagConstraints c = new GridBagConstraints();

    Rectangle hello = new Rectangle(Color.red,"Red");
    BigRectangle hi = new BigRectangle(Color.blue);

    c.fill = GridBagConstraints.HORIZONTAL;
    c.gridx = 0;
    c.gridy = 0;    
    add(hello, c);

    hello.addMouseListener(hello);

    c.gridx = 1;
    c.gridy = 0;
    Rectangle green = new Rectangle(Color.green, "Green");
    green.addMouseListener(green);
    add(green, c);

    c.gridx = 2;
    c.gridy = 0;
    Rectangle yellow = new Rectangle(Color.yellow, "Yellow");
    yellow.addMouseListener(yellow);
    add(yellow, c);

    c.gridx = 3;
    c.gridy = 0;
    add(new Rectangle(Color.orange, "Orange"), c);

    c.gridx = 0;    
    c.gridy = 1;
    c.gridwidth = 4;
    add(hi, c);

    pack(); 
  }

  public static void main(String args[]) {
    Example e = new Example();
  }
}

class Rectangle extends JLabel implements MouseListener {
 
  public Dimension minSize = new Dimension(100,100); 
  Color bg;
  String name;
  public Rectangle(Color c, String text) {
    super(text);
    bg = c;
    name = text;
  }
  public void paint(Graphics g) {
    g.setColor(bg);
    g.fillRect(0,0,(int) minSize.getWidth(), 
                   (int) minSize.getHeight());
  }
  public Dimension getMinimumSize() {
    return minSize;
  }

  public Dimension getPreferredSize() {
    return minSize;
  }
  public void mouseClicked(MouseEvent e) {
    System.out.println("You clicked " + name + " at " + 
            e.getX() + ", " + e.getY());
  }
  public void mouseEntered(MouseEvent e) {}
  public void mouseExited(MouseEvent e) {}
  public void mousePressed(MouseEvent e) {}
  public void mouseReleased(MouseEvent e) {}
}

class BigRectangle extends Rectangle {
  public BigRectangle(Color c) {
    super(c,"");
    minSize= new Dimension(400,400);
  }
}
