#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

typedef struct{
    char code;
    char name[50];
    int price;
    char stockName[50];
} Product;

void start(int *balance);
void addMoney(int *balance);
void products(int *balance);
void buyProduct(int *balance, Product items[], int size, char category[]);
void savePurchase(char productName[], int price, int quantity);
void viewPurchased();
void viewStocks();
void initializeStocks();
int getStock(char productName[]);
void updateStock(char productName[], int quantity);
void clearInputBuffer();
char getSingleChar();
void pauseScreen();
void header(int balance){

    system(CLEAR);

    printf("\nWelcome to Kuya JIRM's Vending Machine\n");
    printf("\nYour Balance: %d\n", balance);
}

int main(){

    int balance = 500;

    initializeStocks();

    while(1){

        header(balance);

        start(&balance);
    }

    return 0;
}

void clearInputBuffer(){

    int c;

    while((c = getchar()) != '\n' && c != EOF);
}

void pauseScreen(){

    printf("\nPress Enter to continue...");
    getchar();
}

char getSingleChar(){

    char input[100];

    if(fgets(input, sizeof(input), stdin) == NULL){

        return '\0';
    }

    if(strlen(input) != 2 || input[1] != '\n'){

        return '\0';
    }

    return input[0];
}

void start(int *balance){

    int choice;

    printf("\nFEATURES:\n\n");

    printf("Enter 1 => Add Money\n");
    printf("Enter 2 => Buy Product\n");
    printf("Enter 3 => My Purchased\n");
    printf("Enter 4 => View Stocks\n");
    printf("Enter 5 => Exit\n");

    printf("\nSelect Feature: ");

    if(scanf("%d",&choice) != 1){

        clearInputBuffer();

        header(*balance);

        printf("\nInvalid Input! Numbers only.\n");

        pauseScreen();

        return;
    }

    clearInputBuffer();

    switch(choice){

        case 1:
            header(*balance);
            addMoney(balance);
            break;

        case 2:
            header(*balance);
            products(balance);
            break;

        case 3:
            header(*balance);
            viewPurchased();
            pauseScreen();
            break;

        case 4:
            header(*balance);
            viewStocks();
            pauseScreen();
            break;

        case 5:
            printf("\nGoodbye!\n");
            exit(0);

        default:
            header(*balance);

            printf("\nInvalid Choice\n");

            pauseScreen();
    }
}

void addMoney(int *balance){

    int deposit;

    char proceed;

    printf("\nHow much do you want to add: ");

    if(scanf("%d",&deposit) != 1){

        clearInputBuffer();

        header(*balance);

        printf("\nInvalid Input! Numbers only.\n");

        pauseScreen();

        return;
    }

    clearInputBuffer();

    if(deposit <= 0){

        header(*balance);

        printf("\nPlease enter a positive amount.\n");

        pauseScreen();

        return;
    }

    if(*balance > 2147483647 - deposit){

        header(*balance);

        printf("\nBalance limit exceeded.\n");

        pauseScreen();

        return;
    }

    printf("\nContinue? Y/N: ");

    proceed = getSingleChar();

    if(proceed == '\0'){

        header(*balance);

        printf("\nOnly ONE character is allowed!\n");

        pauseScreen();

        return;
    }

    if(proceed >= 'A' && proceed <= 'Z'){

        proceed = proceed + 32;
    }

    if(proceed == 'y'){

        *balance += deposit;

        header(*balance);

        printf("\nSuccessfully added %d\n", deposit);

        printf("\nNew Balance: %d\n", *balance);

    }else if(proceed == 'n'){

        header(*balance);

        printf("\nNothing Added\n");

        printf("\nBalance: %d\n", *balance);

    }else{

        header(*balance);

        printf("\nInvalid Choice\n");
    }

    pauseScreen();
}

