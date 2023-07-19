<b>Program to reverse elements in a queue.</b>
<pre class="language-c match-braces line-numbers"><code>#include &lt;stdio.h&gt;

int f = -1, r = -1;
int q[50];
void enqueue(int data, int l) {		//Enqueue for inserting data
    if (r == l - 1) {
		printf("Queue is full");
    } else if ((f == -1) && (r == -1)) {
        f = r = 0;
        q[r] = data;
    } else {
        r++;
        q[r] = data;
    }
}
void print() {						 //Print function for printing the data
    int i;
    for (i = f; i &lt;= r; i++) {
        printf("\n%d", q[i]);
    }
}
void reverse() {					 //reverse function for reversing the data 
    int i, j, t;
    for (i = f, j = r; i &lt; j; i++, j--) {
        t = q[i];
        q[i] = q[j];
        q[j] = t;
    }
}
void main() {
    int n, i = 0, t;
    printf("Enter the size of Queue: ");
    scanf("%d", & n);
    printf("\nEnter the data for Queue: ");
    while (i &lt; n) {
        scanf("%d", & t);
        enqueue(t, n);
        i++;
    }
    printf("\nQueue which you have entered: ");
    print();
    reverse();
    printf("\n\nQueue after reversing: ");
    print();
}
</code></pre>