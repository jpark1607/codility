#include <utility>
#include <vector>
#include <algorithm>

#define INT_MAX 100000
int
solution(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int size = A.size(), csize = C.size();
    vector<pair<int, int> > planks;
    vector<int> nails(csize * 2 + 1, INT_MAX);
    int l = INT_MAX, r = INT_MAX;
    int partial_min = INT_MAX, partial_cnt = 0;
    int total_max = 0, total_cnt = 0;
    bool found;
    int i, j;

    /* preprocess 1 */
    for (i = 0; i < size; i++) {
        planks.push_back(make_pair(A[i], B[i]));
    }
    sort(planks.begin(), planks.end());

    /* preprocess 2 */
    for (i = 0; i < csize; i++) {
        nails[C[i]] = i;
    }

    for (i = size - 1; i >= 0; i--) {
        partial_cnt = 1;
        partial_min = INT_MAX;

        if (i != 0) {
            if (planks[i].first == planks[i - 1].first) {
                partial_cnt++;
                continue;
            }
            else if (found && planks[i].second >= r) {
                total_cnt++;
                continue;
            }
        }

        l = planks[i].first;
        r = planks[i].second;
        found = false;

        for (j = l; j <= r; j++) {
            if (nails[j] != INT_MAX) {
                found = true;
                partial_min = min(nails[j], partial_min);
            }
        }

        if (found) {
            total_cnt += partial_cnt;
            total_max = max(partial_min, total_max);
        }
    }
    if (total_cnt == size)
        return total_max + 1;
    else
        return -1;
}