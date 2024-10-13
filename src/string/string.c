// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
// https://www.techiedelight.com/implement-strcpy-function-c/
char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	if (destination == NULL) {
		return NULL;
	}
	char *result = destination;
	while(*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return result;
}
// https://www.techiedelight.com/implement-strncpy-function-c/
char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	if (destination == NULL) {
        return NULL;
    }
	char* result = destination;
	size_t i = 0;
    while (*source != '\0' && i < len)
    {
        *destination = *source;
        destination++;
        source++;
        i++;
    }

    while (i < len)
    {
	    *destination = '\0';
        destination++;
        i++;
    }

	return result;
}
// https://www.techiedelight.com/implement-strcat-function-c/
char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char* ptr = destination + strlen(destination);
    while (*source != '\0') {
        *ptr++ = *source++;
    }
    *ptr++ = '\0';
	return destination;
}
// https://www.techiedelight.com/implement-strncat-function-c/
char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char* ptr = destination + strlen(destination);

    while (*source != '\0' && len--) {
        *ptr++ = *source++;
    }

    *ptr++ = '\0';
	return destination;
}
// https://www.techiedelight.com/implement-strcmp-function-c/
int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	int a = strlen(str1);
	int b = strlen(str2);
	if(a < b) {
		return -1;
	}
	if(b < a) {
		return 1;
	}
	int i = 0, flag = 0;
    while (flag == 0 && str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] > str2[i]) {
            flag = 1;
        } else if (str1[i] < str2[i]) {
            flag = -1;
        } else {
            i++;
        }
    }
    return flag;
}
// https://stackoverflow.com/questions/32560167/strncmp-implementation
int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	int i = 0, flag = 0;
    while (flag == 0 && len--) {
        if (str1[i] > str2[i]) {
            flag = 1;
        } else if (str1[i] < str2[i]) {
            flag = -1;
        } else {
            i++;
        }
    }
    return flag;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;
	return i;
}
// https://stackoverflow.com/questions/14367727/how-does-strchr-implementation-work
char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	char *isCharFind = NULL;
    if (str != NULL)
    {
        do
        {
            if (*str == (char)c)
            {
                isCharFind = (char *)str;
                break;
            }
        } while (*str++);
    }
    return isCharFind;
}
// https://aticleworld.com/strrchr-function-in-c-cpp/
char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *isCharFind = NULL;
    if (str != NULL)
    {
        do
        {
            if (*str == (char)c )
            {
                isCharFind = (char *)str;
            }
        } while (*str++);
    }
    return isCharFind;
}

int compare(const char *X, const char *Y)
{
    while (*X && *Y)
    {
        if (*X != *Y) {
            return 0;
        }
        X++;
        Y++;
    }
    return (*Y == '\0');
}
// https://www.techiedelight.com/implement-strstr-function-c-iterative-recursive/
char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	while (*haystack != '\0')
    {
        if ((*haystack == *needle) && compare(haystack, needle)) {
            return (char *)haystack;
        }
        haystack++;
    }
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *aux = NULL;
	while (*haystack != '\0')
    {
        if ((*haystack == *needle) && compare(haystack, needle)) {
            aux = (char *)haystack;
        }
        haystack++;
    }
	return aux;
}
// https://www.geeksforgeeks.org/write-memcpy/
void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *pszDest = (char *)destination;
    const char *pszSource =(const char*)source;
    if ((pszDest!= NULL) && (pszSource!= NULL))
    {
        while (num)
        {
            *(pszDest++)= *(pszSource++);
            --num;
        }
    }
    return destination;
}
// https://www.geeksforgeeks.org/write-memcpy/
void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	unsigned char *d = (unsigned char *)destination;
    const unsigned char *s = (const unsigned char *)source;

    if (d < s) {
        while (num--) {
            *d++ = *s++;
        }
    } else if (d > s) {
        d += num;
        s += num;
        while (num--) {
            *(--d) = *(--s);
        }
    }

	return destination;
}
// https://stackoverflow.com/questions/811926/memcmp-c-implementation-any-logical-errors-with-this-one
int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	unsigned char *p = (unsigned char *)ptr1;
    unsigned char *q = (unsigned char *)ptr2;
    int charCompareStatus = 0;
    if (ptr1 == ptr2)
    {
        return charCompareStatus;
    }
    while (num > 0)
    {
        if (*p != *q)
        {
            charCompareStatus = (*p >*q)?1:-1;
            break;
        }
        num--;
        p++;
        q++;
    }
    return charCompareStatus;
}
// https://stackoverflow.com/questions/18851835/create-my-own-memset-function-in-c
void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char* p = source;
    while (num--)
    {
        *p++ = (unsigned char)value;
    }
	return source;
}
