#include <iostream>
#include "bigPosInteger.h"
using namespace std;

int main() {


    bigPosInteger num1("11223344556677889900112233");
    bigPosInteger num2("1234567890123456789012345");
//    bigPosInteger num1("3765");
//    bigPosInteger num2("1");

    cout << "num1:" << num1 << endl;
    cout << "num2:" << num2 << endl;
    cout << num1 - num2;
//    11223344556677889900112233
//    1234567890123456789012345
//    cout << "numTest: " << numTest << endl;
//    numTest = num1 * num2;
//    cout << "numTest:"  << numTest << endl;
//    numTest = num1 - num2;
//    cout << "numTest:" << numTest << endl;
}