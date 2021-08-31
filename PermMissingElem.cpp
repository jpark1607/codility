int
solution(vector<int> &A)
{
    int N;
    char *arr;
    int arr_cnt;
    int pos1, pos2, dummy;
    int res = -1;

    N = A.size();
    /* exception */
    if (N == 0)
        return 1;

    arr_cnt = (N / 8) + 1;
    arr = new char[arr_cnt] {0};

    /* fill 0x1 into current number pos */
    for (int i = 0; i < N; i++) {
        pos1 = (A[i] - 1) / 8;
        pos2 = (A[i] - 1) - (pos1 * 8);
        arr[pos1] |= (1 << pos2);
    }

    /* fill 0x1 into dummy pos */
    dummy = (arr_cnt * 8) - (N + 1);
    for (int i = 7; i > (7 - dummy); i--) {
        arr[arr_cnt - 1] |= 1 << i;
    }

    /* find bit array block by bitand 0xff */
    for (int i = 0; i < arr_cnt; i++) {
        if ((arr[i] & 0xff) != 0xff) {
            res = i * 8;
            /* find nth bit from one block */
            for (int j = 0; j < 8; j++) {
                if ((arr[i] & (1 << j)) == 0)
                    res += j;
            }
            break;
        }
    }

    delete arr;
    return (res + 1);
}