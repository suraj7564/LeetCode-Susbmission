# Java Collection | Set 3 (HashMap) Part-1
## Easy
<div class="problem-statement">
                <p></p><p><span style="font-size:18px"><strong>HashMap</strong>&nbsp;is a part of collection in Java. It provides the basic implementation of Map interface of Java. It stores the data in (Key, Value) pairs. To access a value you must know its key, otherwise, you can’t access it. HashMap is known as HashMap because it uses the&nbsp;technique called Hashing. Solve the&nbsp;following&nbsp;problem using a HashMap.</span></p>

<p><span style="font-size:18px">Given two arrays key[] and arr[] of size N and a key <strong>s.</strong>&nbsp;Each key[i] and arr[i] form a key-value pair.&nbsp;Find if&nbsp;the value of S in the N key-value pairs.&nbsp;</span></p>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> n = 3
keys = {sak, varun, vijay}
arr = {5, 7, 3}
s = sak
<strong>Output:</strong> 5
<strong>Explaination:</strong> The key is present in the map. 
So its corresponding value is returned which 
is 5.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> n = 4
keys = {csdb, dsh, askj, adfs}
arr = {4, 5, 8, 9}
s = dptu
<strong>Output:</strong> -1
<strong>Explaination:</strong> 
The key is not present in the map.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Yous task is to complete the function <strong>map()</strong> which takes n, keys[], arr[] and s as input parameters and returns the value associated with the key s. If the key is not present return -1.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(n)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ n, |length of key|, value ≤ 1000</span></p>
 <p></p>
            </div>