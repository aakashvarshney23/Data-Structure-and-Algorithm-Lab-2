//
// Created by aakas on 9/7/2017.
//

#ifndef LAB_2_BIGPOSINTEGER_H
#define LAB_2_BIGPOSINTEGER_H

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

class bigPosInteger {
    int *valueArray;
    int length;


public:
    bigPosInteger();

    explicit bigPosInteger(string value);

    explicit bigPosInteger(int valArr);

    bigPosInteger(const bigPosInteger &);

    virtual ~bigPosInteger();

    bigPosInteger operator+( bigPosInteger &);

    bigPosInteger operator-(const bigPosInteger &);

    bigPosInteger operator*(const bigPosInteger &);

    bigPosInteger operator%(const bigPosInteger &);

    bigPosInteger &operator=(const bigPosInteger &);

    friend ostream &operator<<(ostream &, const bigPosInteger &);

    friend istream &operator>>(istream &, bigPosInteger &);

};

#endif //LAB_2_BIGPOSINTEGER_H
