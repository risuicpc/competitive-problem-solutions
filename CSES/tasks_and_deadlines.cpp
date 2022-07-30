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
vector<pair<ll, ll>> v;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        v.pb({a, b});
    }
    sort(all(v));
    ll an = 0, sum = 0;
    rep(i, n)
    {
        sum += v[i].fi;
        an += (v[i].se - sum);
    }
    cout << an << "\n";
}