#include <algorithm>

/* Lesson 9.2
 * 1. 문제:
 *   vector A에서 부분합 중 최대의 값을 구하여라.
 *
 * 2. 아이디어:
 *   Kadane 알고리즘 쓴다.
 *
 * 3. 코드:
 *   [A] local_max와 global_max를 초기화한다(A[0]).
 *   [B] 배열의 인자를 순회하며 local한 최대값을 먼저 구하고, global한 최대값을 구한다.
 * */
int
solution(vector<int> &A)
{
    int size = A.size();
    long local_max, global_max;
    int i;

    if (size == 1)
        return A[0];

    /* [A] */
    local_max = (long)A[0];
    global_max = (long)A[0];

    /* [B] */
    for (i = 1; i < size; i++) {
        local_max = max((long)A[i], local_max + (long)A[i]);
        global_max = max(global_max, local_max);
    }

    return (int)global_max;
}
