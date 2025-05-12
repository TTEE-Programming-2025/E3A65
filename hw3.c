#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For getch()
#include <time.h>
#include <string.h>

#define SIZE 9
#define MAX_RESERVED 10 
#define PASSWORD 2025

char seats[SIZE][SIZE];
char tempSeats[SIZE][SIZE];

// Initialise seats and tag 10 random seats as '*'
void iniseats(){
    for(int i=0; i<SIZE; i++)
       for(int j=0; j<SIZE; j++)
          seats[i][j]='-';

    int count=0;
    while(count<MAX_RESERVED){
        int r=rand()%SIZE;
        int c=rand()%SIZE;
        if(seats[r][c]!='*'){
            seats[r][c]='*';
            count++;
        }
    }
}

// Showing the seats 
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
    system("cls");
}

// Showing the temporary seats with '@'
void showTempSeats(){
    printf("\\123456789\n");
    for(int i=SIZE-1; i>=0; i--){
        printf("%d", i+1);
        for (int j=0; j<SIZE; j++){
            printf("%c", tempSeats[i][j]);
        }
        printf("\n");
    }
}

int passwordCheck(){
    int input, attempt = 0;
    while (attempt < 3){
        printf("Enter the password: ");
        scanf("%d", &input);
        if (input == PASSWORD){
            printf("Wwelcome!\n");
            return(1);
        } else{
            printf("Wrong  password\n");
            attempt++;
        }
    }
    printf("Error, shutting down");
    return 0;
}

int confirmContinue() { // Comfirming exiting the program
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

int main() // Main body
{
    
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

    if (!passwordCheck()) return 0;

    iniSeats();

    char input;
    do {
        system("cls"); // Cleaning screen
        printf("------------------------------\n");
        printf("| a. : Available seats       |\n");
        printf("| b. : Arrange for you       |\n");
        printf("| c. : Choose by yourself    |\n");
        printf("| d. : Exit                  |\n");
        printf("------------------------------\n");
        scanf("%c", &input);

        system("cls");
        switch(input){ // Deciding with funtion we are using
            case 'a':
                showseats();
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
    } while(1);

    return  0;
}