#include "Geometry.h"
#include <cmath>

Vector3D operator+(const Vector3D &lhs, const Vector3D &rhs) {
    return {lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z};
}

Vector3D operator-(const Vector3D &lhs, const Vector3D &rhs) {
    return {lhs.X - rhs.X, lhs.Y - rhs.Y, lhs.Z - rhs.Z};
}

Vector3D operator*(const Vector3D &lhs, const double multiplier) {
    return {lhs.X * multiplier, lhs.Y * multiplier, lhs.Z * multiplier};
}

bool operator==(const Vector3D &lhs, const Vector3D &rhs) {
    double eps = 1e-7;
    return std::abs(lhs.X - rhs.X) < eps &&
           std::abs(lhs.Y - rhs.Y) < eps &&
           std::abs(lhs.Z - rhs.Z) < eps;
}

bool operator!=(const Vector3D &lhs, const Vector3D &rhs) {
    double eps = 1e-7;
    return std::abs(lhs.X - rhs.X) > eps &&
           std::abs(lhs.Y - rhs.Y) > eps &&
           std::abs(lhs.Z - rhs.Z) > eps;
}

std::ostream &operator<<(std::ostream &out, Vector3D point) {
    out << "[" << point.X << ", " << point.Y << ", " << point.Z << "]";
    return out;
}

double dot(const Vector3D &lhs, const Vector3D &rhs) {
    return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z;
}

double norm2(const Vector3D &lhs) {
    return dot(lhs, lhs);
}

Vector3D cross(const Vector3D &lhs, const Vector3D &rhs) {
    return {lhs.Y * rhs.Z - rhs.Y * lhs.Z,
            rhs.X * lhs.Z - lhs.X * rhs.Z,
            lhs.X * rhs.Y - rhs.X * lhs.Y};
}

std::optional<Vector3D> Intersect(const Segment3D &lhs, const Segment3D &rhs) {
    const double eps = 1e-7;
    Vector3D v1 = lhs.end - lhs.start;
    Vector3D v2 = rhs.end - rhs.start;
    Vector3D c = rhs.start - lhs.start;

    double check = std::abs(dot(c, cross(v1, v2)));
    if (check > eps) {
        // The segments aren't coplanar
        return {};
    }
    double norm = norm2(cross(v1, v2));
    if (norm < eps) {
        // The segments are collinear
        return {};
    }
    double t = dot(cross(c, v2), cross(v1, v2)) / norm;
    double s = dot(cross(c, v1), cross(v1, v2)) / norm;

    if (0 <= s && s <= 1 && 0 <= t && t <= 1) {
        return lhs.start + v1 * t;
    }
    // The segments don't intersection
    return {};
}
