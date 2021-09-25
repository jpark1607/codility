#include <algorithm>
#include <cmath>

/* Lesson 11.1
 * 1. 문제:
 *   vector A의 특정 인자 A[i]를 나누어 떨어트릴 수 있는 인자를 divisor라고 한다.
 *   특정 A[i]에 대해 A[0] ~ A[N]까지의 범위에서 divisor가 아닌 것의 수를 구하여라.
 *
 * 2. 아이디어:
 *   포함되어 있는 인자와 그 개수를 알아야 하기 때문에 vector(cnt)를 쓰고, 성능을 위해 memorize를 써야 하므로 vector(mem)를 쓴다.
 *   vector A를 순회하며 A[i]를 index로 하는 첫번째 vector(cnt)에 그 개수를 적어 놓는다.
 *   vector A를 순회하며 각 A[i]마다 1부터 제곱근까지 돌면서 나누어 떨어지는 것이 있는지 찾는다. 나누어 떨어지는 것을 찾으면,
 *   그 값을 index로 하는 vector(cnt)의 인자와 나눈 몫을 index로 하는 vector(cnt)의 인자를 각각 더해 준다. (제곱수는 예외처리)
 *   계산이 완료되면 총합을 두번째 vector(mem)에 적어 놓고 return할 vector에 push해 준다.
 *   두번째 vector(mem)는 동일한 값이 올 경우 재사용하기 위함이다.
 *
 * 3. 코드:
 *   [A] 각 인자마다 vector cnt에 그 값을 올려준다.
 *   [B] vector A를 순회하며 나누어 떨어지는 수의 개수를 찾는다.
 *     [B-1] memorize되지 않은 값일 경우, 1부터 제곱근(sqrt(A[i]))까지 돌면서 나누어 떨어지는 값을 찾는다.
 *       [B-1-1] 나누어 떨어지는 값을 찾으면, 그 값의 개수와 나눈 몫의 개수를 각각 vector cnt에서 찾아서 더해 준다.
 *       [B-1-2] 제곱수일 경우 마지막 인자가 두 번 더해졌으므로 한 번은 빼 준다.
 *       [B-1-3] 구해진 개수를 vector mem에 memorize시킨다.
 *     [B-2] return할 vector result에 결과를 push_back 한다.
 * */
vector<int>
solution(vector<int> &A)
{
    int size = A.size();
    vector<int> cnt(size * 2 + 1, 0);
    vector<int> mem(size * 2 + 1, -1);
    vector<int> result;
    int sq;
    int num;
    int i, j;

    /* [A] */
    for (i = 0; i < size; i++)
        cnt[A[i]]++;

    /* [B] */
    for (i = 0; i < size; i++) {
        /* [B-1] */
        if (mem[A[i]] == -1) {
            num = 0;
            sq = sqrt(A[i]);
            for (j = 1; j <= sq; j++) {
                /* [B-1-1] */
                if (A[i] % j == 0) {
                    num += cnt[j];
                    num += cnt[A[i] / j];
                }
            }

            /* [B-1-2] */
            if ((A[i] % sq == 0) && (A[i] / sq == sq))
                num -= cnt[sq];

            /* [B-1-3] */
            mem[A[i]] = num;
        }
        /* [B-2] */
        result.push_back(size - mem[A[i]]);
    }

    return result;
}