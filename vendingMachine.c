#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void start(int *balance, int *choice);
void addMoney(int *balance, int *choice);
void products(int *balance, int *choice);
void drinks(int *balance, int *choice);
void chips(int *balance, int *choice);
void biscuits(int *balance, int *choice);
void packedLunch(int *balance, int *choice);
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main() {
    int balance = 500;
    int choice;
   printf("Welcome to Kuya JIRM's Vending Machine\n");
   printf("\nYour Balance: %d", balance);
   printf("\n");

    start(&balance, &choice);
    switch(choice){
        case 1:
          addMoney(&balance,&choice);
          break;
        case 2:
          printf("\n");
          products(&balance,&choice);
        break;
    }
    return 0;
}

void start(int *balance, int *choice){
   
   printf("\nFEATURES: \n");
   printf("\n");
   printf("Enter 1 => Add Money to your Account\n");
   printf("Enter 2 => Buy a product\n");
   printf("Enter 3 => My Purchased\n");
   printf("Enter 4 => View Product Stocks\n");
   printf("Enter 5 => Exit\n ");
   
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
        case 5:
          printf("\nGoodbye!\n");
          printf("\n");
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
    printf("\n");
    printf("How much do you want to add: ");
    scanf("%d",&deposit);
    if (scanf("%d", &deposit) != 1) {
        clearInputBuffer();
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nInvalid input. Please enter a whole number.\n");
        printf("\nYour Balance: %d\n", *balance);
        start(balance, choice);
        return;
    }

    if (deposit <= 0) {
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nInvalid Amount\n");
        printf("\nYour Balance: %d\n", *balance);
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
    printf("\nSuccesfully added %d to your balance\n",deposit );
    printf("\nYour New Balance is: %d", *balance);
    printf("\n");
    start(balance,choice);
    }else{
    system("clear");
    printf("\n");
    printf("Welcome to Kuya JIRM's Vending Machine\n");
    printf("\nNothing is added to your balance\n"); 
    printf("\nYour Balance: %d\n", *balance); 
    start(balance,choice);             
    }
}
void products(int *balance, int *choice){
   int innerChoice;
   int *pInnerChoice = &innerChoice;
   char arrProducts[5][50] = {"Drinks","Chips","Biscuits", "Packed -Lunch","BACK\n"};
   
   printf("\nMENU: \n");
   printf("\n");
   int size = sizeof(arrProducts)/ sizeof(arrProducts[0]);
   for(int i = 0; i < size; i++){
        printf(" Enter %d => %s\n",i+1,arrProducts[i]);
   }
   printf("\n Please choose what food do you prefer:  ");
   scanf("%d", &innerChoice);

   
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
            printf("\nPACKED-LUNCH:\n");
            packedLunch(balance,choice);
            break;
        case 5:
            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nYour Balance: %d\n", *balance);
            start(balance,choice);
            printf("\n");
            break;
        default:
          system("clear");
          printf("\n");
          printf("Welcome to Kuya JIRM's Vending Machine\n");
          printf("\nYour Balance: %d\n", *balance);
          printf("\nInvalid\n");
          start(balance,choice);
          printf("\n");
          break;
   }
}

void drinks(int *balance, int *choice){
    char proceed;
    char innerChoice;
    char arrString[5][50] ={"Enter A => Coke - 25","Enter B => Sprite - 25","Enter C => Royal - 25","Enter D => Coffee -50","Enter E => Water -15"};
    
    int size = sizeof(arrString)/ sizeof(arrString[0]);
    printf("\n");
    for(int i = 0; i < size; i++){
        printf(" %s\n",arrString[i]);
    }
    
    printf("\nWhat do you want to buy: ");
    scanf(" %c", &innerChoice);
    printf("\n");
    if(innerChoice == 'A' || innerChoice == 'a' || innerChoice == 'B' || innerChoice == 'b' || innerChoice == 'C' || innerChoice == 'c' || innerChoice == 'D' || innerChoice == 'd' || innerChoice == 'E' || innerChoice == 'e'){
    printf("This will deduct to your account, Continue? Y/N: ");
    scanf(" %c",&proceed);
    }else{
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nInvalid\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your Balance: %d", *balance);
        start(balance,choice);  
    }
    
    if(proceed == 'Y' || proceed == 'y'){
        switch(innerChoice){
        case 'A':
        case 'a':
        *balance -= 25;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'B':
        case 'b':
        *balance -= 25;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'C':
        case 'c':
        *balance -= 25;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'D':
        case 'd':
        *balance -= 50;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'E':
        case 'e':
        *balance -= 15;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        default:
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nInvalid\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your Balance: %d", *balance);
        start(balance,choice);
        }
        }else{
            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nOrder was cancelled, nothing is deducted to your account\n");
            printf("\n");
            start(balance,choice);
    }
}

