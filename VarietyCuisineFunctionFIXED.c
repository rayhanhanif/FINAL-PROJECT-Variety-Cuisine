#include <string.h>
#include <stdio.h>
#include <stdlib.h>

FILE *fptr;
int cardNumber[1000],i,n;
char *token;
char cardnumber[1000];

FILE *fptr2;
int cardAmount[1000] = {0},j,m;
char *token2;
char cardamount[1000];


typedef struct cashcard {
    int id;
    int amount;
} cashcard;
cashcard validCards[1000];
int lastCardIndex=0;

struct order {
    int orderNum;
    char foodName[15];
    int price;
    struct order* nextOrder;
};
struct order* firstOrder = NULL;
struct order* orderPtr = NULL;

struct order* arrPtr[5];

void insertOrder(int a, char b[], int c) {
    struct order* queuePtr = NULL;
    struct order* newQueue;
    newQueue = (struct order*) malloc(sizeof(struct order));
    newQueue->orderNum = a;
    strcpy(newQueue->foodName,b);
    newQueue->price = c;
    newQueue->nextOrder = NULL;
    if(firstOrder == NULL) {
        firstOrder = newQueue;
        printf("firstOrder = newQueue\n");
        return;
    }
    queuePtr = firstOrder;
    while(queuePtr->nextOrder != NULL) {
        queuePtr = queuePtr->nextOrder;
    }
    queuePtr->nextOrder = newQueue;
}

void deleteOrder(int a, int* b) {
    if(*b == 0) {
        printf("\n\t\tYou have cancelled all your orders\n");
        //printf("\t\tPlease insert 0\n");
        return;
    }
    if(a == 0) return;
    struct order* checkPtr1;
    struct order* checkPtr2;
    struct order* checkPtr3;
    checkPtr1 = firstOrder;
    checkPtr2 = firstOrder;
    checkPtr3 = firstOrder;
    int num = 1;
    int i = 1;
    while(checkPtr1->orderNum != a) {
        checkPtr1 = checkPtr1->nextOrder;
        num+=1;
    }
    if(num == 1) {
        firstOrder = checkPtr1->nextOrder;
        while(checkPtr2->nextOrder != NULL){
            checkPtr2->orderNum = checkPtr2->orderNum - 1;
            checkPtr2 = checkPtr2->nextOrder;
        }
        checkPtr2->orderNum = checkPtr2->orderNum - 1;
        *b = *b - checkPtr1->price;
        free(checkPtr1);
        return;
    }
    checkPtr1 = firstOrder;

    while(i != num-1 ) {
        checkPtr2 = checkPtr2->nextOrder;
        i++;
    }
    i = 1;
    while(i != num+1 ) {
        checkPtr1 = checkPtr1->nextOrder;
        i++;
    }
    i = 1;
    while(i != num) {
        checkPtr3 = checkPtr3->nextOrder;
        i++;
    }
    //right here, the checkPtr2 is pointing to previous linked list,\
    checkPtr1 is pointing to afterwards linked list and checkPtr3 \
    is pointing to will be deleted linked list
    checkPtr2->nextOrder = checkPtr1;
    while(checkPtr1->nextOrder != NULL){
        checkPtr1->orderNum = checkPtr1->orderNum - 1;
        checkPtr1 = checkPtr1->nextOrder;
    }
    checkPtr1->orderNum = checkPtr1->orderNum - 1;
    *b = *b - checkPtr3->price;
    free(checkPtr3);
}

void deleteAllOrder() {
    struct order* deletePtr;
    while(firstOrder != NULL) {
        deletePtr = firstOrder;
        firstOrder = deletePtr->nextOrder;
        free(deletePtr);
    }
}

void displayOrder()
{

    if(firstOrder == NULL)
    {
        system("cls");
        printf("\n\n\n\t\t\tReceipt\n");
        printf("\t\t--------------------\n\n");
        printf("\t\tThere are no orders..\n\n");
        printf("\t\tPlease order a food!\n\n");
        return;
    }
    struct order* dispPtr;
    dispPtr = firstOrder;
    system("cls"); //printf("%u",firstOrder);
     printf("\n\n\n\t\t\tReceipt\n");
    printf("\t\t=========================\n");

    while(dispPtr->nextOrder != NULL) {
        printf("\t\t%d. %s     Rp%d\n", dispPtr->orderNum, dispPtr->foodName, dispPtr->price);
        dispPtr = dispPtr->nextOrder;
    }
    printf("\t\t%d. %s     Rp%d\n", dispPtr->orderNum, dispPtr->foodName, dispPtr->price);
}

