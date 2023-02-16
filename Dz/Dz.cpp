
#include <iostream>
#include "MyArrayParent.cpp"

using namespace std;
using namespace dz;


int main()
{
	if (true)
	{
		MyArrayParent arr;
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			arr.push(i + 1);
		}
		MyArrayParent p1;
		p1 = arr;
		p1.print();
		cout << "\n";
	}



	char c; cin >> c;
	return 0;
}


