# Critical Connections
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an undirected Connected graph of V vertices and E edges.</span><br><span style="font-size: 18px;">A critical connection&nbsp;is an edge that, if removed, will make some nodes unable to reach some other nodes. Find all critical connections in the graph.<br><strong>Note: </strong>There are many possible orders for the answer. You are supposed to print the edges in sorted order, and also an edge should be in sorted order too. So if there's an edge between node 1 and 2, you should print it like (1,2) and not (2,1).</span></p>
<p><br><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
</span><img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/706303/Web/Other/bbe726f7-e9f7-4a0c-b9fa-c649299d9784_1685087730.png" alt=""><span style="font-size: 18px;">
<strong>Output:</strong>
0 1
0 2
<strong>Explanation</strong>: 
Both the edges in the graph are Crtical
connections.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
</span><img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/706303/Web/Other/730505a5-24f6-41de-bd11-84a0a9e56d49_1685087731.png" alt=""><span style="font-size: 18px;">
<strong>Output:</strong>
2 3
<strong>Explanation</strong>:
The edge between nodes 2 and 3 is the only
Critical connection in the given graph.</span>
</pre>
<p><br><span style="font-size: 18px;"><strong>Your task:</strong><br>You dont need to read input or print anything. Your task is to complete the function <strong>criticalConnections()</strong>&nbsp;which takes the integer V denoting the number of vertices and an adjacency list adj as input parameters and returns </span>&nbsp;<span style="font-size: 18px;">a list of lists containing the Critical connections in the sorted order.</span></p>
<p><br><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(V + E)<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(V)</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ V, E ≤ 10<sup>5</sup></span></p></div>