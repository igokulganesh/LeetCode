#include <unordered_set>

using namespace std;

int square_sum(int n)
{
    int square = 0;

    while (n)
    {
        square += (n % 10) * (n % 10);
        n /= 10;
    }

    return square;
}

bool isHappy(int n)
{
    unordered_set<int> set;

    while (true)
    {
        if (n == 1)
            return true;
        set.insert(n);
        n = square_sum(n);

        if (set.find(n) != set.end())
            break;
    }
    return false;
}

bool isHappy(int slow)
{
    int fast = slow;

    do
    {
        slow = square_sum(slow);
        fast = square_sum(square_sum(fast));
    } while (slow != fast);

    return slow == 1;
}