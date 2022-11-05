#include <stdio.h>

int main()
{
    char s1[] = "Hello World\n Hello ";
    int i = 0;
	char	cc = '\n';
    i = 0;
	while (s1[i])
	{
        printf("|%d| -=- |%c|\n", i, s1[i]);
		if (s1[i] == cc)
			return (i);
		i++;
	}
    return (0);
}