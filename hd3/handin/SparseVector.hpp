#ifndef SPARSE_VECTOR_HPP
#define SPARSE_VECTOR_HPP

#include "Vector.hpp"
#include "Matrix.hpp"
#include <iostream>
#include <algorithm>

template <class T>
class SparseVector
{
private:
	// Add your data members here!
	// Nonnegative dimension
	unsigned int mdim;
	// Indices
	std::vector<int> mIndex;
	// Values
	std::vector<T> mData;

public:
	SparseVector();
	SparseVector(unsigned int dim);
	void setValue(unsigned int index, T value);
	T getValue(unsigned int index) const;
	unsigned int size() const;
	unsigned int nonZeroes() const;
	unsigned int indexNonZero(unsigned int i) const;
	T valueNonZero(unsigned int i) const;
	SparseVector<T> &operator+=(SparseVector<T> const &x);
	SparseVector<T> &operator-=(SparseVector<T> const &x);
	//void print();
};

// Creates an empty vector of dimensionality 0.
template <class T>
SparseVector<T>::SparseVector()
{
	mdim = 0;
	mIndex = std::vector<int>(0, 0);
	mData = std::vector<T>(0, 0);
}
// Creates a vector of dimensionality dim. It starts with 0 nonzero elements
// which need to be set using setValue
template <class T>
SparseVector<T>::SparseVector(unsigned int dim)
{
	mdim = dim;
	mIndex = std::vector<int>(0, 0);
	mData = std::vector<T>(0, 0);
}

//Insert index and values
template <class T>
void SparseVector<T>::setValue(unsigned int index, T value)
{
	// Sets the value v_i of the vector
	// Check if there is collision on index
	if (mIndex.size() > 0 && mData.size() > 0)
	{
		// If has collision
		auto pos = std::find(mIndex.begin(), mIndex.end(), index);
		if (pos != mIndex.end())
		{
			mData[std::distance(mIndex.begin(), pos)] = value;
		}
		// No collision
		else
		{
			mIndex.push_back(index);
			// Sort mIndex to increasing order
			std::sort(mIndex.begin(), mIndex.end());
			// Get position of index
			auto pos = std::find(mIndex.begin(), mIndex.end(), index);
			mData.insert(pos - mIndex.begin() + mData.begin(), value);
		}
	}
	// If nothing exist in vector
	else if (mdim == 0)
	{
		mdim = index;
		mIndex.push_back(index);
		mData.push_back(value);
	}
	// If starts with 0 nonzero elements
	else
	{
		mIndex.push_back(index);
		mData.push_back(value);
	}
}

// Returns the value v_i of the vector. Returns 0 if the value is not stored
template <class T>
T SparseVector<T>::getValue(unsigned int index) const
{
	// Check if stored
	auto pos = std::find(mIndex.begin(), mIndex.end(), index);
	// If stored
	if (pos != mIndex.end())
	{
		return mData[std::distance(mIndex.begin(), pos)];
	}
	// Not stored
	else
	{
		return 0;
	}
}

// Returns the dimensionality of the vector
template <class T>
unsigned int SparseVector<T>::size() const
{
	return mdim;
}

// Returns the number stored elements
template <class T>
unsigned int SparseVector<T>::nonZeroes() const
{
	return mIndex.size();
}
// Returns the index of the ith stored nonzero entry (in increasing order)
template <class T>
unsigned int SparseVector<T>::indexNonZero(unsigned int i) const
{
	return mIndex[i];
}
// Returns the value of the ith stored nonzero entry (in increasing order)
template <class T>
T SparseVector<T>::valueNonZero(unsigned int i) const
{
	return mData[i];
}

