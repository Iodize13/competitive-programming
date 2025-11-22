#include<stdio.h>
#include<string.h>
#define MAX_L (105)

char input[MAX_L];
char krit[4] = "ABC";
char kwan[5] = "BABC";
char uthai[7] = "CCAABB";
int score[3];

int main() {
	while(scanf("%s",input)!=EOF) {
		int length = strlen(input);
		for(int i=0;i<3;i++) score[i]=0;
		for(int i=0;i<length;i++) {
			score[0] += (input[i] == krit[i%3]);
			score[1] += (input[i] == kwan[i%4]);
			score[2] += (input[i] == uthai[i%6]);
		}
		int ans = score[0];
		if(score[1] > ans) ans = score[1];
		if(score[2] > ans) ans = score[2];
		printf("%d",ans);
		if(score[0] == ans) printf(" Krit");
		if(score[1] == ans) printf(" Kwan");
		if(score[2] == ans) printf(" Uthai");
		printf("\n");
	}	
}
