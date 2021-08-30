#define MAX_CNT 1000000000

int
solution(vector<int> &A)
{
    int size = A.size();
    int cnt_zero = 0;
    int sum = 0;

    for (int i = 0; i < size; i++) {
        if (A[i] == 0)
            cnt_zero++;
        else
            sum += cnt_zero;

        if (sum > MAX_CNT)
            return -1;
    }

    return sum;
}