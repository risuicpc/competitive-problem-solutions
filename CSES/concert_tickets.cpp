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
int n, m, k, x;
ll ans = 0;
map<int, int> h;
vi t(N);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n >> m;
    rep(i, n)
    {
        cin >> x;
        h[x]++;
    }
    rep(i, m)
    {
        cin >> x;
        auto iter = h.lower_bound(x);
        if (iter->fi == x && iter->se > 0)
        {
            if (iter->se > 1)
                h[iter->fi]--;
            else
                h.erase(iter);
            cout << iter->fi << "\n";
        }
        else if (iter->fi != x && iter != h.begin())
        {
            iter--;
            if (iter->se > 1)
                h[iter->fi]--;
            else
                h.erase(iter);
            cout << iter->fi << "\n";
        }
        else
            cout << -1 << "\n";
    }
}