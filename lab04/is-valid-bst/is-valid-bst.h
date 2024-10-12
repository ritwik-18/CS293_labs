#include "tree.h"
#include<vector>

/**
 * @brief Check if a binary tree is a valid binary search tree
 * 
 * @param root The root of the binary tree
 * @return true If the binary tree is a valid binary search tree
 * @return false If the binary tree is not a valid binary search tree
 *
 * Your task is to check if the tree indexing all the values of type T is a
 * valid binary search tree, which implies that for each node in the tree,
 * all the values in its left subtree are less than the value of that node, and
 * all the values in its right subtree are greater than the value of that node.
 *
 * You can add helper functions or data structures, but you should not modify
 * the existing function signature. Note that this requiress knowledge about
 * the concpet of smart pointers in C++.
 *
 * Lastly, do not add `using namespace std;` as it is a bad practice.
 * The full problem involves the above task AND the task in the file
 * "employee.h". You should complete both tasks.
 */

/*
template <std::totally_ordered T>
void InorderWalk(std::shared_ptr<struct node_t<T>> root, std::vector<struct node_t<T>> &a){
    if(root == nullptr){
        return;
    }
    InorderWalk(root->left_child,a);
    a.push_back(root->value);
    InorderWalk(root->right_child,a);
}

template <std::totally_ordered T>
bool is_valid_bst(std::shared_ptr<struct node_t<T>> root) {
    if(root == nullptr) return true;
    else{
        std::vector<struct node_t<T>> a;
        InorderWalk(root, a) ;
        bool found = true;
        for(size_t i = 1; i < a.size() ; i++){
            if((a[i-1] <=> a[i]) == std::strong_ordering::greater ) return false;
        }
        return found;
    }
    // TODO: Write your code here
     // dummy return
    // End TODO
}

*/

template <std::totally_ordered T>
void InorderWalk(std::shared_ptr<struct node_t<T>> root, std::vector<std::shared_ptr<struct node_t<T>>> &a){
    if(root == nullptr){
        return;
    }
    InorderWalk(root->left_child, a);
    a.push_back(root);  // Push the entire node (pointer to node_t<T>)
    InorderWalk(root->right_child, a);
}

template <std::totally_ordered T>
bool is_valid_bst(std::shared_ptr<struct node_t<T>> root) {
    if (root == nullptr) return true;

    std::vector<std::shared_ptr<struct node_t<T>>> nodes;
    InorderWalk(root, nodes);

    // Check if the node values are sorted using <=> on node->value
    for (size_t i = 1; i < nodes.size(); ++i) {
        if ((nodes[i-1]->value <=> nodes[i]->value) == std::strong_ordering::greater) {
            return false;
        }
    }
    return true;
}
