<b>Program to implement queue using arrays.</b>
<pre class="language-c match-braces line-numbers"><code>#include &lt;stdio.h&gt;
#define n 5

int main() {
    int queue[n], ch = 1, front = 0, rear = 0, i, j = 1, x = n;
    printf("\tQueue using Array");
    printf("\n\t1.Insertion \n\t2.Deletion \n\t3.Display \n\t4.Exit");
    while (ch) {
        printf("\n\nEnter the Choice: ");
        scanf("%d", & ch);
        switch (ch) {
        case 1:
            if (rear == x)
                printf("\n Queue is Full");
            else {
                printf("\n Enter no %d : ", j++);
                scanf("%d", & queue[rear++]);
            }
            break;
        case 2:
            if (front == rear) {
                printf("\n Queue is empty");
            } else {
                printf("\n Deleted Element is: %d", queue[front++]);
                x++;
            }
            break;
        case 3:
            printf("\nQueue Elements are: \n ");
            if (front == rear)
                printf("\n Queue is Empty");
            else {
                for (i = front; i &lt; rear; i++) {
                    printf("%d", queue[i]);
                    printf("\n");
                }
                break;
                case 4:
                    exit(0);
                default:
                printf("Wrong Choice: please see the options");
            }
        }
    }
    return 0;
}
</code></pre>