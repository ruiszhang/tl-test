//
// Created by wkf on 2021/10/29.
//

#ifndef TLC_TEST_FUZZER_H
#define TLC_TEST_FUZZER_H

#include "../TLAgent/ULAgent.h"

class Fuzzer {
protected:
    uint64_t *cycles;
public:
    Fuzzer() = default;
    ~Fuzzer() = default;
    virtual void tick() = 0;
    void set_cycles(uint64_t *cycles) {
        this->cycles = cycles;
    }
};

class ULFuzzer: public Fuzzer {
private:
    tl_agent::ULAgent *ulAgent;
public:
    ULFuzzer(tl_agent::ULAgent *ulAgent);
    void tick();
};

class CFuzzer: public Fuzzer {
private:
public:
    void tick() = 0;
};

#endif //TLC_TEST_FUZZER_H
