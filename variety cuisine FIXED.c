#include <stdio.h>
#include "VarietyCuisineFunctionFIXED.c"


int main(){

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
    token = strtok(cardnumber, ","); //strtok: tokenize the strings into substrings
//    token2 = strtok(cardamount, ","); // If this is not included, it will worked. WHY??
    i = 0;
    while (token != NULL) {
        cardNumber[i] = atoi(token);
        token = strtok(NULL, ",");
        i++;
    }
    token2 = strtok(cardamount, ",");
    j = 0;
    while (token2 != NULL) {
        cardAmount[j] = atoi(token2);
        token2 = strtok(NULL, ",");
        j++;
    }
    n = i;
    lastCardIndex = i;
    for(i=0; i<lastCardIndex; i++ ) {
        validCards[i].id = cardNumber[i];
        validCards[i].amount = cardAmount[i];
        printf("%d\t",validCards[i].amount);
        printf("%d\n",validCards[i].id);
    }
    fclose(fptr);
    fclose(fptr2);

    int userSelectValue=-1;
    char menu[3][20]={"Cashier", "Booth", "Help"};
    while (userSelectValue != 0){
        userSelectValue = displayMenu("*WELCOME TO THE VARIETY CUISINE RESTAURANT*",menu,"Please select role!",3);
        switch (userSelectValue){
            case 1: cashier(); break;
            case 2: booth(); break;
            case 3: help(); break;
        }
    }

    systemUpdate();
    return 0;
}
