/* 
链式结构——单链表
初始化线性表——initList(LinkList *L)
销毁线性表——destroyList(LinkList *L)
判断是否为空——isEmpty(LinkList L)
插入元素——insertElem(LinkList L,int i,ElemType e)
获取指定位置元素——getElem(LinkList L,int i,ElemType *e)
线性表长度——getLingth(LinkList L)
对比元素——compare(ElemType e1,ElenType e2)
查找元素——findElem(LinkList L,ElemType e,Status (*compare)(ElemType,ElemType))
获取前驱元素——preElem(LinkList L,ElemType cur_e,ELemType *pre_e)
获取后继元素——nextElem(LinkList L,ElemType cur_e,ELemType *next_e)
删除元素——deleteElem(LinkList L,int i,ElemType *e)
访问元素——visit(ElemType e)
遍历链表——traverseList(LinkList L,void (*visit)(ElemType))
 */
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

/* 
存储结构
 */
typedef struct LNode{
    ElemType data;          //数据域
    struct LNode *next;     //指针域
}LNode , *LinkList;           //*LinkList为LNode类型指针  LNode *p === LinkList p

/* 
初始化线性表
 */
void initList(LinkList *L){
    *L = (LinkList) malloc (sizeof(LNode));
    if (!L){
        exit(OVERFLOW);
    }
    (*L)->next = NULL;      //头结点指针域置空
}

/* 
销毁线性表
 */
void destroyList(LinkList *L){
    LinkList temp;          //创建空表
    while (*L){
        temp = (*L)->next;  
        free(*L);           //释放原表空间
        *L = temp;          //空表赋值给原表
    }
    
}

/* 
清空线性表
 */
void clearList(LinkList L){
    LinkList p = L->next;
    L->next = NULL;
    destroyList(&p);
}

/* 
判断是否为空
 */
Status isEmpty(LinkList L){
    if (L->next){
        return FALSE;
    }else{
        return TRUE;
    }    
}

/* 
获取列表长度
 */
int getLength(LinkList L){
    int i=0;
    LinkList p = L->next;
    while (p){
        i++;
        p = p->next;
    }
    return i;   
}

/* 
根据位置获取元素
 */
Status getElem(LinkList L,int i,ElemType *e){
    int j = 1;
    LinkList p = L->next;
    while (p && j<i){
        j++;
        p = p->next;
    }
    if(!p || j>i){
        return ERROR;
    }
    *e = p->data;
    return OK;
}

/* 
比较两个元素是否相等
 */
Status compare(ElemType e1,ElemType e2){
    if (e1 == e2){
        return 0;
    }else if (e1 < e2)
    {
        return -1;
    }else{
        return 1;
    }
}

/* 
查找指定元素位置
 */
int findElem(LinkList L,ElemType e,Status (*compare)(ElemType,ElemType)){
    int i = 0;
    LinkList p = L->next;
    while (p){
        i++;
        if (!compare(p->data,e)){
            return i;
        }
        p = p->next;
    }
    return 0;    
}

/* 
获取前驱元素
 */
Status preELem(LinkList L,ElemType cur_e,ElemType *pre_e){
    LinkList q,p = L->next;
    while (p->next){
        q = p->next;
        if (q->data == cur_e){
            *pre_e = p->data;
            return OK;
        }
        p=q;
    }
    return ERROR;
}

/* 
获取后继元素
 */
Status nextELem(LinkList L,ElemType cur_e,ElemType *next_e){
    LinkList p = L->next;
    while (p->next){
        if (p->data == cur_e){
            *next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

/* 
插入元素
 */
Status insertElem(LinkList L,int i,ElemType e){
    int j = 0;
    LinkList s,p=L;
    while (p && j<i-1){
        j++;
        p = p->next;
    }
    if (!p || j>i-1){
        return ERROR;
    }
    s = (LinkList) malloc (sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;   
}

/* 
删除元素并返回元素值
 */
Status deleteElem(LinkList L,int i,ElemType *e){
    int j = 0;
    LinkList q,p = L;
    while (p->next && j<i-1){
        j++;
        p = p->next;
    }
    if (!p->next || j>i-1){
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;    
}

/* 
访问元素
 */
void visit(ElemType e){
    printf("%d",e);
}

/* 
遍历线性表
 */
void traverseList(LinkList L,void (*visit)(ElemType)){
    LinkList p = L->next;
    while (p){
        visit(p->data);
        p = p->next;
    }
}

/* 
主函数测试
 */
int main(){
    LinkList L;
    initList(&L);           //初始化
    ElemType e;
    int i;
    if (L){
        printf("init success\n");
    }
    if (isEmpty(L)){        //判断是否为空
        printf("List is empty\n");
    }else{
        printf("List is not empty\n");
    }
    for (i = 0; i < 10; i++){
        insertElem(L,i+1,i);    //插入元素
    }
    if (getElem(L,1,&e)){       //获取指定位置元素
        printf("the first element is :%d\n",e);     
    }
    printf("length is:%d\n",getLength(L));    //线性表长度
    
    printf("the 5 at :%d\n",findElem(L,5,*compare));             //查找元素

    preELem(L,5,&e);        //获取前驱元素
    printf("the pre of 5 is :%d\n",e);

    nextELem(L,5,&e);       //获取后继元素
    printf("the next of 5 is :%d\n",e);

    deleteElem(L,1,&e);     //删除元素
    printf("the delete elem is :%d\n",e);

    printf("list:");
    traverseList(L,*visit);  //遍历线性表
    printf("\n");

    destroyList(&L);            //销毁线性表
    if (!L){
        printf("destroy_success\n");
    }
}