#include <iostream>
using namespace std;

#pragma warning (disable:4996)

/*
ǳ����
ֻ�ǽ�����ָ��ͬʱָ����ͬһ���ռ���Ҳ��ܶ����ͷ����е�һ��
��ֵһ��������Ҳ��ı�
class String
{
public:
	String(const char* pStr = "")
		:_pStr(pStr)
	{}
	String(const String& s)
		:_pStr(s._pStr)
	{}

	String& operator=(const String& s)
		:_pStr(s._pStr)
	{
		return *this;
	}

	~String()
	{
		if(NULL != _pStr)
		{
			delete _pStr;
			_pStr = NULL;
		}
	}

private:
	char* _pStr;
};
*/




//���
//�ŵ㣺�����ǳ�����н�����ָ��ָ��ͬһ���ռ䣬һ���ı��������ı�
//����һ�����ͷ�����Ҳ���ͷŲ��ܶ����ͷŵ����⣬���ڸ�ÿ��ָ�붼������
//�Լ��Ŀռ�
//ȱ�㣺��Դ�˷�̫��ÿ������ָ���Լ��Ŀռ䵫�����ǵ�����һ�����˷�����Դ
class String
{
public:
	String(const char* pStr = "")
	{
		if(NULL == pStr)
		{
			_pStr = new char[1];
			*_pStr = '\0';
		}
		else
		{
			_pStr = new char[strlen(pStr)+1];
			strcpy(_pStr, pStr);
		}
	}
	String(const String& s)
		:_pStr(new char[strlen(s._pStr)+1])
	{
		strcpy(_pStr, s._pStr);
	}

	String& operator=(const String& s)
	{
		if(this != &s)
		{
			char* _pTmp = new char[strlen(s._pStr)+1];
			strcpy(_pTmp, s._pStr);
			delete[] _pStr;
			_pStr = _pTmp;
		}
		return *this;
	}
	size_t Size()const
	{
		int count = 0;
		count = Lengh() + 1;
		return count;
	}
	size_t Lengh()const
	{
		char* _sTemp = _pStr;
		int count = 0;
		while(*_sTemp++)
		{
			count++;
		}
		return count;
	}
	char& operator[](size_t index)
	{
		return _pStr[index];
	}
	const char& operator[](size_t index)const
	{
		return _pStr[index];
	}
	bool operator>(const String& s)
	{
		char* _sTemp = s._pStr;
		while(1)
		{
			if(*_pStr > *_sTemp)
			{
				return true;
			}
			else if(*_pStr < *_sTemp)
			{
				return false;
			}
			else
			{
				_pStr++;
				_sTemp++;
			}
		}
	}
	bool operator<(const String& s)
	{	
		char* _sTemp = s._pStr;
		while(1)
		{
			if(*_pStr > *_sTemp)
			{
				return false;
			}
			else if(*_pStr < *_sTemp)
			{
				return true;
			}
			else
			{
				_pStr++;
				_sTemp++;
			}
		}
	}
	bool operator==(const String& s)
	{
		char* _sTemp = s._pStr;
		while(*_pStr == *_sTemp && *_pStr != '\0' && *_sTemp != '\0')
		{
			_pStr++;
			_sTemp++;
		}
		if( *_pStr == '\0' && *_sTemp == '\0')
		{
			return true;	
		}
		return false;

	}
	bool operator!=(const String& s)
	{
		return !(_pStr == s._pStr);
	}
	void Copy(const String& s)
	{
		char* _pStr1 = _pStr;
		char* _sTemp = s._pStr;
		while(*_pStr1++ = *_sTemp++)
		{
			;
		}
	}
	bool strstr(const String& s)
	{
		char* _sTemp = s._pStr;
		int i = 0;
		int tem = 0;
		int j = 0;
		for(i = 0; _pStr[i] != '\0'; i++)
		{
			tem = i;
			j = 0;
			while(_pStr[i++] == _sTemp[j++])
			{
				if(_sTemp[j] == '\0')
				{
					return true;
				}
			}
			i = tem;
		}
		return false;
	}
	String& operator+=(const String& s);

	~String()
	{
		if(NULL != _pStr)
		{
			delete[] _pStr;
			_pStr = NULL;
		}
	}

private:
	char* _pStr;
};

