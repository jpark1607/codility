/* Challenge "Alpha 2010" */
int
solution(vector<int> &A)
{
    int size = A.size();
    vector<int> B(size + 1, 0);
    int i;

    for (i = 0; i < size; i++) {
        B[A[i]]++;
    }

    for (i = size - 1; i >= 0; i--) {
        if (B[A[i]] == 1)
            return i;
        B[A[i]]--;
    }

    return 0;
}