void products(int *balance){

    int choice;

    Product drinks[] = {
        {'A',"Coke",25,"Coke"},
        {'B',"Sprite",25,"Sprite"},
        {'C',"Royal",25,"Royal"},
        {'D',"Coffee",50,"Coffee"},
        {'E',"Water",15,"Water"}
    };

    Product chips[] = {
        {'A',"Mang Juan",25,"MangJuan"},
        {'B',"Patata",25,"Patata"},
        {'C',"Nova",25,"Nova"},
        {'D',"Piatos",25,"Piatos"},
        {'E',"Oishi",25,"Oishi"}
    };

    Product biscuits[] = {
        {'A',"Oreo",15,"Oreo"},
        {'B',"Combi",15,"Combi"},
        {'C',"Skyflakes",15,"Skyflakes"},
        {'D',"Fita",15,"Fita"},
        {'E',"FudgeeBar",15,"FudgeeBar"}
    };

    Product noodles[] = {
        {'A',"ChickenFlavor",50,"ChickenFlavor"},
        {'B',"BeefFlavor",50,"BeefFlavor"},
        {'C',"PorkFlavor",50,"PorkFlavor"},
        {'D',"Hot&Spicy",50,"HotSpicy"},
        {'E',"SeafoodFlavor",50,"SeafoodFlavor"}
    };

    printf("\nMENU:\n\n");

    printf("1 => Drinks\n");
    printf("2 => Chips\n");
    printf("3 => Biscuits\n");
    printf("4 => Instant Noodles\n");
    printf("5 => Back\n");

    printf("\nSelect Menu: ");

    if(scanf("%d",&choice) != 1){

        clearInputBuffer();

        header(*balance);

        printf("\nInvalid Input! Numbers only.\n");

        pauseScreen();

        return;
    }

    clearInputBuffer();

    switch(choice){

        case 1:
            buyProduct(balance, drinks, 5, "DRINKS");
            break;

        case 2:
            buyProduct(balance, chips, 5, "CHIPS");
            break;

        case 3:
            buyProduct(balance, biscuits, 5, "BISCUITS");
            break;

        case 4:
            buyProduct(balance, noodles, 5, "INSTANT NOODLES");
            break;

        case 5:
            return;

        default:
            header(*balance);

            printf("\nInvalid Choice\n");

            pauseScreen();
    }
}

void buyProduct(int *balance, Product items[], int size, char category[]){

    char choice;
    char proceed;

    int quantity;
    int totalPrice;

    header(*balance);

    printf("\n%s:\n\n", category);

    for(int i = 0; i < size; i++){

        printf("Enter %c => %s - %d pesos (Stock: %d)\n",
               items[i].code,
               items[i].name,
               items[i].price,
               getStock(items[i].stockName));
    }

    printf("\nWhat do you want to buy: ");

    choice = getSingleChar();

    if(choice == '\0'){

        header(*balance);

        printf("\nOnly ONE character is allowed!\n");

        pauseScreen();

        return;
    }

    if(choice >= 'a' && choice <= 'z'){

        choice = choice - 32;
    }

    int found = -1;

    for(int i = 0; i < size; i++){

        if(choice == items[i].code){

            found = i;

            break;
        }
    }

    if(found == -1){

        header(*balance);

        printf("\nInvalid Choice\n");

        pauseScreen();

        return;
    }

    printf("\nEnter Quantity: ");

    if(scanf("%d",&quantity) != 1){

        clearInputBuffer();

        header(*balance);

        printf("\nInvalid Input! Numbers only.\n");

        pauseScreen();

        return;
    }

    clearInputBuffer();

    if(quantity <= 0){

        header(*balance);

        printf("\nQuantity must be greater than 0.\n");

        pauseScreen();

        return;
    }

    if(quantity > 1000000){

        header(*balance);

        printf("\nQuantity too large.\n");

        pauseScreen();

        return;
    }

    if(getStock(items[found].stockName) < quantity){

        header(*balance);

        printf("\nInsufficient Stock!\n");

        printf("\nAvailable Stock: %d\n",
               getStock(items[found].stockName));

        pauseScreen();

        return;
    }

    totalPrice = items[found].price * quantity;

    if(*balance < totalPrice){

        header(*balance);

        printf("\nInsufficient Balance!\n");

        printf("\nTotal Price: %d\n", totalPrice);

        printf("Your Balance: %d\n", *balance);

        pauseScreen();

        return;
    }

    printf("\nTotal Price: %d\n", totalPrice);

    printf("\nContinue? Y/N: ");

    proceed = getSingleChar();

    if(proceed == '\0'){

        header(*balance);

        printf("\nOnly ONE character is allowed!\n");

        pauseScreen();

        return;
    }

    if(proceed >= 'A' && proceed <= 'Z'){

        proceed = proceed + 32;
    }

    if(proceed != 'y' && proceed != 'n'){

        header(*balance);

        printf("\nInvalid Choice\n");

        pauseScreen();

        return;
    }

    if(proceed == 'n'){

        printf("\nOrder Cancelled\n");

        pauseScreen();

        return;
    }

    *balance -= totalPrice;

    savePurchase(items[found].name,
                 items[found].price,
                 quantity);

    updateStock(items[found].stockName,
                quantity);

    header(*balance);

    printf("\nSuccessfully bought %d %s\n",
           quantity,
           items[found].name);

    printf("\nTotal Deducted: %d\n", totalPrice);

    printf("\nYour New Balance is: %d\n", *balance);

    pauseScreen();
}

