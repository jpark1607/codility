/*
 * 두 부분에서 모두 과반이면, 전체에서도 과반이다.
 * 전체에서 과반이 아니면, 각각의 부분에서도 과반을 취하지 못한다.
 *
 * [1] 일단 전체의 leader를 구한다.
 * [2] 전체의 leader가 없다면 위 B에 의해 답은 0이다.
 * [3] vector를 따라가면서 하나씩 체크해 본다.
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

    /* [1] */
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

    /* [2] */
    if (total <= (size / 2))
        return 0;

    /* [3] */
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