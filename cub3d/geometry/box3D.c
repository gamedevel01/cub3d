#include "box3D.h"

t_box3D     constructBox(t_vector3D leftDown, t_vector3D rightUp)
{
    t_box3D box;

    box.center = mult3D(sum3D(leftDown, rightUp), 0.5);
    box.halfSizes = diff3D(rightUp, box.center);
    box.halfSizes.xCoordinate = ABS(box.halfSizes.xCoordinate);
    box.halfSizes.yCoordinate = ABS(box.halfSizes.yCoordinate);
    box.halfSizes.zCoordinate = ABS(box.halfSizes.zCoordinate);
    return box;
}
BOOL        checkPointInBox(t_box3D box, t_vector3D point)
{
    t_vector3D dirToPoint = diff3D(point, box.center);

    dirToPoint.xCoordinate = ABS(dirToPoint.xCoordinate);
    dirToPoint.yCoordinate = ABS(dirToPoint.yCoordinate);
    dirToPoint.zCoordinate = ABS(dirToPoint.zCoordinate);
    return dirToPoint.xCoordinate < box.halfSizes.xCoordinate &
           dirToPoint.yCoordinate < box.halfSizes.yCoordinate &
           dirToPoint.zCoordinate < box.halfSizes.zCoordinate;
}

t_rect3D    constructSide(t_box3D box, int dim, BOOL isMinSide/*какая из граней будет выбрана*/)
{
    t_vector3D  axises[] = {
        constructPoint3D(1., 0., 0.),
        constructPoint3D(0., 1., 0.),
        constructPoint3D(0., 0., 1.)
    };
    t_vector3D axis = axises[dim];
    if (isMinSide)
        axis = mult3D(axis, -1);
    t_rect3D rect;

    double      sideSizes[] = {
        box.halfSizes.xCoordinate,
        box.halfSizes.yCoordinate,
        box.halfSizes.zCoordinate
    };

    rect.center = sum3D(box.center, mult3D(axis, sideSizes[dim]));
    t_vector3D* rectAxis[] = {
        &rect.rightDirection,
        &rect.upDirection
    };

    int axisNum = 0;

    for (int rectAxisNum = 0; rectAxisNum < 2; ++rectAxisNum)
    {
        t_vector3D* rectAxisPtr;

        rectAxisPtr = rectAxis[rectAxisNum];
        for (; axisNum < 3; ++axisNum)
        {
            if (axisNum == dim)
                continue;
            *rectAxisPtr = axises[axisNum];
            break;
        }
    }
    return rect;
}