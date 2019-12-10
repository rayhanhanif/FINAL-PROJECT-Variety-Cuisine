# FINAL-PROJECT-Variety-Cuisine
This mini project is created using Code Blocks and the functions that are used in this program are array, function, and header.

Our program is about a data sorting program which is applied in restaurants. The program has two features which are to store the id card number and the amount of money stored in it, and to store the data of the ordered food of the customer. To store the card ID number and the amount of money in it, we use the fptr, fscanf, fopen, fclose and strtoken to keep and open the data from the txt file.
There are two choices in the display menu program; Cashier and Booth.

![HOME](https://serving.photos.photobox.com/50024326decad7be3615cc50e69c35a0d3fc83c754096175ec0171e786f892e70a8113b7.jpg)

1.	Cashier 
    In this function there are are four functions
- newcard(); //to create a member card
- topup(); //to add the amount of cash inside the card
- refund(); //to refund the amount of cash stored in the card and to unregister/delete the card
- listcards(); //to show the list of cards which have been registered and stored in the txt file.

![LISTOFCARDSINDAPROGRAM](https://serving.photos.photobox.com/03655774695a94ecfd1b86fa2e7e4716d1cd33c3e0e29c7ad138848cbf0c4b6c612af068.jpg)

2.	Booth 
    In the booth function we can order the choices of food that is offered in the restaurant. There are ten different food choices. The cool thing about this program is that if we want to order the selected item for an amount of 7, we can spam the number of the selected item in the program and it will keep on adding until we want the desired amount. After selecting the food, we will be directed to the payment function. There are three choices in the payment function;


- Yes // to continue to the payment, entering the card ID number
- Back and add more // return to the food menu and add more food
- Back and reduce // return to the food menu and reduce the amount of food selected

3.  Help 
    In the help function, it's the instruction on how to use the program and the description of the functions that is in the program. 
    
    When ordering the food, we can choose the desired food and there's a feature where we can add and remove the desired food before proceeding to the payment. To add an additional item, we can press the number of the desired food. To remove, we can choose the number of the food we want to remove in the receipt section. The linked list function is applied in the food removal section so we can choose the type of food we want to remove from the receipt. 
    
    In the payment section we are required to enter the card id number the amount of cash inside the card will be reduced by the amount of cash which needs to be paid. If the amount of cash is not enough to pay the required amount of money, the program will ask the user to the cashier menu and top up the card. 
    
     ![PAYMENT](https://serving.photos.photobox.com/416328836a3af81c4169b67dbd6251f86002b5d03b5abc1f6096630afcccf64ed021d893.jpg)
    
    ![messageImage_1575942370029](https://serving.photos.photobox.com/99005484945cbc2843f575e0bf4aa5b3b85b46fba5745e9606fb683dcdc49237a2ab21cb.jpg)
    
    The amount of cash in of the selected card id number will be deducted according the total price of the ordered food. When the payment is finished, the receipt will be printed in txt. file form and stored in the folder with the file of the program.  
    
   
    
    ![ReceiptTXT](https://serving.photos.photobox.com/885109998011b8510054002d50f70c1213a44bf028d19e82134357e5b6bde4e76d3a6b8f.jpg)
