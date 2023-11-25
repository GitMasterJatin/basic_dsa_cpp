#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;
const int N = 1e3;
vector<int> a(N, 0), tree(4 * N, 0);

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
        return;
    }
    int mid = start + (end - start) / 2;
    // left subtree
    build(2 * node, start, mid);
    // right subtree
    build(2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    for (int i = 1; i < 2 * n; i++)
    {
        cout << tree[i] << endl;
    }
    return 0;
}
