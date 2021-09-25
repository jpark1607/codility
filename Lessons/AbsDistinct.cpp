#include <cstdlib>
#ifndef _WIN32
#include <bits/stdc++.h>
#else
#include <limits>
#endif /* _WIN32, for INT_MIN */

/* Lesson 15.1
 * 1. 문제:
 *   오름차순으로 정렬된 vector A가 있을 때, |A[i]|의 distinct 수를 구하여라.
 *
 * 2. 아이디어:
 *   0번지부터 i를, (N - 1)번지부터 j를 출발시켜 각각의 절대값을 비교하면서 더 큰 쪽을 하나씩 당겨 준다(i++ or j--).
 *
 * 3. 코드:
 *   [A] INT_MIN값은 예외처리 해준다. 절대값을 씌울 경우 의도대로 동작하지 않을 수 있다.
 *   [B] i의 값이 j보다 커질 때까지 반복한다.
 *     [B-1] A[i]의 절대값이 A[j]의 절대값보다 클 경우, count를 늘려주고 i에 1을 더해준다.
 *     [B-2] A[i]의 절대값이 A[j]의 절대값보다 작을 경우, count를 늘려주고 j에 1을 빼준다.
 *     [B-3] A[i]의 절대값과 A[j]의 절대값이 같을 경우, count를 늘려주고 i에 1을 더해주며 j에 1을 빼준다.
 * */
int
solution(vector<int> &A)
{
    int size = A.size();
    int cnt = 0;
    int last_val = -1;
    bool finished = false;
    int i, j;

    i = 0;
    j = size - 1;

    /* 1 or 2 units */
    if (size <= 2)
        return (A[i] == A[j] ? 1 : 2);

    /* [A] */
    while (A[i] == INT_MIN)
        i++;
    if (i > 0)
        cnt++;

    /* [B] */
    while (1) {
        /* [B-1] */
        while ((abs(A[i]) > abs(A[j])) && !finished) {
            if (last_val != abs(A[i])) {
                last_val = abs(A[i]);
                cnt++;
            }

            i++;
            if (i > j)
                finished = true;
        }
        /* [B-2] */
        while ((abs(A[i]) < abs(A[j])) && !finished) {
            if (last_val != abs(A[j])) {
                last_val = abs(A[j]);
                cnt++;
            }

            j--;
            if (i > j)
                finished = true;
        }
        /* [B-3] */
        while ((abs(A[i]) == abs(A[j])) && !finished) {
            if (last_val != abs(A[i])) {
                last_val = abs(A[i]);
                cnt++;
            }

            i++;
            j--;
            if (i > j)
                finished = true;
        }

        if (finished)
            break;
    }

    return cnt;
}