#ifndef BUCKETSORT
#define BUCKETSORT

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template<typename T,typename K>
void bucketSort(T begin,T end,K keyFunc) {

  auto size = distance(begin, end); // end - begin;

  // find min for range

  auto min = keyFunc(*begin);

  for(int a = 0; a < size; ++a) {
    if(keyFunc(*(begin + a)) < min) {
      min = keyFunc(*(begin + a));
    }
  }

  //std::cout << min << "\n";

  // find max for range
  
  auto max = keyFunc(*begin);

  for(int a = 0; a < size; ++a) {
    if(keyFunc(*(begin + a)) > max) {
      max = keyFunc(*(begin + a));
    }
  }

  // find range
  
  auto range = max - min;

  // create buckets
  
  auto bin = (size / 5) + 1;
  auto binSize = range/bin;

 
  std::vector<std::vector<typename T::value_type>> buckets(bin); // originally buckets(range)

  for(auto a = begin; a != end; ++a) { // originally < range
    /*auto index = size * keyFunc(*(begin + a));
    //buckets[index] = keyFunc(*(begin + a));
    //buckets.insert(index,(keyFunc(*(begin + a))));  // originally buckets[a] = 0.0;
    buckets[index].push_back(keyFunc(*(begin + a))); */
    /*if(keyFunc(*(begin + a)) < range/5) {
      buckets[0].push_back(keyFunc(*(begin + a)));
    }
    else if((keyFunc(*(begin + a)) < (range/5) * 2) && (keyFunc(*(begin + a)) >= range/5)) {
      buckets[1].push_back(keyFunc(*(begin + a)));
    }
    else if((keyFunc(*(begin + a)) < (range/5) * 3) && (keyFunc(*(begin + a)) >= (range/5) * 2)) {
      buckets[2].push_back(keyFunc(*(begin + a)));
    }
    else if((keyFunc(*(begin + a)) < (range/5) * 4) && (keyFunc(*(begin + a)) >= (range/5) * 3)) {
      buckets[3].push_back(keyFunc(*(begin + a)));
    } else {
      buckets[4].push_back(keyFunc(*(begin + a)));
    } */

    auto index = (keyFunc(*a) - min) / binSize;
    if(index >= bin) {
      --index;
    }
    buckets[index].push_back(*a); 
  }
  /*
  for(auto& x : buckets) {
      for (auto& y : x) {
        std::cout << y << " ";
      }
  }
  std::cout << "\n";  */
   

  //for(auto a = 1; a < binSize; ++a) {
  //  if(
  //}

  // sort buckets
  
  for(int a = 0; a < buckets.size(); ++a) {
    //std::sort(buckets[a].begin(), buckets[a].end());// originally ++buckets[keyFunc(*begin + a)];
    //std::cout << "shit is being sorted in those buckets\n";

    // print out 2D array for testing
  /*
    for(auto& x : buckets) {
      for (auto& y : x) {
        std::cout << y << " ";
      } 
    //std::cout << "\n";
    } */
    auto j = 0;
    for(auto i = 0; i < buckets[a].size(); ++i) {
      j = i;
      while((j > 0) && (keyFunc(buckets[a][j]) < keyFunc(buckets[a][j-1]))) {
        std::swap(buckets[a][j], buckets[a][j - 1]);
        j--;
      }
    }
  }

  // combine buckets

  /*int i = 0;

  for(int a = 0; a < range * max; a++) {
    //std::cout << "past a\n";
    //std::cout << "size of buckets at A: " << buckets[a].size() << "\n";
    for(int b = 0; b < buckets[a].size(); b++) {
      //std::cout << "past b\n";
      T temp = end;
      for(auto c = 0; c < size; ++c) {
        //std::cout << (keyFunc(*(begin + c)) == buckets[a][b]) << "\n";
        if(keyFunc(*(begin + c)) == buckets[a][b]) {
          std::cout << "
          std::iter_swap(begin + i, begin + c);
          c = size;
          std::cout << "shit is being combined\n";
          ++i;
        }
      }
    }
  } */
  
  auto temp = begin;

  for(auto a = buckets.begin(); a != buckets.end(); ++a) {
    for(auto b = a->begin(); b != a->end(); ++b) {
        std::iter_swap(b, temp);
        ++temp;
    }
  }

  // sort incomplete
  /*
  std::vector<T> iterVec(size);
  
  for(auto it = begin; it != end; it++) {
    iterVec[it*]++;
  }
  
  for(int a = 0; int b = 0; b < range; ++b) {
    for(int c = buckets[b]; c > 0; --c) {
      iterVec[a++] = 

  }
  */
}

#endif
