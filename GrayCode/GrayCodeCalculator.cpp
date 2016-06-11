#include <iostream>
using namespace std;

#include "BitVector.h"
#include "GrayCodeList.h"
#include "GrayCodeCalculator.h"

// c'tor
GrayCodeCalculator::GrayCodeCalculator()
{
    m_length = 0;
}

// public interface
GrayCodeList GrayCodeCalculator::Calculate ()
{
    return Calculate (m_length);
}

// private helper methods
GrayCodeList GrayCodeCalculator::Calculate (int length)
{
    if (length == 1)
    {
        return CalculateRankOne ();
    }
    else
    {
        GrayCodeList tmp = Calculate (length - 1);

        // allocate a new Gray Code list - twice a large
        GrayCodeList result (2 * tmp.Length());

        // copy old entries ...
        for (int i = 0; i < tmp.Length(); i ++)
        {
            // ... and prefix old entry with '0'
            BitVector v = tmp[i];
            BitVector ex = v.Extended();
            ex[0] = false;
            result.Add (ex);
        }

        // mirror old entries ...
        for (int i = tmp.Length() - 1; i >= 0; i --)
        {
            // ... and prefix old entry with '1'
            BitVector v = tmp[i];
            BitVector ex = v.Extended();
            ex[0] = true;
            result.Add (ex);
        }

        return result;
    }
}

GrayCodeList GrayCodeCalculator::CalculateRankOne ()
{
    // need two entries
    GrayCodeList list (2);

    BitVector v0 (1);
    v0[0] = false;
    list.Add (v0);

    BitVector v1 (1);
    v1[0] = true;
    list.Add (v1);

    return list;
}
