// v1 : 85
#include <cmath>
#include <vector>

int
solution(int N)
{
    int i;
    vector<int> V;
    int K = N;
    int cnt;
    int total = 1;
    int size;

    for (i = 2; i <= N; i++) {
        cnt = 0;

        while (K % i == 0) {
            K /= i;
            cnt++;
        }
        if (cnt > 0)
            V.push_back(cnt + 1);
        if (K == 1)
            break;
    }

    size = V.size();
    for (i = 0; i < size; i++)
        total *= V[i];

    return total;
}