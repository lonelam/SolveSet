#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const ll eps = 5;
const ll m = 1e18;


#ifndef _TLARGE_FLOAT_H__INCLUDED_
#define _TLARGE_FLOAT_H__INCLUDED_

class TLargeFloat;//���߾��ȸ�������TLargeFloat
class TLargeFloatException;//���߾��ȸ������쳣��

//�Ľ�����
//  1.ǿ���Ż�ArrayMUL���������(��ǰʵ���˶��ַ���FFT�㷨)��
//     a.��ʵ������ż��Ϊ�������и���Ҷ�任���㷨ʵ�֣��ӿ�˷��ٶ�
//     b.ʵ�ֻ�ϻ��ĸ���Ҷ�任���ӿ�˷��ٶ�
//     c.������x87��10byte������ʵ��FFT�Լ�С���Ӷ�����FFT�ܹ���������λ������
//     d.��SSE2���Ż����ٸ���Ҷ�任���ӿ�˷��ٶ�
//     e.���߽�����Ҷ�任�滻Ϊ���۱任��ʵ��(ʹ������)
//  2.�ڲ�ʹ��8λ(��9λ)ʮ������ʵ�֣���Լ�ڴ棻����2���Ƶĵ���(�����Ļ�����������ͻ��鷳һЩ��)
//  3.����µĻ������㺯�����磺ָ������power����������log�����Ǻ���sin,cos,tan��

//ע�⣺�����������TLargeFloat���л������, ���ܻ�������(��Чλ�����ܵ�������Ӱ��)��
//  ���� �� Ϊ�ɱ�ʾ�����ĸ����� �������㲻�������
//  ���ںܴ������������С��λ�ĸ��������������ַ�������ʽת��Ϊ���߾��ȸ�����(�����������)

//void ArrayMUL(TInt32bit* result,long rminsize,const TInt32bit* x,long xsize,const TInt32bit* y,long ysize);//�����, ��Ҫ�Ż�����ҪĿ��

//���߾��ȸ������쳣��  //TLargeFloat�����г��ִ����ʱ����׳������͵��쳣
class TLargeFloatException :public std::runtime_error
{
public:
    TLargeFloatException(const char * Error_Msg) :runtime_error(Error_Msg){}
    virtual ~TLargeFloatException() throw() {}
};


//TCatchIntErrorֻ�Ƕ���������TInt���е�һ���װ
//���߾��ȸ��������ָ������ʱʹ��
//���TCatchIntError��Ϊ�˵��������㳬��ֵ���ʱ���׳��쳣
//template<Ҫ��װ���������ͣ�����ʱ�׳����쳣���ͣ�TInt��Сֵ��TInt���ֵ>
template <typename TInt,typename TException,TInt MinValue,TInt MaxValue>
class TCatchIntError
{
private:
    typedef TCatchIntError<TInt,TException,MinValue,MaxValue> SelfType;
    TInt  m_Int;

    inline SelfType& inc(const TInt& uValue)
    {
        if ( (uValue<0)||(uValue>MaxValue)||(MaxValue-uValue<m_Int) )
            throw TException("ERROR:TCatchIntError::inc(); ");
        m_Int+=uValue;
        return (*this);
    }
    inline SelfType& dec(const TInt& uValue)
    {
        if ( (uValue<0)||(uValue>MaxValue)||(MinValue+uValue>m_Int) )
            throw TException("ERROR:TCatchIntError::dec()");
        m_Int-=uValue;
        return (*this);
    }
    inline SelfType& mul(const TInt& iValue)
    {
        if (iValue==0)
            m_Int=0;
        else
        {
            TInt tmp=m_Int*iValue;
            if ( (iValue<MinValue)||(iValue>MaxValue)||(tmp<MinValue)||(tmp>MaxValue)||((tmp/iValue)!=m_Int) )
                throw TException("ERROR:TCatchIntError::mul(); ");
            m_Int=tmp;
        }
        return (*this);
    }
public:
    inline TCatchIntError() :m_Int(0){ }
    inline TCatchIntError(const TInt& Value)       :m_Int(0) { (*this)+=Value;}
    inline TCatchIntError(const SelfType& Value)   :m_Int(0) { (*this)+=(Value.m_Int); }
    inline const TInt& AsInt() const    { return m_Int; }
    inline SelfType& operator +=(const TInt& Value) //throw(TLargeFloatException)
        { if (Value<0) return dec(-Value);
            else return inc(Value);   }
    inline SelfType& operator -=(const TInt& Value) //throw(TLargeFloatException)
        { if (Value<0)  return inc(-Value);
            else return dec(Value); }
    inline SelfType& operator *=(const TInt& Value) //throw(TLargeFloatException)
       {  return mul(Value); }

    inline SelfType& operator +=(const SelfType& Value) { return (*this)+=(Value.m_Int); }//throw(TLargeFloatException)
    inline SelfType& operator -=(const SelfType& Value) { return (*this)-=(Value.m_Int); }//throw(TLargeFloatException)
    inline SelfType& operator *=(const SelfType& Value) { return (*this)*=(Value.m_Int); }//throw(TLargeFloatException)
};

    //ָ������ʹ�õ���������  ��д������֧�ֵĽϴ����������
    //typedef __int64 TMaxInt; //type long long TMaxInt;
    //const TMaxInt   TMaxInt_MAX_VALUE =   TMaxInt(9223372036854775807);
    //const TMaxInt   TMaxInt_MIN_VALUE = - TMaxInt_MAX_VALUE;
    typedef long  TMaxInt;
    const TMaxInt  TMaxInt_MAX_VALUE =  2147483647;
    const TMaxInt  TMaxInt_MIN_VALUE = -TMaxInt_MAX_VALUE;

    //С������ʹ�õ���������  32bitλ����������
    typedef long TInt32bit;
    const TInt32bit  TInt32bit_MAX_VALUE =  2147483647;
    const TInt32bit  TInt32bit_MIN_VALUE = -TInt32bit_MAX_VALUE;


//���߾��ȸ�������
class TLargeFloat
{
public:
    //һЩ���������Ͷ���
    typedef std::vector<TInt32bit> TArray;//С��λʹ�õ���������
    enum { em10Power =4,   //����Ϊ10000���ƣ�
           emBase =10000,  //�����һ��Ԫ�ض�Ӧ4��ʮ����λ
           emLongDoubleDigits =std::numeric_limits<long double>::digits10,//long double��10������Ч����
           emLongDoubleMaxExponent =std::numeric_limits<long double>::max_exponent10,//long double�����10����ָ��
           emLongDoubleMinExponent =std::numeric_limits<long double>::min_exponent10 };//long double����С10����ָ��
    typedef   TLargeFloatException   TException;
    typedef   TCatchIntError<TMaxInt,TException,TMaxInt_MIN_VALUE,TMaxInt_MAX_VALUE>  TExpInt;//ָ������
    typedef  TLargeFloat  SelfType;
public:
    class TDigits//TDigits��������TLargeFloat�ľ���;//�����������Ϊ�˱���TLargeFloat�Ĺ��캯���Ŀ�������
    {
    private:
        unsigned long  m_DigitsArraySize;
    public:
        explicit TDigits(const long uiDigitsLength)
        {   if (uiDigitsLength<=0) throw TException("ERROR:TLargeFloat::TDigits()");
            m_DigitsArraySize=(uiDigitsLength+em10Power-1)/em10Power; }
        inline const unsigned long  GetDigitsArraySize() const   { return m_DigitsArraySize; }
    };
    TLargeFloat(const SelfType& Value);
    explicit TLargeFloat(const long double DefultValue);//Ĭ�ϸ��㾫��  //ע�⣺ת�����ܴ���С�����
    explicit TLargeFloat(const long double DefultValue,const TDigits& DigitsLength);//TDigits ʮ������Чλ�� //ע�⣺ת�����ܴ���С�����
    explicit TLargeFloat(const char* strValue);//ʹ���ַ�������ľ���
    explicit TLargeFloat(const char* strValue,const TDigits& DigitsLength);
    explicit TLargeFloat(const std::string& strValue);
    explicit TLargeFloat(const std::string& strValue,const TDigits& DigitsLength);
    long double AsFloat() const;//ת��Ϊ������
    std::string  AsString() const;//ת��Ϊ�ַ���
    void SetDigitsLength(const TDigits& DigitsLength);  //��������10������Чλ��
    inline void SetDigitsLength(const long uiDigitsLength) { SetDigitsLength(TDigits(uiDigitsLength)); }
    unsigned long GetDigitsLength() const;//���ص�ǰ��10������Чλ��

