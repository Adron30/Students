#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char* name;  // Needs to be minimalized
    float grade;
} student;

int main() {
    student mystudents;
    int numerin = 0;
    int i = 0;
    char buffer[MAX];
    student* pointer = NULL;
    char trash = ' ';

    printf("Number of students: ");
    scanf("%d", &numerin);
    scanf("%c", &trash);

    pointer = (student*)malloc(sizeof(student) * numerin); 

    if (pointer != NULL) {
        for (i = 0; i < numerin; i++) {
            printf("\nStudent %d\n", i + 1);

            printf("ID: ");
            scanf("%d", &pointer[i].id);
            scanf("%c", &trash);

            printf("Name: ");
            fgets(buffer, MAX, stdin);
            buffer[strlen(buffer) - 1] = '\0';

            pointer[i].name = (char*)malloc((strlen(buffer) + 1) * sizeof(char));

            if (pointer[i].name != NULL) {
                strcpy(pointer[i].name, buffer);
            }

            printf("Grade: ");
            scanf("%f", &pointer[i].grade);
            scanf("%c", &trash);
        }

        for (int i = 0; i < numerin; i++) {
            printf("\n\nSTUDENT %d:\n", i + 1);
            printf("ID: %d\n", pointer[i].id);
            printf("Name: %s\n", pointer[i].name);
            printf("Grade: %.2f\n", pointer[i].grade);
        }

        free(pointer);
        pointer = NULL;
    }

    return 0;
}