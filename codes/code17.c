<b>Write a menu driven program to implement array based stack showing following operations.</b>
<ul>
<li>Creating an Empty Stack</li>
<li>Push()</li>
<li>Pop()</li>
<li>Peek()</li>
<li>Underflow</li>
<li>Overflow</li>
<li>Exit</li></ul>
<pre class="language-c match-braces line-numbers"><code>#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#define size 50
int stack[size];
int N,i,top;
int isEmpty(){
    if(top==-1)
    return 1;
    else{
        return 0;
    }
}
int isFull(){
    
    if(top==N-1)
    return 1;
    else{
        return 0;
    }
}
void create_Stack(){
    printf("Enter the size of the stack\n");
    scanf("%d",&N);
    top=-1;
    printf("size of the stack is %d\n",N);
}
void Push(){
    int x;
    printf("enter data you want to insert in the stack");
    scanf("%d",&x);
    if(isFull()==1)
    /*if(top==4)*/
    printf("\nOVERFLOW CONDITION\n");
    else{
        top+=1;
        stack[top]=x;
    }
}
void Pop(){
    int delvalue;
    if(isEmpty()==1)
    /*
    if(top==-1)*/
    printf("\nUNDERFLOW CONDITION\n");
    else{
        delvalue=stack[top];
        top--;
    }
    printf("\nthe value deleted from the stack is %d \n",delvalue);
}
void Peek(){
    int topvalue;
    
    if(isEmpty()==1)
    printf("\nUNDERFLOW CONDITION\n");
    else{
        topvalue=stack[top];
         printf("\nthe value at the top of the stack is %d \n",topvalue);
    }
}
void Display(){
    printf("these are the elements present in the stack\n");
    for(int i=top;i&gt;=0;i--){
        printf("%d \t",stack[i]);
    }
}

void main()
{   int n;
    do{
       printf("enter your choice of STACK OPERATIONS\n");
       printf("1.Creating a an empty stack\n");
       printf("2.Push()\n");
       printf("3.Pop()\n");
       printf("4.Peek()\n");
       printf("5.Display contents of the stack\n");
       printf("6.Check UNDERFLOW condition\n");
       printf("7.Check OVERFLOW condition\n");
       printf("0.Exit\n");
       scanf("%d",&n);
    switch(n){
        case 1: create_Stack();
                break;
        case 2: Push();
                break;

        case 3: Pop();
                break;

        case 4: Peek();
                break;

        case 5: Display();
                break;

        case 6: isEmpty();
                break;
        case 7: isFull();
                break;
        case 0: exit(0);
                break;
        default:break;
    }
    }while(n!=0);
}
</code></pre>