// Q) given an array and a number x, find the maximum value of xor of arr[i] ^ x

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int

struct Node
{
    Node *links[2];
    bool flag = false;
    bool containsKey(int ch)
    {
        return (links[ch] != NULL);
    }
    Node *get(int ch)
    {
        return links[ch];
    }
    void put(int ch, Node *node)
    {
        links[ch] = node;
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};
int maximizeXOR(int x, vector<int> &v)
{
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans = max(ans, v[i] ^ x);
    }
    return ans;
}
int maximiseXORTries(int x, vector<int> &v)
{
    Node *root = new Node();
    for (int i = 0; i < v.size(); i++)
    {
        Node *node = root;
        for (int j = 1; j <= 32; j++)
        {
            int bit = (v[i] & (1 << (32 - j))) > 0;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int ans = 0;
    Node *node = root;
    for (int i = 1; i <= 32; i++)
    {
        int bit = (x & (1 << (32 - i))) > 0;
        int complement = (bit ^ 1);
        // if node contains the opposite bit
        if (node->containsKey(complement))
        {
            ans |= (1 << (32 - i));
            node = node->get(complement);
        }
        else
        {
            node = node->get(bit);
        }
    }
    return ans;
}
int main()
{
    vector<int> v = {9, 8, 7, 5, 4};
    cout << maximiseXORTries(8, v);
    return 0;
}
