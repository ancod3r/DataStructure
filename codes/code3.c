<b>Programs for Stack, Queues and Circular Queues using Arrays.</b>
<pre class="language-c match-braces line-numbers"><code>#include&lt;stdio.h&gt;

int stack[100], choice, n, top, x, i;
void push(void);
void pop(void);
void display(void);
int main() {
	top = -1;
	printf("\n Enter the size of STACK[MAX=100]:");
	scanf("%d", & n);
	printf("\n\t STACK OPERATIONS USING ARRAY");
	printf("\n\t--------------------------------");
	printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
	do {
		printf("\n Enter the Choice:");
		scanf("%d", & choice);
			switch (choice) {
				case 1:
					push();
					break;
				case 2:
					pop();
					break;
				case 3:
					display();
					break;
				case 4:
					printf("\n\t EXIT POINT ");
					break;
				default:
					printf("\n\t Please Enter a Valid Choice(1/2/3/4)");
			}
	}while (choice != 4);
	return 0;
}
void push() {
	if (top &gt;= n - 1) {
		printf("\n\tSTACK is over flow");
	} else {
		printf(" Enter a value to be pushed:");
		scanf("%d", & x);
		top++;
		stack[top] = x;
		}
}
void pop() {
	if (top &lt;= -1) {
		printf("\n\t Stack is under flow");
	} else {
		printf("\n\t The popped elements is %d", stack[top]);
		top--;
		}
}
void display() {
	if (top &gt;= 0) {
		printf("\n The elements in STACK \n");
		for (i = top; i &gt;= 0; i--)
			printf("\n%d", stack[i]);
		printf("\n Press Next Choice");
	} else {
		printf("\n The STACK is empty");
		}
}

//QUEUES :
/*
#include &lt;stdio.h&gt;
#define MAX 50

void insert();
void delete();
void display();
int queue_array[MAX];
int rear = -1;
int front = -1;
main() {
	int choice;
	while (1) {
		printf("1.Insert element to queue \n");
		printf("2.Delete element from queue \n");
		printf("3.Display all elements of queue \n");
		printf("4.Quit \n");
		printf("Enter your choice : ");
		scanf("%d", & choice);
			switch (choice) {
				case 1:
					insert();
					break;
				case 2:
					delete();
					break;
				case 3:
					display();
					break;
				case 4:
					exit(1);
				default:
					printf("Wrong choice \n");
			}
	}
}
void insert() {
	int add_item;
	if (rear == MAX - 1)
		printf("Queue Overflow \n");
	else {
		if (front == -1)
			//If queue is initially empty
			front = 0;
			printf("Inset the element in queue : ");
			scanf("%d", & add_item);
			rear = rear + 1;
			queue_array[rear] = add_item;
		}
}
void delete() {
	if (front == -1 || front &gt; rear) {
		printf("Queue Underflow \n");
		return;
	} else {
		printf("Element deleted from queue is : %d\n", queue_array[front]);
		front = front + 1;
		}
}
void display() {
	int i;
	if (front == -1)
		printf("Queue is empty \n");
	else {
		printf("Queue is : ");
			for (i = front; i &lt;= rear; i++)
			printf("%d ", queue_array[i]);
    printf("\n");
	}
}
*/

// CIRCULAR QUEUE USING ARRAYS :
/*
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#define MAX 10

int cqueue_arr[MAX];
int front = -1;
int rear = -1;

void display();
void insert(int item);
int del();
int peek();
int isEmpty();
int isFull();

int main() {
	int choice, item;
	while (1) {
		printf("\n1.Insert\n");
		printf("2.Delete\n");
		printf("3.Peek\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("\nEnter your choice: ");
		scanf("%d", & choice);
			switch (choice) {
				case 1:
					printf("\nInput the element for insertion: ");
					scanf("%d", & item);
					insert(item);
					break;
				case 2:
					printf("\nElement deleted is: %d\n", del());
					break;
				case 3:
					printf("\nElement at the front is: %d\n", peek());
					break;	
				case 4:
					display();
					break;
				case 5:
					exit(1);
				default:
					printf("\nWrong choice\n");
			}
	}
	return 0;
}
void insert(int item) {
	if (isFull()) {
		printf("\nQueue Overflow\n");
		return;
	}
	if (front == -1)
		front = 0;
	if (rear == MAX - 1) //rear is at last position of queue
		rear = 0;
	else
		rear = rear + 1;
		cqueue_arr[rear] = item;
}
int del() {
	int item;
	if (isEmpty()) {
		printf("\nQueue Underflow\n");
		exit(1);
	}
	item = cqueue_arr[front];
	if (front == rear) {
		front = -1;
		rear = -1;
	} else if (front == MAX - 1)
			front = 0;
	else
			front = front + 1;
			return item;
}
int isEmpty() {
	if (front == -1)
		return 1;
	else
		return 0;
}
int isFull() {
	if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
		return 1;
	else
		return 0;
}
int peek() {
	if (isEmpty()) {
		printf("\nQueue Underflow\n");
		exit(1);
	}
	return cqueue_arr[front];
}
void display() {
	int i;
	if (isEmpty()) {
		printf("\nQueue is empty\n");
		return;
	}
	printf("\nQueue elements: ");
	i = front;
	if (front &lt;= rear) {
		while (i &lt;= rear)
			printf("%d ", cqueue_arr[i++]);
	} else {
		while (i &lt;= MAX - 1)
			printf("%d ", cqueue_arr[i++]);
			i = 0;
		while (i &lt;= rear)
			printf("%d ", cqueue_arr[i++]);
		}
	printf("\n");
}
*/
</code></pre>