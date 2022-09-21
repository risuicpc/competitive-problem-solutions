#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 10001
vector<int> g(N), v(N), e(N);
queue<int> q;
int n, an = 0, cy = 1;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> g[i], e[g[i]]++;

    int u = 1;
    vector<int> lf;
    while (!v[u])
        v[u] = 1, u = g[u];

    for (int i = 1; i <= n; i++)
    {
        an += !e[i];
        if (!v[i])
            q.push(i);
    }
    lf.push_back(an);
    an = 0;

    while (!q.empty())
    {
        if (!v[q.front()])
        {
            u = q.front();
            vector<bool> t(n + 1, 0);
            while (!v[u] && !t[u])
                t[u] = 1, u = g[u];

            if (!v[u])
                cy++;
            for (int i = 1; i <= n; i++)
            {
                v[i] = v[i] || t[i];
                if (!v[u] && t[i])
                    an += !e[i];
            }
            if (an > 0)
                lf.push_back(an);
            an = 0;
        }
        q.pop();
    }
    for (int i = 1; i < lf.size(); i++)
        lf[0] -= lf[i];
    for (int i : lf)
        an += (cy == 1 ? i : i - 1);
    cy--;
    cout << an + 2 * cy << "\n";
}