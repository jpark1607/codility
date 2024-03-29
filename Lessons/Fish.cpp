#include <stack>

/* Lesson 7.2
 * 1. 문제:
 *   vector A와 B가 있을 때, 좌표 i에 있는 물고기의 힘을 A[i]로 표시하며, 물고기가 나아가는 방향은 B[i]이다.
 *   B[i]가 0이면 상류, 1이면 하류 방향으로 물고기가 가며, 좌표 0번지가 가장 상류이다.
 *   이 때 서로 만나는 물고기는 힘이 더 센 쪽이 약한 쪽을 잡아 먹는다.
 *   모든 물고기가 각자의 힘(A[i])과 방향(B[i])를 가지고 진행한다고 했을 때, 최종적으로 남은 물고기의 수를 구하여라.
 *
 * 2. 아이디어:
 *   물고기가 서로 싸울 가능성은 0 <= P < Q < N 을 만족하고 A[P]는 1, A[Q]는 0일 때이다.
 *   즉 더 상류에 있는 물고기가 하류로 가고, 더 하류에 있는 물고기가 상류로 갈 때 뿐이다.
 *   배열을 앞에서부터 순회하면서 하류로 가는 것은 stack에 push하고, 상류로 가는 것은 stack에서 pop하면서 힘(A[i])을 비교하여 더 작은 쪽을 제거한다.
 *   상류로 가는 것이 없어질 때까지 stack에서 pop하면서 비교해야 한다.
 *
 *   추가로 배열을 뒤에서부터 순회하면 상류로 가는 것을 stack에 push하고, 하류로 가는 것이 나올 때 pop을 하는 방법도 가능할 듯하다.
 *
 * 3. 코드:
 *   [A] 배열을 앞에서부터 순회한다.
 *     [A-1] 하류로 가는 물고기는 stack에 push한다.
 *     [A-2] 상류로 가는 물고기는 stack pop 후 값을 비교한다.
 *       [A-2-1] 만약 stack pop한 인자가 힘이 더 약하면, 다음 stack pop 후 값을 비교한다.
 *       [A-2-2] 상류행 물고기가 더 약하면 그대로 끝낸다.
 * */
int
solution(vector<int> &A, vector<int> &B)
{
    int size = A.size();
    int n = 0;
    int i;
    stack<int> v;

    /* [A] */
    for (i = 0; i < size; i++) {
        /* [A-1] */
        if (B[i] == 1) {
            v.push(A[i]);
            n++;
        }
        else {
            n++;

            if (v.empty())
                continue;

            /* [A-2] */
            while (!v.empty()) {
                n--;
                /* [A-2-1] */
                if (v.top() < A[i])
                    v.pop();
                /* [A-2-2] */
                else
                    break;
            }
        }
    }

    return n;
}