#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> p(40);
ll divid_into_two(int i, ll l, ll r)
{
    if (i < 0 || i == n)
    {
        if (i == n)
            return abs(l - r);
    }
    else
    {
        return min(divid_into_two(i + 1, l + p[i], r),
                   divid_into_two(i + 1, l, r + p[i]));
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    cout << divid_into_two(0, 0, 0) << "\n";
}