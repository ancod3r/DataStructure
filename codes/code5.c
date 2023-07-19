<b>Program to implement stack using arrays.</b>
<pre class="language-c match-braces line-numbers"><code>#include &lt;stdio.h&gt;

int stack[100], choice, n, top, x, i;
void push(void);
void pop(void);
void display(void);
int main() {
    //clrscr();
    top = -1;
    printf("\n Enter the size of STACK[MAX=100]: ");
    scanf("%d", & n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    do {
        printf("\n Enter the Choice: ");
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
            printf("\n\t**** EXIT ****");
            break;
        default: 
            printf("\n\t Please Enter a Valid Choice(1/2/3/4)");
        }
    } while (choice != 4);
			return 0;
}
void push() {
    if (top &gt;= n - 1) {
        printf("\n\tSTACK is over flow");
    } else {
        printf(" Enter a value to be pushed: ");
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
        printf("\n The elements in STACK: ");
        for (i = top; i &gt;= 0; i--)
            printf("\n%d", stack[i]);
        printf("\n Press Next Choice");
    } else {
        printf("\n The STACK is empty");
    }
}
</code></pre>