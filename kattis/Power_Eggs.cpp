#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n <= 2)
        {
            cout << n << "\n";
            continue;
        }
        if (k == 1)
        {
            if (n > 32)
                cout << "Impossible\n";
            else
                cout << n << "\n";
        }
        else
        {
            int an = 0, e = k - 2;
            // if (e > 0)
            //     n++;
            while (e > 0 && n > 1)
            {
                n = (n + 1) / 2;
                e--;
                an++;
            }
            if (an > 0)
                n--;
            for (int i = 0; i <= 33; i++)
            {
                int s = (i * (i + 1)) / 2;
                if (s >= n)
                {
                    an += i;
                    break;
                }
                if (i == 33)
                    an += i;
            }
            if (an >= 33)
                cout << "Impossible\n";
            else
                cout << an << "\n";
        }
    }
}