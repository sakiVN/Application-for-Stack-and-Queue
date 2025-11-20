#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

Node* top;// point to the top of the stack
Node* makeNode(int x)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = x;
    p->next = NULL;
    return p;
}

void initStack()
{
    top = NULL;
}
int stackEmpty()
{
    return top == NULL;
}
int pop()
{
    if(stackEmpty()) return ' ';
    int x = top->value;
    Node* p = top;
    top = top->next;
    free(p);
    return x;
}
void push(int x)
{
    Node* p = makeNode(x);
    p->next = top;
    top = p;
}
int main()
{
    char cmd[0];
    while(1)
    {
        scanf("%s",cmd);
        if(strcmp(cmd,"#")==0)
        {
            break;
        }
        else if(strcmp(cmd,"PUSH")==0)
        {
            int v;
            scanf("%d",&v);
            push(v);
        }
        else if(strcmp(cmd,"POP")==0)
        {
            if(stackEmpty()) // Not neccesary
            {
                printf("NULL\n");
            }
            else
            {
                int v = pop();
                printf("%d\n",v);
            }
        }
    }
    return 0;
}
