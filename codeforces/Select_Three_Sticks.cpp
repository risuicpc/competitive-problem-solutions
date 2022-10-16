// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main()
// {
//     int t, n;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         vector<int> v(n);
//         for (int i = 0; i < n; i++)
//             cin >> v[i];
//         sort(v.begin(), v.end());
//         int an = INT_MAX;
//         for (int i = 1; i < n - 1; i++)
//             an = min(an, v[i + 1] - v[i - 1]);
//         cout << an << "\n";
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main()
// {
//     int t, n, k;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n >> k;
//         vector<ll> v(n);
//         for (int i = 0; i < n; i++)
//             cin >> v[i];
//         sort(v.rbegin(), v.rend());
//         ll an = 0;
//         for (int i = 0; i < k; i++)
//             an += v[i];
//         cout << an << "\n";
//     }
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t, n;
    ll x, y;
    string a, b;
    cin >> t;
    while (t--)
    {
        vector<ll> v;
        cin >> n >> x >> y >> a >> b;
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                v.push_back(i);
        if (v.size() % 2 == 1)
            cout << -1 << "\n";
        else
        {
            ll an = 0, sm = 0, l = v.size();

            if (l > 2)
            {
                for (ll i = 0; i < l; i += 2)
                {
                    sm += ((v[i + 1] - v[i]) * x);
                    if (v[i] + 1 == v[i + 1])
                    {
                        an += min(x, 2 * y);
                    }
                    else
                        an += min((v[i + 1] - v[i]) * x, y);
                }
                an = min(sm, an);
                an = min((l / 2) * y, an);
            }
            else if (l == 2)
            {
                if (v[0] + 1 == v[1])
                    an += min(x, 2 * y);
                else
                    an += min((v[1] - v[0]) * x, y);
            }

            cout << an << "\n";
        }
    }
}