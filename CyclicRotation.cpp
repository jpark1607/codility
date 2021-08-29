vector<int>
solution(vector<int> &A, int K)
{
    vector<int> res;
    int N = A.size();

    /* empty or one element array : return itself */
    if (N == 0 || N == 1)
        return A;

    K = K % N;
    K = N - K;

    for (int i = K; i < K + N; i++)
        res.push_back(A[i % N]);

    return res;
}