/* v1 : 37
 * performance problem */
int
solution(int A, int B, int K)
{
    long alpha = ((A + (K - 1)) / K) * K;
    long beta = (((B + (K - 1)) / K) - 1) * K;

    if (alpha > beta)
        return 0;
    else if (alpha == beta) {
        if (alpha % K == 0)
            return 1;
        else
            return 0;
    }
    else
        return ((((int)(beta - alpha)) / K) + 1);
}