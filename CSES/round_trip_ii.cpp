#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100001
vector<int> g[N];
vector<bool> v(N), w(N);
vector<int> p;

void DFS(int u)
{

    v[u] = 1;
    p.push_back(u);
    for (int i : g[u])
    {
        if (w[i])
            continue;
        if (v[i])
        {
            int c = 1;
            reverse(p.begin(), p.end());
            for (int i : p)
            {
                c++;
                if (i == u)
                    break;
            }
            cout << c << "\n";
            cout << u << " ";
            for (int i : p)
            {
                cout << i << " ";
                if (i == u)
                    break;
            }
            exit(0);
        }

        else
            DFS(i);
    }
    w[u] = 1;
    p.pop_back();
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
        if (!v[i])
            p.clear(), DFS(i);
    cout << "IMPOSSIBLE\n";
}