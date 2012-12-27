/*!
 *  @file Polyhedron.h
 *  @author Clinton Freeman
 *  @date 12/26/2012
 */

#ifndef POLYHEDRON_H
#define POLYHEDRON_H

#include <vector>
#include "Plane.h"
#include "Point.h"
#include "Vector.h"

namespace RAD
{

//============================================================================
// Interface
//============================================================================

class Polyhedron
{
public:
    std::vector<Vector3f> vertices;

    Polyhedron();
};

//============================================================================
// Inline Implementations
//============================================================================

inline Polyhedron::Polyhedron() {}

} // namespace RAD

#endif // POLYHEDRON_H