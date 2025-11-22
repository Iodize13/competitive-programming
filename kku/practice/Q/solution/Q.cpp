#include<stdio.h>
#include<stdlib.h>
int main() {
	int T;
	long long N;
	scanf("%d",&T);
	for(int i=0;i<T;i++) {
		scanf("%lld",&N);
		printf("%lld\n",N*(N+1)/2);
	}
}
