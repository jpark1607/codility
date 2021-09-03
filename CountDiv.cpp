/* v2 : 100 */
int
solution(int A, int B, int K)
{
    long alpha = A, beta = B, k = K;

    if ((A == B) && (A % K == 0))
        return 1;

    alpha = ((alpha + (k - 1)) / k) * k;
    beta = (beta / k) * k;

    if (alpha > beta)
        return 0;
    else if (alpha == beta)
        return 1;
    else
        return ((((int)(beta - alpha)) / K) + 1);
}

/* v1 : 37
 * wrong answers : 0, endpoint, type overflow */
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