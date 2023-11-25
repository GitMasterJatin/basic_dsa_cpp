// find sum of elements in a given range of indices
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
int query(int node, int start, int end, int l, int r)
{

    // case of no overlap
    if (start > r || end < l)
        return 0;

    // if in between
    if (start >= l && end <= r)
    {
        return tree[node];
    }

    // partial segment
    // make call to both children
    int mid = start + (end - start) / 2;
    int left = query(2 * node, start, mid, l, r);
    int right = query(2 * node + 1, mid + 1, end, l, r);

    return left + right;
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
    // for (int i = 1; i < 2 * n; i++)
    // {
    //     cout << tree[i] << endl;
    // }
    cout << query(1, 0, n - 1, 1, 5) << endl;
    return 0;
}
