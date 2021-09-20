#include <algorithm>

/* Lesson 6.3
 * 1. 문제:
 *   vector A가 있고 0 <= P < Q < R < N 일 때, A[P], A[Q], A[R]의 값을 길이로 하는 삼각형이 존재할 경우 1, 없으면 0을 return한다.
 *
 * 2. 아이디어:
 *   정렬해서 A[P] + A[Q] > A[R]를 만족하는 게 있는지 확인한다.
 *
 * 3. 코드:
 *   [A] 정렬한다.
 *   [B] A[P] + A[Q] > A[R]를 만족하는 게 있는지 확인한다.
 * */
int
solution(vector<int> &A)
{
    int size = A.size();
    int i;

    /* [A] */
    sort(A.begin(), A.end());

    for (i = size - 1; i >= 2; i--) {
        /* [B] */
        if ((long)A[i - 1] + (long)A[i - 2] > (long)A[i])
            return 1;
    }

    return 0;
}