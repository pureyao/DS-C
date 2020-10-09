/* 顺序表存储
初始化——initList(SqlList *L)
销毁——destroyList(SqlList *L)
重置为空表——clearList(SqlList *L)
判断是否为空——isEmpty(const SqlList L)
获取长度——getLength(const SqlList L)
根据位置获取元素——getElem(const SqlList L,int i,ElemType *e)        *e:获取到的元素
对比元素——compare(ElemType e1,ElemType e2)      e1:元素1,e2:元素2
查找元素——findElem(const SqlList L,ElemType *e,Status *(compare(ElemType e1,ElemType e2)))      compare:对比元素（状态）
获取前驱元素——preElem(const SqlList L,ElemType cur_e,ElemType *pre_e)       cur_e:元素,pre_e:前驱元素
获取后继元素——nextElem(const SqlList L,ElemType cur_r,ELemType *next_e)     cur_e:元素,next_e:后继元素
插入元素——insertElem(SqlList *L,int i,ElemType e)       i:插入位置
删除元素——deleteElem(SqlList *L,int i,ElemType *e)       i:删除位置,*e:删除的元素
访问元素——visit(ElemType e)
遍历元素——traverseList(const SqlList L,void *(visit)(ElemType))     visit:输出元素
 */
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

#define OK 1                //宏定义——函数执行结果
#define ERROR 0

#define INIt_SIZE 10        //初始化表长
#define INCREMENT_SIZE 5    //分配增量

typedef int Status;         //typedef——别名
typedef int ElemType;

/* 
存储结构
 */
typedef struct{
    ElemType *elem;         //存储空间基址
    int length;             //当前长度——元素个数
    int size;              //当前分配的表长大小
}SqlList;

/* 
初始化空线性表
 */
Status initList(SqlList *L){
    L->elem = (ElemType *) malloc (INIt_SIZE*sizeof(ElemType));       //malloc申请空间
    if (!L->elem){
        return ERROR;
    }
    L->length = 0;       //初始化表长
    L->size = INIt_SIZE;//初始化表长
    return OK;    
}

/* 
销毁线性表
 */
Status destroyList(SqlList *L){
    free(L->elem);      //释放内存
    L->length = 0;
    L->size = 0;
    return OK;
}

/* 
清空线性表
 */
Status clearList(SqlList *L){
    L->length = 0;
    return OK;
}

/* 
判断线性表是否为空
 */
Status isEmpty(const SqlList L){
    if (0 == L.length){
        return TRUE;
    }
    else{
        return FALSE;
    }   
}

/* 
获取长度
 */
Status getLength(const SqlList L){
    return L.length;
}

/* 
根据位置获取元素
 */
Status getElem(const SqlList L,int i,ElemType *e){
    if (i<1||i>L.length){
        return ERROR;
    }
    *e = L.elem[i];
    return OK;
}

/* 
比较两个元素是否相同
 */
Status compare(ElemType e1,ElemType e2){
    if (e1 == e2){
        return 0;
    }
    else if (e1 < e2){
        return -1;
    }else
    {
        return 1;
    }
}

/* 
查找元素
 */
Status findElem(const SqlList L,ElemType e,Status (*compare)(ElemType,ElemType)){
    int i;
    for (i = 0; i < L.length; i++){
        if (!(*compare)(L.elem[i],e)){
            return i+1;
        }
    }
    if (i>=L.length){
        return ERROR;
    }
}

/* 
查找前驱元素
 */
Status preElem(const SqlList L,ElemType cur_e,ElemType *pre_e){     //cur_e元素，pre_e前驱元素
    int i;
    for (i = 0; i < L.length; i++){
        if (cur_e == L.elem[i]){
            if (i!=0){
                *pre_e = L.elem[i-1];
            }
            else{
                return ERROR;
            }            
        }   
    }
    if (i>=L.length)
    {
        return ERROR;
    }
}

/* 
查找后继元素
 */
Status nextElem(const SqlList L,ElemType cur_e,ElemType *next_e){
    int i;
    for (i = 0; i < L.length; i++){
        if (cur_e == L.elem[i]){
            if (i != L.length){
                *next_e = L.elem[i+1];
                return OK;
            }else{
                return ERROR;
            }    
        }
    }
    if (i>=L.length)
    {
        return ERROR;
    }
    
}

/* 
插入元素
 */
Status insertElem(SqlList *L,int i,ElemType e){
    ElemType *new;               //新基址
    if (i<1||i>L->length+1){
        return ERROR;
    }
    // 存储空间不足，增加空间
    if (L->length >= L->size){
        new = (ElemType*) realloc (L->elem,(L->size+INCREMENT_SIZE)*sizeof(ElemType));
        if (!new){
            return ERROR;
        }
        L->elem = new;
        L->size += INCREMENT_SIZE;        
    }
    // 后面的元素位置后移
    ElemType *p = &L->elem[i-1];
    ElemType *q = &L->elem[L->length - 1];
    for (; q>=p; q++){
        *(q+1) = *q;
    }
    *p = e;
    ++L->length;            //表长+1
    return OK;  
}

/* 
删除元素并返回其值
 */
Status deleteElem(SqlList *L,int i,ElemType *e){
    if (i<1||i>L->length){
        return ERROR;
    }
    ElemType *p = &L->elem[i-1];
    *e = *p;
    for (; p < &L->elem[L->length-1]; p++){
        *p = *(p+1);
    }
    --L->length;
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
Status traverseList(const SqlList L,void (*visit)(ElemType)){
    int i;
    for (i = 0; i < L.length; i++){
        visit(L.elem[i]);
    }
    return OK;
}

/* 
主函数测试
 */
int main(){
    SqlList L;
    if (initList(&L)){                  //初始化
        ElemType e;
        printf("init_success\n");
        int i;
        for (i = 0; i < 10; i++){
            insertElem(&L,i+1,i);       //插入元素
        }
        printf("length is %d\n",getLength(L));  //获取长度

        if (getElem(L,1,&e)){          //获取第一个元素
            printf("the first elem is:%d\n",e);
        }else{
            printf("elem is not exist\n");
        }
        if (isEmpty(L)){              //判断是否为空表
            printf("list is empty\n");
        }else{
            printf("list is not empty\n");
        }
        
        printf("the 5 at %d\n",findElem(L,5,*compare));     //查找元素

        preElem(L,5,&e);
        printf("the pre_e of 5 is:%d\n",e);        //前驱元素
        
        nextElem(L,5,&e);
        printf("the next_e of 5 is:%d\n",e);       //后继元素

        deleteElem(&L,1,&e);          //删除元素并返回
        printf("delete first element is:%d\n",e);

        printf("list:");
        traverseList(L,visit);        //遍历线性表
        printf("\n");

        if (destroyList(&L)){         //销毁线性表
            printf("destroy success\n");
        }
    }
    
}