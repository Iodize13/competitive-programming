#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

#define MP(x,y) (make_pair((x),(y)))
#define MT(x,y,z) (make_pair((x),make_pair((y),(z))))

int T;
int n,k;

map<pair<int,int>, int> edge_to_index;
vector<pair<int,long long> > edge[1005];

priority_queue<pair<long long, pair<int,int> >,
	       vector<pair<long long, pair<int,int> > >,
	       greater<pair<long long, pair<int,int> > > > q;
pair<long long, pair<int,int> > g;
pair<long long,int> best[1005],best2[1005];

int mark_answer[1005];

long long shortest_path() {
    q = priority_queue<pair<long long, pair<int,int> >,
	       vector<pair<long long, pair<int,int> > >,
	       greater<pair<long long, pair<int,int> > > >();
	q.push(MT(0,1,-1));
	while(!q.empty()) {
		g = q.top();
		q.pop();
		int city = g.second.first;
		long long cost = g.first;
		int from = g.second.second;
		
		if(best[city].first == -1 ||
		   best[city].first > cost) {
			best2[city] = best[city];
			best[city] = MP(cost,from);

			for(int i=0;i<edge[city].size();i++) {
                        	int next = edge[city][i].first;
                        	long long new_cost = cost + edge[city][i].second;
                        	q.push(MT(new_cost,next,city));
                	}
		}
		else if(best2[city].first == -1 ||
		        best2[city].first > cost) {
			best2[city] = MP(cost,from);
		}
	}
	return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int rr = 0; rr<T;rr++) {
		scanf("%d %d",&n,&k);
		for(int i=0;i<k;i++) {
			int a,b;
			long long r;
			scanf("%d %d %lld",&a,&b,&r);
			edge_to_index[MP(a,b)] = i+1;
			edge_to_index[MP(b,a)] = i+1;
			edge[a].push_back(MP(b,r));
			edge[b].push_back(MP(a,r));
		}
		for(int i=1;i<=n;i++) {
			best[i]=MP(-1,-1);
			best2[i]=MP(-1,-1);
		}
		shortest_path();

		int backward = n;
		int co = 0;
		while(backward != 1) {
			if(best2[backward].first!=-1 && best[backward].first+2 > best2[backward].first)
				break;
			int from = best[backward].second;
			mark_answer[edge_to_index[MP(backward,from)]] = 1;
			co++;
			backward = best[backward].second;
		}

		printf("%d",k-co);
		for(int i=1;i<=k;i++) {
			if(mark_answer[i]==0) printf(" %d",i);
		}
		printf("\n");

		edge_to_index.clear();
		for(int i=1;i<=n;i++) {
			edge[i].clear();
		}
		for(int i=1;i<=k;i++) {
			mark_answer[i]=0;
		}
	}
}
