#include <algorithm>

/* Lesson 2.2
 * 1. 문제:
 *   어떤 vector A가 있을 때, 개수가 홀수인 변수 A[i]를 찾아라.
 *
 * 2. 아이디어:
 *   들어갈 수 있는 변수의 수가 적으면 별도의 array를 두는 게 편하고(공간복잡도 증가), 변수의 수가 많다면 정렬하면 편하다.
 *   정렬을 하는 경우 끝까지 탐색하지 않아도 되며, index를 두 개씩 넘어가며 A[i]와 A[i + 1]을 비교하면 된다.
 *   본 문제는 1 ~ 10억까지 이므로 정렬해서 찾는 방법을 선택했다.
 *
 * 3. 코드:
 *   [A] 정렬한다.
 *   [B] index를 2개씩 넘어가며 A[i]와 A[i + 1]이 같은지 확인하고, 다르면 A[i]의 값을 return한다.
 * */
int
solution(vector<int> &A)
{
    int i;
    int len = A.size();

    /* [A] */
    sort(A.begin(), A.end());

    /* [B] */
    for (i = 0; i < len - 1; i += 2) {
        if (A[i] != A[i + 1])
            break;
    }
    return A[i];
}