/*!
 *  @file Vector.cpp
 *  @author Clinton Freeman
 *  @date 05/07/2011
 */

#include "Vector.h"

namespace RAD
{

template<const size_t N>
const Vector<N> Vector<N>::ZERO;

const Vector2 Vector2::XAXIS(1.0f, 0.0f);
const Vector2 Vector2::YAXIS(0.0f, 1.0f);

const Vector3 Vector3::XAXIS(1.0f, 0.0f, 0.0f);
const Vector3 Vector3::YAXIS(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::ZAXIS(0.0f, 0.0f, 1.0f);

const Vector4 Vector4::XAXIS(1.0f, 0.0f, 0.0f, 0.0f);
const Vector4 Vector4::YAXIS(0.0f, 1.0f, 0.0f, 0.0f);
const Vector4 Vector4::ZAXIS(0.0f, 0.0f, 1.0f, 0.0f);
const Vector4 Vector4::WAXIS(0.0f, 0.0f, 0.0f, 1.0f);

} // namespace RAD
