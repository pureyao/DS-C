/* 栈的顺序存储
初始化栈——initStack(sqStack *S)
销毁栈——destroyStack(sqStack *S)
清空栈——clearStack(sqStack *S)
判断是否为空——isEmpty(sqStack S)
入栈(压栈)——pop(sqStack *S,SElemType e)
出栈——push(sqStack *S,SElemType *e)
获取栈顶——getTop(sqStack S,SElemType *e)
获取栈长——getLength(SqStack S)
访问元素——visit(SElemType e)
遍历栈——traverseStack(sqStack S,void (*visit)(SElemType))
 */
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INITSIZE 20
#define INCREMENT_SIZE 5

typedef int SElemType;
typedef int Status;

/* 
存储结构
 */
typedef struct{
    SElemType *base;        //栈尾指针
    SElemType *top;         //栈顶指针
    int size;               //栈的大小
}sqStack;

/* 
初始化栈
 */
Status initStack(sqStack *S){
    S->base = (SElemType*) malloc (INITSIZE*sizeof(SElemType));
    if (!S->base){
        exit(OVERFLOW);
    }
    //设置栈顶指针初始化在栈尾，栈的大小
    S->top = S->base;
    S->size = INITSIZE;
    return OK;
}

/* 
销毁栈
 */
Status destroyStack(sqStack *S){
    //先释放栈顶指针
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->size = 0;
    return OK;
}

/* 
清空栈
 */
Status clearStack(sqStack *S){
    // 栈顶指针指向栈尾
    S->top = S->base;
    return OK;
}

/* 
判断是否为空
 */
Status isEmpty(sqStack S){
    if (S.top == S.base){
        return TRUE;
    }else{
        return FALSE;
    }   
}

/* 
获取栈的长度
 */
Status getLength(sqStack S){
    return S.top - S.base;
}

/* 
获取栈顶元素
 */
Status getTop(sqStack S,SElemType *e){
    if (S.top == S.base){
        *e = *(--S.top);
        return OK;
    }else{
        return ERROR;
    }    
}

/* 
压栈
 */
Status push(sqStack *S,SElemType e){
    if ((S->top - S->base)/sizeof(SElemType) >= S->size){       //判断栈顶是否还有空间
        S->base = (SElemType*)realloc(S->base,(S->size + INCREMENT_SIZE) * sizeof(SElemType));
        if (!S->base){
            exit(OVERFLOW);
        }
        S->top = S->base + S->size;
        S->size += INCREMENT_SIZE;        
    }
    *S->top = e;        //元素入栈
    S->top++;           //栈顶指针+1
    return OK;
}

/* 
出栈
 */
Status pop(sqStack *S,SElemType *e){
    if (S->top == S->base){         //判断栈是否为空
        return ERROR;
    }
    S->top--;       //栈顶指针下移
    *e = *S->top;   //获取栈顶元素 
    return OK;
}

/* 
访问元素
 */
void visit(SElemType e){
    printf("%d ",e);
}

/* 
遍历栈
 */
Status traverseStack(sqStack S,void (*visit)(SElemType)){
    while (S.top > S.base){
        visit(*S.base);
        S.base++;
    }
    return OK;
}

/* 
    主函数测试
 */
int main(){
    sqStack S;
    if (initStack(&S)){             //初始化
        SElemType e;
        int i;
        printf("init_success\n");

        if (isEmpty(S)){            //判断是否为空
            printf("the stack is empty\n");
        }else{
            printf("the stack is not empty\n");
        }

        for ( i = 0; i < 10; i++){  //入栈
            push(&S,i);
        }        

        getTop(S,&e);               //获取栈顶
        printf("the first element is:%d\n",e);

        printf("the length of stack is:%d\n",getLength(S));     //获取栈长

        pop(&S,&e);        //出栈
        printf("the pop element is:%d\n",e);

        printf("the stack is:");
        traverseStack(S,*visit);        //遍历栈
        printf("\n");

        if (destroyStack(&S)){
            printf("destroy_success\n");
        }
    }   
}