# Split the Array
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array <strong>A</strong> of <strong>n</strong> integers, the task is to count the number of ways to split given array elements into two disjoint groups such that XOR of elements of each group is equal.<br>
<strong>Note: The answer could be very large so print it by doing modulos with 10<sup>9</sup>&nbsp;+ 7.</strong>&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> a[] = {1, 2, 3}
<strong>Output :</strong> 3
<strong>Explanation:
</strong>{(1),(2, 3)},{(2),(1, 3)},{(3),(1, 2)}
are three ways with equal XOR
value of two groups.

</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> a[] = {5, 2, 3, 2}
<strong>Output :</strong> 0

</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
The input is already taken care of by the driver code. You only need to complete the function <strong>countgroup()</strong> that takes an array <strong>(a)</strong>, sizeOfArray <strong>(n)</strong>, and return the number of ways to split an array. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span></p>

<p><span style="font-size:18px">1&lt;=N&lt;=10<sup>5</sup><br>
1&lt;=a&lt;=10<sup>8</sup></span></p>

<p>&nbsp;</p>
</div>