#include<stdio.h>
#include<stdlib.h>
int main() {
	int n,m;
	while(1) {
		scanf("%d %d",&n,&m);
		if(n == -1 && m == -1) {
			break;
		}
		if(n > m) {
			printf("COE\n");
		}
		if(n < m) {
			printf("CP\n");
		}
		if(n == m) {
			printf("DRAW\n");
		}
	}
}
