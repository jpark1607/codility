#include <algorithm>

/* Lesson 8.1 Case #1
 * 1. 문제:
 *   vector A 내에서 과반을 차지하는 변수 x가 있을 경우, 이 x가 속한 A의 index들 중 하나를 return하라.
 *   과반을 차지하는 변수가 없는 경우 -1을 return한다.
 *
 * 2. 아이디어:
 *   배열을 두 번 순회하면 된다.
 *   첫번째 순회 : 0번지부터 나오는 값을 저장하고 count를 올려준 뒤, 1번지에서 나오는 값이 같으면 count를 또 올려주고,
 *     값이 다르면 count를 빼 준다.
 *     i번지 접근 시 count가 0이면 그 배열의 값을 새로이 저장하고 count를 올려준다.
 *     이렇게 순회를 완료한 후, 마지막에 저장된 값을 가지고 두 번째 순회를 수행한다.
 *   두번째 순회 : 첫번째 순회에서 저장된 값이 진짜 과반인지 체크한다.
 *   이렇게 하는 게 가능한 이유는, 과반을 차지하는 leader가 있는 경우는 무조건 마지막에 저장된 값에 그 변수값이 나올 것이며,
 *   과반을 차지하는 leader가 없는 경우는 다른 값이 저장되더라도 두번째 순회에서 leader가 아님을 확인할 수 있다.
 *
 * 3. 코드:
 *   [A] count가 0이면 그 값을 저장하고 count를 1로 만들어 준다.
 *   [B] count가 0이 아닌 경우, 저장된 값과 현재 배열의 값을 비교한다.
 *     [B-1] 같을 경우 count를 올려준다.
 *     [B-2] 다를 경우 count를 내려준다.
 *   [C] 최종 저장된 값을 가지고 다시 배열을 순회하여, 과반을 차지하는지 확인한다.
 * */
int
solution(vector<int> &A)
{
    int size = A.size();
    int num, cnt = 0, total = 0;
    int i;

    if (size == 1)
        return 0;

    for (i = 0; i < size; i++) {
        /* [A] */
        if (cnt == 0) {
            num = A[i];
            cnt++;
        }
        /* [B] */
        else {
            /* [B-1] */
            if (A[i] != num)
                cnt--;
            /* [B-2] */
            else
                cnt++;
        }
    }

    /* [C] */
    for (i = 0; i < size; i++) {
        if (A[i] == num)
            total++;

        if (total > (size / 2))
            return i;
    }

    return -1;
}

/* Lesson 8.1 Case #2
 * 1. 문제:
 *   vector A 내에서 과반을 차지하는 변수 x가 있을 경우, 이 x가 속한 A의 index들 중 하나를 return하라.
 *   과반을 차지하는 변수가 없는 경우 -1을 return한다.
 *
 * 2. 아이디어:
 *   복사본을 만들고 정렬해서 과반이 있는지 찾는다.
 *   각 변수값마다 최초 나오는 경우 count를 1로 초기화하고, 그 다음 배열에 접근할 때마다 값이 같으면 count를 늘려주면 된다.
 *
 * 3. 코드:
 *   [A] 복사본을 만들어 놓고 정렬한다.
 *   [B] 배열을 순회하며
 *     [B-1] 이전 배열의 값과 다르면 count를 1로 초기화한다.
 *       [B-1-1] 앞으로 볼 배열의 길이가 과반수보다 적으면 바로 -1을 return한다. (그냥 최적화..)
 *     [B-2] 이전 배열의 값과 같으면 count를 1 늘려준다.
 *     [B-3] count가 미리 계산해 둔 과반과 같아지는 경우, 복사해 놓은 배열에서 해당 값을 찾아 그 index를 return한다.
 * */
int
solution(vector<int> &A)
{
    int i, j;
    int len = A.size();
    int cnt = 1;
    int dom = (len / 2) + 1;
    vector<int> cp;

    if (len == 0 || len == 1)
        return (len - 1);

    /* [A] */
    cp.assign(A.begin(), A.end());
    sort(A.begin(), A.end());

    /* [B] */
    for (i = 0; i < len; i++) {
        /* [B-1] */
        if (A[i] != A[i + 1]) {
            cnt = 1;
            /* [B-1-1] */
            if (len - i - 1 < dom)
                return -1;
            else
                continue;
        }
        /* [B-2] */
        else
            cnt++;

        /* [B-3] */
        if (cnt == dom) {
            for (j = 0; j < dom; j++) {
                if (cp[j] == A[i])
                    return j;
            }
        }
    }

    return -1;
}