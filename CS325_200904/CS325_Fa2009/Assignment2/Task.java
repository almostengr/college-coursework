import java.util.Vector;
import java.util.Iterator;
import java.util.Calendar;
import java.lang.Runtime;
import java.io.InputStream;
/*
Import the Vector, Iterator, and Calendar classes from the java.util package.
Import the Runtime class from the java.lang package.
Import the InputStream class from the java.io package.
*/

/**
 * This is the Task class.  It uses the Vector, Iterator, and Calendar classes 
 * from the Java Utilities library. It also uses the Runtime class from the 
 * Language library and the InputStream class from the Input/Output library.
 */
public class Task {
  Vector<Integer>  minutes,hours, daysOfMonth, months, daysOfWeek;
  String command; 	//Puts the command into a string. 
  boolean atEvent;	//If the task is an "At" task, then this will be true and False if is Cron event. 
  boolean hasFired;	//If the task has been ran, then it will return true. 

  /**
  * This is the default constructor for the Task class.
  */
  public Task() {
	//Defines the default values for the constructor.
    minutes = new Vector<Integer>();
    hours = new Vector<Integer>();
    daysOfMonth = new Vector<Integer>();
    months = new Vector<Integer>();
    daysOfWeek = new Vector<Integer>();
    command = "";
    atEvent = false;
    hasFired = false;
  }

  /**
  * This constructor defines gets the time for when each event is set to run.
  * @param minutes The minute to run the task.
  * @param hours The hour to run the task.
  * @param daysOfMonth The days of the month to run the task. 
  * @param months The months that the task is to be run.
  * @param daysOfWeek The days of the week to run the task. 
  * @param command The command to run/execute.
  * @param at At the current event.
  */
  public Task(Vector<Integer> minutes, 
   Vector<Integer> hours, 
   Vector<Integer> daysOfMonth, 
   Vector<Integer> months, 
   Vector<Integer> daysOfWeek,
   String command,
   boolean at) {
   //Defines the values for when reading from the configuration file. 
   
    this.minutes = minutes;	//The minute or minutes (if a range) that the task is suppose to start/run
    this.hours = hours;	//The hour or hours that the task is suppose to start/run
    this.daysOfMonth = daysOfMonth;	//The day(s) of the that the task is suppose to start/run
    this.months = months;	//The month(s) that the task is suppose to start/run
    this.daysOfWeek = daysOfWeek;	//The days of the week that the task is suppose to start/run
    this.command = command;	//The command that is to be ran when the given time is reached.
    this.atEvent = at;	//Whether the task is an At task or a Cron task. 
    hasFired = false;
  }

  /**
  * Checks to see if it is time to run a task. 
  * @param time The time of the task. 
  */
  public boolean isTime(Calendar time) {
  //Gets the current time. 
    int h = time.get(Calendar.HOUR),
        m = time.get(Calendar.MINUTE),
        D = time.get(Calendar.DATE),
        M = time.get(Calendar.MONTH),
        dow = time.get(Calendar.DAY_OF_WEEK);

    if(hours.size() > 0 && hours.indexOf(h) == -1)
      return false;
    if(minutes.size() > 0 && minutes.indexOf(m) == -1)
      return false;
    if(daysOfMonth.size() > 0 && daysOfMonth.indexOf(D) == -1)
      return false;
    if(months.size() > 0 && months.indexOf(M) == -1)
      return false;
    if(daysOfWeek.size() > 0 && daysOfWeek.indexOf(dow) == -1)
      return false;
    return true;
  }

  /**
  * Fires (or starts) an event if the event has not already fired. If there is 
  * a problem with starting the event, an exception is passed to the user. 
  */
  public void fire() {
    if(atEvent && hasFired)
	//If it is an At task and it has fired, then return nothing 
      return;

    hasFired = true;

    try {
	//Try to run the command specified in the configuration file
      Process child = Runtime.getRuntime().exec(command);
      InputStream in = child.getInputStream();
      int c;
      while ((c = in.read()) != -1) {
        System.out.print((char)c);
      }
    } catch(Exception e) {
	//If the command in the configuration file can not be run, then print out an exception
    }
  }
}
