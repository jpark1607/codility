#include <algorithm>
#include <utility>

int
solution(vector<int> &A)
{
    vector<pair<long, long> > R;
    vector<pair<long, long> >::iterator it1, it2;
    int size = A.size();
    int i;
    int n = 0;

    for (i = 0; i < size; i++)
        R.push_back(pair<long, long>((long)i - (long)A[i], (long)i + (long)A[i]));

    sort(R.begin(), R.end());

    for (it1 = R.begin(); it1 != R.end(); it1++) {
        for (it2 = it1 + 1; it2 != R.end(); it2++) {
            if (it2->first > it1->second)
                break;

            n++;
        }
    }

    return n > 10000000 ? -1 : n;