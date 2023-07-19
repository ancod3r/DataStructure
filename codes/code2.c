<b>Develop and Implement a menu driven program in C for the following Array operations.</b>
<ul>
<li>Creating Array of N Integer elements.</li>
<li>Display of Array elements with suitable headings.</li>
<li>Find the total Number of Elements in an Array.</li>
<li>Inserting an element (ELEM) at a given valid position (POS).</li>
<li>Deleting an element at a given valid position (POS).</li>
<li>Search an Element in Given array.</li>
<li>Exit </li></ul>
<pre class="language-c match-braces line-numbers"><code>#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

int a[10], pos, elem;
int n = 0;
void create();
void display();
void siz();
void insert();
void del();
void srch();
void main() {
	int choice;
	while (1) {
		printf("\n************MENU************");
		printf("\n1. Create an Array of N Integers");
		printf("\n2. Display of Array Elements");
		printf("\n3. Get the Total Number of Elements of an array");
		printf("\n4. Insert ELEM at a Given POS");
		printf("\n5. Delete an Element at a Given POS");
		printf("\n6. Search an Element");
		printf("\n7. EXIT");
		printf("\nEnter Your Choice: ");
		scanf("%d", & choice);
		switch (choice) {
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				siz();
				break;
			case 4:
				insert();
				break;
			case 5:
				del();
				break;
			case 6:
				srch();
				break;
			case 7:
				exit(1);
				break;
			default:
				printf("\n****Please Enter a Valid Choice****\n\n");
		}
	}
}
void create() {
	int i;
	printf("\nEnter the Size of Array: ");
	scanf("%d", & n);
	printf("\nEnter the Elements: ");
	for (i = 0; i &lt; n; i++) {
		scanf("%d", & a[i]);
	}
}
void siz() {
	int i, len;
	if (n == 0) {
		printf("\n****Array has No Elements(NO SIZE)****\n");
		return;
	}
	for (i = 0; i &lt; sizeof(n); i++) {
		len = n;
	}
	printf("\n\t The Size of Array is: %d\n", len);
}
void display() {
	int i;
	if (n == 0) {
		printf("\n****No Elements to Display****\n");
		return;
	}
	printf("\nArray Elements Are: ");
	for (i = 0; i &lt; n; i++) {
		printf("%d\t ", a[i]);
	}
}
void insert() {
	int i;
	if (n == 5) {
		printf("\n****Array is Full. Insertion is Not Possible****\n");
		return;
	}
	do {
		printf("\nEnter a Valid Position where Element to be Inserted:  ");
		scanf("%d", & pos);
	} while (pos &gt; n);
	printf("\nEnter the Value to be Inserted: ");
	scanf("%d", & elem);
	for (i = n - 1; i &gt;= pos; i--) {
		a[i + 1] = a[i];
	}
	a[pos] = elem;
	n = n + 1;
	display();
}
void del() {
	int i;
	if (n == 0) {
		printf("\n****Array is Empty and No Elements to Delete****\n");
		return;
	}
	do {
		printf("\nEnter a Valid Position from where Element to be Deleted:  ");
		scanf("%d", & pos);
	} while (pos &gt;= n);
	elem = a[pos];
	printf("\nDeleted Element is : %d \n", elem);
	for (i = pos; i &lt; n - 1; i++) {
		a[i] = a[i + 1];
	}
	n = n - 1;
	display();
}
void srch(){
	int num=0,i, pos;
	printf("\nEnter the Integer: ");
    scanf("%d", &num);
     pos = 0;
    for(i=0; i&lt;n; i++) {
        if(a[i]==num) {
        	pos = 1;
        	break;	 
        }
    }
    if(pos==1){
    	printf("\n\tElement \"%d\" Found at Position %d\n", num, i+1);
	}else{
		printf("\n\t****Element  Not  Found****\n");
	}
}</code></pre>