* 性质/典/trick
    1. 同步加值不影响相对大小
    2. 找两个无公共部分的连续等长区间和的最大值可以枚举左区间计算最大值 `maxl`,
        同步更新 `maxl` + 右区间和的最大值
        ```cpp
        int maxk = -0x3f3f3f3f, ans = -0x3f3f3f3f;
        for(int i = k; i + k <= n; i++) {
            // [i - k + 1, i]   [i + 1, i + k]
            maxk = max(maxk, sum{i - k + 1, i});
            ans = max(ans, maxk + sum{i + 1, i + k});
        }
        ```
    3. 枚举两个无公共部分子区间可以枚举 `i` (前半段结尾后半段开始), 
        再分别枚举端点
        ```cpp
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) cnt[a[i] ^ a[j - 1]]++;
            for(int j = i + 1; j <= n; j++) ans += cnt[a[j] ^ a[i + 1 - 1]];
        }
        ```
    4. 数字和字母挨在一块最好用 cin 读, 别先读入然后离线处理.

* 差分
    1. `b[i] = a[i] - a[i - 1]`    
    在进行区间增减，求出某一个位置修改后的值时      
    `b[i]` 作为差分数组进行标记， `a[i]` 为 `b[i]` 的前缀和，代表位置 i 的值
    2. 具有区间加减法、求某一位修改后值特性的题目都要想着一点将题目转换为能够进行差分的形式。
    3. 可以从0计算 `b[i]` 达到只记录变化量, 而后在前缀和中具体计算值

* 前缀和
    1. 前缀和一定要考虑 `1~r`的情况,在考虑将 `l~r` 转换过去.
    2. 列式子拆括号化简可得出前缀和,因此要对式子中隐含的前缀和有概念
    3. 异或操作也可以前缀和

* 搜索
    1. 你只管搜索枚举, 剩下的交给 min/max 
    2. 注意搜索方向, 可能会有不能转弯的情况
    3. 千万注意数据范围能否搜索!!! (不仅要在意"否"也要在意"能")

* 递归
    1. 注意递归的终止条件, 部分递归虽然形式是一样的但终止条件略有不同, 如 `P1010` 这里不知道怎么说了, 感觉不如初高中脑子好使了
    2. 搜索能草掉很多递归范式. 别局限思路.
        将 n 拆分为 1, 2, 3, 4, .. , m 中几个数的和:
            (1) 深度优先搜索, 不降原则防止重复
            (2) 递归为两个情况: 将 n-m 分为不超过 m 的数的和, 将 n 分为不超过 m-1 的数的和
                推广到其他部分, m-1 也可以是 next(m) 等 (`recursion4.cpp`)
