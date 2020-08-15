import java.util.Vector;
import java.util.Iterator;
import java.util.Calendar;
/*
Import the Vector, Iterator, and Calendar classes from the java.util package.
*/

/** The AtCron class contains the main function for the program.
* @param main Starts the task scheduler.  If only one parameter is passed (this program), then print out the help information. If more than one parameter is passed, then task schedule with the second parameter as the configuration file name.
*/
public class AtCron {
  public static void main(String args[]) {
    if(args.length != 1) {
	//If only one parameter is passed in, then print out the help information for the program and then exit.
      printHelp();
      System.exit(1);
    }

    ConfigParser cp = new ConfigParser(args[0]); //create a new parser for the configuration settings
    Vector<Task> tasks = cp.parse();	//create a new vector to store the tasks after they are parsed 

    while(true) {
      Iterator<Task> it = tasks.iterator();	//create a new iterator 
      while(it.hasNext()) {
		//go through the itreator as long as there is a next object 
		
        Task task = it.next();
        if(task.isTime(Calendar.getInstance())) {
		//if a task matches the current time, then start/run the task 
          task.fire();
        }
      }
      try {
        Calendar now = Calendar.getInstance();
        int s = 60 - now.get(Calendar.SECOND); 
        Thread.sleep(s*1000);
      } catch(Exception e) {
		//exception for the scheduler for going to sleep 

      }
    }
  }

  static void printHelp() {
  //prints out the help information about this program
    String mesg = "USAGE: java AtCron configfile";
    System.out.println(mesg);
  }
}
