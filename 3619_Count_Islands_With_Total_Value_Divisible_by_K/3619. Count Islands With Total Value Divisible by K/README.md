<h2><a href="https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/">3619. Count Islands With Total Value Divisible by K</a></h2>
<h3>Medium</h3>
<hr>

<h3>Approach: Depth-First Search (DFS)</h3>

<p>Traverse every cell in the grid. Whenever a cell contains a positive value, run DFS to visit its connected island and calculate the sum of all values in that island.</p>

<ul>
  <li>Use the four directions (up, right, down, left) to explore adjacent cells.</li>
  <li>Mark each visited cell as <code>0</code> so it is not visited again.</li>
  <li>Accumulate the island's total using <code>long long</code>.</li>
  <li>If the island sum is divisible by <code>k</code>, increment the answer.</li>
</ul>

<h3>Complexity Analysis</h3>

<ul>
  <li><strong>Time Complexity:</strong> <code>O(m * n)</code>, where <code>m</code> and <code>n</code> are the grid dimensions. Each cell is visited at most once.</li>
  <li><strong>Space Complexity:</strong> <code>O(m * n)</code> in the worst case for the recursive DFS call stack.</li>
</ul>

<h3>Solution</h3>

<p>See <a href="solution.cpp"><code>solution.cpp</code></a> for the C++ implementation.</p>
