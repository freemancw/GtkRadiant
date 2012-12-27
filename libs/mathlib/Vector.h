/*!
 *  @file Vector.h
 *  @author Clinton Freeman
 *  @date 12/26/2012
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <assert.h>
#include <math.h>

namespace RAD
{

//============================================================================
// Interfaces
//============================================================================

template<typename T, const size_t N>
class Vector
{
public:
    static const Vector<T, N> ZERO;

    static T dotProduct(const Vector<T, N>& a, const Vector<T, N>& b);

    Vector();
    explicit Vector(const Vector<T, N>& values);

    T operator[](const size_t i) const;
    T& operator[](const size_t i);
    Vector<T, N> operator-() const;
    Vector<T, N> operator+(const Vector<T, N>& rhs) const;
    Vector<T, N> operator-(const Vector<T, N>& rhs) const;
    Vector<T, N> operator*(const Vector<T, N>& rhs) const;
    Vector<T, N> operator*(const T s) const;
    Vector<T, N> operator/(const Vector<T, N>& rhs) const;
    Vector<T, N> operator/(const T s) const;
    Vector<T, N>& operator=(const Vector<T, N>& rhs);
    Vector<T, N>& operator+=(const Vector<T, N>& rhs);
    Vector<T, N>& operator-=(const Vector<T, N>& rhs);
    Vector<T, N>& operator*=(const Vector<T, N>& rhs);
    Vector<T, N>& operator*=(const T s);
    Vector<T, N>& operator/=(const Vector<T, N>& rhs);
    Vector<T, N>& operator/=(const T s);
    bool operator==(const Vector<T, N>& rhs) const;
    bool operator!=(const Vector<T, N>& rhs) const;

    bool isApproxEqualTo(const Vector<T, N>& rhs, const T epsilon) const;
    void toZero();
    void normalize();
    Vector<T, N> normalizedCopy() const;
    T length() const;
    T lengthSquared() const;
    const T* ptr() const;
    T* ptr();

protected:
    T elts[N];
};

class Vector2f : public Vector<float, 2>
{
public:
    static const Vector2f XAXIS, YAXIS;

    Vector2f();
    explicit Vector2f(const float x, const float y);

    float  x() const;
    float& x();
    float  y() const;
    float& y();
};

class Vector3f : public Vector<float, 3>
{
public:
    static const Vector3f XAXIS, YAXIS, ZAXIS;
    static Vector3f crossProduct(const Vector3f& a, const Vector3f& b);

    Vector3f();
    explicit Vector3f(const float x, const float y, const float z);

    float  x() const;
    float& x();
    float  y() const;
    float& y();
    float  z() const;
    float& z();
};

class Vector4f : public Vector<float, 4>
{
public:
    static const Vector4f XAXIS, YAXIS, ZAXIS, WAXIS;

    Vector4f();
    explicit Vector4f(const float x, const float y, const float z, 
                      const float w);

    float  x() const;
    float& x();
    float  y() const;
    float& y();
    float  z() const;
    float& z();
    float  w() const;
    float& w();
};

//============================================================================
// Vector<T, N> Inline Implementations
//============================================================================

template<typename T, const size_t N>
inline T dotProduct(const Vector<T, N>& a, const Vector<T, N>& b)
{
    T out = 0.0;

    for(size_t i = 0; i < N; ++i)
        out += a[i] * b[i];

    return out;
}

template<typename T, const size_t N>
inline Vector<T, N>::Vector()
{
    for(size_t i = 0; i < N; ++i)
        elts[i] = 0.0;
}

template<typename T, const size_t N>
inline Vector<T, N>::Vector(const Vector<T, N>& values)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] = values[i];
}

template<typename T, const size_t N>
inline T Vector<T, N>::operator[](const size_t i) const
{
    return elts[i];
}

template<typename T, const size_t N>
inline T& Vector<T, N>::operator[](const size_t i)
{
    return elts[i];
}

template<typename T, const size_t N>
inline Vector<T, N> Vector<T, N>::operator-() const
{
    Vector<T, N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = -elts[i];

    return out;
}

template<typename T, const size_t N>
inline Vector<T, N> Vector<T, N>::operator+(const Vector<T, N>& rhs) const
{
    Vector<T, N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = elts[i] + rhs[i];

    return out;
}

template<typename T, const size_t N>
inline Vector<T, N> Vector<T, N>::operator-(const Vector<T, N>& rhs) const
{
    Vector<T, N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = elts[i] - rhs[i];

    return out;
}

template<typename T, const size_t N>
inline Vector<T, N> Vector<T, N>::operator*(const Vector<T, N>& rhs) const
{
    Vector<T, N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = elts[i] * rhs[i];

    return out;
}

template<typename T, const size_t N>
inline Vector<T, N> Vector<T, N>::operator*(const T s) const
{
    Vector<T, N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = elts[i] * s;

    return out;
}

template<typename T, const size_t N>
inline Vector<T, N> Vector<T, N>::operator/(const Vector<T, N>& rhs) const
{
    assert(!(rhs == ZERO));

    Vector<T, N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = elts[i] / rhs[i];

    return out;
}

template<typename T, const size_t N>
inline Vector<T, N> Vector<T, N>::operator/(const T s) const
{
    assert(s != 0.0);

    Vector<T, N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = elts[i] / s;

    return out;
}

template<typename T, const size_t N>
inline Vector<T, N>& Vector<T, N>::operator=(const Vector<T, N>& rhs)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] = rhs[i];

    return *this;
}

template<typename T, const size_t N>
inline Vector<T, N>& Vector<T, N>::operator+=(const Vector<T, N>& rhs)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] += rhs[i];

    return *this;
}

template<typename T, const size_t N>
inline Vector<T, N>& Vector<T, N>::operator-=(const Vector<T, N>& rhs)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] -= rhs[i];

    return *this;
}

template<typename T, const size_t N>
inline Vector<T, N>& Vector<T, N>::operator*=(const Vector<T, N>& rhs)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] *= rhs[i];

    return *this;
}

template<typename T, const size_t N>
inline Vector<T, N>& Vector<T, N>::operator*=(const T s)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] *= s;

    return *this;
}

template<typename T, const size_t N>
inline Vector<T, N>& Vector<T, N>::operator/=(const Vector<T, N>& rhs)
{
    assert(!(rhs == ZERO));

    for(size_t i = 0; i < N; ++i)
        elts[i] /= rhs[i];

    return *this;
}

template<typename T, const size_t N>
inline Vector<T, N>& Vector<T, N>::operator/=(const T s)
{
    assert(s != 0.0);

    for(size_t i = 0; i < N; ++i)
        elts[i] /= s;

    return *this;
}

template<typename T, const size_t N>
inline bool Vector<T, N>::operator==(const Vector<T, N>& rhs) const
{
    for(size_t i = 0; i < N; ++i)
        if(elts[i] != rhs[i]) return false;

    return true;
}

template<typename T, const size_t N>
inline bool Vector<T, N>::operator!=(const Vector<T, N>& rhs) const
{
    for(size_t i = 0; i < N; ++i)
        if(elts[i] != rhs[i]) return true;

    return false;
}

template<typename T, const size_t N>
inline bool Vector<T, N>::isApproxEqualTo(const Vector<T, N>& rhs, 
                                          const T epsilon) const
{
    for(size_t i = 0; i < N; ++i)
        if(fabs(elts[i] - rhs[i]) < eps) return false;

    return true;
}

template<typename T, const size_t N> 
inline void Vector<T, N>::toZero()
{
    (*this) = ZERO;
}
    
template<typename T, const size_t N> 
inline void Vector<T, N>::normalize()
{
    (*this) /= length();
}

template<typename T, const size_t N> 
inline Vector<T, N> Vector<T, N>::normalizedCopy() const
{
    Vector<T, N> out(*this);
    out.normalize();
    return out;
}

template<typename T, const size_t N> 
inline T Vector<T, N>::length() const
{
    return sqrt(lengthSquared());
}

template<typename T, const size_t N> 
inline T Vector<T, N>::lengthSquared() const
{
    return dotProduct(*this, *this);
}

template<typename T, const size_t N> 
inline const T* Vector<T, N>::ptr() const
{
    return elts;
}

template<typename T, const size_t N> 
inline T* Vector<T, N>::ptr()
{
    return elts;
}

//============================================================================
// Vector2f Inline Implementations
//============================================================================

inline Vector2f::Vector2f() : Vector() {}

inline Vector2f::Vector2f(const float x, const float y) 
{
    elts[0] = x;
    elts[1] = y;
}

inline float Vector2f::x() const { return elts[0]; }
inline float& Vector2f::x() { return elts[0]; }
inline float Vector2f::y() const { return elts[1]; }
inline float& Vector2f::y() { return elts[1]; }

//============================================================================
// Vector3f Inline Implementations
//============================================================================

inline Vector3f::Vector3f() : Vector() {}

inline Vector3f::Vector3f(const float x, const float y, const float z) 
{
    elts[0] = x;
    elts[1] = y;
    elts[2] = z;
}

inline Vector3f Vector3f::crossProduct(const Vector3f& a, const Vector3f& b)
{
    return Vector3f(a.y() * b.z() - a.z() * b.y(),
                    a.z() * b.x() - a.x() * b.z(),
                    a.x() * b.y() - a.y() * b.x());
}

inline float Vector3f::x() const { return elts[0]; }
inline float& Vector3f::x() { return elts[0]; }
inline float Vector3f::y() const { return elts[1]; }
inline float& Vector3f::y() { return elts[1]; }
inline float Vector3f::z() const { return elts[2]; }
inline float& Vector3f::z() { return elts[2]; }

//============================================================================
// Vector4f Inline Implementations
//============================================================================

inline Vector4f::Vector4f() : Vector() {}

inline Vector4f::Vector4f(const float x, const float y, const float z,
                          const float w) 
{
    elts[0] = x;
    elts[1] = y;
    elts[2] = z;
    elts[3] = w;
}

inline float Vector4f::x() const { return elts[0]; }
inline float& Vector4f::x() { return elts[0]; }
inline float Vector4f::y() const { return elts[1]; }
inline float& Vector4f::y() { return elts[1]; }
inline float Vector4f::z() const { return elts[2]; }
inline float& Vector4f::z() { return elts[2]; }
inline float Vector4f::w() const { return elts[3]; }
inline float& Vector4f::w() { return elts[3]; }

} // namespace RAD

#endif // VECTOR_H
