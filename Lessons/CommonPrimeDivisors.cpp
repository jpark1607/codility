/* Lesson 12.2
 * 1. 문제:
 *   특정 index i에 대한 A[i]와 B[i]가 같은 소수로만 구성된 것들의 개수를 구하여라.
 *
 * 2. 아이디어:
 *   두 수의 최대공약수(gcd)를 먼저 구한다.
 *   A[i]를 gcd로 나누고, A[i]와 gcd값의 최대공약수를 구하는 것을 반복한다.
 *   같은 방식으로 B[i]에 대해서도 진행한다.
 *   각각의 gcd값이 1일 때 A[i]와 B[i]도 1이 되는지 확인한다.
 *
 * 3. 코드:
 *   [A] 두 수의 최대공약수(gcd)를 먼저 구한다.
 *   [B] gcd값과 A[i] 및 B[i]값을 대상으로 최대공약수 구하는 작업을 반복한다.
 *     [B-1] A[i]를 gcd1로 나누고, A[i]와 gcd1값의 최대공약수를 구하는 것을 반복한다.
 *     [B-2] B[i]를 gcd2로 나누고, B[i]와 gcd2값의 최대공약수를 구하는 것을 반복한다.
 *   [C] 더 이상 나눌 것이 없을 때(gcd == 1), A[i] 및 B[i]의 값이 1인지 확인한다.
 * */
int
get_gcd(int x, int y)
{
    if (x % y == 0)
        return y;
    else
        return get_gcd(y, (x % y));
}

int
solution(vector<int> &A, vector<int> &B)
{
    int K = A.size();
    int cnt = 0;
    int gcd1 = 0, gcd2 = 0;
    int i;

    for (i = 0; i < K; i++) {
        if (A[i] == B[i]) {
            cnt++;
            continue;
        }

        /* [A] */
        gcd1 = get_gcd(A[i], B[i]);
        gcd2 = gcd1;

        /* [B] */
        /* [B-1] */
        while (gcd1 != 1) {
            A[i] /= gcd1;
            if (A[i] > gcd1)
                gcd1 = get_gcd(A[i], gcd1);
            else
                gcd1 = get_gcd(gcd1, A[i]);
        }
        /* [B-2] */
        while (gcd2 != 1) {
            B[i] /= gcd2;
            if (B[i] > gcd2)
                gcd2 = get_gcd(B[i], gcd2);
            else
                gcd2 = get_gcd(gcd2, B[i]);
        }

        /* [C] */
        if (A[i] == 1 && B[i] == 1)
            cnt++;
    }
    return cnt;
}