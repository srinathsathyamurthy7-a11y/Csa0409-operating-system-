#include <stdio.h>
#include <sys/stat.h>

int main()
{
    struct stat file;

    if (stat("test.txt", &file) < 0)
    {
        perror("stat");
        return 1;
    }

    printf("File: test.txt\n\n");

    printf("Owner permissions:\n");

    if (file.st_mode & S_IRUSR)
        printf("Read\n");

    if (file.st_mode & S_IWUSR)
        printf("Write\n");

    if (file.st_mode & S_IXUSR)
        printf("Execute\n");

    printf("\nGroup permissions:\n");

    if (file.st_mode & S_IRGRP)
        printf("Read\n");

    if (file.st_mode & S_IWGRP)
        printf("Write\n");

    if (file.st_mode & S_IXGRP)
        printf("Execute\n");

    printf("\nOthers permissions:\n");

    if (file.st_mode & S_IROTH)
        printf("Read\n");

    if (file.st_mode & S_IWOTH)
        printf("Write\n");

    if (file.st_mode & S_IXOTH)
        printf("Execute\n");

    return 0;
}