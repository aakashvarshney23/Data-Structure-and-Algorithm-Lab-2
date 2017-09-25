
#include "bigPosInteger.h"

bigPosInteger::bigPosInteger() {
    valueArray = NULL;
    length = 0;
}


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
    int input;

    input = value;
    while (input) {
        input = input / 10;
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


bigPosInteger bigPosInteger::operator+( bigPosInteger &rhs)
/*this operator should be able to add two bigPosInteger together and return the result. The default return should be replaced with the appropriate variable*/
{


    bigPosInteger a = *this;
    bigPosInteger *c = new bigPosInteger('0');


    int len;
    if (a.length > rhs.length) {
        len = a.length;
    } else {

        len = rhs.length;
    }

    if (c->valueArray != NULL)
        delete[] c->valueArray;
    c->length = len;
    c->valueArray = new int[len]();
    int sum = 0;
    int carry_forward = 0;
    int scd_val = 0;
    int first_val =0;
    if (a.length > rhs.length) {
        int snd_loc = rhs.length;
        for (int i = len - 1; i >= 0; i--) {
            if (snd_loc > 0) {
                --snd_loc;
                scd_val = rhs.valueArray[snd_loc];
            } else {
                scd_val = 0;
            }
            sum = (a.valueArray[i] + scd_val + carry_forward) % 10;
            carry_forward = (a.valueArray[i] + scd_val + carry_forward) / 10;
            c->valueArray[i] = sum;
        }
        return *c;
    }
    else {
        int first_loc = a.length;
        for (int i = len - 1; i >= 0; i--) {
            if (first_loc > 0) {
                --first_loc;
                first_val = a.valueArray[first_loc];
            } else {
                first_val = 0;
            }
            sum = (rhs.valueArray[i] + first_val + carry_forward) % 10;
            carry_forward = (rhs.valueArray[i] + first_val + carry_forward) / 10;
            c->valueArray[i] = sum;
        }
        return *c;
    }
}


bigPosInteger bigPosInteger::operator-(const bigPosInteger &rhs)
/*this operator should be able to subtract the Right Hand Side bigPosInteger from the base bigPosInteger and return the result. The default return should be replaced with the appropriate variable*/
{


    bigPosInteger b = *this;
    bigPosInteger d = *this;
    bigPosInteger *c = new bigPosInteger('0');
    int len;
    int len1;
    int diff = 0;
    if (rhs.length > b.length) {
        cout << "Error, this program doesnt accept negative numbers." << endl;
    } else {
        if (b.length >= rhs.length)
            len = b.length;
        else
            len = rhs.length;


        len1 = rhs.length - 1;
        d.length = len;
        d.valueArray = new int[len];

        for (int i = len - 1; i >= 0; i--) {
            if (len1 >= 0) {
                d.valueArray[i] = rhs.valueArray[len1];
                len1--;
            } else {
                d.valueArray[i] = 0;
            }

        }

        if (c->valueArray != NULL)
            delete[] c->valueArray;
        c->length = len;
        c->valueArray = new int[len]();
        for (int i = len - 1; i >= 0; i--) {
            if (b.valueArray[i] >= d.valueArray[i]) {
                diff = b.valueArray[i] - d.valueArray[i];
            }
            if (b.valueArray[i] < d.valueArray[i]) {
                diff = (b.valueArray[i] + 10) - d.valueArray[i];
                b.valueArray[i - 1] = b.valueArray[i - 1] - 1;
            }
            c->valueArray[i] = diff;
        }

        return *c;
    }
}

bigPosInteger bigPosInteger::operator*(const bigPosInteger &rhs)
/*this operator should be able to multiply two bigPosInteger together and return the result. The default return should be replaced with the appropriate variable*/
{
    bigPosInteger resultant("");
    string solstring = "";
    ostringstream outs("");
    for (int i = 0; i < length; i++)
        outs << valueArray[i];
    string num1 = outs.str();
    ostringstream out("");
    for (int i = 0; i < rhs.length; i++)
        out << rhs.valueArray[i];
    string num2 = out.str();
    int size1 = num1.size();
    int size2 = num2.size();
    vector<int> result(size1 + size2, 0);

    int p1 = 0;
    int p2 = 0;

    for (int i = size1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1 = num1[i] - '0';
        p2 = 0;
        for (int j = size2 - 1; j >= 0; j--) {
            int n2 = num2[j] - '0';
            int sum = n1 * n2 + result[p1 + p2] + carry;
            carry = sum / 10;
            result[p1 + p2] = sum % 10;
            p2++;
        }
        if (carry > 0)
            result[p1 + p2] += carry;
        p1++;
    }
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;
    if (i == -1)
        int j = 0;
    resultant.length = 0;
    while (i >= 0) {
        resultant.valueArray[resultant.length] = result[i--];
        resultant.length++;
    }
    return resultant;
}

bigPosInteger bigPosInteger::operator%(const bigPosInteger &rhs) {
    int test = 1;
    int i = 0;
    int k;
    int new_length;
    int count = 0;

    bigPosInteger num1;
    num1.length = length;
    num1.valueArray = new int[length];

    for (int j = 0; j < length; j++) {
        num1.valueArray[j] = valueArray[j];
    }

    bigPosInteger Num3;
    bigPosInteger Num4;

    while (test == 1) {
        if (i == 0) {
            if ((num1.length <= rhs.length) && (num1.valueArray[0] < rhs.valueArray[0])) {
                test = 2;
                Num3.valueArray = new int[num1.length];
                for (int j = num1.length - 1; j >= 0; j--) {
                    Num3.valueArray[j] = num1.valueArray[j];
                }
            } else {
                Num3 = num1 - rhs;

                k = Num3.length - 1;
                for (int a = 0; a < Num3.length; a++) {
                    if (a == 0) {
                        if (Num3.valueArray[a] == 0) {
                            count++;
                        }
                    } else {
                        if (Num3.valueArray[a - 1] == 0) {
                            if (Num3.valueArray[a] == 0) {
                                count++;
                            }
                        }
                    }
                }
                new_length = Num3.length - count;
                Num4.valueArray = new int[new_length];
                for (int j = new_length - 1; j >= 0; j--) {
                    Num4.valueArray[j] = Num3.valueArray[k];
                    k--;
                }
                delete[] Num3.valueArray;
                Num3.valueArray = new int[new_length];
                Num3.length = new_length;
                for (int j = new_length - 1; j >= 0; j--) {
                    Num3.valueArray[j] = Num4.valueArray[j];
                }
                delete[] Num4.valueArray;
            }
        } else {
            int w = Num3.valueArray[0];
            int y = rhs.valueArray[0];
            if ((Num3.length) <= rhs.length) {
                if (Num3.valueArray[0] < rhs.valueArray[0]) {
                    test = 2;
                } else {
                    Num3 = Num3 - rhs;
                    count = 0;
                    k = Num3.length - 1;
                    for (int a = 0; a < Num3.length; a++) {
                        if (a == 0) {
                            if (Num3.valueArray[a] == 0) {
                                count++;
                            }
                        } else {
                            if (Num3.valueArray[a - 1] == 0) {
                                if (Num3.valueArray[a] == 0) {
                                    count++;
                                }
                            }
                        }
                    }
                    new_length = Num3.length - count;
                    Num4.valueArray = new int[new_length];
                    for (int j = new_length - 1; j >= 0; j--) {
                        Num4.valueArray[j] = Num3.valueArray[k];
                        k--;
                    }
                    delete[] Num3.valueArray;
                    Num3.valueArray = new int[new_length];
                    Num3.length = new_length;
                    for (int j = new_length - 1; j >= 0; j--) {
                        Num3.valueArray[j] = Num4.valueArray[j];
                    }

                    delete[] Num4.valueArray;
                }
            } else {
                Num3 = Num3 - rhs;

                count = 0;
                k = Num3.length - 1;
                for (int a = 0; a < Num3.length; a++) {
                    if (a == 0) {
                        if (Num3.valueArray[a] == 0) {
                            count++;
                        }
                    } else {
                        if (Num3.valueArray[a - 1] == 0) {
                            if (Num3.valueArray[a] == 0) {
                                count++;
                            }
                        }
                    }
                }
                new_length = Num3.length - count;
                Num4.valueArray = new int[new_length];
                for (int j = new_length - 1; j >= 0; j--) {
                    Num4.valueArray[j] = Num3.valueArray[k];
                    k--;
                }
                delete[] Num3.valueArray;
                Num3.valueArray = new int[new_length];
                Num3.length = new_length;
                for (int j = new_length - 1; j >= 0; j--) {
                    Num3.valueArray[j] = Num4.valueArray[j]; //copy values into a new bigPosInteger object array, exclude zero in the beginning
                }
                delete[] Num4.valueArray;
            }
        }
        i++;
    }
    return Num3;
}

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
