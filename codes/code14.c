<b>Program to create add remove & display element from double linked list.</b>
<pre class="language-c match-braces line-numbers"><code>#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

struct node {
    struct node * prev;
    int info;
    struct node * next;
};

struct node * create_list(struct node * start);
void display(struct node * start);
struct node * addtoempty(struct node * start, int data);
struct node * addatbeg(struct node * start, int data);
struct node * addatend(struct node * start, int data);
struct node * addafter(struct node * start, int data, int item);
struct node * addbefore(struct node * start, int data, int item);
struct node * del(struct node * start, int data);

int main() {
    int choice, data, item;
    struct node * start = NULL;
    while (1) {
        printf("\n\n1.Create List\n");
        printf("2.Display\n");
        printf("3.Add to empty list\n");
        printf("4.Add at beginning\n");
        printf("5.Add at end\n");
        printf("6.Add after\n");
        printf("7.Add before\n");
        printf("8.Delete\n");
        printf("9.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", & choice);
        switch (choice) {
        case 1:
            start = create_list(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("Enter the element to be inserted : ");
            scanf("%d", & data);
            start = addtoempty(start, data);
            break;
        case 4:
            printf("Enter the element to be inserted : ");
            scanf("%d", & data);
            start = addatbeg(start, data);
            break;
        case 5:
            printf("Enter the element to be inserted : ");
            scanf("%d", & data);
            start = addatend(start, data);
            break;
        case 6:
            printf("Enter the element to be inserted : ");
            scanf("%d", & data);
            printf("Enter the element after which to insert : ");
            scanf("%d", & item);
            start = addafter(start, data, item);
            break;
        case 7:
            printf("Enter the element to be inserted : ");
            scanf("%d", & data);
            printf("Enter the element before which to insert : ");
            scanf("%d", & item);
            start = addbefore(start, data, item);
            break;
        case 8:
            printf("Enter the element to be deleted : ");
            scanf("%d", & data);
            start = del(start, data);
            break;
        case 9:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}

struct node * create_list(struct node * start) {
    int i, n, data;
    printf("\nEnter the number of nodes : ");
    scanf("%d", & n);
    start = NULL;
    if (n == 0)
        return start;
    printf("Enter the element to be inserted : ");
    scanf("%d", & data);
    start = addtoempty(start, data);

    for (i = 2; i &lt;= n; i++) {
        printf("Enter the element to be inserted : ");
        scanf("%d", & data);
        start = addatend(start, data);
    }
    return start;
}
void display(struct node * start) {
    struct node * p;
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    p = start;
    printf("\nList is :");
    while (p != NULL) {
        printf("%d ", p -&gt; info);
        p = p -&gt; next;
    }
    printf("\n");
}
struct node * addtoempty(struct node * start, int data) {
    struct node * tmp;
    tmp = (struct node * ) malloc(sizeof(struct node));
    tmp -&gt; info = data;
    tmp -&gt; prev = NULL;
    tmp -&gt; next = NULL;
    start = tmp;
    return start;
}
struct node * addatbeg(struct node * start, int data) {
    struct node * tmp;
    tmp = (struct node * ) malloc(sizeof(struct node));
    tmp -&gt; info = data;
    tmp -&gt; prev = NULL;
    tmp -&gt; next = start;
    start -&gt; prev = tmp;
    start = tmp;
    return start;
}
struct node * addatend(struct node * start, int data) {
    struct node * tmp, * p;
    tmp = (struct node * ) malloc(sizeof(struct node));
    tmp -&gt; info = data;
    p = start;
    while (p -&gt; next != NULL)
        p = p -&gt; next;
    p -&gt; next = tmp;
    tmp -&gt; next = NULL;
    tmp -&gt; prev = p;
    return start;
}
struct node * addafter(struct node * start, int data, int item) {
    struct node * tmp, * p;
    tmp = (struct node * ) malloc(sizeof(struct node));
    tmp -&gt; info = data;
    p = start;
    while (p != NULL) {
        if (p -&gt; info == item) {
            tmp -&gt; prev = p;
            tmp -&gt; next = p -&gt; next;
            if (p -&gt; next != NULL)
                p -&gt; next -&gt; prev = tmp;
            p -&gt; next = tmp;
            return start;
        }
        p = p -&gt; next;
    }
    printf("\n%d not present in the list\n\n", item);
    return start;
}
struct node * addbefore(struct node * start, int data, int item) {
    struct node * tmp, * q;
    if (start == NULL) {
        printf("\nList is empty\n");
        return start;
    }
    if (start -&gt; info == item) {
        tmp = (struct node * ) malloc(sizeof(struct node));
        tmp -&gt; info = data;
        tmp -&gt; prev = NULL;
        tmp -&gt; next = start;
        start -&gt; prev = tmp;
        start = tmp;
        return start;
    }
    q = start;
    while (q != NULL) {
        if (q -&gt; info == item) {
            tmp = (struct node * ) malloc(sizeof(struct node));
            tmp -&gt; info = data;
            tmp -&gt; prev = q -&gt; prev;
            tmp -&gt; next = q;
            q -&gt; prev -&gt; next = tmp;
            q -&gt; prev = tmp;
            return start;
        }
        q = q -&gt; next;
    }
    printf("\n%d not present in the list\n", item);
    return start;
}
struct node * del(struct node * start, int data) {
    struct node * tmp;
    if (start == NULL) {
        printf("\nList is empty\n");
        return start;
    }
    if (start -&gt; next == NULL)
        if (start -&gt; info == data) {
            tmp = start;
            start = NULL;
            free(tmp);
            return start;
        } else {
			printf("\nElement %d not found\n", data);
			return start;
			}
    if (start -&gt; info == data) {
        tmp = start;
        start = start -&gt; next;
        start -&gt; prev = NULL;
        free(tmp);
        return start;
    }
    tmp = start -&gt; next;
    while (tmp -&gt; next != NULL) {
        if (tmp -&gt; info == data) {
            tmp -&gt; prev -&gt; next = tmp -&gt; next;
            tmp -&gt; next -&gt; prev = tmp -&gt; prev;
            free(tmp);
            return start;
        }
        tmp = tmp -&gt; next;
    }
    // Deletion of last node
    if (tmp -&gt; info == data) {
        tmp -&gt; prev -&gt; next = NULL;
        free(tmp);
        return start;
    }
    printf("\nElement %d not found\n", data);
    return start;
}
</code></pre>