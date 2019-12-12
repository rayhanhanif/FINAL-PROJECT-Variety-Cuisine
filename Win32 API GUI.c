
//#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include "VarietyCuisineFunctionFIXED.c"

#define SELECT_INPUT 1
#define FILE_MENU_NEWCARD 7
#define FILE_MENU_TOPUPCARD 2
#define FILE_MENU_REFUND 3
#define FILE_MENU_LISTCARD 4
#define FILE_EXIT 5
#define FILE_BOOTH 6
#define NEWCARD_INPUT 8
#define TOPUPCARD_INPUT 9
#define REFUND_INPUT 10
#define BOOTH_INPUT 11

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

void AddMenus(HWND);
void AddControls(HWND);

HMENU hMenu;
HWND hEdit;


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {




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
       // printf("%d\t",validCards[i].amount);
       // printf("%d\n",validCards[i].id);
    }
    fclose(fptr);
    fclose(fptr2);

    //MessageBox(NULL, "HELLO", "My First GUI", MB_OK);
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure ;

    if(!RegisterClassW(&wc)) return -1;

    CreateWindowW(L"myWindowClass", L"\t\tVariety Cuisine Restaurant Data", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL,NULL,NULL,NULL);

    MSG msg = {0};
    while( GetMessage(&msg, NULL, NULL, NULL)) {
        TranslateMessage (&msg);
        DispatchMessage (&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProcedure (HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    int i;
    switch (msg) {
    case WM_COMMAND:
        switch(wp) {
        case SELECT_INPUT:
            MessageBeep(MB_OK);

                    //   MessageBeep(MB_OK);
             int number;
            wchar_t text[100];
            //wint_t answer;
            GetWindowTextW(hEdit,text,100);
            number = atoi(text);
            for(i = 0; i<= 10; i++) {
                if(number == 1) {
                    CreateWindowW(L"static", L"1. New Card\n2. Topup Card\n3. Refund\n4. List Card", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER, 100,50,300,100,hWnd,NULL,NULL,NULL);
                }
            /*   GetWindowTextW(hEdit,answer,100);
               //number = atoi(text);
                if(answer == 1){
                    CreateWindowW(L"static", L"Enter your Card ID", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER, 100,50,300,100,hWnd,NULL,NULL,NULL);
                }   */
            }
            if(number == 2) {
               CreateWindowW(L"static", L"1.Onion Rp15k\t6.Fish Rp20k\n2.Garlic Rp20k\t7.Chicken Rp20k\n3.Brocolli Rp5k\t8.Spinach Rp5k\n4.Fungi Rp10k\t9.Banana Rp2k\n5.Peanut Rp1k\t10.Noodle Rp30k ", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_LEFT, 100,50,300,100,hWnd,NULL,NULL,NULL);
            }
            if(number == 0) {
                CreateWindowW(L"static", L"Please Select Operation:\n1. Cashier\n2. Booth\n\n\n0. Back/Exit", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER, 100,50,300,100,hWnd,NULL,NULL,NULL);
            }


            break;
        case NEWCARD_INPUT:



            MessageBeep(MB_OK);
            int number1;
            wchar_t text1[100];
            GetWindowTextW(hEdit,text1,100);
            number1 = atoi(text1);
            for(i=0; i<n; i++ ) {
                if(validCards[i].id == number1) printf("Card ID Has been registered!");
            }
          /*  if(number1 == 1) {
                CreateWindowW(L"static", L"Enter your card ID Down Below", WS_VISIBLE | WS_CHILD|WS_BORDER|SS_CENTER, 100, 50, 300, 100, hWnd,NULL,NULL,NULL);
            }   */
            break;
        case TOPUPCARD_INPUT:
            MessageBeep(MB_OK);

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
                printf("Card Id:\t\t");
                printf("Card Amount:\n");
            for(i=0; i<n; i++ ) {
                validCards[i].id = cardNumber[i];
                validCards[i].amount = cardAmount[i];

                printf("%d\t\t\t",validCards[i].id);
                printf("Rp%d\n",validCards[i].amount);

            }

            CreateWindowW(L"static", L"See in command line", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER, 50,50,400,200,hWnd,NULL,NULL,NULL);

       /*     int number2;
            wchar_t text2[100];
            GetWindowTextW(hEdit,text2,100);
            number2 = atoi(text2);
            if(number2 == 1) {
                CreateWindowW(L"static", L"Enter your card ID Down Below to TopUp", WS_VISIBLE | WS_CHILD|WS_BORDER|SS_CENTER, 100, 50, 300, 100, hWnd,NULL,NULL,NULL);
            }   */
            break;
        case REFUND_INPUT:
            MessageBeep(MB_OK);
            int number3;

                CreateWindowW(L"static", L"1.Onion Rp15k\t6.FishtRp20k\n2.Garlic Rp20k\t7.Chicken Rp20k\n3.Brocolli Rp5k\t8.Spinach Rp5k\n4.Fungi Rp10k\t9.Banana Rp2k\n5.Peanut Rp1k\t10.Noodle Rp30k ", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_LEFT\
                          , 50,50,400,200,hWnd,NULL,NULL,NULL);
            break;
        case BOOTH_INPUT:
            MessageBeep(MB_OK);
            int number4;
            wchar_t text4[100];
            GetWindowTextW(hEdit,text4,100);
            number4 = atoi(text4);
            if(number4 == 1) {
                CreateWindowW(L"static", L"Select the food you want", WS_VISIBLE | WS_CHILD|WS_BORDER|SS_CENTER, 100, 50, 300, 100, hWnd,NULL,NULL,NULL);
            }


            break;
        case FILE_MENU_TOPUPCARD:
            CreateWindowW(L"static", L"Enter your Card ID Number", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER, 100,50,300,100,hWnd,NULL,NULL,NULL);

            break;
        case FILE_MENU_REFUND:
            CreateWindowW(L"static", L"Enter your Card ID Number", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER, 100,50,300,100,hWnd,NULL,NULL,NULL);
            break;
        case FILE_MENU_LISTCARD:
            MessageBeep(MB_OK);

            //system("cls");
                       /* cashcard newCard = { 0, 0};
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
            lastCardIndex = i; */
                printf("Card Id:\t\t");
                printf("Card Amount:\n");
            for(i=0; i<n; i++ ) {
                validCards[i].id = cardNumber[i];
                validCards[i].amount = cardAmount[i];

                printf("%d\t\t\t",validCards[i].id);
                printf("Rp%d\n",validCards[i].amount);

            }
            CreateWindowW(L"static", L"See in command line", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER, 50,50,400,200,hWnd,NULL,NULL,NULL);
            break;
        case FILE_MENU_NEWCARD:
            CreateWindowW(L"static", L"Enter your Card ID down below to create\na new one", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER, 100,50,300,100,hWnd,NULL,NULL,NULL);

            break;
        case FILE_BOOTH:
            CreateWindowW(L"static", L"1.Onion Rp15k\t6.FishtRp20k\n2.Garlic Rp20k\t7.Chicken Rp20k\n3.Brocolli Rp5k\t8.Spinach Rp5k\n4.Fungi Rp10k\t9.Banana Rp2k\n5.Peanut Rp1k\t10.Noodle Rp30k ", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_LEFT\
                          , 50,50,400,200,hWnd,NULL,NULL,NULL);
            break;
        case FILE_EXIT:
            MessageBeep(MB_OK);
            DestroyWindow(hWnd);
            break;

        }


        break;
    case WM_CREATE :
        AddMenus(hWnd);
        AddControls(hWnd);
        break;
    case WM_DESTROY :
        PostQuitMessage (0);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
}

void AddMenus(HWND hWnd) {
    hMenu = CreateMenu();
    HMENU hFileMenu = CreateMenu();
    HMENU hSubMenu = CreateMenu();

    //AppendMenu(hSubMenu,MF_STRING,NULL,"Change Title");

    //Sub Menu
 //   AppendMenu(hFileMenu,MF_STRING,FILE_MENU_NEWCARD,"New Card");
    //AppendMenu(hFileMenu,MF_STRING,SELECT_INPUT,"New Card");
 //   AppendMenu(hFileMenu,MF_STRING,FILE_MENU_TOPUPCARD,"Top Up Card");
 //   AppendMenu(hFileMenu,MF_STRING,FILE_MENU_REFUND,"Refund");
    AppendMenu(hFileMenu,MF_STRING,FILE_MENU_LISTCARD,"List Cards");
    AppendMenu(hFileMenu,MF_STRING,REFUND_INPUT,"Menu's");
    AppendMenu(hFileMenu,MF_SEPARATOR,NULL,NULL);
    //AppendMenu(hFileMenu, MF_STRING,FILE_MENU_BACKorEXIT,"Back/Exit");

    //Main Menu
    AppendMenu(hMenu,MF_POPUP, (UINT_PTR)hFileMenu, "Data");
   // AppendMenu(hMenu,MF_POPUP, (UINT_PTR)hFileMenu, "Booth");
    AppendMenu(hMenu,MF_STRING, FILE_EXIT, "Exit");


    SetMenu(hWnd,hMenu);
}
                                                                            //Middle allignment word
void AddControls(HWND hWnd) {                                  //add border around the text
    CreateWindowW(L"static", L"Please select the operation\n above or below", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER, 50,50,400,200,hWnd,NULL,NULL,NULL);
             //returns a handler to hEdit                                                       //multi line    auto scroll
   // hEdit = CreateWindowW(L"Edit",L"...",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER|ES_MULTILINE|ES_AUTOVSCROLL,200,300,100,50,hWnd,NULL,NULL,NULL);
//    hAns1 = CreateWindowW(L"Edit",L"...",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER|ES_MULTILINE|ES_AUTOVSCROLL,300,152,100,50,hWnd,NULL,NULL,NULL);
   // CreateWindowW(L"Button",L"Insert",WS_VISIBLE|WS_CHILD,400,204,100,50,hWnd,(HMENU)SELECT_INPUT,NULL,NULL);
  //  CreateWindowW(L"Button",L"New Card",WS_VISIBLE|WS_CHILD,0,204,100,50,hWnd,(HMENU)NEWCARD_INPUT,NULL,NULL);
    CreateWindowW(L"Button",L"List Of Cards",WS_VISIBLE|WS_CHILD,100,350,100,50,hWnd,(HMENU)TOPUPCARD_INPUT,NULL,NULL);
    CreateWindowW(L"Button",L"List Of Menus",WS_VISIBLE|WS_CHILD,300,350,100,50,hWnd,(HMENU)REFUND_INPUT,NULL,NULL);
  //  CreateWindowW(L"Button",L"Booth",WS_VISIBLE|WS_CHILD,300,204,100,50,hWnd,(HMENU)BOOTH_INPUT,NULL,NULL);

}








