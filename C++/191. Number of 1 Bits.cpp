int hammingWeight(int n)
{
    int ones = 0;

    while (n)
    {
        ones += (n & 1);
        n = n >> 1;
    }

    return ones;
}