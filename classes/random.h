// From lab_ml

#pragma once

#include <vector>
using std::vector;

class Random {
  public:
    // Parameterized constructor.
    inline Random(unsigned long seed);

    // Returns a random integer.
    inline int nextInt();

    // Randomly shuffles a vector.
    template <class T>
    void shuffle(vector<T>& vec);

  private:
    unsigned long shiftRegister;
    // Returns a random bit.
    inline bool LFSR();
};

#include "random.cpp"
