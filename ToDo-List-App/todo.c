#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int choice = 0;
    char tasks[5][100];
    int count = 0;

    FILE *fp = fopen("tasks.txt", "r");
    if (fp != NULL) {
        while (fgets(tasks[count], sizeof(tasks[count]), fp)) {
            count++;
        }
        fclose(fp);
    }

    while (choice != 4) {
        printf("\n1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            if (count < 5) {
                printf("Enter task: ");
                fgets(tasks[count], sizeof(tasks[count]), stdin);

                fp = fopen("tasks.txt", "a");
                if (fp != NULL) {
                    fputs(tasks[count], fp);
                    fclose(fp);
                }

                count++;
                printf("Task added\n");
            } else {
                printf("Task list full\n");
            }
        }

        else if (choice == 2) {
            if (count == 0) {
                printf("No tasks available\n");
            } else {
                printf("\nYour Tasks:\n");
                for (int i = 0; i < count; i++) {
                    printf("%d. %s", i + 1, tasks[i]);
                }
            }
        }

        else if (choice == 3) {
            if (count == 0) {
                printf("No tasks to delete\n");
            } else {
                int del;
                printf("Enter task number to delete: ");
                scanf("%d", &del);
                getchar();

                if (del < 1 || del > count) {
                    printf("Invalid task number\n");
                } else {
                    for (int i = del - 1; i < count - 1; i++) {
                        strcpy(tasks[i], tasks[i + 1]);
                    }
                    count--;

                    fp = fopen("tasks.txt", "w");
                    if (fp != NULL) {
                        for (int i = 0; i < count; i++) {
                            fputs(tasks[i], fp);
                        }
                        fclose(fp);
                    }

                    printf("Task deleted\n");
                }
            }
        }

        else if (choice == 4) {
            printf("Exiting application...\n");
        }

        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
