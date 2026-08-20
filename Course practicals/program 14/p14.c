#include <stdio.h>
#include <string.h>

int main() {
    char files[20][30];
    int n = 0, choice, i;
    char name[30];

    while (1) {
        printf("\n1. Create File");
        printf("\n2. Delete File");
        printf("\n3. Search File");
        printf("\n4. Display Files");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);

                for (i = 0; i < n; i++) {
                    if (strcmp(files[i], name) == 0) {
                        printf("File already exists\n");
                        break;
                    }
                }

                if (i == n) {
                    strcpy(files[n], name);
                    n++;
                    printf("File created\n");
                }
                break;

            case 2:
                printf("Enter file name: ");
                scanf("%s", name);

                for (i = 0; i < n; i++) {
                    if (strcmp(files[i], name) == 0) {
                        strcpy(files[i], files[n - 1]);
                        n--;
                        printf("File deleted\n");
                        break;
                    }
                }

                if (i == n)
                    printf("File not found\n");
                break;

            case 3:
                printf("Enter file name: ");
                scanf("%s", name);

                for (i = 0; i < n; i++) {
                    if (strcmp(files[i], name) == 0) {
                        printf("File found\n");
                        break;
                    }
                }

                if (i == n)
                    printf("File not found\n");
                break;

            case 4:
                printf("Files in directory:\n");
                for (i = 0; i < n; i++)
                    printf("%s\n", files[i]);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
