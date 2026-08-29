#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char data[100];

    /* Create and write */
    fp = fopen("data.txt", "w");

    if (fp == NULL)
    {
        printf("Unable to create file\n");
        return 1;
    }

    printf("Enter text: ");
    fgets(data, sizeof(data), stdin);

    fprintf(fp, "%s", data);
    fclose(fp);

    printf("Data written successfully.\n");

    /* Read */
    fp = fopen("data.txt", "r");

    printf("\nFile contents:\n");

    while (fgets(data, sizeof(data), fp) != NULL)
    {
        printf("%s", data);
    }

    fclose(fp);

    /* Append */
    fp = fopen("data.txt", "a");

    fprintf(fp, "This line is appended.\n");
    fclose(fp);

    printf("\nData appended successfully.\n");

    return 0;
}
