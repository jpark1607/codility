/* Exercise 1.2
 * 1. 문제:
 *   주어진 배열이 각 좌표의 막대의 높이라고 할 때, 물을 가득 채울 경우 가장 깊은 수심의 값을 구하여라.
 *
 * 2. 아이디어:
 *   포인터 세 개(l/m/r, l < m < r)를 두고 움직인다.
 *   m은 A[l]과 A[r] 사이에 가장 작은 높이 A[m]을 찾기 위한 용도이다.
 *   A[r]이 A[l]보다 작을 경우 A[r] - A[m]과 maxDepth 중 max 값을 취한다.
 *   A[r]이 A[l]보다 클 경우 A[l] - A[m]와 maxDepth 중 max 값을 취하고, l의 위치를 r로, m의 위치는 l + 1로 갱신해 준다.
 * */

int
solution(vector<int> &A)
{
    int l = 0, m = 1, r;
    int size = A.size();
    int maxDepth = 0;

    if (size <= 2)
        return 0;

    while (l < (size - 2) && A[l] <= A[m]) {
        l++;
        m++;
    }
    if (m == (size - 1))
        return 0;

    for (r = m + 1; r < size; r++) {
        if (A[r] <= A[m])
            m = r;
        else if (A[r] > A[m] && A[r] < A[l])
            maxDepth = max(A[r] - A[m], maxDepth);
        else { // A[r] >= A[l]
            maxDepth = max(A[l] - A[m], maxDepth);

            l = r;
            m = l + 1;
            while (l < (size - 2) && A[l] <= A[m]) {
                l++;
                m++;
            }
            r = m;
        }
    }

    return maxDepth;
}