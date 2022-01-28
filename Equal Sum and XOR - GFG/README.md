# Equal Sum and XOR
## Easy
<div class="problem-statement">
                <p></p><p><span style="font-size:20px">Given a positive integer N, Your task is to complete the function <strong>countValues</strong> which&nbsp;returns an integer denoting the count of all positive integers i such that<br>
0 &lt;= i &lt;= n and n+i = n^i where ^ denotes a XOR operation.<br>
<br>
<strong>Input:</strong><br>
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N.<br>
<br>
<strong>Output:</strong><br>
For each test case in a new line output will be the count of such positive integers.<br>
<br>
<strong>Constraints:</strong><br>
1&lt;=T&lt;=100<br>
1&lt;=N&lt;=1000<br>
<br>
<strong>Example(To be used only for expected output):<br>
Input</strong><br>
2<br>
7<br>
12<br>
<strong>Output</strong><br>
1<br>
4<br>
<br>
<strong>Explanation:</strong><br>
<strong>For first test case</strong><br>
7^i = 7+i holds only for only for i = 0<br>
7+0 = 7^0 = 7<br>
<strong>For second test case</strong><br>
12^i = 12+i hold only for i = 0, 1, 2, 3<br>
for i=0, 12+0 = 12^0 = 10<br>
for i=1, 12+1 = 12^1 = 13<br>
for i=2, 12+2 = 12^2 = 14<br>
for i=3, 12+3 = 12^3 = 15</span></p>

<p><br>
<span style="font-size:16px"><strong>Note:</strong>The <strong>Input/Ouput</strong> format and <strong>Example</strong> given are used for system's internal purpose, and should be used by a user for <strong>Expected Output</strong> only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.</span></p>
 <p></p>
            </div>