/*!
 *  @file Vector.cpp
 *  @author Clinton Freeman
 *  @date 12/26/2012
 */

#include "Vector.h"

namespace RAD
{

template<typename T, const size_t N>
const Vector<T, N> Vector<T, N>::ZERO;

const Vector2f Vector2f::XAXIS(1.0f, 0.0f);
const Vector2f Vector2f::YAXIS(0.0f, 1.0f);

const Vector3f Vector3f::XAXIS(1.0f, 0.0f, 0.0f);
const Vector3f Vector3f::YAXIS(0.0f, 1.0f, 0.0f);
const Vector3f Vector3f::ZAXIS(0.0f, 0.0f, 1.0f);

const Vector4f Vector4f::XAXIS(1.0f, 0.0f, 0.0f, 0.0f);
const Vector4f Vector4f::YAXIS(0.0f, 1.0f, 0.0f, 0.0f);
const Vector4f Vector4f::ZAXIS(0.0f, 0.0f, 1.0f, 0.0f);
const Vector4f Vector4f::WAXIS(0.0f, 0.0f, 0.0f, 1.0f);

} // namespace RAD
