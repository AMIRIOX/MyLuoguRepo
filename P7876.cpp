/*

------------------------------------------------------------------------------------------
遇到比大小想有向图
数据结构描述的是数据之间的关系，要提升建模能力
错误做法示例 吸取教训 多想一想，这个算法需要什么（数据
建图意味着大小关系被成功描述出来，接着根据题意的约束判断不合法条件（一般为环）
然后一般根据在图上构造即可。构造需要一些思维。以及对题目细节的理解到位。
例如本题建图后，不仅要考虑环，还要根据图中两个条件、满足题意的条件判断边之间关系，
构造时要考虑根据边描述的大小关系给点分配值，并且要考虑到多个DAG的情况。
总结：大小关系建图->环/非法的边无解->构造给节点分配值，（正难则反）如果考虑比i弱的点不好想就考虑不比i弱的
考虑构造时视角可以宏观/微观切换，既可以只考虑一个点及周围的关系，也可以大范围一块区域看。
入度是宏观衡量点之间关系的标准，可以多考虑根据入度构造而不是死扣一个点往一个点过去。
-----------
写方格取数、wdoi-4 T4
写swtr 7 score

*/