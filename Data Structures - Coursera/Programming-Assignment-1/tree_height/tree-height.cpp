#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
using namespace std;

struct Node{
    int key;
    Node* parent;
    vector<Node *> children;
};

class Tree{
    public:
    int no_of_nodes;
    int *parents;
    Node* root;
    Node* nodes;

    Tree(int n){
        this->no_of_nodes = n;
        parents = new int[n];

    }

    void read_data(){
        for(int i = 0; i < no_of_nodes; i++)
            cin>>parents[i];

        nodes = new Node[no_of_nodes];
        for(int i = 0; i < no_of_nodes; i++){
            nodes[i].key = i;
            if(parents[i] == -1){
                nodes[i].parent = NULL;
                root = &nodes[i];
            }
            else{
                nodes[i].parent = &nodes[parents[i]];
                nodes[parents[i]].children.push_back(&nodes[i]);
            }
        }

        cout<<get_max_height(root);
    }

    int get_max_height(Node *node){
        if(no_of_nodes == 0)return 0;
        if(node->children.size() == 0)return 1;

        int max_height = 0;
        for(int i = 0; i < node->children.size(); i++){
            int height = 1 + get_max_height(node->children[i]);
            max_height = max(max_height, height);
        }

        return max_height;
    }

};

int main()
{
    int n;
    cin>>n;
    Tree* tree = new Tree(n);
    tree->read_data();


    return 0;
}
