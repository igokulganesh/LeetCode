#include <bits/stdc++.h>

using namespace std;

/*
 1      1
 2.     11
 3.     21
 4.     1211
 5.     111221
 6.     312211
 7.     13112221
 8.     1113213211
 9.     31131211131221
 10.    13211311123113112211
*/

string rle_compression(string s)
{
    string rle;

    for (int i = 0, j; i < s.size();)
    {
        j = i + 1;
        while (j < s.size() and s[i] == s[j])
            j++;

        rle += to_string(j - i);
        rle += s[i];
        i = j;
    }
    return rle;
}

string countAndSay(int n, string count)
{
    if (n == 0)
        return count;

    string rle = rle_compression(count);
    return countAndSay(n - 1, rle);
}

string countAndSay(int n)
{
    return countAndSay(n - 1, "1");
}

string countAndSay(int n)
{
    string rle = "1";
    while (--n)
        rle = rle_compression(rle);
    return rle;
}
