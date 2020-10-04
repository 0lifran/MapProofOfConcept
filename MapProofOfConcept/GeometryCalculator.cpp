#include "GeometryCalculator.h"
#include <Math.h>

double GeometryCalculator::CalculateDistanceBetweenTwo3dPoints(Vector3d start, Vector3d target)
{
	return sqrt(
		pow(target.X() - start.X(),2) +
		pow(target.Y() - start.Y(),2) +
		pow(target.Z() - start.Z(),2));
}

Vector3d GeometryCalculator::CalculateVectorToTargetTile(Vector3d start, Vector3d target)
{
	return *new Vector3d(
		target.X() - start.X(),
		target.Y() - start.Y(),
		target.Z() - start.Z());
}


