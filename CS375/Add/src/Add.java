import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.applet.*;

public class Add extends JApplet implements ActionListener {
  private JLabel lab1, lab2, lab3;
  private JTextField text1, text2, text3;
  private JButton b;

  public void init () {
    Container c=getContentPane();
    c.setLayout(new FlowLayout());
    lab1=new JLabel("Num1=");
    c.add(lab1);
    text1=new JTextField(4);
    c.add(text1);
    lab2=new JLabel("Num2=");
    c.add(lab2);
    text2=new JTextField(4);
    c.add(text2);
    b=new JButton("Add");
    c.add(b);
    lab3=new JLabel("Sum=");
    c.add(lab3);
    text3=new JTextField(5);
    c.add(text3);
    text3.setEditable(false);
    b.addActionListener(this);
  }

  public void actionPerformed (ActionEvent e) {
    int num1, num2, sum;
    try {num1=Integer.parseInt(text1.getText());}
      catch (Exception e1) {num1=0;}
    try {num2=Integer.parseInt(text2.getText());}
      catch (Exception e2) {num2=0;}
    sum=num1+num2;
    text3.setText(Integer.toString(sum));
  }
}
