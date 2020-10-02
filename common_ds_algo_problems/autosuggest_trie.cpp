#include<bits/stdc++.h>
using namespace std;

struct Trie{
	Trie *children[26];
	int isEnd;
};

Trie* createNode(){
	Trie *node =new Trie;
	node->isEnd=0;
	for(int i=0;i<26;i++){
		node->children[i]=NULL;
	}
	return node;
}

void insert(string t,Trie *root){
	int n=t.size();
	Trie *temp=root;
	for(int i=0;i<n;i++){
		int index=t[i]-'a';
		if(!temp->children[index])temp->children[index]=createNode();
		temp=temp->children[index];
	}
	temp->isEnd=temp->isEnd+1;
}

int search(string s,Trie *root){
	int n=s.size();
	Trie *temp=root;
	for(int i=0;i<n;i++){
		int index=s[i]-'a';
		if(!temp->children[index])return 0;
		temp=temp->children[index];
	}
	if(temp!=NULL){
		return temp->isEnd;
	}else{
		return 0;
	}
}

void display(Trie *root,string str){
	if(root->isEnd > 0){
		cout<<str<<endl;
	}
	if(root!=NULL){
		for(int i=0;i<26;i++){
			if(root->children[i]!=NULL){
				display(root->children[i],(str+(char)('a'+i)));
			}
		}
	}
}

int autoSuggest(string s,Trie *root){
	int n=s.size();
	Trie *temp=root;
	for(int i=0;i<n;i++){
		int index=s[i]-'a';
		if(!temp->children[index])return 0;
		temp=temp->children[index];
	}
	if(temp!=NULL){
		display(temp,s);
	}else{
		return 0;
	}
}

int main(){
	int q;
	cin>>q;
	Trie *root=createNode();
	while(q--){
		string s,t;
		cin>>s>>t;
		if(s=="insert"){
			insert(t,root);
		}else if(s=="get"){
			int cnt=search(t,root);
			cout<<cnt<<endl;
		}else if(s=="suggest"){
			int res=autoSuggest(t,root);
			if(!res){
				cout<<"No suggestions found!"<<endl;
			}
		}
	}
	cout<<endl;
	string str="";
	display(root,str);
	return 0;
}