#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int digit(int n)
{
    int an = 0;
    while (n)
    {
        an = max(an, n % 10);
        n /= 10;
    }
    return an;
}

int main()
{
    int n;
    cin >> n;
    int step = 0;
    while (n)
    {
        n -= digit(n);
        step++;
    }
    cout << step << "\n";
}