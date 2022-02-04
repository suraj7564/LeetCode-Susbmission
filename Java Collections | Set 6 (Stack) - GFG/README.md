# Java Collections | Set 6 (Stack)
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Java provides an inbuilt object type called&nbsp;<strong>Stack</strong>. It is a collection that is based on the last in first out (LIFO) principle. Try this problem using Stack.&nbsp;</span></p>

<p><span style="font-size:18px">Given <strong>n</strong> elements of a stack <strong>st </strong>where the first value is the bottom-most value of the stack and the last one is the element at top of the stack, delete the middle element of the stack without using any additional data structure.</span></p>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> n = 5
st = {1, 2, 3, 4, 5}
<strong>Output:</strong> 5 4 2 1
<strong>Explaination:</strong> The middle element is 3. If 
it is deleted and then the values are seen 
from top, this will be the order.</span></pre>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> n = 6
st = {1, 4, 9, 2, 6, 5}
<strong>Output:</strong> 5 6 2 4 1
<strong>Explaination:</strong> The middle element is 9 and if 
it is deleted this will be the stack traversal. </span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your task is to complete the function <strong>deleteMid()</strong> which takes n and st as input parameters and returns a stack where the middle element is deleted.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(n)<br>
<strong>Expected Auxiliary Space:</strong> O(n)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
2 ≤ n ≤ 10<sup>3</sup><br>
1 ≤ st[i] ≤ 10<sup>4</sup>&nbsp; &nbsp;</span></p>
 <p></p>
            </div>