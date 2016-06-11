class GrayCodeList
{
private:
    int m_len;
    int m_top;
    BitVector* m_list;

public:
    // c'tors / d'tor
    GrayCodeList();
    GrayCodeList(int len);
    GrayCodeList(const GrayCodeList&);
    ~GrayCodeList();

    // getter
    int Length () const { return m_len; }

    // public interface
    bool Add (const BitVector&);

    // public operators
    BitVector operator[] (int i) const;
    GrayCodeList& operator= (const GrayCodeList&);

    // output
    friend ostream& operator<< (ostream&, const GrayCodeList&);
};