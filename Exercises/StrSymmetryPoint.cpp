/* Exercise 4.2
 * 1. 문제:
 *   string S가 있을 때 특정 index를 기점으로 왼쪽과 오른쪽이 대칭이면 그 index i를 return하라.
 *   대칭이 아닌 경우 -1을 return한다.
 *
 * 2. 아이디어:
 *   특정 index를 기준으로 양쪽이 같으므로 S의 size는 홀수여야 한다.
 *   중간 index를 시작으로 양쪽으로 뻗어 가면서 비교해 본다.
 *
 * 3. 코드:
 *   특별히 남길 comment는 없다.
 * */
int
solution(string &S)
{
    int size = S.size();
    int l, r;

    if (size % 2 == 0)
        return -1;
    else if (size == 1)
        return 0;

    for (l = (size / 2) - 1, r = (size / 2) + 1; l >= 0 && r < size; l--, r++) {
        if (S[l] != S[r])
            return -1;
    }

    return (size / 2);
}