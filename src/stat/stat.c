// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	int aux = syscall(__NR_stat, path, buf);
	if(aux < 0) {
		errno = -aux;
		return -1;
	}
	return aux;
}
