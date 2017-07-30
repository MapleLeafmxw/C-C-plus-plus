#include <ostream>
using namespace std;

class Complex
{
public:
	Complex(const double _dreal = 10, const double _dimagle = 10)
		:_real(_dreal)
		,_imagle(_dimagle)
	{}

	Complex(const Complex& d)
		:_real(d._real)
		,_imagle(d._imagle)
	{}

	~Complex()
	{}

	Complex& operator=(const Complex& complex)
	{
		_real = complex._real;
		_imagle = complex._imagle;
		return *this;
	}
	Complex operator+(const Complex& complex)
	{
		Complex temp(*this);
		temp._real = temp._real + complex._real;
		temp._imagle = temp._imagle + complex._imagle;
		return temp;
	}
	Complex operator-(const Complex& complex)
	{
		Complex temp(*this);
		temp._real = temp._real - complex._real;
		temp._imagle = temp._imagle - complex._imagle;
		return temp;		
	}
	Complex operator*(const Complex& complex)
	{
		Complex temp(*this);
		temp._real = temp._real*complex._real - temp._imagle*complex._imagle;
		temp._imagle = temp._real*complex._imagle + temp._imagle*complex._real;
		return temp;
	}
	Complex operator/(const Complex& complex)
	{
		double f1,f2,f3,f4;
		Complex temp(*this);
		f1 = temp._real*complex._real + temp._imagle*complex._imagle;
		f2 = complex._real*complex._real + complex._imagle*complex._imagle;
		f3 = temp._imagle*complex._real - temp._real*complex._imagle;
		f4 = complex._real*complex._real + complex._imagle*complex._imagle;
		if(f2 != 0 && f4 != 0)
		{
			temp._real = f1 / f2;
			temp._imagle = f3 / f4;
			return temp;
		}
		else
		{
			temp._real = 0;
			temp._imagle = 0;
			return temp;
		}
	}
	Complex& operator+=(const Complex& complex)
	{
		_real += complex._real;
		_imagle += complex._imagle;
		return *this;
	}
	Complex& operator-=(const Complex& complex)
	{
		_real -= complex._real;
		_imagle -= complex._imagle;
		return *this;
	}
	Complex& operator*=(const Complex& complex)
	{
		_real = _real*complex._real - _imagle*complex._imagle;
		_imagle = _real*complex._imagle + _imagle*complex._real;
		return *this;
	}
	Complex& operator/=(const Complex& complex)
	{
		double f1,f2,f3,f4;
		f1 = _real*complex._real + _imagle*complex._imagle;
		f2 = complex._real*complex._real + complex._imagle*complex._imagle;
		f3 = _imagle*complex._real - _real*complex._imagle;
		f4 = complex._real*complex._real + complex._imagle*complex._imagle;
		if(f2 != 0 && f4 != 0)
		{
			_real = f1 / f2;
			_imagle = f3 / f4;
			return *this;
		}
		else
		{
			_real = 0;
			_imagle = 0;
			return *this;
		}
	}
	bool operator>(const Complex& complex)
	{
			Complex temp(*this);
			if((temp._real > complex._real) ||
				(temp._real == complex._real && temp._imagle > complex._imagle))
				return true;
			return false;
	}
	bool operator>=(const Complex& complex)
	{
		Complex temp(*this);
		if((temp._real >= complex._real) ||
			(temp._real == complex._real && temp._imagle >= complex._imagle))
			return true;
		return false;
	}
	bool operator<(const Complex& complex)
	{
			Complex temp(*this);
			return !((temp > complex) || (temp == complex));
	}
	bool operator<=(const Complex& complex)
	{
		Complex temp(*this);
		if((temp._real <= complex._real) ||
			(temp._real == complex._real && temp._imagle <= complex._imagle))
			return true;
		return false;
	}
	bool operator==(const Complex& complex)
	{
		Complex temp(*this);
		if((temp._real == complex._real && temp._imagle == complex._imagle))
			return true;
		return false;
	}
	bool operator!=(const Complex& complex)
	{
		Complex temp(*this);
		if((temp._real != complex._real || temp._imagle != complex._imagle))
			return true;
		return false;
	}
	
private:
	double _real;
	double _imagle;
};

void Funtest()
{
	Complex d1(5, 9);
	Complex d2(3, 2);
	Complex d3(d1);
	Complex d4;
	//d4 = d2;
	//d4 = d2 + d1;
	d4 = d1 * d2;
	d4 = d1 / d2;
}



int main()
{
	Funtest();
	return 0;
}