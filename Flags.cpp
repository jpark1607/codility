/* v2 : 33
 *  */
int
solution(vector<int> &A)
{
    int size = A.size();
    int i, j;
    int K, flags = -1, max = -1;
    int last_pos;
    vector<int> peak;

    for (i = 1; i < size - 1; i++) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            peak.push_back(i);
            i++;
        }
    }

    K = peak.size();
    if (K <= 2)
        return K;

    for (i = K; (i >= 2) && (max < i); i--) {
        flags = i;
        last_pos = peak[0];

        for (j = 1; j < K; j++) {
            if (peak[j] - last_pos < i)
                flags--;
            else
                last_pos = peak[j];

            if (max > flags)
                continue;
        }

        if (max < flags)
            max = flags;
    }

    return max;
}

/* v1 : 26
 * performance problem */
int
solution(vector<int> &A)
{
    int size = A.size();
    int i;
    int K, k;
    int max = 0;
    vector<pair<int, int> > peak;
    vector<pair<int, int> >::iterator it1, it2;

    for (i = 1; i < size - 1; i++) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            peak.push_back(pair<int, int> (i, A[i]));
            i++;
        }
    }

    K = peak.size();

    if (K == 0 || K == 1 || K == 2)
        return K;

    for (i = K; i >= 2; i--) {
        k = i;
        it1 = peak.begin();
        it2 = it1++;

        for ( ; it2 != peak.end(); it1++, it2++) {
            if (it1->second + i >= it2->second)
                k--;
            if (max < k)
                max = k;
        }
    }

    return max;
}