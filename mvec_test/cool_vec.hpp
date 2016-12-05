/*
项目1：向量类（任意维数）的设计（最好设计成类模板）。
*/

//vector.cpp


//vector.h
#define _CRT_SECURE_NO_WARNINGS
#define debug
#include<initializer_list>
#include<vector>
#include<tuple>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#ifndef cool_vec
#define cool_vec
// if there's any conceptional problem, plz point out instantly;

template <typename T, int n_Dim>
class multidim_vector
{
protected:
    vector<T> vec;
    //int dim;
protected:
    T & get(int pos)
    {
        return vec[pos];
    }
public:
    multidim_vector<T, n_Dim>() : vec(n_Dim)
    {
#ifdef debug
        cout << "constructor involked\n";
#endif // debug
    }
    ~multidim_vector<T, n_Dim>() {}
    multidim_vector<T, n_Dim>(initializer_list<T> li) : vec(li)
    {
#ifdef debug
        if (li.size() != n_Dim)
        {
            cout << "length_exceeded" << endl;
            /* TODO : error except ... */
        }
#endif // debug
    }
    multidim_vector<T, n_Dim>(const multidim_vector<T, n_Dim> & obj) : vec(obj.vec) { }
    const multidim_vector<T, n_Dim> & operator=(const multidim_vector<T, n_Dim> & rhs)
    {
        vec = rhs.vec;
        return *this;
    }
    multidim_vector<T, n_Dim> operator+(const multidim_vector<T, n_Dim> & rhs) const
    {
        multidim_vector<T, n_Dim> ans(*this);
        for (int i = 0; i < n_Dim; i++)
        {
            ans.vec[i] += rhs.vec[i];
        }
        return ans;
    }
    //scalar multiplication
    multidim_vector<T, n_Dim> operator*(const T & rhs) const
    {
        multidim_vector<T, n_Dim> ans(*this);
        for (int i = 0; i < n_Dim; i++)
        {
            ans[i] *= rhs;
        }
        return ans;
    }
    friend multidim_vector<T, n_Dim> operator*(const T & lhs, const multidim_vector<T, n_Dim> rhs)
    {
        return rhs* lhs;
    }
    multidim_vector<T, n_Dim> operator-(const multidim_vector<T, n_Dim> & rhs) const
    {
        multidim_vector<T, n_Dim> ans(*this);
        for (int i = 0; i < n_Dim; i++)
        {
            ans.vec[i] -= rhs.vec[i];
        }
        return ans;
    }
    const T & operator[](int Pos_) const
    {
        return vec[Pos_];
    }

    friend T Dot(const multidim_vector<T, n_Dim> & lhs, const multidim_vector<T, n_Dim> & rhs)
    {
        return lhs.Dot(rhs);
    }
    T Dot(const multidim_vector<T, n_Dim> & rhs) const
    {
        T ans = 0;
        for (int i = 0; i < n_Dim; i++)
        {
            ans += vec[i] * rhs.vec[i];
        }
        return ans;
    }
    //precondition: type T is correctly overloaded with istream
    friend istream & operator >> (istream & is, multidim_vector<T, n_Dim> & rhs)
    {
        for (int i = 0; i < n_Dim && is >> rhs.vec[i]; i++);
        return is;
    }
    friend ostream & operator << (ostream & os, const multidim_vector<T, n_Dim> & rhs)
    {
        os << "( ";
        if (n_Dim != 0)
        {
            os << rhs.vec[0];
        }
        for (int i = 1; i < n_Dim; i++)
        {
            os << ", " << rhs.vec[i];
        }
        os << ") ";
        return os;
    }
};

template <typename T>
const T & multidim_vector<T, 0>::operator[](int wtf) const
{
    cout <"wow"<<endl;
    return this->vec[0];
}

//dimention-changeable vector
template<typename T>
class cvector : public multidim_vector<T, 0>
{
private:
    int n_;
public:
    //	template<T>
    cvector<T>(int n = 0) : n_(n)
    {
        this->vec.resize(n);
    }
    void stretch(int n)
    {
        n_ = n;

        this->vec.resize(n);
    }

    friend istream & operator >> (istream & is, cvector<T> & rhs)
    {
        for (int i = 0; i < rhs.n_ && is >> rhs.get(i); i++);
        return is;
    }