// Adds x too the current vector
template <class T>
SparseVector<T> &SparseVector<T>::operator+=(SparseVector<T> const &x)
{
	if (mdim != x.mdim)
	{
		std::cout << "different dim!";
	}
	else
	{
		// If two vectors have same index
		for (auto j = x.mIndex.begin(); j != x.mIndex.end(); j++)
		{
			auto pos = std::find(mIndex.begin(), mIndex.end(), *j);
			if (pos != mIndex.end())
			{
				// Replace value
				mData[std::distance(mIndex.begin(), pos)] = getValue(*pos) + x.getValue(*j);
			}
			else
			{
				mIndex.push_back(*j);
				// Sort mIndex to increasing order
				std::sort(mIndex.begin(), mIndex.end());
				// Get position of index
				auto pos = std::find(mIndex.begin(), mIndex.end(), *j);
				mData.insert(pos - mIndex.begin() + mData.begin(), x.getValue(*j));
			}
		}
	}
	return *this;
}
// Subtracts x from the current vector
template <class T>
SparseVector<T> &SparseVector<T>::operator-=(SparseVector<T> const &x)
{
	if (mdim != x.mdim)
	{
		std::cout << "different dim!";
	}
	else
	{
		// If two vectors have same index
		for (auto j = x.mIndex.begin(); j != x.mIndex.end(); j++)
		{
			auto pos = std::find(mIndex.begin(), mIndex.end(), *j);
			if (pos != mIndex.end())
			{
				// Replace value
				mData[std::distance(mIndex.begin(), pos)] = getValue(*pos) - x.getValue(*j);
			}
			else
			{
				mIndex.push_back(*j);
				// Sort mIndex to increasing order
				std::sort(mIndex.begin(), mIndex.end());
				// Get position of index
				auto pos = std::find(mIndex.begin(), mIndex.end(), *j);
				mData.insert(pos - mIndex.begin() + mData.begin(), -x.getValue(*j));
			}
		}
	}
	return *this;
}

//-----------------------------------------
// Computes z= x+y, equivalent to z=x, z+=y
template <class T>
SparseVector<T> operator+(SparseVector<T> const &x, SparseVector<T> const &y)
{
	// Copy x to z
	SparseVector<T> z(x.size());
	for (int i = 0; i < x.nonZeroes(); i++)
	{
		z.setValue(x.indexNonZero(i), x.valueNonZero(i));
	}
	// z+=y
	z += y;
	return z;
}

// Computes z= x-y, equivalent to z=x, z-=y
template <class T>
SparseVector<T> operator-(SparseVector<T> const &x, SparseVector<T> const &y)
{
	// Copy x to z
	SparseVector<T> z(x.size());
	for (int i = 0; i < x.nonZeroes(); i++)
	{
		z.setValue(x.indexNonZero(i), x.valueNonZero(i));
	}
	// z+=y
	z -= y;
	return z;
}

// Computes the matrix-vector product of a dense matrix and sparse vector z=Ax.
// The result is a dense vector.
template <class T>
Vector<T> operator*(Matrix<T> const &A, SparseVector<T> const &x)
{
	Vector<T> res(A.GetNumberOfRows());
	if (A.GetNumberOfRows() != x.size())
	{
		std::cout << "Size not suitable!";
	}
	else
	{
		for (int i = 0; i < A.GetNumberOfRows(); i++)
		{
			for (int j = 0; j < x.size(); j++)
			{
				res[i] += A(i, j) * x.getValue(j);
			}
		}
	}
	return res;
}

// Computes the matrix-vector product of a dense matrix and sparse vector z=x^TA.
// The result is a dense vector.
template <class T>
Vector<T> operator*(SparseVector<T> const &x, Matrix<T> const &A)
{
	Vector<T> res(A.GetNumberOfRows());
	if (x.size() != A.GetNumberOfRows())
	{
		std::cout << "Size not suitable!";
	}
	else
	{
		for (int i = 0; i < x.size(); i++)
		{
			for (int j = 0; j < A.GetNumberOfRows(); j++)
			{
				res[j] += x.getValue(i) * A(i, j);
			}
		}
	}
	return res;
}
#endif
