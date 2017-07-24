#include <iostream>
using namespace std;
#include <assert.h>


typedef int DataType;
class Vector
{
public:
	explicit Vector(size_t capacity = 3);

	// 有size个值为data的元素
	Vector(size_t n, const DataType& data)
	{
		size_t i = 0;
		_pData = new DataType[n];
		for(; i < n; ++i)
		{
			_pData[i] = data;
		}
		_size = n;
		_capacity = n;
	}

	Vector(const Vector& v)
		: _capacity(v._capacity)
		, _size(v._size)
	{
		_pData = new DataType[_capacity];

		//memcpy(_pData, v._pData, sizeof(DataType)*_size);

		// 2
		for(size_t idx = 0; idx < _size; ++idx)
			_pData[idx] = v._pData[idx];
	}

	Vector& operator=(const Vector& v)
	{
		size_t i = 0;
		if(this != &v)
		{
			delete[] _pData;
			_capacity = v._capacity;
			_size = v._size;
			_pData = new DataType[_capacity];
			for(; i < _size; i++)
			{
				_pData[i] = v._pData[i];
			}
		}
		return *this;
	}	

	~Vector()
	{
		delete[] _pData;
		_pData = NULL;
		_size = 0;
		_capacity = 0;
	}


	void Rerese(size_t _newcapacity)
	{
		size_t i = 0;
		if(_newcapacity < _capacity)
			return ;
		DataType* _oldpData = _pData;
		_pData = new DataType[_newcapacity];
		for(; i < _capacity; i++)
		{
			_pData[i] = _oldpData[i];
		}
		_capacity = _newcapacity;
		delete[] _oldpData;
	}

	void PushBack(const DataType& data)
	{
		if(_size == _capacity)
		{
			Rerese(_capacity * 2+1);
		}
		_pData[_size++] = data;
	}
	void PopBack()
	{
		_size--;
	}
	void Insert(size_t pos, const DataType& data)
	{
		size_t i = _size;
		for(; pos < i; --i)
		{
			_pData[i] = _pData[i-1];
		}
		_pData[pos] = data;
		++_size;
	}
	void Erase(size_t pos)
	{
		size_t i = pos;
		for(; i < _size-1; i++)
		{
			_pData[i] = _pData[i+1];
		}
		--_size;
	}
	int Find(const DataType& data)const
	{
		size_t i = 0;
		for(; i < _size; ++i)
		{
			if(_pData[i] == data)
			{
				return i;
			}
		}
		return -1;
	}
	void Clear()
	{
		_size = 0;
		_pData = NULL;
	}
	size_t Size()const
	{
		return _size;
	}
	void ReSize(size_t size, const DataType& data = DataType())
	{
		size_t i = _size;
		if((size+_size) >= _capacity)
		{
			Rerese(_capacity * 2+1);
		}
		for(; i < size+_size; ++i)
		{
			_pData[i] = data;
		}
		_size = size;

	}
	size_t Capacity()const
	{
		return _capacity;
	}
	bool Empty()const
	{
		if(_size == 0)
			return true;
		return false;
	}
	DataType& Front()
	{
		return _pData[0];
	}
	const DataType& Front()const
	{
		return _pData[0];
	}
	DataType& Back()
	{
		return _pData[_size-1];
	}
	const DataType& Back()const
	{
		return _pData[_size-1];
	}
	void Assign(size_t n, const DataType& data = DataType())
	{
		size_t i = 0;
		_pData = new DataType[n];
		for(; i < n; ++i)
		{
			_pData[i] = data;
		}
		_size = n;
	}
	DataType& operator[](size_t index)
	{

		return _pData[index];
	}
	const DataType& operator[](size_t index)const
	{

		return _pData[index];
	}
	DataType& At(size_t index)
	{

		return _pData[index];
	}
	const DataType& At(size_t index)const
	{

		return _pData[index];
	}

private:
	void _CheckCapacity();
	friend std::ostream& operator<<(std::ostream& _cout, const Vector& v);
private:
	DataType* _pData;
	size_t _capacity;
	size_t _size;
};


void Funtest1()
{
	int i = 0;
	Vector v1(0,0);
	//Vector v2(v1);
	//v1.PushBack(3);
	//v1.PopBack();
	//i = v1.At(2);
	//i = v1[2];
	//v1.Assign(3,5);
	//v1.ReSize(3,6);
	//Vector v1;
	v1.PushBack(3);
	v1.PushBack(6);
	v1.PushBack(11);
	v1.PushBack(4);
	v1.PushBack(6);
	v1.PushBack(9);
	v1.PushBack(8);
	v1.PushBack(1);
	//i = v1.Find(4);
	v1.Erase(3);
}

int main()
{
	Funtest1();
	return 0;
}