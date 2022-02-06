#include <stdio.h>
#include <stdlib.h> // malloc in stdlib.h

int main()
{
	int *data;
	data = (int*)malloc(sizeof(int));
	*data = 1;
	printf("%d\n",*data);

	return 0;
}
