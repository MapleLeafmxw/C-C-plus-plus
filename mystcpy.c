#include <stdio.h>
#include <assert.h>

char* my_strcpy(char *dst, const char *src)
{
	char *ret = dst;
	assert(dst);
	assert(src);
	
	while(*dst++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	char arr[30];
	char *pa = "I have a dream";
	my_strcpy(arr, pa);
	printf("%s\n", arr);
	return 0;
}