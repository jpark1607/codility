/* Lesson 15.2
 * 1. 문제:
 *   vector A가 있을 때, (P, Q)의 모든 독립(distinct) 집합을 구하여라. 단, 0 <= P <= Q < N이다.
 *
 * 2. 아이디어:
 *   계속해서 distinct한 value가 나온다고 가정할 때, (N - 1)까지의 배열에서 독립 집합의 수가 X개라면 여기에 N번째 배열을 추가할 경우
 *   독립 집합의 수는 (X + N)개이다.
 *   만약 중복값이 있는 배열이라면, N번째부터 뒤로 보면서 중복값이 없는 부분 집합까지의 개수를 확인한 후, 그 값을 더해주면 된다.
 *   예를 들어 (1, 2, 3, 4, 2, 6)에서, 변수 6의 시점에서 더해줘야 할 것은 변수 6부터 시작해서 역으로 2, 4, 3을 따라가다가 다시 2를 만난
 *   시점에 stop을 해 주고, 거기까지의 개수인 4를 더해주면 된다.
 *
 *   위 내용을 구현하기 위해서는
 *     1) 모든 변수 값을 포괄하는 배열을 하나 만들고
 *     2) vector A를 순회하며 나오는 변수 값을 위 배열의 위치에 넣은 뒤(vm[A[i]] = i)
 *     3) vm[A[i]]의 값이 존재하는 경우에는 pos(ition)_l의 위치를 해당 위치로 기록하고
 *     4) 더해 줄 값은 현재 위치인 i와 pos_l의 차를 더해주면 된다.
 *
 * 3. 코드:
 *   [A] vector를 순회하며
 *     [A-1] i번지의 값이 두 번 이상 나온 것인지 확인하고, 나온 적이 있으면 pos_l을 마지막 출현 index 값으로 설정해 준다.
 *     [A-2] i번지부터 pos_l번지까지는 중복이 없음이 증명되므로, i - pos_l 만큼 count에 더해준다.
 *     [A-3] 위치를 기록하는 배열에서, 해당 변수의 값에 대한 index 위치에 i를 넣어 준다.
 * */
#define MAX_VAL 1000000000

int
solution(int M, vector<int> &A)
{
    vector<int> vm(M + 1, -1);
    int size = A.size();
    int cnt = 0;
    int pos_l = -1;
    int i;

    /* [A] */
    for (i = 0; i < size; i++) {
        /* [A-1] */
        if (vm[A[i]] > pos_l)  // NOT (vm[A[pos_r]] > -1), CAUTION FOR (1, 2, 2, 1)
            pos_l = vm[A[i]];

        /* [A-2] */
        cnt += i - pos_l;
        if (cnt > MAX_VAL)
            return MAX_VAL;

        /* [A-3] */
        vm[A[pos_r]] = i;
    }

    return cnt;
}