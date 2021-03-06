#pragma once

namespace Math
{

	//pi conversions
	const float Rad2Deg = 180.0f / float(M_PI);
	const float Deg2Rad = float(M_PI) / 180.0f;

	
	inline float CalculateAngle(float x1, float y1, float x2, float y2)
	{
		float dy = y2 - y1;
		float dx = x2 - x1;

		float angle = atan2(dy, dx);

		return angle;
	}

	inline float CalculateAngle(float x, float y)
	{
		return atan2(y, x);
	}
}


namespace WG
{
	struct Vector2
	{
		Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y){}
		float x, y;
	};
}