/*
*
* Prints Wishes
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	system("clear");
	char wish[] = "Belated Pongal Wishes!!";

	for (int i = 0; wish[i]!= '\0'; ++i)
	{
		putchar(wish[i]);
		sleep(1);
		fflush(stdout);
	}
	printf("\n");
	return 0;
}