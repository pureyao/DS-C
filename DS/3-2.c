/* 二叉树

堆：经过排序的树——最大堆，最小堆
二叉排序树(二叉查找树)：左子树小于祖先，右子树大于祖先
平衡二叉树(AVL树)：左右子树高度差的绝对值不超过1
哈夫曼树(最优二叉树)：权值最小依次合并。左0右1。

初始化二叉树——
销毁二叉树——
按规则构造二叉树——createBiTree(BiTree *T)
清空二叉树——
判断是否为空——
求二叉树深度——
求二叉树根——
求结点的值——
求双亲结点——
求左孩子结点——
求右孩子结点——
求左兄弟结点——
求右兄弟结点——

插入结点——
删除结点——

先序遍历(根左右)——
中序遍历(左根右)——
后序遍历(左右根)——
层序遍历(一层层)——
 */

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int TElemType;
/* 
存储结构
 */
#define MAXSIZE 100     //最大结点数
//顺序结构
typedef TElemType sqBiTree[MAXSIZE];    //0号为存储根结点
sqBiTree bt;
//链式存储
typedef struct BiTNode{
    TElemType data;     //数据域
    struct BiTNode *lchild,*rchild;     //左右孩子指针
}BiTNode,*BiTree;

/* 
创建二叉树(输入0创建空树)
 */
Status createBiTree(BiTree *T){
    TElemType e;
    scanf("%d",&e);
    if(e == 0){
        *T = NULL;
    }else{
        *T = (BiTree) malloc (sizeof(BiTNode));
        if(!T){
            exit(OVERFLOW);
        }
        (*T)->data = e;
        createBiTree(&(*T)->lchild);    //创建左子树
        createBiTree(&(*T)->rchild);    //创建右子树
    }
    return OK;
}

/* 
访问元素
 */
void visit(TElemType e){
    printf("%d ",e);
}

/* 
先序遍历
 */
Status preOrderTraverse(BiTree T,void (*visit)(TElemType)){
    if(T){
        visit(T->data);
        preOrderTraverse(T->lchild,visit);
        preOrderTraverse(T->rchild,visit);
    }
}

/* 
中序遍历
 */
Status inOrderTraverse(BiTree T,void (*visit)(TElemType)){
    if(T){
        inOrderTraverse(T->lchild,visit);
        visit(T->data);
        inOrderTraverse(T->rchild,visit);
    }
}

/* 
后序遍历
 */
Status postOrderTraverse(BiTree T,void (*visit)(TElemType)){
    if(T){
        postOrderTraverse(T->lchild,visit);
        postOrderTraverse(T->rchild,visit);
        visit(T->data);
    }
}

/* 
主函数测试
 */
int main(){
    BiTree T;
    printf("创建树，输入0为空树：\n");
    createBiTree(&T);
    printf("先序遍历：");
    preOrderTraverse(T,visit);
    printf("\n中序遍历：");
    inOrderTraverse(T,visit);
    printf("\n后序遍历：");
    postOrderTraverse(T,visit);
    printf("\n");

    return 0;
}