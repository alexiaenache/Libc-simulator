// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	int aux = syscall(__NR_lseek, fd, offset, whence);
	if(aux < 0) {
		errno = -aux;
		return (off_t)-1;
	}
	return aux;
}
