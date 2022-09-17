#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define N 200001
using namespace std;
typedef long long ll;
int n, m, x, Q;
vector<int> p(N), bx(N), adj[N];
queue<int> q;

void BFS(int u)
{
    stack<int> st;
    queue<int> qu;
    qu.push(u);
    st.push(u);

    while (!qu.empty())
    {
        for (int i = 0; i < len(adj[qu.front()]); i++)
        {
            qu.push(adj[qu.front()][i]);
            st.push(adj[qu.front()][i]);
        }
        qu.pop();
    }

    while (!st.empty())
    {
        bx[st.top()]++;
        bx[p[st.top()]] += bx[st.top()];
        st.pop();
    }
}

bool comp(int x, int y)
{
    return bx[x] > bx[y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x == 0)
            q.push(i);
        else
            adj[x].pb(i);
        p[i] = x;
    }
    while (!q.empty())
    {
        BFS(q.front());
        q.pop();
    }

    cin >> Q;
    while (Q--)
    {
        cin >> m;
        vector<int> ar(m);
        vector<bool> vis(n + 1);
        for (int i = 0; i < m; i++)
            cin >> ar[i];
        sort(all(ar), comp);
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            if (!vis[p[ar[i]]])
                ans += bx[ar[i]];
            vis[ar[i]] = 1;
        }
        cout << ans << "\n";
    }
}