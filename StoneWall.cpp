#include <stack>

int
solution(vector<int> &H)
{
    stack<int> st;
    int cnt = 0;
    int size = H.size();
    int i;

    st.push(H[0]);

    for (i = 1; i < size; i++) {
        while ((!st.empty()) && (st.top() > H[i])) {
            st.pop();
            cnt++;
        }

        if ((st.empty()) || (st.top() < H[i]))
            st.push(H[i]);
    }

    cnt += st.size();

    return cnt;
}