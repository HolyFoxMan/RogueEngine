#pragma once

class Vec2D {

public:

    enum Ratio {
        OPPOSITE = -1,
        PERPENDICULAR,
        PARALLEL,
    };

    double x, y;

    Vec2D(double x, double y) noexcept;

    Vec2D& operator+= (const Vec2D& v) noexcept;
    Vec2D& operator+= (double scalar) noexcept;
    Vec2D& operator-= (const Vec2D& v) noexcept;
    Vec2D& operator-= (double scalar) noexcept;
    Vec2D& operator*= (const Vec2D& v) noexcept;
    Vec2D& operator*= (double scalar) noexcept;
    Vec2D& operator/= (const Vec2D& v) noexcept;
    Vec2D& operator/= (double scalar) noexcept;

    double GetLength(void) const noexcept;
    double GetDistance(const Vec2D& v) const noexcept;
    void Normalize(void) noexcept;
    bool IsNormalized(void) const noexcept;
    Ratio GetRatio(const Vec2D& v) const noexcept;


    friend Vec2D operator+ (const Vec2D& a, const Vec2D& b) noexcept;
    friend Vec2D operator+ (const Vec2D& v, double scalar) noexcept;
    friend Vec2D operator- (const Vec2D& a, const Vec2D& b) noexcept;
    friend Vec2D operator- (const Vec2D& v, double scalar) noexcept;
    friend Vec2D operator* (const Vec2D& a, const Vec2D& b) noexcept;
    friend Vec2D operator* (const Vec2D& v, double scalar) noexcept;
    friend Vec2D operator/ (const Vec2D& a, const Vec2D& b) noexcept;
    friend Vec2D operator/ (const Vec2D& v, double scalar) noexcept;

    friend double ScalarProduct(const Vec2D& a, const Vec2D& b) noexcept;

    friend bool operator== (const Vec2D& a, const Vec2D& b) noexcept;
    friend bool operator!= (const Vec2D& a, const Vec2D& b) noexcept;
    friend bool operator> (const Vec2D& a, const Vec2D& b) noexcept;
    friend bool operator< (const Vec2D& a, const Vec2D& b) noexcept;
    friend bool operator>= (const Vec2D& a, const Vec2D& b) noexcept;
    friend bool operator<= (const Vec2D& a, const Vec2D& b) noexcept;

private:

    mutable double length;  // cache variable
    static constexpr double OUTDATED_LEN = -1.0f;
    static constexpr double BASIS_LEN = 1.0f;
};
