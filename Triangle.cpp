#include <algorithm>

int
solution(vector<int> &A)
{
    int size = A.size();
    int i;

    sort(A.begin(), A.end());

    for (i = size - 1; i >= 2; i--) {
        if ((long)A[i - 1] + (long)A[i - 2] > (long)A[i])
            return 1;
    }

    return 0;
}