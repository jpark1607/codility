#define MAX_VAL 1000000000

int
solution(int M, vector<int> &A)
{
    vector<int> vm(M + 1, -1);
    int size = A.size();
    int cnt = 0;
    int pos_l = -1, pos_r;

    for (pos_r = 0; pos_r < size; pos_r++) {
        if (vm[A[pos_r]] > pos_l)  // NOT (vm[A[pos_r]] > -1), CAUTION FOR (1, 2, 2, 1)
            pos_l = vm[A[pos_r]];

        cnt += pos_r - pos_l;
        if (cnt > MAX_VAL)
            return MAX_VAL;

        vm[A[pos_r]] = pos_r;
    }

    return cnt;
}