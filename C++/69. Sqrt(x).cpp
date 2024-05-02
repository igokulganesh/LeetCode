// Brute-Force
int mySqrt(int x)
{
    unsigned long int sq = 1;

    while (sq * sq < x)
        sq++;

    if (sq * sq > x)
        sq--;

    return sq;
}

// Binary-Search
int mySqrt(int x)
{
    int l = 0, r = x, m;

    while (l <= r)
    {
        m = l + (r - l) / 2;

        if ((long)m * m > (long)x)
            r = m - 1;
        else if ((long)m * m < (long)x)
            l = m + 1;
        else
            return m;
    }
    return -1;
}