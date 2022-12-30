# Binary Tree K level sum
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a binary tree and a number <strong>K</strong>, the task is to find sum of tree nodes at level K. The Binary Tree is given in string form <strong>S</strong>: (node-value(left-subtree)(right-subtree)).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong></span>
<span style="font-size:18px"><strong>K = </strong>2</span>
<span style="font-size:18px"><strong>S = </strong>"</span><span style="font-size:18px">(0(5(6()())(4()(9()())))(7(1()())(3()())))"</span>
<span style="font-size:18px"><strong>Output:</strong></span>
<span style="font-size:18px">14</span>
<span style="font-size:18px"><strong>Explanation:</strong></span>
<span style="font-size:18px">The Tree from the above String will be formed as:
                             0
                           /   \
                          5      7
                        /  \    /  \
                       6    4  1    3
                             \
                              9 </span> 
<span style="font-size:18px">Sum of nodes at the 2nd level is 6+4+1+3 = 14.</span></pre>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong></span>
<span style="font-size:18px"><strong>K = </strong>1</span>
<span style="font-size:18px"><strong>S = </strong>"(4(8()9())"</span>
<span style="font-size:18px"><strong>Output:</strong></span>
<span style="font-size:18px">17</span>
<span style="font-size:18px"><strong>Explanation:</strong></span>
<span style="font-size:18px">The Tree from the above String will be formed as:
                             4
                           /   \
                          8     9</span>
<span style="font-size:18px">Sum of nodes at the 1st level is 8+9 = 17.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>kLevelSum()</strong> which takes an Integer K and a String S as input and returns the sum of all the node values at Kth level of the tree.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(|S|)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
5 &lt;= |S| &lt;= 10<sup>5</sup></span><br>
<span style="font-size:18px">0 &lt;= K &lt;= </span><span style="font-size:18px">15</span></p>
</div>