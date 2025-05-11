#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For getch()
#include <time.h>
#include <string.h>

#define SIZE 9
#define MAX_RESERVED 10 

char seats[SIZE][SIZE];
char tempSeats[SIZE][SIZE];

void cleanScreen(){ // Clean screen
    system("cls"); 
}

void iniseats(){
    for(int i=0; i<SIZE; i++)
       for(int j=0; SIZE; j++)
          seats[i][j]='-';

    int count=0;
    while(count<MAX_RESERVED){
        int row=rand()%SIZE;
        int col=rand()%SIZE;
        if(seats[row][col]!='*'){
            seats[row][col]='*';
            count++;
        }
    }
}

void showseats(){
    printf("\\123456789\n");
    for(int i=SIZE-1; i>=0; i--){
        printf("%d", i+1);
        for(int j=0; j<SIZE; j++){
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
    printf("\nPress any key to return to main menu");
    getch();
    cleanScreen();
}


int confirmContinue() { // Comfirming exiting the program
    char choice;
    while (1) {
        printf("Enter again (y/n)? ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            cleanScreen();
            return 1;
        } else if (choice == 'n' || choice == 'N') {
            printf("Ending...\n");
            return 0;
        } else {
            printf("Warning: Enter y or n\n");
        }
    }
}

int main() // Main body
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
            printf("Welcome!\n");
            getchar();
            break;
                             
            } else {
            i++; // Minus one attempt
            printf("Wrong password, reamining attempts:%d\n", 3 - i);
        }
    }

    while (1) // Main body
        {
            system("cls"); // Cleaning screen
            printf("------------------------------\n");
            printf("| a. : Available seats       |\n");
            printf("| b. : Arrange for you       |\n");
            printf("| c. : Choose by yourself    |\n");
            printf("| d. : Exit                  |\n");
            printf("------------------------------\n");
            getchar(); // waiting for user to type anything
            scanf("%c", &input);

            switch(input){ // Deciding with funtion we are using
                case 'a':
                    showseats();
                    iniseats();
                    break;
                case 'b':
                    break;
                case 'c':
                    break;
                case 'd':
                    if (!confirmContinue()){
                    return 0; 
                    }   
                default:
                    printf("Wrong option enter again!\n");
                    break;
            }
        }
        return  0;
}