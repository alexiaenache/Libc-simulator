// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	int aux = syscall(__NR_close, fd);
	if(aux < 0) {
		errno = -aux;
		return -1;
	}
	return 0;
}
