#pragma once
#include <optional>
#include <iostream>

struct Vector3D {
    double X, Y, Z;
};

struct Segment3D {
    Vector3D start, end;
};

Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs);

Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs);

Vector3D operator*(const Vector3D& lhs, const double multiplier);

bool operator==(const Vector3D& lhs, const Vector3D& rhs);

bool operator!=(const Vector3D& lhs, const Vector3D& rhs);

std::ostream& operator<<(std::ostream& out, Vector3D point);

double dot(const Vector3D& lhs, const Vector3D& rhs);

double norm2(const Vector3D& lhs);

Vector3D cross(const Vector3D& lhs, const Vector3D& rhs);

std::optional<Vector3D> Intersect(const Segment3D& lhs, const Segment3D& rhs);
