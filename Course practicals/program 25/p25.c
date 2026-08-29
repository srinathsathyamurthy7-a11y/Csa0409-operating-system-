#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main()
{
    int fd;
    struct stat st;
    DIR *dir;
    struct dirent *entry;

    /* fcntl */
    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("File opened successfully\n");

    /* seek */
    lseek(fd, 0, SEEK_END);
    printf("File pointer moved to end\n");

    /* stat */
    if (stat("sample.txt", &st) == 0)
    {
        printf("File size: %ld bytes\n", st.st_size);
    }

    /* fcntl */
    printf("File descriptor flags: %d\n", fcntl(fd, F_GETFL));

    close(fd);

    /* opendir and readdir */
    dir = opendir(".");

    if (dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    printf("\nDirectory contents:\n");

    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}