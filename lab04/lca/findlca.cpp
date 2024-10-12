#include "tree.h"

// Function which returns lca node of given nodes 'a' and 'b'
TreeNode* TREE::findlca(TreeNode* a, TreeNode* b) {
  TreeNode* root = TREE::root;

  /*if(a == root) return a;
  else if(b == root) return b;*/
  if( a == nullptr || b == nullptr) return nullptr;
  else if(a->parent == nullptr || b->parent == nullptr) return root;
  else{

    TreeNode* c = a;
    TreeNode* d = b;
    int depth_a = 1;
    while(c->parent != root){
      if(c->parent == nullptr) return nullptr;
        c = c->parent;
        depth_a++;
    }
    int depth_b = 1;    
    while(d->parent !=root){
      if(d->parent == nullptr) return nullptr;
      d = d->parent;
      depth_b++;
    }
      
    if(depth_a > depth_b){
        while(depth_a > depth_b){
          a = a->parent;
          depth_a--;
          }
    }
    else if(depth_a<depth_b){
        while(depth_b > depth_a){
          b = b->parent;
          depth_b--;
          }
    }

    
    
    while(a != b){
      //if(a == nullptr || b== nullptr) return root;
      a = a->parent;
      b = b->parent;

      
    }
    return a;// dummy return
  }
  return nullptr;
}