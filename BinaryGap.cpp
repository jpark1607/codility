int
solution(int N)
{
    int max = 0, cnt = 0;

    while (N % 2 == 0) {
        N = N / 2;
    }

    if (N == 1)
        return 0;

    while (N > 0) {
        if (N % 2 == 0) {
            cnt++;
        }
        else {
            if (cnt > max)
                max = cnt;
            cnt = 0;
        }
        N = N / 2;
    }

    return max;
}