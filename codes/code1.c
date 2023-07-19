<b> Program to Find the Number of Elements in an Array.</b>
<pre class="language-c match-braces line-numbers"><code>#include &lt;stdio.h&gt; 
int main(){
    int array[] = {4, 78, 23, 92, 106, 81, 1, 55, 99, 0};
    int length;
    length = sizeof(array) / sizeof(array[0]);
    printf("Size of the given array is: %d\n", length);
    getchar();
    return 0;
}
/*
	Output:
    Size of the given array is: 10
*/ 
</code></pre>