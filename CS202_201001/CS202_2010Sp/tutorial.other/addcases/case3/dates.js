/*
   New Perspectives on HTML and XHTML 5th Edition
   Additional Case Problems
   Case Problem 3
   Filename: dates.js

   Notes:
   The showDate function displays the date in the format: "Weekday, Month Day, Year"

*/

function showDate() {
   thisDate = new Date();
   var thisWDay=thisDate.getDay();
   var thisDay=thisDate.getDate();
   var thisMonth=thisDate.getMonth();
   var thisYear=thisDate.getFullYear();
   var mName = new Array("January", "February", "March", "April", "May", 
       "June", "July", "August", "September", "October","November", "December");
   var wdName = new Array("Sunday", "Monday", "Tuesday", "Wednesday",
       "Thursday", "Friday", "Saturday");
   return wdName[thisWDay]+", "+mName[thisMonth]+" "+thisDay+", "+thisYear;
}
