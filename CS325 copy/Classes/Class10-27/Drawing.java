import java.awt.*;
import javax.swing.*;

public class Drawing extends JFrame {
	static int WIDTH = 500;
	static int HEIGHT = 500;

	int x = 0, y = 0;
	
	class CircleThread extends Thread{
	/*IS A SUB CLASS OF A A THREAD */

		public void run(){
			int dir = 1;	//direction variable
			
			while(true){
				/*increment x value*/

				x += dir;

				if (x > WIDTH || x < 0){
					dir *= -1;
				}
				
				repaint();	//AUTOMATIC REDRAWS WITHOUT HAVING TO RESIZE SCREEN

				try{
				Thread.sleep(100);
				}catch (Exception e){ }

			}
		}
	}

	class SquareThread extends Thread{
	/*IS A SUB CLASS OF A A THREAD */

		public void run(){
			int dir = 1;	//direction variable
			
			while(true){
				/*increment x value*/

				y += dir;

				if (y > WIDTH || y < 0){
					dir *= -1;
				}
				
				repaint();	//AUTOMATIC REDRAWS WITHOUT HAVING TO RESIZE SCREEN

				try{
				Thread.sleep(100);
				}catch (Exception e){ }

			}
		}
	}

	public static void main(String args[]){
		Drawing d = new Drawing();
		d.setSize(WIDTH, HEIGHT);
		d.setTitle("Hello there I'm drawing!");
		d.setVisible(true);
	}
	
	public Drawing(){
		/*instance of the thread*/
		//CircleThread circle = new CircleThread();	
		//circle.start();	

		Thread circle = new Thread(){
		//class that was runnable
		//thread is an abstract class	
			public void run(){
			int dir = 1;	//direction variable
			
			while(true){
				/*increment x value*/

				y += dir;

				if (y > WIDTH || y < 0){
					dir *= -1;
				}
				
				repaint();	//AUTOMATIC REDRAWS WITHOUT HAVING TO RESIZE SCREEN

				try{
				Thread.sleep(100);
				}catch (Exception e){ }

			}
		}

		};

		circle.start();
		/*or could wrap entire function in thread and then the .start();
		
		( this is the code ).start();
		*/


		SquareThread square = new SquareThread();	
		square.start();	
	}


	public void paint(Graphics g){
		
		/*DOUBLE BUFFER*/	
		Image offscreen = createImage(WIDTH, HEIGHT);
		Graphics buffer = offscreen.getGraphics();
		
		/*DRAW CIRCLE*/
		buffer.setColor(Color.blue);
		buffer.fillOval(x, 100, 50, 50);
	
		/*DRAW RECTANGLE*/
		buffer.setColor(Color.red);	
		buffer.fillRect(300, y, 50, 50);

		/*DRAW IMAGE TO SCREEN*/
		g.drawImage(offscreen,0,0,WIDTH,HEIGHT,this);
	
	}

	public void update(Graphics g){
		paint(g);
	}
}
