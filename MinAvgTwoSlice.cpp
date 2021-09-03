/* v1 : 60
 * performance problem */
int
solution(vector<int> &A)
{
    int size = A.size();
    int i, j;
    double min = 10001;
    int first_pos = -1;
    double res = -1;
    double elem_cnt;

    for (i = 0; i < size - 1; i++) {
        res = (double)A[i];
        elem_cnt = 1;
        for (j = i + 1; j < size; j++) {
            res += (double)A[j];
            elem_cnt++;
            if (min > (res / elem_cnt)) {
                min = res / elem_cnt;
                first_pos = i;
            }
        }
    }

    return first_pos;
}