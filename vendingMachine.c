#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void start(int *balance, int *choice);
void addMoney(int *balance, int *choice);
void products(int *balance, int *choice);
void drinks(int *balance, int *choice);
void chips(int *balance, int *choice);
void biscuits(int *balance, int *choice);
void instantNoodles(int *balance, int *choice);
void savePurchase(char productName[], int price);
void viewPurchased();
void viewStocks();
void initializeStocks();
int getStock(char productName[]);
void updateStock(char productName[]);

int main() {

    int balance = 500;
    int choice;

    initializeStocks();

    printf("Welcome to Kuya JIRM's Vending Machine\n");
    printf("\nYour Balance: %d", balance);
    printf("\n");

    start(&balance, &choice);

    return 0;
}

void start(int *balance, int *choice){

   printf("\nFEATURES:\n");
   printf("\n");
   printf("Enter 1 => Add Money to your Account\n");
   printf("Enter 2 => Buy a product\n");
   printf("Enter 3 => My Purchased\n");
   printf("Enter 4 => View Product Stocks\n");
   printf("Enter 5 => Exit\n");

   printf("\nPlease select a Feature: ");
   scanf("%d", choice);

   system("clear");

   switch(*choice){

        case 1:
          printf("\n");
          printf("Welcome to Kuya JIRM's Vending Machine\n");
          printf("\nYour Balance: %d\n", *balance);
          addMoney(balance,choice);
          break;

        case 2:
          printf("\n");
          printf("Welcome to Kuya JIRM's Vending Machine\n");
          printf("\nYour Balance: %d\n", *balance);
          products(balance,choice);
          break;

        case 3:
          printf("\n");
          printf("Welcome to Kuya JIRM's Vending Machine\n");
          viewPurchased();
          start(balance,choice);
          break;

        case 4:
          printf("\n");
          printf("Welcome to Kuya JIRM's Vending Machine\n");
          viewStocks();
          start(balance,choice);
          break;

        case 5:
          printf("\nGoodbye!\n");
          exit(0);
          break;

        default:
          printf("\nInvalid choice.\n");
          start(balance,choice);
          break;
    }
}

void addMoney(int *balance, int *choice){

    char toContinue;
    int deposit;

    printf("\nHow much do you want to add: ");

    if (scanf("%d", &deposit) != 1) {
        system("clear");  
        printf("\n");      
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nYour Balance: %d", *balance);
        printf("\n");  
        printf("\nInvalid input! Numbers only.\n");
        while (getchar() != '\n');
        start(balance, choice);
        return;
    }else if (deposit <= 0) {
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nYour Balance: %d", *balance);
        printf("\n");
        printf("\nInvalid input! Please enter a positive amount.\n");
        start(balance, choice);
        return;
    }

    printf("\nContinue? (Y/N): ");
    scanf(" %c", &toContinue);

    if(toContinue == 'Y' || toContinue == 'y'){

        *balance += deposit;

        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfully added %d to your balance\n", deposit);
        printf("\n");
        printf("New Balance: %d\n", *balance);

        start(balance, choice);
    }
    else {
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nNothing is added.\n");
        printf("\n");
        printf("Your Balance: %d\n", *balance);

        start(balance, choice);
    }
}

void products(int *balance, int *choice){

   int innerChoice;

   char arrProducts[5][50] = {
       "Drinks",
       "Chips",
       "Biscuits",
       "Packed-Lunch",
       "BACK"
   };

   printf("\nMENU:\n");
   printf("\n");

   int size = sizeof(arrProducts)/ sizeof(arrProducts[0]);

   for(int i = 0; i < size; i++){
        printf(" Enter %d => %s\n",i+1,arrProducts[i]);
   }

    printf("\nPlease choose what food do you prefer: ");
    while (scanf("%d", &innerChoice) != 1) {
    system("clear");
    printf("\n");
    printf("Welcome to Kuya JIRM's Vending Machine\n");
    printf("\nYour Balance: %d\n", *balance);
    printf("\nInvalid input! Please enter a whole number only: ");
    while (getchar() != '\n');
    printf("\n");
    start(balance,choice);
}


   switch(innerChoice){

        case 1:
            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nYour Balance: %d\n", *balance);
            printf("\nDRINKS:\n");
            drinks(balance,choice);
            break;

        case 2:
            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nYour Balance: %d\n", *balance);
            printf("\nCHIPS:\n");
            chips(balance,choice);
            break;

        case 3:
            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nYour Balance: %d\n", *balance);
            printf("\nBISCUITS:\n");
            biscuits(balance,choice);
            break;

        case 4:
            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nYour Balance: %d\n", *balance);
            printf("\nINSTANT NOODLES:\n");
            instantNoodles(balance,choice);
            break;

        case 5:
            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nYour Balance: %d\n", *balance);
            start(balance,choice);
            break;

        default:
            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nYour Balance: %d\n", *balance);
            printf("\nInvalid\n");
            start(balance,choice);
            break;
   }
}

