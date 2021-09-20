/* Lesson 6.1
 * 1. 문제:
 *   distinct value의 수를 구하여라.
 *
 * 2. 아이디어:
 *   bool type array 만들어서 distinct한 게 나오면 true로 바꿔주고, count를 올려준다.
 *   이미 true인 상태면 지나간다.
 *
 * 3. 코드:
 *   [A] value의 distinct를 체크할 bool type array를 만든다.
 *   [B] 특정 value에 해당하는 bool 값이 false이면, true로 바꿔주면서 count를 올려준다.
 * */
int
solution(vector<int> &A)
{
    int size = A.size();
    bool *arr;
    int cnt = 0;

    if (size < 2)
        return size;

    /* [A] */
    arr = new bool[2000001] {false};

    for (int i = 0; i < size; i++) {
        /* [B] */
        if (arr[A[i] + 1000000] == false) {
            arr[A[i] + 1000000] = true;
            cnt++;
        }
    }

    return cnt;
}