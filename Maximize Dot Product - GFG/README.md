# Maximize Dot Product
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given two arrays <strong>A</strong> and <strong>B</strong> of positive integers of size <strong>N</strong> and <strong>M</strong> where <strong>N &gt;= M</strong>, the task is to maximize the dot product by inserting zeros in the second array but you cannot disturb the order of elements.<br>
<br>
Dot Product of array A and B of size N is <strong>A[0]*B[0] + A[1]*B[1]+....A[N]*B[N].</strong></span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: N = 5, A[] = {2, 3, 1, 7, 8} 
       M = 3, B[] = {3, 6, 7}
<strong>Output:</strong> 107
<strong>Explanation</strong>: We get maximum dot product 
after inserting 0 at first and third 
positions in second array.
Maximum Dot Product : = A[i] * B[j] 
2*0 + 3*3 + 1*0 + 7*6 + 8*7 = 107</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: N = 3, A[] = {1, 2, 3}
       M = 1, B[] = {4} 
<strong>Output:</strong> 12 
<strong>Explanation</strong>: We get maximum dot product
after inserting 0 at first and second
positions in second array. 
Maximum Dot Product : = A[i] * B[j] 
1*0 + 2*0 + 3*4 = 12</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Complete the function <strong><code>maxDotProduct</code>()&nbsp;</strong>which takes <strong>N, M</strong>, array <strong>A </strong>and<strong> B</strong> as input parameters and returns the maximum value.<br>
<br>
<strong>Expected Time Complexity:</strong> O(<strong>N*M</strong>)<br>
<strong>Expected Auxiliary Space:</strong> O(<strong>N*M</strong>)<br>
<br>
<strong>Constraints:</strong><br>
1 ≤ M ≤N ≤ 10<sup>3</sup></span><br>
<span style="font-size:18px">1 ≤ A[i], B[i] ≤ 10<sup>3</sup></span></p>
</div>