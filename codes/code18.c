<b>Write a menu driven program to implement array based queue showing following operations.</b>
<ul>
<li>Creating queue stack</li>
<li>Enqueue()</li>
<li>Dequeue()</li>
<li>Underflow</li>
<li>Overflow</li>
<li>Exit</li></ul>
<pre class="language-c match-braces line-numbers"><code>#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#define size 50
int queue[size];
int front,rear,N;
int isFull(){
        if(rear==(N-1))
        return 1;
        else
        return 0;
}
int isEmpty(){
    if(front==-1&&rear==-1)
    return 1;
    else
    return 0;
}
void create_Queue(){
        printf("Enter the size of the queue\n");
        scanf("%d",&N);
        front=-1; rear=-1;
    printf("size of the queue is %d\n",N);
}
void Enqueue(int x){
        if(isFull()==1)
        printf("OVERFLOW CONDITION");
    else if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
void Dequeue(){
        if(isEmpty()==1)
        printf("UNDERFLOW CONDITION");
        
    else if(front==rear){
        front=rear=-1;
    }
    else{
        printf("element deleted from the queue is %d ",queue[front]);
        front++;
    }
}
void Display(){
        if(isEmpty()==1)
        printf("UNDERFLOW CONDITION");
    else{
        printf("the data in the queue is as follows\n");
        for(int i=front;i&lt;rear+1;i++)
        printf("%d\t",queue[i]);
    }
}

void main(){
   int n,data;
    do{
       printf("enter your choice of QUEUE OPERATIONS\n");
       printf("1.Creating a an empty QUEUE\n");
       printf("2.Enqueue()\n");
       printf("3.Dequeue()\n");
       printf("4.Display contents of the QUEUE\n");
       printf("5.Check UNDERFLOW condition\n");
       printf("6.Check OVERFLOW condition\n");
       printf("0.Exit\n");
       scanf("%d",&n);
    switch(n){
        case 1: create_Queue();
                break;
        case 2: printf("enter data you want to insert in the queue");
                scanf("%d",&data);
                Enqueue(data);
                break;

        case 3: Dequeue();
                break;

        case 4: Display();
                break;

        case 5: isEmpty();
                break;
        case 6: isFull();
                break;
        case 0: exit(0);
                break;
        default:break;
    }
    }while(n!=0);   
}
</code></pre>