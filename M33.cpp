#include <iostream>
#include <cmath>

#include "Dimension.hpp"
#include "V3.hpp"
#include "M33.hpp"

using namespace std;

void swap(float &x, float &y) {
    float temp = x;
    x = y;
    y = temp;
}

istream& operator>>(istream& in, M33& matrix) {
    cout << "Please enter matrix row vectors:\n";
    cout << "1: ";
    in >> matrix[0];
    cout << "2: ";
    in >> matrix[1];
    cout << "3: ";
    in >> matrix[2];
    return in;
}

ostream& operator<<(ostream& out, M33& matrix) {
    out << "Matrix (\n";
    out << "  " << matrix[Dim::X];
    out << "  " << matrix[Dim::Y];
    out << "  " << matrix[Dim::Z];
    out << ")\n";
    return out;
}

M33::M33() {}

M33::M33(int i) {
    (*this)[Dim::X] = V3(1, 0, 0);
    (*this)[Dim::Y] = V3(0, 1, 0);
    (*this)[Dim::Z] = V3(0, 0, 1);
}

M33::M33(V3 &v1, V3 &v2, V3 &v3) {
    (*this)[Dim::X] = v1;
    (*this)[Dim::Y] = v2;
    (*this)[Dim::Z] = v3;
}

M33::M33(Dim dim, float alpha) {
    float sin_theta = sin(alpha);
    float cos_theta = cos(alpha);
    switch (dim) {
        case Dim::X:
            (*this)[Dim::X] = V3(1, 0, 0);
            (*this)[Dim::Y] = V3(0, cos_theta, -sin_theta);
            (*this)[Dim::Z] = V3(0, sin_theta, cos_theta);
            break;
        case Dim::Y:
            (*this)[Dim::X] = V3(cos_theta, 0, sin_theta);
            (*this)[Dim::Y] = V3(0, 1, 0);
            (*this)[Dim::Z] = V3(-sin_theta, 0, cos_theta);
            break;
        case Dim::Z:
            (*this)[Dim::X] = V3(cos_theta, -sin_theta, 0);
            (*this)[Dim::Y] = V3(sin_theta, cos_theta, 0);
            (*this)[Dim::Z] = V3(0, 0, 1);
            break;
    }
}

M33::M33(Dim dim, float sin_theta, float cos_theta) {
    switch (dim) {
        case Dim::X:
            (*this)[Dim::X] = V3(1, 0, 0);
            (*this)[Dim::Y] = V3(0, cos_theta, -sin_theta);
            (*this)[Dim::Z] = V3(0, sin_theta, cos_theta);
            break;
        case Dim::Y:
            (*this)[Dim::X] = V3(cos_theta, 0, sin_theta);
            (*this)[Dim::Y] = V3(0, 1, 0);
            (*this)[Dim::Z] = V3(-sin_theta, 0, cos_theta);
            break;
        case Dim::Z:
            (*this)[Dim::X] = V3(cos_theta, -sin_theta, 0);
            (*this)[Dim::Y] = V3(sin_theta, cos_theta, 0);
            (*this)[Dim::Z] = V3(0, 0, 1);
            break;
    }
}

V3& M33::operator[](Dim dim) {
    return this->matrix[dim];
} 

V3& M33::operator[](int i) {
    return this->matrix[i];
}        

M33 M33::operator*(M33& matrix) {
    M33 result = M33();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // transposed dot product
            result[j][i] =
                (*this)[j][Dim::X] * matrix[Dim::X][i]
                + (*this)[j][Dim::Y] * matrix[Dim::Y][i]
                + (*this)[j][Dim::Z] * matrix[Dim::Z][i];
        }
    }
    return result;
}

V3 M33::operator*(V3& vector) {
    V3 result = V3();
    result[Dim::X] = (*this)[Dim::X] * vector;
    result[Dim::Y] = (*this)[Dim::Y] * vector;
    result[Dim::Z] = (*this)[Dim::Z] * vector;
    return result;
}

void M33::operator*=(M33& m2) {
    *this = m2 * (*this);
}

void operator*=(V3& v, M33& m) {
    v = m * v;
}

void M33::operator*=(float scalar) {
    (*this)[Dim::X] *= scalar;
    (*this)[Dim::Y] *= scalar;
    (*this)[Dim::Z] *= scalar;
}

