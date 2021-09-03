/* v1 : 62
 * performance problem */
vector<int>
solution(string &S, vector<int> &P, vector<int> &Q)
{
    int M = P.size();
    int i, j;
    int min;
    vector<int> res;

    for (i = 0; i < M; i++) {
        min = 5;
        for (j = P[i]; j <= Q[i]; j++) {
            switch (S[j]) {
                case 'A':
                    min = (min > 1) ? 1 : min;
                    break;
                case 'C':
                    min = (min > 2) ? 2 : min;
                    break;
                case 'G':
                    min = (min > 3) ? 3 : min;
                    break;
                case 'T':
                    min = (min > 4) ? 4 : min;
                    break;
            }
        }
        res.push_back(min);
    }

    return res;
}