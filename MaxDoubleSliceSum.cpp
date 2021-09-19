#include <algorithm>

/* Lesson 9.3
 * 1. 문제:
 *   vector A에서
 *
 * 2. 아이디어:
 *   전체 범위에 대한 합은 Kadane 알고리즘을 쓴다.
 *   이 범위 내에서 최소의 값을 기억하고 있으면서, 나중에 빼 주도록 한다.
 *
 * 3. 코드:
 *   [A]
 *   [B]
 *
 * 4. 진행 중: 38%
 *   The following issues have been detected: wrong answers.
 *     For example, for the input [0, 10, -5, -2, 0] the solution returned a wrong answer (got 15 expected 10).
 * */
int
solution(vector<int> &A)
{
    int size = A.size();
    int local_max, global_max;
    int i, min = -10001;

    if (size == 3)
        return 0;

    local_max = A[1];
    global_max = A[1];
    min = A[1];

    for (i = 3; i < size; i++) {
        if (min > A[i - 1])
            min = A[i - 1];

        /* local_max = max(A[i], local_max + A[i]) */
        if (A[i - 1] > (local_max + A[i - 1] - min)) {
            min = A[i - 1];
            local_max = A[i - 1];
        }
        else {
            local_max += A[i - 1];
        }

        global_max = max(global_max, local_max);

    }

    return global_max - min;
}