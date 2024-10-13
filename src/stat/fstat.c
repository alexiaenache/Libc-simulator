// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	int aux = syscall(__NR_fstat, fd, st);
	if(aux < 0) {
		errno = -aux;
		return -1;
	}
	return aux;
}
