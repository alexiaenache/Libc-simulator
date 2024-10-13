// SPDX-License-Identifier: BSD-3-Clause
#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
// https://elixir.bootlin.com/musl/latest/source/src/fcntl/open.c#L5
int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */

	mode_t mode = 0;

	if (flags & O_CREAT) {
		va_list ap;
		va_start(ap, flags);
		mode = va_arg(ap, mode_t);
		va_end(ap);
	}


	int aux = syscall(__NR_open, filename, flags, mode);
	if(aux < 0) {
		errno = -aux;
		return -1;
	} else {
		return aux;
	}
}
