#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ordered_set o_set;
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        o_set.insert(i);

    int kk = k % n;
    int i, ii = kk;
    while (n > 0)
    {
        for (i = ii; i < n; i += kk)
        {
            auto j = o_set.find_by_order(i);
            cout << *j << " ";
            o_set.erase(j);
            n--;
            if (!n)
                break;
            kk = k % n;
        }
        if (!n)
            break;
        ii = i % n;
    }
    cout << "\n";
}