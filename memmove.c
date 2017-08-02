#include <stdio.h>
#include <assert.h>
#include <string.h>

char *my_memmove(char *dst, const char *src, int len)
{
	char *ret = dst;
		char *ret = dst;
	int i = 0;
	assert(dst);
	assert(src);
	assert(len > 0);
	while (0 < len--)
	{
		*dst++ = *src++;
	}
	return ret;

int main()
{
	char arr[30] = "hello world";
	char *pa = "hello";
	my_memmove(arr, pa, strlen(pa)-2);
	printf("%s\n", arr);
	return 0;
}