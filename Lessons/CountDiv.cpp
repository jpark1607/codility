/* Lesson 5.2
 * 1. 문제:
 *   두 수 A, B가 주어졌을 때, A 이상 B 이하의 범위에서 K로 나누어 떨어지는 수의 개수를 구하여라.
 *
 * 2. 아이디어:
 *   A 이상의 수 중 K로 나누어 떨어지는 가장 작은 수(alpha)와 B 이하의 수 중 K로 나누어 떨어지는 가장 작은 수(beta)를 구하고
 *   beta에서 alpha를 뺀 뒤 K로 나누어 떨어지는 값에 1을 더한 결과를 return한다.
 *   단, alpha가 beta보다 크면 만족하는 게 없다는 뜻이므로 0개이다.
 *
 * 3. 코드:
 *   [A] alpha와 beta를 구한다.
 *     [A-1] alpha는 A에 K - 1의 값을 더하고, K로 나눈 뒤, 다시 K를 곱하면 얻을 수 있다.
 *     [A-2] beta는 B에 K를 나눈 뒤, 다시 K를 곱하면 얻을 수 있다.
 *   [B] 결과를 return한다.
 *     [B-1] alpha가 beta보다 크면 0이다.
 *     [B-2] beta에서 alpha를 뺀 후, 여기에 K를 나눈 값에 1을 더한다.
 * */
int
solution(int A, int B, int K)
{
    long alpha = A, beta = B, k = K;

    if ((A == B) && (A % K == 0))
        return 1;

    /* [A] */
    /* [A-1] */
    alpha = ((alpha + (k - 1)) / k) * k;
    /* [A-2] */
    beta = (beta / k) * k;

    /* [B] */
    /* [B-1] */
    if (alpha > beta)
        return 0;
    /* [B-2] */
    else
        return ((((int)(beta - alpha)) / K) + 1);
}
