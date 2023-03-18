#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct Trie
{
    Trie *children[26] = {};
    string *Word;

    void fillWords(string &word)
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
        curr->Word = &word;
    }
};
vector<string> ans;

void dfs(int i, int j, int m, int n, vector<vector<char>> &grid, Trie *curr)
{
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '.' || curr->children[grid[i][j] - 'a'] == nullptr)
        return;
    char c = grid[i][j];
    curr = curr->children[c - 'a'];
    if (curr->Word != nullptr)
    {
        ans.push_back(*curr->Word);
        curr->Word = nullptr;
    }
    dfs(i + 1, j, m, n, grid, curr);
    dfs(i - 1, j, m, n, grid, curr);
    dfs(i, j + 1, m, n, grid, curr);
    dfs(i, j - 1, m, n, grid, curr);
    grid[i][j] = c;
}

vector<string> findWords(vector<vector<char>> &grid, vector<string> &word)
{
    int m = grid.size();
    int n = grid[0].size();
    Trie trie;
    for (string &s : word)
    {
        trie.fillWords(s);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dfs(i, j, m, n, grid, &trie);
        }
    }

    return ans;
}

int main()
{
    int row;
    int col;

    cout << "enter the row size of the matrix:" << endl;
    cin >> row;
    cout << "enter the column size of the matrix:" << endl;
    cin >> col;

    vector<vector<char>> grid(row, vector<char>(col));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            char c;
            cout << "enter the character to the grid:" << endl;
            cin >> c;
            grid[i][j] = c;
        }
        cout << endl;
    }
    cout << endl;
    int n;
    cout << "enter the string vector:" << endl;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cout << "enter the strings to list:" << endl;
        cin >> temp;
        s[i] = temp;
    }
    cout << endl;
    vector<string> ans = findWords(grid, s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}