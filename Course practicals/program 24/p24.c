#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];
    int n;

    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    if (fd == -1)
    {
        perror("File opening failed");
        return 1;
    }

    write(fd, "Hello UNIX System Calls\n", 24);

    lseek(fd, 0, SEEK_SET);

    n = read(fd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';

    printf("File contents:\n%s", buffer);

    close(fd);

    return 0;
}
