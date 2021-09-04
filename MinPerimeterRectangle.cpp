#include <cmath>

int
solution(int N)
{
    int i;
    int sq = sqrt(N);
    int x = 0;

    for (i = sq; i >= 1; i--) {
        if (N % i == 0) {
            x = (N / i) + i;
            break;
        }
    }
    return x * 2;
}