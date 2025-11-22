#include<stdio.h>
#define MAX_N (1000005)
#define MAX_D (1000005)

// The number of fishes swimming at depth D
int prev_D[MAX_D];

int main() {
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++) {
		for(int i=0;i<MAX_D;i++) prev_D[i]=0;
		int N;
		scanf("%d",&N);
		int ans = 0;
		for(int i=0;i<N;i++) {
			int depth;
			scanf("%d",&depth);
			if(prev_D[depth-1] != 0) prev_D[depth-1]--;
			else ans++;
			prev_D[depth]++;
		}
		printf("%d\n",ans);
	}
}

