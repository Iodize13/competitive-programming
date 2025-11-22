#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;

#define MP(x,y) (make_pair((x),(y)))
#define MT(x,y,z) (make_pair((x),make_pair((y),(z))))

map<int,long long> m;
map<pair<int,int>, long long> m2;
map<pair<int, pair<int,int> >, long long> m3;

int main() {
	int T;
	int n,b[5];
	scanf("%d",&T);
	for(int rr=0;rr<T;rr++) {
		scanf("%d",&n);
		long long ans = 0;
		for(int i=0;i<n;i++) {
			scanf("%d %d %d",&b[0],&b[1],&b[2]);
			sort(b,b+3);

			// individual fav
			ans += m[b[0]];
			ans += m[b[1]];
			ans += m[b[2]];
			m[b[0]]=m[b[0]]+1;
			m[b[1]]=m[b[1]]+1;
			m[b[2]]=m[b[2]]+1;

			// pair fav
			ans -= m2[MP(b[0],b[1])];
			ans -= m2[MP(b[0],b[2])];
			ans -= m2[MP(b[1],b[2])];
			m2[MP(b[0],b[1])]= m2[MP(b[0],b[1])]+1;
			m2[MP(b[0],b[2])]= m2[MP(b[0],b[2])]+1;
			m2[MP(b[1],b[2])]= m2[MP(b[1],b[2])]+1;

			// triplet fav
			ans +=  m3[MT(b[0],b[1],b[2])];
			m3[MT(b[0],b[1],b[2])]=m3[MT(b[0],b[1],b[2])]+1;
		}
		printf("%lld\n",ans);
		m.clear();
		m2.clear();
		m3.clear();
	}
}

