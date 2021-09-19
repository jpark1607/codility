#include <algorithm>

/*
 * 1. 문제:
 *   vector A에서 index P, Q, R이 삼각형을 이루는(즉, A[P] + A[Q] > A[R]) 모든 경우의 수를 출력하라.
 *
 * 2. 아이디어:
 *  idx  |0|1|2|3|4|5|6|7|
 *  arr  |-|-|-|-|-|-|-|-|
 *  ptr1  p q r  ~  r
 *  ptr2  p   q    ~  r
 *
 *  위 예제를 보면, 첫번째 ptr1에서 r이 만족하는 경우는 r(5) - q(1) 이다. 단, r의 좌표는 6번지이기 때문에 r - q - 1이 정확한 계산이다.
 *  q가 2번지로 옮겨 가도, r이 5번째까지는 무조건 만족한다는 것을 알 수 있기 때문에 지금 있는 r의 번지부터 체크해보면 된다.
 *  r의 반경은 size까지이며, 이 작업은 q가 (size - 1)이 될 때까지 반복한다.
 *  그리고 이 전체의 작업을 p에 대해 돌면서 수행하며, p는 (size - 2)까지 반복한다.
 *
 * 3. 코드:
 *   [A] vector를 정렬시킨다.
 *   [B] 아래 각 항목에 따라 중첩 반복문을 수행한다.
 *     [B-1] (1차) 0 <= p 이고, p < (size - 2)
 *     [B-2]   (2차) (p + 1) <= q 이고, q < (size - 1)
 *     [B-3]     (3차) r < size 이고, A[p] + A[q] > A[r]
 *     [B-4]     3차가 만족하지 않을 때 (r - q - 1)만큼 cnt에 더해 준다(만족하는 부분 개수).
 * */
int
solution(vector<int> &A)
{
    int size = A.size();
    int p, q, r;
    int cnt = 0;

    if (size < 3)
        return 0;

    /* [A] */
    sort(A.begin(), A.end());

    /* [B] */
    /* [B-1] */
    for (p = 0; p < size - 2; p++) {
        q = p + 1;
        r = p + 2;
        /* [B-2] */
        for (; q < size - 1; q++) {
            /* [B-3] */
            while ((r < size) && ((A[p] + A[q]) > A[r])) {
                r++;
            }
            /* [B-4] */
            cnt += r - q - 1;
        }
    }

    return cnt;
}