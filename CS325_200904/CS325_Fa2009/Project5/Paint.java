import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import javax.swing.event.*;


public class Paint extends JFrame{

	/**
	 * @param args
	 */
	
	
	public Paint(){
			setTitle("Project 5 Paint - Kenneth Robison");
			setSize(600, 600);
			setVisible(true);
			setBackground(Color.white);
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			
			GridBagLayout gbl = new GridBagLayout();
			setLayout(gbl);
			GridBagConstraints c = new GridBagConstraints();
			
			c.fill = GridBagConstraints.HORIZONTAL;


			c.gridx = 0;
			c.gridy = 0;
			ToolBox toolSelector = new ToolBox();
			toolSelector.addMouseMotionListener(toolSelector);
			add(toolSelector,c);

			c.gridx = 1;
			c.gridy = 0;
			//DrawingCanvas canvas;
			DrawingCanvas canvas = new DrawingCanvas(Color.white);
			canvas.addMouseMotionListener(canvas);
			add(canvas,c);
		
			c.gridx = 0;
			c.gridy = 1;
			CurrentColor colorSelected = new CurrentColor(Color.black);
			//colorSelected.addMouseMotionListener(colorSelected);
			add(colorSelected,c);
		
			c.gridx = 1;
			c.gridy = 1;
			
			
			//pack(); 
			
	}
	
	
	
	public static void main(String[] args) {
		Paint paintIt = new Paint(); 
	}
}

class Rectangle extends JLabel implements MouseListener{
	public Dimension minSize = new Dimension(100,100);
	Color bg;
	String name;
	public Rectangle(Color c, String text){
		super(text);
		bg = c;
		name = text;
	}
	
	public void paint(Graphics g){
		g.setColor(bg);
		g.fillRect(0, 0, (int) minSize.getWidth(), (int) minSize.getHeight());
	}
	public Dimension getMinimumSize(){
		return minSize;
	}
	public Dimension getPreferredSize(){
		return minSize;
	}

	public void mouseClicked(MouseEvent e){
		System.out.println("You clicked " + name + " at " + e.getX() + ", " + e.getY());
	}
	public void mouseEntered(MouseEvent e){
	}
	public void mouseExited(MouseEvent e){
	}
	public void mousePressed(MouseEvent e){
	}
	public void mouseReleased(MouseEvent e){
	}
}

class ToolBox extends JPanel implements MouseMotionListener{
	public ToolBox(){
		//super(Color.black,"");
		//minSize = new Dimension(100,400);		
		setBackground(Color.black);
	}
	
	public void mouseClicked(MouseEvent e){
	}	
	public void mouseEntered(MouseEvent e){
	}
	public void mouseExited(MouseEvent e){	
	}
	public void mousePressed(MouseEvent e){
	}
	public void mouseReleased(MouseEvent e){
	}
	public void mouseDragged(MouseEvent e){
	}
	public void mouseMoved(MouseEvent e){
	}

}

class CurrentColor extends JLabel{
	Color bg;

	public CurrentColor(Color c){
		bg = c;
	}
		
	public void paint(Graphics g){
		g.setColor(bg);
	}
	
}


class ColorPalette extends JPanel{
	LayoutManager colorLayout = new GridLayout(2,5);
	//setLayout(colorLayout);

	//add new(fillRect(10,10,Color.red));
	
}

class ColorPaletteButton extends JLabel implements MouseMotionListener{
	
	public void mouseClicked(MouseEvent e){
	}	
	public void mouseEntered(MouseEvent e){
	}
	public void mouseExited(MouseEvent e){	
	}
	public void mousePressed(MouseEvent e){
	}
	public void mouseReleased(MouseEvent e){
	}
	public void mouseDragged(MouseEvent e){
	}
	public void mouseMoved(MouseEvent e){
	}
	
}

class DrawingCanvas extends JLabel implements MouseMotionListener{
	
	Image offscreenImage;
	Graphics offscreen;
	
	public DrawingCanvas (Color color){
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
