#include<stdio.h>
#include<stdlib.h>

typedef struct line{
    struct line *prior;
    int data;
    struct line *next;
}line;
//双链表的创建
line* initLine(line * head);
//双链表插入元素，add表示插入位置
line* insertLine(line* head,int data,int add);
//双链表删除指定元素
line* delLine(line* head,int data);
//双链表中查找制定元素
int selectElem(line* head,int elem);
//双链表中更改指定位置结点中存储的数据，add表示更改位置
line* amendElem(line* head,int add,int newElem);
//输出双链表的实现函数
void display(line* head);

int main(){
    line* head=NULL;
    //创建双链表
    head=initLine(head);
    display(head);
    //在表中第3的位置插入元素7
    head=insertLine(head,7,3);
    //表删中删除元素2
    head=delLine(head,2);
     display(head);

     printf("元素3的位置是：%d\n",selectElem(head,3));
    //表中第个结点重点数据改为存储6
    head=amendElem(head,3,6);
    display(head);
    return 0;
}

line* initLine(line* head){
    head=(line*)malloc(sizeof(line));
    head->prior=NULL;
    head->next=NULL;
    head->data=1;
    line* list=head;
    for(int i=2;i<=5;i++){
        line* body=(line*)malloc(sizeof(line));
        body->prior=NULL;
        body->next=NULL;
        body->data=i;

        list->next=body;
        body->prior=list;
        list=list->next;
    }
    return head;
}
line* insertLine(line* head,int data,int add){
    //新建数据域为data的结点
    line* temp=(line*)malloc(sizeof(line));
    temp->prior=NULL;
    temp->next=NULL;
    temp->data=data;
    if(add==1){
         //插入到表头，要特殊考虑
        temp->next=head;
        head->prior=temp;
        head=temp;
    }else{
        line* body=head;
        //找到要插入的位置的前一个结点
        for(int i=1;i<add-1;i++){
            body=body->next;
        }
        //判断条件为真，说明插入位置为链表尾
        if(body->next==NULL){
            body->next=temp;
            temp->prior=body;
        }else{
            temp->next=body->next;
            body->next=temp;
            temp->prior=body;
            body->next->prior=temp;
        }
           
    }
    return head;
}
line* delLine(line* head,int data){
    line* temp=head;
    //遍历链表
    while(temp){
        if(data==temp->data){
            temp->next->prior=temp->prior;
            temp->prior->next=temp->next;
            free(temp);
            return head;
        }
        temp=temp->next;
    }
    printf("链表中无该数据元素");
    return head;
}
//head为原双链表，elem表示被查找元素
int selectElem(line* head,int elem){
    line* temp=head;
    int i=1;
    while(temp){
        if(elem==temp->data){
            return i;
        }
        i++;
        temp=temp->next;
    }
    //程序执行至此处，表示查找失败
    return -1;
}
//更新函数，其中，add表示更改结点在双链表中的位置，newElem为新数据的值
line* amendElem(line* head,int add,int newElem){
    line*temp=head;
    //遍历到被删除结点
    for(int i=1;i<add;i++){
        temp=temp->next;
    }
    temp->data=newElem;
    return head;
}
//输出链表的功能函数
void display(line* head){
    line* temp=head;
    while(temp){
        if(temp->next==NULL){
            printf("%d\n",temp->data);
        }else
        {
            printf("%d->",temp->data);
        }
        temp=temp->next;
    }
}