void cashier() {
    //TO DO display menu
    //handle
    int userSelectValue=-1;
    char menu[4][20]={"New Card", "Top Up Card","Refund", "List Cards"};
    while (userSelectValue != 0)
    {
        userSelectValue = displayMenu("Variety Cuisine Cashier",menu,"Please select Operation!",4);
        switch (userSelectValue)
        {
            case 1: newCard(); break;
            case 2: topupCard(); break;
            case 3: refundCard(); break;
            case 4: listCard(); break;
        }
    }
}

void systemUpdate() {
    fptr = fopen("VarietyCuisineDataTemp.txt","w"); //fptr: tunjuk file fopen: fungsi return address. type write
    fptr2 = fopen("VarietyCuisineMoneyTemp.txt","w");
    for(i = 0; i < lastCardIndex; i++) {
        fprintf(fptr, "%d,", validCards[i].id);
        fprintf(fptr2, "%d,", validCards[i].amount);
    }
    fclose(fptr);
    fclose(fptr2);
    remove("VarietyCuisineData.txt");
    remove("VarietyCuisineMoney.txt");
    rename("VarietyCuisineDataTemp.txt", "VarietyCuisineData.txt");
    rename("VarietyCuisineMoneyTemp.txt", "VarietyCuisineMoney.txt");
    printf("\t\tSystem has succesfully updated!\n\n");
}

void createReceipt(int total, int cardNo) {

    struct order* dispPtr;
    dispPtr = firstOrder;

    FILE* fptr3 = NULL;
    //int cardID;
    char resultName[250];
    sprintf(resultName,"Receipt #%d .txt",cardNo);
    fptr3 = fopen(resultName,"w");

    if(fptr3 == NULL)
   {
      printf("Error!");
      exit(1);
   }
    fprintf(fptr3,"\t\tReceipt #%d\n",cardNo);
    fprintf(fptr3,"\t\t--------------------\n",NULL);
    while(dispPtr->nextOrder != NULL) {
        fprintf(fptr3,"\t\t%d. %s Rp%d\n", dispPtr->orderNum, dispPtr->foodName, dispPtr->price);
        dispPtr = dispPtr->nextOrder;
        i++;
    }
    fprintf(fptr3,"\t\t%d. %s Rp%d\n", dispPtr->orderNum, dispPtr->foodName, dispPtr->price);
    fprintf(fptr3,"\t\t--------------------\n",NULL);
    fprintf(fptr3,"\t\tTotal : Rp%d\n\n",total);
    fprintf(fptr3,"\t Thank you for choosing our service :)\n",NULL);
    fprintf(fptr3,"\t We really hope you enjoy the meal!\n",NULL);
    fclose(fptr3);
    printf("\n\n\t\t Your receipt has been print!\n");
}



    void newCard(){
/////////////////////////////////////////////////
    cashcard newCard = { 0, 0};
    fptr = fopen("VarietyCuisineData.txt","a+");
    fptr2 = fopen("VarietyCuisineMoney.txt","a+");
    if(fptr == NULL) {
        printf("Error Opening File");
        return -1;
    }
    if(fptr2 == NULL) {
        printf("Error Opening File");
        return -1;
    }
    fscanf(fptr,"%s",cardnumber);
    fscanf(fptr2,"%s",cardamount);
    token = strtok(cardnumber, ","); //stringtoken function is to tokenize a string into substring
//    token2 = strtok(cardamount, ","); --->> DO NOT PUT HERE!! READ THE STRTOK FUNCTION WORKS

    i = 0;
    while (token != NULL) {
        cardNumber[i] = atoi(token);
        token = strtok(NULL, ",");
        i++;
    }
    token2 = strtok(cardamount,","); // --->> SHOULD BE PUT RIGHT HERE FOR THE STRTOK FUNCTION
    j = 0;
    while (token2 != NULL) {
        cardAmount[j] = atoi(token2);
        token2 = strtok(NULL, ",");
        j++;
    }
    n = i;
    lastCardIndex = i;
    for(i=0; i<n; i++ ) {
        validCards[i].id = cardNumber[i];
        validCards[i].amount = cardAmount[i];

    }
    printf("\t\tEnter Card ID Number:");
    scanf("%d", &newCard.id);

    //checking from the assign validCards
    for(i=0; i<n; i++ ) {
        if(newCard.id == validCards[i].id) goto there;
    }


    if ( getAmount(newCard.id) < 0 ) {
        validCards[lastCardIndex++].id = newCard.id;
        printf("\t\tCard ID %d is now registered.",newCard.id);
        fprintf(fptr2, "%d,", newCard.amount);
        fprintf(fptr, "%d,",newCard.id);

        }
    else {
        there:
        printf("\t\tCard ID %d has already been registered with current amount of Rp.%7d,-.\n\n",
                newCard.id, getAmount(newCard.id));
    }

    fclose(fptr);
    fclose(fptr2);
    system("pause");
}

