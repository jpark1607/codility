int
solution(int N)
{
    int max = 0, cnt = 0;

    /* find first 0x1 from bottom */
    while (N % 2 == 0) {
        N = N / 2;
    }

    /* if N == 1, there is no gap found */
    if (N == 1)
        return 0;

    /* find gap */
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