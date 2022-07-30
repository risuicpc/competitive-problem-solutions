#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector<ll>
#define len(x) x.size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
#define N 200010
using namespace std;
typedef long long ll;
int t, n, m, k, x;
ll ans = 0;
vi v(N);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n;
    ll maxSum = -1e9 - 10;
    rep(i, n)
    {
        cin >> x;
        ans += (ll)x;
        maxSum = max(maxSum, ans);
        ans = ans < 0 ? 0 : ans;
    }
    cout << maxSum << "\n";
}