int getAmount(int id) {
    int i;
    for ( i=0; i<lastCardIndex; i++) {
        if (validCards[i].id == id) {
            return validCards[i].amount;
        }
    }
    return -3;
}

void payment(int a, int b) {
    int i,answer;
    int exit = 1;
    while(exit != 0) {
        cashcard newCard = { 0, 0};
        printf("\n\t\tEnter your card ID number:");
        scanf("%d", &newCard.id);
        for(i=0;i<lastCardIndex;i++) {
            if(validCards[i].id == newCard.id ) {
                printf("\t\tYou are going to purchase for the item listed above. Proceed?\n");
                printf("\t\t1. Yes\n\t\t2. Cancel\n");
                printf("\t\tAnswer:");
                scanf("%d",&answer);
                if(answer == 1) {
                    validCards[i].id = newCard.id;
                    validCards[i].amount -= a;
                    if(validCards[i].amount < 0) {
                        printf("\t\tsorry, your balance is not enough\n");
                        printf("\t\tPlease top up your balance first in the cashier option\n");
                        validCards[i].amount += a;
                        system("pause");
                        exit = 0;
                    }
                    printf("\t\tThe card ID %d balance is now %d\n\n",validCards[i].id,validCards[i].amount);
                    createReceipt(a, newCard.id);
                    deleteAllOrder();
                    system("pause");
                    exit = 0;
                }
                if(answer == 2) {
                    exit = 0;
                    printf("\t\tYou have cancelled your orders\n");
                    system("pause");
                    deleteAllOrder();
                }
            }

            else {
                printf("\t\tCard ID %d not yet registered!\n",newCard.id);

                exit = 0;
            }
        }
    }
}


void topupCard(){
    int id=0, amount=0;

    printf("\t\tEnter Card ID Number:");
    scanf("%d", &id);
    if (getAmount(id) >= 0) {
        //topup
        printf("\t\tCurrent amount of Card ID %d is Rp. %7d,-.\n",
                id, getAmount(id));
        printf("\t\tEnter Top Up Amount: ");
        scanf("%d", &amount);
        updateBalance(id, amount);
        printf("\t\tCurrent amount of Card ID %d is Rp. %7d,-.\n\n",
                id, getAmount(id));
    } else {
        // Refuse
        printf ("\t\tCard ID %d is not registered.\n]\n", id);
    }
    system("pause");
}

int updateBalance(int id, int amount) {
    int i;
    for ( i=0; i<lastCardIndex; i++) {
        if (validCards[i].id == id) {
            validCards[i].amount += amount;
            cardAmount[i] = validCards[i].amount;
            return 1;
        }
    }

    return 0;
}


void refundCard(){
    int id=0; int answer;
    printf("\t\tEnter Card ID Number:");
    scanf("%d", &id);
    if (getAmount(id) >= 0) {
        printf("\t\tCurrent amount of Card ID %d is Rp. %7d,-.\n",id, getAmount(id));
        printf("\t\tRefund? (1=Yes) (0=No)\n\n ");
        scanf("%d", &answer);
        if (answer == 1) {
            //search for id location in array
            int i;
            for (i=0; i<lastCardIndex; i++) {
                if (validCards[i].id == id) {
                    int j;
                    for ( j=i; j < (lastCardIndex-1);j++)
                        validCards[j] = validCards[j+1];
                        --lastCardIndex;
                    break;
                }
            }
            printf("\t\tCard is unregistered, please proceed with refund.\n");
        }
    }
    else {
        // Refuse
        printf ("\t\tCard ID %d is not registered.\n", id);
    }
    systemUpdate();
    system("pause");

}

