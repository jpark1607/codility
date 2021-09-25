/* Lesson 9.1
 * 1. 문제:
 *   어떤 vector A가 있을 때, A[Q] - A[P]의 최대값을 찾아라.
 *   0 <= P <= Q < N 이며, 이윤을 취할 수 없는 경우 0을 return 한다.
 *
 * 2. 아이디어:
 *   index K에 대해 1부터 (N - 1)까지, 각 상황에서 그 전 min value를 계산한다.
 *   그 전에 미리 계산된 min value와 (K - 1)번째와 비교해서 더 작은 값을 min value로 한다.
 *
 * 3. 코드:
 *   [A] 최초의 min value는 A[0]의 값으로 한다.
 *   [B] index i에 대해 1부터 (N - 1)까지 순회하며 가장 많은 이윤을 가지는 값을 찾는다.
 *     [B-1] min value와 A[i - 1] 값을 비교하여 더 작은 것을 골라 저장해 놓는다.
 *     [B-2] A[i]와 min value의 차를 계산하여, max profit 값과 비교하여 크다면 max profit 값으로 바꾼다.
 *   [C] max profit 값이 0보다 크다면 max profit를 return하고, 아니면 0을 return한다.
 * */
int
solution(vector<int> &A)
{
    int size = A.size();
    int min_val, max_prof;
    int i;

    if (size <= 1)
        return 0;

    /* [A] */
    min_val = A[0];
    max_prof = -200001;

    /* [B] */
    for (i = 1; i < size; i++) {
        /* [B-1] */
        if (min_val > A[i - 1])
            min_val = A[i - 1];

        /* [B-2] */
        if (max_prof < (A[i] - min_val))
            max_prof = A[i] - min_val;
    }

    /* [C] */
    return (max_prof > 0 ? max_prof : 0);
}