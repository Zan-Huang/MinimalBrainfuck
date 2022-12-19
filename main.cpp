#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <getopt.h>
#include <iomanip>
#include <stdio.h>

#include "brainfuck.h"

using namespace std;

int main(int argc, char *argv[]){
    string input_string;
    string part_string;

    while(cin >> part_string){
        input_string.append(part_string);
    }

    Interpreter one(input_string);
    one.run();
    cout << endl;
    return 0;
}