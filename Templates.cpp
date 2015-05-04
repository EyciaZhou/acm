int one(int value)
{
    value = (value & 0x55555555) + ((value >> 1) & 0x55555555);
    value = (value & 0x33333333) + ((value >> 2) & 0x33333333);
    value = (value & 0x0F0F0F0F) + ((value >> 4) & 0x0F0F0F0F);
    value = (value & 0x00FF00FF) + ((value >> 8) & 0x00FF00FF);
    value = (value & 0x0000FFFF) + ((value >> 16) & 0x0000FFFF);
    return value;
}

//----tarjan-----
vector<int> g[10005];   //grah
int dfn[10005];         //first visit time
int low[10005];         //the low visit time
int belong[10005];      //the point's belong at last
int nn[10005];          //the child point number in the big point
int ind;                //time
bool v[10005];          //visited
bool sta[10005];        //in stack

stack<int> ss;          //the stack
int num = 0;            //the big point's No

void tarjan(int u) {
    dfn[u] = low[u] = ++ind;
    ss.push(u);
    sta[u] = true;
    v[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
        if (!v[g[u][i]]) {
            tarjan(g[u][i]);
            low[u] = min(low[u], low[g[u][i]]);
        } else if (sta[g[u][i]]) {
            low[u] = min(low[u], dfn[g[u][i]]);
        }
    }
    if (dfn[u] == low[u]) {
        int p, k = 0;
        num++;
        do {
            k++;
            p = ss.top();
            ss.pop();
            belong[p] = num;
            sta[p] = false;
        } while (p != u);
        nn[num] = k;
    }
}
//----end tarjan------


//----start cmp-------
typedef struct node{
    int deadline;
    int score;
    
    bool operator<(const node& a) const
    {
        if (score == a.score) {
            return deadline < a.deadline;
        }
        return score < a.score;
    }
} *pnode;

bool cmp(const node &a, const node &b) {
    return b.deadline < a.deadline;
}

struct cmp2 {
    bool operator()(const pnode &na, const pnode &nb)
    {
        if (na->score == nb->score) {
            return na->deadline < nb->deadline;
        }
        return na->score < nb->score;
    }
};
//------low_bound-------
struct Comparator {
    inline bool operator()(const ps& s1, const ps& s2) const {
        return s1.first < s2.first;
    }
    inline bool operator()(const ps& s1, const string& s2) const {
        return s1.first < s2;
    }
    inline bool operator()(const string& s1, const ps& s2) const {
        return s1 < s2.first;
    }
};
//-----end cmp-------------

//-----最大流－－－－－－
const int N = 210;
const int INF = 0x7fffffff;
int num_node;

int map[N][N];
int pre[N];
int flow_in[N];
int start, end;
std::queue<int> q;

int find_one_bfs() {
    int i, t;
    while (!q.empty()) {
        q.pop();
    }
    memset(pre, -1, sizeof(pre));
    
    pre[start] = 0;
    flow_in[start] = INF;
    
    q.push(start);
    while (!q.empty()) {
        t = q.front();
        q.pop();
        
        if (t == end) {
            break;
        }
        
        for (i = 1; i <= num_node; i++) {
            if (pre[i] == -1 &&  map[t][i]) {
                if (flow_in[t] < map[t][i]) {
                    flow_in[i] = flow_in[t];
                } else {
                    flow_in[i] = map[t][i];
                }
                q.push(i);
                pre[i] = t;
            }
        }
    }
    if (pre[end] == -1) {
        return -1;
    } else{
        return flow_in[end];
    }
}

int zdl() {
    int max_flow = 0;
    int cf_p;
    int now, prev;
    
    while ((cf_p = find_one_bfs()) != -1) {
        max_flow += cf_p;
        
        now = end;
        
        while (now != start) {
            prev = pre[now];
            map[prev][now] -= cf_p;
            map[now][prev] += cf_p;
            now = prev;
        }
    }
    return max_flow;
}
//－－－－end 最大流－－－－－－

//－－－－而大二分匹配－－－－－
vector<int> G[__maxNodes];
typedef vector<int>::iterator iterator_t;

int num_nodes;
int num_left;
int num_right;
int num_edges;

int matching[__maxNodes];
int check[__maxNodes];

bool dfs(int u) {
    for (iterator_t i = G[u].begin(); i != G[u].end(); i++) {
        int v = *i;
        if (!check[v]) {
            check[v] = true;
            if (matching[v] < 0 || dfs(matching[v])) {
                matching[v] = u;
                matching[u] = v;
                return true;
            }
        }
    }
    return false;
}

int xyl_dfs() {
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    for (int u = 0; u < num_left; u++) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u)) {
                ans++;
            }
        }
    }
    return ans;
}

int solv(int t) {
    int temp[1005];
    for (int i = 0; i < 2010; i++) {
        G[i].clear();
    }
    
    for (int i = 0; i < t; i++) {
        cin >> temp[i];
    }
    for (int i = 0; i < t - 1; i++) {
        for (int j = i + 1; j < t; j++) {
            if (temp[i] >= temp[j]) {
                G[i].push_back(1000+j);
                G[1000+j].push_back(i);
            }
        }
    }
    num_left = t;
    return t - xyl_dfs();
}
//------end--------

//------并查集－－－－
inline int getf(int s) {
    if (fa[s] == s) {
        return s;
    }
    int t = s;
    while (fa[t] != t) {
        t = fa[t];
    }
    fa[s] = t;
    while (fa[s] != s) {
        s = fa[s];
        fa[s] = t;
    }
    return t;
}
//------end--------

//--#include <iomanip>---cout << fixed <<  setprecision(10) << tot << endl;----