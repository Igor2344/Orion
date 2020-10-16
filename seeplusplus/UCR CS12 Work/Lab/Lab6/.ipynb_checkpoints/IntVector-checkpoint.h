#include <stdexcept>

class IntVector{
    private:
    unsigned sz;
    unsigned cap;
    int *data;
    
    public:
    IntVector();
    IntVector(unsigned size, int value = 0);
    ~IntVector();
    unsigned size() const;
    unsigned capacity() const;
    bool empty() const;
    const int & at(unsigned index) const;
    void insert(unsigned index, int value);
    int & at(unsigned index);
    void erase(unsigned index);
    void push_back(int value);
    void pop_back();
    void clear();
    void resize(unsigned size, int value = 0);
    void reserve(unsigned n);
    void assign(unsigned n, int value);
    const int & front() const;
    int & front();
    const int & back() const;
    int & back();
    
    private:
    void expand();
    void expand(unsigned amount);
};