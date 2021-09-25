#include <algorithm>

/* Exercise 3.1
 * 1. 문제:
 *   테니스 경기는 2명의 사람이 하나의 테니스 코트에서 진행한다.
 *   주어진 사람 수 P와 테니스 코트 수 C가 있을 때, 동시에 진행할 수 있는 테니스 경기의 수를 구하여라.
 *
 * 2. 아이디어:
 *   (사람 수 / 2)와 (테니스 코트 수), 둘 중 최소값
 *
 * 3. 코드:
 *   특별히 남길 comment가 없다.
 * */
int
solution(int P, int C)
{
    return min((int)(P / 2), C);
}