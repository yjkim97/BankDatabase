#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>

void changeBalance(int line, float changedBalance);

float totalAmount = 0;
void transferUI(char *currentUser) {
    char currUser[80];
    strcpy(currUser, currentUser);
    float transferAmount = 0;

    char saveUsr[80];
    char savePas[80];
    char trash[80];
    int prefCurr = 0;
    int accountTotal = 0;
    while(1) {
      FILE *f = fopen("save.txt", "r+");
      if(f == NULL) {
        printf("Error opening file!\n");
        exit(1);
      }
      char tempUsr[50];
      printf("Username: ");
      scanf("%s", tempUsr);
      fgets(trash, 20, stdin);
      fscanf(f, "%[^\n]", saveUsr);
      fgets(trash, 20, f);
      fscanf(f, "%[^\n]", savePas);
      fgets(trash, 20, f);
      fscanf(f, "%[^\n]", &prefCurr);
      fgets(trash, 20, f);
      fscanf(f, "%[^\n]", &accountTotal);
      while(strcmp(saveUsr, tempUsr) != 0) {
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
      if(strcmp(saveUsr, tempUsr) == 0) {
        printf("Input the value you want to transfer in dollars. Example: 50.25\n=>> ");
        scanf("%f", &transferAmount);
        if(transferAmount > accountTotal) {
          printf("Insufficient funds.");
        }
        else{
          printf("Transfering $%.2f to user %s\n", transferAmount, saveUsr);
        }
        //Finding the total amount of transfered User
        char trash[80];
        char userAccount[80];
        char tempValue[80];
        FILE *f = fopen("save.txt", "r+");
        if(f == NULL) {
          printf("Error opening file!\n");
          exit(1);
        }
        char tempUsr[50];
        fscanf(f, "%[^\n]", tempValue);
        while(strcmp(tempValue, saveUsr) != 0) {
          if(feof(f)){
            break;
          }
          else {
            fgets(trash, 20, f);
            fscanf(f, "%[^\n]", tempValue);
          }
        }
        if(strcmp(tempValue, saveUsr) == 0) {
          fgets(trash, 20, f);
          fscanf(f, "%[^\n]", tempValue);
          fgets(trash, 20, f);
          fscanf(f, "%[^\n]", tempValue);
          fgets(trash, 20, f);
          fscanf(f, "%[^\n]", tempValue);
          totalAmount = atof(tempValue);
        }
        printf("old amount: %f\n", totalAmount);
        totalAmount += transferAmount;
        printf("new amount: %f\n", totalAmount);

        //finding del_line and changing balance
        rewind(f);
        char anotherTempVal[80];
        int del_line = 1;

        if(f == NULL) {
          printf("Error opening file!\n");
          exit(1);
        }
        fscanf(f, "%[^\n]", anotherTempVal);
        while(strcmp(anotherTempVal, saveUsr) != 0) {
          if(feof(f)){
            break;
          }
          else {
            del_line = del_line + 1;
            fgets(trash, 20, f);
            fscanf(f, "%[^\n]", anotherTempVal);
          }
        }
        fclose(f);
        if(strcmp(anotherTempVal, saveUsr) == 0) {
          del_line += 3;
          float tempTotal = totalAmount;
          printf("Hello\n");
          changeBalance(del_line, tempTotal);
        }
        fclose(f);


        //transfer(saveUsr, currUser, transferAmount);
      }
      else {
        printf("Invalid user.\n\n");
      }
    }
}
void transfer(char *transferUser, char *currUser) {


}

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
}

int main() {
  char user[80] = "YuJin";
  transferUI(user);
}
