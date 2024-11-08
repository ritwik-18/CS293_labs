using namespace std;

struct Node{
    int size;
    Node* parent;
};

struct Unionfind{
    Node* root;
    void makeSet(Node* root){
        root->parent = root;
        root->size = 1;
    }
    void swap(Node* root_1, Node* root_2){
        Node* z = root_1;
        root_1 = root_2;
        root_2 = z;
    }
    Node* findSet(Node* node){
        if(node->parent != node) return findSet(node->parent);
        return node->parent;
    }
    void Union(Node* root_1, Node* root_2){
        root_1 = findSet(root_1);
        root_2 = findSet(root_2);
        if(root_1->size < root_2->size) swap(root_1,root_2);
        root_2->parent = root_1;
        root_1->size = root_1->size + root_2->size;
    }
};