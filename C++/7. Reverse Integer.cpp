#include <bits/stdc++.h>

using namespace std;

int reverse(int x)
{
	long res = 0;

	while (x)
	{
		res = (res * 10) + (x % 10);
		x /= 10;
	}

	return (res > INT_MAX or res < INT_MIN) ? 0 : res;
}

int reverse(int x)
{
	int res = 0;

	while (x)
	{
		if (res > INT_MAX / 10 or res < INT_MIN / 10)
		{
			res = 0;
			break;
		}
		res = (res * 10) + (x % 10);
		x /= 10;
	}

	return res;
}