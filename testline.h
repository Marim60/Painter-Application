#include <Windows.h>
#include<iostream>
using namespace std;
/// Bresenham cases
//  0 <= slope <= 1
//dx>0 & dy>0 & dx>dy
void case1(HDC hdc, int xs, int ys, int xe, int ye, COLORREF color) {
    // Ensure that dx is positive
    if (xs > xe) {
        swap(xs, xe);
        swap(ys, ye);
    }
    int dx = xe - xs;
    int dy = ye - ys;
    int x = xs;
    int y = ys;
    int d_initial = dx - 2 * dy;
    int d = d_initial;
    int d1 = 2 * (dx - dy);
    int d2 = -2 * dy;
    SetPixel(hdc, x, y, color);
    while (x < xe) {
        if (d < 0) {
            y++;
            d += d1;
        } else
            d += d2;
        x++;
        SetPixel(hdc, x, y, color);
    }
}
// 1 < slope
//dx>0 & dy>0 & dx<dy
//void case2(HDC hdc, int xs, int ys, int xe, int ye, COLORREF color) {
//    // Ensure that dy is positive
//    if (ys > ye) {
//        swap(xs, xe);
//        swap(ys, ye);
//    }
//    int dx = xe - xs;
//    int dy = ye - ys;
//    int x = xs;
//    int y = ys;
//    int d_initial = 2 * dx - dy;
//    int d = d_initial;
//    int d1 = 2 * dx;
//    int d2 = 2 * (dx - dy);
//    SetPixel(hdc, x, y, color);
//    while (y < ye) {
//        if (d < 0) {
//            d += d1;
//        } else {
//            x++;
//            d += d2;
//        }
//        y++;
//        SetPixel(hdc, x, y, color);
//    }
//}
//// -1 <= slope <= 0
////dx>0 & dy<0 & dx>dy
//void case3(HDC hdc, int xs, int ys, int xe, int ye, COLORREF color) {
//    // Ensure that dx is negative
//    if (xs < xe) {
//        swap(xs, xe);
//        swap(ys, ye);
//    }
//    int dx = xe - xs;
//    int dy = ye - ys;
//    int x = xs;
//    int y = ys;
//    int d_initial = dx + 2 * dy;
//    int d = d_initial;
//    int d1 = 2 * (dx + dy);
//    int d2 = 2 * dy;
//    SetPixel(hdc, x, y, color);
//    while (x > xe) {
//        if (d < 0) {
//            y++;
//            d += d1;
//        } else
//            d += d2;
//        x--;
//        SetPixel(hdc, x, y, color);
//    }
//}
// slope < -1
//dx<0 & dy>0 & dx<dy
void case4(HDC hdc, int xs, int ys, int xe, int ye, COLORREF color) {
    // Ensure that dy is positive
    if (ys > ye) {
        swap(xs, xe);
        swap(ys, ye);
    }
    int dx = xe - xs;
    int dy = ye - ys;
    int x = xs;
    int y = ys;
    int d_initial = 2 * dx + dy;
    int d = d_initial;
    int d1 = 2 * (dx + dy);
    int d2 = 2 * dx;
    SetPixel(hdc, x, y, color);
    while (y < ye) {
        if (d < 0) {
            x--;
            d += d1;
        } else
            d += d2;
        y++;
        SetPixel(hdc, x, y, color);
    }
}

// Bresenham algorithm (midpoint algorithm) (integer DDA)
void DrawLineBresenham(HDC hdc, int xs, int ys, int xe, int ye, COLORREF color) {
    // Compute slope
    double slope = (double) (ye - ys) / (xe - xs);
    // case 1
//    if (0 <= slope && slope <= 1) case1(hdc, xs, ys, xe, ye, color);

        // case 2
//    else if (slope > 1) case2(hdc, xs, ys, xe, ye, color);
//
//        // case 3
//    else if (-1 <= slope && slope < 0) case3(hdc, xs, ys, xe, ye, color);
//
        // case 4
    //else
    if (slope < -1) case4(hdc, xs, ys, xe, ye, color);
}