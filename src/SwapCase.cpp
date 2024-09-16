#include "SwapCase.h"

string SwapCase::calculate(const string str, const bool b) const
{
	if (b)
	{
		print(str);
	}

	string swapStr = str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			swapStr[i] = str[i] + 32;
		}
		
		else if(str[i] >= 97 && str[i] <= 122)
		{
			swapStr[i] = str[i] - 32;
		}
	}
	return swapStr;
}
