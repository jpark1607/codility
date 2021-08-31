#include <algorithm>

int
solution(vector<int> &A)
{
    int i;
    int len = A.size();

    sort(A.begin(), A.end());

    if (A[0] != 1)
        return 0;

    for (i = 0; i < len - 1; i++) {
        if (A[i] != A[i + 1] - 1)
            return 0;
    }
    return 1;
}