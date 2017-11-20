/*****************************************************************
//
// NAME: YuJin Kim
//
// HOMEWORK: Programming Assignment 2 - User & Transaction Validation
//
// CLASS: ICS 355
//
// INSTRUCTOR: Daniel Clark
//
// DATE: November 19, 2017
//
// FILE: main.c
//
// DESCRIPTION: This file contains the driver and the user-interface functions
// for Programming Assignment 2 - User & Transaction Validation
//
//****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include "record.h"
#include "functions.h"

float totalAmount = 0;
char usrName[50], pasWord[50];

/*****************************************************************
//
// Function name: userMenu
//
// DESCRIPTION: A userinterface function for normal users.
// This function allows a user to choose several different options
//
// Parameters: char *userName : contains the user name to reference data
//
// Return values: None
//
//****************************************************************/
void userMenu(char *userName){
  int option = 0;
  int currency = 0;
  float amount = 0;
  float tempAmount = 0;
  char trash[80];
  char userAccount[80];
  strcpy(userAccount, userName);

  while(1) {
    char tempValue[80];
    FILE *f = fopen("save.txt", "r+");
    if(f == NULL) {
      printf("Error opening file!\n");
      exit(1);
    }
    char tempUsr[50], tempPas[50];
    fscanf(f, "%[^\n]", tempValue);
    while(strcmp(tempValue, userAccount) != 0) {
      if(feof(f)){
        break;
      }
      else {
        fgets(trash, 20, f);
        fscanf(f, "%[^\n]", tempValue);
      }
    }
    if(strcmp(tempValue, userAccount) == 0) {
      fgets(trash, 20, f);
      fscanf(f, "%[^\n]", tempValue);
      fgets(trash, 20, f);
      fscanf(f, "%[^\n]", tempValue);
      fgets(trash, 20, f);
      fscanf(f, "%[^\n]", tempValue);
      totalAmount = atof(tempValue);
    }
    else {
      printf("Invalid username.\n\n");
    }
    fclose(f);

    printf("Please choose an option.\n");
    printf("1. See balance\n2. Make a deposit\n3. Withdraw an amount\n4. Exit\n=>> ");
    scanf("%d", &option);

    if(option == 1) {
      printf("Your balance is: $%.2f.\n\n", totalAmount);
    }

    else if(option == 2) {
      while(1) {
        printf("\nChoose a type of currency.\n");
        printf("1. US Dollar\n2. Euro\n3. UK Pound\n=>> ");
        scanf("%d", &currency);

        if(currency != 1 && currency != 2 && currency != 3) {
          printf("Invalid input, please enter a number 1-3\n");
        }
        else {
          fgets(trash, 20, stdin);
          break;
        }

        currency = 0;
        fgets(trash, 20, stdin);
      }
      printf("\nInput the value you want to deposit. Example: 50.25\n=>> ");
      scanf("%f", &amount);

      if(currency == 1){
        printf("Deposited: %.2f US Dollars\n", amount);
        totalAmount += amount;
        char saveUsr[80];
        int del_line = 1;
        FILE *f = fopen("save.txt", "r+");
        if(f == NULL) {
          printf("Error opening file!\n");
          exit(1);
        }
        fscanf(f, "%[^\n]", saveUsr);
        while(strcmp(saveUsr, userAccount) != 0) {
          if(feof(f)){
            break;
          }
          else {
            del_line = del_line + 1;
            fgets(trash, 20, f);
            fscanf(f, "%[^\n]", saveUsr);
          }
        }
        fclose(f);
        if(strcmp(saveUsr, userAccount) == 0) {
          del_line += 3;
          changeBalance(del_line, totalAmount);
        }
        else {
          printf("Invalid username.\n\n");
        }
        printf("Total balance: $%.2f\n\n", totalAmount);
      }


      else if(currency == 2){
        tempAmount = amount*1.18;
        printf("Deposited: %.2f Euros ($%.2f)\n", amount, tempAmount);
        totalAmount += tempAmount;
        printf("Total balance: $%.2f\n\n", totalAmount);
      }


      else if(currency == 3){
        tempAmount = amount*1.33;
        printf("Deposited: %.2f UK Pounds ($%.2f)\n", amount, tempAmount);
        totalAmount += tempAmount;
        printf("Total balance: $%.2f\n\n", totalAmount);
      }
    }

    else if(option == 3) {
      currency = 0;
      while(1) {
        printf("\nChoose a type of currency.\n");
        printf("1. US Dollar\n2. Euro\n3. UK Pound\n=>> ");
        scanf("%d", &currency);

        if(currency != 1 && currency != 2 && currency != 3) {
          printf("Invalid input, please enter a number 1-3\n");
        }
        else {
          fgets(trash, 20, stdin);
          break;
        }

        currency = 0;
        fgets(trash, 20, stdin);
      }
      printf("\nInput the value you want to withdraw. Example: 50.25\n");
      scanf("%f", &amount);

      if(currency == 1){
        if(amount > totalAmount) {
          printf("Insufficient funds.\n\n");
        }
        else {
          printf("Withdrew: %.2f US Dollars\n", amount);
          totalAmount -= amount;
        }
      }
      else if(currency == 2){
        tempAmount = amount*1.18;
        if(tempAmount > totalAmount) {
          printf("Insufficient funds.\n\n");
        }
        else {
          printf("Withdrew: %.2f Euros ($%.2f)\n", amount, tempAmount);
          totalAmount -= tempAmount;
        }
      }
      else if(currency == 3){
        tempAmount = amount*1.33;
        if(tempAmount > totalAmount) {
          printf("Insufficient funds.\n\n");
        }
        else {
          printf("Withdrew: %.2f UK Pounds ($%.2f)\n", amount, tempAmount);
          totalAmount -= tempAmount;
        }
      }
      printf("Total balance: $%.2f\n\n", totalAmount);
    }

    else if(option == 4) {
      printf("Logging out.\n\n");
      break;
    }

    else {
      printf("Invalid input, please enter a number 1-4.\n\n");
    }

    option = 0;
    amount = 0;
    tempAmount = 0;
    fgets(trash, 20, stdin);
  }
}

