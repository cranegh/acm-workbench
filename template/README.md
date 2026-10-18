# 个人 ACM / ICPC 模板库

42 个模板，按 7 个算法大类存放。打印版：[ACM_Template.pdf](printable/ACM_Template.pdf)。

## 维护规则

1. 使用你习惯的 int、long long，不引入更宽的整数类型。乘法和总和超出 ll 时，先核对题目范围，不偷偷更换类型。
2. 已写过的算法以原文件为准：保留算法流程、变量、全局数组、函数、下标、循环和输出习惯。
   不把“接口统一”或“进一步优化”当作理由重写。仅提取题目无关部分、补必要初始化、修正明确错误。
3. KMP 与 Manacher 的 `#include` 之后逐字保留原文件，连完整 main 和输出形式一起保留。
   若原写法有适用前提，就注明前提；不替换其拼接串、哨兵或匹配流程。
4. 新增算法的注释说明最小调用示例、参数、返回结果、关键变量、主要步骤和清空方式，直接进入打印版。
5. 每次修改后更新测试与 PDF，不能只改 cpp 留下过期纸质版本。

## 源码来源与风格

递归读取 747 份 C++/头文件，共 27,877 行；清单和原始 SHA-256 在 `history_inventory.json`。
初筛关键词只帮助定位候选，不代表程序已经 AC。已对照来源逐项核查本库提取实现。
历史题解没有修改。

风格保留：`using ll = long long;`、四空格缩进、紧凑运算符、
`for(int i=1 ; i<=n ; i++)`、全局数组、`vector<edge> g[N]`，
以及 `root/fa`、`lowbit/getsum`、`w/lzy`、`pushup/pushdown`、`pi/len`、`C/R/p` 等原名称。
来源和新增标记见下面索引；新增算法不能假称为你的原实现。

## 使用方式

- `00_base/main.cpp` 是比赛骨架。KMP 和 Manacher 是各自独立可运行的原程序，直接编译即可。
- 其余通常为片段，复制所需函数/全局定义到骨架前，按文件注释填写 solve。
  不把所有 cpp 一起链接：`N/g/init/build/query` 等短名称保留了你的习惯，组合时按题目取舍。
- 二分保留 `while(l+1!=r)` 和 `(l+r)>>1`，返回最后一个假位置；必须先保证两端是假/真哨兵。
- KMP 读正文 s1 和模式 s2，拼 `s2+'#'+s1`，输出所有 **1-index** 匹配位置，再输出模式串 pi。
  两串非空且不含 `#`，不是空模式通用库。
- Manacher 读非空字符串，使用 `@/#/$`；输入不应包含这三个保留字符，输出最长回文长度。
- 快速幂先设全局 p，使用 `qpow(a,b)%p`；0<=a<p，b>=0，1<=p<=3037000500。
- 二维前缀和把原数据放 `diff`，build 原地转前缀和；再次 build 前必须重填原数据。
- 组合数保留 `f[n]*inv(f[m])%MOD*inv(f[n-m])%MOD`，init 只处理实际最大 n，查询 O(log MOD)。
- 完全背包保留“组合计数”的原语义；01 背包、分组背包保留全局 dp 和原循环方向。
- 其他接口以 cpp 注释为准。图多测清空旧点数范围内的邻接表、反图、边表，再重建。
- N 包含容量余量，合法下标至多 N-1。扩大 ST/LCA 的 N 时也要检查 LOG。
- DSU、Kruskal 保留原递归 root 与连接方式。很长的父链可能爆栈，这是原写法的使用限制。
- 凸包返回原来的 hi/lo 两条链，未改成单个环；坐标范围按文件注释控制，ll 叉积也会溢出。

## 修正边界

保留的正确性修正有：埃氏筛将误写的 `vis[i]` 改为 `vis[j]`；组合数预处理不再访问 f[N]；
线段树建树清空懒标记；多测清空工作状态；Floyd 跳过不可达项；A* 过滤不可达点并限制重复弹出，防止环上无休止扩展。
这些改动围绕原实现进行。没有新增按大小合并、逆阶乘、KMP 双串扫描或 Manacher 整数哨兵；全册不使用 `__int128`。
补充的 Trie query/init 与计数数组单独注明，insert 的大小写分支保留原样。

新增的 ST、匹配、LCA、SCC、割点/桥、Z-function、字符串哈希、扩欧等在代码里解释调用和关键步骤。
迭代 DFS/SCC/割点桥是新增写法，说明栈如何模拟遍历；二分图匹配保留较短的递归增广。
不加入网络流、2-SAT、树链剖分、AC 自动机、SAM、SA；一般图带花树草稿未当成已掌握的可靠模板收入。
已有 Kruskal 不再重复加入 Prim；凸包独立归几何，没有凑一个杂项目录。

## 验证与增量维护

```bash
python3 template/validate.py
python3 template/build_pdf.py
python3 template/check_pdf.py
```

