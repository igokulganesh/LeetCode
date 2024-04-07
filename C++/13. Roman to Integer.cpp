#include <unordered_map>
#include <string>

using namespace std;

int get_val(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }
    return 0;
}

int romanToInt(string s)
{
    int result = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'I' and (i + 1 < s.size()) and (s[i + 1] == 'V' or s[i + 1] == 'X'))
            result -= 1;
        else if (s[i] == 'X' and (i + 1 < s.size()) and (s[i + 1] == 'L' or s[i + 1] == 'C'))
            result -= 10;
        else if (s[i] == 'C' and (i + 1 < s.size()) and (s[i + 1] == 'D' or s[i + 1] == 'M'))
            result -= 100;
        else
            result += get_val(s[i]);
    }

    return result;
}