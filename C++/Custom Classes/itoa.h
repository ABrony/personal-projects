#ifndef ITOA_H
#define ITOA_H

#include <stdlib.h>

char* itoa(int i)
{
	int digits = 0;
	int tmp = i;
	while (tmp != 0)
	{
		tmp = tmp / 10;
		digits++;
	}
	if (i <= 0)
	{
		digits++;
	}
	char* res = (char*)malloc(digits + 1);
	tmp = digits - 1;
	if (i == 0) {
		res[0] = '0';
		res[1] = '\0';
		return res;
	}
	if (i < 0)
	{
		res[0] = '-';
		i = -i;
	}
	while (i != 0)
	{
		res[tmp] = (i % 10 + '0');
		i = i / 10;
		tmp--;
	}
	res[digits] = '\0';
	return res;
}

#endif
