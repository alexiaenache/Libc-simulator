// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	long long aux = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if(aux < 0) {
		errno = -aux;
		return MAP_FAILED;
	}
	return (void *)aux;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	 if (old_address == MAP_FAILED || old_size == 0 || new_size == 0) {
        errno = EINVAL;
        return MAP_FAILED;
    }
	void *aux = (void *)syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if(aux == MAP_FAILED) {
		errno = -(int)(long)aux;
		return MAP_FAILED;
	}

	return aux;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int aux = syscall(__NR_munmap, addr, length);
	if(aux < 0) {
		errno = -aux;
		return -1;
	}

	return 0;
}
