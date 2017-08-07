#include<iostream>
using namespace std;

struct trie
{
	trie* next[26];
	int isword;
};

trie* createnode()
{
	trie* nn=new trie;
	for(i=0;i<26;i++)
	{
		nn->next[i]=NULL;
	}
	nn->isword=0;
	return nn;
}
void insert(trie* root,char* str)
{
	if(str[0]=='\0')
	{
		root->isword=1;
		return;
	}
	int alphabet=str[0]-'a';
	if((root->next[alphabet])==NULL)
	{
		root->next[alphabet]=createnode();
	}
	insert(root->next[alphabet],str+1);
}
int check(trie* root,char* str)
{
	if(str[0]=='\0'){return root->isword};
	int alphabet=str[0]-'a';
	if((root->next[alphabet])==NULL){return 0;}
	return check(root->next[alphabet],str+1);
}
	
	
	
	
	
	
	
	
	
