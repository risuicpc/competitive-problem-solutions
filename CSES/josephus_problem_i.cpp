#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    node *next;
};

int main()
{
    int n;
    cin >> n;
    node *t, *root = new node();
    root->x = 1;
    t = root;
    for (int i = 2; i <= n; i++)
    {
        node *temp = new node();
        temp->x = i;
        t->next = temp;
        t = temp;
    }
    t->next = root;

    while (root != root->next)
    {
        cout << root->next->x << " ";
        root->next = root->next->next;
        root = root->next;
    }
    cout << root->x << "\n";
}