#include <iostream>
#include <stack>

struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int a) : data(a), left(nullptr), right(nullptr) {};
};
  
bool isBST(treeNode* root) {
	std::stack<treeNode*> nodes;
    nodes.push(root);
    
    treeNode* current;
    while (!nodes.empty()) {
    	current = nodes.top();
        nodes.pop();
        
        if (current->left) {
            if (current->left->data > current->data) {
                std::cout << "short circuiting at " << current->data << ".\n";
                return false;
            }
            nodes.push(current->left);
        }
        
        if (current->right) {
            if (current->right->data < current->data) {
                std::cout << "short circuiting at " << current->data << ".\n";
                return false;
            }
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

    return 0;
}