#include <bits/stdc++.h>
#define rep(i, n) for (int i = 1; i <= n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define eb push_back
#define fi first
#define se second
#define mod 1000000007
#define N 200000
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<tuple<int, int64_t, int64_t>> V;
    rep(i, k)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'R')
        {
            V.eb({a, 0, 1});
            V.eb({b + 1, 0, -1});
        }
        else if (c == 'D')
        {
            V.eb({a, 0, -1});
            V.eb({b + 1, 0, 1});
        }
        else if (c == 'H')
        {
            int m = (a + b) / 2;
            V.eb({a, 1, -a + 1});
            V.eb({m + 1, -1, a - 1});
            V.eb({m + 1, -1, b + 1});
            V.eb({b + 1, 1, -b - 1});
        }
        else if (c == 'V')
        {
            int m = (a + b) / 2;
            V.eb({a, -1, a - 1});
            V.eb({m + 1, 1, -a + 1});
            V.eb({m + 1, 1, -b - 1});
            V.eb({b + 1, -1, b + 1});
        }
    }
    sort(all(V));
    int64_t K = 0, b = 0;
    int j = 0;
    rep(i, n)
    {
        while (j < len(V) && get<0>(V[j]) <= i)
        {
            K += get<1>(V[j]);
            b += get<2>(V[j]);
            j++;
        }
        cout << K * i + b << "\n";
    }
}