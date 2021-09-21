#include <stack>

/* Lesson 7.4
 * 1. 문제:
 *   vector H의 각각의 인자가 밑변 1인 직사각형의 높이를 나타낸다고 할 때, 이 직사각형들로 이루어진 벽을 직사각형들로 나눌 수 있는 최소 개수를 구하라.
 *   (문제의 그림 참조)
 *
 * 2. 아이디어:
 *   stack을 사용하여 그 전에 넣은 길이보다 다음에 넣을 길이가 더 길면 그대로 넣고, 짧으면 긴 게 나올 때까지 stack에서 pop을 반복한다.
 *   stack에서 pop할 때 count를 올려준다.
 *
 * 3. 코드:
 *   [A] 최초 값을 stack에 넣은 후 1번지부터 배열을 순회한다.
 *     [A-1] stack의 가장 top 값이 현재 값보다 더 크면, top의 값이 더 작거나 같을 때까지 pop하며 count를 올려준다.
 *     [A-2] stack이 empty이거나 top 값이 현재 값보다 더 작으면 현재 값을 stack에 push한다.
 *   [B] 배열 순회 완료 후, 누적된 count에 현재 stack에 쌓인 개수를 더해준다.
 * */
int
solution(vector<int> &H)
{
    stack<int> st;
    int cnt = 0;
    int size = H.size();
    int i;

    /* [A] */
    st.push(H[0]);
    for (i = 1; i < size; i++) {
        /* [A-1] */
        while ((!st.empty()) && (st.top() > H[i])) {
            st.pop();
            cnt++;
        }

        /* [A-2] */
        if ((st.empty()) || (st.top() < H[i]))
            st.push(H[i]);
    }

    /* [B] */
    cnt += st.size();

    return cnt;
}