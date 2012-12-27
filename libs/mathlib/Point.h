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
// Point<T, N> Inline Implementations
//============================================================================

template<typename T, const size_t N>
inline Point<T, N>::Point()
{
    for(size_t i = 0; i < N; ++i)
        elts[i] = 0.0;
}

template<typename T, const size_t N>
inline Point<T, N>::Point(const Point<T, N>& values)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] = values[i];
}

template<typename T, const size_t N>
inline T Point<T, N>::operator[](const size_t i) const
{
    return elts[i];
}

template<typename T, const size_t N>
inline T& Point<T, N>::operator[](const size_t i)
{
    return elts[i];
}

template<typename T, const size_t N>
inline Point<T, N> Point<T, N>::operator-() const
{
    Point<T, N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = -elts[i];

    return out;
}

template<typename T, const size_t N>
inline Point<T, N> Point<T, N>::operator+(const Vector<T, N>& rhs) const
{
    Point<T, N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = elts[i] + rhs[i];

    return out;
}

template<typename T, const size_t N>
inline Point<T, N> Point<T, N>::operator-(const Vector<T, N>& rhs) const
{
    Point<T, N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = elts[i] - rhs[i];

    return out;
}

template<typename T, const size_t N>
inline Vector<T, N> Point<T, N>::operator-(const Point<T, N>& rhs) const
{
    Vector<T, N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = elts[i] - rhs[i];

    return out;
}

template<typename T, const size_t N>
inline Point<T, N>& Point<T, N>::operator=(const Point<T, N>& rhs)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] = rhs[i];

    return *this;
}

template<typename T, const size_t N>
inline Point<T, N>& Point<T, N>::operator+=(const Vector<T, N>& rhs)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] += rhs[i];

    return *this;
}

template<typename T, const size_t N>
inline Point<T, N>& Point<T, N>::operator-=(const Vector<T, N>& rhs)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] -= rhs[i];

    return *this;
}

template<typename T, const size_t N>
inline bool Point<T, N>::operator==(const Point<T, N>& rhs) const
{
    for(size_t i = 0; i < N; ++i)
        if(elts[i] != rhs[i])
            return false;

    return true;
}

template<typename T, const size_t N>
inline bool Point<T, N>::operator!=(const Point<T, N>& rhs) const
{
    for(size_t i = 0; i < N; ++i)
        if(elts[i] != rhs[i])
            return true;

    return false;
}

template<typename T, const size_t N>
inline bool Point<T, N>::isApproxEqualTo(const Point<T, N>& rhs, 
                                         const T epsilon) const
{
    for(size_t i = 0; i < N; ++i)
        if(fabs(elts[i] - rhs[i]) > epsilon)
            return false;

    return true;
}

template<typename T, const size_t N>
inline void Point<T, N>::toZero()
{
    for(size_t i = 0; i < N; ++i)
        elts[i] = 0.0;
}

template<typename T, const size_t N>
inline const T* Point<T, N>::ptr() const
{
    return elts;
}

template<typename T, const size_t N>
inline T* Point<T, N>::ptr()
{
    return elts;
}

} // namespace RAD

#endif // POINT_H