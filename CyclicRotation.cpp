/* Lesson 2.1
 * 1. 문제:
 *   어떤 vector A가 있을 때, K회 만큼 오른쪽으로 회전한 뒤의 결과를 vector로 return한다.
 *
 * 2. 아이디어:
 *   A.size()를 N이라고 할 때, K회 만큼 수행할 필요 없이 K를 N으로 나눈 나머지만큼만 회전하면 된다.
 *   하나씩 회전에서 앞에 넣는 것보다, (N - K)번째부터 순회하며 새로운 vector에 push하는 게 편하다.
 *
 * 3. 코드:
 *   [A] 새로운 vector에 넣을 index K를 구한다.
 *     [A-1] K에 (K % N)의 값을 넣는다.
 *     [A-2] (N - K)의 값으로 push할 index K를 구한다.
 *   [B] 새로운 index K부터 vector에 push한다.
 * */
vector<int>
solution(vector<int> &A, int K)
{
    vector<int> res;
    int N = A.size();

    /* empty or one element array : return itself */
    if (N == 0 || N == 1)
        return A;

    /* [A] */
    /* [A-1] */
    K = K % N;
    /* [A-2] */
    K = N - K;

    /* [B] */
    for (int i = K; i < K + N; i++)
        res.push_back(A[i % N]);

    return res;
}