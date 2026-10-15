#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <vector>

//插入排序
//直接插入排序
void insertion_sort(std::vector<int> &nums){
  if(nums.size() <= 1) return ;
  int x = 0, i = 0, j = 0;
  for(; i < nums.size(); ++i){
    x = nums[i];
    for(j = i - 1; j >= 0; --j){
	if(x < nums[j]){
	  nums[j + 1] = nums[j];
	}
	else break;
    }
    nums[j + 1] = x;
  }
}
//希尔排序
void shell_sort(std::vector<int> &nums){
  if(nums.size() <= 1) return ;
  int d = 0, i = 0, j = 0;
  for(d = nums.size()/2; d >= 1; d = d/2){
    int x = 0;
    for(i = d; i < nums.size(); i += d){
	x = nums[i];
	for(j = i - d; j >= 0; j -= d){
	  if(x < nums[j]) nums[j + d] = nums[j];
	  else break;
	}
	nums[j + d] = x;
    }
  }
}

//选择排序
//直接选择排序
void selection_sort(std::vector<int> &nums){
  if(nums.size() <= 1) return ;
  int min_index = 0;
  for(int i = 1; i < nums.size(); ++i){
    min_index = i - 1;
    for(int j = i; j < nums.size(); ++j){
	if(nums[min_index] > nums[j]) min_index = j;
    }
    int x = nums[min_index];
    nums[min_index] = nums[i - 1];
    nums[i - 1] = x;
  }
}
//堆排序
void sift(std::vector<int> &nums, int n, int i){
  int x = nums[i];
  int j = 0;
  j = 2 * i + 1;
  while(j < n){
    if(j < n - 1 && nums[j] < nums[j + 1]) j++;
    if(x < nums[j]){
	nums[i] = nums[j]; i = j; j = i * 2 + 1;
    }
    else break;
  }
  nums[i] = x;
}
void heap_sort(std::vector<int> &nums){
  if(nums.size() <= 1) return ;
  int x = 0;
  int n = nums.size();
  int i = 0;
  for(int i = n/2 - 1; i >= 0; i--) sift(nums, n, i);
  for(int i = 1; i < n; ++i){
    x = nums[0];
    nums[0] = nums[n - i];
    nums[n - i] = x;
    sift(nums, n - i, 0);
  }
}

//交换排序
//冒泡排序
void bubble_sort(std::vector<int> &nums){
  if(nums.size() <= 1) return ;
  int flag = 0;
  for(int i = 1; i < nums.size(); ++i){
    flag = 0;
    for(int j = 0; j < nums.size() - i; ++j){
	if(nums[j] > nums[j + 1]){
	  int x = nums[j + 1];
	  nums[j + 1] = nums[j];
	  nums[j] = x;
	  flag = 1;
	}
    }
    if(flag == 0) return ;
  }
}
//快速排序
void quick_sort(std::vector<int> &nums, int s, int t){
  int left = s + 1, right = t;
  
  while(left <= right){
    while(left <= right && nums[s] > nums[left]) left++;
    while(left <= right && nums[s] < nums[right]) right--;
    if(left < right){
	int a = nums[left];
	nums[left] = nums[right];
	nums[right] = a;
	left++;right--;
    }
  }
  if(s != right){
    int a = nums[s];
    nums[s] = nums[right];
    nums[right] = a;
  }
  if(s < right - 1) quick_sort(nums, s, right - 1);
  if(right + 1 < t) quick_sort(nums, right + 1, t);
}

//归并排序
void two_merge(std::vector<int> &nums, std::vector<int> &res, int left, int mid, int right){
  int i = left, j = left, k = mid + 1;
  while(i <= mid && k <= right){
    if(nums[i] < nums[k]){
	res[j] = nums[i];i++;j++;
    }
    else{
	res[j] = nums[k];j++;k++;
    }
  }
  while(i <= mid){
    res[j] = nums[i];j++;i++;
  }
  while(k <= right){
    res[j] = nums[k];j++;k++;
  }
  for(int i = left; i <= right; ++i)
    nums[i] = res[i];
}
void merge_sort_recursive(std::vector<int> &nums, std::vector<int> &res, int left, int right){
  if(left >= right) return ;
  int mid = left + (right - left)/2;
  merge_sort_recursive(nums, res, left, mid);
  merge_sort_recursive(nums, res, mid + 1, right);
  two_merge(nums, res, left, mid, right);
}
void merge_sort(std::vector<int> &nums){
  if(nums.size() <= 1) return ;
  std::vector<int> res(nums.size(), 0);
  merge_sort_recursive(nums, res, 0, nums.size() - 1);
}
#endif
