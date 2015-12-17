#include <iostream>
using namespace std;

const int size = 1001;

struct Node {
  int id;  //结点编号
  struct Node* next;
};

class solve {
 public:
  solve() : cases(0) {
    for (int i = 0; i < size; i++)  //初始化邻接链表链头
      ListTable_Head[i] = 0;

    DFS();
  }
  ~solve() { delete[] * ListTable_Head; }

  int min(int a, int b) const { return a < b ? a : b; }

  bool Input(void);  //返回0: 等待下一组输入。 返回1:程序结束
  void Insert(int x, int y);  //把无向边(x,y)插入邻接表

  void DFS(void);  //搜索割点及其对应的连通分量数
  void DFS_SPF(
      int k, int father,
      int depth);  //搜索割点。k:当前结点。father:k的父亲结点。depth:搜索深度(时间戳)
  void DFS_Subnet(
      int i);  // i为从割点出发的分支,搜索并标记该从该分支出发所能到达的所有node
  //（这些node就是一个连通分量）

  void Empty(void);  //清空邻接表(保留链头并使其指向NULL)
  void Del(Node* p);  //删除以结点p为链头的整条链(保留链头并使其指向NULL)

 protected:
  int cases;                   //案例数
  Node* ListTable_Head[size];  //邻接链表链头

  int Root;        //深搜树的根(搜索起点)
  int deep[size];  //结点k的搜索深度deep[k]
  int AnceDeep[size];  //结点k及其子孙辈分最高(深度最浅)的祖先的深度AnceDeep[k]
  int color[size];      //结点k的颜色color[k]。0:未访问未检查；1:已访问未检查；2:已访问已检查
  bool cut[size];  //标记结点是否为割点
  bool SPF;        //标记网络是否出现割点

  int Subnet_Num;   //被割点的划分的连通分量的个数
  bool vist[size];  //标记访问过的node
};

bool solve::Input(void) {
  int x, y;
  for (int i = 0;; i++) {
    cin >> x;
    if (x == 0 && i == 0)  //程序结束
      break;
    else if (x == 0 && i != 0)  //当前case的数据输入完毕
      return true;

    cin >> y;
    Insert(x, y);
  }
  return false;
}

void solve::Insert(int x, int y) {
  if (!ListTable_Head[x])  //链头不存在，则创建
  {
    ListTable_Head[x] = new Node;
    ListTable_Head[x]->next = 0;
  }
  if (!ListTable_Head[y]) {
    ListTable_Head[y] = new Node;
    ListTable_Head[y]->next = 0;
  }

  Node* px = ListTable_Head[x];
  Node* py = ListTable_Head[y];
  Node* tmp;

  tmp = px->next;  //头插入法
  px->next = new Node;
  px->next->id = y;
  px->next->next = tmp;

  tmp = py->next;  //头插入法
  py->next = new Node;
  py->next->id = x;
  py->next->next = tmp;

  return;
}

void solve::DFS(void) {
  while (Input()) {
    SPF = false;
    memset(deep, 0, sizeof(deep));
    memset(AnceDeep, 0, sizeof(AnceDeep));
    memset(color, 0, sizeof(color));
    memset(cut, false, sizeof(cut));

    /*搜索编号最小的node作为深搜树树的根*/
    for (int k = 1; k < size; k++)
      if (ListTable_Head[k]) {
        Root = k;
        break;
      }

    /*寻找所有割点*/
    DFS_SPF(Root, Root, 1);

    cout << "Network #" << ++cases << endl;
    if (!SPF)
      cout << "  No SPF nodes" << endl;
    else {
      for (int i = Root; i < size; i++)  //小剪枝，根编号必定是最小的编号
        if (cut[i]) {
          Subnet_Num = 0;
          memset(vist, false, sizeof(vist));
          vist[i] = true;

          for (Node* p = ListTable_Head[i]->next; p; p = p->next) {
            if (!vist[p->id]) {  //说明当前分支与前面搜索的连通分量 不连通
              Subnet_Num++;       //则连通分量数+1
              DFS_Subnet(p->id);  //搜索并标记该连通分量下的所有node
            }
          }
          cout << "  SPF node " << i << " leaves " << Subnet_Num << " subnets"
               << endl;
        }
    }
    cout << endl;

    Empty();
  }
  return;
}

void solve::DFS_SPF(int k, int father, int depth) {
  color[k] = 1;
  deep[k] = depth;
  AnceDeep[k] = depth;
  int son = 0;

  for (Node* p = ListTable_Head[k]->next; p; p = p->next) {
    int i = p->id;

    if (color[i] == 0) {
      son++;
      DFS_SPF(i, k, depth + 1);
      AnceDeep[k] = min(AnceDeep[k], AnceDeep[i]);
    }

    if (i != father && color[i] == 1) AnceDeep[k] = min(AnceDeep[k], deep[i]);

    if ((k == Root && son > 1) || (k != Root && AnceDeep[i] >= deep[k])) {
      cut[k] = true;
      SPF = true;
    }
  }
       color[k]=2;
       return;
}

void solve::DFS_Subnet(int cp)
{
       for(Node* p=ListTable_Head[cp]->next;p;p=p->next)
       {
              int i=p->id;
              if(!vist[i])
              {
                     vist[i]=true;
                     DFS_Subnet(i);
              }
       }
       return;
}

void solve::Empty(void)
{
       for(int i=1;i<size;i++)
       {
              if(ListTable_Head[i])
                     Del(ListTable_Head[i]);
              ListTable_Head[i]=0;            //保留链表表头并初始化
       }
       return;
}

void solve::Del(Node* p)
{
       if(p->next)
              Del(p->next);
       delete p;
       return;
}

int main(void)
{
       solve poj1523;
       return 0;
}