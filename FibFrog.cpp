/* v1 : 58
 * wrong answers */
int
find_next(vector<int> &F, vector<int> &A, int pos)
{
    int found = -1;
    int size = A.size();

    if (pos == size)
        return 1;
    else if (pos > size)
        return -1;

    for (int i = F.size() - 1; i >= 2; i--) {
        if (pos + F[i] == size)
            return 1;
        else if (pos + F[i] > size)
            continue;
        else if (A[pos + F[i]] == 1) {
            found = find_next(F, A, pos + F[i]);
            if (found >= 1)
                return (found + 1);
        }
    }

    return -1;
}

int
solution(vector<int> &A)
{
    int size = A.size();
    vector<int> Fibo;
    int cnt = 2;

    /*
     *    0     1     1     2     3     5     8    13    21    34
     *   55    89   144   233   377   610   987  1597  2584  4181
     * 6765 10946 17711 28657 46368 75025
     * */
    Fibo.push_back(0);
    Fibo.push_back(1);

    while (1) {
        Fibo.push_back(Fibo[cnt - 2] + Fibo[cnt - 1]);
        if (Fibo[cnt] > size + 1) {
            Fibo.pop_back();
            break;
        }
        cnt++;
    }

    return find_next(Fibo, A, -1);
}