void Funtest()
{
	bool ret;
	//String c("12345");
	//ret = c.Lengh();
	//cout<<"Lengh = "<<ret<<endl;
	//ret = c.Size();
	//cout<<"Size = "<<ret<<endl;
	String c1("abcdef");
	String c2("cde");
	//c1 > c2;
	c1 = c2;
	//c1.Copy(c2);
	ret = c1.strstr(c2);
}

int main()
{
	Funtest();
	return 0;
}


/*
//���--����
class String
{
public:
	String(const char* pStr = "")
	{
		if(NULL == pStr)
		{
			_pStr = new char[1];
			*_pStr = '\0';
		}
		else
		{
			_pStr = new char[strlen(pStr)+1];
			strcpy(_pStr, pStr);
		}
	}
	String(const String& s)
		:_pStr(new char[strlen(s._pStr)+1])
	{
		String sTmp(s._pStr);
		std::swap(_pStr, sTmp._pStr);
	}

	String& operator=(const String& s)
	{
		if(this != &s)
		{
			String sTmp(s);
			std::swap(_pStr, sTmp._pStr);
		}
	}

	~String()
	{
		if(NULL != _pStr)
		{
			delete[] _pStr;
			_pStr = NULL;
		}
	}

private:
	char* _pStr;
};
*/


/*
���ü���--���ÿռ�
���з��������ָ����Թ���һ���ռ䣬���Դ����ٿռ俪�ٵ��˷�
���Ҹ���ָ����ԵĿռ��Լ����ͷź������޹أ���������ȱ���ǲ���
�޸����е�ֵ����Ϊ���е�һ�ģ���������ָ��ͬһ��ռ��ֵҲ���
�Ÿı䡣
class String
{
public:
	String(const char* pStr = "")
		: _count(new int(1))
	{
		if(NULL == pStr)
		{
			_pStr = new char[1];
			*_pStr = '\0';
		}
		else
		{
			_pStr = new char[strlen(pStr)+1];
			strcpy(_pStr, pStr);
		}
	}
	String(const String& s)
		: _pStr(s._pStr)
		, _count(s._count)
	{
		++*(_count);
	}

	String& operator=(const String& s)
	{
		if(this != &s)
		{
			--(*_count);
			if(*_count == 0)
			{
				delete[] _pStr;
				delete _count;
			}
			_pStr = s._pStr;
			_count = s._count;
			++(*_count);
		}
		return *this;
	}
	~String()
	{
		if(0 == --(*_count) && _count)
		{
			delete[] _pStr;
			delete _count;
			_pStr = NULL;
			_count = NULL;
		}
	}

private:
	char* _pStr;
	int* _count;
};

void Funtest()
{
	String s1("11111");
	String s2("2222");
	String s3(s2);
	//s1 = s3;
	s3 = s1;
}

int main()
{
	Funtest();
	return 0;
}
*/


/*
//дʱ����
class String
{
public:
	String(const char* pStr = "")
	{
		if(NULL == pStr)
		{
			_pStr = new char[1+4];
			_pStr += 4;
			*_pStr = '\0';
		}
		else
		{
			_pStr = new char[strlen(pStr)+1+4];
			_pStr += 4;
			strcpy(_pStr, pStr);
		}
		GetRef() = 1;
	}
	String(const String& s)
		: _pStr(s._pStr)
	{
		++GetRef();
	}

	String& operator=(const String& s)
	{
		if(this != &s)
		{
			Release();
			_pStr = s._pStr;
			++GetRef();
		}
		return *this;
	}
	~String()
	{
		Release();
	}

	int& GetRef()
	{
		return *((int*)_pStr-1);
	}
	void Release()
	{
		if(0 == --GetRef())
		{
			_pStr -= 4;
			delete[] _pStr;
			_pStr = NULL;
		}
	}
	char& operator[](size_t index)//��ֵ
	{
		if(GetRef() > 1)
		{
			char* sTemp = new char[strlen(_pStr)+1+4];
			sTemp += 4;
			strcpy(sTemp, _pStr);
			--GetRef();
			_pStr = sTemp;
			GetRef() = 1;
		}
		return _pStr[index];
	}
	const char& operator[](size_t index)const//��ֵ
	{
		return _pStr[index];
	}


private:
	char* _pStr;
};

void FunTest()
{
	char str[] = "111111";

	String s1("1111");
	String s2(s1);

	s1[0] = '0';
	s2[0] = '2';

	const String s3("22222");
	char c = s3[0];
}

int main()
{
	FunTest();
	return 0;
}
*/