#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define for if(0);else for

struct In{
	char s[25];
}dat[1005];

typedef struct trie{
	struct trie *next[26];
	char data;
	int cnt;
}*_trie;

void init_trie(_trie root,char *string){
	_trie s;
	s=root;
	s->cnt=0;
	while(*string!=0){
		if(s->next[*string-'a']==NULL){
			s->next[*string-'a']=(_trie)malloc(sizeof(struct trie));
			(s->next[*string-'a'])->data=*string;
			s->next[*string-'a']->cnt=1;
			s=s->next[*string-'a'];
			for(int i=0;i<26;i++){
				s->next[i]=NULL;
			}
		}
		else {
			s->next[*string-'a']->cnt++;
			s=s->next[*string-'a'];
		}
		string++;
	}
	s->cnt++;
}

void search(_trie root,char *string,int cur){
	if(string[cur]==0)return;
	for(int i=0;i<26;i++){
		if(root->next[i]&&root->next[i]->data==string[cur]){
			putchar(string[cur]);
			if(root->next[i]->cnt==1)return;			                   search(root->next[i],string,cur+1);
		}
	}

}

int main(){
	int n=0;
	_trie root;
	root=(_trie)malloc(sizeof(struct trie));
	for(int i=0;i<26;i++)root->next[i]=NULL;
	while(scanf("%s",dat[n].s)==1){
		init_trie(root,dat[n].s);
		n++;
	}
	for(int i=0;i<n;i++){
		printf("%s ",dat[i].s);
		search(root,dat[i].s,0);
		puts("");
	}
	return 0;
}



