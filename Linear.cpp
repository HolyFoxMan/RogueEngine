#include "Linear.hpp"
#include <cmath>

Vec2D::Vec2D(double x, double y) noexcept : x(x), y(y), length(OUTDATED_LEN) {}
Vec2D::Vec2D(void) noexcept : x(0.0f), y(0.0f), length(OUTDATED_LEN) {}

Vec2D& Vec2D::operator+= (const Vec2D& v) noexcept {
    x += v.x;
    y += v.y;
    length = OUTDATED_LEN;
    return *this;
}

Vec2D& Vec2D::operator+= (double scalar) noexcept {
    x += scalar;
    y += scalar;
    length = OUTDATED_LEN;
    return *this;
}

Vec2D& Vec2D::operator-= (const Vec2D& v) noexcept {
    x -= v.x;
    y -= v.y;
    length = OUTDATED_LEN;
    return *this;
}

Vec2D& Vec2D::operator-= (double scalar) noexcept {
    x -= scalar;
    y -= scalar;
    length = OUTDATED_LEN;
    return *this;
}

Vec2D& Vec2D::operator*= (const Vec2D& v) noexcept {
    x *= v.x;
    y *= v.y;
    length = OUTDATED_LEN;
    return *this;
}

Vec2D& Vec2D::operator*= (double scalar) noexcept {
    x *= scalar;
    y *= scalar;
    length = OUTDATED_LEN;
    return *this;
}

Vec2D& Vec2D::operator/= (const Vec2D& v) noexcept {
    x /= v.x;
    y /= v.y;
    length = OUTDATED_LEN;
    return *this;
}

Vec2D& Vec2D::operator/= (double scalar) noexcept {
    x /= scalar;
    y /= scalar;
    length = OUTDATED_LEN;
    return *this;
}

double Vec2D::GetLength(void) const noexcept {
    if (length == OUTDATED_LEN)
        length = sqrt(x * x + y * y);
    return length;
}

double Vec2D::GetDistance(const Vec2D& v) const noexcept {
    return (v - *this).GetLength();
}

void Vec2D::Normalize(void) noexcept {
    *this /= GetLength();
    length = BASIS_LEN;
}

bool Vec2D::IsNormalized(void) const noexcept {
    if (length == BASIS_LEN)
        return true;
    else
        return false;
}

Vec2D::Ratio Vec2D::GetRatio(const Vec2D& v) const noexcept {
    double threta = acos(ScalarProduct(*this, v));
    if (threta > 0.0f)
        return Ratio::PARALLEL;
    else if (threta == 0.0f)
        return Ratio::PERPENDICULAR;
    else
        return Ratio::OPPOSITE;
}

Vec2D operator+ (const Vec2D& a, const Vec2D& b) noexcept {
    return {a.x + b.x, a.y + b.y};
}

Vec2D operator+ (const Vec2D& v, double scalar) noexcept {
    return {v.x + scalar, v.y + scalar};
}

Vec2D operator- (const Vec2D& a, const Vec2D& b) noexcept {
    return {a.x + b.x, a.y + b.y};
}

Vec2D operator- (const Vec2D& v, double scalar) noexcept {
    return {v.x - scalar, v.y - scalar};
}

Vec2D operator* (const Vec2D& a, const Vec2D& b) noexcept {
    return {a.x * b.x, a.y * b.y};
}

Vec2D operator* (const Vec2D& v, double scalar) noexcept {
    return {v.x * scalar, v.y * scalar};
}

Vec2D operator/ (const Vec2D& a, const Vec2D& b) noexcept {
    return {a.x / b.x, a.y / b.y};
}

Vec2D operator/ (const Vec2D& v, double scalar) noexcept {
    return {v.x / scalar, v.y / scalar};
}

double ScalarProduct(const Vec2D& a, const Vec2D& b) noexcept {
    return a.x * b.x + a.y * b.y;
}

bool operator== (const Vec2D& a, const Vec2D& b) noexcept {
    if (a.x == b.x && a.y == b.y)
        return true;
    else
        return false;
}

bool operator!= (const Vec2D& a, const Vec2D& b) noexcept {
    if (a.x != b.x || a.y != b.y)
        return true;
    else
        return false;
}

bool operator> (const Vec2D& a, const Vec2D& b) noexcept {
    if (a.x > b.x && a.y > b.y)
        return true;
    else
        return false;
}

bool operator< (const Vec2D& a, const Vec2D& b) noexcept {
    if (a.x < b.x && a.y < b.y)
        return true;
    else
        return false;
}

bool operator>= (const Vec2D& a, const Vec2D& b) noexcept {
    if (a.x >= b.x && a.y >= b.y)
        return true;
    else
        return false;
}

bool operator<= (const Vec2D& a, const Vec2D& b) noexcept {
    if (a.x <= b.x && a.y <= b.y)
        return true;
    else
        return false;
}