使用 C++17；`validate.py` 默认用 PATH 中的 `g++`，也可传 `--cxx '编译器路径'`，或设置 `CXX`。本版不需要更宽整数扩展。
每份片段用 `-fsyntax-only` 独立编译；KMP、Manacher 运行原程序样例，图论恢复版运行随机对拍，其他新增模板提供语法检查和代码内调用说明。
随机种子固定为 20260906，基准包括朴素数组、穷举、传递闭包、删除点/边后的连通分量等。
测试只覆盖模板注明的合法输入范围，不能把超范围成功当成支持承诺。
KMP/Manacher 测试直接运行原程序；本次最终检查另用 `tools/tests/template/final_audit.py` 对全部 42 个模板进行对拍和边界验证，并检查两份字符串程序与原文件逐字一致。
结果及源码哈希见 `validation_report.json`。这不是形式化证明，没有宣称执行过 ASan/UBSan。

新增模板时，在对应分类放一个 cpp，在 `catalog.json` 登记信息，并为 `validate.py` 增加验证。
cpp 是唯一代码来源；`build_pdf.py` 读取现有文件生成 A4、目录、页码和书签，不重新生成算法代码。
`check_pdf.py` 核查页码链接、所有代码行、页面边界、字体嵌入和测试/PDF/源码哈希一致。
重新生成后仍需用 Poppler 渲染并检查实际分页。中间文件放 `tools/tests/template/.work/`（已 gitignore）。

Python 依赖在 `requirements.txt`。打印字体默认取 `TEMPLATE_FONT_DIR`（默认 `C:/Windows/Fonts`）下的 Consolas 与 SimSun；其他系统用 `TEMPLATE_CODE_FONT`、`TEMPLATE_CODE_BOLD_FONT`、`TEMPLATE_CJK_FONT` 指到实际字体文件。

## 模板索引与原始来源

来源表示提取关系，不代表原题解已 AC；新增实现明确标出。

