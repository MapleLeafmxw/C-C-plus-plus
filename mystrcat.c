#include <stdio.h>
#include <assert.h>

char *my_strcat(char *dst, const char *src)
{
	char *rec = dst;
	assert(dst);
	assert(src);
	while(*dst++ = *src++)
	{
		;
	}
	return rec;
}

int my_strlen(char *dst)
{
	int count = 0;
	assert(dst);
	while(*dst++)
	{
		count++;
	}
	return count;
}

int main()
{
	char arr[30] = "hello world";
	char *pa = "I have a dream";
	int rec = my_strlen(arr);
	my_strcat(arr+rec, pa);
	printf("%s", arr);
	return 0;
}