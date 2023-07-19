<b>Program to create add remove & display element from circular linked list.<span style="color: red">&nbsp;May you get some Error</span></b>
<pre class="language-c match-braces line-numbers"><code>#include &lt;stdio.h&gt;
#include &lt;conio.h&gt;

void insertAtBeginning(int);
void insertAtEnd(int);
void insertAtAfter(int, int);
void deleteBeginning();
void deleteEnd();
void deleteSpecific(int);
void display();

struct Node {
    int data;
    struct Node * next;
}* head = NULL;

void main() {
    int choice1, choice2, value, location;
    clrscr();
    while (1) {
        printf("\n*********** MENU *************\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice:  ");
        scanf("%d", & choice1);
        switch (choice1) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", & value);
                while (1) {
                    printf("\nSelect from the following Inserting options\n");
                    printf("1. At Beginning\n2. At End\n3. After a Node\n4. Cancel\nEnter your choice: "); 
                    scanf("%d", & choice2);
                        switch (choice2) {
                        case 1:
                            insertAtBeginning(value);
                            break;
                        case 2:
                            insertAtEnd(value);
                            break;
                        case 3:
                            printf("Enter the location after which you want to insert: ");
                            scanf("%d", & location);
                            insertAfter(value, location);
                            break;
                        case 4:
                            goto EndSwitch;
                        default:
                            printf("\nPlease select correct Inserting option!!!\n");
                        }
                    }
            case 2: 
            	while (1) {
                    printf("\nSelect from the following Deleting options\n");
                    printf("1. At Beginning\n2. At End\n3. Specific Node\n4. Cancel\nEnter your choice: "); 
                    scanf("%d", & choice2);
                        switch (choice2) {
                            case 1:
                                deleteBeginning();
                                break;
                            case 2:
                                deleteEnd();
                                break;
                            case 3:
                                printf("Enter the Node value to be deleted: ");
                                scanf("%d", & location);
                                deleteSpecic(location);
                                break;
                            case 4:
                                goto EndSwitch;
                            default:
                                printf("\nPlease select correct Deleting option!!!\n");
                            }
                        }
                        EndSwitch: break;
            case 3: display();
                    break;
            case 4: exit(0);
                    default: printf("\nPlease select correct option!!!");
        }
    }
}

void insertAtBeginning(int value) {
    struct Node * newNode;
    newNode = (struct Node * ) malloc(sizeof(struct Node));
    newNode -&gt; data = value;
    if (head == NULL) {
        head = newNode;
        newNode -&gt; next = head;
    } else {
        struct Node * temp = head;
        while (temp -&gt; next != head)
            temp = temp -&gt; next;
            newNode -&gt; next = head;
            head = newNode;
            temp -&gt; next = head;
        }
    printf("\nInsertion success!!!");
}

void insertAtEnd(int value) {
    struct Node * newNode;
    newNode = (struct Node * ) malloc(sizeof(struct Node));
    newNode -&gt; data = value;
    if (head == NULL) {
        head = newNode;
        newNode -&gt; next = head;
    } else {
        struct Node * temp = head;
        while (temp -&gt; next != head)
            temp = temp -&gt; next;
            temp -&gt; next = newNode;
            newNode -&gt; next = head;
        }
    printf("\nInsertion success!!!");
}

void insertAfter(int value, int location) {
	struct Node * newNode;
	newNode = (struct Node * ) malloc(sizeof(struct Node));
	newNode -&gt; data = value;
	if (head == NULL) {
		head = newNode;
		newNode -&gt; next = head;
	} else {
		struct Node * temp = head;
		while (temp -&gt; data != location) {
			if (temp -&gt; next == head) {
				printf("Given node is not found in the list!!!");
				goto EndFunction;
			} else {
		temp = temp -&gt; next;
		}
	}
	newNode -&gt; next = temp -&gt; next;
	temp -&gt; next = newNode;
	printf("\nInsertion success!!!");
	}
	EndFunction:
}

void deleteBeginning() {
	if (head == NULL)
	printf("List is Empty!!! Deletion not possible!!!");
	else {
		struct Node * temp = head;
		if (temp -&gt; next == head) {
			head = NULL;
			free(temp);
		} else {
	head = head -&gt; next;
	free(temp);
	}
	printf("\nDeletion success!!!");
	}
}

void deleteEnd() {
	if (head == NULL)
	printf("List is Empty!!! Deletion not possible!!!");
	else {
		struct Node * temp1 = head, temp2;
		if (temp1 -&gt; next == head) {
			head = NULL;
			free(temp1);
		} else {
		while (temp1 -&gt; next != head) {
			temp2 = temp1;
			temp1 = temp1 -&gt; next;
			}
		temp2 -&gt; next = head;
		free(temp1);
	}
	printf("\nDeletion success!!!");
	}
}

void deleteSpecific(int delValue) {
	if (head == NULL)
	printf("List is Empty!!! Deletion not possible!!!");
	else {
		struct Node * temp1 = head, temp2;
		while (temp1 -&gt; data != delValue) {
			if (temp1 -&gt; next == head) {
				printf("\nGiven node is not found in the list!!!");
				goto FuctionEnd;
			} else {
				temp2 = temp1;
				temp1 = temp1 -&gt; next;
				}
			}
		if (temp1 -&gt; next == head) {
			head = NULL;
			free(temp1);
		} else {
		if (temp1 == head) {
			temp2 = head;
			while (temp2 -&gt; next != head)
				temp2 = temp2 -&gt; next;
				head = head -&gt; next;
				temp2 -&gt; next = head;
				free(temp1);
		} else {
			if (temp1 -&gt; next == head) {
				temp2 -&gt; next = head;
			} else {
				temp2 -&gt; next = temp1 -&gt; next;
				}
			free(temp1);
			}
		}
		printf("\nDeletion success!!!");
		}
	FuctionEnd:
}

void display() {
    if (head == NULL)
        printf("\nList is Empty!!!");
    else {
        struct Node * temp = head;
        printf("\nList elements are: \n");
        while (temp -&gt; next != head) {
            printf("%d ---&gt; ", temp -&gt; data);
        }
        printf("%d ---&gt; %d", temp -&gt; data, head -&gt; data);
    }
}
</code></pre>