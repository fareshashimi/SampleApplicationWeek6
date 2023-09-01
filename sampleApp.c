#include <stdio.h>
#include <stdlib.h>

int main(){
    int c;
    int accountNum;
    char name[50];
    double balance;
    FILE *mfP;

    if((mfP=fopen("customer.txt", "r"))==NULL){
        printf("\n Sorry, the file is not opened.\n\n");
    }
    else{

        printf("1.Accounts with no money in the account.\n2.Accounts in debt.\n3.Accounts with money in the account.\n4.Exit.\n\n");
        printf("Select your choice: ");
        scanf("%d", &c);

        while(c!=4){
            fscanf(mfP, "%d %s %lf", &accountNum, name, & balance);

            switch(c){
                case 1:
                    printf("\nAccounts with no money:\n\n");
                    while(!feof(mfP)){
                        if(balance==0){
                             printf("%-10d%-13s%7.2f\n\n", accountNum, name, balance);
                        }
                        fscanf(mfP, "%d %s %lf", &accountNum, name, &balance);
                }
                break;

                case 2:
                    printf("\nAccounts in debt:\n\n");
                    while(!feof(mfP)){
                        if(balance < 0){
                             printf("%-10d%-13s%7.2f\n\n", accountNum, name, balance);
                        }
                        fscanf(mfP, "%d %s %lf", &accountNum, name, &balance);
                    }
                break;

                case 3:
                    printf("\nAccounts with money:\n\n");
                    while(!feof(mfP)){
                        if(balance > 0){
                            printf("%-10d%-13s%7.2f\n\n", accountNum, name, balance);
                        }
                        fscanf(mfP, "%d %s %lf", &accountNum, name, &balance);
                    }
                break;
            }
            rewind(mfP);
            printf("\n?");
            scanf("%d", &c);
        }
        printf("The program is terminated.\n");
        fclose(mfP);
    }

    return 0;
}
