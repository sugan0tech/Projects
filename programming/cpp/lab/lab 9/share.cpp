#include <bits/stdc++.h>
using namespace std;

const int SIZ = 26;

struct Trie
{
    struct Trie *children[SIZ];

    bool is_end;
};

struct Trie *getNode(void)
{
    struct Trie *pNode = new Trie;

    pNode->is_end = false;

    for (int i = 0; i < SIZ; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct Trie *root, string key)
{
    struct Trie *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->is_end = true;
}

bool search(struct Trie *root, string key)
{
    struct Trie *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl->is_end);
}

int main()
{
    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their"};
    int n = sizeof(keys) / sizeof(keys[0]);

    struct Trie *root = getNode();

    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    search(root, "the") ? cout << "Yes\n" : cout << "No\n";
    search(root, "these") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}