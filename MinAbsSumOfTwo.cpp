#include <algorithm>
#include <cstdlib>

/* Lesson 15.4
 * 1. 문제:
 *   vector A에서 두 변수의 합의 절대값이 가장 작은 값을 찾아라.
 *
 * 2. 아이디어:
 *   정렬하고 양 끝에서부터 합해보면서 줄여 나간다.
 *
 * 3. 코드:
 *   [A] 정렬한다.
 *   [B] i = 0, j = (N - 1)의 위치부터 두 배열 인자를 합해서 절대값을 구하고, 아래 항목에 따라 index를 바꿔준다.
 *     [B-1] 합이 0보다 클 경우 j--;
 *     [B-2] 합이 0보다 작을 경우 i++;
 *     [B-3] 합이 0일 경우 무조건 최소이므로 0을 return
 *   [C] 합의 절대값이 min값보다 작을 경우 대체한다.
 * */
int
solution(vector<int> &A)
{
    int size = A.size();
    int min = 2000000001;
    int sum = 0;
    int i, j;

    /* [A] */
    sort(A.begin(), A.end());

    /* [B] */
    i = 0, j = size - 1;
    while (i <= j) {
        sum = A[i] + A[j];
        /* [B-1] */
        if (sum > 0)
            j--;
        /* [B-2] */
        else if (sum < 0)
            i++;
        /* [B-3] */
        else
            return 0;

        /* [C] */
        min = (min > abs(sum)) ? abs(sum) : min;
    }

    return min;
}