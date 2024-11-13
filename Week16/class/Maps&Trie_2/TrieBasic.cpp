#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode
{
public:
    char value;
    unordered_map<int, TrieNode *> children;
    bool isTerminal;

    TrieNode(char data)
    {
        value = data;
        isTerminal = false;
    }
};

void insertIntoTrie(TrieNode *root, string word)
{
    //? base case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    //? processing
    char ch = word[0];
    TrieNode *child;

    if (root->children.count(ch) == 1)
    {
        child = root->children[ch];
    }
    else
    {
        child = new TrieNode(ch);
        root->children[ch] = child;
    }

    insertIntoTrie(child, word.substr(1));
}

bool searchTrie(TrieNode *root, string word)
{

    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    TrieNode *child;

    if (root->children.find(ch) != root->children.end())
    {
        child = root->children[ch];
    }
    else
    {
        return false;
    }

    bool recursionAns = searchTrie(child, word.substr(1));
    return recursionAns;
}

void deleteTrie(TrieNode *root, string word)
{

    if (word.length() == 0)
    {
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    TrieNode *child;

    if (root->children.find(ch) != root->children.end())
    {
        child = root->children[ch];
    }
    else
    {
        return;
    }

    deleteTrie(child, word.substr(1));
}

int main()
{
    cout << "Hello!" << endl;

    TrieNode *root = new TrieNode('-');
    insertIntoTrie(root, "cover");
    insertIntoTrie(root, "car");
    insertIntoTrie(root, "care");
    insertIntoTrie(root, "snake");
    insertIntoTrie(root, "five");
    insertIntoTrie(root, "extreme");
    insertIntoTrie(root, "coward");
    insertIntoTrie(root, "obsessed");
    insertIntoTrie(root, "tag");
    insertIntoTrie(root, "take");
    insertIntoTrie(root, "took");

    deleteTrie(root, "cover");
    bool ans = searchTrie(root, "cover");
    if (ans)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    return 0;
}