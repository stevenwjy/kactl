/**
 * Author: From http://e-maxx.ru/algo/assignment_hungary
 * Description: So far we know that it is similiar to weighted matching except for N <= M
 * and we are more used to with this implementation.
 * Time: O(N^3)
 */
#pragma once

const int N = 1005;
int n, m, arr[N][N];
// N <= M, match item in N to M, get minimum
pair<int, vector<int>> hungarianAlgorithm() {
    vector<int> u (n + 1), v (m + 1), p (m + 1), way (m + 1);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv (m + 1, INF);
        vector<bool> used (m + 1, false);
        do {
            used[j0] = true;
            int i0 = p[j0],  delta = INF,  j1;
            for (int j = 1; j <= m; ++j)
                if (!used[j]) {
                    int cur = arr[i0][j] - u[i0] - v[j];
                    if (cur < minv[j])
                        minv[j] = cur, way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j], j1 = j;
                }
            for (int j=0; j<=m; ++j)
                if (used[j]) u[p[j]] += delta,  v[j] -= delta;
                else minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    vector<int> ans (n+1);
    for (int j=1; j<=m; ++j)
        ans[p[j]] = j;
    int cost = -v[0];
    return {cost, ans};
}