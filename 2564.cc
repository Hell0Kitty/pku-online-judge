#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 25010;
const int HASH = 1000010;

int n,head[HASH],next[MAXN],f[MAXN];
char b[MAXN][20],temp[20];

int hash(char *s){
	int v = 0,seed = 131;
	while (*s)
		v = v * seed + *(s++);
	return (v & 0x7fffffff) % HASH;
}

void insert(int s){
	int h = hash(b[s]);
	next[s] = head[h];
	head[h] = s; 
}

int search(char *s){
	int i,h = hash(s);
	for (i = head[h]; i != -1; i = next[i])
		if (!strcmp(b[i],s))
			break;
	return i;
}

void add(char *s, int p, int d){
	int i = 0, j = 0;
	while (i < p)
		temp[j++] = s[i++];
	temp[j++] = 'a' + d;
	while (s[i])
		temp[j++] = s[i++];
	temp[j] = '\0';
}

void del(char *s, int p){
	int i = 0,j = 0;
	while (i < p)
		temp[j++] = s[i++];
	i++;
	while (s[i])
		temp[j++] = s[i++];
	temp[j] = '\0';
}

void change(char *s, int p, int d){
	strcpy(temp, s);
	temp[p] = 'a' + d;
}

int dp(int s){
	if (f[s] != -1)
		return f[s];
	int ans = 0;
	int len = strlen(b[s]);
	for (int p = 0; p <= len; p++)
		for (int d = 0; d < 26; d++){
			add(b[s], p, d);
			int v = search(temp);
			if (v != -1 && strcmp(b[s], temp) < 0){
				int t = dp(v);
				if (ans < t+1)
					ans = t+1;
			}
		}
	for (int p = 0; p < len; p++){
		del(b[s], p);
		int v = search(temp);
		if (v != -1 && strcmp(b[s], temp) < 0){
			int t = dp(v);
			if (ans < t+1)
				ans = t+1;
		}
	}
	for (int p = 0; p < len; p++)
		for (int d = 0; d < 26; d++){
			change(b[s], p, d);
			int v = search(temp);
			if (v != -1 && strcmp(b[s], temp) < 0){
				int t = dp(v);
				if (ans < t+1)
					ans = t+1;
			}
		}
	return f[s] = ans;
}

int main(){
	n = 0;
	memset(head, -1, sizeof(head));
	while (scanf("%s", b[n]) != EOF){
		insert(n),++n;
	}
	memset(f, -1, sizeof(f));
	int ans = 0;
	for (int i = 0; i < n; i++){
		int t = dp(i);
		if (ans < t)
			ans = t;
	}
	printf("%d\n", ans+1);
	return 0;
}



