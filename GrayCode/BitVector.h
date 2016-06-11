class BitVector
{
private:
    int m_len;
    bool* m_vec;

public:
    // c'tors / d'tor
    BitVector();
    BitVector(int len);
    BitVector(const BitVector&);
    ~BitVector();

    // public interface
    BitVector Extended();

    // getter
    int Length () const { return m_len; }

    // public operators
    BitVector& operator= (const BitVector&);
    bool& operator[] (int);
    const bool& operator[](int) const;	

    // output
    friend ostream& operator<< (ostream&, const BitVector&);
};
