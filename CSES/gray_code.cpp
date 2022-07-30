#include <bits/stdc++.h>
using namespace std;

void bin(int n)
{
    if (n > 1)
        bin(n / 2);
    cout << n % 2;
}

int ans = 0, m;
void display(int n, char sign)
{
    ans = sign == '+' ? ans + (1 << n - 1) : ans - (1 << n - 1);
    int len = log2(ans);
    for (int i = 0; i < m - len - 1; i++)
        cout << 0;
    bin(ans);
    cout << "\n";
}

void grayCode(int n, char sign)
{
    if (n == 1)
        display(n, sign);
    else
    {
        grayCode(n - 1, '+');
        display(n, sign);
        grayCode(n - 1, '-');
    }
}

int main()
{
    cin >> m;
    for (int i = 0; i < m; i++)
        cout << 0;
    cout << "\n";
    grayCode(m, '+');
}