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
struct Student {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
};

struct Student students[MAX];
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

void showMenu() {
        printf("-------[Grading system]-------\n"); 
        printf("| a. : Enter grades          |\n");
        printf("| b. : Display grades        |\n");
        printf("| c. : Search grades         |\n");
        printf("| d. : Ranking grades        |\n");
        printf("| e. : Exit                  |\n");
        printf("------------------------------\n");    
}

// Grade entering system
void enterGrades() { 
    int n;
    system("clear");
    printf("Enter the number of studnets(5~10): ");
    scanf("%d", &n);
    if (n < 5 || n > 10) {
        printf("Too much/less of the student.\n");
        return;
    }
    studentCount = 0;
    for (int i = 0; i < n; i++){
        printf("Name of the %d student: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter ID(Six-digit number): ");
        scanf("%s", &students[i].id);
        if(students[i].id < 100000 || students[i].id >  999999) {
            printf("Wrong format of student ID. ");
            i--;
            continue;
        }

        printf("Enter Math grade(0~100): ") ;
        scanf("%d", &students[i].math);
        if (students[i].math < 0 || students[i].math > 100) {
            printf("Wrong format of grade.");
            i--;
            continue;
        }

        printf("Enter Physics grade(0~100): ") ;
        scanf("%d", &students[i].physics);
        if (students[i].physics < 0 || students[i].physics > 100) {
            printf("Wrong format of grade.");
            i--;
            continue;
        }

        printf("Enter English grade(0~100): ") ;
        scanf("%d", &students[i].english);
        if (students[i].english < 0 || students[i].english > 100) {
            printf("Wrong format of grade.");
            i--;
            continue;
        }

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }
}

// Grade displaying function
void displayGrades() {
    system("clear");
    printf("Name\tID\tMath\tPhysics\tEnglish\tAverage\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%.1f\n",
        students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
    }
    getchar(); getchar(); // waiting for input
}

// Grade searching function
void searchGrade() {
    char target[50];
    int found  = 0;
    system("clear");
    printf("Who's grade do you want to look up?: ");
    scanf("%s", target);
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, target) == 0) {
            printf("Found it!!\n");
            printf("Name: %s\tId: \n",  students[i].name, students[i].id);
            printf("Math: %d\tPhysics: %d\tEnglish: %d\n", students[i].math, students[i].physics, students[i].english);
            printf("Average: %1.f\n",  students[i].average);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("This student does not exist in the system!\n");
    }
    getchar(); getchar();
} 

// Ranking system
void rankGrade() {
    system("clear");
    struct Student temp;
    for(int i = 0; i < studentCount - 1; i++) {
        for(int j = i + 1; j < studentCount; j++) {
            if (students[i].average < students[j].average) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    } 
    printf("Name\tID\tAverage\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s\t%d\t%1.f\n", students[i].name, students[i].id, students[i].average);
    }
    getchar(); getchar();
}

// Main body
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

// Final project of the semester, this one is trickly with the combinations of array and structure, makes it way more difficult than the last one,
// but thru out the studying and hard work I am still able to finsih it. I've learnt a lot from making these projects, definitely gave me some  
// experiences for programming in general, and I believe these expereience it's going to help me a lot in the future!  