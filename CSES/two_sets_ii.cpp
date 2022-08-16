#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define N 63000
using namespace std;
typedef long long ll;
int n;

int dp[N][501];
void findWays(int x)
{
    rep(i, n + 1) dp[0][i] = 1;
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (dp[i][j - 1] + (i >= j ? dp[i - j][j - 1] : 0)) % mod;

    cout << dp[x][n] / 2 << "\n";
}

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int x = (n * (n + 1)) / 2;
    if (x & 1)
        cout << 0 << "\n";
    else
        findWays(x / 2);
}