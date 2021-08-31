#include <algorithm>

int
solution(vector<int> &A)
{
    int i;
    int len = A.size();

    sort(A.begin(), A.end());

    for (i = 0; i < len - 1; i += 2) {
        if (A[i] != A[i + 1])
            break;
    }
    return A[i];
}