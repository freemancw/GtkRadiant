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

template<const size_t N>
class Vector
{
public:
    static const Vector<N> ZERO;

    static float dotProduct(const Vector<N>& a, const Vector<N>& b);

    Vector();
    explicit Vector(const Vector<N>& values);

    float operator[](const size_t i) const;
    float& operator[](const size_t i);
    Vector<N> operator-() const;
    Vector<N> operator+(const Vector<N>& rhs) const;
    Vector<N> operator-(const Vector<N>& rhs) const;
    Vector<N> operator*(const Vector<N>& rhs) const;
    Vector<N> operator*(const float s) const;
    Vector<N> operator/(const Vector<N>& rhs) const;
    Vector<N> operator/(const float s) const;
    Vector<N>& operator=(const Vector<N>& rhs);
    Vector<N>& operator+=(const Vector<N>& rhs);
    Vector<N>& operator-=(const Vector<N>& rhs);
    Vector<N>& operator*=(const Vector<N>& rhs);
    Vector<N>& operator*=(const float s);
    Vector<N>& operator/=(const Vector<N>& rhs);
    Vector<N>& operator/=(const float s);
    bool operator==(const Vector<N>& rhs) const;
    bool operator!=(const Vector<N>& rhs) const;

    bool isApproxEqualTo(const Vector<N>& rhs, const float epsilon) const;
    void toZero();
    void normalize();
    Vector<N> normalizedCopy() const;
    float length() const;
    float lengthSquared() const;

protected:
    float elts[N];
};

class Vector2 : public Vector<2>
{
public:
    static const Vector2 XAXIS, YAXIS;

    Vector2();
    explicit Vector2(const float x, const float y);

    float x() const;
    float& x();
    float y() const;
    float& y();
};

class Vector3 : public Vector<3>
{
public:
    static const Vector3 XAXIS, YAXIS, ZAXIS;
    static Vector3 crossProduct(const Vector3& a, const Vector3& b);

    Vector3();
    explicit Vector3(const float x, const float y, const float z);

    float x() const;
    float& x();
    float y() const;
    float& y();
    float z() const;
    float& z();
};

class Vector4 : public Vector<4>
{
public:
    static const Vector4 XAXIS, YAXIS, ZAXIS, WAXIS;

    Vector4();
    explicit Vector4(const float x, const float y, const float z, 
                     const float w);

    float x() const;
    float& x();
    float y() const;
    float& y();
    float z() const;
    float& z();
    float w() const;
    float& w();
};

//============================================================================
// Vector<N> Inline Implementations
//============================================================================

template<const size_t N>
inline Vector<N>::Vector()
{
    for(size_t i = 0; i < N; ++i)
        elts[i] = 0.0f;
}

template<const size_t N>
inline Vector<N>::Vector(const Vector<N>& values)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] = values[i];
}

template<const size_t N>
inline float Vector<N>::operator[](const size_t i) const
{
    return elts[i];
}

template<const size_t N>
inline float& Vector<N>::operator[](const size_t i)
{
    return elts[i];
}

template<const size_t N>
inline Vector<N> Vector<N>::operator-() const
{
    Vector<N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = -elts[i];

    return out;
}

template<const size_t N>
inline Vector<N> Vector<N>::operator+(const Vector<N>& rhs) const
{
    Vector<N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = elts[i] + rhs[i];

    return out;
}

template<const size_t N>
inline Vector<N> Vector<N>::operator-(const Vector<N>& rhs) const
{
    Vector<N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = elts[i] - rhs[i];

    return out;
}

template<const size_t N>
inline Vector<N> Vector<N>::operator*(const Vector<N>& rhs) const
{
    Vector<N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = elts[i] * rhs[i];

    return out;
}

template<const size_t N>
inline Vector<N> Vector<N>::operator*(const float s) const
{
    Vector<N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = elts[i] * s;

    return out;
}

template<const size_t N>
inline Vector<N> Vector<N>::operator/(const Vector<N>& rhs) const
{
    assert(!(rhs == ZERO));

    Vector<N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = elts[i] / rhs[i];

    return out;
}

template<const size_t N>
inline Vector<N> Vector<N>::operator/(const float s) const
{
    assert(s != 0.0f);

    Vector<N> out;

    for(size_t i = 0; i < N; ++i)
        out[i] = elts[i] / s;

    return out;
}

template<const size_t N>
inline Vector<N>& Vector<N>::operator=(const Vector<N>& rhs)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] = rhs[i];

    return *this;
}

template<const size_t N>
inline Vector<N>& Vector<N>::operator+=(const Vector<N>& rhs)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] += rhs[i];

    return *this;
}

