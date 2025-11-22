#include<stdio.h>

int main() {
  	while(1) {
		int N,M;
		scanf("%d %d",&N,&M);
		if(N == -1 && M == -1) break;
		if(N < M) printf("%d\n",2*N-2);
		else printf("%d\n",2*M-2);
  	}
}
