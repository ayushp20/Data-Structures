#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket tmp(next, position);
            opening_brackets_stack.push(tmp);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(opening_brackets_stack.size()==0){
                Bracket tmp(next, position);
                opening_brackets_stack.push(tmp);
                break;
            }
            else if(next==')' && opening_brackets_stack.top().type=='('){
                opening_brackets_stack.pop();
            }
            else if(next==']' && opening_brackets_stack.top().type=='['){
                opening_brackets_stack.pop();
            }
            else if(next=='}' && opening_brackets_stack.top().type=='{'){
                opening_brackets_stack.pop();
            }
            else{
                Bracket tmp(next, position);
                opening_brackets_stack.push(tmp);
                break;
            }
        }
    }

    if(opening_brackets_stack.empty()){
        cout<<"Success"<<endl;
    }
    else{
        cout<<opening_brackets_stack.top().position + 1<<endl;
    }

    // Printing answer, write your code here

    return 0;
}
