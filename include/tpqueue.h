// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T arr[100];
    int first;
    int last;

 public:
    TPQueue(): first(0), last(0) { }
    void push(T x) {
        if (last - first >= size) {
            throw std::string("Full!");
        } else {
              if (!getSize()) {
                  arr[(last++) % size] = x;
              } else {
                    for (int i = first; i < last; ++i) {
                        if (arr[i].prior < x.prior) {
                            for (int j = last; j > i; --j) {
                                arr[j % size] = arr[(j % size) - 1];
                            }
                            last++;
                            arr[i] = x;
                            return;
                        }
                    }
                    arr[(last++) % size] = x;
              }
        }
    }
    T pop() {
        return arr[(first++) % size];
    }
    int getSize() {
        return (last - first);
    }
    T front() {
        return arr[first % size];
    }
    T back() {
        return arr[(last - 1) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
