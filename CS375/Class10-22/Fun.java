import java.awt.*;
import javax.swing.*;

public class Fun extends JFrame implements Runnable {
	/*
	JFrame is an object that's inside of the swing.  Swing has the graphics objects (buttons, windows, etc)
	implements does the behavior that is not already done for us.  used threads. 
	*/
	
	int x; 

	public Fun(){
		//DEFAULT CONSTRUCTOR
		x=0;
	}

	public static void main(String args[]){
		//A STATIC METHOD CAN BE CALLED WITHOUT AN INSTANCE OF THE METHOD
		
		Fun f = new Fun();
		f.setSize(300,400);	//SIZE OF THE WINDOW
		f.setTitle("Hello!");	//SET THE TITLE WINDOW
		f.setVisible(true);	//PUTS THE WINDOW IN THE FRONT

		//f.run();
		
		Thread t = new Thread(f);	//CREATES A NEW THREAD
		t.start();
		System.out.println("This is after the thread");

		try{	
			Thread.sleep(500);	//SLOWS IT DOWN 
		}
		catch(Exception e){
		}
	}

	/*
	public void paint(Graphics g){
		//PRINTS OUT BLUE CIRCLE WITHIN WINDOW
		g.setColor(Color.blue);
		g.fillOval(x++,100,50,50);
		//OVAL POSITION, OVAL POSITION, SIZE, SIZE
		//x++ redraws the button as you adjust the window

		//g.setBackground(Color.green);
		//g.drawline(30,80,14,70);
	}
	*/

	public void update(Graphics g){
		//CHANGES WHEN AN EVENT HAPPENS
		paint(g);
	}



	/*DOUBLE BUFFERING*/
	public void paint(Graphics g){
		Image db = createImage(300,400);	//IMAGE BUFFER
		Graphics gb = db.getGraphics();		//GET GRAPHICS
		
		gb.setColor(Color.blue);
		gb.fillOval(x++,100,50,50);

		g.drawImage(db,0,0,300,400,this);
		//"THIS" REFERS TO THE CURRENT OBJECT

		x%=300;
	}

	public void run(){
		while(true){	
			repaint();
			
		}
	}
	
}
