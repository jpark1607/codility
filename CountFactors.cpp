#include <cmath>

/* Lesson 10.1
 * 1. 문제:
 *   주어진 수의 약수의 개수를 구하여라.
 *
 * 2. 아이디어:
 *   주어진 수의 제곱근을 구하고, 1부터 그 제곱근까지의 수를 순회하며 나눠지는 수만큼 +2 해 준다.
 *   예를 들어 N이 K로 나눠질 경우, 약수는 K와 (N / K) 두 개가 있다.
 *   단, 원래 주어진 수가 제곱의 수일 경우 약수가 그 수 자체 하나뿐이기 때문에 최종 결과에서 -1을 해 준다.
 *
 * 3. 코드:
 *   [A] 제곱근을 구한다.
 *   [B] 1부터 제곱근의 정수 부분까지 순회하며 나눠지는지 확인한다.
 *     [B-1] 나눠질 경우 +2 해 준다.
 *   [C] 제곱의 수인 경우 -1 해 준다.
 * */
int
solution(int N)
{
    int i;
    /* [A] */
    int sq = sqrt(N);
    int cnt = 0;

    /* [B] */
    for (i = 1; i <= sq; i++) {
        /* [B-1] */
        if (N % i == 0)
            cnt += 2;
    }

    /* [C] */
    if (sq * sq == N)
        cnt--;

    return cnt;
}

/* v1 : 85
 * performance problem */
#include <vector>

int
solution(int N)
{
    vector<int> V;
    int K = N;
    int cnt, size, total = 1;
    int i;

    for (i = 2; i <= N; i++) {
        cnt = 0;

        while (K % i == 0) {
            K /= i;
            cnt++;
        }
        if (cnt > 0)
            V.push_back(cnt + 1);
        if (K == 1)
            break;
    }

    size = V.size();
    for (i = 0; i < size; i++)
        total *= V[i];

    return total;
}