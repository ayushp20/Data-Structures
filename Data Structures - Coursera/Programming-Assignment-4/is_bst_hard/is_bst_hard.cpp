#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBST_rec(const vector<Node>& tree, int i, long long max, long long min){

   if(i == -1)
        return true;

   if((long long)tree[i].key >= max || (long long)tree[i].key < min)
    return false;

   return (IsBST_rec(tree, tree[i].left, (long long)tree[i].key, (long long)min)
           && IsBST_rec(tree, tree[i].right, (long long)max, (long long)tree[i].key));

}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  if(tree.size() == 0)
    return true;

  return IsBST_rec(tree, 0, LLONG_MAX, LLONG_MIN);
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