    void Swap(SelfType& Value);//����ֵ
    void Zero(); //����Ϊ0

    inline void StrToLargeFloat(const std::string& strValue) { sToLargeFloat(strValue); }
    inline void StrToLargeFloat(const char* strValue) { sToLargeFloat(std::string(strValue)); }
    SelfType& operator =  (const SelfType& Value);
    SelfType& operator =  (long double  fValue); //ע�⣺ת�����ܴ���С�����
    inline const SelfType  operator -  () const  {  SelfType temp(*this); temp.Chs(); return temp;  }//��
    inline const SelfType& operator +  () const  { return (*this); }//����

    SelfType& operator += (const SelfType& Value);
    SelfType& operator -= (const SelfType& Value);
    inline SelfType& operator += (long double  fValue)  { return (*this)+=TLargeFloat(fValue); }
    inline SelfType& operator -= (long double  fValue)  { return (*this)-=TLargeFloat(fValue); }
    friend inline const TLargeFloat operator + (const TLargeFloat& x,const TLargeFloat& y)  { TLargeFloat temp(x);  return temp+=y; }
    friend inline const TLargeFloat operator - (const TLargeFloat& x,const TLargeFloat& y)  { TLargeFloat temp(x);  return temp-=y; }
    friend inline const TLargeFloat operator + (const TLargeFloat& x,long double y)  { TLargeFloat temp(x);  return temp+=y; }
    friend inline const TLargeFloat operator - (const TLargeFloat& x,long double y)  { TLargeFloat temp(x);  return temp-=y; }
    friend inline const TLargeFloat operator + (long double x,const TLargeFloat& y)  { return y+x; }
    friend inline const TLargeFloat operator - (long double x,const TLargeFloat& y)  { return -(y-x); }

    SelfType& operator *= (long double  fValue);
    SelfType& operator *= (const SelfType& Value);
    friend inline const TLargeFloat operator * (const TLargeFloat& x,const TLargeFloat& y)  { TLargeFloat temp(x); if (&x!=&y)  return temp*=y; else { temp.Sqr(); return temp;  } }
    friend inline const TLargeFloat operator * (const TLargeFloat& x,long double y)  {TLargeFloat temp(x); return temp*=y;}
    friend inline const TLargeFloat operator * (long double x,const TLargeFloat& y)  { return y*x; }
    SelfType& operator /= (long double  fValue);
    SelfType& operator /= (const SelfType& Value);
    friend inline const TLargeFloat operator / (const TLargeFloat& x,const TLargeFloat& y)  { TLargeFloat temp(x); return temp/=y; }
    friend inline const TLargeFloat operator / (const TLargeFloat& x,long double y)  { TLargeFloat temp(x); return temp/=y; }
    friend inline const TLargeFloat operator / (long double x,const TLargeFloat& y)  { TLargeFloat temp(y); temp.Rev(); return temp*=x; }

    friend inline bool operator ==(const TLargeFloat& x,const TLargeFloat& y) { return (x.Compare(y)==0); }
    friend inline bool operator < (const TLargeFloat& x,const TLargeFloat& y) { return (x.Compare(y)<0); }
    friend inline bool operator ==(const TLargeFloat& x,long double y) { return (x==TLargeFloat(y)); }
    friend inline bool operator < (const TLargeFloat& x,long double y) { return (x<TLargeFloat(y)); }
    friend inline bool operator ==(long double x,const TLargeFloat& y) { return (y==x); }
    friend inline bool operator < (long double x,const TLargeFloat& y) { return (y>x); }
    friend inline bool operator !=(const TLargeFloat& x,const TLargeFloat& y) { return !(x==y); }
    friend inline bool operator > (const TLargeFloat& x,const TLargeFloat& y) { return (y<x); }
    friend inline bool operator >=(const TLargeFloat& x,const TLargeFloat& y) { return !(x<y); }
    friend inline bool operator <=(const TLargeFloat& x,const TLargeFloat& y) { return !(x>y); }
    friend inline bool operator !=(const TLargeFloat& x,long double y) { return !(x==y); }
    friend inline bool operator > (const TLargeFloat& x,long double y) { return (y<x); }
    friend inline bool operator >=(const TLargeFloat& x,long double y) { return !(x<y); }
    friend inline bool operator <=(const TLargeFloat& x,long double y) { return !(x>y); }
    friend inline bool operator !=(long double x,const TLargeFloat& y) { return !(x==y); }
    friend inline bool operator > (long double x,const TLargeFloat& y) { return (y<x); }
    friend inline bool operator >=(long double x,const TLargeFloat& y) { return !(x<y); }
    friend inline bool operator <=(long double x,const TLargeFloat& y) { return !(x>y); }

    friend inline const TLargeFloat abs(const TLargeFloat& x)  { TLargeFloat result(x); result.Abs(); return result; }//����ֵ,|x|
    friend inline const TLargeFloat sqrt(const TLargeFloat& x) { TLargeFloat result(x); result.Sqrt(); return result;} //����,x^0.5
    friend inline const TLargeFloat revsqrt(const TLargeFloat& x) { TLargeFloat result(x); result.RevSqrt(); return result; }//��1/x^0.5;
    friend inline const TLargeFloat sqr(const TLargeFloat& x) { TLargeFloat result(x); result.Sqr(); return result; };//ƽ��,x^2
    friend inline void swap(TLargeFloat& a,TLargeFloat& b) { a.Swap(b); }//����ֵ
    friend inline std::ostream& operator << (std::ostream& cout, const TLargeFloat& Value) { return cout<<Value.AsString(); }

///////////////////////////////////////////////////////////////////////////////////////////////////////
private:
    TInt32bit   m_Sign;     //����λ  ��:1,  ��:-1, ��: 0
    TExpInt     m_Exponent; //����10Ϊ�׵�ָ��
    TArray      m_Digits;   //С������ ����˳����TArray[0]Ϊ��һ��С��λ(em10Power��10����λ),�������ƣ�ȡֵ��Χ[0--(emBase-1)]
private:
    void Canonicity();//��� ת��ֵ���Ϸ���ʽ
    void fToLargeFloat(long double fValue);//�ڲ�ʹ�� ������ת��Ϊ TLargeFloat,������Ĭ�Ͼ���
    void iToLargeFloat(TMaxInt iValue);//�ڲ�ʹ�� ����ת��Ϊ TLargeFloat,������Ĭ�Ͼ���
    void sToLargeFloat(const std::string& strValue);//�ڲ�ʹ�� �ַ���ת��Ϊ TLargeFloat
    long Compare(const SelfType& Value) const;//�Ƚ���������(*this)>Value ����1��С�ڷ���-1����ȷ���0
    void Abs_Add(const SelfType& Value);//����ֵ��  x:=|x|+|y|;
    void Abs_Sub_Abs(const SelfType& Value);//����ֵ���ľ���ֵx:=| |x|-|y| |;

public:
    void Chs();//��
    void Abs();//����ֵ
    void MulInt(TMaxInt iValue);//����һ��������
    void DivInt(TMaxInt iValue);//����һ��������
    void Rev();//����
    void RevSqrt();//��1/x^0.5;
    inline void Sqrt()  { SelfType x(*this);  x.RevSqrt(); (*this)*=x; } //��x^0.5;
    inline void Sqr()   { (*this)*=(*this); };//ƽ��,x^2


};


//��Ԫ����
void LargeFloat_UnitTest();


#endif // _TLARGE_FLOAT_H__INCLUDED_
// TLargeFloat.h

class TDigitsLengthCtrl
{
private:
    std::vector<TLargeFloat*> m_list;
public:
    inline void add_to_ctrl(TLargeFloat* var) { m_list.push_back(var); }
    void SetDigitsLength(const long uiDigitsLength)
    {
        long size=m_list.size();
        for (long i=0;i<size;++i)
            m_list[i]->SetDigitsLength(uiDigitsLength);
    }
};

