#include <stdio.h>
#include <string.h>

char users[10][20];
char files[10][20][20];
int fileCount[10];

int main() {
    int choice, u, i;
    char username[20], filename[20];

    while (1) {
        printf("\n1. Create User");
        printf("\n2. Create File");
        printf("\n3. Delete File");
        printf("\n4. Search File");
        printf("\n5. Display Files");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter username: ");
                scanf("%s", username);

                strcpy(users[u = 0], username);

                for (i = 0; i < 10; i++) {
                    if (strcmp(users[i], username) == 0) {
                        printf("User already exists\n");
                        break;
                    }
                }

                if (i == 10) {
                    strcpy(users[u], username);
                    fileCount[u] = 0;
                    printf("User created\n");
                }
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", username);

                for (u = 0; u < 10; u++) {
                    if (strcmp(users[u], username) == 0)
                        break;
                }

                if (u == 10) {
                    printf("User not found\n");
                    break;
                }

                printf("Enter file name: ");
                scanf("%s", filename);

                strcpy(files[u][fileCount[u]], filename);
                fileCount[u]++;

                printf("File created\n");
                break;

            case 3:
                printf("Enter username: ");
                scanf("%s", username);

                for (u = 0; u < 10; u++) {
                    if (strcmp(users[u], username) == 0)
                        break;
                }

                if (u == 10) {
                    printf("User not found\n");
                    break;
                }

                printf("Enter file name: ");
                scanf("%s", filename);

                for (i = 0; i < fileCount[u]; i++) {
                    if (strcmp(files[u][i], filename) == 0) {
                        strcpy(files[u][i], files[u][fileCount[u] - 1]);
                        fileCount[u]--;
                        printf("File deleted\n");
                        break;
                    }
                }

                if (i == fileCount[u])
                    printf("File not found\n");
                break;

            case 4:
                printf("Enter username: ");
                scanf("%s", username);

                for (u = 0; u < 10; u++) {
                    if (strcmp(users[u], username) == 0)
                        break;
                }

                if (u == 10) {
                    printf("User not found\n");
                    break;
                }

                printf("Enter file name: ");
                scanf("%s", filename);

                for (i = 0; i < fileCount[u]; i++) {
                    if (strcmp(files[u][i], filename) == 0) {
                        printf("File found\n");
                        break;
                    }
                }

                if (i == fileCount[u])
                    printf("File not found\n");
                break;

            case 5:
                for (u = 0; u < 10; u++) {
                    if (strlen(users[u]) > 0) {
                        printf("\nUser: %s\n", users[u]);

                        for (i = 0; i < fileCount[u]; i++)
                            printf("%s\n", files[u][i]);
                    }
                }
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
