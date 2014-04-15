
1. [Reverse Words in a String][Reverse Words in a String]

    > 只要根据空格分隔成字符串就好了，或者从后面前遍历字符串，取出单词之后再用空格拼接即可。

1. [Evaluate Reverse Polish Notation][Evaluate Reverse Polish Notation]

    > 维护一个栈，遇到数字时进栈，遇到符号时出栈两个元素，将算完之后的结果进栈。

1. [Max Points on a Line][Max Points on a Line]

    > 很容易想到暴力的做法：枚举两个点，组成直线，再枚举第三个点，看看是否共线，这样的复杂度为`O(n^3)`，略高。  
    > 优化之后的做法：枚举每个点做为基点，对其他点进行极角排序，然后现行扫描排序后的点，这样复杂度为`O(n^2logn)`。  

[Max Points on a Line]: http://oj.leetcode.com/problems/max-points-on-a-line/
[Evaluate Reverse Polish Notation]: http://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
[Reverse Words in a String]: http://oj.leetcode.com/problems/reverse-words-in-a-string/