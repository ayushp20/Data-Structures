#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;
  vector <int> result;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    result.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  void in_order_rec(int i){

    if(left[i]!=-1)
        in_order_rec(left[i]);

    result.push_back(key[i]);

    if(right[i]!=-1)
        in_order_rec(right[i]);

  }
  vector <int> in_order() {
    // Finish the implementation
    // You may need to add a new recursive method to do that

    result.clear();
    in_order_rec(0);
    return result;
  }

  void pre_order_rec(int i){

    result.push_back(key[i]);

    if(left[i]!=-1)
        pre_order_rec(left[i]);

    if(right[i]!=-1)
        pre_order_rec(right[i]);

  }
  vector <int> pre_order() {

    // Finish the implementation
    // You may need to add a new recursive method to do that
    result.clear();
    pre_order_rec(0);

    return result;
  }


  void post_order_rec(int i){
    if(left[i]!=-1)
        post_order_rec(left[i]);

    if(right[i]!=-1)
        post_order_rec(right[i]);

    result.push_back(key[i]);
  }
  vector <int> post_order() {

    // Finish the implementation
    // You may need to add a new recursive method to do that
    result.clear();
    post_order_rec(0);
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}


