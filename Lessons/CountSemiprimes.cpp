/* Lesson 11.2
 * 1. 문제:
 *   Semi Prime이란 두 개의 Prime Number(소수)의 곱으로만 이루어진 수를 의미한다.
 *   주어진 index i가 있고, vector P는 시작 자연수를, vector Q는 끝 자연수를 의미한다고 할 때, P[i] 이상 Q[i] 이하의 범위에서 Semi Prime의
 *   개수를 모두 찾아라.
 *
 * 2. 아이디어:
 *   에라토스테네스의 체만 사용해서는 성능 상 안 좋으므로, 결과를 누적시키는 Prefix Sum까지 같이 고려해야 한다.
 *   아래 [A]가 에라토스테네스의 체를 사용한 것이며, [B]가 결과를 누적시킨 것이다.
 *
 * 3. 코드:
 *   [A] 주어진 자연수 N까지의 범위 중에 Semi Prime들을 모두 찾는다.(vector cnt의 결과가 2인 것)
 *   [B] cnt vector를 따라가면서 결과가 2인 것들을 찾아보며 vector num에다가 Semi Prime 결과를 누적시킨다.
 *   [C] vector P, Q를 순회하며 해당 범위에 누적된 Semi Prime 결과의 차이로 result vector에 push한다.
 * */
vector<int>
solution(int N, vector<int> &P, vector<int> &Q)
{
    int M = P.size();
    vector<int> cnt(N + 1, 0);
    vector<int> num(N + 1, 0);
    vector<int> result;
    int sum = 0;
    int i, j;

    for (i = 2; i < N + 1; i++) {
        num[i] = i;
    }
    num[1] = 1;
    cnt[1] = 1;

    /* [A] */
    for (i = 2; i <= N; i++) {
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

    /* [B] */
    for (i = 1; i <= N; i++) {
        if (cnt[i] == 2)
            sum++;
        num[i] = sum;
    }

    /* [C] */
    for (i = 0; i < M; i++) {
        result.push_back(num[Q[i]] - num[P[i] - 1]);
    }

    return result;
}