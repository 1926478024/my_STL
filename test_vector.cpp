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
<<<<<<< HEAD

    Vector<std::string> v1;
    v1.push_back("hello");
    v1.push_back("world");
    v1.push_back("foo");
    
    std::cout << "size=" << v.size() << ", cap=" << v.capacity() << std::endl;
    
    v.pop_back();
    std::cout << "after pop_back, size=" << v.size() << std::endl;
    
    v.resize(1);
    std::cout << "after resize(1), size=" << v.size() << std::endl;
    
    v.resize(5);
    std::cout << "after resize(5), size=" << v.size() << std::endl;
    
    v.clear();
    std::cout << "after clear, size=" << v.size() << ", cap=" << v.capacity() << std::endl;
    
    v.reserve(100);
    std::cout << "after reserve(100), cap=" << v.capacity() << std::endl;
=======
>>>>>>> 62f5f307985791666e0ab3a54e62b3980301e1a1
    return 0;
}