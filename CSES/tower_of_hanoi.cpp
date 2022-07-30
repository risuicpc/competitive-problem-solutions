#include <bits/stdc++.h>
using namespace std;

void tower_hanoi(int n, int src, int aux, int dest)
{
    if (n == 1)
        cout << src << " " << dest << "\n";
    else
    {
        tower_hanoi(n - 1, src, dest, aux);
        cout << src << " " << dest << "\n";
        tower_hanoi(n - 1, aux, src, dest);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << (2 << n - 1) - 1 << "\n";
    tower_hanoi(n, 1, 2, 3);
}