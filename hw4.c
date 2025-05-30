#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// Comfirming exiting the program
int confirmContinue() { 
    char choice;
    while (1) {
        printf("Enter again (y/n)? ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            system("cls");
            return 1;
        } else if (choice == 'n' || choice == 'N') {
            printf("Ending...\n");
            return 0;
        } else {
            printf("Warning: Enter y or n\n");
        }
    }
}

int main()
{
    if(!login()) return 0;
    char input;
    while(1) {
        system("cls");
        showMenu();
        printf("PLease enter your choice: ");
        scanf("%c", &input);

        switch (input) {
            case 'a':
                enterGrades();
                break;
            case 'b':
                displayGrades();
                break;
            case 'c':
                searchGrades();
                break;
            case 'd':
                rankGrades();
                break;
            case 'e':
                if(!confrimContinue()){
                    return 0;
                }
            default:
                printf("Worng choice enter again!\n");
                getchar(); getchar();                
        }
    }
    return 0;
}