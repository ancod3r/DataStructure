<b> Program to convert an Infix Expression into Postfix Expression and vice-versa.</b>
<pre class="language-c match-braces line-numbers"><code>#include &lt;stdio.h&gt;
#include &lt;ctype.h&gt;

char stack[100];
int top = -1;

void push(char x) {
	 stack[++top] = x;
}
char pop() {
	if (top == -1)
		return -1;
	else
		return stack[top--];
}
int priority(char x) {
	 if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/')
		return 2;
	return 0;
}
int main() {
	char exp[100];
	char * e, x;
	printf("Enter the expression: ");
	scanf("%s", exp);
	printf("\n");
	e = exp;

	while ( * e != '\0') {
		if (isalnum( * e))
			printf("%c ", * e);
		else if ( * e == '(')
			push( * e);
		else if ( * e == ')') {
			while ((x = pop()) != '(')
				printf("%c ", x);
		} else {
			while (priority(stack[top]) &gt;= priority( * e))
				printf("%c ", pop());
			push( * e);
			}
			e++;
	}
	while (top != -1) {
		printf("%c ", pop());
	}
	return 0;
}
</code></pre>