//
// Created by roomi on 5/15/2023.
//

#ifndef COMPUTERGRAPHICSPROJECT_SWITCHES_H
#define COMPUTERGRAPHICSPROJECT_SWITCHES_H

#endif //COMPUTERGRAPHICSPROJECT_SWITCHES_H
#include "prototype.h"

COLORREF selectedColor = RGB(0, 0, 0);
void switch2Clicks(int num, HDC hdc, int x1, int y1, int x2, int y2, COLORREF c)
{
    int r = sqrt( pow(x1-x2,2)+pow(y1-y2, 2));
    switch (num) {
        case 1:
            SimpleDDA(hdc, x1, y1, x2, y2, c);
            break;
        case 2:
            parametricLine(hdc, x1, y1, x2, y2, c);
            break;
        case 3:
            DrawLineMidPoint(hdc, x1, y1, x2, y2, c);
            break;
        case 4:
            CircleDirect(hdc, x1, y1, r, c);
            break;
        case 5:
            CirclePolar(hdc, x1, y1, r, c);
            break;
        case 6:
            circleIterativePolar(hdc, x1, y1, r, c);
            break;
        case 7:
            circleFasterMidPoint(hdc, x1, y1, r,0, c);
            break;
        case 8:
            CircleBresenham(hdc, x1, y1, r, c);
            break;
        case 10:
            Rectangle(hdc, x1, y1, x2, y2, selectedColor);
            break;
        case 9:
            DrawSquare(hdc, y1, x1, r, selectedColor, selectedColor);
            break;
    }
}
void switch3Clicks(int num, HDC hdc, int x1, int y1, int x2, int y2, int x3, int y3, COLORREF c)
{
    int q = determineQuarter(x3, y3, x1, y1);
    int r = sqrt( pow(x1-x2,2)+pow(y1-y2, 2));
    int B = sqrt( pow(x1-x3,2)+pow(y1-y3, 2));
    switch(num)
    {
        case 11:
            Draw_Direct_Ellipse(hdc, x1, y1, r,B,selectedColor );
            break;
        case 12:
            Draw_Polar_Ellipse(hdc, x1, y1, r,B,selectedColor);
            break;
        case 13:
            Draw_Midpoint_Ellipse(hdc, x1, y1, r,B,selectedColor);
            break;
        case 14:
            fillCircleWithCircles(hdc, x1, y1, r, q,selectedColor);
            break;
        case 15:
            circleFasterMidPoint(hdc, x1, y1, r,q, c);
            break;
        case 16:
            PointClippingCircle(hdc,x3,y3,x1,y1,r,selectedColor);
            break;
        case 17:
            PointClippingRecSq(hdc, x3, y3, x1, y1, x1 + r, y1 +r, selectedColor);
            break;
        case 18:
            PointClippingRecSq(hdc, x3, y3, x1, y1, x2 , y2 , selectedColor);
            break;

    }
}
void switch4Clicks(int num , HDC hdc, int x1, int y1, int x2, int y2, int x3, int y3,int x4, int y4, COLORREF c)
{
    double r = sqrt( pow(x1-x2,2)+pow(y1-y2, 2));
    switch (num) {
        case 19:
            lineClippingWithCircle(hdc, {{(double)x1, (double)y1}, r},{(double)x3, (double)y3},{(double)x4, (double)y4},selectedColor);
            break;
        case 20:
            Cohen(hdc,x3,y3,x4,y4,x1,y1,x1+(int)r,y1+(int)r);
            break;
        case 21:
            Cohen(hdc,x3,y3,x4,y4,x1,y1,x2,y2);
            break;
    }
}
void switchNClicks(int num, HDC hdc, POINT p[], int n)
{
    switch (num) {
        case 22:
            ConvexFill(hdc,p,n,selectedColor);
            break;
        case 23:
            GeneralPolygonFill(hdc,p,n,selectedColor);
            break;
    }

}
void addMenus(HWND hWnd)
{
    hMenu = CreateMenu();
    HMENU hColorMenu = CreateMenu();
    HMENU hShapesMenu = CreateMenu();
    HMENU hLineMenu = CreateMenu();
    HMENU hCircleMenu = CreateMenu();
    HMENU hEllipseMenu = CreateMenu();
    HMENU hCurveMenu = CreateMenu();
    HMENU hFillingsMenu = CreateMenu();
    HMENU hClippingMenu = CreateMenu();
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hShapesMenu, "Shapes");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hLineMenu, "Line");


    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hCircleMenu, "Circle");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hEllipseMenu, "Ellipse");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hCurveMenu, "Curve");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFillingsMenu, "Filling");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hClippingMenu, "Clipping");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hColorMenu, "Color");
    AppendMenu(hColorMenu, MF_STRING, BLACK, "Black");
    AppendMenu(hColorMenu, MF_STRING, RED, "Red");
    AppendMenu(hColorMenu, MF_STRING, GREEN, "Green");
    AppendMenu(hColorMenu, MF_STRING, BLUE, "Blue");


    AppendMenu(hMenu, MF_POPUP, COLORWindow, "Background Color");

    AppendMenu(hMenu, MF_STRING, TRANSFORM, "Transform");
    AppendMenu(hMenu, MF_STRING, SCALE, "Scale");
    AppendMenu(hMenu, MF_STRING, SAVE, "Save");
    AppendMenu(hMenu, MF_STRING, CLEAR, "Clear");
    AppendMenu(hMenu, MF_STRING, LOAD, "Load");
    AppendMenu(hMenu, MF_STRING, EXIT, "Exit");

    SetMenu(hWnd, hMenu);
}
int console()
{
    int num;
    cout<<"Choose from the menu enter the number\n";
    cout<<"1 lineDAA, 2 parametricLine, 3 LineMidPoint. \n"
          "4 CircleDirect, 5 CirclePolar,6 circleIterativePolar, 7 circleModifiedMidPoint, 8 CircleBresenham. \n"
          "9 Filling Square with Hermit Curve. \n10 Filling Rectangle with Bezier Curve\n";
    cout<<"11 Draw_Direct_Ellipse, 12 Draw_Polar_Ellipse, 13 Draw_Midpoint_Ellipse\n"
          "14.Filling Circle With Circles for quarter\n15.Filling Circle With Lines for quarter\n"
          "16.Clipping Point Circle with window \n17.Clipping Point Square with window\n"
          "18.Clipping Point rectangle with window\n";
    cout<<"19 Clipping Line Inside Circle\n 20 Clipping Line Inside Square\n21 Clipping Line Inside Rectangle\n";
    cout<<"22 convex filling\n23 non convex filling\n24 polygon clipping\n";
    cout<<"25 flood fill Recursive\n26 flood fill nonRecursive\n27 Cardinal Spline\n";
    cin>>num;
    return num;
}
void swap(int& x,int& y)
{
    int tmp=x;
    x=y;
    y=tmp;
}
int Round(double x)
{
    return (int)(x+0.5);
}