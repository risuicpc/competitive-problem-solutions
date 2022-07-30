#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long x, len;
        cin >> x;
        string str;
        cin >> str;
        string curr = str;
        while (x > 0)
        {
            if (curr.length() <= 3)
                break;
            len = curr.length();
            curr = curr.substr(len / 4, len);
            x--;
            len = curr.length();
            if (x <= 0)
                break;
            if (curr.length() <= 3)
                break;
            curr = curr.substr(0, len - (len / 4));
            x--;
        }
        cout << curr << endl;
    }
}