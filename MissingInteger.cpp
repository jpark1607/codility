#include <algorithm>

/* Lesson 4.4
 * 1. 문제:
 *   주어진 vector A에 포함되어 있지 않은 자연수 중 가장 작은 수를 return하라.
 *
 * 2. 아이디어:
 *   정렬하고, 음수는 지나간 뒤에, 양수 부분부터 1부터 체크하면 된다.
 *
 * 3. 코드:
 *   [A] 정렬한다.
 *   [B] 배열을 순회하며 맞는 값을 찾는다.
 *     [B-1] 음수는 필요 없으므로 넘어간다.
 *     [B-2] 배열의 변수가 원하는 값이면 다음 값(+1)을 찾아본다.
 *     [B-3] 배열의 변수가 원하는 값보다 크면 그 값은 빠졌다는 의미이다. 이 값을 return한다.
 * */
int
solution(vector<int> &A)
{
    int i;
    int size = A.size();
    int pos = 1;

    /* [A] */
    sort(A.begin(), A.end());

    /* [B] */
    for (i = 0; i < size; i++) {
        /* [B-1] */
        if (A[i] < 1)
            continue;
        /* [B-2] */
        else if (A[i] == pos)
            pos++;
        /* [B-3] */
        else if (A[i] > pos)
            break;
    }
    return pos;
}