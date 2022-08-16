#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define N 5000
using namespace std;
typedef long long ll;
vector<ll> V;
int n;

ll dp[N][N];
ll solve(int i, int j)
{
    rep(g, n)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            ll x = i + 2 <= j ? dp[i + 2][j] : 0;
            ll y = i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0;
            ll z = i <= j - 2 ? dp[i][j - 2] : 0;

            dp[i][j] = max(V[i] + min(x, y), V[j] + min(y, z));
        }
    }

    return dp[0][n - 1];
}

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    rep(i, n)
    {
        ll x;
        cin >> x;
        V.pb(x);
    }
    cout << solve(0, n - 1) << "\n";
}