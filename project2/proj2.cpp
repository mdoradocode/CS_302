

#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include "NodeStack.h"
#include "NodeStack.cpp"
#include "Node.h"
#include "Node.cpp"

using namespace std;

int evalExpression(char sign,  int op1, int op2);
bool evalPrecedence(NodeStack<char, Node<char>> opStack);
int evalOutput(string pObj);
void infixToPostfix(string obj, string &pObj);

int main(){
    string expression;
    string pExpression;
    cout << "Please input expression: ";
    getline(cin,expression);
    cout << "The expression in pre-fix notation is: " << expression << endl;
    infixToPostfix(expression, pExpression);
    cout << "The expression in post-fix is: " << pExpression << endl;
    cout << "The evaluation of the expression is: " << evalOutput(pExpression) << endl;
    return 0;
}


int evalOutput(string pObj){
    NodeStack<char, Node<char>> operatorStack;
    NodeStack<int, Node<int>> dataStack;
    int objIndex = 0;
    int op1; //Probs gonna return this one, figure it out in a minute
    int op2;
    char sign;
    while(pObj[objIndex] != '\0'){
        if(pObj[objIndex] == '-' || pObj[objIndex] == '+' || pObj[objIndex] == '*' || pObj[objIndex] == '/' || pObj[objIndex] == '^'){
            op2 = dataStack.top().getData() ;
            dataStack.pop();
            op1 = dataStack.top().getData() ; 
            dataStack.pop();
            sign = pObj[objIndex];
            dataStack.push(evalExpression(sign, op1, op2));
            objIndex++;
        }
        else{
            int pushHelper = pObj[objIndex] - 48;
            dataStack.push(pushHelper);
            objIndex++;
        }
    }
    return dataStack.top().getData();
}

void infixToPostfix(string obj, string &pObj){
    NodeStack<char, Node<char>> opStack;
    char op1, op2;
    int objIndex = 0;
    while(obj[objIndex] != '\0'){
        if(obj[objIndex] == '-' || obj[objIndex] == '+' || obj[objIndex] == '*' || obj[objIndex] == '/' || obj[objIndex] == '^'){
            opStack.push(obj[objIndex]);
            if(evalPrecedence(opStack) == false){
                op1 = opStack.top().getData();     
                opStack.pop();            
                op2 = opStack.top().getData();    
                opStack.pop();
                pObj += obj[objIndex+2];
                pObj += op1;
                pObj += op2;
                objIndex += 2;
            }
            objIndex++;
        }
        if(obj[objIndex] == '0' || obj[objIndex] == '1' || obj[objIndex] == '2'  || obj[objIndex] == '3' || obj[objIndex] == '4' || obj[objIndex] == '5' || obj[objIndex] == '6' || obj[objIndex] == '7' || obj[objIndex] == '8' || obj[objIndex] == '9'){
            pObj += obj[objIndex];
            objIndex++;
        }
        else{
            objIndex++;
        }
    }
    while(!opStack.IsEmpty()){
        op1 = opStack.top().getData();
        opStack.pop();
        pObj += op1;
    }
}


// WHEN FALSE THE TOP HAS A LOWER PRECEDENCE THAN THE BOTTOM
bool evalPrecedence(NodeStack<char, Node<char>> opStack){
    if (opStack.size() < 2){
        return true;
    }
    char top = opStack.peek();
    char second = opStack.top().getNext() ->getData();
    switch(second){
        //Lowest precednce never needs to be popped
        case '+': case '-':
        //Same for both cases
        case '*': case '/':
        if (top == '+' || top == '-'){
            return false;
        }
        case '^':
        if (top == '+' || top == '-' || top == '*' || top == '/'){
            return false;
        }
    }
    return true;
}

int evalExpression(char sign,  int op1, int op2){
        int temp;
    switch(sign){
        case '+':
        temp = op1 + op2;
        break;

        case '-':
        temp = op1 - op2;
        break;

        case '/':
        temp = op1/op2;
        break;

        case '*':
        temp = op1 * op2;
        break;

        case '^':
        temp = pow(op1,op2);
        break;
    }
    return temp;
}

/*
    ASCII of Operators
        !   ^ = 94
        !   * = 42
        !   + = 43
        !    - = 45
        !   / = 47
*/

