#include "myVector.h"

int main(){
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);
    Vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);

// 方式1：原生指针迭代
for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    std::cout << *it << " ";

// 方式2：范围 for（推荐）
for (const auto& x : v)
    std::cout << x << " ";

// 方式3：auto 推导
for (auto it = v.begin(); it != v.end(); ++it)
    std::cout << *it << " ";
    return 0;
}