void initializeStocks(){

    FILE *fp = fopen("stocks.txt","r");

    if(fp == NULL){

        fp = fopen("stocks.txt","w");

        if(fp == NULL){

            printf("\nError creating stock file.\n");
            return;
        }

        char *products[] = {
            "Coke","Sprite","Royal","Coffee","Water",
            "MangJuan","Patata","Nova","Piatos","Oishi",
            "Oreo","Combi","Skyflakes","Fita","FudgeeBar",
            "ChickenFlavor","BeefFlavor","PorkFlavor",
            "HotSpicy","SeafoodFlavor"
        };

        for(int i = 0; i < 20; i++){

            fprintf(fp,"%s 10\n", products[i]);
        }
    }

    fclose(fp);
}

void savePurchase(char productName[],
                  int price,
                  int quantity){

    FILE *fp = fopen("purchases.txt","a");

    if(fp == NULL){

        printf("\nError opening purchases file.\n");

        return;
    }

    fprintf(fp,
            "%s x%d - %d pesos\n",
            productName,
            quantity,
            price * quantity);

    fclose(fp);
}

void viewPurchased(){

    FILE *fp = fopen("purchases.txt","r");

    char line[100];

    if(fp == NULL){

        printf("\nNo Purchases Yet\n");

        return;
    }

    printf("\nPURCHASE HISTORY:\n\n");

    int empty = 1;

    while(fgets(line,sizeof(line),fp)){

        printf("%s",line);
        empty = 0;
    }

    if(empty){

        printf("No Purchases Yet\n");
    }

    fclose(fp);

    printf("\n");
}

void viewStocks(){

    FILE *fp = fopen("stocks.txt","r");

    char product[50];
    int stock;

    if(fp == NULL){

        printf("\nNo stock file found.\n");

        return;
    }

    printf("\nAVAILABLE STOCKS:\n\n");

    while(fscanf(fp,"%49s %d",
                 product,
                 &stock) != EOF){

        printf("%s = %d\n",
               product,
               stock);
    }

    fclose(fp);

    printf("\n");
}

int getStock(char productName[]){

    FILE *fp = fopen("stocks.txt","r");

    char product[50];
    int stock;

    if(fp == NULL){

        return -1;
    }

    while(fscanf(fp,"%49s %d",
                 product,
                 &stock) != EOF){

        if(strcmp(product,productName) == 0){

            fclose(fp);

            return stock;
        }
    }

    fclose(fp);

    return -1;
}

void updateStock(char productName[],
                 int quantity){

    FILE *fp = fopen("stocks.txt","r");

    FILE *temp = fopen("temp.txt","w");

    char product[50];
    int stock;

    if(fp == NULL || temp == NULL){

        printf("\nError updating stock.\n");

        if(fp != NULL){
            fclose(fp);
        }

        if(temp != NULL){
            fclose(temp);
        }

        return;
    }

    while(fscanf(fp,"%49s %d",
                 product,
                 &stock) != EOF){

        if(strcmp(product,
                  productName) == 0){

            stock -= quantity;
        }

        fprintf(temp,"%s %d\n",
                product,
                stock);
    }

    fclose(fp);
    fclose(temp);

    if(remove("stocks.txt") != 0){

        printf("\nError deleting old stock file.\n");
        return;
    }

    if(rename("temp.txt","stocks.txt") != 0){

        printf("\nError renaming temp file.\n");
    }
}

