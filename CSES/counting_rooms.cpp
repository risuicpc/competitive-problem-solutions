#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define se second
#define N 1000
using namespace std;
typedef long long ll;
int a[N][N];
bool visit[N][N];
queue<pair<int, int>> q1, q2;
vector<string> v;
int n, m, an = 0;

void f(int i, int j, int d)
{
    if (i < 0 || j < 0 || i == n || j == m || visit[i][j] || v[i][j] == '#')
        return;
    visit[i][j] = 1;
    a[i][j] = d;
    q2.push({i, j});
}

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    rep(i, n)
    {
        string s;
        cin >> s;
        v.pb(s);
        rep(j, m) if (s[j] == '.') q1.push({i, j});
    }
    while (!q1.empty())
    {
        auto fr = q1.front();
        q1.pop();
        if (!visit[fr.fi][fr.se])
        {
            visit[fr.fi][fr.se] = 1;
            a[fr.fi][fr.se] = ++an;
            q2.push(fr);
            while (!q2.empty())
            {
                auto ff = q2.front();
                q2.pop();
                f(ff.fi - 1, ff.se, a[fr.fi][fr.se]);
                f(ff.fi + 1, ff.se, a[fr.fi][fr.se]);
                f(ff.fi, ff.se - 1, a[fr.fi][fr.se]);
                f(ff.fi, ff.se + 1, a[fr.fi][fr.se]);
            }
        }
    }

    cout << an << "\n";
}