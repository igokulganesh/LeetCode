bool isPowerOfThree(int n)
{
    while (n > 0)
    {
        if (n == 1)
            return true;

        if (n % 2 == 0 || n % 3 != 0)
            return false;
        n = n / 3;
    }
    return false;
}