#include <stdio.h>
#include <stdlib.h>


int main() {
    int choice = 0;
    char tasks[5][100];   // store up to 5 tasks
    int count = 0;

    while (choice != 3) {
        printf("\nWelcome to To-Do List App\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear buffer

        if (choice == 1) {
    if (count < 5) {
        printf("Enter task: ");
        fgets(tasks[count], sizeof(tasks[count]), stdin);

        FILE *fp = fopen("tasks.txt", "a");
        if (fp != NULL) {
            fputs(tasks[count], fp);
            fclose(fp);
        }

        count++;
        printf("Task added and saved\n");
    } else {
        printf("Task list full\n");
    }
}
        else if (choice == 2) {
            printf("\nYour Tasks:\n");
            for (int i = 0; i < count; i++) {
                printf("%d. %s", i + 1, tasks[i]);
            }
        } 
        else if (choice == 3) {
            printf("Exiting application...\n");
        }
    }

    return 0;
}
