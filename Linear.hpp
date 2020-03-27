#pragma once

/* apply cache variable for length */
#define LINEAR_LENGTH_CACHE

class Vec2D {

public:

    enum Ratio {
        MORE_OPPOSITE = -1,
        PERPENDICULAR,
        MORE_PARALLEL,
    };

    double x, y;

    Vec2D(double x, double y) noexcept;
    Vec2D(void) noexcept;

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
    double GetThreta(const Vec2D& v) const noexcept;
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
    #ifdef LINEAR_LENGTH_CACHE
    mutable double length;  // cache variable
    static constexpr double OUTDATED_LEN = -1.0f;
    #endif
    static constexpr double BASIS_LEN = 1.0f;
    static constexpr double ZERO_FVALUE = 0.0f;
};
