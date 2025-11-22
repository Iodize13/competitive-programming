#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_S (105)
#define MAX_L (105)
char mystring[MAX_S][MAX_L];
int main() {
	while(1) {
		int N;
		scanf("%d",&N);
		if(N==-1) break;
		char input[MAX_L];
		for(int i=0;i<N;i++) {
			scanf("%s",input);
			int count = 0;
			int length = strlen(input);
			for(int j=0;j<length;j++) {
				// ignore adjacent identical characters
				if(count==0 || input[j]!=mystring[i][count-1]) {
					mystring[i][count]=input[j];
					count++;
				}
			}
			mystring[i][count]=0;
		}
		int cheat = 0;
		for (int i=1;i<N;i++) {
			if(strcmp(mystring[0],mystring[i])!=0) {
				cheat=1;
				break;
			}
		}
		if(cheat) printf("CHEAT\n");
		else printf("FAIR\n");
	}
}
