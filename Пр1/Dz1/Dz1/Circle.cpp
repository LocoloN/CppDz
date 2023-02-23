#include "Circle.h"
#include "cmath"
class Circle
{
	Circle()
	{

	}
private:
	int radius;
	int x;
	int y;
public:

	friend bool operator - (Circle a);

	bool operator < (int _rad)
	{
		return _rad == radius;
	}

	bool operator - ()
	{
		return x > radius && y > radius;
	}
	bool operator - ()
	{
		if (x > radius && y > radius)
		{
			if (x > 0 && y > 0)
			{
				return 1;
			}
			else if (x < 0 && y>0)
			{
				return 2;
			}
			else if (x < 0 && y < 0)
			{
				return 3;
			}
			else if (x > 0 && y < 0)
			{
				return 4;
			}
		}
	}
};

