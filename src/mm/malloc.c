// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (p == MAP_FAILED) {
		return NULL;
	}
	if (mem_list_head.prev == &mem_list_head) {
		mem_list_init();
	}
	if (mem_list_add(p, size) == 0) {
		return p;
	} else {
		//mem_list_cleanup();
		munmap(p, size);
		return NULL;
	}
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void* p = malloc(nmemb * size);
	if(!p) {
		return NULL;
	}
	return memset(p, 0, nmemb * size);
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list *p = mem_list_find(ptr);
	if(!p) {
		return;
	}
	munmap(p->start, p->len);
	mem_list_del(ptr);
	if(mem_list_num_items() == 0) {
		mem_list_cleanup();
		mem_list_head.prev = &mem_list_head;
		mem_list_head.next = &mem_list_head;
	}
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if(!ptr) {
		return malloc(size);
	}
	free(ptr);
	return malloc(size);
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	return realloc(ptr, nmemb * size);
}
