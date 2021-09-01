#include <algorithm>

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

    cp.assign(A.begin(), A.end());
    sort(A.begin(), A.end());

    for (i = 0; i < len; i++) {
        if (A[i] != A[i + 1]) {
            cnt = 1;
            if (len - i - 1 < dom)
                return -1;
            else
                continue;
        }
        else
            cnt++;

        if (cnt == dom) {
            for (j = 0; j < dom; j++) {
                if (cp[j] == A[i])
                    return j;
            }
        }
    }

    return -1;
}