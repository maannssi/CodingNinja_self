# Tree Node Class and Operations

This code implements a TreeNode class and various operations on trees, including inputting a tree, printing a tree, counting nodes, finding the maximum value in a tree, calculating the height of a tree, printing nodes at a given level, counting leaf nodes, traversing the tree in post-order and pre-order, searching for a value in the tree, counting the number of nodes greater than a given value, checking if two trees are identical, and replacing node values with their depth in the tree.

## Code Explanation

The code defines a TreeNode class template, representing a node in a tree, with a data field and a vector of child nodes. The following operations are implemented:

- `input()`: Takes user input to create a tree starting from the root node.
- `print()`: Prints the tree in a pre-order traversal manner.
- `lvlinput()`: Takes user input to create a tree level by level, using a queue for efficient construction.
- `lvlprint()`: Prints the tree level by level.
- `nodes()`: Returns the total number of nodes in the tree.
- `sum_ofnodes()`: Returns the sum of all node values in the tree.
- `max_node()`: Returns the maximum value among the nodes in the tree.
- `findMax()`: Returns the maximum value among the nodes in the tree (recursive implementation).
- `height()`: Returns the height of the tree.
- `printK()`: Prints nodes at a given level `k`.
- `countleaf()`: Returns the count of leaf nodes in the tree.
- `PostOrder()`: Prints the nodes of the tree in a post-order traversal manner.
- `PreOrder()`: Prints the nodes of the tree in a pre-order traversal manner.
- `find()`: Searches for a given value `x` in the tree.
- `greaterx()`: Returns the count of nodes greater than a given value `x`.
- `identical()`: Checks if two trees are identical.
- `depthreplace()`: Replaces the value of each node with its depth in the tree.
- `replaceDepthValue()`: Replaces the value of each node with its depth in the tree (wrapper function).

## Usage

1. Compile and run the code.
2. Follow the prompts to input the tree, either starting from the root or level by level.
3. Choose the operation you want to perform on the tree by uncommenting the corresponding function call in the `main()` function.
4. Compile and run the code again to see the output.

