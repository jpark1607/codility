/* v2 */
#include <cmath>

int
solution(int N)
{
    int i;
    int sq = sqrt(N);
    int cnt = 0;

    for (i = 1; i <= sq; i++) {
        if (N % i == 0)
            cnt += 2;
    }

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