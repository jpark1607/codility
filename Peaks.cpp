/* Lesson 10.4
 * 1. 문제:
 *   vector A의 각 index i가 x좌표, A[i]가 y좌표라고 할 때, y의 높이가 주변(i - 1, i + 1)보다 높은 부분을 peak이라고 한다.
 *   vector A의 부분집합 인자의 수를 균등하게 만들면서, 각 부분집합에 최소 하나 이상의 peak이 들어가게 만드는 최대 부분집합의 수를 구하여라.
 *
 * 2. 아이디어:
 *   peak을 모아 놓은 vector를 만들고, vector A를 K개 단위로 묶어 앞에서부터 peak이 있는지 검사한다.
 *   이 때 K는 vector A의 인자의 수를 나누어 떨어져야 하며, 최소값은 max(0부터 첫번째 peak의 위치까지의 길이, 마지막 peak의 위치부터 끝까지의 길이)
 *   여야 한다.
 *
 * 3. 코드:
 *   [A] peak 부분을 찾아 vector에 넣는다.
 *   [B] 논리적 최소값을 구한다.
 *   [C] 논리적 최소값으로 설정한 개수부터 size - 1까지 탐색한다. (size까지 탐색하면 결과는 1이므로 할 필요가 없다)
 *     [C-1] 탐색할 개수가 size를 나누어 떨어지지 않으면 pass한다.
 *     [C-2] 최소 검사 구간으로 l(left)은 0, r(right)는 i를 설정한다.
 *     [C-3] 현재 탐색하는 peak 값이 r 이상이면 지금 설정한 l/r 구간에는 peak값이 없는 것이므로 fail처리한다.
 *     [C-4] 각 구간을 반복 탐색하며, peak vector에 있는 값인지 체크한다.
 *     [C-5] failed가 아니면 i개만큼씩 묶을 수 있다는 뜻이므로, 묶음의 개수를 구하는 (size / i)를 return한다.
 * */
int
solution(vector<int> &A)
{
    int size = A.size(), psize;
    vector<int> peak;
    int dist;
    int l, r;
    int i, j;
    bool failed = false;

    /* [A] */
    for (i = 1; i < size - 1; i++) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            peak.push_back(i);
            i++;
        }
    }

    psize = peak.size();
    if (psize <= 1)
        return psize;

    /* [B] */
    dist = peak[0] + 1;
    if (size - peak[psize - 1] > dist)
        dist = size - peak[psize - 1];

    /* [C] */
    for (i = dist; i < size; i++) {
        /* [C-1] */
        if (size % i != 0)
            continue;
        /* [C-2] */
        l = 0;
        r = i;

        failed = false;
        j = 0;
        while (j < psize) {
            /* [C-3] */
            if (peak[j] >= r) {
                failed = true;
                break;
            }

            /* [C-4] */
            while (peak[j] >= l && peak[j] < r) {
                j++;
            }
            l = r;
            r += i;
        }

        /* [C-5] */
        if (!failed)
            return (size / i);
    }

    return 1;
}