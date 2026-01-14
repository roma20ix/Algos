#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}


bool in_triangle(int xn, int yn, int x1, int y1, int x2, int y2, int x3, int y3) {
    int v1 = (x2 - x1) * (yn - y1) - (y2 - y1) * (xn - x1);
    int v2 = (x3 - x2) * (yn - y2) - (y3 - y2) * (xn - x2);
    int v3 = (x1 - x3) * (yn - y3) - (y1 - y3) * (xn - x3);
    if (v1 > 0 && v2 > 0 && v3 > 0 || v1 < 0 && v2 < 0 && v3 < 0) {
        return true;
    }
    return false;
}


ld square_triangle(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3) {
    return abs((x1 - x2) * (y3 - y2) - (y1 - y2) * (x3 - x2)) / 2.0;
}


pair<ld, ld> intersection_lines(ld a1, ld b1, ld c1, ld a2, ld b2, ld c2) {
    ld x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
    ld y = (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1);
    return {x, y};
}
