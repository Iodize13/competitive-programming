#include <stdio.h>
#include <queue>
#include <set>
using namespace std;

int point_to[500005];
int in_degree[500005];

queue<int> q;

int co_answered;
bool answered[500005];
int max_good;
set<int> s;

void answer(int p, bool good) {
	if(answered[p]) return;
	co_answered++;
	answered[p] = 1;
	s.erase(p);
	max_good += good;
	int next = point_to[p];
	if(good) answer(next,1-good);
	else {
		in_degree[next]--;
		if(in_degree[next]==0)
			q.push(next);
	}
}

int main() {
	int T;
	scanf("%d",&T);
	for (int rr=0;rr<T;rr++) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &point_to[i]);
			in_degree[point_to[i]]++;
			s.insert(i);
    		}

		for(int i=1;i<=n;i++) {
			if(in_degree[i]==0) {
				q.push(i);
			}
		}

		while(co_answered!=n) {
			if(!q.empty()) {
				int g = q.front();
				q.pop();				
				answer(g,1);
			}
			else {
				answer(*(s.begin()),0);
			}
		}
		printf("%d\n", max_good);

		co_answered = 0;
		max_good = 0;
		while(!q.empty()) q.pop();
		s.clear();
		for(int i=1;i<=n;i++) {
			answered[i]=0;
			in_degree[i]=0;
			point_to[i]=0;
		}
			
	}
}
