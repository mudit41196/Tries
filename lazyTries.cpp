#include<iostream>
#include<cstring>
using namespace std;

struct trie
{
	trie* next[26];
	char suffix[50];
	int isword;

};
trie* createnode()
{
	trie* nn=new trie;
	int i;
	for(i=0;i<26;i++)
	{
		nn->next[i]=NULL;
	}
	nn->suffix[0]='\0';
	nn->isword=0;
	return nn;
	
}
void insert(trie* root,char* str)
{
	if(str[0]=='\0'){root->isword=1; return;}
	
	int alphabet=str[0]-'a';
	if(root->next[alphabet]==NULL)
	{
		trie* temp=createnode();
		root->next[alphabet]=temp;
		strcpy(temp->suffix,str+1);
		temp->isword=1;
		return;
	}
	else
	{	
		trie* node=root->next[alphabet];
		insert(node,node->suffix);
		node->suffix[0]='\0';
		node->isword=0;
		
		insert(node,str+1);
	}
}
int check(trie* root,char* str)
{
	if(str[0]=='\0'){
		return root->isword;
	}
	int alphabet=str[0]-'a';
	if(root->next[alphabet]==NULL){return 0;}
	
	trie* node=root->next[alphabet];
	if(node->suffix[0]!='\0')	
		{	
			if(strcmp(node->suffix,str+1)==0){return 1;}
			else{return 0;}
		}
	return check(root->next[alphabet],str+1);		
		
}
int main()
{
	trie* root=createnode();
	char str1[50]="tree";
	insert(root,str1);
	
	char str2[50]="trie";
	
	insert(root,str2);
	cout << check(root,"trie");
	cout << check(root,"toy");
	cout << check(root,"t");
}










