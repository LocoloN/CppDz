#include <iostream>
#include "MyArrayChild.cpp"
#include <algorithm>
using namespace std;
namespace dz
{
	class MySortedArray : MyArrayChild
	{
	public:
		MySortedArray(int Dimension) : MyArrayChild(Dimension)
		{
			sort(ptr, ptr + Dimension);
		}

		void push(double value)
		{
			int I;
			for (int i = 0;i<sizeof(ptr) ; i++)
			{
				if (value > ptr[i])
				{
					continue;
				}
				I = i;
			}
			InsertAt(I, value);
		}
	};
}