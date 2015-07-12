#include <iostream>
#include <stack>
#include <limits>

struct upperAndLower {
    int upper = std::numeric_limits<int>::max();
    int lower = std::numeric_limits<int>::min();
};

struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;
    upperAndLower bounds;
    treeNode(int a) : data(a), left(nullptr), right(nullptr) {};
};
  
bool isBST(treeNode* root) {
	std::stack<treeNode*> nodes;
    nodes.push(root);
    
    treeNode* current;
    while (!nodes.empty()) {
    	current = nodes.top();
        nodes.pop();

        // Check that current node is with it's bounds
        // Bounds are initially (-infinity, infinity)
        // All other bounds are based on ancestors (modified through recursion)
        // How bounds work:
        //      Left child gets new upper bound
        //      Right child gets new lower bound
        if (current->data < current->bounds.lower || current->data > current->bounds.upper) {
            std::cout << "Short circuit at " << current->data << ".\n";
            return false;
        }
        
        if (current->left) {
            current->left->bounds.lower = current->bounds.lower;
            current->left->bounds.upper = current->data;
            nodes.push(current->left);
        }
        
        if (current->right) {
            current->right->bounds.lower = current->data;
            current->right->bounds.upper = current->bounds.upper;
            nodes.push(current->right);
        }
    }
    return true;
}

int main() {

/*
    Make BST
        1
       /  \
      0    4
          / \
         3   5
*/
    treeNode one = treeNode(1);
    treeNode zero = treeNode(0);
    treeNode three = treeNode(3);
    treeNode four = treeNode(4);
    treeNode five = treeNode(5);

    one.left = &zero;
    one.right = &four;
    four.left = &three;
    four.right = &five;

    bool isaBST = isBST(&one);
    std::cout << (isaBST ? "Is BST" : "Is not BST") << "!\n";

/*
    Make not BST
        1
       /  \
      0     4
     / \    / \
       -1  3   5

*/
    treeNode negOne = treeNode(-1);
    zero.right = &negOne;

    std::cout << '\n';
    isaBST = isBST(&one);
    std::cout << (isaBST ? "Is BST" : "Is not BST") << "!\n";

/*
    Make another not BST
        1
       /  \
      0    4
          / \
         -1   5
*/
    three.data = -1;
    zero.right = nullptr;

    std::cout << '\n';
    isaBST = isBST(&one);
    std::cout << (isaBST ? "Is BST" : "Is not BST") << "!\n";

    return 0;
}