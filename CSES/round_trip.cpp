#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define N 100001
using namespace std;
typedef long long ll;
vector<vector<int>> adj(N);
vector<bool> vis(N);
vector<int> an(N), ans;
queue<int> q1;
stack<int> st;
int n, m, a, b;

void in(int i, int x)
{
    if (i != x)
    {
        in(an[i], x);
        ans.pb(i);
    }
}

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    rep(i, m)
    {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    rep(i, n) q1.push(i + 1);
    while (!q1.empty())
    {
        a = q1.front();
        q1.pop();
        if (!vis[a])
        {
            st.push(a);
            while (!st.empty())
            {
                auto t = st.top();
                st.pop();
                rep(j, len(adj[t]))
                {
                    if (an[adj[t][j]] != 0 && adj[t][j] != an[t])
                    {
                        in(t, an[adj[t][j]]);
                        cout << len(ans) + 3 << "\n";
                        cout << an[adj[t][j]] << " ";
                        for (int x : ans)
                            cout << x << " ";
                        cout << adj[t][j] << " " << an[adj[t][j]];
                        return 0;
                    }
                    else if (!vis[adj[t][j]])
                    {
                        st.push(adj[t][j]);
                        an[adj[t][j]] = t;
                    }
                }
                vis[t] = 1;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}