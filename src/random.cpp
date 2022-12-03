Random::Random(unsigned long seed) {
    if (seed == 0) {
        shiftRegister = 1;
    } else {
        shiftRegister = seed;
    }
}

int Random::nextInt() {
    int to_return = 0;
    for (int i = 0; i < 10; i++) {
        to_return |= static_cast<int>(LFSR()) << i;
    }
    return to_return;
}

template <class T>
void Random::shuffle(vector<T>& vec) {
    size_t lastIndex = vec.size();
    for (size_t i = 0; i < vec.size(); ++i, --lastIndex) {
        size_t nextIndex = nextInt() % lastIndex;
        std::swap(vec[nextIndex], vec[lastIndex - 1]);
    }
}


bool Random::LFSR() {
    if (shiftRegister & 0x00000001) {
        shiftRegister = (shiftRegister ^ 0x80000057 >> 1) | 0x80000000;
        return true;
    } else {
        shiftRegister >>= 1;
        return false;
    }
}
