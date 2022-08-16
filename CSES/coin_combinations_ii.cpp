#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define N 1000000
using namespace std;
typedef long long ll;
vector<int> v;
int n, x, a;

int dp[101][N + 1];
void findWays()
{
    sort(all(v));
    rep(i, x + 1) dp[0][i] = 0;
    rep(i, n + 1) dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= x; j++)
            dp[i][j] = (dp[i - 1][j] + (j - v[i - 1] >= 0 ? dp[i][j - v[i - 1]] : 0)) % mod;

    cout << dp[n][x] << "\n";
}

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    rep(i, n)
    {
        cin >> a;
        v.push_back(a);
    }
    findWays();
    return 0;
}