/*****************************************************************
//
// Function name: adminMenu
//
// DESCRIPTION: A userinterface function for administrators
// This function allows a user to choose administrative options
//
// Parameters: None
//
// Return values: None
//
//****************************************************************/
void adminMenu(){
  int option = 0;
  int currencyOption = 0;
  int currency = 0;
  float amount = 0;
  float tempAmount = 0;
  char trash[80];
  while(1) {
    printf("Please choose an option.\n");
    printf("1. Create an account\n2. Delete and existing account\n3. Exit\n=>> ");
    scanf("%d", &option);

    if(option == 1) {
      printf("Enter your new username: ");
      scanf("%s", usrName);
      fgets(trash, 20, stdin);
      printf("Enter your new password: ");
      scanf("%s", pasWord);
      while(1){
        printf("Choose your preferred currency type.\n1. US Dollars\n2. Euros\n3. UK Pounds\n=>> ");
        scanf("%d", &currencyOption);
        if(currencyOption > 3 || currencyOption < 1) {
          printf("Invalid input, please enter a number 1-3.\n\n");
        }
        else {
          break;
        }
      }
      printf("Your new username is: %s\n", usrName);
      printf("Your new password is: %s\n\n", pasWord);
      addUser(usrName, pasWord, currencyOption);
    }

    else if(option == 2) {
      char trash[80];
      char saveUsr[80];
      int del_line = 1;
      FILE *f = fopen("save.txt", "r+");
      if(f == NULL) {
        printf("Error opening file!\n");
        exit(1);
      }
      char tempUsr[50], tempPas[50];
      printf("Username: ");
      scanf("%s", tempUsr);
      fscanf(f, "%[^\n]", saveUsr);
      while(strcmp(saveUsr, tempUsr) != 0) {
        if(feof(f)){
          break;
        }
        else {
          del_line = del_line + 1;
          fgets(trash, 20, f);
          fscanf(f, "%[^\n]", saveUsr);
        }
      }
      fclose(f);
      if(strcmp(saveUsr, tempUsr) == 0) {
        delUser(del_line);
        delUser(del_line);
        delUser(del_line);
        delUser(del_line);
        printf("User deleted.\n\n");
      }
      else {
        printf("Invalid username.\n\n");
      }
    }

    else if(option == 3) {
      printf("Logging out.\n\n");
      break;
    }

    else {
      printf("Invalid input, please enter a number 1-3.\n\n");
    }

    option = 0;
    amount = 0;
    tempAmount = 0;
    fgets(trash, 20, stdin);
  }
}

