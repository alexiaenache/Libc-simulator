// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
// https://elixir.bootlin.com/musl/latest/source/src/malloc/mallocng/malloc.c#L299
void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	 if (size == 0) {
        return NULL;
    }

    size_t total_size = size + sizeof(size_t);
    void *aux = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (aux == MAP_FAILED) {
        return NULL;
    }

    size_t *size_ptr = (size_t *)aux;
    *size_ptr = size;
    mem_list_add((void *)((size_t *)aux + 1), size);

    return (void *)(size_ptr + 1);
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *aux = malloc(nmemb * size);
	for (unsigned long i = 0; i < nmemb; i++) {
		*(size_t *) aux = 0;
	}

	return aux;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL) {
        return;
    }
	struct mem_list *item = mem_list_find(ptr);
	if (item != NULL) {
		mem_list_del(ptr);
		size_t block_size = *((size_t *)ptr - 1);
        void *block_start = (void *)((char *)ptr - sizeof(size_t));

        munmap(block_start, block_size + sizeof(size_t));
	}
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL) {
        return malloc(size);
    }
    if (size == 0) {
        free(ptr);
        return NULL;
    }
	size_t old_size = *(((size_t *) ptr) - 1);
	void *aux = malloc(size);

	if (size > old_size) {
		memcpy(aux, ptr, old_size);
	} else {
		memcpy(aux, ptr, size);
	}
	free(ptr);
	return aux;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	void *aux = realloc(ptr, nmemb * size);
	if (aux == NULL) {
		errno = ENOMEM;
		return NULL;
	}

	return aux;
}
