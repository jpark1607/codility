/* v2 : 100 */
#include <cstdlib>
#ifndef _WIN32
#include <bits/stdc++.h>
#else
#include <limits>
#endif /* _WIN32, for INT_MIN */

int
solution(vector<int> &A)
{
    int size = A.size();
    int cnt = 0;
    int last_val = -1;
    bool finished = false;
    int i, j;

    i = 0;
    j = size - 1;

    /* 1 or 2 units */
    if (size <= 2)
        return (A[i] == A[j] ? 1 : 2);

    /* if INT_MIN, abs() will not return properly */
    while (A[i] == INT_MIN)
        i++;
    if (i > 0)
        cnt++;

    while (1) {
        while ((abs(A[i]) > abs(A[j])) && !finished) {
            if (last_val != abs(A[i])) {
                last_val = abs(A[i]);
                cnt++;
            }

            i++;
            if (i > j)
                finished = true;
        }
        while ((abs(A[i]) < abs(A[j])) && !finished) {
            if (last_val != abs(A[j])) {
                last_val = abs(A[j]);
                cnt++;
            }

            j--;
            if (i > j)
                finished = true;
        }
        while ((abs(A[i]) == abs(A[j])) && !finished) {
            if (last_val != abs(A[i])) {
                last_val = abs(A[i]);
                cnt++;
            }

            i++;
            j--;
            if (i > j)
                finished = true;
        }

        if (finished)
            break;
    }

    return cnt;
}


/* v1 : 57
 * wrong answer */
#include <cstdlib>
#ifndef _WIN32
#include <bits/stdc++.h>
#else
#include <limits>
#endif /* _WIN32, for INT_MIN */

int
solution(vector<int> &A)
{
    int size = A.size();
    int cnt = 0;
    int i = 0, j = size - 1;
    int last_val = INT_MIN;

    if (size == 1)
        return 1;

    if (A[i] == INT_MIN) {
        cnt++;
        i++;
    }

    /* first initialize for last_val */
    if (abs(A[i]) > abs(A[j])) {
        last_val = abs(A[j]);
        cnt++;
        i++;
    }
    else if (abs(A[i]) < abs(A[j])) {
        last_val = abs(A[j]);
        cnt++;
        j--;
    }
    else {
        last_val = abs(A[j]);
        cnt++;
        i++;
        j--;
    }

    while (i <= j) {
        if ((A[i] == 0) || (A[j] == 0)) { // shortcut
            cnt += j - i + 1;
            break;
        }

        while (abs(A[i]) > abs(A[j]) && i <= j) {
            if (abs(A[i]) != last_val) {
                last_val = abs(A[i]);
                cnt++;
            }
            i++;
        }

        while (abs(A[i]) < abs(A[j]) && i <= j) {
            if (abs(A[j]) != last_val) {
                last_val = abs(A[j]);
                cnt++;
            }
            j--;
        }

        while (abs(A[i]) == abs(A[j]) && i <= j) {
            if (abs(A[i]) != last_val) {
                last_val = abs(A[i]);
                cnt++;
            }
            i++;
            j--;
        }
    }

    return cnt;
}