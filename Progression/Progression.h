//
// Created by rodrigo.cespedes on 5/06/2019.
//

#ifndef PROGRESSION_PROGRESSION_H
#define PROGRESSION_PROGRESSION_H
//ITERADORES
class ArithProgIterator{
    long cur_data;
    long step;
    friend class ArithProgression;
    ArithProgIterator(long cur_datam,long inc_datam):
    cur_data{cur_datam},step{inc_datam}{}

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
    long st1;
    long st2;
    friend class FibonacciProgression;
    FiboProgIterator(long cur,long st1, long st2):
    cur_data{cur},st1{st1},st2{st2}{};
    FiboProgIterator(long cur, long st1):
        cur_data{cur},st1{st1}{};
public:
    bool operator==(const FiboProgIterator& other) const;
    bool operator!=(const FiboProgIterator& other) const;
    long &operator*();
    FiboProgIterator& operator++();
    FiboProgIterator& operator++(int);


};



class Progression {
public:
    long first;
    Progression()= default;
    Progression(long firstm):first{firstm}{}
    long firstValue();
    virtual long nextValue();
    void printProgression(){};
};




//PROG ARITMETICA

class ArithProgression : public Progression {
    long step;
    long stop;
public:
    ArithProgression()=default;
    ArithProgression(long stop): Progression{0},step{1},stop{stop}{}
    ArithProgression(long start, long stop) : Progression{start},step{1},
    stop{stop}{}
    ArithProgression(long start, long stop, long step) : Progression{start},
    step{step},stop{stop}{}
    long nextValue(){};
    using iterator=ArithProgIterator;
    iterator begin() const{return iterator(first,stop);}

    iterator end() const{return iterator(stop, step);}
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
    cur_data +=step;
    return *this;
}

ArithProgIterator &ArithProgIterator::operator++(int){
    auto it=this;
    ++(*this);
    return *it;
}

//PROG GEOMETRICA


class GeomProgression : public Progression {
    long step;
    long start;
    long stop;
public:
    GeomProgression()= default;
    GeomProgression(long stop):Progression{0},stop{stop},step{1}{}
    GeomProgression(long start, long stop):Progression{start},stop{stop},
    step{step}{}
    GeomProgression(long start, long stop, long step): Progression{start},
    stop{stop},step{step}{}

    long nextValue(){};
    using iterator=GeomProgIterator;
    iterator  begin() const{return iterator(stop,step);}
    iterator end() const{return iterator(stop, step);}
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
    long start;
    long stop;
    long step1;
    long step2;
public:
    FibonacciProgression()= default;
    FibonacciProgression(long stop): Progression{0},stop{stop} {}
    long nextValue() override {};
    using iterator=FiboProgIterator;
    iterator begin() const{return iterator(start,step1,step2);}
    iterator end() const{return iterator(stop,step1);}
};

bool FiboProgIterator::operator==(const FiboProgIterator &other) const {
    return cur_data==other.cur_data;
}

bool FiboProgIterator::operator!=(const FiboProgIterator &other) const {
    return cur_data < other.cur_data;
}

FiboProgIterator &FiboProgIterator::operator++() {
    cur_data=st1+st2;
    st1=st2;
    st2=cur_data;
    return *this;
}




#endif //PROGRESSION_PROGRESSION_H
