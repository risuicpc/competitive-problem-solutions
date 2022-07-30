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
map<int, int> mi;
int n, x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n;
    rep(i, n)
    {
        cin >> x;
        bool nb = 1;
        if (i > 0)
        {
            auto lb = mi.lower_bound(x);

            for (auto it = lb; it != mi.end();)
                it = mi.erase(it);
            if (mi.size() > 0)
            {
                cout << (--mi.end())->se << " ";
                nb = 0;
            }
        }
        if (nb)
            cout << 0 << " ";
        mi.insert({x, i + 1});
    }
}