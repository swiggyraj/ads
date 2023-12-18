#include<stdio.h>
#include<stdlib.h>

    struct node * f = NULL;
    struct node * r = NULL;
struct node{
    int data;
    struct node * next;
};

int isFull ( struct node * f , struct node * r ){
    struct node * n = (struct node *) malloc(sizeof(struct node));
    if(n==NULL){
        return 1 ;
    }
    else {
        return 0;
    }
}

int isEmpty ( struct node * f , struct node * r ){
    struct node * n = (struct node *) malloc(sizeof(struct node));
    if(n==NULL){
        return 1 ;
    }
    else {
        return 0;
    }
}

void enque (  int val){
    struct node * n = (struct node *) malloc(sizeof(struct node));
    if(n==NULL){
        printf("Queue is full cannot insert");
    }
    else {
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}

int deque (){
    int val = -1 ;
    struct node * ptr = f ;
    if(f==NULL){
        printf("stack is empty cannot delete element feom stack \n");
    }
    else{
        f=f->next;
        val =  ptr->data;
        free(ptr);
    }
        return val;
}

void print(struct node * ptr){
    while(ptr!= NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main(int argc, char const *argv[])
{
    printf("dequing element %d\n",deque());
    enque(43);
    enque(42);
    enque(47);
    print(f);
    int a = deque();
    printf("After deque %d\n",a);

    print(f);
   
    return 0;
}