void chips(int *balance, int *choice){
    char proceed;
    char innerChoice;
    char arrString[5][50] ={"Enter A => Coke - 25","Enter B => Sprite - 25","Enter C => Royal - 25","Enter D => Coffee -50","Enter E => Water -15"};
    
    int size = sizeof(arrString)/ sizeof(arrString[0]);
    printf("\n");
    for(int i = 0; i < size; i++){
        printf(" %s\n",arrString[i]);
    }
    
    printf("\nWhat do you want to buy: ");
    scanf(" %c", &innerChoice);
    printf("\n");
    if(innerChoice == 'A' || innerChoice == 'a' || innerChoice == 'B' || innerChoice == 'b' || innerChoice == 'C' || innerChoice == 'c' || innerChoice == 'D' || innerChoice == 'd' || innerChoice == 'E' || innerChoice == 'e'){
    printf("This will deduct to your account, Continue? Y/N: ");
    scanf(" %c",&proceed);
    }else{
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nInvalid\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your Balance: %d", *balance);
        start(balance,choice);  
    }
    
    if(proceed == 'Y' || proceed == 'y'){
        switch(innerChoice){
        case 'A':
        case 'a':
        *balance -= 25;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'B':
        case 'b':
        *balance -= 25;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'C':
        case 'c':
        *balance -= 25;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'D':
        case 'd':
        *balance -= 50;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'E':
        case 'e':
        *balance -= 15;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        }
        }else{
            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nOrder was cancelled, nothing is deducted to your account\n");
            printf("\n");
            start(balance,choice);
    }
}

void biscuits(int *balance, int *choice){
    char proceed;
    char innerChoice;
    char arrString[5][50] ={"Enter A => Coke - 25","Enter B => Sprite - 25","Enter C => Royal - 25","Enter D => Coffee -50","Enter E => Water -15"};
    
    int size = sizeof(arrString)/ sizeof(arrString[0]);
    printf("\n");
    for(int i = 0; i < size; i++){
        printf(" %s\n",arrString[i]);
    }
    
    printf("\nWhat do you want to buy: ");
    scanf(" %c", &innerChoice);
    printf("\n");
    if(innerChoice == 'A' || innerChoice == 'a' || innerChoice == 'B' || innerChoice == 'b' || innerChoice == 'C' || innerChoice == 'c' || innerChoice == 'D' || innerChoice == 'd' || innerChoice == 'E' || innerChoice == 'e'){
    printf("This will deduct to your account, Continue? Y/N: ");
    scanf(" %c",&proceed);
    }else{
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nInvalid\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your Balance: %d", *balance);
        start(balance,choice);  
    }
    
    if(proceed == 'Y' || proceed == 'y'){
        switch(innerChoice){
        case 'A':
        case 'a':
        *balance -= 25;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'B':
        case 'b':
        *balance -= 25;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'C':
        case 'c':
        *balance -= 25;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'D':
        case 'd':
        *balance -= 50;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'E':
        case 'e':
        *balance -= 15;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        }
        }else{
            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nOrder was cancelled, nothing is deducted to your account\n");
            printf("\n");
            start(balance,choice);
    }
}

void packedLunch(int *balance, int *choice){
    char proceed;
    char innerChoice;
    char arrString[5][50] ={"Enter A => Coke - 25","Enter B => Sprite - 25","Enter C => Royal - 25","Enter D => Coffee -50","Enter E => Water -15"};
    
    int size = sizeof(arrString)/ sizeof(arrString[0]);
    printf("\n");
    for(int i = 0; i < size; i++){
        printf(" %s\n",arrString[i]);
    }
    
    printf("\nWhat do you want to buy: ");
    scanf(" %c", &innerChoice);
    printf("\n");
    if(innerChoice == 'A' || innerChoice == 'a' || innerChoice == 'B' || innerChoice == 'b' || innerChoice == 'C' || innerChoice == 'c' || innerChoice == 'D' || innerChoice == 'd' || innerChoice == 'E' || innerChoice == 'e'){
    printf("This will deduct to your account, Continue? Y/N: ");
    scanf(" %c",&proceed);
    }else{
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nInvalid\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your Balance: %d", *balance);
        start(balance,choice);  
    }
    
    if(proceed == 'Y' || proceed == 'y'){
        switch(innerChoice){
        case 'A':
        case 'a':
        *balance -= 25;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'B':
        case 'b':
        *balance -= 25;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'C':
        case 'c':
        *balance -= 25;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'D':
        case 'd':
        *balance -= 50;
        system("clear");
        printf("\n");
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        case 'E':
        case 'e':
        *balance -= 15;
        system("clear");
        printf("\n");                   
        printf("Welcome to Kuya JIRM's Vending Machine\n");
        printf("\nSuccessfull Transaction...ThankYou for chosing JIRM's Vending Shop!\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  Your New Balance is: %d", *balance);
        start(balance,choice);
        break;
        }
        }else{
            system("clear");
            printf("\n");
            printf("Welcome to Kuya JIRM's Vending Machine\n");
            printf("\nOrder was cancelled, nothing is deducted to your account\n");
            printf("\n");
            start(balance,choice);
    }
}           








