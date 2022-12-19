#ifndef BRAINFUCK_H
#define BRAINFUCK_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <stack>


class Interpreter{
    std::string input;
    std::vector<size_t> memory;
    std::vector<char> instructions;
    size_t pointer = 0;
    size_t i = 0;
public:

    Interpreter(std::string &input) : input(input) {
        std::copy(input.begin(), input.end(), std::back_inserter(instructions));
        memory.resize(30000);
    }
    void run(){
        int matching = 0;
        std::stack<size_t> loopstack;

        while(i < instructions.size()){
            char instruction = instructions[i];
            switch(instruction){
                case '>':
                    ++pointer;
                    break;
                case '<':
                    --pointer;
                    break;
                case '+':
                    memory[pointer] = memory[pointer] + 1;
                    break;
                case '-':
                    memory[pointer] = memory[pointer] - 1;
                    break;
                case '.':
                    std::cout << static_cast<char>(memory[pointer]);
                    break;
                case ',':
                    std::cin >> memory[pointer];
                    break;
                case '[':
                    if(memory[pointer] != 0){
                        loopstack.push(i);
                    } else if(memory[pointer] == 0){
                        int bracecount = 0;
                        i++;
                        bracecount++;
                        while(bracecount != 0){
                            if(instructions[i] == ']'){
                                bracecount--;
                            }
                            if(instructions[i] == '['){
                                bracecount++;
                            }
                            i++;
                        }
                        i--; //to offset the automatic i++ at the end with the while loop
                    }
                    break;

                case ']':
                    if(memory[pointer] != 0){
                        i = loopstack.top();
                    } else {
                        loopstack.pop();
                    }
                    break;
            }
            i++;
        }
    }
};

#endif /* BRAINFUCK_H */