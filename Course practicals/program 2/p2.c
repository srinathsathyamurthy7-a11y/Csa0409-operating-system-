#include <stdio.h>
int main()
{
    FILE *fp1, *fp2;
    int ch;

    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("File cannot be opened\n");
        return 0;
    }

    while ((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    printf("File copied successfully\n");

    return 0;
}
