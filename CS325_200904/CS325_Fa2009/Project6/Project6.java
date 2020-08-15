import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.Scanner;
import javax.swing.*;
import javax.swing.event.*;


class Global{
	/////DOUBLE BUFFER/////

	//DRAW IMAGE IN BUFFER
	public static Image offscreen;
	//COPY IMAGE FROM BUFFER, DISPLAY ON SCREEN
	public static Graphics bufferImg;
}


public class Project6 extends JFrame{
	
	//WIDTH AND HEIGHT OF MAZE
	static int widthOfMaze=600;
	static int heightOfMaze=600;
	
	
	//POSITIONING COORDINATES
	static int xCoord;
	static int yCoord;
	
	//NOTING OF START END POINT
	static int mazeStartingPointX;
	static int mazeStartingPointY;
	static int mazeEndingPointX;
	static int mazeEndingPointY;
	
	static int tileColor=0;

	public Project6(){
		setTitle("Project6 Maze");
		setSize(600,600);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//SET DRAWING COORDINATES TO 0
		xCoord = yCoord = 0;
		
		
		BlankLabel blankLabel = new BlankLabel();
		
		//ADD THE BLANKLABEL TO THE DRAWING
		add(blankLabel);
		addMouseMotionListener(blankLabel);
		
		

		/////DOUBLE BUFFER/////
		//DRAW IMAGE IN BUFFER
		Global.offscreen = createImage(widthOfMaze, heightOfMaze);
		
		//COPY IMAGE FROM BUFFER, DISPLAY ON SCREEN
		Global.bufferImg = Global.offscreen.getGraphics();
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//CALLS PROJECT 6 DEFAULT CONSTRUCTOR
		
		try{
			Project6 project6 = new Project6();
			
			//THE FILE TO READ IN
			FileInputStream inputMazeFile = new FileInputStream("maze.txt");
			
			//OPEN FILE WITH SCANNER
			Scanner mazeScanner = new Scanner(inputMazeFile);
			
			//INPUTLINENUMBER
			int inputLineNumber=1;
			
			while(mazeScanner.hasNext()){
				
				if(inputLineNumber==1){
					//mazeScanner.useDelimiter(" ");
					widthOfMaze = mazeScanner.nextInt();
					heightOfMaze = mazeScanner.nextInt();
					//System.out.println("Width: " + widthOfMaze);
					//System.out.println("Height: " + heightOfMaze);
				}

				int mazeRectSize = (int) 600/(widthOfMaze);
				System.out.println("his " + mazeRectSize);
				
				//FOR LOOP FOR Y-VARIABLE
				for(int j=0; j<heightOfMaze; j++){
					xCoord=0;

					//FOR LOOP FOR X-VARIABLE
					for(int k=0; k<widthOfMaze; k++){
						tileColor = mazeScanner.nextInt();
						//System.out.println(tileColor);
						
						
						//IF THE GIVEN POSITION IS WHITE OR BLACK 
						if(tileColor == 0){
							//Do nothing. Area of travel for maze.
							Global.bufferImg.setColor(Color.white);
							Global.bufferImg.fillRect(xCoord, yCoord, mazeRectSize, mazeRectSize);	
						}
						else if(tileColor == 1){
							//AREA OF MAZE NOT ALLOW TO BE IN 
							Global.bufferImg.setColor(Color.black);
							Global.bufferImg.fillRect(xCoord, yCoord, mazeRectSize, mazeRectSize);			
						}
						else if(tileColor == 2){
							//START OF MAZE
							//must start to click 
							Global.bufferImg.setColor(Color.blue);
							Global.bufferImg.fillRect(xCoord, yCoord, mazeRectSize, mazeRectSize);
							
							//COPY VARIABLE FOR STARTING COORD
							mazeStartingPointX = xCoord;
							mazeStartingPointY = yCoord;
						}
						else if(tileColor == 3){
							//END OF MAZE
							//once mouse has reached point, then end
							Global.bufferImg.setColor(Color.red);

							
							//System.out.println("Ending Point");
							
							//COPY VARIABLE FOR ENDING COORD
							mazeEndingPointX = xCoord;
							mazeEndingPointY = yCoord;
						}
						Global.bufferImg.fillRect(xCoord, yCoord, mazeRectSize, mazeRectSize);
						xCoord = xCoord+mazeRectSize;
					}
					yCoord = yCoord+mazeRectSize;
				}
				
				//char c = inputLine.charAt(2);
				//System.out.println(c);	

				inputLineNumber++;
			}
			mazeScanner.close();	//CLOSE FILE
		}
		catch(Exception e){
			//DISPLAYS ERROR MESSAGE IF ERROR OPENING FILE
			System.out.println("There was an error opening the maze.txt input file.");
		}	
	}
}
//END OF THE PUBLIC CLASS PROJECT6  


//START OF THE BLANKLABEL CLASS 
class BlankLabel extends JLabel implements MouseMotionListener{
	
	Image offscreenImage;
	Graphics offscreen;
	
	boolean trackingMouseMovement = false;
	
	public BlankLabel (){
		setBackground(Color.white);
		
		setOpaque(true);
		Global.offscreen=createImage(600,600);

	}
	
	/*
	//DRAW IMAGE IN BUFFER
	public static Image offscreen;
	//COPY IMAGE FROM BUFFER, DISPLAY ON SCREEN
	public static Graphics bufferImg;
	*/

	public void mouseDragged(MouseEvent e){
		/*System.out.println(e.getX() + ", " + e.getY());*/
	/*	
		if(offscreenImage == null){
			offscreenImage = createImage(500,500);
		}
	
		Global.bufferImg = offscreenImage.getGraphics();
		Global.bufferImg.fillOval(e.getX(),e.getY(),10,10);
		repaint();
		*/
	}

	public void mouseMoved(MouseEvent e){
		
		if(Global.offscreen == null){
			Global.offscreen = createImage(600,600);
		}

		//if(trackingMouseMovement==true){
			Global.bufferImg = Global.offscreen.getGraphics();
			//offscreen.setColor(Color.green);
			//offscreen.fillOval(e.getX()-10,e.getY()-30,6,6);
			System.out.println("Mouse at X:" + e.getX() + ", Y: " + e.getY());
			repaint();
		//}	
	}
		
	public void update(Graphics g){
		paint(g);
	}
	
	public void paint(Graphics g){
		g.drawImage(Global.offscreen,0,0,this);
	}
}
//END OF THE BLANKLABEL CLASS 