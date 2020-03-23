#include "Linear.hpp"
#include <cmath>

Vec2D::Vec2D(double x, double y) noexcept : x(x), y(y) {}
Vec2D::Vec2D(void) noexcept : x(0), y(0), line(OUTDATED_LEN)
Vec2D& Vec2D::operator+= (const Vec2D& v) noexcept {
    x += v.x;
    y += v.y;
    return *this;
}

Vec2D& Vec2D::operator+= (double scalar) noexcept {
    x += scalar;
    y += scalar;
    return *this;
}

Vec2D& Vec2D::operator-= (const Vec2D& v) noexcept {
    x -= v.x;
    y -= v.y;
    return *this;
}

Vec2D& Vec2D::operator-= (double scalar) noexcept {
    x -= scalar;
    y -= scalar;
    return *this;
}

Vec2D& Vec2D::operator*= (const Vec2D& v) noexcept {
    x *= v.x;
    y *= v.y;
    return *this;
}

Vec2D& Vec2D::operator*= (double scalar) noexcept {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vec2D& Vec2D::operator/= (const Vec2D& v) noexcept {
    x /= v.x;
    y /= v.y;
    return *this;
}

Vec2D& Vec2D::operator/= (double scalar) noexcept {
    x /= scalar;
    y /= scalar;
    return *this;
}

double GetLength(void) const noexcept {

}
double GetDistance(const Vec2D& v) const noexcept {

}
void Normalize(void) noexcept {

}
bool IsNormalized(void) const noexcept {

}
Ratio GetRatio(const Vec2D& v) const noexcept {

}

 Vec2D Vec2D::operator+ (const Vec2D& a, const Vec2D& b) noexcept {

 }
 Vec2D Vec2D::operator+ (const Vec2D& v, double scalar) noexcept {

 }
 Vec2D Vec2D::operator- (const Vec2D& a, const Vec2D& b) noexcept {

 }
 Vec2D Vec2D::operator- (const Vec2D& v, double scalar) noexcept {

 }
 Vec2D Vec2D::operator* (const Vec2D& a, const Vec2D& b) noexcept {

 }
 Vec2D Vec2D::operator* (const Vec2D& v, double scalar) noexcept {

 }
 Vec2D Vec2D::operator/ (const Vec2D& a, const Vec2D& b) noexcept {

 }
 Vec2D Vec2D::operator/ (const Vec2D& v, double scalar) noexcept {

 }

 double ScalarProduct(const Vec2D& a, const Vec2D& b) noexcept {

 }

 bool Vec2D::operator== (const Vec2D& a, const Vec2D& b) noexcept {

 }
 bool Vec2D::operator!= (const Vec2D& a, const Vec2D& b) noexcept {

 }
 bool Vec2D::operator> (const Vec2D& a, const Vec2D& b) noexcept {

 }
 bool Vec2D::operator< (const Vec2D& a, const Vec2D& b) noexcept {

 }
 bool Vec2D::operator>= (const Vec2D& a, const Vec2D& b) noexcept {

 }
 bool Vec2D::operator<= (const Vec2D& a, const Vec2D& b) noexcept {

 }
