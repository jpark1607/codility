int gcd(int x, int y);

int
solution(int N, int M)
{
    return N / (gcd(N, M));
}

int gcd(int x, int y)
{
    if (x % y == 0)
        return y;
    else
        return gcd(y, (x % y));
}
