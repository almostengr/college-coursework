import java.awt.*;
import javax.swing.*;


/**
*This is the main class for Project 4.
*The "extends JFrame" make sure that the class uses the javax.swing.* package for creating a GUI window. 
*/
public class Project4 extends JFrame {
	static int width = 500, height = 500;
	//THE HEIGHT AND WIDTH OF THE WINDOW
	
	static boolean openMouth = true, goingRight = true;;	
	//OPENMOUTH = IS PACMAN'S MOUTH OPEN OR CLOSED
	//GOINGRIGHT = IS PACMAN GOING TOWARDS THE RIGHT OR LEFT OF THE SCREEN
	

	static int leftTurn = 0, allTraffic = 0, count=0;
	//0 = red, 1 = yellow, 2 = green
	

	
	int x = 0, y = 0;
	//POSITIONING 
	

	/**
	* The Project4 function is the default constructor. 
	* It creates a thread for the program to run. 
	*/
	public Project4(){
		

		Thread pacBody = new Thread(){
			public void run(){
			int dir = 5; 	//HOW FAST DOES PACMAN MOVE
			
				while(true){
	
					x += dir; 	//REPOSITIONS PACMAN IMITATING MOVEMENT
	
					if (x > (width-90) || x < 0){	
					//SET SO THAT PACMAN DOESN'T RUN PASS THE BORDER OF THE SCREEN
						
						dir *= -1;	//CHANGES DIRECTION
						if(goingRight == true){
							goingRight = false;
							//MAKES PACMAN TURN IN OPPOSITE DRIECTION
						}
						else{
							goingRight = true;
							//MAKES PACMAN TURN IN OPPOSITE DRIECTION
						}
					}
					
					repaint();	//AUTOMATIC REDRAWS WITHOUT HAVING TO RESIZE SCREEN
	
					try{
					Thread.sleep(100);
					//CONTROLS SPEED OF REPAINTING
					}catch (Exception e){ }
	
				}
			}
		};
				
		pacBody.start();
		//STARTS THE THREAD 
		
	}

