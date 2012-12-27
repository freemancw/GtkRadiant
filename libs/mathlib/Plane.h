/*!
 *  @file Plane.h
 *  @author Clinton Freeman
 *  @date 12/26/2012
 */

#ifndef PLANE_H
#define PLANE_H

#include "Vector.h"

namespace RAD
{

//============================================================================
// Interface
//============================================================================
  
class Plane
{
public:
    Vector3f n;
    float d;

    Plane();
    explicit Plane(const Vector3f& n, const float d);

    enum Side { FRONT, BACK, ON };
    Side pClassifyPoint(const Vector3f& p) const;
};

//============================================================================
// Inline Implementations
//============================================================================
    
inline Plane::Plane() :
    d(0.0f) {}

inline Plane::Plane(const Vector3f& n, const float d) :
    n(n), d(d) {}

} // namespace RAD

#endif // PLANE_H