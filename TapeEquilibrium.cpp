#include <cstdlib>
#include <numeric>

int
solution(vector<int> &A)
{
    int sum = accumulate(A.begin(), A.end(), 0);
    int min = 999999999;
    int size = A.size();
    int res;

    for (int i = 0; i < size - 1; i++) {
        sum -= A[i] * 2;
        res = abs(sum);
        if (min > res)
            min = res;
        if (min == 0)
            return 0;
    }

    return min;
}