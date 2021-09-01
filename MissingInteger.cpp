#include <algorithm>

int
solution(vector<int> &A)
{
    int i;
    int size = A.size();
    int pos = 1;

    sort(A.begin(), A.end());

    for (i = 0; i < size; i++) {
        if (A[i] < 1)
            continue;
        else if (A[i] > pos)
            break;
        else if (A[i] == pos)
            pos++;
    }
    return pos;
}