    friend ostream & operator << (ostream & os, const cvector<T> & rhs)
    {
        os << "( ";
        if (rhs.n_ != 0)
        {
            os << rhs.vec[0];
        }
        for (int i = 1; i < rhs.n_; i++)
        {
            os << ", " << rhs.vec[i];
        }
        os << ") ";
        return os;
    }
public:

    cvector<T>(const cvector<T> & obj) : n_(obj.n_)
    {
        this->vec = obj.vec;
    }

    cvector<T>(const initializer_list<T> & il) : n_(il.size())
    {
        this->vec = vector<T>(il);
    }

    const cvector<T> & operator=(const cvector<T> & rhs)
    {
        this->vec = rhs.vec;
        return *this;
    }

    cvector<T> operator+(const cvector<T> & rhs) const
    {
        if(this->n_ != rhs->n_)
        {
            throw runtime_error("size_error\n");
        }
        cvector<T> ans(*this);
        for (int i = 0; i < n_; i++)
        {
            ans.vec[i] += rhs.vec[i];
        }
        return ans;
    }

    //scalar multiplication
    cvector<T> operator*(const T & rhs) const
    {
        cvector<T> ans(*this);
        for (int i = 0; i < n_; i++)
        {
            ans[i] *= rhs;
        }
        return ans;
    }
    friend cvector<T> operator*(const T & lhs, const cvector<T> & rhs)
    {
        return rhs* lhs;
    }
    cvector<T> operator-(const cvector<T> & rhs) const
    {
        cvector<T> ans(*this);
        for (int i = 0; i < n_; i++)
        {
            ans.vec[i] -= rhs.vec[i];
        }
        return ans;
    }
    const T & operator[](int Pos_) const
    {
        return this->vec[Pos_];
    }

    friend T Dot(const cvector<T> & lhs, const cvector<T> & rhs)
    {
        return lhs.Dot(rhs);
    }
    T Dot(const cvector<T> & rhs) const
    {
        T ans = 0;
        for (int i = 0; i < n_; i++)
        {
            ans += this->vec[i] * rhs.vec[i];
        }
        return ans;
    }
};

//2-dimentional vector specialized
template <typename T>
class pvector : public multidim_vector<T, 2>
{
public:
    //	pvector(): vec(2) {}
    T Cross(const pvector<T> & rhs) const
    {
        return this->get(0) * rhs.get(1) - this->get(1) * rhs.get(0);
    }
    friend T Cross(const pvector<T> & lhs, const pvector<T> & rhs)
    {
        return lhs.Cross(rhs);
    }
    pvector(const pair<T, T> &obj)
    {
        this->get(0) = obj.first;
        this->get(1) = obj.second;
    }
    pvector(const initializer_list<T> & obj) {}
    pvector() {}
};


//3-dimentional vector specialized
template<typename T>
class tvector : public multidim_vector<T, 3>
{
public:
    tvector() {}
    tvector(const initializer_list<T> & obj) :multidim_vector<T, 3>(obj) {}
    tvector(const tuple<T, T, T> & obj)
    {
        tie(this->get(0), this->get(1), this->get(2)) = obj;
#ifdef debug
        cout << "tuple2tvector constructor involked\n";
#endif
    }
    tvector Cross(const tvector & rhs) const
    {
        return tvector({ this->get(1) * rhs[2] - this->get(2) * rhs[1], this->get(2) * rhs[0] - this->get(0) * rhs[2], this->get(0) * rhs[1] - this->get(1) * rhs[0] });
    }
};
struct Point
{
    double x, y, z;
    Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
};
class Vector : public tvector<double>
{
public:
    //Vector() {}
    //Vector(const initializer_list<int> & obj) {}
    Vector(const tuple<double, double, double> & obj) :tvector<double>(obj) {}
    Vector(const initializer_list<double> & obj) :tvector<double>(obj) {}
    double Length()
    {
        return sqrt(this->Dot(*this));
    }
    double Angle(Vector & rhs)
    {
        return this->Length() == 0 || rhs.Length() == 0 ? 0 : acos(this->Dot(rhs) / this->Length() / rhs.Length());
    }

};
Vector operator-(Point & A, Point & B)
{
    return Vector({ A.x - B.x, A.y - B.y, A.z - B.z });
}

#endif // cool_vec