M33 M33::operator*(float scalar) {
    return M33(
        (*this)[Dim::X] * scalar,
        (*this)[Dim::Y] * scalar,
        (*this)[Dim::Z] * scalar
    );
}

void M33::operator/=(float scalar) {
    (*this) *= 1.0f / scalar;
}

M33 M33::operator/(float scalar) {
    return (*this) * (1.0f / scalar);
}

void M33::transpose() {
    swap((*this)[0][1], (*this)[1][0]);
    swap((*this)[0][2], (*this)[2][0]);
    swap((*this)[2][1], (*this)[1][2]);
}

// Note: must be positive definite matrix
M33 M33::inverse_iter(int max_iter) {
    M33 inverse = M33();
    V3 v1 = V3(1, 0, 0);
    inverse[Dim::X] = conjugate_grad(v1, max_iter);
    V3 v2 = V3(0, 1, 0);
    inverse[Dim::Y] = conjugate_grad(v2, max_iter);
    V3 v3 = V3(0, 0, 1);
    inverse[Dim::Z] = conjugate_grad(v3, max_iter);
    inverse.transpose();
    return inverse;
}

// CS314 time (from 1 of my HW assignments)!
V3 M33::conjugate_grad(V3 &b, int maxiter) {
    // A = matrix (this)
    M33 &A = *this;
    // x = our current guess
    V3 x = V3(1.0f, 1.0f, 1.0f);
    // residuals
    V3 r = b - A * x;
    V3 p = r;
    float r_prev_mag_sq = r * r;

    for (int k = 1; k <= maxiter; k++) {
        V3 g = A * p;
        float alpha = r_prev_mag_sq / (p * g);
        x += p * alpha;
        r -= g * alpha;

        float r_curr_mag_sq = r * r;
        if (r_curr_mag_sq < 1e-3) return x;

        float beta = r_curr_mag_sq / r_prev_mag_sq;
        p = r + p * beta;

        r_prev_mag_sq = r_curr_mag_sq;
    }
    return x;
}

M33 M33::inverse() {
    M33& m = *this;
    V3 col1 = m[Dim::Y] ^ m[Dim::Z];
    float det = (*this)[Dim::X] * col1;
    V3 col2 = m[Dim::Z] ^ m[Dim::X];
    V3 col3 = m[Dim::X] ^ m[Dim::Y];
    M33 inverse = M33(col1, col2, col3);
    inverse.transpose();
    inverse /= det;
    return inverse;
}

M33 M33::get_rotation_matrix(V3 axis1, V3 axis2, float alpha) {
    axis2 -= axis1;
    float xy_len_inverse = 1.0f / sqrt(axis2[Dim::X] * axis2[Dim::X] + axis2[Dim::Y] * axis2[Dim::Y]);
    float xy_cos_theta = axis2[Dim::X] * xy_len_inverse;
    float xy_sin_theta = axis2[Dim::Y] * xy_len_inverse;
    M33 xy_rotation = M33(Dim::Z, -xy_sin_theta, xy_cos_theta);
    M33 xy_rotation_inv = M33(Dim::Z, xy_sin_theta, xy_cos_theta);
    if (isnan(xy_len_inverse) || isinf(xy_len_inverse)) {
        xy_rotation = M33(1);
        xy_rotation_inv = M33(1);
    }
    axis2 *= xy_rotation;

    float xz_len_inverse = 1.0f / sqrt(axis2[Dim::X] * axis2[Dim::X] + axis2[Dim::Z] * axis2[Dim::Z]);
    float xz_cos_theta = axis2[Dim::X] * xz_len_inverse;
    float xz_sin_theta = axis2[Dim::Z] * xz_len_inverse;
    M33 xz_rotation = M33(Dim::Y, xz_sin_theta, xz_cos_theta);
    M33 xz_rotation_inv = M33(Dim::Y, -xz_sin_theta, xz_cos_theta);
    if (isnan(xy_len_inverse) || isinf(xy_len_inverse)) {
        xz_rotation = M33(1);
        xz_rotation_inv = M33(1);
    }
    M33 yz_rotation = M33(Dim::X, alpha);

    M33 total_rotation = xz_rotation * xy_rotation;
    total_rotation *= yz_rotation;
    total_rotation *= xz_rotation_inv;
    total_rotation *= xy_rotation_inv;
    return total_rotation;
}