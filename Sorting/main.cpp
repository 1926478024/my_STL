#include "sorting.h"

int main(){
  std::vector<int> a{7,32,9,12,21,13,23,1,16};
  std::vector<int> b(a);
  //1.插入排序
  insertion_sort(a);
  for(auto &i : a)
    std::cout<<i<<" ";
  std::cout<<std::endl;
  a = b;
  //2.希尔排序
  shell_sort(a);
  for(auto &i : a)
    std::cout<<i<<" ";
  std::cout<<std::endl;
  //3.直接选择排序
  a = b;
  selection_sort(a);
  for(auto &i : a)
    std::cout<<i<<" ";
  std::cout<<std::endl;
  //4.堆排序
  a = b;
  heap_sort(a);
  for(auto &i : a)
    std::cout<<i<<" ";
  std::cout<<std::endl;
  //5.冒泡排序
  a = b;
  bubble_sort(a);
  for(auto &i : a)
    std::cout<<i<<" ";
  std::cout<<std::endl;
  //6.快速排序
  a = b;
  quick_sort(a, 0, a.size() - 1);
  for(auto &i : a)
    std::cout<<i<<" ";
  std::cout<<std::endl;

  //7.归并排序
  a = b;
  merge_sort(a);
  for(auto &i : a)
    std::cout<<i<<" ";
  std::cout<<std::endl;
  return 0;
}
