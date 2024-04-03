#include <vector>
#include <string>

using namespace std;

vector<string> fizzBuzz(int n)
{
    int i = 1;
    vector<string> result = vector<string>(n);

    while (i <= n)
    {
        if (i % 3 == 0 && i % 5 == 0)
            result[i - 1] = "FizzBuzz";
        else if (i % 3 == 0)
            result[i - 1] = "Fizz";
        else if (i % 5 == 0)
            result[i - 1] = "Buzz";
        else
            result[i - 1] = to_string(i);
        i++;
    }
    return result;
}