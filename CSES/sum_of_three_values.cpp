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
int n;
ll x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n >> x;
    vl v(n);
    map<int, vector<int>> an;
    rep(i, n)
    {
        cin >> v[i];
        an[v[i]].pb(i + 1);
    }
    sort(all(v));
    bool ns = 1;
    rep(k, n - 2)
    {
        if (!ns || n < 3)
            break;
        int i = k + 1, j = n - 1;
        ll t = x - v[k];
        while (i < j)
        {
            if (v[i] + v[j] == t)
            {
                cout << an[v[k]].back() << " ";
                an[v[k]].pop_back();
                cout << an[v[i]].back() << " ";
                an[v[i]].pop_back();
                cout << an[v[j]].back() << "\n";
                ns = 0;
                break;
            }
            else if (v[i] + v[j] < t)
                i++;
            else
                j--;
        }
    }
    if (ns)
        cout << "IMPOSSIBLE\n";
}