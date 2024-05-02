#include <string>

using namespace std;

/*
    Two Pointers Technique
    Time: O(n) linear
    Space: O(1) Constant
*/
bool isPalindrome(string s)
{
    int left = 0, right = s.size() - 1;

    while (left < right)
    {
        while (left < s.size() and iswalnum(s[left]) == 0)
            left++;

        while (right >= 0 and iswalnum(s[right]) == 0)
            right--;

        if (left < right and tolower(s[left]) != tolower(s[right]))
            return false;

        left++, right--;
    }

    return true;
}