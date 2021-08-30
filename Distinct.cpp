int
solution(vector<int> &A)
{
    int size = A.size();
    bool *arr;
    int cnt = 0;

    if (size < 2)
        return size;

    arr = new bool[2000001] {false};

    for (int i = 0; i < size; i++) {
        if (arr[A[i] + 1000000] == false) {
            arr[A[i] + 1000000] = true;
            cnt++;
        }
    }

    return cnt;
}