/* Lesson X.X Case #
 * 1. 문제:
 *   자연수 N이 있을 때, 2의 거듭제곱 중 N으로 나누어 떨어지는 자연수의 2의 지수 값을 구하여라.
 *
 * 2. 아이디어:
 *   반복작업 해보면 된다.
 *
 * 3. 코드:
 *   딱히 남길 comment가 없다.
 * */
int
solution(int N)
{
    int cnt = 0;

    while (N % 2 == 0) {
        N /= 2;
        cnt++;
    }

    return cnt;
}