void listCard() {
   printf("\t\t\tList of Registered Cards:\n");
    printf("\t\t\t=========================\n");
    int p;
    for ( p=0; p<lastCardIndex; p++) {
        printf("\t\tCard ID: %10d, Amount: Rp.%7d,-\n",
               validCards[p].id,validCards[p].amount);
    }
    printf("\n");
    system("pause");
}


void booth() {
    int orderNum = 1;
    int cancelNum;
    int cardID;
    int totalPrice=0;
    int mp1=0,mp2=0,mp3=0,mp4=0,mp5=0,mp6=0,mp7=0,mp8=0,mp9=0,mp10=0;
    int food;
    int repeat=-1;
    int answer,i,maxMenuNumber=5;
    int userSelectValue =-1;
    char menu[10][20] = {"Onion\tRp15k","Garlic\tRp20k","Brocoli\tRp5k","Eggplant\tRp10k","Peanut\tRp1k","Fish\t\tRp10k",
    "Chicken\tRp20k","Spinach\tRp5k","Banana\tRp2k","Noodle\tRp30k"};
    while(userSelectValue!=0) {//initial while
        userSelectValue = displayMenu("Variety Cousine Booth", menu, "Select your food", 10);
        switch(userSelectValue) {
            case 1: insertOrder(orderNum++,"Onion",15000); totalPrice += 15000; break;
            case 2: insertOrder(orderNum++,"Garlic",20000); totalPrice += 20000; break;
            case 3: insertOrder(orderNum++,"Brocoli",5000); totalPrice += 5000; break;
            case 4: insertOrder(orderNum++,"Eggplant",10000); totalPrice += 10000; break;
            case 5: insertOrder(orderNum++,"Peanut",1000); totalPrice += 1000; break;
            case 6: insertOrder(orderNum++,"Fish",10000); totalPrice += 10000; break;
            case 7: insertOrder(orderNum++,"Chicken",20000); totalPrice += 20000; break;
            case 8: insertOrder(orderNum++,"Spinach",5000); totalPrice += 5000; break;
            case 9: insertOrder(orderNum++,"Banana",2000); totalPrice += 2000; break;
            case 10: insertOrder(orderNum++,"Noodle",30000); totalPrice += 30000; break;
        }
        repeat+=1;
    }
    displayOrder();
    printf("\n\n\t\tYou purchased %d item for Rp%d\n",repeat,totalPrice);
    printf("\t\tProceed to the payment?\n\t\t1. Yes\n\t\t2. Back and add more\n\t\t3. Back and reduce\n\t\tAnswer:");
    scanf("%d",&answer);
    while( answer < 1 || answer > 3) {
        printf("\t\tSelect the correct option please\n");
        printf("\t\tProceed to the payment?\n\t\t1. Yes\n\t\t2. Back and add more\n\t\t3. Back and reduce\n\t\tAnswer:");
        scanf("%d",&answer);
    }
    while(answer != 1) { //big while
        while (answer == 2) { //small while
            userSelectValue=-1;
            repeat-=1;
            while(userSelectValue!=0) {
                userSelectValue = displayMenu("Variety Cousine Booth", menu, "Select your food you want to add", 10);
                switch(userSelectValue) {
                    case 1: insertOrder(orderNum++,"Onion",15000); totalPrice += 15000; break;
                    case 2: insertOrder(orderNum++,"Garlic",20000); totalPrice += 20000; break;
                    case 3: insertOrder(orderNum++,"Brocoli",5000); totalPrice += 5000; break;
                    case 4: insertOrder(orderNum++,"Eggplant",10000); totalPrice += 10000; break;
                    case 5: insertOrder(orderNum++,"Peanut",1000); totalPrice += 1000; break;
                    case 6: insertOrder(orderNum++,"Fish",10000); totalPrice += 10000; break;
                    case 7: insertOrder(orderNum++,"Chicken",20000); totalPrice += 20000; break;
                    case 8: insertOrder(orderNum++,"Spinach",5000); totalPrice += 5000; break;
                    case 9: insertOrder(orderNum++,"Banana",2000); totalPrice += 2000; break;
                    case 10: insertOrder(orderNum++,"Noodle",30000); totalPrice += 30000; break;
                }
                    repeat+=1;
                }
                    displayOrder();
                    printf("\n\n\t\tYou purchased %d item for Rp%d\n",repeat,totalPrice);
                    printf("\t\tProceed to the payment?\n\t\t1. Yes\n\t\t2. Back and add more\n\t\t3. Back and reduce\n\t\tAnswer:");
                    scanf("%d",&answer);
                    while( answer < 1 || answer > 3) {
                        printf("\t\tSelect the correct option please\n");
                        printf("\t\tProceed to the payment?\n\t\t1. Yes\n\t\t2. Back and add more\n\t\t3. Back and reduce\n\t\tAnswer:");
                        scanf("%d",&answer);
                    }
                }
        while (answer == 3) {//small while
            repeat+=1;
            userSelectValue=-1;
            orderNum += 1; //weird codee do not delete!!
            while(userSelectValue!=0) {

                displayOrder();
                printf("Insert 0 to finish\n");
                printf("Select the food you want to cancel:");
                scanf("%d", &cancelNum);
                if(cancelNum == 0) userSelectValue = 0;
                deleteOrder(cancelNum, &totalPrice);
                orderNum -= 1; //weird code do not delete!!

                repeat-=1;
                if(repeat == 0) {
                    userSelectValue = 0;
                    printf("\t\tYou will be directed to payment..\n");
                    deleteAllOrder();
                    orderNum = 1;
                    system("pause");
                }

                }   displayOrder();
                    printf("\n\n\t\tYou purchased %d item for Rp%d\n",repeat,totalPrice);
                    printf("\t\tProceed to the payment?\n\t\t1. Yes\n\t\t2. Back and add more\n\t\t3. Back and reduce\n\t\tAnswer:");
                    scanf("%d",&answer);
                    while( answer < 1 || answer > 3) {
                        printf("\t\tSelect the correct option please\n");
                        printf("\t\tProceed to the payment?\n\t\t1. Yes\n\t\t2. Back and add more\n\t\t3. Back and reduce\n\t\tAnswer:");
                        scanf("%d",&answer);
                    }
                }
    }
    displayOrder();
    payment(totalPrice, repeat);
}



