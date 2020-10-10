/* 树
树的度：度最大的度
双亲结点 == 父结点
祖先：从根结点到结点的所有结点
子孙：结点下的所有子结点

初始化树——
销毁树——
按定义构造树——
清空树——
判断是否为空——
树的深度——
求根结点——
返回结点的值——
求双亲结点——
求最左孩子——
求右兄弟——
插入结点——
删除结点——
遍历树——
 */

/* 
存储结构
 */
typedef int TElemType;
#define MAX_TREE_SIZE 100
//双亲表示法
typedef struct PTNode{      //结点结构
    TElemType data;
    int parent;     //双亲位置域
}PTNode;
typedef struct{     //树结构
    PTNode nodes[MAX_TREE_SIZE];
    int r,n;    //根的位置，结点数
}PTree;

//孩子表示法
typedef struct CTNode{      //孩子结点
    int child;
    struct CTNode *next;
}ChildPtr;
typedef struct{
    TElemType data;
    ChildPtr firstchild;        //孩子链表头指针
}CTBox;
typedef struct{
    CTBox node[MAX_TREE_SIZE];
    int r,n;        //根的位置，结点数
}CTree;

//孩子兄弟表示法(二叉树表示法)
typedef struct CSNode{
    TElemType data;
    struct CSNode *firstchild,*nextsibling;     //第一个孩子结点和下一个兄弟结点
}CSNode,*CSTree;