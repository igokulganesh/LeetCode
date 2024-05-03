#include <vector>

using namespace std;

// Brute-Force
bool isprime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int countPrimes(int n)
{
    if (n <= 2)
        return 0;

    int count = 1;

    for (int i = 3; i < n; i += 2)
        if (isprime(i))
            count++;

    return count;
}

// Sieve of Eratosthenes
int countPrimes(int n)
{
    if (n <= 2)
        return 0;

    vector<bool> isprime(n, true);

    isprime[0] = false;
    isprime[1] = false;

    for (int i = 2; i * i < n; i++)
    {
        // Skip non Prime Numbers
        if (isprime[i])
            for (int j = i + i; j < n; j += i)
                isprime[j] = false;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
        if (isprime[i])
            count++;

    return count;
}
