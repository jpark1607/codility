#include <cstdlib>
#ifndef _WIN32
#include <bits/stdc++.h>
#else
#include <limits>
#endif /* _WIN32, for INT_MAX */

/* Lesson 13.1
 * 1. 문제:
 *   vector A의 index i는 좌표를 의미하며, A[i]의 값은 나뭇잎이 있는지 여부를 표기한다.
 *   피보나치 수 만큼만 점프할 수 있는 개구리가 있을 때, -1부터 시작해서 N(A의 size)까지 나뭇잎만 밟고 도착할 수 있는 최소 점프의 수를 구하여라.
 *
 * 2. 아이디어:
 *   일단 피보나치 수를 하나의 배열로 만들고, 각 좌표마다 최소 점프가 가능한 숫자를 담는 배열도 만든다.
 *   피보나치의 큰 수부터 따라가면서 점프를 하되, 특정 좌표까지 최소 점프로 왔을 때에만 그 뒤를 진행하도록 한다.
 *
 * 3. 코드:
 *   [A] 필요한 피보나치 수 까지만 계산하여 배열을 만든다.
 *   [B] 계산한 배열을 큰 수부터 따라간다. 현재 위치에서 특정 피보나치 수를 더했을 때...
 *     [B-1] 목적지 N보다 넘어가면 지나간다.
 *     [B-2] 목적지 N까지 최소 점프로 도달했을 경우 그 값을 갱신한다.
 *     [B-3] 나뭇잎이 있는 위치라면 그 위치까지 최소 점프로 도달했을 경우 값을 갱신하고, 해당 위치에서부터 다음 점프 거리를 계산한다.
 * */
void
find_next(vector<int> &F, vector<int> &A, vector<int> &M, int cnt, int pos)
{
    int size = A.size();
    int new_pos;

    cnt++;

    /* [B] */
    for (int i = F.size() - 1; i >= 2; i--) {
        new_pos = pos + F[i];
        /* [B-1] */
        if (new_pos > size)
            continue;
        /* [B-2] */
        else if (new_pos == size) {
            if (M[new_pos] > cnt)
                M[new_pos] = cnt;
        }
        /* [B-3] */
        else if (A[new_pos] == 1) {
            if (M[new_pos] > cnt) {
                M[new_pos] = cnt;
                find_next(F, A, M, cnt, new_pos);
            }
        }
    }
}

int
solution(vector<int> &A)
{
    int size = A.size() + 1;
    vector<int> Fibo;
    vector<int> Min(size, INT_MAX);
    int cnt = 2;

    Fibo.push_back(0);
    Fibo.push_back(1);

    /* [A] */
    while (1) {
        Fibo.push_back(Fibo[cnt - 2] + Fibo[cnt - 1]);
        if (Fibo[cnt] > size) {
            Fibo.pop_back();
            break;
        }
        cnt++;
    }

    cnt = 0;
    find_next(Fibo, A, Min, cnt, -1);

    if (Min[size - 1] == INT_MAX)
        return -1;
    return Min[size - 1];
}