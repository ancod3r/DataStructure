<b>Program to implement circular queue using arrays.</b>
<pre class="language-c match-braces line-numbers"><code>#include &lt;stdio.h&gt;
# define max 6
int queue[max]; 		// array declaration  
int front = -1;
int rear = -1;
// function to insert an element in a circular queue  
void enqueue(int element) {
    if (front == -1 && rear == -1) { 		// condition to check queue is empty  
        front = 0;
        rear = 0;
        queue[rear] = element;
    } else if ((rear + 1) % max == front) {		// condition to check queue is full  
        printf("/nQueue is overflow../n");
    } else {
        rear = (rear + 1) % max; 		// rear is incremented  
        queue[rear] = element; 			// assigning a value to the queue at the rear position.  
    }
}
// function to delete the element from the queue  
int dequeue() {
    if ((front == -1) && (rear == -1)) {		// condition to check queue is empty
        printf("\nQueue is underflow..\n");
    } else if (front == rear) {
        printf("\nThe dequeued element is: %d", queue[front]);
        front = -1;
        rear = -1;
    } else {
        printf("\nThe dequeued element is: %d", queue[front]);
        front = (front + 1) % max;
    }
}
// function to display the elements of a queue  
void display() {
    int i = front;
    if (front == -1 && rear == -1) {
        printf("\n Queue is empty..\n");
    } else {
        printf("\nElements in a Queue are : ");
        while (i &lt;= rear) {
            printf("%d\t", queue[i]);
            i = (i + 1) % max;
        }
    }
}
int main() {
    int choice = 1, x; // variables declaration  
    while (choice &lt; 4 && choice != 0) {
        printf("\n1. Insert an element");
        printf("\n2. Delete an element");
        printf("\n3. Display the element");
        printf("\n4. EXIT");
        printf("\n\nEnter your choice: ");
        scanf("%d", & choice);
        switch (choice) {
        case 1:
            printf("Enter the element which is to be inserted: ");
            scanf("%d", & x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
        case 4:
        	exit(0);
        	break;
        default:
        	printf("\nInvalid Choice\n");
        }
    }
    return 0;
}
</code></pre>