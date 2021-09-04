/* v2 : 87
 * performance for extreme_large */
vector<int>
solution(string &S, vector<int> &P, vector<int> &Q)
{
    int M = P.size();
    int i;
    vector<int> res;
    int n = -1;

    for (i = 0; i < M; i++) {
        if (S.find('A', P[i]) <= (unsigned int)Q[i])
            n = 1;
        else if (S.find('C', P[i]) <= (unsigned int)Q[i])
            n = 2;
        else if (S.find('G', P[i]) <= (unsigned int)Q[i])
            n = 3;
        else
            n = 4;

        res.push_back(n);
    }
    return res;
}

/* v1 : 62
 * performance problem */
vector<int>
solution(string &S, vector<int> &P, vector<int> &Q)
{
    int M = P.size();
    int i, j;
    char min;
    vector<int> res;

    for (i = 0; i < M; i++) {
        min = 'Z';
        for (j = P[i]; j <= Q[i]; j++) {
            if (min > S[j])
                min = S[j];

            if (min == 'A')
                break;
        }

        switch (min) {
        case 'A':
            res.push_back(1);
            break;
        case 'C':
            res.push_back(2);
            break;
        case 'G':
            res.push_back(3);
            break;
        case 'T':
            res.push_back(4);
            break;
        }
    }

    return res;
}