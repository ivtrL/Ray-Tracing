#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vector3D {
    public:
        vector3D() : e{0, 0, 0} {}
        vector3D(float e0, float e1, float e2) : e{e0, e1, e2} {}

        float x() const { return e[0]; }
        float y() const { return e[1]; }
        float z() const { return e[2]; }

        vector3D operator-() const { return vector3D(-e[0], -e[1], -e[2]); }
        float operator[](int i) const { return e[i]; }
        float& operator[](int i) { return e[i]; }

        vector3D& operator+=(const vector3D &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        vector3D& operator*=(const float t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vector3D& operator/=(const float t) {
            return *this *= 1/t;
        }

        float length() const {
            return sqrt(length_squared());
        }

        float length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

    public:
        float e[3];
};

// Type aliases for vector3D
using point3D = vector3D;   // 3D point
using color = vector3D;    // RGB color

#endif