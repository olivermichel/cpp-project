#ifndef ADD_H
#define ADD_H

namespace add {
    static inline auto add(auto a, auto b) -> decltype(a + b) {

        return a + b;
    }
}

#endif
