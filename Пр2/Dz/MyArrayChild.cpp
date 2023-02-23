#include <iostream>
#include "MyArrayParent.cpp"

using namespace std;
namespace dz
{
	class MyArrayChild : public MyArrayParent
	{
	protected:
		double CountAverage()
		{
			double summ =0;
			double middle;
			for (int i = 0; i < sizeof(ptr); i++)
			{
				summ += ptr[i];
			}
			middle = summ / sizeof(ptr);
			return middle;
		}
	public:
		//используем конструктор родителя. Нужно ли что-то ещё?
		MyArrayChild(int Dimension = 100) : MyArrayParent(Dimension)
		{
			cout << "\nMyArrayChild constructor";
		}
		MyArrayChild(const MyArrayChild& obj)
		{
			this->capacity = obj.capacity;
			this->count = obj.count;
			this->ptr = new double[sizeof(obj.ptr)];
			for (int i = 0; i < sizeof(obj.ptr); i++)
			{
				this->ptr[i] = obj.ptr[i];
			}
		}
		~MyArrayChild() { cout << "\nMyArrayChild destructor\n"; }
		
		void RemoveAt(int &index)
		{
			for (int i = index; i < capacity; i++)
			{
				if (i == capacity - 1)
				{
					ptr[i] = NULL;
					return;
				}
				ptr[i] = ptr[i + 1];
			}
		}
		double IndexOf(double element)
		{
			for (int i = 0; i < capacity; i++)
			{
				if (ptr[i] = element)
				{
					return i;
				}
			}
			return NULL;
		}
		void InsertAt(int index, double value)
		{
			
			for (int i = index + 1; i < capacity-1; i++)
			{
				ptr[i] = ptr[i + 1];
			}
			ptr[index] = value;
		}

		//Задание 2.2.4 вариант 19
		MyArrayChild ReplaceRepeatingWithAverage()
		{
			double avg = CountAverage();
			MyArrayChild* result = new MyArrayChild(*this);
			MyArrayChild *uniqueElems = new MyArrayChild((sizeof(ptr)));
			for (int i = 0; i < sizeof(ptr); i++)
			{
				if (uniqueElems->IndexOf(ptr[i]) == NULL)
				{
					uniqueElems->push(ptr[i]);
				}
				result[i] = avg;
			}
			return *result;
		}

		
	};
}
