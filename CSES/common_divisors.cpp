#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define N 1000001
#define fi first
#define se second
using namespace std;
vector<int> v(N);
int n, x, a = 0;

int main()
{
    cin >> n;
    rep(i, n)
    {
        cin >> x;
        a = max(a, x);
        int j = sqrt(x);
        for (int i = 1; i <= j; i++)
        {
            if (x % i == 0)
                v[i]++, v[x / i]++;
        }
        if (j * j == x)
            v[j]--;
    }
    for (int i = a; i > 0; i--)
        if (v[i] > 1)
        {
            cout << i << "\n";
            return 0;
        }
}