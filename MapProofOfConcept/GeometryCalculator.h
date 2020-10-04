#include "Vector3d.h"

#pragma once
class GeometryCalculator
{
public:
	double CalculateDistanceBetweenTwo3dPoints(Vector3d start, Vector3d target);
	Vector3d CalculateVectorToTargetTile(Vector3d start, Vector3d target);
};

