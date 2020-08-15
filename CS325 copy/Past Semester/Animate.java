
import javax.swing.*;
import java.awt.*;

public class Animate {

    public static void main(String[] args) {
	JFrame frame = new JFrame("Animate");		//CREATES JFRAME
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	//SET
	
	AnimationPanel p = new AnimationPanel();
	p.setPreferredSize(new Dimension(300,200));	//SIZE OF THE ELEMENT
	p.setBackground(Color.yellow);	//SET THE BACKGROUND
	p.setForeground(Color.blue);		//

	frame.getContentPane().add(p);		//ADD ELEMETNS TO FRAME
	frame.pack();	//SHRINK THE WINDOW TO IT'S CONTENTS
	frame.setVisible(true);	//BRING THE WINDOW TO THE FRONT 

	Thread t = new Thread(p);	//CREATE A NEW THREAD 
	t.start();	//START NEW THREAD 
    }
}


class AnimationPanel extends Panel implements Runnable {
	private int x, y, oldx, oldy, diameter=25, xdelta=4, ydelta=3;

	public void paint (Graphics g) {
		g.setColor(getBackground());
		g.fillOval(oldx,oldy,diameter,diameter);
		g.setColor(getForeground());
		g.fillOval(x,y,diameter,diameter);
	}

	public void update (Graphics g) {
		paint(g);	///REDRAWS THE PICTURE 
	}

	public void run () {
		int w=getSize().width;
		int h=getSize().height;
		while (true) {
			repaint();	//REDRAWS THE PICTURE
			try {Thread.sleep(10);}	//SLOWS DOWN THE REDRAWING OF THE ANIMATION
			catch (Exception e) {}
			oldx=x;
			x+=xdelta;
			if (x<0) {x=0; xdelta=-xdelta;}
			if (x>w-diameter) {x=w-diameter; xdelta=-xdelta;}
			oldy=y;
			y+=ydelta;
			if (y<0) {y=0; ydelta=-ydelta;}
			if (y>h-diameter) {y=h-diameter; ydelta=-ydelta;}
		}
	}
}