int displayMenu(char title[],char menu[][20],char instruction[],int maxMenuNumber) {
    int userInput;
    int i;
    system("cls");
    for (i=0; i<5; i++) printf("\n");
    printf("\t\t%s\n", title);
    printf("\t\t-------------------\n");
    for (i=0; i<maxMenuNumber; i++){
        printf("\t\t%d: %s\n", i+1, menu[i]);
    }
    printf("\n\t\t0: Exit/Back\n");
    printf("\t\t-------------------\n");
    printf("\t\t%s\n", instruction);
    scanf("%d",&userInput);
    while ( userInput<0 || userInput > maxMenuNumber)
    {
        printf("Please enter the correct number!\n");
        scanf("%d",&userInput);
    }

    return userInput;
}


void purchase(int q, int w, int e, int r, int t, int y, int u, int i, int o, int p) {
    printf("\t\tOnion\tRp15k\tamount: %d\n",q);
    printf("\t\tGarlic\tRp20k\tamount: %d\n",w);
    printf("\t\tBrocoli\tRp5k\tamount: %d\n",e);
    printf("\t\tEggplantRp10k\tamount: %d\n",r);
    printf("\t\tPeanut\tRp1k\tamount: %d\n",t);
    printf("\t\tFish\tRp10k\tamount: %d\n",y);
    printf("\t\tChicken\tRp20k\tamount: %d\n",u);
    printf("\t\tSpinach\tRp5k\tamount: %d\n",i);
    printf("\t\tBanana\tRp2k\tamount: %d\n",o);
    printf("\t\tNoodle\tRp30k\tamount: %d\n",p);
}
void help()
{
            printf("\n\n\n");
            printf("\t\t\t\t\t**********************************\n");
			printf("\t\t\t\t\t\t*******HELP*******\n");
			printf("\t\t\t\t\t**********************************\n");
			printf("\t\t\tHere are the procedures that can be used to operate this program.\n\n");
			printf("\t\t\t1. The CASHIER menu is to create a new card, top up the amount,\n \t\t\t   refund the card and to see the list of registered cards.\n\n");
			printf("\t\t\t2. The BOOTH menu is to select the food choices desired for the user.\n\n");
			printf("\t\t\t3. When topping up, insert the amount desired without any dots\n \t\t\t or coma. For example, insert 50000. Not 50,000 or 50.000. \n\n");
			system("pause");
			system("cls");
}






