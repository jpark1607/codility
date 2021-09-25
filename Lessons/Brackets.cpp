#include <stack>

/* Lesson 7.1
 * 1. 문제:
 *   String S가 properly nested(정상 중첩?)인지 확인하여라.
 *   예를 들어 "{[()()]}"는 properly nested이고, "([)()]"는 아니다.
 *
 * 2. 아이디어:
 *   stack을 활용한다.
 *   open bracket('{', '[', '(')은 stack에 바로 넣고, close bracket('}', ']', ')')은 stack을 pop하면서 자기 짝이 맞는지 확인해본다.
 *
 * 3. 코드:
 *   [A] open bracket은 stack에 push한다.
 *   [B] close bracket은 stack에서 pop하면서 자기 짝이 맞는지 확인한다.
 * */
int
solution(string &S)
{
    stack<char> st;

    for (string::iterator it = S.begin(); it != S.end(); ++it) {
        switch (*it) {
        /* [A] */
        case '(':
        case '{':
        case '[':
            st.push(*it);
            break;
        /* [B] */
        case ')':
            if (st.top() != '(')
                return 0;
            st.pop();
            break;
        case '}':
            if (st.top() != '{')
                return 0;
            st.pop();
            break;
        case ']':
            if (st.top() != '[')
                return 0;
            st.pop();
            break;
        default:
            return 0;
        }
    }

    return (st.empty() ? 1 : 0);
}