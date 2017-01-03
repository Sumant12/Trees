BST:
It is a binary tree data structure with the following properties:
1.The left subtree of a node contains only nodes with keys less than the node’s key.
2.The right subtree of a node contains only nodes with keys greater than the node’s key.
The left and right subtree each must also be a binary search tree.

My Implementation:
Insert:
1.inserted the new node at leaf.
2.Started searching a key from root till I hit a leaf node.
3.Once a leaf node is found, the new node is added as a child of the leaf node.

Search:
1.To search a given key in BST, I first compared it with root, if the key is present at root, I returned root.
2.If the Key is greater than root’s key, I recurred for right subtree of root node.
3.Otherwise I recurred for left subtree.

Delete:
Three case arise when deleting a node in BST.
1) Node to be deleted is leaf:
	 Simply remove from the tree.
2) Node to be deleted has only one child: 
	Copy the child to the node and delete the child.
3) Node to be deleted has two children:
	 1.Find inorder successor of the node
	 2.Copy contents of the inorder successor to the node and delete the inorder successor. 
	 
	 
2D Tree:
1.A 2-D Tree is a binary search tree where data in each node is a 2-Dimensional point in space.
2.It is a space partitioning data structure for organizing points in a 2-Dimensional space.
	 
My Implementation:
All the implementations are very similar to BST. But while doing any dictionary operations, dimension should be taken care of and 
the structure of 2D tree is maintained.
