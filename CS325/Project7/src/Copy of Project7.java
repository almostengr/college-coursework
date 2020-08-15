import java.awt.*;
import java.awt.event.*;
import java.util.Random;
import javax.swing.*;
import javax.swing.event.*;

class Global{
	//GLOBAL CLASS FOR ALL OBJECTS

		public static Image offScreenBuffer;
		public static Graphics displayOnScreen;
		public static int fruitFallingx;
}


public class Project7 extends JFrame{
	static int widthOfWindow = 500, heightOfWindow = 500;

	public Project7(){
		setTitle("Project 7");
		setSize(500,500);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBackground(Color.black);
	}


	static int y=0; static int y2=0;
	int xVariable01=0, xVariable02=0, xVariable03=0, xVariable04=0;
	int xVariable05=0, xVariable06=0, xVariable07=0, xVariable08=0;
	int xVariable01a=0, xVariable02a=0, xVariable03a=0, xVariable04a=0;
	int xVariable05a=0, xVariable06a=0, xVariable07a=0, xVariable08a=0;
	int yVariable01=0, yVariable02=0, yVariable03=0, yVariable04=0;
	int yVariable05=0, yVariable06=0, yVariable07=0, yVariable08=0;
	

	public void paint(Graphics g){
		if(y==0){
			Random randomXLocation = new Random();
			//GENERATES RANDOM X VARIABLE FOR FRUIT DROPING

			xVariable01 = randomXLocation.nextInt(widthOfWindow-1);
			xVariable02 = randomXLocation.nextInt(widthOfWindow-1);
			xVariable03 = randomXLocation.nextInt(widthOfWindow-1);
			xVariable04 = randomXLocation.nextInt(widthOfWindow-1);
			xVariable05 = randomXLocation.nextInt(widthOfWindow-1);
			xVariable06 = randomXLocation.nextInt(widthOfWindow-1);
			xVariable07 = randomXLocation.nextInt(widthOfWindow-1);
			xVariable08 = randomXLocation.nextInt(widthOfWindow-1);				
		}

		Global.offScreenBuffer = createImage(500,500);
		Global.displayOnScreen = Global.offScreenBuffer.getGraphics();
		
		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable01,(yVariable01++)*2,20,20);
		
		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable02,(yVariable02++)+10,20,20);
		
		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable03,(yVariable03++)+5,20,20);
		
		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable04,(yVariable04++)+1,20,20);
		
		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable05,(yVariable05++)/3,20,20);
		
		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable06,(yVariable06++)+21,20,20);

		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable07,(yVariable07++)+13,20,20);
		
		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable08,(yVariable08++)/2,20,20);
		y++;
		int yTester = (int)y/3;
		if(yTester>450){
			y = 0;	//RESETS Y VARIABLE
			y2 = 226;

			//COPY X VALUES TO HAVE MULTIPLE WAVES OF FRUIT DROPPING
			xVariable01a=xVariable01;
			xVariable02a=xVariable02;
			xVariable03a=xVariable03;
			xVariable04a=xVariable04;
			xVariable05a=xVariable05;
			xVariable06a=xVariable06;
			xVariable07a=xVariable07;
			xVariable08a=xVariable08;
		}
/*
		if(y2>=225){
		System.out.println("y2: " + y2);
		Global.offScreenBuffer = createImage(500,500);
		Global.displayOnScreen = Global.offScreenBuffer.getGraphics();
		
		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable01a,y2*2,20,20);
		
		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable02a,y2+10,20,20);
		
		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable03a,y2+2,20,20);
		
		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable04a,y2+1,20,20);
		
		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable05a,y2/3,20,20);
		
		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable06a,y2+2,20,20);

		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable07a,y2+3,20,20);
		
		Global.displayOnScreen.setColor(Color.red);
		Global.displayOnScreen.fillOval(xVariable08a,y2/2,20,20);
		y2++;
			
		}
*/

		g.drawImage(Global.offScreenBuffer,0,0,widthOfWindow,heightOfWindow,this);
		repaint();
	}
	
	public void update(Graphics g){
		paint(g);	
	}



	public static void main(String args[]){
		Project7 p = new Project7();
	}
}


class StickMan implements MouseMotionListener{

	@Override
	public void mouseDragged(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseMoved(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
	
}