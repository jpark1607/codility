/* v2 : 100
 * searched : the result slice array only can be 2 or 3. */
int
solution(vector<int> &A)
{
    int size = A.size();
    int i;
    double min = ((double)A[0] + (double)A[1]) / 2;
    int idx = 0;
    double avg;


    for (i = 2; i < size; i++) {
        avg = ((double)A[i - 2] + (double)A[i - 1] + (double)A[i]) / 3;
        if (min > avg) {
            idx = i - 2;
            min = avg;
        }

        avg = ((double)A[i - 1] + (double)A[i]) / 2;
        if (min > avg) {
            idx = i - 1;
            min = avg;
        }
    }

    return idx;
}


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