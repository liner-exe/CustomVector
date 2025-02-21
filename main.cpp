#include <iostream>
#include <vector>
#include <type_traits>

template <typename T>
class myVector
{
	T* m_pData;
	size_t m_size;


public:
	myVector(): m_pData(nullptr), m_size(0) {}

	myVector(std::initializer_list<T> list): m_size(list.size())
	{
		m_pData = new T[m_size];

		size_t i = 0;
		for (const T &item : list)
		{
			m_pData[i++] = item;
		}
	}

	~myVector()
	{
		delete[] m_pData;
	}

	size_t sizeOf() const
	{
		return m_size;
	}

	T at(size_t index)
	{
		return m_pData[index];
	}

	T& operator[](size_t index) const
	{
		return m_pData[index];
	}

	bool operator==(const myVector& other)
	{
		if (this->sizeOf() != other.sizeOf())
			return false;

		for (size_t i = 0; i < this->sizeOf(); i++)
		{
			if (m_pData[i] != other.m_pData[i])
			{
				return false;
			}
		}

		return true;
	}

	bool operator!=(const myVector& other)
	{
		if (this->sizeOf() != other.sizeOf())
			return true;

		for (size_t i = 0; i < this->sizeOf(); i++)
		{
			if (m_pData[i] != other.m_pData[i])
			{
				return true;
			}
		}
		
		return false;
	}

	myVector<T> operator+(const myVector& other)
	{
		myVector<T> newVector;

		for (size_t i = 0; i < m_size; i++)
		{
			newVector.push_back(m_pData[i]);
		}

		for (size_t i = 0; i < other.m_size; i++)
		{
			newVector.push_back(other.m_pData[i]);
		}

		return newVector;
	}

	myVector<T> operator+=(const myVector& other)
	{
		for (size_t i = 0; i < other.m_size; i++)
		{
			this->push_back(other[i]);
		}

		return *this;
	}

	void push_back(const T& item)
	{
		T* newData = new T[m_size + 1];

		for (size_t i = 0; i < m_size; i++)
		{
			newData[i] = m_pData[i];
		}

		delete[] m_pData;
		newData[m_size++] = item;
		m_pData = newData;

	}

	bool compareTo(const myVector& other)
	{
		if (this->sizeOf() != other.sizeOf())
			return false;

		for (size_t i = 0; i < this->sizeOf(); i++)
		{
			if (m_pData[i] != other.m_pData[i])
			{
				return false;
			}
		}

		return true;
	}

	void print()
	{
		for (int i = 0; i < this->sizeOf(); i++)
		{
			std::cout << m_pData[i] << " ";
		}

		std::cout << std::endl;
	}

};

int main()
{
	myVector<int> vec1 = {1, 2, 3};
	myVector<int> vec2 = {4, 5, 6};

	myVector<int> vec3 = {1, 2};
	vec3 += vec2;

	vec3.print();
}
