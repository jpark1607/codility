#include <algorithm>

/* Lesson 6.2
 * 1. 문제:
 *   주어진 vector A에 있는 세 개의 변수를 뽑아서 곱했을 때, 최대가 되는 값을 찾아라.
 *
 * 2. 아이디어:
 *   아래 둘 중 하나가 답이다.
 *     1) 음수 중 절대값이 큰 변수 두 개와, 양수 중 절대값이 큰 변수 하나의 곱
 *     2) 양수 중 절대값이 큰 변수 세 개의 곱
 *   정렬한 뒤 1)번과 2)번의 계산을 max 함수로 비교해 본다.
 *
 * 3. 코드: 코드 상으로 볼 것은 없다.
 * */
int
solution(vector<int> &A)
{
    int size = A.size();

    if (size == 3)
        return A[0] * A[1] * A[2];

    sort(A.begin(), A.end());

    return std::max(A[0] * A[1] * A[size - 1], A[size - 1] * A[size - 2] * A[size - 3]);
}