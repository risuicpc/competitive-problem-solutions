#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
int n;

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<string> a(n);
    ll v[n][n];
    rep(i, n) rep(j, n) v[i][j] = 0;
    rep(i, n) cin >> a[i];
    if (a[0][0] == '.')
        v[0][0] = 1;
    rep(i, n)
    {
        rep(j, n)
        {
            if (i + 1 < n && a[i + 1][j] == '.')
                v[i + 1][j] = (v[i + 1][j] + v[i][j]) % mod;
            if (j + 1 < n && a[i][j + 1] == '.')
                v[i][j + 1] = (v[i][j + 1] + v[i][j]) % mod;
        }
    }
    cout << v[n - 1][n - 1] << "\n";
}