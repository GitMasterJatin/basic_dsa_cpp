// find maximum in a given range and also add the function to update the array at a given index

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

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
int queryMax(int node, int start, int end, int l, int r)
{

    // case of no overlap
    if (start > r || end < l)
        return INT_MIN;

    // if in between
    if (start >= l && end <= r)
    {
        return tree[node];
    }

    // partial segment
    // make call to both children
    int mid = start + (end - start) / 2;
    int left = queryMax(2 * node, start, mid, l, r);
    int right = queryMax(2 * node + 1, mid + 1, end, l, r);

    return max(left, right);
}
void update(int node, int start, int end, int index, int val)
{
    // start updating from the leaf node
    if (start == end)
    {
        tree[node] = val;
        a[start] = val;
        return;
    }
    // update is similar to binary search
    int mid = start + (end - start) / 2;
    if (index <= mid)
    {
        update(2 * node, start, mid, index, val);
    }
    else
    {
        update(2 * node + 1, mid + 1, end, index, val);
    }
    // all ancestors of updated node need to be updated
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
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
    cout << queryMax(1, 0, n - 1, 3, 5) << endl;
    update(1, 0, n - 1, 7, 58);
    cout << queryMax(1, 0, n - 1, 0, 5) << endl;
    cout << queryMax(1, 0, n - 1, 0, 7) << endl;
    return 0;
}
