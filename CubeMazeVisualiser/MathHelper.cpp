#include "MathHelper.h"

Vector2f linearToIsometric(const Vector3f& point, const RenderWindow& window)
{
	Vector2f temp;
	int halfSize = Block::SIZE / 2;
	temp.x = ((point.x * halfSize) + (point.y * -halfSize)) + window.getSize().x / 2;
	temp.y = (point.x * halfSize / 2) + (point.y * halfSize / 2);
	temp.y -= point.z * halfSize;
	return temp;
}