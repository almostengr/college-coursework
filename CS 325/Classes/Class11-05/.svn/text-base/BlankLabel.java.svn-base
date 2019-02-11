import java.awt.*;
import java.awt.event.*;		//for catching events

import javax.swing.*;
import javax.swing.event.*;	//for catching events

public class BlankLabel extends JLabel implements MouseMotionListener{
	
	Image offscreenImage;
	Graphics offscreen;
	
	public BlankLabel (Color color){
		setBackground(color);
		setOpaque(true);
		offscreenImage=createImage(500,500);

	}


	public void mouseDragged(MouseEvent e){
		/*System.out.println(e.getX() + ", " + e.getY());*/
		
		if(offscreenImage == null){
			offscreenImage = createImage(500,500);
		}
	
		offscreen = offscreenImage.getGraphics();
		offscreen.fillOval(e.getX(),e.getY(),10,10);
		repaint();
	}
	public void mouseMoved(MouseEvent e){
	}
	public void update(Graphics g){
		paint(g);
	}
	public void paint(Graphics g){	
		/*g.fillOval(50,50,50,50);*/
	
		g.drawImage(offscreenImage,0,0,this);
	}
}
