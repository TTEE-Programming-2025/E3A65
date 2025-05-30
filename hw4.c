#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

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