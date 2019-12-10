# FINAL-PROJECT-Variety-Cuisine
This mini project is created using Code Blocks and the functions that are used in this program are array, function, and header.

Our program is about a data sorting program which is applied in restaurants. The program has two features which are to store the id card number and the amount of money stored in it, and to store the data of the ordered food of the customer. To store the card ID number and the amount of money in it, we use the fptr, fscanf, fopen, fclose and strtoken to keep and open the data from the txt file.
There are two choices in the display menu program; Cashier and Booth.

1.	Cashier In this function there are are four functions
\n newcard(); //to create a member card
\n topup(); //to add the amount of cash inside the card
\n refund(); //to refund the amount of cash stored in the card and to unregister/delete the card
\n listcards(); //to show the list of cards which have been registered and stored in the txt file.

2.	Booth In the booth function we can order the choices of food that is offered in the restaurant. There are ten different food choices. The cool thing about this program is that if we want to order the selected item for an amount of 7, we can spam the number of the selected item in the program and it will keep on adding until we want the desired amount. After selecting the food, we will be directed to the payment function. There are three choices in the payment function;


\n Yes // to continue to the payment, entering the card ID number
\n Back and add more // return to the food menu and add more food
\n Back and reduce // return to the food menu and reduce the amount of food selected

3.  Help In the help function, it's the instruction on how to use the program and the description of the functions that is in the program. 

In the payment section we are required to enter the card id number the amount of cash inside the card will be reduced by the amount of cash which needs to be paid. If the amount of cash is not enough to pay the required amount of money, the program will ask the user to the cashier menu and top up the card.
