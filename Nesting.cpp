// Same as Bracket..?
#include <stack>

int
solution(string &S)
{
    stack<char> st;

    for (string::iterator it = S.begin(); it != S.end(); ++it) {
        switch (*it) {
        case '(':
            st.push(*it);
            break;
        case ')':
            if (st.top() != '(' || st.empty())
                return 0;
            st.pop();
            break;
        default:
            return 0;
        }
    }

    return (st.empty() ? 1 : 0);
}