// v2 : 100
vector<int>
solution(int N, vector<int> &A)
{
    vector<int> v(N, 0);
    int size = A.size();
    int max = 0;
    int gap = 0;
    int i;

    for (i = 0; i < size; i++) {
        if (A[i] <= N) {
            if (v[A[i] - 1] < gap)
                v[A[i] - 1] = gap;

            v[A[i] - 1] += 1;

            if (v[A[i] - 1] > max)
                max = v[A[i] - 1];
        }
        else {
            gap = max;
        }
    }

    for (i = 0; i < N; i++) {
        if (v[i] < gap)
            v[i] = gap;
    }

    return v;
}

/* v1 : 77
 * performance problem */
vector<int>
solution(int N, vector<int> &A)
{
    vector<int> v(N, 0);
    int size = A.size();
    int max = 0;
    int i, j;

    for (i = 0; i < size; i++) {
        if (A[i] <= N) {
            v[A[i] - 1] += 1;
            if (max < v[A[i] - 1])
                max = v[A[i] - 1];
        }
        else {
            for (j = 0; j < N; j++) {
                v[j] = max;
            }
        }
    }

    return v;
}