/*****************************************************************
//
// Function name: converstionMenu
//
// DESCRIPTION: A userinterface function for currency converstions
//
// Parameters: None
//
// Return values: None
//
//****************************************************************/
void converstionMenu() {
  int option = 0;
  char trash[80];
  float val1 = 0;
  float val2 = 0;

  while(1) {
    printf("\nChoose an option.\n");
    printf("1. US Dollars to Euros\n2. US Dollars to UK Pounds\n3. Euros to US Dollars\n4. Euros to UK Pounds\n5. UK Pounds to US Dollars\n6. UK Pounds to Euros\n7. Exit\n=>> ");
    scanf("%d", &option);

    if(option == 1) {
      printf("\nEnter the value in US Dollars (Ex. 50.25): ");
      scanf("%f", &val1);
      val2 = val1*.85;
      printf("Converted amount: %.2f Euros\n", val2);
    }
    else if(option == 2) {
      printf("\nEnter the value in US Dollars (Ex. 50.25): ");
      scanf("%f", &val1);
      val2 = val1*.75;
      printf("Converted amount: %.2f UK Pounds\n", val2);
    }
    else if(option == 3) {
      printf("\nEnter the value in Euros (Ex. 50.25): ");
      scanf("%f", &val1);
      val2 = val1*1.18;
      printf("Converted amount: %.2f US Dollars\n", val2);
    }
    else if(option == 4) {
      printf("\nEnter the value in Euros (Ex. 50.25): ");
      scanf("%f", &val1);
      val2 = val1*0.89;
      printf("Converted amount: %.2f UK Pounds\n", val2);
    }
    else if(option == 5) {
      printf("\nEnter the value in UK Pounds (Ex. 50.25): ");
      scanf("%f", &val1);
      val2 = val1*1.33;
      printf("Converted amount: %.2f US Dollars\n", val2);
    }
    else if(option == 6) {
      printf("\nEnter the value in UK Pounds (Ex. 50.25): ");
      scanf("%f", &val1);
      val2 = val1*1.12;
      printf("Converted amount: %.2f Euros\n", val2);
    }
    else if(option == 7) {
      printf("Exiting coverter.\n\n");
      break;
    }
    else {
      printf("Invalid input, please enter a number 1-7\n");
    }

    option = 0;
    fgets(trash, 20, stdin);

  }
}

