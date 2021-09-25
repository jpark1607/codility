/* Lesson 3.2
 * 1. 문제:
 *   vector A의 A.size()가 N일 때, 각 배열의 인자가 가지는 변수의 값은 1부터 (N + 1)까지이다.
 *   각 배열의 인자가 distinct한 값을 가진다고 할 때, 빠진 수 하나를 찾아라.
 *
 * 2. 아이디어:
 *   각 변수의 값이 있는지 체크할 수 있는 bool type array를 선언하면 된다.
 *   단, 아래 구현부에서는 bit array를 써 본다. (C언어에서 주로 쓰는 기법)
 *
 * 3. 코드:
 *   [A] N의 모든 값을 포함하는 bit array를 생성(8로 나누고 1을 더한다)한다. char type으로 선언하고 하나의 index당 8개의 변수를 사용한다.
 *   [B] 필요한 bit를 켜 준다.
 *     [B-1] 배열의 인자 변수 값에 맞는 bit를 켜 준다.
 *     [B-2] bit array는 8의 배수로 생성된 것이기 때문에 뒤에 dummy가 존재한다. 이 부분의 bit들도 켜 준다.
 *   [C] bit array를 돌면서 0xff가 아닌 것을 찾는다. (0xff는 해당 배열 인자의 bit가 다 켜진 것이다)
 *     [C-1] 0xff가 아닌 것이 나오면, 어떤 bit가 0인지 찾아서 변수로 역 계산한다.
 * */
int
solution(vector<int> &A)
{
    int N;
    char *arr;
    int arr_cnt;
    int pos1, pos2, dummy;
    int res = -1;

    N = A.size();
    /* exception */
    if (N == 0)
        return 1;

    /* [A] */
    arr_cnt = (N / 8) + 1;
    arr = new char[arr_cnt] {0};

    /* [B] */
    /* [B-1] */
    for (int i = 0; i < N; i++) {
        pos1 = (A[i] - 1) / 8;
        pos2 = (A[i] - 1) - (pos1 * 8);
        arr[pos1] |= (1 << pos2);
    }

    /* [B-2] */
    dummy = (arr_cnt * 8) - (N + 1);
    for (int i = 7; i > (7 - dummy); i--) {
        arr[arr_cnt - 1] |= 1 << i;
    }

    /* [C] */
    for (int i = 0; i < arr_cnt; i++) {
        if ((arr[i] & 0xff) != 0xff) {
            res = i * 8;
            /* [C-1] */
            for (int j = 0; j < 8; j++) {
                if ((arr[i] & (1 << j)) == 0)
                    res += j;
            }
            break;
        }
    }

    delete arr;
    return (res + 1);
}