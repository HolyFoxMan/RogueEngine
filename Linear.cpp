#include "Linear.hpp"
#include <cmath>

#ifdef LINEAR_LENGTH_CACHE
    Vec2D::Vec2D(double x, double y) noexcept : x(x), y(y), length(OUTDATED_LEN) {}
    Vec2D::Vec2D(void) noexcept : x(ZERO_FVALUE), y(ZERO_FVALUE), length(OUTDATED_LEN) {}
    #define OPT_SET_LEN_CACHE(LENGTH, VALUE) \
        length = (VALUE)
#else
    Vec2D::Vec2D(double x, double y) noexcept : x(x), y(y) {}
    Vec2D::Vec2D(void) noexcept : x(ZERO_FVALUE), y(ZERO_FVALUE) {}
    #define OPT_SET_LEN_CACHE(LENGTH, VALUE) \
        ((void)0)
#endif // LINEAR_LENGTH_CATCHE

Vec2D& Vec2D::operator+= (const Vec2D& v) noexcept {
    x += v.x;
    y += v.y;
    OPT_SET_LEN_CACHE(length, OUTDATED_LEN);
    return *this;
}

Vec2D& Vec2D::operator+= (double scalar) noexcept {
    x += scalar;
    y += scalar;
    OPT_SET_LEN_CACHE(length, OUTDATED_LEN);
    return *this;
}

Vec2D& Vec2D::operator-= (const Vec2D& v) noexcept {
    x -= v.x;
    y -= v.y;
    OPT_SET_LEN_CACHE(length, OUTDATED_LEN);
    return *this;
}

Vec2D& Vec2D::operator-= (double scalar) noexcept {
    x -= scalar;
    y -= scalar;
    OPT_SET_LEN_CACHE(length, OUTDATED_LEN);
    return *this;
}

Vec2D& Vec2D::operator*= (const Vec2D& v) noexcept {
    x *= v.x;
    y *= v.y;
    OPT_SET_LEN_CACHE(length, OUTDATED_LEN);
    return *this;
}

Vec2D& Vec2D::operator*= (double scalar) noexcept {
    x *= scalar;
    y *= scalar;
    OPT_SET_LEN_CACHE(length, OUTDATED_LEN);
    return *this;
}

Vec2D& Vec2D::operator/= (const Vec2D& v) noexcept {
    x /= v.x;
    y /= v.y;
    OPT_SET_LEN_CACHE(length, OUTDATED_LEN);
    return *this;
}

Vec2D& Vec2D::operator/= (double scalar) noexcept {
    x /= scalar;
    y /= scalar;
    OPT_SET_LEN_CACHE(length, OUTDATED_LEN);
    return *this;
}

double Vec2D::GetLength(void) const noexcept {
#ifdef LINEAR_LENGTH_CACHE
    if (length == OUTDATED_LEN)
        length = sqrt(x * x + y * y);
    return length;
#else
    return sqrt(x * x + y * y);
#endif
}

double Vec2D::GetDistance(const Vec2D& v) const noexcept {
    return (v - *this).GetLength();
}

void Vec2D::Normalize(void) noexcept {
    *this /= GetLength();
    OPT_SET_LEN_CACHE(length, BASIS_LEN);
}

bool Vec2D::IsNormalized(void) const noexcept {
#ifdef LINEAR_LENGTH_CACHE
    if (length == BASIS_LEN)
        return true;
    else
        return false;
#else
    if (GetLength() == BASIS_LEN)
        return true;
    else
        return false;
#endif
}

double Vec2D::GetThreta(const Vec2D& v) const noexcept {
    return acos(ScalarProduct(*this, v));
}

Vec2D::Ratio Vec2D::GetRatio(const Vec2D& v) const noexcept {
    double threta = GetThreta(v);
    if (threta > ZERO_FVALUE)
        return Ratio::MORE_PARALLEL;
    else if (threta == ZERO_FVALUE)
        return Ratio::PERPENDICULAR;
    else
        return Ratio::MORE_OPPOSITE;
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
