#include <stdio.h>
#include <assert.h>

char *my_strncpy(char *dst, const char *src, int len)
{
	int i = 0;
	char *ret = dst;
	assert(dst);
	assert(src);
	assert(len > 0);
	while((*dst++ = *src++) && (i < len))
	{
		i++;
	}
	*dst = '\0';
	return ret;
}

int main()
{
	char arr[30];
	char *pa = "I have a dream";
	my_strncpy(arr, pa, 6);
	printf("%s", arr);
	return 0;
}