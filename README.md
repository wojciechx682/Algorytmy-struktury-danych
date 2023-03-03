# algorytmy
Implementacja podstawowych algorytmów i struktur danych

red_black_tree.cpp

    The code is implementing a Red-Black Tree (RBT) data structure, which is a self-balancing binary search tree. The RBT has the property that the path from the root to any leaf node contains the same number of black nodes, which ensures a balanced structure.

    The code defines two classes: Node and RBT. The Node class represents a single node of the tree, and the RBT class represents the tree as a whole. The Node class has four data members: parent, left, right, and data. parent, left, and right are pointers to the parent, left child, and right child of the node, respectively. data is the data stored in the node. Additionally, Node has an index field that is used to keep track of the index of each node, and a color field that indicates whether the node is colored black (0) or red (1).

    The RBT class has three data members: root, TNULL, and size. root is a pointer to the root node of the tree. TNULL is a special node that represents a null or empty node in the tree. size keeps track of the number of nodes in the tree.

    The RBT class provides several member functions, including find_node, add_node, add_fix, preorder, inorder, and printRBT_short.

    find_node searches for a node with the given data in the tree and returns a pointer to the node if found. If the node is not found, it returns NULL.
    add_node inserts a new node with the given data into the tree and maintains the RBT properties. It first creates a new node with the given data, sets its parent, left, and right pointers to nullptr, and sets its color to red. It then searches for the correct position to insert the new node in the tree, similar to a binary search tree. Once the new node is inserted, it calls the add_fix function to fix any violations of the RBT properties caused by the insertion.
    add_fix is a helper function that fixes any violations of the RBT properties caused by inserting a new node. It does this by performing a series of rotations and color changes on the nodes in the tree. The function takes a pointer to the newly inserted node as an argument and works its way up the tree, fixing violations until the root of the tree is reached.
    preorder and inorder are functions that traverse the tree in preorder and inorder, respectively, and print out the values of the nodes.
    printRBT_short is a function that prints out a short representation of the tree in the format (index: [color, p: parent_index, l: left_child_index, r: right_child_index]). It uses a counter C to limit the output to the first 20 nodes in the tree.
