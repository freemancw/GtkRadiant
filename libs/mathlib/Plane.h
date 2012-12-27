/*!
 *  @file Plane.h
 *  @author Clinton Freeman
 *  @date 12/26/2012
 */

#ifndef PLANE_H
#define PLANE_H

#include <assert.h>
#include <math.h>


namespace RAD
{

//============================================================================
// Interface
//============================================================================
    /*
class Plane
{
public:
    Vector3 n;
    float d;

    Plane();
    explicit Plane(const Vector3& n, const float d);

    enum Side
    {
        FRONT, BACK, ON
    };

    Side classifyPoint(const Vector3& p) const;
};*/

//============================================================================
// Inline Implementations
//============================================================================
    /*
inline Plane::Plane() :
    n(Vector3::ZERO), d(0.0f) {}

inline Plane::Plane(const Vector3& n, const float d) :
    n(n), d(d) {}*/

} // namespace RAD

#endif // PLANE_H