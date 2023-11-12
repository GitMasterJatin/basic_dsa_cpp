#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int

struct Node
{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
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
int countDistinctSubstrings(string &s)
{
    int cnt = 0;
    Node *root = new Node();
    for (int i = 0; i < s.length(); i++)
    {
        Node *node = root;
        for (int j = i; j < s.length(); j++)
        {
            if (!node->containsKey(s[i]))
            {
                cnt++;
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
    }
    // count empty string class as well;
    return cnt + 1;
}

int main()
{
    string s = "abc";
    cout << countDistinctSubstrings(s) << endl;
    string a = "aaa";
    cout << countDistinctSubstrings(a) << endl;
    return 0;
}
