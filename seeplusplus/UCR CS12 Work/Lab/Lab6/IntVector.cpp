#include "IntVector.h"

using namespace std;

IntVector::IntVector(){
    sz = 0;
    cap = 0;
    data = nullptr;
}

IntVector::IntVector(unsigned size, int value){
    sz = size;
    cap = size;
    data = new int[size];
    for(unsigned i = 0; i < size; ++i){
        data[i] = value;
    }
}

IntVector::~IntVector(){
    delete[] data;
}

unsigned IntVector::size() const{
    return sz;
}

unsigned IntVector::capacity() const{
    return cap;
}

bool IntVector::empty() const{
    return (sz == 0);
}

const int & IntVector::at(unsigned index) const{
    if(index >= sz){
        throw out_of_range("IntVector::at_range_check");
    }
    else{
        return data[index];
    }
}

int & IntVector::at(unsigned index){
    if(index >= sz){
        throw out_of_range("IntVector::at_range_check");
    }
    else{
        return data[index];
    }
}

void IntVector::expand(){
    if(cap == 0){
        cap = 1;
        data = new int[cap];
    }
    else{
        cap = cap*2;
        int *datatemp = new int[cap];
        for(unsigned i = 0; i < cap/2; ++i){
            datatemp[i] = data[i];
        }
        delete[] data;
        data = datatemp;
    }
}

void IntVector::expand(unsigned amount){
    cap = cap + amount;
    int *datatemp = new int[cap];
    for(unsigned i = 0; i < cap - amount; ++i){
            datatemp[i] = data[i];
    }
    delete[] data;
    data = datatemp;
}

void IntVector::insert(unsigned index, int value){
    if(index > sz){
        throw out_of_range("IntVector::insert_range_check");
    }
    if(sz == cap){
        expand();
    }
    sz +=1;
    for(unsigned i = index + 1; i < sz; ++i){
        data[i] = data[i-1];
    }
    data[index] = value;
}

void IntVector::erase(unsigned index){
    if(index >= sz){
        throw out_of_range("IntVector::erase_range_check");
    }
    if(sz > 0){
        sz -=1;
        for(unsigned i = index; i < sz; ++i){
            data[i] = data[i+1];
        }
    }
}

void IntVector::push_back(int value){
    if(sz == cap){
        expand();
    }
    data[sz] = value;
    sz +=1;
}

void IntVector::pop_back(){
    if(sz != 0){
        sz -= 1;
    }
}

void IntVector::clear(){
    sz = 0;
}

void IntVector::resize(unsigned size, int value){
    if(size < sz){
        sz = size;
    }
    else if(size > sz && size <= cap){
        for(unsigned i = sz; i < size; ++i){
            data[i] = value;
        }
        sz = size;
    }
    else if(size > cap){
        if(cap*2 > size){
            expand();
            for(unsigned i = sz; i < size; ++i){
            data[i] = value;
            }
            sz = size;
        }
        else{
            expand(size-cap);
            for(unsigned i = sz; i < size; ++i){
            data[i] = value;
            }
            sz = size;
        }
    }
    
}

void IntVector::reserve(unsigned n){
    if(n > cap){
        expand(n-cap);
    }
}

void IntVector::assign(unsigned n, int value){
    if(n > cap){
        if(cap*2 > n){
            expand();
            for(unsigned i = 0; i < n; ++i){
            data[i] = value;
            }
            sz = n;
        }
        else{
            expand(n-cap);
            for(unsigned i = 0; i < n; ++i){
            data[i] = value;
            }
            sz = n;
        }
    }
    for(unsigned i = 0; i < n; ++i){
        data[i] = value;
    }
    sz = n;
}

const int & IntVector::front() const{
    return data[0];
}

int & IntVector::front(){
    return data[0];
}

const int & IntVector::back() const{
    return data[sz-1];
}

int & IntVector::back(){
    return data[sz-1];
}

