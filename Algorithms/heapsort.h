#ifndef HEAPSORT
#define HEAPSORT

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template<typename T>
void maxHeapify(T begin, T end, int index) {

  auto n = end - begin;

  int left, right, largest;

  left = 2 * index;
  right = (2 * index + 1);
  
  
  if((left <= n) && (*(begin + left - 1) > *(begin + index -1))) {
    largest = left;
  } else {
    largest = index;
  }

  if((right <= n) && (*(begin + right -1) > *(begin + largest -1))) {
    largest = right;
  } 

  if(largest != index) {
    std::iter_swap(begin + index - 1, begin + largest -1);
    maxHeapify(begin, end, largest);
  }
}
  
  /*std::cout << "Max Heapify Called\n";

  int b;
  auto temp = a[i];

  b = 2 * i;

  while(b <= n) {
    if(b < n && a[b+1] > a[b]) {
      b = b + 1;
    }
    if (temp > a[b]) {
      return;
    } else if (temp <= a[b]) {
    //a.insert((a.begin()+(b/2)),a[b]);
    //a.erase((a.begin()+((b/2)+1)));
      auto temp2 = a[b];
      a.erase(a.begin() + (b/2));
      a.insert(a.begin() + (b/2), temp2);
      b = 2 * b;
    }
  }

  a.erase(a.begin() + (b/2));
  a.insert(a.begin() + (b/2), temp);  
  //a.insert((a.begin()+(b/2)),temp);
  //a.erase(a.begin()+((b/2)+1));
  return; */

template<typename T>
void buildMaxHeap(T begin, T end) {
  auto n = end - begin;
  for(int v =  n/2; v >= 1; v--) {
    maxHeapify(begin, end, v);
  }
}

template<typename T> 
void heapsort(T begin, T end) {

  auto n = end - begin;

  buildMaxHeap(begin, end);

  int index;

  for(index = n; index >= 2; index--) {
    std::iter_swap(begin + index -1, begin);
    maxHeapify(begin, end - (n - index + 1), 1);
  }

}

  //using D = typename std::iterator_traits<T>::value_type;

  

  //std::cout << "Heapsort Called";

  //if(begin == end) return;

  /*std::vector<D> data(begin, end);

  auto n = data.size();

  buildMaxHeap(data, n);

  int v;
  D temp; */

  /*for(v = n; v >= 2; v--) {
    temp = data[v];
    std::iter_swap(data.begin()
 */
  /*for(v = n; v >= 2; v--) {
    temp = data[v];
    //std::cout << temp;
    data.erase(data.begin() + v);
    data.insert(data.begin() + v, data[0]);
    data.erase(data.begin()); // plus 1?
    data.insert(data.begin(), temp);
	  //data.insert((data.begin()+v),data[1]);
	  //data.erase(data.begin()+(v+1));
	  //data.insert((data.begin()+1),temp);
    //data.erase(data.begin()+2);
    maxHeapify(data, 1, v - 1);
  }*/
	/*
  T swapper = begin;
  int swapidx = 0;
  while(swapper != end) {
    *swapper = data[swapidx];
    ++swapper;
    ++swapidx;
  } */

  //tester inside to confirm sort
 /* for(auto i = 0; i < data.size(); ++i) {
    std::cout << data[i] << " ";
  }
}*/

/*template<typename B>
void maxHeapify(const std::vector<B>& a, int i, int n) {
  int b;
  auto temp = a[i];

  b = 2 * i;

  while(b <= n) {
    if(b < n && a[b+1] > a[b]) {
      b = b + 1;
    }
    if (temp > a[b]) {
      return;
    } else if (temp <= a[b]) {
	  a.insert((a.begin()+b/2),a[b]);
	  a.erase((a.begin()+(b/2)+1));
      b*=2;
    }
  }

  a.insert((a.begin()+(b/2)),temp);
  a.erase(a.begin()+((b/2)+1));
  return;
}*/

#endif
