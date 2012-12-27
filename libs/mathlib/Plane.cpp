/*!
 *  @file Plane.cpp
 *  @author Clinton Freeman
 *  @date 12/26/2012
 */

#include "Plane.h"

namespace RAD
{
    
Plane::Side Plane::pClassifyPoint(const Point3f& p) const
{
    return Side::ON;
}

} // namespace RAD