#include "Smart_ptr.h"

struct Node {
    int val;
    Weak_ptr<Node> peer;
    ~Node() { std::cout << "Node " << val << " destroyed\n"; }
};

int main() {
    auto a = Shared_ptr<Node>(new Node{1});
    auto b = Shared_ptr<Node>(new Node{2});
    a->peer = b;  // 弱引用，不增加 b 的计数
    b->peer = a;
    // 离开作用域后两个 Node 都能正常析构
    return 0;
}