template<const size_t N>
inline Vector<N>& Vector<N>::operator-=(const Vector<N>& rhs)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] -= rhs[i];

    return *this;
}

template<const size_t N>
inline Vector<N>& Vector<N>::operator*=(const Vector<N>& rhs)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] *= rhs[i];

    return *this;
}

template<const size_t N>
inline Vector<N>& Vector<N>::operator*=(const float s)
{
    for(size_t i = 0; i < N; ++i)
        elts[i] *= s;

    return *this;
}

template<const size_t N>
inline Vector<N>& Vector<N>::operator/=(const Vector<N>& rhs)
{
    assert(!(rhs == ZERO));

    for(size_t i = 0; i < N; ++i)
        elts[i] /= rhs[i];

    return *this;
}

template<const size_t N>
inline Vector<N>& Vector<N>::operator/=(const float s)
{
    assert(s != 0.0f);

    for(size_t i = 0; i < N; ++i)
        elts[i] /= s;

    return *this;
}

template<const size_t N>
inline bool Vector<N>::operator==(const Vector<N>& rhs) const
{
    for(size_t i = 0; i < N; ++i)
        if(elts[i] != rhs[i]) return false;

    return true;
}

template<const size_t N>
inline bool Vector<N>::operator!=(const Vector<N>& rhs) const
{
    for(size_t i = 0; i < N; ++i)
        if(elts[i] != rhs[i]) return true;

    return false;
}

template<const size_t N>
inline bool Vector<N>::isApproxEqualTo(const Vector<N>& rhs, 
                                       const float epsilon) const
{
    for(size_t i = 0; i < N; ++i)
        if(fabs(elts[i] - rhs[i]) < eps) return false;

    return true;
}

template<const size_t N> 
inline void Vector<N>::toZero()
{
    (*this) = ZERO;
}
    
template<const size_t N> 
inline void Vector<N>::normalize()
{
    (*this) /= length();
}

template<const size_t N> 
inline Vector<N> Vector<N>::normalizedCopy() const
{
    Vector<N> out(*this);
    out.normalize();
    return out;
}

template<const size_t N> 
inline float Vector<N>::length() const
{
    return sqrt(lengthSquared());
}

template<const size_t N> 
inline float Vector<N>::lengthSquared() const
{
    return dotProduct(*this, *this);
}

//============================================================================
// Vector2 Inline Implementations
//============================================================================

inline Vector2::Vector2() : Vector() {}

inline Vector2::Vector2(const float x, const float y) 
{
    elts[0] = x;
    elts[1] = y;
}

inline float Vector2::x() const 
{
    return elts[0];
}

inline float& Vector2::x() 
{
    return elts[0];
}

inline float Vector2::y() const
{
    return elts[1];
}

inline float& Vector2::y()
{
    return elts[1];
}

//============================================================================
// Vector3 Inline Implementations
//============================================================================

inline Vector3::Vector3() : Vector() {}

inline Vector3::Vector3(const float x, const float y, const float z) 
{
    elts[0] = x;
    elts[1] = y;
    elts[2] = z;
}

inline Vector3 Vector3::crossProduct(const Vector3& a, const Vector3& b)
{
    return Vector3(a.y() * b.z() - a.z() * b.y(),
                   a.z() * b.x() - a.x() * b.z(),
                   a.x() * b.y() - a.y() * b.x());
}

inline float Vector3::x() const 
{
    return elts[0];
}

inline float& Vector3::x() 
{
    return elts[0];
}

inline float Vector3::y() const
{
    return elts[1];
}

inline float& Vector3::y()
{
    return elts[1];
}

inline float Vector3::z() const
{
    return elts[2];
}

inline float& Vector3::z()
{
    return elts[2];
}

//============================================================================
// Vector4 Inline Implementations
//============================================================================

inline Vector4::Vector4() : Vector() {}

inline Vector4::Vector4(const float x, const float y, const float z,
                        const float w) 
{
    elts[0] = x;
    elts[1] = y;
    elts[2] = z;
    elts[3] = w;
}

inline float Vector4::x() const 
{
    return elts[0];
}

inline float& Vector4::x() 
{
    return elts[0];
}

inline float Vector4::y() const
{
    return elts[1];
}

inline float& Vector4::y()
{
    return elts[1];
}

inline float Vector4::z() const
{
    return elts[2];
}

inline float& Vector4::z()
{
    return elts[2];
}

inline float Vector4::w() const
{
    return elts[3];
}

inline float& Vector4::w()
{
    return elts[3];
}

} // namespace RAD

#endif // VECTOR_H
