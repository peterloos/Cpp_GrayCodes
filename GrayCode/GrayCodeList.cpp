#include <iostream>
using namespace std;

#include "BitVector.h"
#include "GrayCodeList.h"

// c'tors / d'tor
GrayCodeList::GrayCodeList()
{
    m_len = 0;
    m_top = 0;
    m_list = (BitVector*) 0;
}

GrayCodeList::GrayCodeList(int len)
{
    m_len = len;
    m_top = 0;
    m_list = new BitVector [m_len];
}

GrayCodeList::GrayCodeList(const GrayCodeList& v)
{
    m_len = v.m_len;
    m_top = v.m_top;
    m_list = new BitVector [m_len];

    for (int i = 0; i < m_top; i ++)
        m_list[i] = v.m_list[i];
}

GrayCodeList::~GrayCodeList()
{
    delete[] m_list;
}

// public interface
bool GrayCodeList::Add (const BitVector& vec)
{
    if (m_top == m_len)
        return false;

    m_list[m_top] = vec;
    m_top ++;
    return true;
}

// public operators
BitVector GrayCodeList::operator[] (int i) const
{
    return m_list[i];
}

GrayCodeList& GrayCodeList::operator= (const GrayCodeList& list)
{
    if (this == &list)
        return *this;

    delete[] m_list;

    m_len = list.m_len;
    m_top = list.m_top;
    m_list = new BitVector [m_len];

    for (int i = 0; i < m_top; i ++)
        m_list[i] = list.m_list[i];

    return *this;
}

// output
ostream& operator<< (ostream& os, const GrayCodeList& list)
{
    for (int i = 0; i < list.Length(); i ++)
        os << list[i] << endl;

    return os;
}
