#include <algorithm>

/* Lesson 14.1
 * 1. 문제:
 *   vector A를 K개의 그룹으로 나눌 때, 각 그룹마다의 합 중 최대값이 최소가 되는 값을 구하여라.
 *
 * 2. 아이디어: (구글을 참조함)
 *   이진탐색를 사용하는 게 A가 아니라 A의 합이 될 수 있는 최소와 최대를 기준으로 한다.
 *   l은 0(모든 A 인자가 0인 경우), r은 M * size(모든 A 인자가 M인 경우)로 놓고, 가운데 값인 m을 개별 그룹 하나의 합이 되도록 가정한 뒤
 *   실제 vector A에서 그룹을 만들어보며 비교하는 것이다.
 *   그룹 수가 K보다 크게 나왔을 경우에는 하나의 그룹의 합이 그보다 커야 하는 것을 의미하므로 l을 크게 만들어 주며(m + 1),
 *   그룹 수가 K보다 작거나 같게 나왔을 경우에는 하나의 그룹의 합이 그보다 작거나 같은 것을 의미하므로 r을 작게 만들어 준다(m - 1).
 *   단, 그룹 수가 K보다 작거나 같게 나오는 것은 답이 될 수 있다(공집합이 있을 수 있으므로)
 *
 * 3. 코드:
 *   [A] 위 기준에 의해 l과 r을 설정하고 이진 탐색을 시작한다.
 *     [A-1] m의 값을 정하고((l + r) / 2) 그룹 하나의 합이 m에 가까워지도록 계산해 본다.
 *     [A-2] 그룹 수가 K보다 크면 l을 크게 만들어 준다.
 *     [A-3] 그룹 수가 K보다 작거나 같으면 답(res)으로 min으로 갱신해주고, r을 작게 만들어 준다.
 * */

int
solution(int K, int M, vector<int> &A)
{
    int size = A.size();
    int l, r, m;
    int sum, grp, pmax;
    int res;
    int i;

    l = 0;
    r = M * size;
    res = M * size;

    while (l <= r) {
        grp = 1;
        sum = 0;
        pmax = 0;

        m = (l + r) / 2;
        for (i = 0; i < size; i++) {
            sum += A[i];
            if (sum > m) {
                pmax = max(sum - A[i], pmax);
                grp++;
                sum = A[i];
            }
        }

        pmax = max(sum, pmax);
        if (grp > K) {
            l = m + 1;
        }
        else {
            r = m - 1;
            res = min(pmax, res);
        }
    }

    return res;
}