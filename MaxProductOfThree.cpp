#include <algorithm>

int
solution(vector<int> &A)
{
    int size = A.size();

    if (size == 3)
        return A[0] * A[1] * A[2];

    sort(A.begin(), A.end());

    return std::max(A[0] * A[1] * A[size - 1], A[size - 1] * A[size - 2] * A[size - 3]);
}