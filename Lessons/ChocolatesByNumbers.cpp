/* Lesson 12.1
 * 1. 문제:
 *   N개의 초콜릿이 있을 때, 0번지부터 시작해서 M개씩 넘어가면서 먹는다고 할 때 먹을 수 있는 개수를 구하여라.
 *
 * 2. 아이디어:
 *   문제는 어려운데 그냥 N과 M의 최대공약수를 구하고, N에서 나누면 된다.
 *   아래는 각 함수의 예제이다. (N > M)
 *     GCD(N, M) = GCD(M, (N % M))
 *     LCM(N, M) = (N * M) / GCD(N, M)
 *
 * 3. 코드: 여기는 코드 볼 게 없다.
 * */
int gcd(int x, int y)
{
    if (x % y == 0)
        return y;
    else
        return gcd(y, (x % y));
}

int
solution(int N, int M)
{
    return N / (gcd(N, M));
}

