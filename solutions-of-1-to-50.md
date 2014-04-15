
1. [Reverse Words in a String][Reverse Words in a String]

    > 只要根据空格分隔成字符串就好了，或者从后面前遍历字符串，取出单词之后再用空格拼接即可。

1. [Evaluate Reverse Polish Notation][Evaluate Reverse Polish Notation]

    > 维护一个栈，遇到数字时进栈，遇到符号时出栈两个元素，将算完之后的结果进栈。

1. [Max Points on a Line][Max Points on a Line]

    > 很容易想到暴力的做法：枚举两个点，组成直线，再枚举第三个点，看看是否共线，这样的复杂度为`O(n^3)`，略高。  
    > 优化之后的做法：枚举每个点做为基点，对其他点进行极角排序，然后现行扫描排序后的点，这样复杂度为`O(n^2logn)`。  

1. [Sort List][Sort List]

    > 根据`O(nlogn)`的实现和`常量空间`的限制，想到用`归并排序`。

1. [Insertion Sort List][Insertion Sort List]
    
    > 直接插入排序，复杂度`O(n^2)`

1. [LRU Cache][LRU Cache]

    > 传统的做法有维护一个单列表，维护双列表等办法，我比较偷懒，用单链表 + `map<int, Node*>`的做法。  
    > 链表维护`<key, value>`对，`map<int, Node*>`维护某个`key`指向哪个链表节点，这样查找复杂度`O(logn)`，
    > 更新复杂度`O(logn)`，插入复杂度和删除复杂度也为`O(nlogn)`，只不过多了空间开销。

1. [Binary Tree Postorder Traversal][Binary Tree Postorder Traversal]

    > 先递归左子树和右子树，再处理当前节点

1. [Binary Tree Preorder Traversal][Binary Tree Preorder Traversal]

    > 处理当前节点，再递归左子树和右子树

[Binary Tree Preorder Traversal]: http://oj.leetcode.com/problems/binary-tree-preorder-traversal/
[Binary Tree Postorder Traversal]: http://oj.leetcode.com/problems/binary-tree-postorder-traversal/
[LRU Cache]: http://oj.leetcode.com/problems/lru-cache/
[Insertion Sort List]: http://oj.leetcode.com/problems/insertion-sort-list/
[Sort List]: http://oj.leetcode.com/problems/sort-list/
[Max Points on a Line]: http://oj.leetcode.com/problems/max-points-on-a-line/
[Evaluate Reverse Polish Notation]: http://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
[Reverse Words in a String]: http://oj.leetcode.com/problems/reverse-words-in-a-string/