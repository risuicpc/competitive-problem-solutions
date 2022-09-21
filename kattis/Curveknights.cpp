#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    vector<int> a(n), b(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<int, int>> g[n];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g[v].push_back({u, w});
        b[u]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (b[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        for (int j = 0; j < g[i].size(); j++)
        {
            if (a[g[i][j].first] == 0)
                a[g[i][j].first] += a[i] * g[i][j].second;
            else
                a[i] += ceil(a[g[i][j].first] / (float)g[i][j].second);
            b[g[i][j].first]--;
            if (!b[g[i][j].first])
                q.push(g[i][j].first);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << " ";
        cout << a[i];
    }
}