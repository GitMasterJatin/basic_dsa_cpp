#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

ll partition(vector<ll> &v, ll low, ll high)
{
    ll pivot = v[high];
    ll i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}
void Quicksort(vector<ll> &v, ll low, ll high)
{
    if (low < high)
    {
        ll par = partition(v, low, high);
        Quicksort(v, low, par - 1);
        Quicksort(v, par + 1, high);
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Quicksort(v, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
