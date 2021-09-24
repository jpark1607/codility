#include <cmath>
#include <algorithm>

/* Lesson 10.3
 * 1. 문제:
 *   vector A의 각 index i가 x좌표, A[i]가 y좌표라고 할 때, y의 높이가 주변(i - 1, i + 1)보다 높은 부분을 peak이라고 한다.
 *   이 peak마다 깃발을 꽂는다고 할 때, N개의 깃발을 꽂으려면 peak 간 거리가 N 이상이 되어야 한다.
 *   꽂을 수 있는 최대 깃발의 개수를 구하시오.
 *
 * 2. 아이디어:
 *   peak을 찾아서 vector에 넣고 최대 개수부터 탐색한다.. 가 원래 아이디어였는데, 성능이 안 좋았다.
 *   핵심은 최대 개수부터 탐색하는 게 아니라 최대 거리(peak[n - 1] - peak[0])의 제곱근(+1)의 개수부터 탐색하는 것이다.
 *   -> 최대 거리에 꽂을 수 있는 총 깃발의 수(N) x 각 깃발의 거리(N)
 *
 * 3. 코드:
 *   [A] peak 부분을 찾아 vector에 넣는다.
 *   [B] 최대 가능 개수부터 시작하여 2까지 순회하며 탐색을 시작한다. (최대 가능 개수는 위에 언급했듯 제곱근)
 *     [B-1] 깃발을 못 꽂아도 되는 여유분을 구한다(buf).
 *     [B-2] peak를 순회하면서 거리가 안 되면 여유분에서 1을 뺀다.
 *     [B-3] 여유분이 음수가 되면 그 깃발 개수만큼 못 꽂는 것이므로 false.
 *     [B-4] 여유분이 0 이상이면(정확히는 0에서만 답이 된다) 그 값을 return한다.
 *
 * 4. 참고사항:
 *   제곱근 뿐만 아니라 size와 비교하여 min을 씌운 것을 하면 더 최적화할 수 있다. (아래 주석 부분 참고)
 *   어차피 거리가 멀어도 peak의 수보다 더 많이는 못 꽂으니까.
 * */
int
solution(vector<int> &A)
{
    int size = A.size();
    int buf;
    int pos;
    int i, j;
    bool found = false;
    vector<int> peak;

    /* [A] */
    for (i = 1; i < size - 1; i++) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            peak.push_back(i);
            i++;
        }
    }

    size = peak.size();
    if (size == 0 || size == 1 || size == 2)
        return size;

    /* TODO 아래 부분을 잘 기억하자.
     *      for (i = sqrt(peak[size - 1] - peak[0]) + 1; i >= 2; i--)
     *      아래 내용도 된다.
     *      for (i = min((int)(sqrt(peak[size - 1] - peak[0]) + 1), size); i >= 2; i--)
     */
    /* [B] */
    for (i = min((int)(sqrt(peak[size - 1] - peak[0]) + 1), size); i >= 2; i--) {
    //for (i = size; i >= 2; i--) {
        /* [B-1] */
        buf = size - i;
        pos = peak[0];
        found = true;

        for (j = 1; j < size; j++) {
            /* [B-2] */
            if (peak[j] - pos < i)
                buf--;
            else
                pos = peak[j];

            /* [B-3] */
            if (buf < 0) {
                found = false;
                break;
            }
        }

        /* [B-4] */
        if (found)
            break;
    }
    return i;
}


/* 간단한 버전. 하지만 이 코드는 참고를 좀 더 했다 */
int
solution(vector<int> &A)
{
    int size = A.size();
    vector<int> peak;
    int cnt, pos;
    int i, j;

    for (i = 1; i < size - 1; i++) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            peak.push_back(i);
            i++;
        }
    }

    size = peak.size();
    if (size <= 2)
        return size;

    for (i = sqrt(peak[size - 1] - peak[0]) + 1; i >= 2; i--) {
        cnt = 1;
        pos = peak[0];

        for (j = 1; j < size; j++) {
            if (peak[j] - pos >= i) {
                cnt++;
                pos = peak[j];
            }
        }

        if (cnt >= i)
            return i;
    }

    /* cannot reach */
    return -1;
}