#include <stdio.h>

int main()
{
    int users, files;
    char user[10][30];
    char file[10][10][30];

    printf("Enter number of users: ");
    scanf("%d", &users);

    for(int i=0; i<users; i++)
    {
        printf("Enter user name: ");
        scanf("%s", user[i]);

        printf("Enter number of files for %s: ", user[i]);
        scanf("%d", &files);

        for(int j=0; j<files; j++)
        {
            printf("Enter file %d: ", j+1);
            scanf("%s", file[i][j]);
        }
    }

    printf("\nTwo Level Directory Structure\n");

    for(int i=0; i<users; i++)
    {
        printf("\nUser: %s\n", user[i]);

        for(int j=0; file[i][j][0] != '\0'; j++)
        {
            printf("%s\n", file[i][j]);
        }
    }

    return 0;
}
