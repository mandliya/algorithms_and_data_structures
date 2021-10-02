
#include<bits/stdc++.h>
using namespace std;

class trieNode {
    public:
     char data;
     bool isTerminating;
     trieNode** child;

    public:
     trieNode(char data){
         this->data = data;
         isTerminating = false;
         child = new trieNode*[26];
         for(int i=0; i<26; i++)
            child[i] = NULL;
     }
};

class trie{
    private: 
      trieNode* node;

    trie(){
        node = new trieNode('\0');
    }  
};