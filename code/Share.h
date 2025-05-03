#ifndef SHARE_H
#define SHARE_H

#include "ModInt.h"

struct Share {
    ModInt x;
    ModInt y;

    Share(const ModInt& xVal, const ModInt& yVal);
};

#endif
