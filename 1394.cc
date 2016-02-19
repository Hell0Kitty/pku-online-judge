#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define INF 1000001
int C, T;
struct {
	int time;
	int city;
}map[1000][100];
char name[100][100];
int start, dist;
int train[1000];
int travel[100];
int search(char *city) {
	for(int i=0; i<C; i++) {
		if(!strcmp(name[i], city))
			return i;
	}
	return -1;
}
void solve(int dep) {
	int i, j, k;
	for(i=0; i<C; i++) {
		travel[i] = INF;
	}
	travel[start] = dep;
	for(k=0; k<C; k++) {
		for(i=0; i<T; i++) {
			for(j=0; j<train[i]-1; j++) {
				if(map[i][j].time >= travel[map[i][j].city] && travel[map[i][j+1].city] > map[i][j+1].time)
					travel[map[i][j+1].city] = map[i][j+1].time;
			}
		}
	}
	for(i=0; i<C; i++) {
		if(i != dist)
			travel[i] = -1;
	}
	for(k=0; k<C; k++) {
		for(i=0; i<T; i++) {
			for(j=0; j<train[i]-1; j++) {
				if(map[i][j+1].time <= travel[map[i][j+1].city] && travel[map[i][j].city] < map[i][j].time)
					travel[map[i][j].city] = map[i][j].time;
			}
		}
	}
}
int main() {
	int i, j;
	char str[1000];
	int dep;
	int id = 1;
	while(scanf("%d", &C), C) {
		for(i=0; i<C; i++)
			scanf("%s", name[i]);
		scanf("%d", &T);
		for(i=0; i<T; i++) {
			scanf("%d", &train[i]);
			for(j=0; j<train[i]; j++) {
				scanf("%d%s", &map[i][j].time, str);
				map[i][j].city = search(str);
			}
		}
		scanf("%d", &dep);
		scanf("%s", str);
		start = search(str);
		scanf("%s", str);
		dist = search(str);
		solve(dep);
		printf("Scenario #%d\n", id++);
		if(travel[dist] < INF) {
			printf("Departure %.4d %s\n", travel[start], name[start]);
			printf("Arrival   %.4d %s\n\n", travel[dist], name[dist]);
		} else {
			puts("No connection\n");
		}
	}
	return 0;
}



