#include <cstdlib>
#include <numeric>

/* Lesson 3.3
 * 1. 문제:
 *   vector A가 있을 때, 이 vector를 index P 기준으로 (A[0] ~ A[P - 1])과 (A[P] ~ A[N - 1])의 합을 각각 구한 뒤,
 *   두 묶음의 차이에 대한 절대값이 제일 작은 경우를 찾아라.
 *
 * 2. 아이디어:
 *   vector A에 대한 전체 합을 구해놓고, A[i]번지의 값을 두 번 뺀 값에 대한 절대값을 구해본다.
  *
 * 3. 코드:
 *   [A] 전체 합을 구한다.
 *   [B] A[i]번지 변수의 값을 두 번 뺀다. 두 번 빼면서 전체의 묶음에 대한 차이가 계속 계산된다.
 *     [B-1] 절대값을 구해서 min보다 작은지 비교한다.
 * */
int
solution(vector<int> &A)
{
    int sum = accumulate(A.begin(), A.end(), 0); /* [A] */
    int min = 999999999;
    int size = A.size();
    int res;

    /* [B] */
    for (int i = 0; i < size - 1; i++) {
        sum -= A[i] * 2;
        /* [B-1] */
        res = abs(sum);
        if (min > res)
            min = res;
        if (min == 0)
            return 0;
    }

    return min;
}