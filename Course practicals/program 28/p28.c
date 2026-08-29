#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[50];
    char pattern[50];
    char line[200];

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter search word: ");
    scanf("%s", pattern);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    printf("\nMatching lines:\n");

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strstr(line, pattern) != NULL)
        {
            printf("%s", line);
        }
    }

    fclose(fp);

    return 0;
}
