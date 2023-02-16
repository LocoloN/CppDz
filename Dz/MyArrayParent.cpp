
#include <iostream>
using namespace std;
namespace dz
{

	class MyArrayParent
	{
	protected:
		//сколько памяти выделено?
		int capacity;
		//количество элементов - сколько памяти используем
		int count;
		//массив
		double* ptr;
	public:
		//конструкторы и деструктор
		MyArrayParent(int Dimension = 100)
		{
			cout << "\nMyArray constructor";
			ptr = new double[Dimension];
			capacity = Dimension;
			count = 0;
		}
		//конструктор принимает существующий массив
		MyArrayParent(double* arr, int len)
		{
			cout << "\nMyArray constructor";
			this->ptr = new double[sizeof(len)];
			this->capacity = len;
			for (int i = 0; i < len; i++)
			{
				if (arr[i] != NULL)
				{
					this->count++;
					this->ptr[i] = arr[i];
				}
			}

		}
		MyArrayParent(const MyArrayParent& obj)
		{
			this->capacity = obj.capacity;
			this->count = obj.count;
			this->ptr = new double[sizeof(obj.ptr)];
			for (int i = 0; i < sizeof(obj.ptr); i++)
			{
				this->ptr[i] = obj.ptr[i];
			}
		}

		//деструктор
		~MyArrayParent()
		{
			cout << "\nMyArray destructor";
			if (ptr != NULL)
			{
				delete[] ptr;
				ptr = NULL;
			}
		}
		//обращение к полям
		int Capacity() { return capacity; }
		int Size() { return count; }

		double GetComponent(int index)
		{
			if (index >= 0 && index < count)
				return ptr[index];
			//сгенерировать исключение, если индекс неправильный
			return -1;
		}
		void SetComponent(int index, double value)
		{
			if (index >= 0 && index < count)
				ptr[index] = value;
			//сгенерировать исключение, если индекс неправильный
		}
		//добавление в конец нового значения
		void push(double value)
		{
			if (count < capacity)
			{
				ptr[count] = value;
				count++;
			}
			//что делаем, если массив заполнен?
		}
		//удаление элемента с конца
		void RemoveLastValue()
		{
			if (count >= 0)
				count--;
			//что делаем, если пуст?
		}
		double& operator[](int index)
		{
			return ptr[index];
		}

		MyArrayParent& operator=(const MyArrayParent& obj)
		{
			cout << endl << "operator = ";

			this->capacity = obj.capacity;
			this->count = obj.count;
			this->ptr = new double[sizeof(obj.ptr)];
			for (int i = 0; i < sizeof(obj.ptr); i++)
			{
				this->ptr[i] = obj.ptr[i];
			}
			return *this;
		}
		void MyArray(const MyArrayParent& V)
		{
			cout << "\nCopy constructor";
			//создание копии объекта - в основном, при возвращении результата из функции / передаче параметров в функцию
		}
		void print()
		{
			cout << "\nMyArr, size: " << count << ", values: {";
			int i = 0;
			for (i = 0; i < count; i++)
			{
				cout << ptr[i];
				if (i != count - 1)
					cout << ", ";
			}
			cout << "}";
		}
	};
}
