#include <bits/stdc++.h>
#define rep(i, n) for (int i = 1; i <= n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define N 100000
using namespace std;
typedef long long ll;
vector<pair<int, int>> V;
int n, x;

int dp[1001][N + 1];
void knapsack()
{
    rep(i, n) rep(j, x)
    {
        if (V[i - 1].fi <= j)
            dp[i][j] = max(dp[i - 1][j], V[i - 1].se + dp[i - 1][j - V[i - 1].fi]);
        else
            dp[i][j] = dp[i - 1][j];
    }
    cout << dp[n][x] << "\n";
}

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    vector<int> h(n), s(n);
    rep(i, n) cin >> h[i - 1];
    rep(i, n) cin >> s[i - 1];
    rep(i, n) { V.pb({h[i - 1], s[i - 1]}); }
    sort(all(V));
    knapsack();
}