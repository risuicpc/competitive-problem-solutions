#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, x, k = 1;
    cin >> n;
    while (k <= n)
    {
        x = k * k;
        cout << ((x * (x - 1)) / 2) - (4 * (k - 1) * (k - 2)) << "\n";
        k++;
    }
}