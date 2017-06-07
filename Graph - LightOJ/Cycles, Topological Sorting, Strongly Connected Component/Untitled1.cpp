    #include<iostream>
    #include <cstdio>
    #include <cstring>
    #include<vector>
    #include<stack>
    #include <queue>
    using namespace std;
    const int maxn = 1010;


    int vis[maxn];
    int y[maxn];
    vector <int> G[maxn], G2[maxn], G3[maxn];
    int n, m;
    int a[maxn][maxn];

    int pre[maxn];
    int low[maxn];
    int sccno[maxn];
    int dfs_clock;
    int scc_cnt;
    stack <int> S;

    void dfs(int u)
    {
        pre[u] = low[u] = ++dfs_clock;
        S.push(u);
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if(!pre[v])
            {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if(!sccno[v])
                low[u] = min(low[u], pre[v]);
        }
        if(pre[u] == low[u])
        {
            scc_cnt++;
            while(1)
            {
                int x = S.top();
                S.pop();
                sccno[x] = scc_cnt;
                if(x == u)
                    break;
            }
        }
    }
    void find_scc()
    {
        dfs_clock = scc_cnt = 0;
        memset(sccno, 0, sizeof(sccno));
        memset(pre, 0, sizeof(pre));
        for(int i = 1; i <= n; i++)
            if(!pre[i])
                dfs(i);
    }

    void BFS(int u)
    {
        queue <int> Q;
        memset(vis, 0, sizeof(vis));
        vis[u] = true;
        Q.push(u);
        while(!Q.empty())
        {
            int x = Q.front(); Q.pop();
            for(int i = 0; i < G2[x].size(); i++)
            {
                int v = G2[x][i];
                if(vis[v])
                    continue;
                vis[v] = true;
                G[u].push_back(v);
                Q.push(v);
            }
        }
    }
    bool dfs2(int u)
    {
        for(int i = 0; i < G3[u].size(); i++)
        {
            int v = G3[u][i];
            if(vis[v])
                continue;
            vis[v] = true;
            if(y[v] == -1 || dfs2(y[v]))
            {
                y[v] = u;
                return true;
            }
        }
        return false;
    }
    int match()
    {
        int ans = 0;
        memset(y, -1, sizeof(y));
        for(int i = 1; i <= scc_cnt; i++)
        {
            memset(vis, 0, sizeof(vis));
            if(dfs2(i))
                ans++;
        }
        return ans;
    }

    int main()
    {
        freopen("input.tst","r",stdin);
        int cas = 1;
        int T;
        scanf("%d", &T);
        while(T--)
        {
            scanf("%d %d", &n, &m);
            for(int i = 0; i <= n; i++)
                G[i].clear(), G2[i].clear(), G3[i].clear();
            while(m--)
            {
                int u, v;
                scanf("%d %d", &u, &v);
                G2[u].push_back(v);
            }
            for(int i = 1; i <= n; i++)
                BFS(i);
            find_scc();

            for(int u = 1; u <= n; u++)
            {
                for(int i = 0; i < G[u].size(); i++)
                {
                    int v = G[u][i];
                    if(sccno[u] != sccno[v])
                        G3[sccno[u]].push_back(sccno[v]);
                }
            }
            printf("Case %d: %d\n", cas++, scc_cnt-match());
        }
        return 0;
    }
