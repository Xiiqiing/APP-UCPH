#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <cassert>
#include <cmath>
#include <vector>

template <class T>
class Vector
{
private:
    std::vector<T> mData; // data stored in vector
    int mSize;            // size of vector

public:
    // copy constructor
    Vector(const Vector &otherVector)
    {
        mSize = otherVector.size();
        mData = otherVector.mData;
    }

    Vector(int size)
    {
        assert(size > 0);
        mSize = size;
        // Initialize zeros
        mData = std::vector<T>(size, 0);
    }

    int size() const
    {
        return mSize;
    }

    T &operator[](int i)
    {
        assert(i >= 0 && i < mSize);
        return mData[i];
    }

    T const &operator[](int i) const
    {
        assert(i >= 0 && i < mSize);
        return mData[i];
    }

    // assignment operator
    Vector &operator=(const Vector &otherVector)
    {
        assert(mSize == otherVector.mSize);

        for (int i = 0; i < mSize; i++)
        {
            mData[i] = otherVector.mData[i];
        }
        return *this;
    }

    // overloading the unary - operator
    Vector operator-() const
    {
        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = -mData[i];
        }
        return v;
    }

    // overloading the binary + operator
    Vector operator+(const Vector<T> &v1) const
    {
        assert(mSize == v1.mSize);

        Vector v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = mData[i] + v1.mData[i];
        }
        return v;
    }

    // overloading the binary - operator
    Vector operator-(const Vector &v1) const
    {
        assert(mSize == v1.mSize);

        Vector v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = mData[i] - v1.mData[i];
        }
        return v;
    }

    // scalar multiplication
    Vector operator*(double a) const
    {
        Vector v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = a * mData[i];
        }
        return v;
    }

    // p-norm method
    double CalculateNorm(int p = 2) const
    {
        double sum = 0.0;
        for (int i = 0; i < mSize; i++)
        {
            sum += pow(std::abs(mData[i]), p);
        }
        return pow(sum, 1.0 / ((double)(p)));
    }

    // Returning a const reference to mData.
    std::vector<T> const &getStorage() const
    {
       return mData;
    }
};

#endif
