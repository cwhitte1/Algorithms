#ifndef ORDER
#define ORDER

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template<typename T,typename C>
T &findNth(std::vector<T> &data,int index,const C &comp) {
  /*if(data.size() == 1) {
    return data[0];
  } */

  std::sort(data.begin(), data.end(), [&comp](T t1, T t2) -> bool {return comp(t1,t2) < 0;});
  return data[index];
}

#endif
