int
solution(int X, vector<int> &A)
{
    int remain = X;
    int size = A.size();
    int i;
    bool *arr;

    if (X > size)
        return -1;

    arr = new bool[X] {false};

    for (i = 0; i < size; i++) {
        if (arr[A[i] - 1] == false) {
            arr[A[i] - 1] = true;
            remain--;
        }

        if (remain == 0)
            return i;

        if (remain > (size - i - 1))
            return -1;
    }

    return -1;
}