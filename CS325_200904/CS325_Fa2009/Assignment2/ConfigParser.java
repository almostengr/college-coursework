import java.util.Vector;
import java.util.Scanner;
import java.io.File;
/*
Import the Scanner class from the java.util package.
Import the File class from the java.io package.
*/

/**
* The ConfigParser class reads the configuration file that is specified in the 
* parameters.  The file name is stored in a string and each event and its 
* details are stored in a Vector. It uses the Vector and Scanner classes from 
* the Java Utilities library.  It also uses the File class from the Java 
* Input/Output library. 
*/
public class ConfigParser {
  String filename;
  Scanner scanner;

  /**
  * The ConfigParser opens the configuration file.  If it is unsuccessful,
  * @param filename The name of the configuration file 
  */
  public ConfigParser(String filename) {
  //Reads in the configuration file. 
    this.filename = filename;
    try {
		//Read in the configuration file that is specified. 
      scanner = new Scanner(new File(filename));
    } catch(Exception e) {
		//If the configuration file cannot be read, then create a new file to read in??
      scanner = new Scanner("");
    }
  }

  /**
  * This creates a new vector and stores the tasks in and their attributes.
  * @return tasks Puts the tasks in to the vector
  */
  public Vector<Task> parse() {
    Vector<Task> tasks = new Vector<Task>();
	//Create a new vector. 
	
    while(scanner.hasNext()) {
		//While reading the file, parse the tasks while reading them in. 
      tasks.add(parseEntry()); 
    }
    return tasks;
  }

  /**
  * The Task parseEntry() function separates each line of the configuration 
  * file into parts and places them into the Vector.  Each line in the 
  * configuration file is labeled as a Task in the vector. 
  * @return Task Returns the attributes of the task. 
  */
  Task parseEntry() {
    boolean atEvent = false;
    if(scanner.hasNext("@")) {
	//if the line starts with @, then run as "At" task; otherwise run as Cron event.
      atEvent = true;
      scanner.next("@"); 
    }
	
	//Read in the attributes of each task. 
    Vector<Integer> minutes = parseDateField();
    Vector<Integer> hours = parseDateField();
    Vector<Integer> daysOfMonth = parseDateField();
    Vector<Integer> months = parseDateField();
    Vector<Integer> daysOfWeek = parseDateField();
  
    return new Task(minutes,hours,daysOfMonth,
                    months,daysOfWeek,parseCommand(), atEvent);  
  }

  /**
  * parseDateField() reads the date and divides it into chunks. Each line has
  * to be divided into chunks before it is placed into the vector.
  * @return parts Returns the parts of the date and place them in the vector.
  */
  Vector<Integer> parseDateField() {
    String chunk = scanner.next();
    Vector<Integer> parts = new Vector<Integer>();

	
    if(chunk.equals("*")) 
	//if the chunk has the value * then return it. 
      return parts;

    Scanner cp = new Scanner(chunk);
    cp.useDelimiter(",") ;	//read line until comma is reached 

    while(cp.hasNext()) {
      parts.addAll(parseDateRange(cp.next()));
    } 

    return parts;
  }

  /**
  * parseDateRange reads in the date range and breaks it into date, month, etc.
  * @return pdf Returns the parsed date.
  */
  Vector<Integer> parseDateRange(String dr) {
    Vector<Integer> pdr = new Vector<Integer>();
    if(dr.indexOf('-') == -1) {
      pdr.add(Integer.parseInt(dr));
      return pdr;
    }
	
	//If a task attribute has a range (not a definite value), then get the first value, discard the "-", and then get the second value. 
    String parts[] = dr.split("-");		//Split the range at the hyphen. 
    int a = Integer.parseInt(parts[0]);		//holds the first number (before hyphen)
    int b = Integer.parseInt(parts[1]);		//holds the second number (after hyphen)

    for(; a<=b; a++) {
      pdr.add(a);
    }
    return pdr;
  }

  //Reads in the command for a task and returns the next line of the configuration file
  String parseCommand() {
    return scanner.nextLine().trim();
  }

  /**
  * The main function of the program.  If only one argument is entered, then it displays the help file for the program.  Otherwise it reads the file that is specified as the second parameter and parses it. 
  */
  public static void main(String args[]) {
    if(args.length != 1) {
		//if only one argument was entered, then do the following
		
      printHelp();		//Print the help mesage 
      System.exit(1);	//Exit the program
    }

    ConfigParser parser = new ConfigParser(args[0]);
  }

  static void printHelp() {
	//This function prints out the help information regarding the program. 
    String mesg = "USAGE: java ConfigParser filename";
    System.out.println(mesg);
  }
}
