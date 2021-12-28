#include <bits/stdc++.h>
using namespace std;

const int SIZ = 26;

struct Trie
{
    struct Trie *child[SIZ];

    bool is_end;
};

struct Trie *getNode(void)
{
    struct Trie *parent = new Trie;

    parent->is_end = false;

    for (int i = 0; i < SIZ; i++)
        parent->child[i] = NULL;

    return parent;
}

void insert(struct Trie *root, string key)
{
    struct Trie *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->child[index])
            pCrawl->child[index] = getNode();

        pCrawl = pCrawl->child[index];
    }

    pCrawl->is_end = true;
}

bool search(struct Trie *root, string key)
{
    struct Trie *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->child[index])
            return false;

        pCrawl = pCrawl->child[index];
    }

    return (pCrawl->is_end);
}

void print_ocu(string txt, string pat)
{
    int found = txt.find(pat);
    while (found != string::npos)
    {
        cout << "Pattern found at index " << found << endl;
        found = txt.find(pat, found + 1);
    }
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

    string txt = "aaaa", pat = "aa";
    print_ocu(txt, pat);
    return 0;
}
