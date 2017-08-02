#include <stdio.h>
#include <assert.h>
#include <string.h>

char *my_memcpy(char *dst, const char *src, int len)
{
	int i = 0;
	char * ret = dst;
	assert(dst);
	assert(src);
	assert(len > 0);
	while((*dst++ = *src++) && (i < len))
	{
		i++;
	}
	return ret;
}

int main()
{
	char pa[] = "********************";
	char pb[] = "asdko123kjhads";
	my_memcpy(pa, pb, strlen(pb)-5);
	printf("%s\n", pa);
	return 0;
}