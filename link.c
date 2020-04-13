#include<stdio.h>
#include<stdlib.h>

typedef struct Link{
    int elem;
    struct Link *next;
}Link;

Link * initLink();
//链表插入的函数，p是链表，elem是插入的数据域，add是插入到的位置
Link *insertElem(Link *p,int elem,int add);
//删除结点函数，p是链表，add是删除函数的位置
Link *delElem(Link *p,int add);
//更新结点的函数，newElem是新的数据域的值
Link *amendElem(Link *p,int add,int newElem);
//查找结点的函数，elem为目标结点的数据域的值
int selectElem(Link *p,int elem);
void display(Link *p);

int main(){
    //初始化链表（1,2,3,4）
    printf("初始化链表为：\n");
    Link *p=initLink();
    display(p);

    printf("在第4的位置插入元素5：\n");
    p=insertElem(p,5,4);
    display(p);

    printf("删除元素3：\n");
    p=delElem(p,3);
    display(p);

    printf("查找元素2的位置：\n");
    int address=selectElem(p,2);
    if(address==-1){
        printf("没有该元素");
    }else{
        printf("元素2的位置：%d\n",address);
    }

    printf("更改第3的位置上的数据为7：\n");
    p=amendElem(p,3,7);
    display(p);

    return 0;

}

Link *initLink(){
    Link *p=(Link*)malloc(sizeof(Link));     //
    Link *t=p;
    for(int i=1;i<5;i++){
        Link *a=(Link*)malloc(sizeof(Link));
        a->elem=i;
        a->next=NULL;
        t->next=a;
        t=t->next;
    }
    return p;
}

Link *insertElem(Link *p,int elem,int add){
    Link *temp=p;//创建一个临时结点
    //首先找到插入位置的上一个结点
    for(int i=1;i<add;i++){
        if(temp==NULL){
            printf("插入位置无效\n");
            return p;
        }
        temp=temp->next;
    }
    //创建插入结点c
    Link *c=(Link *)malloc(sizeof(Link));
    c->elem=elem;
    //向链表中插入结点
    c->next=temp->next;
    temp->next=c;
    return p;
}

Link *delElem(Link *p,int add){
    Link *temp=p;
    //遍历到被删除结点的上一个结点
    for(int i=1;i<add;i++){
        temp=temp->next;
    }
    Link *del=temp->next;
    temp->next=temp->next->next;//单独设置一个指针指向被删除结点，以防止丢失
    free(del);  //手动释放该结点，防止内存泄露
    return p;
}

Link *amendElem(Link *p,int add,int newElem){
    Link *temp=p;
    for(int i=1;i<add;i++){
        temp=temp->next;
    }
    Link *d=(Link*)malloc(sizeof(Link));
    d->elem=newElem;
    return p;
}

int selectElem(Link *p,int elem){
    Link *temp=p;
    int i=1;
    while(temp->next){
       temp=temp->next;
        if(temp->elem==elem){
            return i;
        }
        i++;
    }
    return -1;
}

//void display(Link *p);
void display(Link *p){
    Link* temp=p;
    while(temp->next){
        temp=temp->next;
        printf("%d ",temp->elem);
    }
    printf("\n");
}