#include <stdio.h>
#include <assert.h>

int my_strcmp(char *dst, const char *src)
{
	assert(dst);
	assert(src);
	while((*dst != '\0') && (*src != '\0'))
	{
		if(*dst == *src)
		{
			dst++;
			src++;
		}
		else if(*dst > *src)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	if((*dst == '\0') && (*src != '\0'))
	{
		return -1;
	}
	if((*dst != '\0') && (*src == '\0'))
	{
		return 1;
	}
	return 0;
}

int main()
{
	char *pa = "hello I am a student";
	char *pb = "hello I am a teacher";
	int rec = my_strcmp(pa, pb);
	printf("%d\n", rec);
	return 0;
}