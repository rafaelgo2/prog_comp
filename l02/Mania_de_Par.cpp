#include <cstdio>
#include <queue>

using namespace std;
const int INF = 100000000  ;
typedef pair<int, int> PII;

int main(){
	int c, v;
    scanf("%d%d", &c, &v);
	vector< vector<PII> > grafo1_1(c+1);
	for (int i = 0; i < v; i++){
        int c1, c2, g;
        scanf("%d%d%d", &c1, &c2, &g);
        grafo1_1[c1].push_back(make_pair(g, c2));
        grafo1_1[c2].push_back(make_pair(g, c1));
	}
	vector< vector<PII> > grafo2_2(c+1);
	for (unsigned int i = 1; i < grafo1_1.size(); i++){
        int origem = i;
        for (unsigned int j = 0; j < grafo1_1[i].size(); j++){
            PII meio = grafo1_1[i][j];
            for (unsigned int k = 0; k < grafo1_1[meio.second].size(); k++){
                PII destino = grafo1_1[meio.second][k];
                if (origem != destino.second){
                    grafo2_2[origem].push_back(make_pair(meio.first + destino.first, destino.second));
                }
            }
        }
	}

	priority_queue<PII, vector<PII>, greater<PII> > Q;
    vector<int> dist(c+1, INF);
    Q.push(make_pair(0, 1));
    dist[1] = 0;
    while (!Q.empty()){
        PII p = Q.top();
        Q.pop();
        int here = p.second;
        if (here == c) break;
        if (dist[here] != p.first) continue;


        for (unsigned int i = 0; i < grafo2_2[here].size(); i++){
            if (dist[here] + grafo2_2[here][i].first < dist[grafo2_2[here][i].second]){
                dist[grafo2_2[here][i].second] = dist[here] + grafo2_2[here][i].first;
                Q.push(make_pair(dist[grafo2_2[here][i].second], grafo2_2[here][i].second));
            }
        }
    }
    if (dist[c] < INF)
        printf("%d\n", dist[c]);
    else
        printf("-1\n");
	return 0;
}
