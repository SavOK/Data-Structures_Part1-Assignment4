#Implementation of Dynamic Programming

---
<p align="right">
Specialization:Data Structures and Algorithms</br>
Course:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Algorithmic Toolbox</br>
Project:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Assignment&nbsp;4</br></p>

---
Implemented solutions by using dynamic programming algorithm for the following
computational problems:

- primitive calculator
- knapsack without repetitions
- edit distance between two strings
- maximize the value of an arithmetic expression
- longest common subsequence of three sequences

## Problem 1: [Primitive Calculator]
Given an integer N, compute the minimum number of operations needed to obtain
the number n starting from the number 1.
Input:&nbsp;&nbsp;&nbsp; 1 &lt; n &lt; 10<sup>6</sup>.  
Output:The minimum number K of operations needed to get N from 1. And a sequence
of intermediate numbers. such as positive integers a<sub>0</sub>,
a<sub>2</sub>, ..., a<sub>k−1</sub>
such that a<sub>0</sub> = 1, a<sub>k−1</sub> = N and for all 0 &le; i &lt;
k−1,
a<sub>i+1</sub> is equal to either a<sub>i</sub> + 1, 2&sdot;a<sub>i</sub>, or
3&sdot;a<sub>i</sub>.</br>

*Example*:  
Input:

    96234

Output:
  
    14  /* number of steps */
    1 3 9 10 11 22 66 198 594 1782 5346 16038 16039 32078 96234 /* intermediate value */


**Note**  </br>
- Current implementation is O(N).
- This is straight forward implementation of algorithm from course slides.

## Problem 2: [Knapsack]
Given a set of bars of gold and goal is to take as much gold as possible
 into your bag with limited capacity.</br>
Input:&nbsp;&nbsp;&nbsp;The capacity W of a knapsack and the sequence N of
bars of gold { w<sub>0</sub> ,
 w<sub>1</sub> , ..., w<sub>n−1</sub> } defining the weights of the bars of
 gold.
  1 &le; W &le; 10<sup>4</sup>; 1 &le; N &le; 300; 0 &le; w<sub>0</sub>, ...,
  w<sub>n−1</sub> &le; 10<sup>5</sup>.  
Output: Max value that can fit in knapsack.

*Example*  
Input:

    10          /* W max capacity */
    3 1 4 8     /* Array of bars size 3 */

Output:

    9

**Note**
- Solution O(N&sdot;W) </br>
- In this problem weight and value are identical, optimal value equal max weight

## Problem 3: [Edit Distance] </br>
Compute the edit distance between two strings.  
Input:&nbsp;&nbsp;&nbsp; 2 char strings of length N and M. 1 &le; N, M &le;
100</br>
Output: Edit distance.

**Note**</br>
- Complexity O(N&sdot;M) </br>
- This is straight forward implementation of algorithm from course slides.


## Problem 4: [Arithmetic Expression] </br>
Add parentheses to a given arithmetic expression to maximize its value.</br>
Input:&nbsp;&nbsp;&nbsp; String of length 2N + 1 for some N, with symbols
s<sub>0</sub>, s<sub>1</sub>, ..., s<sub>2n</sub>. Each symbol at an even
position of s is a digit (that is, an integer from 0 to 9) while each symbol
at an odd position is one of three operations from {+,-,*}. 1 &le; N &le; 14  
Output: Maximum value of arithmetic expression.</br>

*Example*  
Input:

    5-8+7*4-8+9

Output:

    200 /* 200 = (5 − ((8 + 7) * (4 − (8 + 9)))) */

**Note**
- Complexity O(N<sup>2</sup>)</br>
- This is straight forward implementation of algorithm from course slides.

## Problem 5: [LCS]</br>
Compute the length of a longest common subsequence of three sequences.</br>

Input:&nbsp;&nbsp;&nbsp; Three numeric sequences A, B, C of length N, M, L.
</br> 1 &le; N,M,L &le; 100; −10<sup>9</sup> &lt; a<sub>i</sub>, b<sub>i</sub>,
c<sub>i</sub> &lt; 10<sup>9</sup>.  
Output: Length of LCS  

*Example*:  
Input:

    5 8 3 2 1 7         /* Sequence 1 of length 5 */
    7 8 2 1 3 8 10 7    /* Sequence 2 of lenght 7 */
    6 6 8 3 1 4 7       /* Sequence 3 of length 6 */


Output:
  
    3

**Note**  </br>
- Complexity O(N&sdot;M&sdot;L)

[Primitive Calculator]:./src/primitive_calculator.
[Knapsack]:./src/knapsack.c
[Edit Distance]:./src/edit_distance.c
[Arithmetic Expression]:./src/placing_parentheses.c
[LCS]:./src/lcs3.c
