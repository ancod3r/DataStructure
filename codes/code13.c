<b>Program to create add remove & display element from single linked list.</b>
<pre class="language-c match-braces line-numbers"><code>#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;

struct info {
    char name[30];
    int eno;
    struct info * next;
};

struct info * head = NULL, * temp, * disp;
void addrecord();
void deleterecord();
void disrecord();

void main() {
    int ch;
    //system("cls");
    while (1) {
        printf("\n 1. To add records\n");
        printf("\n 2. To delete a records\n");
        printf("\n 3. To view the records\n");
        printf("\n 4. To exit\n");
        printf("\n Enter your choice: ");
        scanf("%d", & ch);
        fflush(stdin);
        switch (ch) {
        case 1:
            addrecord();
            break;
        case 2:
            deleterecord();
            break;
        case 3:
            disrecord();
            break;
        case 4:
            exit(0);
        }
    }
}
void addrecord() {
    struct info * add;
    char ans = 'y';
    while (ans == 'y') {
        add = (struct info * ) malloc(sizeof(struct info));
        printf("\n Enter the names: ");
        gets(add -&gt; name);
        fflush(stdin);
        printf("\n Enter the enrollment number: ");
        scanf("%d", & add -&gt; eno);
        fflush(stdin);
        if (head == NULL) {
            head = add;
            add -&gt; next = NULL;
            temp = add;
        } else {
            temp -&gt; next = add;
            add -&gt; next = NULL;
            temp = add;
			}
        printf("\n Would you like to enter another name(y\\n): ");
        ans = getchar();
        fflush(stdin);
    }
}
void deleterecord() {
    struct info * delete;
    int teno, present = 0;
    if (head == NULL) {
        printf("\n No records to delete\n");
        return;
    }
    printf("\n Enter the enrollment number to be deleted \n");
    scanf("%d", & teno);
    fflush(stdin);
    for (delete = head; delete != NULL; delete = delete -&gt; next) {
        if (delete -&gt; eno == teno) {
            if (head -&gt; eno == teno) {
                delete = head;
                head = head -&gt; next;
                free(delete);
                return;
            } else {
                temp -&gt; next = delete -&gt; next;
                free(delete);
                return;
            }
        }
        temp = delete;
    }
    if (present == 0)
        printf("\nNo such enrollment number present\n");
}
void disrecord() {
    if (head == NULL) {
        printf("\n No records to view\n");
        return;
    }
    for (disp = head; disp != NULL; disp = disp -&gt; next) {
        printf("\n\n Name   : %s", disp -&gt; name);
        printf("\n\n Number : %d\n", disp -&gt; eno);
    }
}
</code></pre>