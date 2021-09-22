/* Lesson 11.2
 * 1. 문제:
 *
 *
 * 2. 아이디어:
 *
 *
 * 3. 코드:
 *   [A]
 *     [A-1]
 *   [B]
 *
 * 4. 경과: 66%
 *   The following issues have been detected: timeout errors.
 *   Detected time complexity: O(N * log(log(N)) + M * N)
 *                             or O(M * N ** (3/2))
 * */
vector<int>
solution(int N, vector<int> &P, vector<int> &Q)
{
    int M = P.size();
    vector<int> cnt(N + 1, 0);
    vector<int> num(N + 1, 0);
    vector<int> result;
    int sum;
    int i, j;

    for (i = 2; i < N + 1; i++) {
        num[i] = i;
    }
    num[1] = 1;
    cnt[1] = 1;

    for (i = 2; i < N + 1; i++) {
        if (cnt[i] == 0) {
            for (j = i; j < N + 1; j += i) {
                if (cnt[i] > 2)
                    continue;

                while (num[j] % i == 0) {
                    cnt[j]++;
                    num[j] /= i;
                }
            }
        }
    }

    for (i = 0; i < M; i++) {
        sum = 0;
        for (j = P[i]; j <= Q[i]; j++) {
            if (cnt[j] == 2)
                sum++;
        }

        result.push_back(sum);
    }

    return result;
}