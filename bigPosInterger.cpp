
#include "bigPosInteger.h"


bigPosInteger::bigPosInteger(string value)
/*This constructor should take in a string containing a set of chars between '0' and '9' of arbitrary length and constructs it into bigPosInteger type*/
{
    length = value.length();
    valueArray = new int[length];
    for (int i = length - 1; i >= 0; i--) {
        valueArray[i] = value.at(i) - '0';
    }

}

bigPosInteger::bigPosInteger(int value)
/*this instructor takes in an integer and constructs it into a bigPosInteger type*/
{
    int rem;
    int counter = 0;
    int in;

    in = value;
    while (in) {
        in = in / 10;
        counter++;
    }
    length = counter;
    int i = length - 1;
    valueArray = new int[length];
    if (value == 0) {
        valueArray = new int[0];
        valueArray[0] = 0;
    }

    while ((value != 0) && (i >= 0)) {
        rem = value % 10;
        valueArray[i] = rem;
        i--;
        value = value / 10;

    }
}

bigPosInteger::bigPosInteger(const bigPosInteger &value)
/*This is a copy constructor, be EXTREMELY careful for memory leaks here*/
{
    if (this == &value) {
        return;
    }
    length = value.length;
    valueArray = new int[length];
    for (int i = 0; i < length; i++) {
        valueArray[i] = value.valueArray[i];
    }
}

bigPosInteger::~bigPosInteger()
/*This is the destructor, be extremely careful for memory leaks here*/
{
    delete[] valueArray;
}

bigPosInteger bigPosInteger::operator+(const bigPosInteger &rhs)
/*this operator should be able to add two bigPosInteger together and return the result. The default return should be replaced with the appropriate variable*/
{


    bigPosInteger a = *this;
     bigPosInteger *c = new bigPosInteger ('0');


    int len;
    if (a.length > rhs.length) {
        len = a.length;
    } else {

        len = rhs.length;
    }
    if(c->valueArray!=NULL)
        delete [] c->valueArray;
    c->length = len;
    c->valueArray=new int [len]();
    int sum = 0;
    int cf = 0;
    int scd_val = 0;
    int snd_loc = rhs.length;
    for (int i = len - 1; i >= 0; i--) {
        if (snd_loc > 0) {
            --snd_loc;
            scd_val = rhs.valueArray[snd_loc];
        } else {
            scd_val = 0;
        }
        sum = (a.valueArray[i] + scd_val) % 10 + cf;
        cf = (a.valueArray[i] + scd_val + cf) / 10;
        c->valueArray[i] = sum;
    }
    return *c;
}

bigPosInteger bigPosInteger::operator-(const bigPosInteger &rhs)
/*this operator should be able to subtract the Right Hand Side bigPosInteger from the base bigPosInteger and return the result. The default return should be replaced with the appropriate variable*/
{
    bigPosInteger b = *this;

    for (int i = b.length - 1; i >= 0; i--) {
        if (b.valueArray[i] < rhs.valueArray[i]) {
            b.valueArray[i] = b.valueArray[i] + 10 - rhs.valueArray[i];
            b.valueArray[i - 1] = b.valueArray[i - 1] - 1;
        } else
            b.valueArray[i] = b.valueArray[i] - rhs.valueArray[i];
    }

    return b;
}

bigPosInteger bigPosInteger::operator*(const bigPosInteger &rhs)
/*this operator should be able to multiply two bigPosInteger together and return the result. The default return should be replaced with the appropriate variable*/
{
    bigPosInteger a = *this;
    if (length > rhs.length) {
        a.length = a.length + 1;
    } else
        a.length = rhs.length + 1;

    int val = 0;
    for (int i = a.length - 1; i >= 0; i--) {
        val = val + a.valueArray[i] + rhs.valueArray[i];

        if (val > 9) {
            a.valueArray[i] = (a.valueArray[i] * rhs.valueArray[i]) % 10;
            val = 1;
        } else {
            a.valueArray[i] = a.valueArray[i] * rhs.valueArray[i];
            val = 0;
        }

    }
    return a;
}
//bigPosInteger bigPosInteger::operator%(const bigPosInteger &) {
//    return bigPosInteger();
//}


bigPosInteger &bigPosInteger::operator=(const bigPosInteger &rhs)
/* this is the copy assignment operator, be EXTREMELY careful for memory leaks here. The default return should be replaced with the appropriate variable*/
{
    for (int i = (*this).length; i >= 0; i--)
        (*this).valueArray[i] = rhs.valueArray[i];

    return *this;
}

ostream &operator<<(ostream &stream, const bigPosInteger &rhs)
/* this is the copy assignment operator, be EXTREMELY careful for memory leaks here. The default return should be replaced with the appropriate variable*/
{
    for (int i = 0; i < rhs.length; i++) {
        stream << rhs.valueArray[i];
    }
    return stream;

}

istream &operator>>(istream &instream, bigPosInteger &object)
/* this is the copy assignment operator, be EXTREMELY careful for memory leaks here. The default return should be replaced with the appropriate variable*/
{
    string num;
    cout << "Enter a number: " << endl;
    instream >> num;

    object.length = num.length();
    object.valueArray = new int[object.length];

    for (int i = object.length - 1; i >= 0; i--) {
        object.valueArray[i] = num[i] - '0';
    }


}