//
// Created by aakas on 9/7/2017.
//

#ifndef LAB_2_BIGPOSINTEGER_H
#define LAB_2_BIGPOSINTEGER_H

#include <iostream>
#include <string>

using namespace std;

class bigPosInteger {
    int *valueArray;
    int length;


public:
    //bigPosInteger();

    explicit bigPosInteger(string value);

    explicit bigPosInteger(int valArr);

    bigPosInteger(const bigPosInteger &);//copy constructor
    virtual ~bigPosInteger();

    bigPosInteger operator+(const bigPosInteger &);

    bigPosInteger operator-(const bigPosInteger &);

    bigPosInteger operator*(const bigPosInteger &);

   // bigPosInteger operator%(const bigPosInteger &);

    bigPosInteger &operator=(const bigPosInteger &);

    friend ostream &operator<<(ostream &, const bigPosInteger &);

    friend istream &operator>>(istream &, bigPosInteger &);

};
//
//
#endif //LAB_2_BIGPOSINTEGER_H
