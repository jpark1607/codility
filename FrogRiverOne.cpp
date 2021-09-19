/*
 * 1. 문제:
 *   vector A의 index가 초(second), 값이 활성화된 나뭇잎의 위치라고 할 때, 좌표 1에서 X까지 한 번에 건널 수 있는 최소 시간을 구하여라.
 *   (즉, 1부터 X까지 모든 값이 vector에 하나라도 나온 가장 작은 index의 값)
 *
 * 2. 아이디어:
 *   활성화된 변수 값을 기억하기 위해 bool type의 array를 하나 만들고, 몇 개의 값이 더 활성화되어야 하는지 확인하기 위한 변수 r을 둔다.
 *   비활성화된 변수 값 K를 활성화하는 경우 arr[A[K] - 1]을 true로 켜 주고 r에서도 1을 빼 준다.
 *   r이 0이 되는 순간이 최소 시점이다.
 *
 * 3. 코드:
 *   [A] 활성화된 변수를 기억할 bool type array를 할당한다.
 *   [B] 아래 내용을 반복한다.
 *     [B-1] 처음 보는 변수 값일 경우 해당 변수 값의 위치를 true로 활성화하고 r에서 1을 빼 준다.
 *     [B-2] r이 0이 되었으면 그 index를 return한다.
 *     [B-3] 만약 남은 r의 수보다 앞으로 더 탐색할 index의 수가 작다면 바로 -1을 return한다(예외처리 최적화).
 * */
int
solution(int X, vector<int> &A)
{
    int r = X;
    int size = A.size();
    int i;
    bool *arr;

    if (X > size)
        return -1;

    /* [A] */
    arr = new bool[X] {false};

    /* [B] */
    for (i = 0; i < size; i++) {
        /* [B-1] */
        if (arr[A[i] - 1] == false) {
            arr[A[i] - 1] = true;
            r--;
        }

        /* [B-2] */
        if (r == 0)
            return i;

        /* [B-3] */
        if (r > (size - i - 1))
            return -1;
    }

    return -1;
}