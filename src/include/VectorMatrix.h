#pragma once
#include <stdio.h>
#include <cmath>

/* ========================================================================================== */

/**
* @brief Wektor 3-wymiarowy - (4-wymiarowoœæ umo¿liwia mno¿enie przez macierze 4x4).
*/
struct Vector4 {
    double data[4];

    Vector4();
    void Print(void);
    void Set(double d1,double d2,double d3);
    double GetX();
    double GetY();
    double GetZ();
    Vector4 operator-(const Vector4 &);
    
    friend Vector4 operator*(const Vector4 &,double);
};

/**
* @brief Macierz 4x4
*/
struct Matrix4 {
    double data[4][4];
 
    Matrix4();
    void Print(void);
    Matrix4 operator*(const Matrix4);
    
    friend Vector4 operator*(const Matrix4,const Vector4);
};


/**
* @brief Macierz przesuniêcia
*/
struct Translation_Matrix : public Matrix4 {
    Translation_Matrix(){
        data[0][0] = 1;
        data[1][1] = 1;
        data[2][2] = 1;
    }
    Translation_Matrix(double x, double y, double z) {
        data[0][3] = x;
        data[1][3] = y;
        data[2][3] = z;

        data[0][0] = 1;
        data[1][1] = 1;
        data[2][2] = 1;
    }
    void Set_Translation(double x, double y, double z) {
        data[0][3] += x;
        data[1][3] += y;
        data[2][3] += z;
    }
};

/**
* @brief Macierz skali
*/
struct Multiplication_Matrix : public Matrix4 {
    Multiplication_Matrix() {}
    Multiplication_Matrix(double x, double y, double z) {
        data[0][0] = x;
        data[1][1] = y;
        data[2][2] = z;
    }
    void Set_Mutliplication(double x, double y, double z) {
        data[0][0] *= x;
        data[1][1] *= y;
        data[2][2] *= z;
    }
};

/**
* @brief Macierz rotacji wzglêdem osi 0X
*/
struct XRotate_Matrix : public Matrix4 {
    XRotate_Matrix() {}
    XRotate_Matrix(double p) {
        data[0][0] = 1;
        data[1][1] = cos(p);
        data[1][2] = -sin(p);
        data[2][1] = sin(p);
        data[2][2] = cos(p);
    }
    void Set_Rotation(double p) {
        data[0][0] = 1;
        data[1][1] = cos(p);
        data[1][2] = -sin(p);
        data[2][1] = sin(p);
        data[2][2] = cos(p);
    }
};

/**
* @brief Macierz rotacji wzglêdem osi 0Y
*/
struct YRotate_Matrix : public Matrix4 {
    YRotate_Matrix() {}
    YRotate_Matrix(double p) {
        data[0][0] = cos(p);
        data[1][1] = 1;
        data[0][2] = sin(p);
        data[2][0] = -sin(p);
        data[2][2] = cos(p);
    }
    void Set_Rotation(double p) {
        data[0][0] = cos(p);
        data[1][1] = 1;
        data[0][2] = sin(p);
        data[2][0] = -sin(p);
        data[2][2] = cos(p);
    }
};

/**
* @brief Macierz rotacji wzglêdem osi 0Z
*/
struct ZRotate_Matrix : public Matrix4 {
    ZRotate_Matrix() {}
    ZRotate_Matrix(double p) {
        data[0][0] = cos(p);
        data[0][1] = -sin(p);
        data[1][0] = sin(p);
        data[1][1] = cos(p);
        data[2][2] = 1;
    }
    void Set_Rotation(double p) {
        data[0][0] = cos(p);
        data[0][1] = -sin(p);
        data[1][0] = sin(p);
        data[1][1] = cos(p);
        data[2][2] = 1;
    }
};

/**
* @brief Macierz rzutowania
*/
struct Projection_Matrix : public Matrix4 {
    Projection_Matrix() {}
    Projection_Matrix(double f, double n, double top, double bottom, double left, double right) {
        data[0][0] = 2 * n / (right - left); data[0][3] = -n*(right + left) / (right - left);
        data[1][1] = 2 * n / (top - bottom); data[1][3] = -n*(top + bottom) / (top - bottom);
        data[2][2] = -(f + n) / (f - n); data[2][3] = -(2 * f * n) / (f - n);
        data[3][2] = -1;
    }
};

/**
* @brief Macierz przekszta³cenia window-space
*/
struct WS_Matrix : public Matrix4 {
    WS_Matrix(){
        data[0][0] = 1.0;
        data[1][1] = 1.0;
        data[2][2] = 1.0;
        data[0][3] = 1.0;
        data[1][3] = 1.0;
        data[2][3] = 1.0;
    }
    WS_Matrix(double size_x, double size_y, double size_z, double x_min, double y_min, double z_min,
        double x_0, double y_0, double z_0){
        data[0][0] = size_x;
        data[1][1] = size_y;
        data[2][2] = size_z;
        data[0][3] = x_min - size_x * x_0;
        data[1][3] = y_min - size_y * y_0;
        data[2][3] = z_min - size_z * z_0;
    }
    void SetMatrix(double size_x, double size_y, double x_min, double y_min,
        double x_0, double y_0) {
        data[0][0] = size_x;
        data[0][2] = x_min - size_x * x_0;
        data[1][1] = size_y;
        data[1][2] = y_min - size_y * y_0;
    }
};

/**
* @brief Macierz przekszta³cenia window-space (2 wersja)
*/
struct WS_Matrix2 : public Matrix4 {
    WS_Matrix2() {
        data[0][0] = 1.0;
        data[1][1] = 1.0;
        data[2][2] = 1.0;
        data[0][3] = 1.0;
        data[1][3] = 1.0;
    }
    WS_Matrix2(double size_x, double size_y, double x_min, double y_min,
        double x_0, double y_0) {
        data[0][0] = size_x;
        data[1][1] = size_y;
        data[0][3] = x_min - size_x * x_0;
        data[1][3] = y_min - size_y * y_0;
    }
    void SetMatrix(double size_x, double size_y, double x_min, double y_min,
        double x_0, double y_0) {
        data[0][0] = size_x;
        data[0][2] = x_min - size_x * x_0;
        data[1][1] = size_y;
        data[1][2] = y_min - size_y * y_0;
    }
};

/* ========================================================================================= */