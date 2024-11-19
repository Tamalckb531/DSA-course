#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    unordered_map<char, TrieNode *> children;
    bool isTerminal;

    TrieNode(char val)
    {
        data = val;
        isTerminal = false;
    }
};
void insertWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    TrieNode *child;
    if (root->children.find(ch) != root->children.end())
    {
        // present
        child = root->children[ch];
    }
    else
    {
        // absent
        child = new TrieNode(ch);
        root->children[ch] = child;
    }

    insertWord(child, word.substr(1));
}

void findlcp(TrieNode *root, string &ans)
{
    //? base case
    if (root->isTerminal)
    {
        return;
    }
    //? processing
    TrieNode *child;
    if (root->children.size() == 1)
    {
        //* The loop under is not a loop as the children is only one. We are just using it to retrieve the children easily
        for (auto i : root->children)
        {
            char ch = i.first;
            ans.push_back(ch);
            child = i.second;
        }
    }
    else
    {
        return;
    }

    findlcp(child, ans);
}

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        TrieNode *root = new TrieNode('-');

        // insert all words into trie
        for (auto word : strs)
        {
            insertWord(root, word);
        }

        // main logic
        string ans = "";
        findlcp(root, ans);
        return ans;
    }
};