#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;
    string *word;

    bool checkKey(char c)
    {
        return links[c - 'a'];
    }
    void put(char c, Node *node)
    {
        links[c - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
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

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        // creating new object
        root = new Node();
    }

    bool insert(string words)
    {
        Node *node = root;
        for (int i = 0; i < words.size(); i++)
        {
            if (!node->checkKey(words[i]))
            {
                node->put(words[i], new Node());
            }
            node = node->get(words[i]);
        }
        node->setEnd();
        node->word = &words; 

        return true;
    }

    bool search(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->checkKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        if (node->isEnd())
        {

            return true;
        }
        return false;
    }
    bool startsWithin(string prefixWord)
    {
        Node *node = root;
        for (int i = 0; i < prefixWord.size(); i++)
        {
            if (!node->checkKey(prefixWord[i]))
            {
                return false;
            }
            node = node->get(prefixWord[i]);
        }
        return true;
    }
};

int main()
{
    Node *node;
    Trie trie;

    int n;
    cout << "enter the number of words to insert in the string:" << endl;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cout << "enter the string you want to insert:" << endl;
        cin >> temp;
        words[i] = temp;
    }

    cout << "insert the string in to the trie:" << endl;

    for (int i = 0; i < n; i++)
    {
        if (trie.insert(words[i]))
            cout << "inserted all words successfully!" << endl;
    }
    bool searchAnswer = trie.search(words[0]);
    if (searchAnswer)
    {

        cout << "word is present in the trie::" << endl;
    }
    else
    {
        cout << "word is not present" << endl;
    }

    return 0;
}
