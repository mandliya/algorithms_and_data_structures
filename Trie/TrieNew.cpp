#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct Trie
{
public:
    Trie *children[26] = {};
    bool isWord = false;

    void insert(string &word)
    {
        Trie *curr = this;
        for (char c : word)
        {

            if (curr->children[c - 'a'] == nullptr)
            {

                curr->children[c - 'a'] = new Trie();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
        cout << "insertion took palce successfully!!" << endl;
    }
    bool search()
    {
        string word;
        cout << "enter the string you want to search" << endl;
        cin >> word;
        Trie *curr = this;
        for (char &c : word)
        {
            if (!curr->children[c - 'a'])
            {

                return false;
            }

            curr = curr->children[c - 'a'];
        }
        if (curr->isWord)
        {
            cout << "the word is present" << endl;
        }
        else
        {
            cout << "the word is not present:" << endl;
        }

        return curr->isWord;
    }
    bool searchWithin()
    {
        string prefixWord;
        cout << "enter the prefixWord you want to check" << endl;
        cin >> prefixWord;
        Trie *curr = this;
        for (char c : prefixWord)
        {
            if (!curr->children[c - 'a'])
                return false;
            curr = curr->children[c - 'a'];
        }
        cout << "the prefix word is present in the trie" << endl;
        return true;
    }
};

int main()
{
    Trie trie;
    int n;
    cout << "enter the number of strings you want to store in vector:" << endl;
    cin >> n;

    vector<string> store(n);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cout << "enter the string:" << endl;
        cin >> temp;
        store[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << store[i] << endl;
    }
    cout << "choose number 1 to insert all elements to trie" << endl;
    cout << "1:insert words" << endl;
    int number;
    cin >> number;
    switch (number)
    {
    case 1:
        cout << "insertion of trie takes place!" << endl;
        for (int i = 0; i < n; i++)
        {
            trie.insert(store[i]);
        }
        break;

    default:
        break;
    }
    cout << endl;

    cout << "Choose 2:search \t Choose 3:search Prefix" << endl;
    int number1;
    cout << "enter the Option:" << endl;
    cin >> number1;

    switch (number1)
    {
    case 2:
        trie.search();
        break;
    case 3:
        trie.searchWithin();

    default:
        break;
    }
    return 0;
}