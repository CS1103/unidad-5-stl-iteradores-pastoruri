//
// Created by rodrigo.cespedes on 5/06/2019.
//

#ifndef PROGRESSION_PROGRESSION_H
#define PROGRESSION_PROGRESSION_H
//ITERADORES
class ArithProgIterator{
    long cur_data;
    long inc_data;
    friend class ArithProgression;
    ArithProgIterator(long cur_datam,long inc_datam): cur_data{cur_datam},inc_data{inc_datam}{}
public:
    bool operator==(const ArithProgIterator& other) const;
    bool operator!=(const ArithProgIterator& other) const;
    long&operator*();
    ArithProgIterator& operator++();
    ArithProgIterator& operator++(int);
};

class GeomProgIterator{
    long cur_data;
    long base;
    friend class GeomProgression;
    GeomProgIterator(long cur_datam, long basem):cur_data{cur_datam},base{basem}{}

public:
    bool operator==(const GeomProgIterator& other) const;
    bool operator!=(const GeomProgIterator& other) const;
    long &operator*();
    GeomProgIterator& operator++();
    GeomProgIterator& operator++(int);

};


class FiboProgIterator{
    long cur_data;
    long prev;
    friend class FibonacciProgression;
    FiboProgIterator(long cur_datam, long prevm):cur_data{cur_datam},prev{prevm}{}
public:
    bool operator==(const FiboProgIterator& other) const;
    bool operator!=(const FiboProgIterator& other) const;
    long &operator*();
    FiboProgIterator& operator++();
    FiboProgIterator& operator++(int);


};



class Progression {
    long first;
public:
    Progression()= default;
    Progression(long firstm):first{firstm}{}
    long firstValue();
    virtual long nextValue();
    void printProgression(){};
};




//PROG ARITMETICA

class ArithProgression : public Progression {
    long inc;
public:
    ArithProgression()=default;
    ArithProgression(long incm): Progression{0},inc{incm}{}
    long nextValue(){};
    using iterator=ArithProgIterator;
};

bool ArithProgIterator::operator==(const ArithProgIterator &other) const {
    return cur_data==other.cur_data;
}

bool ArithProgIterator::operator!=(const ArithProgIterator &other) const {
    return cur_data<other.cur_data;
}

long &ArithProgIterator::operator*() {
    return cur_data;
}

ArithProgIterator &ArithProgIterator::operator++() {
    cur_data +=inc_data;
    return *this;
}

ArithProgIterator &ArithProgIterator::operator++(int) {
    auto it=this;
    ++(*this);
    return *it;
}

//PROG GEOMETRICA


class GeomProgression : public Progression {
    long base;
public:
    GeomProgression()= default;
    GeomProgression(long basem):Progression{0},base{basem}{}
    long nextValue(){};
    using iterator=GeomProgIterator;
};

bool GeomProgIterator::operator==(const GeomProgIterator &other) const {
    return cur_data == other.cur_data;
}

bool GeomProgIterator::operator!=(const GeomProgIterator &other) const {
    return cur_data<other.cur_data;
}

long &GeomProgIterator::operator*() {
    return cur_data;
}

GeomProgIterator &GeomProgIterator::operator++() {
    cur_data=cur_data*base;
    return *this;
}

GeomProgIterator &GeomProgIterator::operator++(int) {
    auto it=this;
    ++(*this);
    return *it;
}



//PROG FIBONACCI



class FibonacciProgression : public Progression {
    long prev;
public:
    FibonacciProgression()= default;
    FibonacciProgression(long prevm): Progression{0},prev{prevm}{}
    long nextValue(){};
    using iterator=FiboProgIterator;
    FiboProgIterator(int curr, int step1, int step2): curr{curr}, step1{step1}, step2{step2} {}
    FiboProgIterator(int curr, int step1): curr{curr}, step1{step1} {}
};

bool FiboProgIterator::operator==(const FiboProgIterator &other) const {
    return cur_data==other.cur_data;
}

bool FiboProgIterator::operator!=(const FiboProgIterator &other) const {
    return cur_data < other.cur_data;
}

long &FiboProgIterator::operator*() {
    return cur_data;
}

FiboProgIterator &FiboProgIterator::operator++() {
    cur_data+=prev;
    return *this;
}

FiboProgIterator &FiboProgIterator::operator++(int) {
    auto it=this;
    ++(*this);
    return *it;
}


#endif //PROGRESSION_PROGRESSION_H
