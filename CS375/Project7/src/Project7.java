import java.awt.*;
import java.awt.event.MouseMotionListener;
import javax.swing.*;

class Global{
	/////DOUBLE BUFFER/////

	//DRAW IMAGE IN BUFFER
	public static Image offscreen;
	//COPY IMAGE FROM BUFFER, DISPLAY ON SCREEN
	public static Graphics bufferImg;
}

public class Project7 extends JFrame{
	public Project7(){
		setTitle("Project 7");
		setSize(500, 500);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBackground(Color.white);
	}
	
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Project7 p = new Project7();
	}

}

abstract class DrawStickFigure implements MouseMotionListener{
	
}
class DrawFruit{
	
}
