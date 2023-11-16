#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int

struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};
class HuffmanEncoder
{
private:
    unordered_map<char, int> frequency;
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
    MinHeapNode *left, *right, *top, *root;
    void countFrequency(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            frequency[s[i]]++;
        }
        // put in minHeap after counting frequency
        for (auto it : frequency)
        {
            minHeap.push(new MinHeapNode(it.first, it.second));
        }
    }

public:
    void printFrequency()
    {
        for (auto it : frequency)
        {
            cout << it.first << " " << it.second << endl;
        }
    }
    void encode(string s)
    {
        countFrequency(s);
        while (minHeap.size() > 1)
        {
            left = minHeap.top();
            minHeap.pop();
            cout << left->data << endl;
            right = minHeap.top();
            minHeap.pop();
            cout << right->data << endl;
            top = new MinHeapNode('$', left->freq + right->freq);
            top->left = left;
            top->right = right;
            minHeap.push(top);
            cout << top->data << endl;
        }
        root = top;
    }
    void printCodes(string str)
    {
        if (!root)
        {
            return;
        }
        if (root->data != '$')
        {
            cout << root->data << ": " << str << endl;
        }
        root = root->left;
        printCodes(str + "0");
        root = root->right;
        printCodes(str + "1");
    }
};
int main()
{
    string s = "ddbvkjblnbb";
    HuffmanEncoder hf;
    hf.encode(s);
    // hf.printFrequency();
    hf.printCodes("");
    return 0;
}
