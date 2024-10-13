#include<internal/io.h>
#include<unistd.h>
#include <errno.h>
#include <string.h>

int puts(const char *str)
{
    ssize_t aux = write(1, str, strlen(str));
    if (aux < 0) {
        errno = -aux;
        return -1;
    }
    write(1, "\n", 1);
    return 0;
}
