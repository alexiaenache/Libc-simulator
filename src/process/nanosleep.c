
#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>
int nanosleep(const struct timespec *req, struct timespec *rem) {
    int aux = syscall(__NR_nanosleep, req, rem);
    if (aux < 0) {
        errno = -aux;
        return -1;
    }
    return aux;
}
