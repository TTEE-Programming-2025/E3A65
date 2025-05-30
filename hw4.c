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

// Student data structure
struct student {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
};

struct Student student[MAX];
int studentCount = 0;

// Login function
int login() {
    int pwd, attempts = 0;
    const int correctPwd = 2025;

    while (attempts < 3) {
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
        printf("Enter the 4-digit password: ");
        scanf("%d", &pwd);
        if (pwd == correctPwd) {
            printf("Welcoem!\n");
            return 1;
        } else {
            printf("Wrong passwoed!\n");
            attempts++;
        }
    }
    printf("Attempt failed...system ending...\n");
    return 0;
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