void drinks(int *balance, int *choice){

    char proceed;
    char innerChoice;

    char arrString[5][50] ={
        "Enter A => Coke - 25",
        "Enter B => Sprite - 25",
        "Enter C => Royal - 25",
        "Enter D => Coffee - 50",
        "Enter E => Water - 15"
    };

    int size = sizeof(arrString)/ sizeof(arrString[0]);

    printf("\n");

    for(int i = 0; i < size; i++){
        printf("%s\n",arrString[i]);
    }

    printf("\nWhat do you want to buy: ");
    scanf(" %c", &innerChoice);

    if(innerChoice == 'A' || innerChoice == 'a' ||
       innerChoice == 'B' || innerChoice == 'b' ||
       innerChoice == 'C' || innerChoice == 'c' ||
       innerChoice == 'D' || innerChoice == 'd' ||
       innerChoice == 'E' || innerChoice == 'e'){
        
        printf("\nThis will deduct to your account, Continue? Y/N: ");
        scanf(" %c",&proceed);

    }else{
        system("clear");
        printf("\nWelcome to Kuya JIRM's Vending Machine\n");
        printf("\nYour Balance: %d",*balance);
        printf("\nInvalid\n");
        start(balance,choice);
    }

    if(proceed == 'Y' || proceed == 'y'){

        switch(innerChoice){

        case 'A':
        case 'a':

            if(getStock("Coke") <= 0){
                printf("\nCoke is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 25;

            savePurchase("Coke",25);
            updateStock("Coke");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought Coke\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'B':
        case 'b':

            if(getStock("Sprite") <= 0){
                printf("\nSprite is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 25;

            savePurchase("Sprite",25);
            updateStock("Sprite");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought Sprite\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'C':
        case 'c':

            if(getStock("Royal") <= 0){
                printf("\nRoyal is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 25;

            savePurchase("Royal",25);
            updateStock("Royal");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought Royal\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'D':
        case 'd':

            if(getStock("Coffee") <= 0){
                printf("\nCoffee is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 50;

            savePurchase("Coffee",50);
            updateStock("Coffee");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought Coffee\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'E':
        case 'e':

            if(getStock("Water") <= 0){
                printf("\nWater is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 15;

            savePurchase("Water",15);
            updateStock("Water");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought Water\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        default:
            printf("\nInvalid Choice\n");
            start(balance,choice);
        }

    }else{

        printf("\nOrder Cancelled\n");
        start(balance,choice);
    }
}

void chips(int *balance, int *choice){

    char proceed;
    char innerChoice;

    char arrString[5][50] ={
        "Enter A => Mang Juan - 25",
        "Enter B => Patata - 25",
        "Enter C => Nova - 25",
        "Enter D => Piatos - 25",
        "Enter E => Oishi - 25"
    };

    int size = sizeof(arrString)/ sizeof(arrString[0]);

    printf("\n");

    for(int i = 0; i < size; i++){
        printf("%s\n",arrString[i]);
    }

    printf("\nWhat do you want to buy: ");
    scanf(" %c", &innerChoice);

    if(innerChoice == 'A' || innerChoice == 'a' ||
       innerChoice == 'B' || innerChoice == 'b' ||
       innerChoice == 'C' || innerChoice == 'c' ||
       innerChoice == 'D' || innerChoice == 'd' ||
       innerChoice == 'E' || innerChoice == 'e'){

        printf("\nThis will deduct to your account, Continue? Y/N: ");
        scanf(" %c",&proceed);

    }else{

        system("clear");

        printf("\nInvalid\n");

        start(balance,choice);
    }

    if(proceed == 'Y' || proceed == 'y'){

        switch(innerChoice){

        case 'A':
        case 'a':

            if(getStock("MangJuan") <= 0){
                printf("\nMang Juan is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 25;

            savePurchase("Mang Juan",25);
            updateStock("MangJuan");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought Mang Juan\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'B':
        case 'b':

            if(getStock("Patata") <= 0){
                printf("\nPatata is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 25;

            savePurchase("Patata",25);
            updateStock("Patata");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought Patata\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'C':
        case 'c':

            if(getStock("Nova") <= 0){
                printf("\nNova is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 25;

            savePurchase("Nova",25);
            updateStock("Nova");

            system("clear");

            printf("\nSuccessfully bought Nova\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'D':
        case 'd':

            if(getStock("Piatos") <= 0){
                printf("\nPiatos is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 25;

            savePurchase("Piatos",25);
            updateStock("Piatos");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought Piatos\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'E':
        case 'e':

            if(getStock("Oishi") <= 0){
                printf("\nOishi is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 25;

            savePurchase("Oishi",25);
            updateStock("Oishi");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought Oishi\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        default:
            printf("\nInvalid Choice\n");
            start(balance,choice);
        }

    }else{

        printf("\nOrder Cancelled\n");
        start(balance,choice);
    }
}

void biscuits(int *balance, int *choice){

    char proceed;
    char innerChoice;

    char arrString[5][50] ={
        "Enter A => Oreo - 15",
        "Enter B => Combi - 15",
        "Enter C => Skyflakes - 15",
        "Enter D => Fita - 15",
        "Enter E => FudgeeBar - 15"
    };

    int size = sizeof(arrString)/ sizeof(arrString[0]);

    printf("\n");

    for(int i = 0; i < size; i++){
        printf("%s\n",arrString[i]);
    }

    printf("\nWhat do you want to buy: ");
    scanf(" %c", &innerChoice);

    if(innerChoice == 'A' || innerChoice == 'a' ||
       innerChoice == 'B' || innerChoice == 'b' ||
       innerChoice == 'C' || innerChoice == 'c' ||
       innerChoice == 'D' || innerChoice == 'd' ||
       innerChoice == 'E' || innerChoice == 'e'){

        printf("\nThis will deduct to your account, Continue? Y/N: ");
        scanf(" %c",&proceed);

    }else{

        system("clear");

        printf("\nInvalid\n");

        start(balance,choice);
    }

    if(proceed == 'Y' || proceed == 'y'){

        switch(innerChoice){

        case 'A':
        case 'a':

            if(getStock("Oreo") <= 0){
                printf("\nOreo is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 15;

            savePurchase("Oreo",15);
            updateStock("Oreo");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought Oreo\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'B':
        case 'b':

            if(getStock("Combi") <= 0){
                printf("\nCombi is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 15;

            savePurchase("Combi",15);
            updateStock("Combi");

            system("clear");

            printf("\nSuccessfully bought Combi\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'C':
        case 'c':

            if(getStock("Skyflakes") <= 0){
                printf("\nSkyflakes is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 15;

            savePurchase("Skyflakes",15);
            updateStock("Skyflakes");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought Skyflakes\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'D':
        case 'd':

            if(getStock("Fita") <= 0){
                printf("\nFita is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 15;

            savePurchase("Fita",15);
            updateStock("Fita");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought Fita\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'E':
        case 'e':

            if(getStock("FudgeeBar") <= 0){
                printf("\nFudgeeBar is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 15;

            savePurchase("FudgeeBar",15);
            updateStock("FudgeeBar");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought FudgeeBar\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        default:
            printf("\nInvalid Choice\n");
            start(balance,choice);
        }

    }else{

        printf("\nOrder Cancelled\n");
        start(balance,choice);
    }
}

void instantNoodles(int *balance, int *choice){

    char proceed;
    char innerChoice;

    char arrString[5][50] ={
        "Enter A => ChickenFlavor - 50",
        "Enter B => BeefFlavor - 50",
        "Enter C => PorkFlavor - 50",
        "Enter D => Hot&Spicy - 50",
        "Enter E => SeafoodFlavor - 50"
    };

    int size = sizeof(arrString)/ sizeof(arrString[0]);

    printf("\n");

    for(int i = 0; i < size; i++){
        printf("%s\n",arrString[i]);
    }

    printf("\nWhat do you want to buy: ");
    scanf(" %c", &innerChoice);

    if(innerChoice == 'A' || innerChoice == 'a' ||
       innerChoice == 'B' || innerChoice == 'b' ||
       innerChoice == 'C' || innerChoice == 'c' ||
       innerChoice == 'D' || innerChoice == 'd' ||
       innerChoice == 'E' || innerChoice == 'e'){

        printf("\nThis will deduct to your account, Continue? Y/N: ");
        scanf(" %c",&proceed);

    }else{

        system("clear");

        printf("\nInvalid\n");

        start(balance,choice);
    }

    if(proceed == 'Y' || proceed == 'y'){

        switch(innerChoice){

        case 'A':
        case 'a':

            if(getStock("ChickenFlavor") <= 0){
                printf("\nChickenFlavor is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 50;

            savePurchase("ChickenFlavor",50);
            updateStock("ChickenFlavor");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought ChickenFlavor\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'B':
        case 'b':

            if(getStock("BeefFlavor") <= 0){
                printf("\nBeefFlavor is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 50;

            savePurchase("BeefFlavor",50);
            updateStock("BeefFlavor");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought BeefFlavor\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'C':
        case 'c':

            if(getStock("PorkFlavor") <= 0){
                printf("\nPorkFlavor is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 50;

            savePurchase("PorkFlavor",50);
            updateStock("PorkFlavor");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought PorkFlavor\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'D':
        case 'd':

            if(getStock("HotSpicy") <= 0){
                printf("\nHot&Spicy is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 50;

            savePurchase("Hot&Spicy",50);
            updateStock("HotSpicy");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought Hot&Spicy\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        case 'E':
        case 'e':

            if(getStock("SeafoodFlavor") <= 0){
                printf("\nSeafoodFlavor is OUT OF STOCK!\n");
                start(balance,choice);
            }

            *balance -= 50;

            savePurchase("SeafoodFlavor",50);
            updateStock("SeafoodFlavor");

            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nSuccessfully bought SeafoodFlavor\n");
            printf("\nYour New Balance is: %d\n", *balance);

            start(balance,choice);
            break;

        default:

            printf("\nInvalid Choice\n");
            start(balance,choice);
        }

    }else{

        printf("\nOrder Cancelled\n");
        start(balance,choice);
    }
}

void initializeStocks(){

    FILE *fp;

    fp = fopen("stocks.txt","r");

    if(fp == NULL){

        fp = fopen("stocks.txt","w");

        /* DRINKS */
        fprintf(fp,"Coke 10\n");
        fprintf(fp,"Sprite 10\n");
        fprintf(fp,"Royal 10\n");
        fprintf(fp,"Coffee 10\n");
        fprintf(fp,"Water 10\n");

        /* CHIPS */
        fprintf(fp,"MangJuan 10\n");
        fprintf(fp,"Patata 10\n");
        fprintf(fp,"Nova 10\n");
        fprintf(fp,"Piatos 10\n");
        fprintf(fp,"Oishi 10\n");

        /* BISCUITS */
        fprintf(fp,"Oreo 10\n");
        fprintf(fp,"Combi 10\n");
        fprintf(fp,"Skyflakes 10\n");
        fprintf(fp,"Fita 10\n");
        fprintf(fp,"FudgeeBar 10\n");

        /* INSTANT NOODLES */
        fprintf(fp,"ChickenFlavor 10\n");
        fprintf(fp,"BeefFlavor 10\n");
        fprintf(fp,"PorkFlavor 10\n");
        fprintf(fp,"HotSpicy 10\n");
        fprintf(fp,"SeafoodFlavor 10\n");

        fclose(fp);

    }else{

        fclose(fp);
    }
}

void savePurchase(char productName[], int price){

    FILE *fp;

    fp = fopen("purchases.txt","a");

    fprintf(fp,"%s - %d pesos\n", productName, price);

    fclose(fp);
}

void viewPurchased(){

    FILE *fp;

    char line[100];

    fp = fopen("purchases.txt","r");

    if(fp == NULL){

        printf("\nNo purchases yet.\n");
        return;
    }

    printf("\nPURCHASE HISTORY:\n\n");

    while(fgets(line,sizeof(line),fp)){

        printf("%s", line);
    }

    fclose(fp);

    printf("\n");
}

void viewStocks(){

    FILE *fp;

    char product[50];
    int stock;

    fp = fopen("stocks.txt","r");

    if(fp == NULL){

        printf("\nNo stock file found.\n");
        return;
    }

    printf("\nAVAILABLE STOCKS:\n\n");

    while(fscanf(fp,"%s %d", product, &stock) != EOF){

        printf("%s = %d\n", product, stock);
    }

    fclose(fp);

    printf("\n");
}

int getStock(char productName[]){

    FILE *fp;

    char product[50];
    int stock;

    fp = fopen("stocks.txt","r");

    while(fscanf(fp,"%s %d", product, &stock) != EOF){

        if(strcmp(product, productName) == 0){

            fclose(fp);

            return stock;
        }
    }

    fclose(fp);

    return 0;
}

void updateStock(char productName[]){

    FILE *fp;
    FILE *temp;

    char product[50];
    int stock;

    fp = fopen("stocks.txt","r");
    temp = fopen("temp.txt","w");

    while(fscanf(fp,"%s %d", product, &stock) != EOF){

        if(strcmp(product, productName) == 0){

            stock--;
        }

        fprintf(temp,"%s %d\n", product, stock);
    }

    fclose(fp);
    fclose(temp);

    remove("stocks.txt");
    rename("temp.txt","stocks.txt");
}