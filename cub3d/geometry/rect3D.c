#include "rect3D.h"

#include <stdio.h>

t_vector3D  normalRect(t_rect3D rect)
{
    return crossVectors3D(rect.rightDirection, rect.upDirection);
}
double      distToRect(t_rect3D rect, t_vector3D point)
{
    t_plane plane;
    
    plane = constructPlane(rect);
    double distToPlaneRect;

    distToPlaneRect = ABS(distToPlane(plane, point));

    t_vector3D projection;

    projection = projectToPlane(plane, point);

    if (inRect(rect, localCoordinate(rect, projection)))
        return distToPlaneRect;
    double minDistToEdge = -1;
    for (int xDim = -1; xDim <= 1; xDim += 2)
    {
        for (int yDim = -1; yDim <= 1; yDim += 2)
        {
            t_vector2D edgeLocal;

            edgeLocal.xCoordinate = rect.halfSizes.xCoordinate * xDim;
            edgeLocal.yCoordinate = rect.halfSizes.yCoordinate * yDim;

            t_vector3D worldEdge;

            worldEdge = localToWorld(rect, edgeLocal);
            double distToEdge;
            
            distToEdge = distance(point, worldEdge);
            if (minDistToEdge < 0. || distToEdge < minDistToEdge)
                minDistToEdge = distToEdge;
        }
    }
    return minDistToEdge;
}
t_plane     constructPlane(t_rect3D rect)
{
    t_plane plane;

    plane.normal = normalRect(rect);
    plane.bias   = dot3D(plane.normal, rect.center);
    return plane;
}

t_vector2D  localCoordinate(t_rect3D rect, t_vector3D point)
{
    t_vector2D local;

    local.xCoordinate = dot3D(diff3D(point, rect.center), rect.rightDirection);
    local.yCoordinate = dot3D(diff3D(point, rect.center), rect.upDirection);
    return local;
}

BOOL        inRect(t_rect3D rect, t_vector2D localCoordinate)
{
    return ABS(localCoordinate.xCoordinate) < rect.halfSizes.xCoordinate &
           ABS(localCoordinate.yCoordinate) < rect.halfSizes.yCoordinate;
}

t_vector3D  localToWorld(t_rect3D rect, t_vector2D localCoordinate)
{
    return sum3D(rect.center, sum3D(
        mult3D(rect.rightDirection, localCoordinate.xCoordinate),
        mult3D(rect.upDirection, localCoordinate.yCoordinate)
    ));
}