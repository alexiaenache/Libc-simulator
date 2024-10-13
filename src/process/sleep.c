
#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>
// https://elixir.bootlin.com/musl/latest/source/src/unistd/sleep.c#L4
unsigned int sleep(unsigned int seconds) {
    struct timespec tv = { .tv_sec = seconds, .tv_nsec = 0};

    if (nanosleep(&tv, &tv))
        return tv.tv_sec;
    return 0;
}
