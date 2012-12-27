/*!
 *  @file Point.h
 *  @author Clinton Freeman
 *  @date 12/27/2012
 */

#ifndef POINT_H
#define POINT_H

#include <assert.h>
#include <math.h>
#include "Vector.h"

namespace RAD
{

//============================================================================
// Interfaces
//============================================================================

template<typename T, const size_t N>
class Point
{
public:
    Point();
    explicit Point(const Point<T, N>& values);

    T operator[](const size_t i) const;
    T& operator[](const size_t i);
    Point<T, N> operator-() const;
    Point<T, N> operator+(const Vector<T, N>& rhs) const;
    Point<T, N> operator-(const Vector<T, N>& rhs) const;
    Vector<T, N> operator-(const Point<T, N>& rhs) const;
    Point<T, N>& operator=(const Point<T, N>& rhs);
    Point<T, N>& operator+=(const Vector<T, N>& rhs);
    Point<T, N>& operator-=(const Vector<T, N>& rhs);
    bool operator==(const Point<T, N>& rhs) const;
    bool operator!=(const Point<T, N>& rhs) const;

    bool isApproxEqualTo(const Point<T, N>& rhs, const T epsilon) const;
    void toZero();
    const T* ptr() const;
    T* ptr();

protected:
    T elts[N];
};

class Point2f : public Point<float, 2>
{
public:
    Point2f();
    explicit Point2f(const float x, const float y);

    float  x() const;
    float& x();
    float  y() const;
    float& y();
};

class Point3f : public Point<float, 3>
{
public:
    Point3f();
    explicit Point3f(const float x, const float y, const float z);

    float  x() const;
    float& x();
    float  y() const;
    float& y();
    float  z() const;
    float& z();
};

//============================================================================
// Inline Implementations
//============================================================================

} // namespace RAD

#endif // POINT_H