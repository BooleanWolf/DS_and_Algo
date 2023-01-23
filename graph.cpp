// time-limit: 3000
#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define loop(x,n) for(int x = 0; x < n; ++x)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define iter(it,a) for(auto it=a.begin();it!=a.end();it++)

bool custom_sort(pair<double, int> a, pair<double, int> b){
    if(a.first==b.first){
        return a.second < b.second;
    }
    else {
        return a.first > b.first;
    }
}


class Graph {
    int V;
    vector<list<int>> adj;
    map<int, bool> visited;

    public:
        Graph(int V);

        void addEdge(int v, int w);
        void BFS(int s);
        void DFS(int v);
};


Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
}


void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){
    vector<bool> visited;
    visited.resize(V, false);

    list<int> queue; 


    visited[s] = true; 
    queue.push_back(s); 

    while(!queue.empty()){
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (auto adjacent: adj[s]){
            if(!visited[adjacent]){
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

void Graph::DFS(int v)
{

    visited[v] = true;
    cout << v << " ";
 

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}


int main() {
    ios_base::sync_with_stdio(0);
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}