	/**
	*The paint(Graphics g) function draws the image off screen into a buffer.
	*Then it reads the buffer and copies the shape on the screen. It also 
	*changes the direction that Pacman is facing when he reaches the edge of 
	*the window and opens and closes Pacman's mouth.  
	*
	* In addition, it displays a changing traffic light with a left turn signal on the screen.
	*
	*@param g is  the image to be updated 
	*/
	public void paint(Graphics g){
		
		/*DOUBLE BUFFER*/	
		Image offscreen = createImage(width, height);	//DRAW IMAGE IN BUFFER
		Graphics bufferImg = offscreen.getGraphics();	//COPY IMAGE FROM BUFFER, DISPLAY ON SCREEN

		setBackground(Color.black);		//SET THE BACKGROUND COLOR OF THE WINDOW
		
		
		//DRAWS THE BODY OF PACMAN
		bufferImg.setColor(Color.red);		//SET THE COLOR OF THE PACBODY
		bufferImg.fillOval(x, 50, 90, 90);		//FILL THE PACBODY WITH THE COLOR SET ABOVE
		

		if (goingRight == true){
			
			
			if(openMouth == true){	
				
				openMouth = false;
				//IF THE MOUTH IS OPEN, THEN CLOSE IT
				
			}
			else{
				//DRAWS THE MOUTH OF PACMAN
				bufferImg.setColor(Color.black);	//SET THE COLOR OF THE MOUTH	
				bufferImg.fillArc(x,50,90,90,30,-60);	//DRAWS THE MOUTH
				
				openMouth = true;
				//IF THE MOUTH IS CLOSED, THEN OPEN IT
			}

			//DRAWS THE EYE OF PACMAN
			bufferImg.setColor(Color.white);	//SETS THE COLOR OF THE EYE
			bufferImg.fillOval(x+55, 60, 10, 10);	//DRAWS THE EYE
	
		}
		else{

			if(openMouth == true){
	
				openMouth = false;
				//IF THE MOUTH IS OPEN ,THEN CLOSE IT
				
			}
			else{
	
				//DRAWS THE MOUTH OF PACMAN
				bufferImg.setColor(Color.black);	//SET THE COLOR OF THE MOUTH
				bufferImg.fillArc(x,50,90,90,150,60);	//DRAWS THE MOUTH
				
				openMouth = true;
				//IF THE MOUTH IS CLOSED, THE OPEN IT
			}
			
			//DRAWS THE EYE OF PACMAN
			bufferImg.setColor(Color.white);	//SETS THE COLOR OF THE EYE
			bufferImg.fillOval(x+25, 60, 10, 10);	//DRAWS THE EYE
		}
		

		
		
		//TRAFFIC LIGHT 
		
		/* SHOW GREEN LIGHT AND GREEN ARROW
		 * SHOW GREEN LIGHT AND YELLOW ARROW
		 * SHOW GREEN LIGHT
		 * SHOW YELLOW LIGHT 
		 * SHOW RED LIGHT 
		 * 
		 * REPEAT 
		 */
		
		bufferImg.setColor(Color.white);
		bufferImg.fillRect(95, 330, 30, 70);
		bufferImg.fillRect(125, 300, 35, 100);
		

		bufferImg.fillRect((125+70), 300, 35, 100);
		

		bufferImg.fillRect((125+140), 300, 35, 100);

		bufferImg.setColor(Color.black);
		bufferImg.fillOval(97, 337, 25, 25);	//DRAWS CIRCULAR YELLOW
		bufferImg.fillOval(97, 367, 25, 25);	//DRAWS CIRCULAR RED
		
		if(leftTurn == 2){
			
			bufferImg.setColor(Color.green);
			bufferImg.drawLine(100, 380, 110, 370);
			bufferImg.drawLine(100, 380, 120, 380);
			bufferImg.drawLine(100, 380, 110, 390);
			
			if(count == 3){
				leftTurn--;
			}
		}
		else if(leftTurn == 1){
			bufferImg.setColor(Color.yellow);
			bufferImg.drawLine(100, 350, 110, 340);
			bufferImg.drawLine(100, 350, 120, 350);
			bufferImg.drawLine(100, 350, 110, 360);
			leftTurn--;
		}
		else{
		}
		
		count++;

		int x_coord=130;
		
		if(allTraffic == 2){
			for(int whichLight=0; whichLight < 3; whichLight++){
				bufferImg.setColor(Color.black);
				bufferImg.fillOval(x_coord, 340, 25, 25);	//DRAWS CIRCULAR YELLOW
				bufferImg.fillOval(x_coord, 310, 25, 25);	//DRAWS CIRCULAR RED
				
				bufferImg.setColor(Color.green);	//SETS THE COLOR OF THE EYE
				bufferImg.fillOval(x_coord, 370, 25, 25);	//DRAWS CIRCULAR GREEN
				
				x_coord = x_coord + 70;
			}

			
			if(count == 8){
				allTraffic--;
				count = 0;
			}
		}
		else if(allTraffic == 1){
			for(int whichLight=0; whichLight < 3; whichLight++){
				bufferImg.setColor(Color.black);
				bufferImg.fillOval(x_coord, 370, 25, 25);	//DRAWS CIRCULAR GREEN
				bufferImg.fillOval(x_coord, 310, 25, 25);	//DRAWS CIRCULAR RED
				
				bufferImg.setColor(Color.yellow);	//SETS THE COLOR
				bufferImg.fillOval(x_coord, 340, 25, 25);	//DRAWS CIRCULAR YELLOW
				x_coord = x_coord + 70;
			}
			
			allTraffic--;

		}
		else{
			for(int whichLight=0; whichLight < 3; whichLight++){
				bufferImg.setColor(Color.black);
				bufferImg.fillOval(x_coord, 370, 25, 25);	//DRAWS CIRCULAR GREEN
				bufferImg.fillOval(x_coord, 340, 25, 25);	//DRAWS CIRCULAR YELLOW
				
				bufferImg.setColor(Color.red);	//SETS THE COLOR OF THE EYE
				bufferImg.fillOval(x_coord, 310, 25, 25);	//DRAWS THE EYE

				x_coord = x_coord + 70;
			}
			if(count==10){
				allTraffic = 2;
				leftTurn = 2;
				count=0;
			}
		}
		
		
		
		//DRAWS THE IMAGE TO SCREEN
		g.drawImage(offscreen,0,0,width,height,this);
	}
	

	/**
	*This automatically updates the function the painting of the shape and it 
	*is an automatic occurring event.
	*
	*@param g is the image to be updated. 
	*/
	public void update(Graphics g){
		paint(g);
		//AUTOMATICALLY REPAINT THE OBJECT
	}



	/**
	*This is the main class.  This calls all of the other functions for the 
	*program to run. 
	*/
	public static void main(String args[]){
		Project4 d = new Project4();
		d.setSize(width, height);
		d.setTitle("Project 4 Animation w/ Pacman and Traffic Light");
		d.setVisible(true);
		
	}

}
