#include <string>

using namespace std;

bool validPalindrome(string s, int i, int j)
{
	while (i < j)
	{
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

bool validPalindrome(string s)
{
	int i = 0, j = s.size() - 1;

	while (i < j)
	{
		if (s[i] != s[j])
			return validPalindrome(s, i + 1, j) or validPalindrome(s, i, j - 1);
		i++;
		j--;
	}

	return true;
}
