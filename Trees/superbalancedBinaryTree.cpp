// "Superbalanaced Binary Tree"
// Problem from "Interview Cake"

#include <iostream>
#include <limits>


struct binaryTreeNode{
	int val;
	binaryTreeNode* left;
	binaryTreeNode* right;
	binaryTreeNode(int a) : val(a), left(nullptr), right(nullptr) {};
};

bool isSuperbalanced(binaryTreeNode* root, int& min, int& max, int& currHeight, bool& shortCiruit) {
	if (shortCiruit) {
		std::cout << "Short-circuiting!\n";
		return false;

	}

	std::cout << "Root is now " << root->val << ".\n";

	if (root->left == nullptr && root->right == nullptr) {
		// Hit leaf node
		std::cout << "Hit leaf node\t" << "height is " << currHeight << ".\n";

		// Update max and min
		if (currHeight > max) {
			max = currHeight;
		}

		if (currHeight < min) {
			min = currHeight;
		}

		if ((max - min) > 1) {
			shortCiruit = true;
			return false;
		}

		return (max - min) <= 1;
	}


	// Recurse left
	// Increase "currHeight" before recursing
	bool left = true;
	if (root->left != nullptr) {
		currHeight++;
		left = isSuperbalanced(root->left, min, max, currHeight, shortCiruit);
		currHeight--;
	}

	// Recurse right
	// Increase "currHeight" before recursing
	bool right = true;
	if (root->right != nullptr) {
		currHeight++;
		right = isSuperbalanced(root->right, min, max, currHeight, shortCiruit);	
		currHeight--;
	}

	return !shortCiruit && left && right;
}

bool isSuperbalanced(binaryTreeNode* root) {
	int min = std::numeric_limits<int>::max();
	int max = std::numeric_limits<int>::min();
	int height = 0;
	bool shortCiruit = false;
	return isSuperbalanced(root, min, max, height, shortCiruit);
}



int main() {

/*	Make a "superbalanced" tree
/*			1
/*		   /  \
/*		  2     3
/*		 / \   / \
/*		4   5  6		
*/
	binaryTreeNode one = binaryTreeNode(1);
	binaryTreeNode two = binaryTreeNode(2);
	binaryTreeNode three = binaryTreeNode(3);
	binaryTreeNode four = binaryTreeNode(4);
	binaryTreeNode five = binaryTreeNode(5);
	binaryTreeNode six = binaryTreeNode(6);
	
	three.left = &six;
	two.right = &five;
	two.left = &four;
	one.right = &three;
	one.left = &two;

	bool superbalanced = isSuperbalanced(&one);

	std::cout << ((superbalanced) ? "Superbalanced!\n" : "Not Superbalanced\n");


/*	Make a not "superbalanced" tree
/*			11
/*		   /  \
/*		  12   13
/*		 / \    
/*	   14   15  	
/*		   /	
/*		  17
/*		  /
/*		 18	
*/		
	binaryTreeNode eleven = binaryTreeNode(11);
	binaryTreeNode twelve = binaryTreeNode(12);
	binaryTreeNode thirteen = binaryTreeNode(13);
	binaryTreeNode fourteen = binaryTreeNode(14);
	binaryTreeNode fifteen = binaryTreeNode(15);
	binaryTreeNode seventeen = binaryTreeNode(17);
	binaryTreeNode eighteen = binaryTreeNode(18);

	seventeen.left = &eighteen;
	fifteen.left = &seventeen;
	twelve.right = &fifteen;
	twelve.left = &fourteen;
	eleven.left = &twelve;
	eleven.right = &thirteen;
	
	std::cout << "\n";
	superbalanced = isSuperbalanced(&eleven);

	std::cout << ((superbalanced) ? "Superbalanced!\n" : "Not Superbalanced\n");

	return 0;
}
