class GrayCodeCalculator
{
private:
    int m_length;

public:
    // c'tor
    GrayCodeCalculator();

    // getter/setter
    int GetLength () const { return m_length; }
    void SetLength (int length) { m_length = length; }

    // public interface
    GrayCodeList Calculate ();

private:
    // private helper method
    GrayCodeList Calculate (int length);
    GrayCodeList CalculateRankOne ();
};