- [比赛主程序](00_base/main.cpp)：多测入口。来源：[cf/cfcode/fjcpc_h.cpp](../solutions/fjcpc_h.cpp)。
- [快速幂](00_base/fast_pow.cpp)：正模数下幂取模。来源：`P_1226_模板_快速幂.cpp`（本地 archive/oldcode/）。
- [整数二分](00_base/binary_search.cpp)：寻找最后一个不满足 check 的整数。来源：[cf/cfcode/fjcpc_b.cpp](../solutions/fjcpc_b.cpp)。
- [二维前缀和](00_base/prefix_sum_2d.cpp)：静态子矩形求和。来源：[luogu/P_2004_领地选择.cpp](../solutions/P_2004_领地选择.cpp)。
- [二维差分](00_base/difference_2d.cpp)：离线矩形加，最终还原。来源：`【模板】二维前缀和.cpp`（本地 archive/oldcode/）。
- [离散化](00_base/discretization.cpp)：值映射为有序编号。来源：[luogu/P_1955_NOI_2015_程序自动分析.cpp](../solutions/P_1955_NOI_2015_程序自动分析.cpp)。
- [并查集](01_data_structure/dsu.cpp)：动态连通性。来源：[luogu/P_1955_NOI_2015_程序自动分析.cpp](../solutions/P_1955_NOI_2015_程序自动分析.cpp)。
- [树状数组](01_data_structure/fenwick.cpp)：单点加、前缀和、区间和。来源：`P_3374_模板_树状数组_1.cpp`（本地 archive/oldcode/）。
- [线段树](01_data_structure/segment_tree.cpp)：单点赋值、区间和。来源：[luogu/P_3372_模板_线段树_1.cpp](../solutions/P_3372_模板_线段树_1__7c1012046e.cpp)。
- [懒标记线段树](01_data_structure/lazy_segment_tree.cpp)：区间加、区间和。来源：[luogu/P_3372_模板_线段树_1.cpp](../solutions/P_3372_模板_线段树_1__7c1012046e.cpp)。
- [赋值加法线段树](01_data_structure/lazy_assign_add_max.cpp)：区间赋值、区间加、区间最大值。来源：[luogu/P_1253_扶苏的问题.cpp](../solutions/P_1253_扶苏的问题.cpp)。
- [ST 表](01_data_structure/sparse_table.cpp)：静态区间最大值。来源：按个人风格补充，含使用说明。
- [单调栈](01_data_structure/monotonic_stack.cpp)：右侧第一个严格更大元素的位置。来源：`P_5788_模板_单调栈.cpp`（本地 archive/oldcode/）。
- [单调队列](01_data_structure/monotonic_queue.cpp)：长度 k 的滑动窗口最小值。来源：`P_1886_模板_单调队列_滑动窗口.cpp`（本地 archive/oldcode/）。
- [BFS](02_graph/bfs.cpp)：无权图最短距离。来源：按个人风格补充，含使用说明。
- [迭代 DFS](02_graph/dfs_order.cpp)：遍历、生成树父亲与逆序树 DP。来源：按个人风格补充，含使用说明。
- [拓扑排序](02_graph/topo_sort.cpp)：有向图判环、DAG 处理顺序。来源：`B_3644_模板_拓扑排序_家谱树.cpp`（本地 archive/oldcode/）。
- [Dijkstra](02_graph/dijkstra.cpp)：非负权单源最短路。来源：`P_3371_模板_单源最短路径_弱化版.cpp`（本地 archive/oldcode/）。
- [Floyd](02_graph/floyd.cpp)：全源最短路。来源：`floyd.cpp`（本地 archive/oldcode/）。
- [Kruskal](02_graph/kruskal.cpp)：最小生成树 / 最小生成森林。来源：[luogu/P_1194_买礼物.cpp](../solutions/P_1194_买礼物.cpp)。
- [二分图染色](02_graph/bipartite.cpp)：无向图二分性判定。来源：按个人风格补充，含使用说明。
- [二分图最大匹配](02_graph/bipartite_matching.cpp)：增广路求最大匹配数。来源：按个人风格补充，含使用说明。
- [倍增 LCA](02_graph/lca.cpp)：树 / 森林最近公共祖先。来源：按个人风格补充，含使用说明。
- [强连通分量](02_graph/scc.cpp)：Kosaraju 迭代版。来源：按个人风格补充，含使用说明。
- [割点与桥](02_graph/cut_bridge.cpp)：无向图 lowlink，支持重边。来源：按个人风格补充，含使用说明。
- [A* 第 k 短路](02_graph/astar_kth_walk.cpp)：非负权图第 k 短游走，可重复点边。来源：[luogu/P_1379_八数码难题.cpp](../solutions/P_1379_八数码难题.cpp)。
- [KMP](03_string/kmp.cpp)：拼接串前缀函数，输出匹配起点和模式串 pi。来源：[cf/summer2/KMP.cpp](../contest/nowcoder-summer-2/KMP.cpp)、[luogu/P_4391_BalticOI_2009_Radio_Transmission_无线传输.cpp](../solutions/P_4391_BalticOI_2009_Radio_Transmission_无线传输.cpp)。
- [Manacher](03_string/manacher.cpp)：最长回文子串长度。来源：[luogu/P_3805_模板_Manacher.cpp](../solutions/P_3805_模板_Manacher.cpp)。
- [Trie](03_string/trie.cpp)：大小写字母字典，统计完整单词次数。来源：[cf/summer3/H.cpp](../contest/nowcoder-summer-3/H.cpp)。
- [Z-function](03_string/z_function.cpp)：各后缀与全串的最长公共前缀。来源：按个人风格补充，含使用说明。
- [双模字符串哈希](03_string/string_hash.cpp)：子串相等性快速筛选。来源：按个人风格补充，含使用说明。
- [埃氏筛](04_math/sieve.cpp)：筛出 2..n 所有素数。来源：`埃氏筛.cpp`（本地 archive/oldcode/）。
- [试除分解质因数](04_math/factorization.cpp)：返回 {素因子,指数}。来源：[luogu/B_3716_分解质因子_3.cpp](../solutions/B_3716_分解质因子_3.cpp)。
- [扩展欧几里得与逆元](04_math/exgcd_inverse.cpp)：ax+by=gcd(a,b)，一般模数逆元。来源：按个人风格补充，含使用说明。
- [组合数](04_math/combination.cpp)：阶乘与快速幂逆元求组合数。来源：`求组合数.cpp`（本地 archive/oldcode/）。
- [01 背包](05_dp/knapsack_01.cpp)：容量至多 m 的最大价值。来源：`P_1048_NOIP_2005_普及组_采药.cpp`（本地 archive/oldcode/）。
- [完全背包计数](05_dp/complete_knapsack.cpp)：每种体积无限次，恰好凑出 n 的组合数。来源：`P_1832_A_B_Problem_再升级.cpp`（本地 archive/oldcode/）。
- [多重背包](05_dp/bounded_knapsack.cpp)：二进制拆分数量限制。来源：按个人风格补充，含使用说明。
- [分组背包](05_dp/group_knapsack.cpp)：每组至多选一个物品。来源：`P_1757_通天之分组背包.cpp`（本地 archive/oldcode/）。
- [最长严格上升子序列](05_dp/lis.cpp)：长度与一个下标方案。来源：按个人风格补充，含使用说明。
- [子集枚举](05_dp/submask.cpp)：遍历一个 mask 的所有子集。来源：按个人风格补充，含使用说明。
- [二维凸包](06_geometry/convex_hull.cpp)：返回上凸壳 hi 与下凸壳 lo，两条链均按 x 递增。来源：[luogu/P_2742_模板_二维凸包_USACO_5_1_圈奶牛Fencing_the_Cows.cpp](../solutions/P_2742_模板_二维凸包_USACO_5_1_圈奶牛Fencing_the_Cows.cpp)、[luogu/P_1452_USACO_03_FALL_Beauty_Contest_G.cpp](../solutions/P_1452_USACO_03_FALL_Beauty_Contest_G.cpp)。
