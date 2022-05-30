# Paths to reach origin
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">You are standing on a point&nbsp;<strong>(n, m)</strong>&nbsp;and you want to go to origin<strong>&nbsp;(0, 0)</strong>&nbsp;by taking steps either&nbsp;left or down&nbsp;i.e. from each point you are allowed to move either in&nbsp;<strong>(n-1, m)&nbsp;or&nbsp;(n, m-1)</strong>. Find the number of <strong>paths </strong>from<strong> point to origin</strong>.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong></span>

<span style="font-size:18px">N=3, M=0
<strong>Output:</strong> 1
<strong>Explanation</strong>: Path used was - 
&nbsp;            <strong>(3,0)  --&gt; ( 2,0) --&gt; (1,0) --&gt; (0,0)</strong>.
&nbsp;            We can see that there is no other path
&nbsp;            other than this path for this testcase.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N=3, M=6
<strong>Output:</strong> 84 
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function <strong>ways</strong>() that takes <strong>array N&nbsp;and integer M</strong>&nbsp;as parameters and returns the total&nbsp;number of <strong>paths </strong>from<strong> point(n,m) to the origin(0,0) % 1000000007.</strong></span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N*M).<br>
<strong>Expected Auxiliary Space:</strong> O(N*M).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N, M ≤ 500</span></p>

<p>&nbsp;</p>
 <p></p>
            </div>