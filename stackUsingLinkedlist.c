#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next ;
};

struct node * top = NULL;

int isEmpty(struct node * top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
    
};

void linkedListTraversal(struct node * ptr){
    while(ptr != NULL){
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }
}

int isFull(struct node * top){
    struct node * p = (struct node *)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }

};

struct node * push(struct node * top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct node * n = (struct node*)malloc(sizeof(struct node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
}

int pop(struct node * tp){
    if(isEmpty(tp)){
        printf("Stack underflow\n");
    }
    else{
        struct node * n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int pos){
    struct node * ptr = top;
    for(int i=0;(i<pos-1 && ptr!=NULL);i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL)
      return ptr -> data;
    else 
      return -1;
}

int stackTop(struct node * top ){
    return top->data;
}

int stackBottom(struct node * top){
    while(top!=NULL && top->next != NULL){
        top=top->next;
    }
    return top->data;
}

int main(int argc, char const *argv[])
{
    
    top= push(top,5);
    top= push(top,29);
    top= push(top,69);
    linkedListTraversal(top);
    int element = pop(top);
    printf("Poped element is %d\n",element);
    linkedListTraversal(top);  
    int peekElement = peek(2);
    printf("peek element is %d\n",peekElement); 
    int stacktop= stackTop(top);
    printf("stack top is %d\n",stacktop);
    int stackbottom = stackBottom(top);
    printf("Stack bottom is %d\n",stackbottom);
    return 0;
}
