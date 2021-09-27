/* Lesson 13.2
 * 1. 문제:
 *   vector A의 각 인자는 사다리에서 다리의 수를 나타내고, 사다리를 오를 때 한 번에 한 칸 혹은 두 칸만 오를 수 있다.
 *   올라가는 방법의 경우에 수를 vector B의 인자로 나눈 나머지 값을 구하여라.
 *
 * 2. 아이디어:
 *   피보나치 수 계산을 위한 recursive 구현과, 중간 결과를 저장해 놓는 memoization이 필요하다.
 *
 * 3. 코드:
 *   특별히 남길 comment가 없다.
 * */
int
make_fibo(int num, vector<int> &F)
{
    if (F[num] == 0)
        F[num] = (make_fibo(num - 1, F) + make_fibo(num - 2, F)) % 1073741824;

    return F[num];
}

vector<int>
solution(vector<int> &A, vector<int> &B)
{
    int size = A.size();
    vector<int> result;
    vector<int> fibo(50001, 0);
    vector<int> indices(31, 0);
    int i;

    indices[0] = 1;
    for (i = 1; i < 31; i++) {
        indices[i] = 2 * indices[i - 1];
    }


    fibo[1] = 1;
    fibo[2] = 2;
    for (i = 0; i < size; i++) {
        result.push_back(make_fibo(A[i], fibo) % indices[B[i]]);
    }

    return result;
}