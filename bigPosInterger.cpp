
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
        sum = (a.valueArray[i] + scd_val + cf) % 10;
        cf = (a.valueArray[i] + scd_val + cf) / 10;
        c->valueArray[i] = sum;
    }
    return *c;
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
    bigPosInteger solution("");
    std::string solstring = "";
    //std::string num1="",num2="";
    //converts first int array to string
    std::ostringstream outs("");
    for (int i = 0; i < length; i++)
        outs << valueArray[i];
    std::string num1 = outs.str();
    //converts second digit array to string
    std::ostringstream out("");
    for (int i = 0; i < rhs.length; i++)
        out << rhs.valueArray[i];
    std::string num2 = out.str();
    //multiplies string of numbers and results in int array
    int n1 = num1.size();
    int n2 = num2.size();
    // (n1 == 0 || n2 == 0)


    // keep the number in vector in reverse order
    std::vector<int> result(n1 + n2, 0);

    // used for positions
    int p1 = 0;
    int p2 = 0;

    // loop to move positions in num1
    for (int i = n1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1 = num1[i] - '0';

        // shift position to left after every multiplication
        p2 = 0;

        // loop to move positions in num2
        for (int j = n2 - 1; j >= 0; j--) {
            // digit value
            int n2 = num2[j] - '0';

            // add and multiply
            int sum = n1 * n2 + result[p1 + p2] + carry;

            // Carried number
            carry = sum / 10;


            result[p1 + p2] = sum % 10;

            p2++;
        }

        // store carried number in next index
        if (carry > 0)
            result[p1 + p2] += carry;


        p1++;
    }

    // move from 0 digits
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;


    if (i == -1)


        // generate resulting string
        //std::string result = "";

        int j = 0;
    solution.length = 0;
    while (i >= 0) {
        solution.valueArray[solution.length] = result[i--];
        solution.length++;
    }


    return solution;
}

bigPosInteger bigPosInteger::operator%(const bigPosInteger &num2) {
    char check = 'a';
    int i = 0;
    int k;
    int newlen;
    int zerocount = 0;

    bigPosInteger num1;
    num1.length = length;
    num1.valueArray = new int[length];

    for (int j = 0; j < length; j++) {
        num1.valueArray[j] = valueArray[j]; //copy values into a new bigPosInteger object array
    }

    bigPosInteger Num3;
    bigPosInteger Num4;

    while (check == 'a') { //if char equals 'a', then the num2 is bigger than num3
        if (i == 0) {
            if ((num1.length <= num2.length) && (num1.valueArray[0] < num2.valueArray[0])) {
                check = 'b';
                Num3.valueArray = new int[num1.length];
                for (int j = num1.length - 1; j >= 0; j--) {
                    Num3.valueArray[j] = num1.valueArray[j]; //copy values into a new bigPosInteger object array, excludes zeros in the beginning
                }
            } else {
                Num3 = num1 -
                       num2; //will put a zero in the front of Num3 if there is no carry /  assume that num1 is bigger than num2, doesn't work on negative numbers

                k = Num3.length - 1;
                for (int a = 0; a < Num3.length; a++) {
                    if (a == 0) {
                        if (Num3.valueArray[a] == 0) {
                            zerocount++;
                        }
                    } else {
                        if (Num3.valueArray[a - 1] == 0) { //if previous index had a value of zero...
                            if (Num3.valueArray[a] == 0) {
                                zerocount++; //...then add unto zerocount
                            }
                        }
                    }
                }
                newlen = Num3.length - zerocount; //tells actual length of the number

                //need to resize the array
                Num4.valueArray = new int[newlen];
                for (int j = newlen - 1; j >= 0; j--) {
                    Num4.valueArray[j] = Num3.valueArray[k]; //copy values into a new bigPosInteger object array, excludes zeros in the beginning
                    k--;
                }
                delete[] Num3.valueArray;
                Num3.valueArray = new int[newlen];
                Num3.length = newlen;
                for (int j = newlen - 1; j >= 0; j--) {
                    Num3.valueArray[j] = Num4.valueArray[j]; //copy values into a new bigPosInteger object array, exclude zero in the beginning
                }
                //Num3.valueArray = Num4.valueArray;
                delete[] Num4.valueArray;

                std::cout << "Num3 array" << i << " : " << Num3.valueArray[i];
                std::cout << "num2 array" << i << " : " << num2.valueArray[i];
            }
        } else {
            int w = Num3.valueArray[0];
            int y = num2.valueArray[0];
            if ((Num3.length) <= num2.length) { //check which array is longer
                if (Num3.valueArray[0] < num2.valueArray[0]) { //check which has the larger digit
                    check = 'b'; //exit loop and return the current value of Num3
                } else {
                    Num3 = Num3 - num2;

                    zerocount = 0;
                    k = Num3.length - 1;
                    for (int a = 0; a < Num3.length; a++) {
                        if (a == 0) {
                            if (Num3.valueArray[a] == 0) {
                                zerocount++;
                            }
                        } else {
                            if (Num3.valueArray[a - 1] == 0) {
                                if (Num3.valueArray[a] == 0) {
                                    zerocount++;
                                }
                            }
                        }
                    }
                    newlen = Num3.length - zerocount; //tells actual length of the number

                    //need to resize the array
                    Num4.valueArray = new int[newlen];
                    for (int j = newlen - 1; j >= 0; j--) {
                        Num4.valueArray[j] = Num3.valueArray[k]; //copy values into a new bigPosInteger object array, excludes zeros in the beginning
                        k--;
                    }
                    delete[] Num3.valueArray;
                    Num3.valueArray = new int[newlen];
                    Num3.length = newlen;
                    for (int j = newlen - 1; j >= 0; j--) {
                        Num3.valueArray[j] = Num4.valueArray[j]; //copy values into a new bigPosInteger object array, exclude zero in the beginning
                    }
                    //Num3.valueArray = Num4.valueArray;
                    delete[] Num4.valueArray;
                }
            } else {
                Num3 = Num3 - num2;

                zerocount = 0;
                k = Num3.length - 1;
                for (int a = 0; a < Num3.length; a++) {
                    if (a == 0) {
                        if (Num3.valueArray[a] == 0) {
                            zerocount++;
                        }
                    } else {
                        if (Num3.valueArray[a - 1] == 0) {
                            if (Num3.valueArray[a] == 0) {
                                zerocount++;
                            }
                        }
                    }
                }
                newlen = Num3.length - zerocount; //tells actual length of the number

                //need to resize the array
                Num4.valueArray = new int[newlen];
                for (int j = newlen - 1; j >= 0; j--) {
                    Num4.valueArray[j] = Num3.valueArray[k]; //copy values into a new bigPosInteger object array, excludes zeros in the beginning
                    k--;
                }
                delete[] Num3.valueArray;
                Num3.valueArray = new int[newlen];
                Num3.length = newlen;
                for (int j = newlen - 1; j >= 0; j--) {
                    Num3.valueArray[j] = Num4.valueArray[j]; //copy values into a new bigPosInteger object array, exclude zero in the beginning
                }
                //Num3.valueArray = Num4.valueArray;
                delete[] Num4.valueArray;

                std::cout << "Num3 array" << i << " : " << Num3.valueArray[i];
                std::cout << "num2 array" << i << " : " << num2.valueArray[i];
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
