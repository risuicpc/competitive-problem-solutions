#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define se second
#define N 1000
using namespace std;
typedef long long ll;
queue<pair<int, int>> qp;
bool visit[N][N];
vector<string> v;
pair<int, int> a, b;
int n, m;

void f(int i, int j, char ch)
{
    if (i < 0 || j < 0 || i == n || j == m || visit[i][j] || v[i][j] == '#')
        return;
    qp.push({i, j});
    visit[i][j] = 1;
    v[i][j] = ch;
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
        rep(j, m) if (s[j] == 'A') a = {i, j};
        else if (s[j] == 'B') b = {i, j};
    }
    qp.push({a.fi, a.se});
    visit[a.fi][a.se] = 1;
    while (!qp.empty())
    {
        auto fr = qp.front();
        qp.pop();
        if (fr.fi == b.fi && fr.se == b.se)
        {
            cout << "YES\n";
            int i = fr.fi, j = fr.se;
            string str = "";
            while (v[i][j] != 'A')
            {
                str += v[i][j];
                if (v[i][j] == 'U')
                    i++;
                else if (v[i][j] == 'R')
                    j--;
                else if (v[i][j] == 'D')
                    i--;
                else
                    j++;
            }
            cout << str.size() << "\n";
            reverse(str.begin(), str.end());
            cout << str << "\n";
            return 0;
        }
        f(fr.fi - 1, fr.se, 'U');
        f(fr.fi + 1, fr.se, 'D');
        f(fr.fi, fr.se - 1, 'L');
        f(fr.fi, fr.se + 1, 'R');
    }
    cout << "NO\n";
}