//
// Created by roomi on 5/17/2023.
//

#ifndef COMPUTERGRAPHICSPROJECT_TRANSFORMS_H
#define COMPUTERGRAPHICSPROJECT_TRANSFORMS_H

#endif //COMPUTERGRAPHICSPROJECT_TRANSFORMS_H
class Vector2D
{
    double v[3];
public:
    Vector2D(){v[0]=v[1];v[2]=1;}
    Vector2D(double x, double y){v[0]=x;v[1]=y;v[2]=1;}
    double& operator[](int n){return v[n];}
};
class Matrix2
{
    Vector2D A[3];
public:
    Vector2D& operator[](int n){return A[n];}
    friend Matrix2 operator*(Matrix2& A,Matrix2& B)
    {
        Matrix2 C;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                C[i][j]=0;
                for(int k=0;k<3;k++)C[i][j]+=A[i][k]*B[k][j];
            }
        return C;
    }
    friend Vector2D operator*(Matrix2& A,Vector2D& v)
    {
        Vector2D r;
        for(int i=0;i<3;i++)
        {
            r[i]=0;
            for(int j=0;j<3;j++)r[i]+=A[i][j]*v[j];
        }
        return r;
    }
    Matrix2& operator*=(Matrix2& B)
    {
        *this=*this*B;
        return *this;
    }
};
Matrix2 Identity()
{
    Matrix2 A;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            A[i][j]= i==j ;
    return A;
}

Matrix2 translate(double dx, double dy)
{
    Matrix2 T=Identity();
    T[0][2]=dx; T[1][2]=dy;
    return T;
}


Matrix2 scale(double alpha, double beta)
{
    Matrix2 Sc=Identity();
    Sc[0][0]=alpha;
    Sc[1][1]=beta;
    return Sc;
}