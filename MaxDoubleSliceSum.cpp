#include <algorithm>

/* Lesson 9.3
 * 1. 문제:
 *   vector A에서 [X와 Y 사이의 합과, Y와 Z사이의 합]의 합 중 최대값을 구하시오.
 *
 * 2. 아이디어:
 *   Y를 기점으로 왼쪽과 오른쪽의 합들 중 가장 큰 수치를 구하는 방식으로 진행한다.
 *   Kadane 알고리즘을 쓰되, global_max 비교 시 0과 비교하면 되는 것이다.
 *
 * 3. 코드:
 *   [A] 각 방향의 부분합의 최대값을 vector에 저장한다.
 *     [A-1] Y 기준 왼쪽의 부분합의 최대값들을 구한다.
 *     [A-2] Y 기준 오른쪽의 부분합의 최대값들을 구한다.
 *   [B] i의 위치를 Y로 놓고, Y의 왼쪽의 부분합의 값과 오른쪽의 부분합의 값을 더해보면서 최대값을 구한다.
 *
 * 4. 진행 중: 62%
 *
 * */
int
solution(vector<int> &A)
{
    int size = A.size();
    vector<int> left(size, 0);
    vector<int> right(size, 0);
    int max_val = 0;
    int i, j;

    if (size == 3)
        return 0;

    /* [A] */
    for (i = 1, j = size - 2; (i < size - 1) && (j > 1); i++, j--) {
        /* [A-1] */
        left[i] = max(A[i] + left[i - 1], 0);
        /* [A-2] */
        right[j] = max(A[j] + right[j + 1], 0);
    }

    /* [B] */
    for (i = 1; i < size - 1; i++) {
        max_val = max(left[i - 1] + right[i + 1], max_val);
    }

    return max_val;
}