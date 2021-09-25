/* Lesson 5.1
 * 1. 문제:
 *   vector A가 있을 때, N번 좌표에 있는 차량이 달리는 방향은 A[N]의 값이 0일 경우 동쪽, 1일 경우 서쪽이다.
 *   모든 차량이 정해진 방향으로 나아간다고 할 때, 모든 차량의 교차 횟수를 구하여라.
 *
 * 2. 아이디어:
 *   vector에서 특정 index에 대하여 A[K]가 1일 때, 이 차량이 만나는 자동차의 수는 0 < i < K 에 있는 A[i]가 0인 개수이다.
 *   그러므로 앞에서부터 0의 카운트를 누적시키면서, 1을 만날 경우 그 카운트만큼 계속 더해주면 된다.
 *
 * 3. 코드:
 *   [A] vector를 순회한다.
 *     [A-1] 0을 만날 경우 count를 누적시킨다.
 *     [A-2] 1을 만날 경우 지금의 count만큼 총합에 더해준다.
 *   [B] 총합이 10억을 넘어가면 -1을 return한다.
 * */
#define MAX_CNT 1000000000

int
solution(vector<int> &A)
{
    int size = A.size();
    int cnt_zero = 0;
    int sum = 0;

    /* [A] */
    for (int i = 0; i < size; i++) {
        /* [A-1] */
        if (A[i] == 0)
            cnt_zero++;
        /* [A-2] */
        else
            sum += cnt_zero;

        /* [B] */
        if (sum > MAX_CNT)
            return -1;
    }

    return sum;
}