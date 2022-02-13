# Sum Indexes
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">You are given 3 different arrays A, B, and C of the same size N. Find the number of indexes i such that:<br>
<strong>A<sub>i</sub> = B<sub>i </sub>+ C<sub>k&nbsp;</sub></strong><br>
where k&nbsp;lies between [1, N].</span></p>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 3
A = {1, 2, 3}
B = {3, 2, 4}
C = {0, 5, -2}
<strong>Output:</strong> 2
<strong>Explaination:</strong> The possible i's are 0 and 1. 
1 = 3 + (-2) and 2 = 2 + 0.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your task is to complete the function <strong>pairCount()</strong> which takes the value N and the arrays A, B, and C as input parameters and returns the number of possible indices.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N)<br>
<strong>Expected Auxiliary Space:</strong> O(N)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>4</sup></span><br>
<span style="font-size:18px">1 ≤ A[i], B[i] ≤ 100</span><br>
<span style="font-size:18px">-100 ≤ C[i] ≤ 100</span></p>
 <p></p>
            </div>