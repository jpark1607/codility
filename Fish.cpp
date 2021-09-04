#include <stack>

int
solution(vector<int> &A, vector<int> &B)
{
    int size = A.size();
    int n = 0;
    int i;
    stack<int> v;

    for (i = 0; i < size; i++) {
        if (B[i] == 1) {
            v.push(A[i]);
            n++;
        }
        else {
            n++;

            if (v.empty())
                continue;

            while (!v.empty()) {
                n--;
                if (v.top() < A[i])
                    v.pop();
                else
                    break;
            }
        }
    }

    return n;
}