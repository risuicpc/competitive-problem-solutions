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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n;
    rep(i, n)
    {
        cin >> x;
        int c = 2;
        if (x == 1)
            cout << x << "\n";
        else
        {
            for (int i = 2; i * i <= x; i++)
                if (i * i == x)
                    c++;
                else if (x % i == 0)
                    c += 2;
            cout << c << "\n";
        }
    }
}