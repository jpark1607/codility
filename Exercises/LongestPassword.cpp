/* Exercise 1.1
 * 1. 문제:
 *   주어진 String에서 공백(' ')을 기준으로 단어를 구분하여, password의 조건에 맞는 각 단어 중 가장 긴 것의 길이를 return하라.
 *   password의 조건은
 *     문자('A' ~ 'Z', 'a' ~ 'z')의 개수가 짝수여야 하고
 *     숫자('0' ~ '9')의 개수가 홀수여야 하며,
 *     이 외에 다른 문자가 들어가서는 안 된다.
 *
 * 2. 아이디어:
 *   string의 길이가 길지 않으니(최대 200) 그냥 일일이 비교해본다.
 *
 * 3. 코드:
 *   딱히 남길 comment가 없다.
 * */
int
solution(string &S)
{
    int size = S.size();
    int cnt, max = -1;
    int digits, letters;
    bool failed = false;
    int i;
    string::iterator it;

    for (i = 0; i < size; i++) {
        letters = 0;
        digits = 0;
        cnt = 0;
        failed = false;

        while (i < size && S[i] != ' ') {
            if (S[i] >= 'A' && S[i] <= 'Z')
                letters++;
            else if (S[i] >= 'a' && S[i] <= 'z')
                letters++;
            else if (S[i] >= '0' && S[i] <= '9')
                digits++;
            else {
                failed = true;
            }
            i++;
        }
        cnt = letters + digits;

        if ((letters % 2 == 0) && (digits % 2 == 1) && (!failed) && (cnt > max))
            max = cnt;
    }

    return max;
}