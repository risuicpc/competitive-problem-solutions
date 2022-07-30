#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<bool> v(n + 1);
    vector<long long> a;
    long long sum = (n * (n + 1)) / 2;
    if (sum % 2)
        cout << "NO\n";
    else
    {
        sum /= 2;
        cout << "YES\n";
        while (sum > 0)
        {
            if (sum >= n)
            {
                v[n] = 1;
                a.push_back(n);
                sum -= n;
                n--;
            }
            else if (sum > 0)
            {
                v[sum] = 1;
                a.push_back(sum);
                sum = 0;
            }
        }

        cout << a.size() << "\n";
        for (int i : a)
            cout << i << " ";
        cout << "\n"
             << v.size() - (a.size() + 1) << "\n";
        for (int i = 1; i < v.size(); i++)
        {
            if (!v[i])
                cout << i << " ";
        }
        cout << endl;
    }
}