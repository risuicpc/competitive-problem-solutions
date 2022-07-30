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
int ans = 0;
vi v(N), ind(N);
int f(int i, int j, int k)
{
    // cout << i << " " << j << " " << k << "\n";
    if ((k > i && k > j) || (k < i && k < j))
        return 0;
    else
    {
        if ((v[i] > v[k] && j > k) || (v[i] < v[k] && j < k))
            return -1;
        else
            return 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n >> m;
    rep(i, n)
    {
        cin >> x;
        v[i + 1] = x;
        ind[x] = i + 1;
        if (!ind[x - 1])
            ans++;
    }

    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        if (a != b)
        {
            if (v[a] - 1 > 0 && v[a] - 1 != v[b])
                ans += f(a, b, ind[v[a] - 1]);
            else if (v[a] - 1 > 0 && v[a] - 1 == v[b])
            {
                if (a < b)
                    ans--;
                else
                    ans++;
            }
            if (v[a] + 1 <= n && v[a] + 1 != v[b])
                ans += f(a, b, ind[v[a] + 1]);
            else if (v[a] + 1 <= n && v[a] + 1 == v[b])
            {
                if (a > b)
                    ans--;
                else
                    ans++;
            }

            if (v[b] - 1 > 0 && v[b] - 1 != v[a])
                ans += f(b, a, ind[v[b] - 1]);

            if (v[b] + 1 <= n && v[b] + 1 != v[a])
                ans += f(b, a, ind[v[b] + 1]);
        }
        cout << ans << "\n";
        swap(v[a], v[b]);
        swap(ind[v[a]], ind[v[b]]);

        // for (int l = 1; l <= n; l++)
        //     cout << v[l] << " ";
        // cout << "\n";
    }
}