//�Զ����ȿ���
class TDigitsLengthAutoCtrl:public TDigitsLengthCtrl
{
private:
    std::vector<long>    m_DigitsLengthList;
    long   step;
public:
    TDigitsLengthAutoCtrl(long DigitsMul,long DigitsLength0,long MaxDigitsLength)//(����ϵ��,��ʼ����,������Ҫ����)
    {
        //MyDebugAssert(DigitsLength0>0);
        //�õ���ѵľ����ݶ�
        long curDigitsLength=MaxDigitsLength;
        while (curDigitsLength>DigitsLength0)
        {
            m_DigitsLengthList.push_back(curDigitsLength);

            if ((DigitsLength0<=1)&&(curDigitsLength==1)) break;
            curDigitsLength=(curDigitsLength+DigitsMul-1)/DigitsMul;
        }
        step=get_runcount()-1;
    }
    inline long get_runcount() { return m_DigitsLengthList.size(); }
    inline void SetNextDigits()
    {
        //MyDebugAssert(step>=0);
        long DigitsLength=m_DigitsLengthList[step];
        if (step>0)
            DigitsLength+=4;
        SetDigitsLength(DigitsLength);
        --step;
        if (step<0) step=0;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////

void TLargeFloat_CtrlExponent(TLargeFloat::TArray& v,TMaxInt iMoveRightCount)
{
    //iMoveCountBig �п��ܴ治�� �����ڵ���ϵ�������Ƴ���ֵ��Ƚ���
    long iMoveCountBig=(long)(iMoveRightCount/TLargeFloat::em10Power);
    long iMoveCountSmall=(long)(iMoveRightCount%TLargeFloat::em10Power);

    //�������
    if (iMoveCountBig>0)
    {
        for (long i=v.size()-1;i>=iMoveCountBig;--i)
            v[i]=v[i-iMoveCountBig];
        for (long j=0;j<iMoveCountBig;++j)
            v[j]=0;
    }
    //С������
    if (iMoveCountSmall>0)
    {
        TInt32bit iDiv=1;
        for (long j=0;j<iMoveCountSmall;++j) iDiv*=10;

        long v_size=v.size();
        for (long i=iMoveCountBig;i<v_size-1;++i)
        {
            v[i+1]+=(v[i]%iDiv)*TLargeFloat::emBase;
            v[i]/=iDiv;
        }
        if (v_size>=1)
            v[v_size-1]/=iDiv;
    }

}

    void TLargeFloat_ArrayAddTestLast(TInt32bit* x,long xsize)
    {
        for (long i=xsize-1;i>0;--i)
        {
            if (x[i]>=TLargeFloat::emBase)//��λ
            {
                ++x[i-1];
                x[i]-=TLargeFloat::emBase;
            }
            else
                break;
        }
    }

void TLargeFloat_ArrayAdd(TInt32bit* result,long rsize,const TInt32bit* y,long ysize)
{
    //MyDebugAssert(rsize>=ysize);
    //MyDebugAssert(ysize>0);
    TInt32bit* ri=&result[rsize-ysize];
    long i;
    for (i=ysize-1;i>0;--i)
    {
        TInt32bit r=ri[i]+y[i];
        if (r>=TLargeFloat::emBase)//��λ
        {
            ++ri[i-1];
            r-=TLargeFloat::emBase;
        }
        ri[i]=r;
    }
    ri[0]+=y[0];

    TLargeFloat_ArrayAddTestLast(result,rsize-ysize+1);
}

void TLargeFloat_ArraySub(TInt32bit* result,long rsize,const TInt32bit* y,long ysize)
{
    //MyDebugAssert(rsize>=ysize);
    //MyDebugAssert(ysize>0);
    TInt32bit* ri=&result[rsize-ysize];
    long i;
    for (i=ysize-1;i>0;--i)
    {
        TInt32bit r=ri[i]-y[i];
        if (r<0)//��λ
        {
            --ri[i-1];
            r+=TLargeFloat::emBase;
        }
        ri[i]=r;
    }
    ri[0]-=y[0];

    for (i=rsize-ysize;i>0;--i)
    {
        if (result[i]<0)//��λ
        {
            --result[i-1];
            result[i]+=TLargeFloat::emBase;
        }
        else
            break;
    }
}


        TInt32bit _inti_csMaxMuliValue()
        {
            double rb=1; double mb=1;
            for (long i=0;i<100/TLargeFloat::em10Power;++i)
            {
                mb*=(1.0/TLargeFloat::emBase);
                rb+=mb;
            }
            return (TInt32bit)( TInt32bit_MAX_VALUE*(1.0/(TLargeFloat::emBase-1))/rb ) -1;
        }
    //������������ĳ���ֵM����: (emBase-1)*M + (emBase-1)*M/B + (emBase-1)*M/B^2 + (emBase-1)*M/B^3 ... <=TInt32bit_MAX_VALUE
    static const TInt32bit csMaxMuliValue=_inti_csMaxMuliValue();
    static const TInt32bit csMaxMulAddValue = csMaxMuliValue - (TLargeFloat::emBase-1);

void TLargeFloat_ArrayMUL_ExE(TInt32bit* result,long rminsize,const TInt32bit* x,long xsize,const TInt32bit* y,long ysize)
{
    //N*N���Ӷȵļ򵥳˷�ʵ��
    for (long k=0;k<rminsize;++k) result[k]=0;
    while ((ysize>0)&&(y[0]==0)) { --ysize; ++y; ++result; --rminsize;}
    //while ((xsize>0)&&(x[0]==0)) { --xsize; ++x; ++result; --rminsize;}
    while ((ysize>0)&&(y[ysize-1]==0)) { --ysize; }
    //while ((xsize>0)&&(x[xsize-1]==0)) { --xsize; }

    long add_sum=0;
    for (long i=0;i<xsize;++i)
    {
        long xi=x[i];
        if (xi>0)
        {
            TInt32bit* resulti=&result[i+1];
            long y_limit=std::min(rminsize-1-i,ysize);
            for (long j=0;j<y_limit;++j)
            {
                resulti[j]+=(xi*y[j]);
            }
            add_sum+=xi;
            if (add_sum>csMaxMulAddValue)
            {
                for (long k=i+y_limit;k>0;--k)
                {
                    TInt32bit v=result[k];
                    if (v>=TLargeFloat::emBase)
                    {
                        result[k-1]+=v/TLargeFloat::emBase;
                        result[k]= v%TLargeFloat::emBase;
                    }
                }
                add_sum=0;
            }
        }
    }
    if (add_sum>0)
    {
        for (long k=rminsize-1;k>0;--k)
        {
            TInt32bit v=result[k];
            if (v>=TLargeFloat::emBase)
            {
                result[k-1]+=v/TLargeFloat::emBase;
                result[k]= v%TLargeFloat::emBase;
            }
        }
    }
}

//����˷�  ����
void ArrayMUL(TInt32bit* result,long rminsize,const TInt32bit* x,long xsize,const TInt32bit* y,long ysize);


void ArrayMUL_Dichotomy(TInt32bit* result,long rminsize,const TInt32bit* x,const TInt32bit* y,long MulSize)
{

    //���ַ��ĳ˷�ʵ��
    //   x*y=(a*E+b)*(c*E+d)=(E*E-E)*ac + E*(a+b)*(c+d) -(E-1)*bd

    //   temp_a_add_b=a+b;
    //   temp_c_add_d=c+d;
    //   result=E*temp_a_add_b*temp_c_add_d;

    //   temp_ac=a*c;
    //   result+=E*E*temp_ac;
    //   result-=E*temp_ac;

    //   temp_bd=b*d;
    //   result+=temp_bd;
    //   result-=E*temp_bd;
    //
    long i;

    const long E=((MulSize+1)>>1);
    //if (tmpData+2*(E+1)>end_tmpData)  __asm int 3
    const long acSize=MulSize-E;
    const long acErrorSize=E-acSize;

    const TInt32bit* a=x;
    const TInt32bit* b=&x[acSize];
    const TInt32bit* c=y;
    const TInt32bit* d=&y[acSize];

    TLargeFloat::TArray _tmpData((E+1)*2);
    TInt32bit* tmpData=&_tmpData[0];

    TInt32bit* temp_a_add_b=&tmpData[0];
    TInt32bit* temp_c_add_d=&tmpData[(E+1)];

    temp_a_add_b[0]=0;
    for (i=0;i<E;++i) temp_a_add_b[i+1]=b[i];
    TLargeFloat_ArrayAdd(temp_a_add_b,1+E,a,E-acErrorSize);
    temp_c_add_d[0]=0;
    for (i=0;i<E;++i) temp_c_add_d[i+1]=d[i];
    TLargeFloat_ArrayAdd(temp_c_add_d,1+E,c,E-acErrorSize);

    const long abcdPos=(2*MulSize-E-2*(E+1));
    for (i=0;i<abcdPos;++i) result[i]=0;
    ArrayMUL(&result[abcdPos],std::min(rminsize-abcdPos,2*(E+1)),temp_a_add_b,E+1,temp_c_add_d,E+1);
    for (i=abcdPos+2*(E+1);i<rminsize;++i) result[i]=0;

    TInt32bit* temp_ac=&tmpData[0];
    const long acminsize=std::min(rminsize,acSize*2);
    ArrayMUL(temp_ac,acminsize,a,acSize,c,acSize);
    TLargeFloat_ArrayAdd(result,acminsize,temp_ac,acminsize);
    long sub_ac_size=acSize*2;
    if (E+sub_ac_size>rminsize) sub_ac_size=rminsize-E;
    TLargeFloat_ArraySub(result,E+sub_ac_size,temp_ac,sub_ac_size);

    const long add_bdPos=2*MulSize-2*E;
    long sub_bd_size=2*E;
    const long sub_bdPos=add_bdPos-E;
    if (sub_bdPos+sub_bd_size>rminsize) sub_bd_size=rminsize-sub_bdPos;
    if (sub_bd_size>0)
    {
        TInt32bit* temp_bd=&tmpData[0];
        ArrayMUL(temp_bd,sub_bd_size,b,E,d,E);
        long add_bd_size=2*E;
        if (add_bdPos+add_bd_size>rminsize) add_bd_size=rminsize-add_bdPos;
        if (add_bd_size>0)
          TLargeFloat_ArrayAdd(result,add_bdPos+add_bd_size,temp_bd,add_bd_size);
        TLargeFloat_ArraySub(result,sub_bdPos+sub_bd_size,temp_bd,sub_bd_size);
    }
}


void ArrayMUL_DichotomyPart(TInt32bit* result,long rminsize,const TInt32bit* x,long xsize,const TInt32bit* y,long ysize)
{
    //���ַ��ĸ�������
    ///////////////////////////////////////////
    //x*y=(a*E+b)*y=a*y*E+b*y;

    if (xsize==ysize)
    {
        ArrayMUL_Dichotomy(result,rminsize,x,y,ysize);
        return ;
    }

    if (xsize<ysize)
    {
        std::swap(xsize,ysize);
        std::swap(x,y);
    }

    const long E=ysize;
    const long asize=xsize-E;
    const TInt32bit* a=&x[0];
    const TInt32bit* b=&x[asize];


    ArrayMUL(result,rminsize,a,asize,y,ysize);
    for (long i=asize+ysize;i<rminsize;++i) result[i]=0;
    const long byPos=asize;
    if (byPos<rminsize)
    {
        const long byminsize=rminsize-byPos;
        TLargeFloat::TArray tmpData(byminsize);
        TInt32bit* tmp_by=&tmpData[0];
        ArrayMUL_Dichotomy(tmp_by,byminsize,b,y,E);
        TLargeFloat_ArrayAdd(result,rminsize,tmp_by,byminsize);
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////

const long csTMaxInt_Digits=(long)(log10((long double)TMaxInt_MAX_VALUE)+1);

TLargeFloat::TLargeFloat(const SelfType& Value)
:m_Digits(Value.m_Digits)
{
    m_Exponent=Value.m_Exponent;
    m_Sign=Value.m_Sign;
}

TLargeFloat::TLargeFloat(const long double DefultValue)
:m_Digits(TDigits(emLongDoubleDigits+1).GetDigitsArraySize(),0)
{
    fToLargeFloat(DefultValue);
}

TLargeFloat::TLargeFloat(const long double DefultValue,const TDigits& DigitsLength)
:m_Digits(DigitsLength.GetDigitsArraySize(),0)
{
    fToLargeFloat(DefultValue);
}

TLargeFloat::TLargeFloat(const char* strValue)
:m_Digits(TDigits(csTMaxInt_Digits).GetDigitsArraySize(),0)
{
    sToLargeFloat(std::string(strValue));
}
TLargeFloat::TLargeFloat(const char* strValue,const TDigits& DigitsLength)
:m_Digits(DigitsLength.GetDigitsArraySize(),0)
{
    sToLargeFloat(std::string(strValue));
}
TLargeFloat::TLargeFloat(const std::string& strValue)
:m_Digits(TDigits(csTMaxInt_Digits).GetDigitsArraySize(),0)
{
    sToLargeFloat(strValue);
}
TLargeFloat::TLargeFloat(const std::string& strValue,const TDigits& DigitsLength)
:m_Digits(DigitsLength.GetDigitsArraySize(),0)
{
    sToLargeFloat(strValue);
}


void TLargeFloat::Zero()
{
    if (m_Sign==0) return;
    m_Sign=0;
    m_Exponent=0;
    long old_size=m_Digits.size();
    for (long i=0;i<old_size;++i)
        m_Digits[i]=0;
}

void TLargeFloat::Canonicity()
{
    //��� С������
    //���ǰ����:m_Digits[0]>=emBase Ҳ����С�����ֵ�ֵ���ڵ���1.0;
    //���ǰ����:m_Digits[]ǰ���ж��0ֵ Ҳ����С�����ֵ�ֵС��0.1;
    //��񻯺���������������С�����ֵ�ֵ С��1.0�����ڵ���0.1;

    if (m_Sign==0)
    {
        return;
    }
    long old_size=m_Digits.size();
    if (old_size<=0) return; //�����ܷ���:)

    if ( (m_Digits[0]<emBase)&&(m_Digits[0]>=(emBase/10)) ) return;

    //��������
    while (m_Digits[0]>=emBase)//�Ƿ���Ҫ����1
    {
        m_Exponent+=em10Power;
        for (long i=old_size-1;i>=2;--i)
            m_Digits[i]=m_Digits[i-1];
        if (old_size>=2) m_Digits[1]=m_Digits[0] % emBase;
        m_Digits[0]/=emBase;
    }

    ////////////////////////////////////
    //��������

    //�������
    long iMoveCountBig=old_size;
    for (long i=0;i<old_size;++i)
    {
        if (m_Digits[i]!=0)
        {
            iMoveCountBig=i;
            break;
        }
    }
    if (iMoveCountBig==old_size)
    {
        //as Zero();
        m_Sign=0;
        m_Exponent=0;
        return;
    }

    if (iMoveCountBig>0)
    {
        m_Exponent-=(iMoveCountBig*em10Power);
        for (long j=0;j<old_size-iMoveCountBig;++j)
            m_Digits[j]=m_Digits[j+iMoveCountBig];
        for (long k=old_size-iMoveCountBig;k<old_size;++k)
            m_Digits[k]=0;
    }

    //С������
    TInt32bit iMoveMul=1;
    long iMoveCountSmall=0;
    while (iMoveMul*m_Digits[0]<(emBase/10))
    {
        iMoveMul*=10;
        ++iMoveCountSmall;
    }
    if (iMoveCountSmall>0)
    {
        m_Exponent-=iMoveCountSmall;
        for (long i=old_size-1;i>=0;--i)
            m_Digits[i]*=iMoveMul;
        for (long j=old_size-1;j>0;--j)
        {
            TInt32bit value=m_Digits[j];
            m_Digits[j]=value%emBase;
            m_Digits[j-1]+=value/emBase;
        }
    }
}

void TLargeFloat::iToLargeFloat(TMaxInt iValue)
{
    Zero();
    long new_size=TDigits(csTMaxInt_Digits).GetDigitsArraySize();
    if ((long)m_Digits.size()<new_size)
        m_Digits.resize(new_size,0);
    if (iValue==0)
        return;
    else if (iValue>0)
        m_Sign=1;
    else
    {
        m_Sign=-1;
        iValue=-iValue;
    }

    //�����ת��
    TMaxInt tmp_iValue=iValue;
    long n=0;
    for (;tmp_iValue!=0;++n)
        tmp_iValue/=emBase;
    m_Exponent=n*em10Power;
    for (long i=0;i<n;++i)
    {
        m_Digits[n-1-i]=(TInt32bit)(iValue%emBase);
        iValue/=emBase;
    }
    Canonicity();
}

void TLargeFloat::fToLargeFloat(long double fValue)
{
    TMaxInt iValue=(TMaxInt)fValue;
    if (iValue==fValue)
    {
        iToLargeFloat(iValue);
        return;
    }

    Zero();
    long new_size=TDigits(emLongDoubleDigits+1).GetDigitsArraySize();
    if ((long)m_Digits.size()<new_size)
        m_Digits.resize(new_size,0);
    if (fValue==0)
        return;
    else if (fValue>0)
        m_Sign=1;
    else
    {
        m_Sign=-1;
        fValue=-fValue;
    }

    m_Exponent=(long)floor(log10(fValue));
    fValue/=pow(10.0,(long)m_Exponent.AsInt());
    long size=m_Digits.size();
    for (long i=0;i<size;++i)//�õ�С��λ
    {
        if (fValue<=0) break;
        fValue*=emBase;
        TInt32bit iValue=(TInt32bit)floor(fValue);
        fValue-=iValue;
        m_Digits[i]=iValue;
    }

    Canonicity();
}

void TLargeFloat::Swap(SelfType& Value)
{
    if (this==&Value) return;
    m_Digits.swap(Value.m_Digits);
    std::swap(m_Sign,Value.m_Sign);
    std::swap(m_Exponent,Value.m_Exponent);
}

void TLargeFloat::Chs()
{
    m_Sign*=(-1);
}

void TLargeFloat::Abs()
{
    if (m_Sign!=0) m_Sign=1;
}

unsigned long TLargeFloat::GetDigitsLength() const
{
    return m_Digits.size()*em10Power;
}

void TLargeFloat::SetDigitsLength(const TDigits& DigitsLength)
{
    m_Digits.resize(DigitsLength.GetDigitsArraySize(),0);
}

TLargeFloat::SelfType& TLargeFloat::operator =  (const SelfType& Value)
{
    if (this==&Value) return *this;
    m_Digits=Value.m_Digits;
    m_Sign=Value.m_Sign;
    m_Exponent=Value.m_Exponent;
    return *this;
}

TLargeFloat::SelfType& TLargeFloat::operator =  (long double  fValue)
{
    fToLargeFloat(fValue);
    return *this;
}

long double TLargeFloat::AsFloat() const
{
    if ( ((m_Exponent.AsInt())>=emLongDoubleMaxExponent)
        ||((m_Exponent.AsInt())<=emLongDoubleMinExponent) )
    {
        throw TException("ERROR:TLargeFloat::AsFloat()");
    }

    if (m_Sign==0) return 0;
    long double result=m_Sign*pow((long double)10.0,(long double)m_Exponent.AsInt());

    long double r=1;
    long double Sum=0;
    long old_size=m_Digits.size();
    for (long i=0;i<old_size;++i)//�õ�С��λ
    {
        r/=emBase;//r*=(1.0/emBase);
        if (r==0) break;
        Sum+=(m_Digits[i]*r);
    }
    return result*Sum;
}
std::string  TLargeFloat::AsString() const
{
    if (m_Sign==0)
        return "0";

    //������Ҫ���ַ����ռ��С
    long str_length=2+m_Digits.size()*em10Power;
    if  (m_Sign<0) ++str_length; //����

    TMaxInt EpValue=m_Exponent.AsInt();
    long UEP_StrLength=0;
    if (EpValue!=0)
    {
        ++str_length;
        if (EpValue<0)
        {
            EpValue=-EpValue;
            ++str_length;
        }
        UEP_StrLength=0;
        while (EpValue>0)
        {
            EpValue/=10;
            ++UEP_StrLength;
        }
        str_length+=UEP_StrLength;
    }

    std::string result(str_length,' ');
    std::string::value_type* pStr=&result[0];

    //����ַ���
    if  (m_Sign<0) { *pStr='-'; ++pStr; }
    *pStr='0'; ++pStr;   *pStr='.'; ++pStr;

    long dgsize=m_Digits.size();
    for (long i=0;i<dgsize;++i)
    {
        TInt32bit Value=m_Digits[i];
        for (long d=0;d<em10Power;++d)
        {
            pStr[em10Power-1-d]=(char)('0'+(Value%10));
            Value/=10;
        }
        pStr+=em10Power;
    }

    EpValue=m_Exponent.AsInt();
    if (EpValue!=0)
    {
        *pStr='e'; ++pStr;
        if (EpValue<0)
        {
            EpValue=-EpValue;
            *pStr='-'; ++pStr;
        }
        for (long i=0;i<UEP_StrLength;++i)
        {
            pStr[UEP_StrLength-1-i]=(char)('0'+(EpValue%10));
            EpValue/=10;
        }
        pStr+=UEP_StrLength;
    }

    return result;
}

    template<class PChar>
    PChar sToLargeFloat_GetCharIntEnd(PChar int_begin,PChar str_end)
    {
        long int_count=0;
        for (PChar i=int_begin;i<str_end;++i)
        {
            if ( ('0'<=(*i)) && ((*i)<='9') )
                ++int_count;
            else
                break;
        }
        return &int_begin[int_count];
    }

    inline void sToLargeFloat_setAChar(TLargeFloat::TArray& Digits,long set_index,char aChar)
    {
        unsigned long Value=aChar-'0';
        long e10Power_count=TLargeFloat::em10Power-1-(set_index%TLargeFloat::em10Power);
        for (long i=0;i<e10Power_count;++i)
          Value*=10;
        Digits[set_index/TLargeFloat::em10Power]+=Value;
    }

void TLargeFloat::sToLargeFloat(const std::string& strValue)
{
    if (strValue.size()<=0)
    {
        this->Zero();
        return;
    }
    typedef const std::string::value_type* PChar;
    PChar pstr_begin=strValue.c_str();
    PChar pstr_end=&pstr_begin[strValue.size()];

    //str as:  [+|-][0..9][.][0..9][E|e][+|-][0..9]
    bool is_have_sign=false;
    long  sign=1;
    bool is_have_int=false;
    PChar int_begin=0; PChar int_end=0;
    bool is_have_dot=false;
    bool is_have_digits=false;
    PChar digits_begin=0; PChar digits_end=0;
    bool is_have_ep=false;
    bool is_have_ep_sign=false;
    long  ep_sign=1;
    bool is_have_ep_int=false;
    PChar ep_int_begin=0; PChar ep_int_end=0;

    //����������
    if ((*pstr_begin)=='-')
    {
        sign = -1;
        is_have_sign=true;
        ++pstr_begin;
    }
    else if ((*pstr_begin)=='+')
    {
        is_have_sign=true;
        ++pstr_begin;
    }

    //����ǰ�����������
    int_begin=pstr_begin;
    int_end=sToLargeFloat_GetCharIntEnd(int_begin,pstr_end);
    is_have_int=(int_begin!=int_end);
    if ((int_end-int_begin>=2)&&((*int_begin)=='0')) throw TException("ERROR:TLargeFloat::sToLargeFloat(); 0"); //'0?'���ֱ�ʾ����
    pstr_begin=int_end;
    if (((*pstr_begin)!='.')&&(!is_have_int)) throw TException("ERROR:TLargeFloat::sToLargeFloat(); 1"); //û���κ�����

    //����С������
    if ((*pstr_begin)=='.')
    {
        is_have_dot=true;
        ++pstr_begin;

        digits_begin=pstr_begin;
        digits_end=sToLargeFloat_GetCharIntEnd(digits_begin,pstr_end);
        is_have_digits=(digits_begin!=digits_end);
        if ((!is_have_digits)&&(!is_have_int)) throw TException("ERROR:TLargeFloat::sToLargeFloat(); 2"); //û���κ�����
        pstr_begin=digits_end;
    }

    //����ָ������
    if ( ((*pstr_begin)=='e')||((*pstr_begin)=='E') )
    {
        is_have_ep=true;
        ++pstr_begin;
        //����ָ����������
        if ((*pstr_begin)=='-')
        {
            ep_sign = -1;
            is_have_ep_sign=true;
            ++pstr_begin;
        }
        else if((*pstr_begin)=='+')
        {
            is_have_ep_sign=true;
            ++pstr_begin;
        }
        //����ָ���е�����
        ep_int_begin=pstr_begin;
        ep_int_end=sToLargeFloat_GetCharIntEnd(ep_int_begin,pstr_end);
        is_have_ep_int=(ep_int_begin!=ep_int_end);
        if ((ep_int_end-ep_int_begin>=2)&&((*ep_int_begin)=='0')) throw TException("ERROR:TLargeFloat::sToLargeFloat(); 3"); //'0?'���ֱ�ʾ����
        pstr_begin=ep_int_end;
        if (!is_have_ep_int) throw TException("ERROR:TLargeFloat::sToLargeFloat(); 4"); //ָ��û������
    }
    if (pstr_begin!=pstr_end) throw TException("ERROR:TLargeFloat::sToLargeFloat(); 5"); //δԤ�ϵ��ַ�


    //////////////////
    //ʵ�ʵ�����ת��

    this->Zero();
    this->m_Sign=sign;
    this->m_Exponent=(int_end-int_begin);
    long need_digits_count=(int_end-int_begin)+(digits_end-digits_begin);
    if ((long)this->GetDigitsLength()<need_digits_count)
      this->SetDigitsLength(need_digits_count);
    long set_index=0;
    PChar set_begin=int_begin;
    for (;set_begin<int_end;++set_begin,++set_index)
        sToLargeFloat_setAChar(this->m_Digits,set_index,*set_begin);
    set_begin=digits_begin;
    for (;set_begin<digits_end;++set_begin,++set_index)
        sToLargeFloat_setAChar(this->m_Digits,set_index,*set_begin);

    if (is_have_ep)
    {
        TExpInt ep=0;
        for (PChar set_begin=ep_int_begin;set_begin<ep_int_end;++set_begin)
        {
            ep*=10;
            ep+=((*set_begin)-'0');
        }
        ep*=ep_sign;
        this->m_Exponent+=ep;
    }
    Canonicity();
}


long  TLargeFloat::Compare(const SelfType& Value) const
{
    if (this==&Value) return 0;
    //(*this)>Value ����1��С�ڷ���-1����ȷ���0

    //�ȽϷ���
    if (m_Sign>Value.m_Sign)
        return 1;
    else if(m_Sign<Value.m_Sign)
        return -1;
    else //m_Sign==Value.m_Sign
    {
        if(m_Sign==0)
            return 0;
    }
    //m_Sign==Value.m_Sign

    //�Ƚ�ָ��
    if (m_Exponent.AsInt()>Value.m_Exponent.AsInt())
        return m_Sign;
    else if (m_Exponent.AsInt()<Value.m_Exponent.AsInt())
        return -m_Sign;
    else//(m_Exponent==Value.m_Exponent)
    {
        long sizeS=m_Digits.size();
        long sizeV=Value.m_Digits.size();
        long min_size=std::min(sizeS,sizeV);
        for (long i=0;i<min_size;++i)
        {
            if (m_Digits[i]!=Value.m_Digits[i])
            {
                if (m_Digits[i]>Value.m_Digits[i])
                    return m_Sign;
                else //if (m_Digits[i]<Value.m_Digits[i])
                    return -m_Sign;
            }
        }

        //�����Ƚ� ����β��
        if (sizeS>sizeV)
        {
            for (long i=sizeV;i<sizeS;++i)
            {
                if (m_Digits[i]>0)
                    return m_Sign;;
            }
        }
        else if (sizeS<sizeV)
        {
            for (long i=sizeS;i<sizeV;++i)
            {
                if (Value.m_Digits[i]>0)
                    return -m_Sign;
            }
        }
        //sizeS==sizeV

        return 0;
    }
}

//////////////////////////////
//+ -

TLargeFloat::SelfType& TLargeFloat::operator += (const SelfType& Value)
{
    if (Value.m_Sign==0)
        return (*this);
    else if (m_Sign==0)
        return (*this)=Value;
    else if (m_Sign==Value.m_Sign)
    {
        TInt32bit oldSign=m_Sign;
        Abs_Add(Value);
        m_Sign=oldSign;
        return *this;
    }
    else
        return *this-=(-Value);
}

TLargeFloat::SelfType& TLargeFloat::operator -= (const SelfType& Value)
{
    if (Value.m_Sign==0)
        return (*this);
    else if (m_Sign==0)
    {
        (*this)=-Value;
        return (*this);
    }
    else if (m_Sign==Value.m_Sign)
    {
        long comResult=this->Compare(Value);
        if (comResult==0)
        {
            this->Zero();
        }
        else
        {
            Abs_Sub_Abs(Value);
            m_Sign=comResult;
        }
        return *this;
    }
    else
        return *this+=(-Value);
}

void TLargeFloat::Abs_Add(const SelfType& Value)//����ֵ�ӷ�
{
    this->Abs();
    SelfType Right(Value);
    Right.Abs();

    //����һ��
    if (m_Digits.size()<Right.m_Digits.size())
        m_Digits.resize(Right.m_Digits.size(),0);
    else if (m_Digits.size()>Right.m_Digits.size())
        Right.m_Digits.resize(m_Digits.size(),0);
    //������ָ���ϴ�Ϳ�����
    if (m_Exponent.AsInt()<Right.m_Exponent.AsInt())
        this->Swap(Right);
    long size=m_Digits.size();

    TMaxInt iMoveRightCount=m_Exponent.AsInt()-Right.m_Exponent.AsInt();
    if (iMoveRightCount>=size*(TMaxInt)TLargeFloat::em10Power) return;
    TLargeFloat_CtrlExponent(Right.m_Digits,iMoveRightCount);//����С����

    TLargeFloat_ArrayAdd(&m_Digits[0],size,&Right.m_Digits[0],size);
    if (m_Digits[0]>=emBase)
        Canonicity();
}

void TLargeFloat::Abs_Sub_Abs(const SelfType& Value)//����ֵ����
{
    this->Abs();
    SelfType Right(Value);
    Right.Abs();

    long comResult=this->Compare(Right);
    if (comResult==0)
    {
        this->Zero();
        return;
    }
    else if (comResult<0)
        this->Swap(Right);

    //����һ��
    if (m_Digits.size()<Right.m_Digits.size())
        m_Digits.resize(Right.m_Digits.size(),0);
    else if (m_Digits.size()>Right.m_Digits.size())
        Right.m_Digits.resize(m_Digits.size(),0);

    long size=m_Digits.size();

    TMaxInt iMoveRightCount=m_Exponent.AsInt()-Right.m_Exponent.AsInt();
    if (iMoveRightCount>=size*(TMaxInt)TLargeFloat::em10Power) return;
    TLargeFloat_CtrlExponent(Right.m_Digits,iMoveRightCount); //����С����

    TLargeFloat_ArraySub(&m_Digits[0],size,&Right.m_Digits[0],size);
    if (m_Digits[0]*10<emBase)
        Canonicity();
}



/////////////////////////////////
// /

    //����32bit��������M����: (emBase-1)+(M-1)*emBase<=TInt32bit_MAX_VALUE
    const TInt32bit csMaxDiviValue=TInt32bit_MAX_VALUE/TLargeFloat::emBase -1;
    //������������M����: (emBase-1)+(M-1)*emBase<=TMaxInt_MAX_VALUE
    const TMaxInt csMaxDiviValueBig=TMaxInt_MAX_VALUE/TLargeFloat::emBase -1;

void TLargeFloat::DivInt(TMaxInt iValue)//����һ������
{
    if (iValue==0)
        throw TException("ERROR:TLargeFloat::DivInt()");
    else if (iValue<0)
    {
        iValue=-iValue;
        this->Chs();
        //continue
    }
    if (iValue==1)  return;
    if (this->m_Sign==0) return;

    if (iValue>csMaxDiviValueBig)
    {
        TLargeFloat y(0.0);
        y.iToLargeFloat(iValue);
        (*this)/=y;
        return;
    }

    if (iValue<=csMaxDiviValue)
    {
        TInt32bit iDiv=(TInt32bit)iValue;
        long size=m_Digits.size();
        for (long i=0;i<size-1;++i)
        {
            m_Digits[i+1]+=(m_Digits[i]%iDiv)*emBase;
            m_Digits[i]/=iDiv;
        }
        if (size>=1)
            m_Digits[size-1]/=iDiv;
    }
    else
    {
        TMaxInt iDiv=iValue;
        long size=m_Digits.size();
        TMaxInt cur_value=m_Digits[0];
        for (long i=0;i<size-1;++i)
        {
            m_Digits[i]=(TInt32bit)(cur_value/iDiv);
            cur_value=m_Digits[i+1]+(cur_value%iDiv)*emBase;
        }
        if (size>=1)
            m_Digits[size-1]=(TInt32bit)(cur_value/iDiv);
    }

    Canonicity();
}

TLargeFloat::SelfType& TLargeFloat::operator /= (long double  fValue)
{
    TMaxInt iValue=(TMaxInt)fValue;
    if (iValue==fValue)
    {
        DivInt(iValue);
        return *this;
    }
    else
        return (*this)/=TLargeFloat(fValue);
}

TLargeFloat::SelfType& TLargeFloat::operator /= (const SelfType& Value)
{
    SelfType x(Value);
    x.Rev();//x=1/x;
    return (*this)*=x;
}

void TLargeFloat::Rev()//����
{
    //��1/a,
    // ����a=1/x;  y=a-1/x;
    // �󵼵�y'=1/x^2;
    // ����ţ�ٷ��� x(n+1)=x(n)-y(x(n))/y'(x(n));
    // �е���ʽ x_next=(2-a*x)*x; //��֤�����ù�ʽΪ2��������ʽ
    // ֤��:��x=1/a+dx;
    // ����x_next-1/a=(2-a*(1/a+dx))*(1/a+dx)-1/a
    //               =(-a)*dx^2
    // ֤��.

    if (this->m_Sign==0) throw TException("ERROR:TLargeFloat::Rev()");
    TExpInt oldExponent=m_Exponent;

    SelfType a(*this);
    a.m_Exponent=0;
    SelfType x(0.0,TLargeFloat::TDigits(a.GetDigitsLength()));
    x=1.0/a.AsFloat();//��ʼ����ֵ

    TDigitsLengthAutoCtrl dlCtrl(2,emLongDoubleDigits-1,(a.m_Digits.size()*TLargeFloat::em10Power));
    SelfType ta(0.0,TLargeFloat::TDigits(a.GetDigitsLength()));
    SelfType temp(0.0,TLargeFloat::TDigits(a.GetDigitsLength()));
    dlCtrl.add_to_ctrl(&ta);
    dlCtrl.add_to_ctrl(&x);
    dlCtrl.add_to_ctrl(&temp);
    for (long i=0;i<dlCtrl.get_runcount();++i)
    {
        ta=a;
        dlCtrl.SetNextDigits();
        //x=x*2-x*x*ta;
        temp=x;
        temp*=temp;
        temp*=ta;
        x*=2;
        x-=temp;
    }

    x.m_Exponent-=oldExponent;
    this->Swap(x);
}


/////////////////////////////////////////////////////
//

void TLargeFloat::RevSqrt()//
{
    //��1/a^0.5,
    // ����a=1/x^2;  y=a-1/x^2;
    // �󵼵�y'=2/x^3;
    // ����ţ�ٷ��� x(n+1)=x(n)-y(x(n))/y'(x(n));
    // �е���ʽ x_next=(3-a*x*x)*x/2; //��֤�����ù�ʽΪ2��������ʽ
    // ֤��:��x=1/a^0.5+dx;
    // ����x_next-1/a^0.5=(3-a*(1/a^0.5+dx)*(1/a^0.5+dx))*(1/a^0.5+dx)/2 - 1/a^0.5
    //                   =-(1.5/a^0.5)*dx^2-0.5*a*dx^3;
    // ֤��.
    if (this->m_Sign<0) throw TException("ERROR:TLargeFloat::RevSqrt()");
    if (this->m_Sign==0) return;

    SelfType a(*this);
    TMaxInt sqrExponent=a.m_Exponent.AsInt()/2;
    a.m_Exponent-=(sqrExponent*2);


    SelfType x(0.0,TDigits(a.GetDigitsLength()));
    x=1.0/sqrt(a.AsFloat());//��ʼ����ֵ

    TDigitsLengthAutoCtrl dlCtrl(2,emLongDoubleDigits-1,(a.m_Digits.size()*TLargeFloat::em10Power));
    SelfType ta(0.0,TLargeFloat::TDigits(a.GetDigitsLength()));
    SelfType temp(0.0,TLargeFloat::TDigits(a.GetDigitsLength()));
    dlCtrl.add_to_ctrl(&ta);
    dlCtrl.add_to_ctrl(&x);
    dlCtrl.add_to_ctrl(&temp);
    for (long i=0;i<dlCtrl.get_runcount();++i)
    {
        ta=a;
        dlCtrl.SetNextDigits();
        //x=(3-x*x*ta)*x/2;
        temp=x;
        temp*=temp;
        temp*=ta;
        temp.Chs();
        temp+=3;
        x*=temp;
        x/=2;
    }

    x.m_Exponent-=sqrExponent;
    this->Swap(x);
}

////////////////////////////
//*

void TLargeFloat::MulInt(TMaxInt iValue)
{
    if (this->m_Sign==0) return;
    if (iValue==0)
    {
        this->Zero();
        return;
    }
    else if (iValue<0)
    {
        iValue=-iValue;
        this->Chs();
        //continue
    }

    if (iValue>csMaxMuliValue)
    {
        TLargeFloat y(0.0);
        y.iToLargeFloat(iValue);
        (*this)*=y;
        return;
    }

    //����һ������
    TInt32bit Value=(TInt32bit)iValue;
    long size=m_Digits.size();
    for (long i=size-1;i>=0;--i)
    {
        m_Digits[i]*=Value;
    }
    for (long j=size-1;j>=1;--j)
    {
        if (m_Digits[j]>=emBase)
        {
            m_Digits[j-1]+=m_Digits[j]/emBase;
            m_Digits[j]%=emBase;
        }
    }
    Canonicity();
}
TLargeFloat::SelfType& TLargeFloat::operator *= (long double  fValue)
{
    TMaxInt iValue=(TMaxInt)fValue;
    if (iValue==fValue)
    {
        MulInt(iValue);
        return *this;
    }
    else
    {
        TLargeFloat temp(fValue);
        return (*this)*=temp;
    }
}

inline void getBestMulSize(const TInt32bit*& x,long& xsize,const TInt32bit*& y,long& ysize)
{
    long bxsize=xsize;
    long bysize=ysize;

    long i;
    for (i=xsize-1;i>=0;--i)
    {
        if (x[i]==0)
            --bxsize;
        else
            break;
    }
    for (i=ysize-1;i>=0;--i)
    {
        if (y[i]==0)
            --bysize;
        else
            break;
    }

    if (bxsize<bysize)
    {
        std::swap(bxsize,bysize);
        std::swap(xsize,ysize);
        std::swap(x,y);
    }
    xsize=bxsize;

    const long csABigMulSize=1000;
    if ( (bysize<csABigMulSize)||(bxsize*2>=bysize*3)||(bxsize>ysize) )
        ysize=bysize;
    else
        ysize=bxsize;
}

TLargeFloat::SelfType& TLargeFloat::operator *= (const SelfType& Value)
{
    long xsize=m_Digits.size();
    long ysize=Value.m_Digits.size();
    if ((m_Sign==0)||(Value.m_Sign==0))
    {
        if (m_Sign!=0)
            this->Zero();
        if (xsize<ysize)
            m_Digits.resize(ysize,0);
        return *this;
    }
    if (xsize<ysize)
        m_Digits.resize(ysize,0);

    long rminsize=std::max(xsize,ysize)+2;//�˷������Ҫ��λ��

    const TInt32bit* x=&m_Digits[0];
    const TInt32bit* y=&Value.m_Digits[0];
    getBestMulSize(x,xsize,y,ysize);
    if (rminsize>xsize+ysize)
        rminsize=xsize+ysize;

    TArray tempArray(rminsize);
    ArrayMUL(&tempArray[0],rminsize,x,xsize,y,ysize);

    xsize=m_Digits.size();
    long resultsize=std::min(xsize,rminsize);
    long i;
    for (i=0;i<resultsize;++i)  this->m_Digits[i]=tempArray[i];
    for (i=resultsize;i<xsize;++i) this->m_Digits[i]=0;
    m_Exponent+=Value.m_Exponent;
    m_Sign*=Value.m_Sign;
    Canonicity();
    return *this;
}


////////////////////////////////////////////////////////////
//���ٸ���Ҷ�任ʵ�ִ������˷�
//  FFT Mul

struct TComplex //��������
{
    double  i;
    double  r;
};

//��ʼ��

void FFTInitial(TComplex* w,long* lst,const long n)
{
    //����W^i , i in [0--n)
    const double PI=3.1415926535897932385;
    const double seta=2.0*PI/n;
    long i,j;

    long n2=n>>2;
    for (i=0;i<=n2;++i)
    {
        w[i].i=sin(seta*i);
        w[i].r=cos(seta*i);
    }
    for (j=(n2+1),i=(n2-1); i>=0 ;--i,++j)
    {
        w[j].i= w[i].i;
        w[j].r=-w[i].r;
    }

    //��������������
    lst[0]=0;
    i=1;
    long m;
    for (n2=n>>1,m=2; n2>0 ;n2=n2>>1,m =m<<1)
    {
        for (long j=0;i<m;++i,++j)
        {
            lst[i]=lst[j]+n2;
        }
    }
}

//���ٸ���Ҷ�任
void FFT(TComplex* a,const TComplex* w,const long n)
{
    long n2=1;
    long n1=n >> 1;
    for (long per=1;per<n;)
    {
        long m=n2;  long j=0;  long k=n2;
        per<<=1;
        while (k<n)
        {
            for (long i2=0; j<m ;++j,++k,i2+=n1)
            {
                TComplex tmpb=a[j];
                double   tmp1=a[k].r*w[i2].r-a[k].i*w[i2].i;
                double   tmp2=a[k].r*w[i2].i+a[k].i*w[i2].r;
                a[j].r=tmpb.r+tmp1;
                a[j].i=tmpb.i+tmp2;
                a[k].r=tmpb.r-tmp1;
                a[k].i=tmpb.i-tmp2;
            }
            m+=per;
            j+=n2;
            k+=n2;
        }
        n2=per;
        n1>>=1;
    }
}


//������ٸ���Ҷ�任
void InvFFT(TComplex* a,const TComplex* w,const long n)
{
    for (long i=0;i<n;++i)
        a[i].i=-a[i].i;
    FFT(a,w,n);
}

void FFT_Convolution(const TComplex* a,TComplex* b,const long n)
{
    for (long i=0;i<n;++i)
    {
        double br=a[i].r*b[i].r - a[i].i*b[i].i;
        b[i].i=a[i].r*b[i].i + a[i].i*b[i].r;
        b[i].r=br;
    }
}

    void FFT_IntArrayCopyToComplexArray(const TInt32bit* ACoef,const long ASize,TComplex* result,const long n,const long* lst)
    {
        for (long i=0;i<n;++i)
        {
            long ai=lst[i];
            if (ai<ASize)
                result[i].r=ACoef[ai];
            else
                result[i].r=0.0;
            result[i].i=0.0;
        }
    }

    void FFT_ComplexArrayToIntArray(const TComplex* cmx,const long n,TInt32bit* result,const long rMinSize)
    {
        const double tmpRevN=1.0/n;
        double FFT_int_base;
        TLargeFloat::TArray tempResult;
        TInt32bit* dst=0;
        long dstsize=0;
        {
            FFT_int_base=(long)TLargeFloat::emBase;
            dstsize=rMinSize;
            dst=result;
        }
        const double tmpRevFFT_int_base=1.0/FFT_int_base;

        double MaxWorstEr=0;
        double tmp=0.0;
        for (long i=std::min(n,dstsize)-1;i>=1;--i)
        {
            double num =cmx[i-1].r*tmpRevN+tmp;
            tmp=floor((num+0.499)*tmpRevFFT_int_base);
            dst[i]=(TInt32bit)(num+0.499-tmp*FFT_int_base);

            double newWorstEr=abs(num-tmp*FFT_int_base-dst[i]);//��¼������
           if (newWorstEr>MaxWorstEr)
                MaxWorstEr=newWorstEr;
        }
        if (dstsize>0)
            dst[0]=(TInt32bit)(tmp+0.1);
        if (MaxWorstEr>=0.499)
            throw TLargeFloat::TException("ERROR:FFT's FFT_ComplexArrayToIntArray(); "); //������
    }


//FFTƽ��
void SquareFFT(const TInt32bit* ACoef,const long ASize,TInt32bit* CCoef,const long CMinSize)
{
    long ansize=ASize+ASize;
    long n=1;
    while (n<ansize) n<<=1;

    std::vector<TComplex>   _w((n>>1)+1);
    std::vector<long>       _lst(n);
    TComplex* w=&_w[0];
    long*     lst=&_lst[0];
    FFTInitial(w,lst,n);

    std::vector<TComplex>   _a(n);
    TComplex* a=&_a[0];
    FFT_IntArrayCopyToComplexArray(ACoef,ASize,a,n,lst);

    FFT(a,w, n);
    FFT_Convolution(a,a,n);

    std::vector<TComplex>   _tmpa(n);
    _tmpa.swap(_a);
    TComplex* tmpa=&_tmpa[0]; a=&_a[0];
    for (long i=0;i<n;++i)  a[i]=tmpa[lst[i]];
    _tmpa.clear();
    _lst.clear();
    InvFFT(a,w,n);
    _w.clear();
    FFT_ComplexArrayToIntArray(a,n,CCoef,CMinSize);
 }


//FFT�˷�
void MulFFT(const TInt32bit* ACoef,const long ASize,const TInt32bit* BCoef,const long BSize,TInt32bit* CCoef,const long CMinSize)
{
    long absize=(ASize+BSize);
    long n=1;
    while (n<absize) n<<=1;

    std::vector<TComplex>   _w((n>>1)+1);
    std::vector<long>       _lst(n);
    TComplex* w=&_w[0];
    long*     lst=&_lst[0];
    FFTInitial(w,lst,n);

    std::vector<TComplex>   _a(n);
    TComplex* a=&_a[0];
    FFT_IntArrayCopyToComplexArray(ACoef,ASize,a,n,lst);
    std::vector<TComplex>   _b(n);
    TComplex* b=&_b[0];
    FFT_IntArrayCopyToComplexArray(BCoef,BSize,b,n,lst);

    FFT(b,w, n);
    FFT(a,w, n);
    FFT_Convolution(a,b,n);
    for (long i=0;i<n;++i)  a[i]=b[lst[i]];
    _b.clear();
    _lst.clear();
    InvFFT(a,w,n);
    _w.clear();
    FFT_ComplexArrayToIntArray(a,n,CCoef,CMinSize);
}


/////////////////////////////////////////////////////////////////////////////////////////////

const long csBestMUL_ExE_size           =1024       /TLargeFloat::em10Power;
const long csBestMUL_Dichotomy_size     =4096       /TLargeFloat::em10Power;
const long csBestMul_FFT4Max_size       =16777216   /TLargeFloat::em10Power;
void ArrayMUL(TInt32bit* result,long rminsize,const TInt32bit* x,long xsize,const TInt32bit* y,long ysize)
{
    if (xsize<ysize)
    {
        std::swap(xsize,ysize);
        std::swap(x,y);
    }
    if (rminsize<ysize)
    {
        xsize=rminsize;
        ysize=rminsize;
    }
    if (ysize<=csBestMUL_ExE_size)  //
        TLargeFloat_ArrayMUL_ExE(result,rminsize,x,xsize,y,ysize);
    else  if (ysize<=csBestMUL_Dichotomy_size)
        ArrayMUL_DichotomyPart(result,rminsize,x,xsize,y,ysize);
    else if ((xsize+ysize)<=(csBestMul_FFT4Max_size*2))
    {
        if (x==y)
            SquareFFT(x,xsize,result,rminsize);
        else
            MulFFT(x,xsize,y,ysize,result,rminsize);
    }
    else
        ArrayMUL_DichotomyPart(result,rminsize,x,xsize,y,ysize);
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LargeFloat_UnitTest()
{
    //��Ԫ����

    //��������... ������̫��...
    //todo:

    TLargeFloat x(200,TLargeFloat::TDigits(100));
    TLargeFloat y(12345.678987654321,TLargeFloat::TDigits(100));
    //TLargeFloat z("-12345.678987654321e-100",TLargeFloat::TDigits(100));

    TLargeFloat z("99999999999999999999999999999999999999999999",TLargeFloat::TDigits(200));
//
}

int main()
{
  int T;cin>>T;
	while(T--)
    {

     ll x1,y1,x2,y2,x3,y3,x,y;
     while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x>>y)
     {
         TLargeFloat X1(x1,TLargeFloat::TDigits(1500)),Y1(y1,TLargeFloat::TDigits(1500)),X2(x2,TLargeFloat::TDigits(1500)),Y2(y2,TLargeFloat::TDigits(1500))
         ,X3(x3,TLargeFloat::TDigits(1500)),Y3(y3,TLargeFloat::TDigits(1500)),X(x,TLargeFloat::TDigits(1500)),Y(y,TLargeFloat::TDigits(1500));
         TLargeFloat a(X1-X2);
         TLargeFloat b(Y1-Y2);
         TLargeFloat c(X1-X3);
         TLargeFloat d(Y1-Y3);
         TLargeFloat e((X1*X1-X2*X2-Y2*Y2+Y1*Y1)/2.0);
         TLargeFloat f((X1*X1-X3*X3-Y3*Y3+Y1*Y1)/2.0);
         TLargeFloat X0((b*f-d*e)/(b*c-a*d));
         TLargeFloat Y0((c*e-a*f)/(b*c-a*d));
         //cout<<X0<<' '<<Y0<<endl;
         TLargeFloat R_f((X1-X0)*(X1-X0)+(Y1-Y0)*(Y1-Y0));
         //cout<<R_f<<endl;
         //if((X-X0)*(X-X0)+(Y-Y0)*(Y-Y0)==R_f) cout<<",,,,,"<<endl;
         if((X-X0)*(X-X0)+(Y-Y0)*(Y-Y0)>R_f) cout<<"Accepted"<<endl;
         else cout<<"Rejected"<<endl;
     }

	}
	return 0;
}
