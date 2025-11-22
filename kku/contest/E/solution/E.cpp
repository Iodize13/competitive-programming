#include<stdio.h>
#define MAX_N (200005)
long long depth[MAX_N];
int main() {
	depth[1] = 1;
	while(1) {
		int N;
		scanf("%d",&N);
		if(N==-1) break;
		long long total = 1;
		for(int i=2;i<=N;i++) {
			int parent;
			scanf("%d",&parent);
			depth[i] = depth[parent]+1;
			total += (depth[i]*(depth[i]+1)/2);
		}
		printf("%lld\n",total);
	}
}

