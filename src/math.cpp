#include "math.h"

ld fpow_int(ld x, int p) {
    if (p == 0) return 1.0;
    if (p == 1) return x;
    if (p % 2 == 0) {
        int t = fpow_int(x, p / 2);
        return t * t;
    }
    return fpow_int(x, p - 1) * x;
}
