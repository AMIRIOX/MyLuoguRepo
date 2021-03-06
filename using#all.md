# (fake code)

## usage of bellman-ford 

@循环n-1次 每次对所有边进行松弛
@如果结束后还有可以松弛的边 说明有负环
1. 预处理: {
    填充dis数组 dis[1]=0
}
2. for i to n-1
    for each edge(u,v,w) of $G
        if dis[v] > dis[u] + w 
            dis[v] = dis[u] + w
3. for each edge(u,v,w) of graph
    if dis[v] > dis[u] + w
        return true
!注意(2)和(3)中需要判断dis[x]不为inf

---


## usage of SPFA

@从起始节点开始拓展BFS序节点 只对松弛过的点连向的边进行松弛
@如果经过的最短路超过了节点总数 说明有负环
1. 预处理: {
    填充dis数组 dis[s]=0 
    清空cnt数组
    q.push(s) inq[s]=true
}
2. while q.size
    取出对首作为current
    for each edge(v,w) connected to current
        if dis[v] > dis[u] + w
            dis[v] = dis[u] + w
            cnt[v] = cnt[u] + 1
            if cnt[v] >= n 
                return true
            if !inq[v] 
                q.push(v) inq[v]=true
?为什么是`>=`:
    `cnt[s]=0` 如果`cnt[i]==n`说明最短路已经是所有节点数+1了 必有负环.

---


## usage of Dijkstra (with heap optimization)

@每次从距离起始节点最近的节点开始以BFS序拓展节点并松弛其连向的边
0. 数据结构: 带有u和dis的node结构体, 定义排序规则为符号`>`
            优先队列priq
1. 预处理: {
    填充dis数组 dis[s]=0
    清空vis数组
    priq.push(node(s, 0));
}
2. while q.size
    取出队首作为node x(u,udis)
    vis[u]=true
    for each edge(v,w) connect to u
        if dis[v] > dis[u] + w
            dis[v] = dis[u] + w
            if !vis[v] 
                q.push(node(v,dis[v]))

---


## usage of SPFA

@通过中继节点k将i~j更新为i~k+k~j
1. 预处理: {
    填充dis数组
    将有效的G[i][j]填入dis数组
        如果i==j则填0 
        否则填原值
}
2. for each node(k) of $V
    for each node(i) of $V
        for each node(j) of $V
            if dis[i][j] > dis[i][k] + dis[k][j]
                dis[i][j] = dis[i][k] + dis[k][j]
!?Floyd算法枚举k_i的时候，已经得到了前 k-1 个点的最短路径?

---

//TODO
```
树的直径（两次BFS/DFS）
分块
LCA-倍增法
树状数组（单点修改区间查询 区间修改单点查询）
treap和fhq-treap
ST表求RMQ问题
```
