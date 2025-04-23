#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // getch()

void cleanscreen(){
    system("cls"); // Clean screen
}

void multiplicationTable(){
    int n;
    cleanscreen();
    while(1){
        printf("Enter a number:");
        scanf("%d",  &n);
        if(n>=1&&n<=9){
            for(int i=1; i<=n; i++){
                for(int j=i; j<=n; j++){
                    printf("%d*%d=%2d", i, j, i*j);
                }
                printf("\n");
            }
            printf("\nEnter a key to back to main menu");
            getch();
            cleanscreen();
            return;
        } else{
            printf("Warning: Enter again:\n");
        }
    }
}

void Drawtriangle(char ch){
    int rows=ch-'a'+1;
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=rows; j++){
            printf("*");
        }
        printf("\n");
    }
}

void triangleOption() {
    char ch;
    clearScreen();
    while (1) {
        printf("Enter character between a and n:");
        scanf(" %c", &ch);

        if (ch>='a'&&ch<='n') {
            drawTriangle(ch);
            printf("\nEnter a key to back to main menu\n");
            getch();
            clearScreen();
            return;
        } else {
            printf("Warning: Enter again:\n");
        }
    }
}

int confirmContinue() {
    char choice;
    while (1) {
        printf("Continue? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            clearScreen();
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
    int password, i=0;
    char input;

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@\n");
    printf("@@@@@@@@  @@@@@@@@@@@@@@        @@@@@\n");
    printf("@@@@@@          @@@@@          @@@@@@\n");
    printf("@@@@@     @@@@@@@@@@@           @@@@@\n");
    printf("@@@@@@ @@@ @@@@@@@@@@@@@@@  @@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@          @@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@    @@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    while (i<3){ // Checking if it's still under 3 attpemts
        printf("Enter the 4-digit password:");
        scanf("%d", &password);
        if (password==2025){ 
            break;
                             
            } else {
            i++; // Minus one attempt
            printf("Wrong password, reamining attempts:%d\n", 3 - i);
        }
    }

    while (1)
        {
            system("cls"); // Cleaning screen
            printf("------------------------------\n");
            printf("| a. : Draw a Right Triangle |\n");
            printf("| b. : 9x9 Table             |\n");
            printf("| c. : Exit                  |\n");
            printf("------------------------------\n");
            getchar(); // waiting for user to type anything
            scanf("%c", &input);

            switch(input){
                case 'a':
                case 'A':
                    traingleOption();
                    break;
                case 'b':
                case 'B':
                    multiplicationTable();
                    break;
                case 'c':
                case 'C':
                    if (!confirmContinue()){
                        return 0;
                    }
                    break;
                default:
                    printf("Wrong option enter again!\n");
                    break;
            }
        }
        return  0;
}
    
