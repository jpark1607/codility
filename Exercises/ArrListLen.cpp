/* Exercise 7.1
 * 1. 문제:
 *   vector A에서 index k에 대한 변수가 다음 index를 가리킨다고 했을 때, index 0부터 시작해서 -1을 만날 때까지의 개수를 구하여라.
 *
 * 2. 아이디어:
 *   -1 나올 때까지 while문 돌리면 된다.
 *
 * 3. 코드:
 *   특별히 남길 comment는 없다.
 * */
int
solution(vector<int> &A)
{
    int cnt = 1, pos = 0;

    while (A[pos] != -1) {
        pos = A[pos];
        cnt++;
    }

    return cnt;
}