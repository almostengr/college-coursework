/*
    
    March 8, 2011
    MIS 320
    Assignment 7
*/
    
function calculate(buttonSubmit){
    var subtotal;
    var salesTax;
    var total;
    var taxRate=0.09;
    var index;
    var errorsExist = false;
    
    var drinks=new Array();
              //ITEM NAME, ITEM PRICE
    drinks[0]=["Lemonade",1.00];
    drinks[1]=["Pink Lemonade",2.00];
    drinks[2]=["Grapefruit",0.50];
    
    if(document.orderform.drinkType.value == ""){
        //CHECKS REQUIRED FIELDS TO MAKE SURE THEY ARE NOT BLANK
        alert("Please select a drink type.");
        errorsExist = true;
    }    
    if(document.orderform.quantity.value < 0 || document.orderform.quantity.value == "" || 
        document.orderform.quantity.value != parseInt(document.orderform.quantity.value)){
        
        //CHECKS REQUIRED FIELDS TO MAKE SURE THEY ARE NOT BLANK
        alert("Please enter a numeric quantity.");
        errorsExist = true;
    }
    if (errorsExist == false){
        //CALCULATE SUBTOTAL
        if(document.orderform.drinkType.value == "lemonade"){
            index = 0;
        }
        else if (document.orderform.drinkType.value == "pink_lemonade"){
            index = 1; 
        }
        else if (document.orderform.drinkType.value == "grapefruit"){
            index = 2;
        }
        
        //CALCULATE AND DISPLAY SUBTOTAL
        subtotal = document.orderform.quantity.value * drinks[index][1];
        document.orderform.subtotal.value = subtotal.toFixed(2);
        
        //CALCULATE AND DISPLAY SALES TAX
        salesTax = subtotal * taxRate;
        document.orderform.tax.value = salesTax.toFixed(2);
        
        //CALCULATE AND DISPLAY TOTAL
        total = subtotal + salesTax;
        document.orderform.total.value = total.toFixed(2);
    }
}

function last_updated(){
    document.write("Last Updated: " + document.lastModified);
}