#include <algorithm>

/* Lesson 4.2 Case #1
 * 1. 문제:
 *   주어진 vector에 있는 모든 변수가 순열을 이루는지 확인한다.
 *
 * 2. 아이디어:
 *   정렬해서 앞에서부터 비교해보자.
 *
 * 3. 코드:
 *   [A] 정렬한다.
 *   [B] (i + 1)번째 배열이 i번째 배열보다 1이 더 큰 지 확인한다.
 * */
int
solution(vector<int> &A)
{
    int i;
    int len = A.size();

    /* [A] */
    sort(A.begin(), A.end());

    if (A[0] != 1)
        return 0;

    /* [B] */
    for (i = 0; i < len - 1; i++) {
        if (A[i] != A[i + 1] - 1)
            return 0;
    }
    return 1;
}

/* Lesson 4.2 Case #2
 * 1. 문제:
 *   주어진 vector에 있는 모든 변수가 순열을 이루는지 확인한다.
 *
 * 2. 아이디어:
 *   각 변수가 나타날 경우 true로 활성화 할 bool type array를 만든다.
 *   i번째 배열의 변수가 vector의 길이보다 크거나, 이미 true로 활성화 한 array 번지에 접근하면 0을 return한다.
 *
 * 3. 코드:
 *   [A] 활성화된 변수를 기억할 bool type array를 할당한다.
 *   [B] 아래 둘 중 하나 조건에 맞는 경우 순열이 아니므로 0을 return한다.
 *     [B-1] A[i]의 값이 vector의 size보다 큰 경우(중간에 빈 숫자가 생김)
 *     [B-2] bool type array에서 true로 되어 있는 번지를 다시 접근할 경우(중복값)
 * */
int
solution(vector<int> &A)
{
    int i;
    int len = A.size();
    bool *arr;

    arr = new bool[len] {false};

    for (i = 0; i < len; i++) {
        if (A[i] > len || arr[A[i] - 1] == true)
            return 0;

        arr[A[i] - 1] = true;
    }
    return 1;
}