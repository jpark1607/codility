/* Lesson 8.2
 * 1. 문제:
 *   어떤 vector A가 있을 때, index S 시점을 기준으로 (0) ~ (S)까지의 부분 vector와 (S+1) ~ (N)까지의 부분 vector의 leader가
 *   같은 경우의 수를 모두 찾아라.
 *
 * 2. 아이디어:
 *   두 부분에서 모두 과반이면, 전체에서도 과반이다.
 *   전체에서 과반이 아니면, 각각의 부분에서도 과반을 취하지 못한다.
 *
 * 3. 코드:
 *   [A] 일단 전체의 leader를 구한다.
 *     [A-1] 전체의 leader가 없다면 위 B에 의해 답은 0이다.
 *   [B] vector를 따라가면서 하나씩 체크해 본다.
 * */
int
solution(vector<int> &A)
{

    int size = A.size();
    int num, cnt = 0, total = 0;
    int equi_pos = 0;
    int i;

    if (size == 1)
        return 0;

    /* [A] */
    for (i = 0; i < size; i++) {
        if (cnt == 0) {
            num = A[i];
            cnt++;
        }
        else {
            if (A[i] != num)
                cnt--;
            else
                cnt++;
        }
    }

    for (i = 0; i < size; i++) {
        if (A[i] == num)
            total++;
    }

    /* [A-1] */
    if (total <= (size / 2))
        return 0;

    /* [B] */
    cnt = 0;
    for (i = 0; i < size; i++) {
        if (A[i] == num) {
            cnt++;
            total--;
        }

        if (total == 0)
            break;

        if (cnt > ((i + 1) / 2) && total > ((size - i - 1) / 2))
            equi_pos++;
    }

    return equi_pos;
}