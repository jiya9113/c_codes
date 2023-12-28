int bitAnd(int x, int y) {
    int result;
    result = ~(~x | ~y);
    return result;
}

int bitXor(int x, int y) {
    int a = ~(x & y);
    int b = ~((~x) & (~y));
    return a & b;
}

int sign(int x) {
    int sign_bit = x >> 31;
    return (sign_bit | (!!x)) ^ (sign_bit >> 31);
}

int getByte(int x, int n) {
    int shift = n << 3; 
    int byte = (x >> shift) & 0xFF;
    return byte;
}

int logicalShift(int x, int n) {
    int shiftRight = x >> n;
    int sign = (1 << 31) >> n; 
    int mask = ~(sign << 1);
    return shiftRight & mask;
}

int conditional(int x, int y, int z) {
    int mask = ((!x + ~0) + 1);
    return (y & mask) | (z & ~mask); 
}

int bang(int x) {
    int negX = ~x + 1;
    int result = (~(x | negX)) >> 31;
    return result & 1; 
}

int invert(int x, int p, int n) {
    int mask = (~(~0 << n)) << p;
    return x ^ mask; 
}





