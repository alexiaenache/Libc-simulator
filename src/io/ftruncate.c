// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	int aux = syscall(__NR_ftruncate, fd, length);
	if(aux < 0) {
		errno = -aux;
		return -1;
	}
	return 0;
}
