// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
#include <stdlib.h>

char *strcpy(char *destination, const char *source)
{
	if (destination == NULL) {
        return NULL;
    }
	char *ptr;
	for (ptr = destination; *source != '\0'; source++, ptr++) {
		*ptr = *source;
	}
	*ptr = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
    if (destination == NULL) {
        return NULL;
    }
	char *ptr;
	for (ptr = destination; *source != '\0' && len; source++, ptr++, len--) {
		*ptr = *source;
	}
	while (len) {
		*ptr = '\0';
		len--;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	strcpy(destination + strlen(destination), source);
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	if (destination == NULL) {
        return NULL;
    }
	char *ptr;
	for (ptr  = destination + strlen(destination); *source != '\0' && len; source++, ptr++, len--) {
		*ptr = *source;
	}
	*ptr = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	int dif = *str1 - *str2;
	while (dif == 0 && *str1 && *str2) {
		str1++;
		str2++;
		dif = *str1 - *str2;
	}
	return dif;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	int dif = *str1 - *str2;
	while (dif == 0 && *str1 && *str2) {
		str1++;
		str2++;
		len--;
		if (len == 0) {
			return 0;
		}
		dif = *str1 - *str2;
	}
	return dif;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	if (str == NULL) {
        return NULL;
    }
	while(*str != (char)c && *str) {
		str++;
	}
	if (*str == (char)c) {
		return (char *)str;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	if (str == NULL) {
        return NULL;
    }
	const char *ptr = str + strlen(str);
	while (ptr >= str) {
		if (*ptr == (char)c) {
			return (char *)ptr;
		}
		ptr--;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	if (haystack == NULL || needle == NULL) {
        return NULL;
    }
	for (unsigned int i = 0; i < strlen(haystack) - strlen(needle); i++) {
		if (strncmp(haystack + i, needle, strlen(needle)) == 0) {
			return (char *)haystack + i;
		}
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	if (haystack == NULL || needle == NULL) {
        return NULL;
    }
	for (int i = strlen(haystack) - strlen(needle); i >= 0; i--) {
		if (strncmp(haystack + i, needle, strlen(needle)) == 0) {
			return (char *)haystack + i;
		}
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	if (destination == NULL || source == NULL) {
        return NULL;
    }
	for (unsigned  i = 0; i < num; i++) {
		*(unsigned char *)(destination + i) = *(unsigned char *)(source + i);
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	void *buf = malloc(num);
	memcpy((void *)buf, source, num);
	memcpy(destination, (void *)buf, num);
	free(buf);
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char *str1 = (unsigned char *)ptr1;
	unsigned char *str2 = (unsigned char *)ptr2;
	int dif = *str1 - *str2;
	while (dif == 0) {
		str1++;
		str2++;
		num--;
		if (num == 0) {
			return 0;
		}
		dif = *str1 - *str2;
	}
	return dif;
}

void *memset(void *source, int value, size_t num)
{
	if (source == NULL) {
		return NULL;
	}
	for (unsigned int i = 0; i < num; i++) {
		*(unsigned char *)(source + i) = (unsigned char)value;
	}
	return source;
}
