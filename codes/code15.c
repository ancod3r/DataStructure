<b>Program to count number of nodes in linear linked list.</b>
<pre class="language-c match-braces line-numbers"><code>#include &lt;stdio.h&gt;
struct node {
    int data;
    struct node * next;
};
struct node * head;
void insert(int data) {
    struct node * temp = (struct node * ) malloc(sizeof(struct node));
    temp -&gt; data = data;
    temp -&gt; next = head;
    head = temp;
}
void print() {
    struct node * temp = head;
    int count = 0;
    while (temp != NULL) {
        temp = temp -&gt; next;
        count++;
    }
    printf("\n Total no. of nodes is: %d", count);
}
void main() {
    head = NULL;
    insert(4); // HERE
    insert(7); // NODES
    insert(9); // ARE
    insert(1); // INSERTED
    print();
}
/*
	Output: 
	Total no. of nodes is: 4
*/
</code></pre>