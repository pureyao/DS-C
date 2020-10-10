/* 队列——链式结构
初始化——initQueue(LinkQueue *Q)
销毁队列——destoryQueue(LinkQueue *Q)
清空队列——clearQueue(LinkQueue *Q)
判断队列是否为空——isEmpty(LinkQueue Q)
获取队列长度——getLength(LinkQueue Q)
获取对头元素——getHead(LinkeQueue Q,QElemType *e)
入队——enQueue(LinkQueue *Q,QElemType e)
出队——deQueue(LinkQueue *Q,QElelmType *e)
访问元素——visit(QElemType e)
遍历队列——traverseQueue(LinkQueue Q,void(*visit)(QElemType))
 */
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int QElemType;
typedef int Status;

/* 
存储结构
 */
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr front; //对头指针
    QueuePtr rear;  //队尾指针
} LinkQueue;

/* 
初始化队列
 */
Status initQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front)
    { //判断是否溢出
        exit(OVERFLOW);
    }
    Q->front->next = NULL;
    return OK;
}

/* 
销毁队列
 */
Status destroyQueue(LinkQueue *Q)
{
    while (Q->front)
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

/* 
清空队列
 */
Status clearQueue(LinkQueue *Q)
{
    destroyQueue(Q);
    initQueue(Q);
    return OK;
}

/* 
判断队列是否为空
 */
Status isEmpty(LinkQueue Q)
{
    if (Q.front->next == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/* 
获取队列长度
 */
int getLength(LinkQueue Q)
{
    int i=0;
    QueuePtr p = Q.front;
    while (Q.rear != p)
    {
        i++;
        p = p->next;
    }
    return i;
}

/* 
获取对头元素
 */
Status getHead(LinkQueue Q, QElemType *e)
{
    QueuePtr p;
    if (Q.front == Q.rear)
    {
        return ERROR;
    }
    p = Q.front->next;
    *e = p->data;
    return OK;
}

/* 
入队
 */
Status enQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
    {
        exit(OVERFLOW);
    }
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

/* 
出队
 */
Status deQueue(LinkQueue *Q, QElemType *e)
{
    QueuePtr p;
    if (Q->front == Q->rear)
    {
        return ERROR;
    }
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
    {
        Q->rear = Q->front;
    }
    free(p);
    return OK;
}

/* 
访问元素
 */
void visit(QElemType e)
{
    printf("%d", e);
}

/* 
遍历队列
 */
Status traverseQueue(LinkQueue Q, void (*visit)(QElemType))
{
    QueuePtr p = Q.front->next;
    while (p){
        visit(p->data);
        p = p->next;
    }
    return OK;
}

/* 
测试主函数
 */
int main()
{
    LinkQueue Q;
    if (initQueue(&Q)){ //初始化队列
        printf("init_success\n");
        QElemType e;
        int i;

        if (isEmpty(Q)){        //判断是否为空
            printf("the queue is empty\n");
        }else{
            printf("the queue is not empty\n");
        }

        for (i = 0; i < 10; i++){
            enQueue(&Q,i);      //入队
        }
        

        getHead(Q, &e);      //获取对头元素
        printf("the head of queue is:%d\n",e);

        printf("the length of queue is %d\n",getLength(Q));     //获取队长

        deQueue(&Q,&e);     //出队
        printf("delete element is :%d\n",e);

        traverseQueue(Q,*visit);        //遍历队
        printf("\n");

        clearQueue(&Q);         //清空队
        traverseQueue(Q,*visit);
        printf("\n");

        if (destroyQueue(&Q)){      //销毁队列
            printf("destroy_success\n");
        }
    }
}