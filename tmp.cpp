
inline bool cmp(const int &i, const int &j) {
    return dfn[i] < dfn[j];
}

void build(int vectrices[], int k) {
    static int stk[MAX_N];
    sort(vectrices, vectrices + k, cmp);

    stk[sz++] = 0;
    for (int i = 0; i < k; ++i) {
        int u = vectrices[i], lca = ::lca(u, stk[sz - 1]);
        if (lca == stk[sz - 1]) stk[sz++] = u;
        else {
            while (sz - 2 >= 0 && dep[stk[sz - 2]] >= dep[lca]) {
                addEdge(stk[sz - 2], stk[sz - 1]);
                sz--;
            }

            if (stk[sz - 1] != lca) {
                addEdge(lca, stk[--sz]);
                stk[sz++] = lca, vectrices[cnt++] = lca;
            }

            stk[sz++] = u;
        }
    }
    for (int i = 0; i < sz - 1; ++i) addEdge(stk[i], stk[i + 1]);
