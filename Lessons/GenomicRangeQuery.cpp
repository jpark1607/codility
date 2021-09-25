/* v3 : 100
 * searched : make arrays for each letter, cumulative values */
vector<int>
solution(string &S, vector<int> &P, vector<int> &Q)
{
    int M = P.size();
    vector<int> res;
    vector<int> aA, aC, aG;
    int A = 0, C = 0, G = 0;
    int size = S.size();
    int i;

    aA.push_back(0);
    aC.push_back(0);
    aG.push_back(0);

    for (i = 0; i < size; i++) {
        switch (S[i]) {
        case 'A':
            A++;
            break;
        case 'C':
            C++;
            break;
        case 'G':
            G++;
            break;
        }
        aA.push_back(A);
        aC.push_back(C);
        aG.push_back(G);
    }

    for (i = 0; i < M; i++) {
        if (P[i] == Q[i]) {
            switch (S[P[i]]) {
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
        else if (aA[Q[i] + 1] - aA[P[i]] != 0)
            res.push_back(1);
        else if (aC[Q[i] + 1] - aC[P[i]] != 0)
            res.push_back(2);
        else if (aG[Q[i] + 1] - aG[P[i]] != 0)
            res.push_back(3);
        else
            res.push_back(4);
    }

    return res;
}


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