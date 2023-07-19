<b>Program to implement stack using linked list.</b>
<pre class="language-c match-braces line-numbers"><code>#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

struct Node {
	int data;
	struct Node * next;
	}* top = NULL;

void push(int);
void pop();
void display();

int main() {
	int choice, value;
	printf("\nIMPLEMENTING STACKS USING LINKED LISTS\n");
	while (1) {
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("\nEnter your choice : ");
		scanf("%d", & choice);
			switch (choice) {
				case 1:
					printf("\nEnter the value to insert: ");
					scanf("%d", & value);
					push(value);
					break;
				case 2:
					pop();
					break;
				case 3:
					display();
					break;
				case 4:
					exit(0);
					break;
				default:
					printf("\nInvalid Choice\n");
			}
	}
}
void push(int value) {
	struct Node * newNode;
	newNode = (struct Node * ) malloc(sizeof(struct Node));
	newNode -&gt; data = value;
	if (top == NULL)
		newNode -&gt; next = NULL;
	else
		newNode -&gt; next = top;
		top = newNode;
		printf("Node is Inserted\n\n");
}
void pop() {
	if (top == NULL)
		printf("\nEMPTY STACK\n");
	else {
		struct Node * temp = top;
		printf("\nPopped Element : %d", temp -&gt; data);
		printf("\n");
		top = temp -&gt; next;
		free(temp);
	}
}
void display() {
	if (top == NULL)
		printf("\nEMPTY STACK\n");
	else {
		printf("The stack is: ");
		struct Node * temp = top;
			while (temp -&gt; next != NULL) {
				printf("%d---&gt;", temp -&gt; data);
				temp = temp -&gt; next;
			}
		printf("%d---&gt;NULL\n\n", temp -&gt; data);
		}
}
</code></pre>