/*****************************************************************
//
// Function name: addUser
//
// DESCRIPTION: A function that adds a user and their data into a
//              save file.
//
// Parameters: char *usrName: Contains the username of the user
//             char *pasWord: Contains the pasWord of the user
//             int prefCurrency: Contains the preferred currency of
//                               the user. 1 = US Dollars, 2 = Euros,
//                               3 = UK Pounds
//
// Return values: None
//
//****************************************************************/
void addUser(char *usrName, char *pasWord, int prefCurrency){
  char trash[80];
  FILE *f = fopen("save.txt", "a+");
  if(f == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  fprintf(f, "%s\n%s\n%d\n0\n", usrName, pasWord, prefCurrency);
  fclose(f);
}

/*****************************************************************
//
// Function name: delUser
//
// DESCRIPTION: Deletes a user and their data off of the save file
//
// Parameters: int line: Contains the line in the file of the username.
//                       Uses this line to reference which lines should
//                       be deleted
//
// Return values: None
//
//****************************************************************/
void delUser(int line) {
    FILE *fp1, *fp2;
    char filename[40] = "save.txt";
    char c;
    int del_line = line;
    int temp = 1;
    fp1 = fopen(filename, "r");
    fp2 = fopen("copy.c", "w");
    c = getc(fp1);
    rewind(fp1);
    while (c != EOF) {
      c = getc(fp1);
      if (c == '\n')
      temp++;
      if (temp != del_line)
      {
        putc(c, fp2);
      }
    }
    fclose(fp1);
    fclose(fp2);
    remove(filename);
    rename("copy.c", filename);
    fclose(fp1);
}

/*****************************************************************
//
// Function name: changeBalance
//
// DESCRIPTION: Changes the balance of a user
//
// Parameters: int line: the line that contains the balance
//             float totalAmount: the amount to replace the balance
//
// Return values: None
//
//****************************************************************/
void changeBalance(int line, float changedBalance) {
    FILE *fp1, *fp2;
    float tempBalance = changedBalance;
    char filename[40] = "save.txt";
    char c;
    char amount[60];
    snprintf(amount, 50, "%.2f", tempBalance);
    int del_line = line;
    int temp = 1;
    fp1 = fopen(filename, "r");
    fp2 = fopen("copy.c", "w");
    c = getc(fp1);
    rewind(fp1);
    while (c != EOF) {
      c = getc(fp1);
      if (c == '\n'){
        temp++;
      }
      if (temp != del_line)
      {
        putc(c, fp2);
      }
      else {
        putc('\n', fp2);
        fputs(amount, fp2);
        c = getc(fp1);
        while(c != '\n'){
          c = getc(fp1);
        }
        putc('\n', fp2);
        temp++;
      }
    }
    fclose(fp1);
    fclose(fp2);
    remove(filename);
    rename("copy.c", filename);
    fclose(fp1);
}

/*****************************************************************
//
// Function name: main
//
// DESCRIPTION: A userinterface function
// This function allows a user to choose several different options
// from the bank database menu
//
// Parameters: None
//
// Return values: None
//
//****************************************************************/
int main() {
  printf("\n\n _______          ______         __    __        __    __ \n|       \\        /      \\       |  \\  |  \\      |  \\  /  \\\n| $$$$$$$\\      |  $$$$$$\\      | $$\\ | $$      | $$ /  $$\n| $$  | $$      | $$__| $$      | $$$\\| $$      | $$/  $$\n| $$  | $$      | $$    $$      | $$$$\\ $$      | $$  $$\n| $$  | $$      | $$$$$$$$      | $$\\$$ $$      | $$$$$\\\n| $$__/ $$      | $$  | $$      | $$ \\$$$$      | $$ \\$$\\\n| $$    $$      | $$  | $$      | $$  \\$$$      | $$  \\$$\\\n \\$$$$$$$        \\$$   \\$$       \\$$   \\$$       \\$$   \\$$\n\n");
  printf(" _______          ______         __    __        __    __\n|       \\        /      \\       |  \\  |  \\      |  \\  /  \\\n| $$$$$$$\\      |  $$$$$$\\      | $$\\ | $$      | $$ /  $$\n| $$__/ $$      | $$__| $$      | $$$\\| $$      | $$/  $$\n| $$    $$      | $$    $$      | $$$$\\ $$      | $$  $$\n| $$$$$$$\\      | $$$$$$$$      | $$\\$$ $$      | $$$$$\\\n| $$__/ $$      | $$  | $$      | $$ \\$$$$      | $$ \\$$\\\n| $$    $$      | $$  | $$      | $$  \\$$$      | $$  \\$$\\\n \\$$$$$$$        \\$$   \\$$       \\$$   \\$$       \\$$   \\$$ \n\n");

  struct record * start = NULL;
  int option = 0;
  char trash[80];
  char saveUsr[80];
  char savePas[80];
  int prefCurr = 0;
  int accountTotal = 0;

  while(1) {
    printf("Welcome to the Dank Bank Database. Please choose an option.\n");
    printf("1. Login to an existing account\n2. Make a conversion\n3. Exit the program\n=>> ");
    scanf("%d", &option);

    if(option == 1) {
      FILE *f = fopen("save.txt", "r+");
      if(f == NULL) {
        printf("Error opening file!\n");
        exit(1);
      }
      char tempUsr[50], tempPas[50];
      char adminUsr[] = "admin";
      char adminPas[] = "adminpass";
      printf("Username: ");
      scanf("%s", tempUsr);
      fgets(trash, 20, stdin);
      printf("Password: ");
      scanf("%s", tempPas);
      fscanf(f, "%[^\n]", saveUsr);
      fgets(trash, 20, f);
      fscanf(f, "%[^\n]", savePas);
      fgets(trash, 20, f);
      fscanf(f, "%[^\n]", &prefCurr);
      fgets(trash, 20, f);
      fscanf(f, "%[^\n]", &accountTotal);
      while(strcmp(saveUsr, tempUsr) != 0 || strcmp(savePas, tempPas) != 0) {
        if(feof(f)){
          break;
        }
        else {
          fgets(trash, 20, f);
          fscanf(f, "%[^\n]", saveUsr);
          fgets(trash, 20, f);
          fscanf(f, "%[^\n]", savePas);
          fgets(trash, 20, f);
          fscanf(f, "%[^\n]", &prefCurr);
          fgets(trash, 20, f);
          fscanf(f, "%[^\n]", &accountTotal);
        }
      }
      fclose(f);
      if(strcmp(tempUsr, adminUsr) == 0 && strcmp(tempPas, adminPas) == 0) {
        printf("Login successful.\n\n");
        adminMenu();
      }
      else if(strcmp(saveUsr, tempUsr) == 0 && strcmp(savePas, tempPas) == 0) {
        printf("Login successful.\n\n");
        userMenu(saveUsr);
      }
      else {
        printf("Invalid username or password\n\n");
      }
    }
    else if(option == 2) {
      converstionMenu();
    }
    else if(option == 3) {
      exit(0);
    }
    else {
      printf("Invalid input, please enter a number 1-3.\n\n");
    }
    option = 0;
    fgets(trash, 20, stdin);
  }
}
