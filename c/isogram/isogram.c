#include "isogram.h"
#include <ctype.h>

bool is_isogram(const char phrase[])
{
	if (!phrase) return false;

	int flag = 0;	
	char c;

	while (*phrase)
	{
		c = *phrase;
		if (c >= 'a' && c <= 'z')
		{
			c -= 'a';
		}
		else if (c >= 'A' && c <= 'Z')
		{
			c -= 'A';
		}
		else
		{
			phrase++;
			continue;
		}
		
		if (flag & (1 << c)) return false;
		flag |= (1 << c);
		phrase++;
	}
	return true;
}

