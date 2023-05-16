#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
void small();
void dove(int i);
int p[5]={0,1,2,3,4},c=1,i,k,l,m,pi;
char sw[5]={'=','-','+','/','*'},j[20],a[5],b[5],ch[2];
void main()
{
printf("Enter the expression:");
scanf("%s",j);
printf("\tThe Intermediate code is:\n");
small();
}
void dove(int i)
{ 
a[0]=b[0]='\0'; 
if(!isdigit(j[i+2])&&!isdigit(j[i-2]))
{
a[0]=j[i-1];
b[0]=j[i+1];
}
if(isdigit(j[i+2])){
a[0]=j[i-1];
b[0]='t';
b[1]=j[i+2];
}
if(isdigit(j[i-2]))
{
b[0]=j[i+1];
a[0]='t';
a[1]=j[i-2];
b[1]='\0'; 
}
if(isdigit(j[i+2]) &&isdigit(j[i-2]))
{ 
a[0]='t';
b[0]='t';
a[1]=j[i-2];
b[1]=j[i+2];
sprintf(ch,"%d",c);
j[i+2]=j[i-2]=ch[0]; 
}
if(j[i]=='*')
printf("\tt%d=%s*%s\n",c,a,b);
if(j[i]=='/')
printf("\tt%d=%s/%s\n",c,a,b);
if(j[i]=='+')
printf("\tt%d=%s+%s\n",c,a,b);if(j[i]=='-')
printf("\tt%d=%s-%s\n",c,a,b);
if(j[i]=='=')
printf("\t%c=t%d",j[i-1],--c);
sprintf(ch,"%d",c);
j[i]=ch[0];
c++;
small();
}
void small()
{ 
pi=0;l=0;
for(i=0;i<strlen(j);i++)
{ 
for(m=0;m<5;m++)
if(j[i]==sw[m])
if(pi<=p[m])
{
pi=p[m];
 l=1;
 k=i;
} 
}
if(l==1)
dove(k);
else
exit(0);}

//Enter the expression: a=b+c-d

/*
#include <iostream>
#include <stack>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const set<char> OPERATORS = {'+', '-', '*', '/', '(', ')'};
map<char, int> PRI = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

string infix_to_postfix(string expression) {
    string postfix;
    stack<char> s;
    for (char ch : expression) {
        if (OPERATORS.find(ch) == OPERATORS.end()) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && s.top() != '(' && PRI[ch] <= PRI[s.top()]) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

string infix_to_prefix(string expression) {
    reverse(expression.begin(), expression.end());
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(') {
            expression[i] = ')';
            i++;
        } else if (expression[i] == ')') {
            expression[i] = '(';
            i++;
        }
    }
    string prefix = infix_to_postfix(expression);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

void generate3AC(string pos) {
    stack<string> stack;
    int t = 1;
    for (char ch : pos) {
        if (OPERATORS.find(ch) == OPERATORS.end()) {
            stack.push(string(1, ch));
        } else {
            string op2 = stack.top();
            stack.pop();
            string op1 = stack.top();
            stack.pop();
            stack.push("t(" + to_string(t) + ")");
            cout << "t(" << t << ")" << " = " << op1 << " " << ch << " " << op2 << endl;
            t++;
        }
    }
}

void generateQuadruple(string pos) {
    stack<string> stack;
    vector<string> op;
    int x = 1;
    for (char ch : pos) {
        if (OPERATORS.find(ch) == OPERATORS.end()) {
            stack.push(string(1, ch));
        } else if (ch == '-') {
            string op1 = stack.top();
            stack.pop();
            stack.push("t(" + to_string(x) + ")");
            cout << setw(4) << ch << " |" << setw(5) << op1 << " | (-) | t(" << x << ")" << endl;
            x++;
            if (!stack.empty()) {
                string op2 = stack.top();
                stack.pop();
                string op1 = stack.top();
                stack.pop();
                cout << setw(4) << "+" << " |" << setw(5) << op1 << " |" << setw(5) << op2 << " | t(" << x <<
")" << endl;
stack.push("t(" + to_string(x) + ")");
x++;
}
} else {
string op2 = stack.top();
stack.pop();
string op1 = stack.top();
stack.pop();
stack.push("t(" + to_string(x) + ")");
cout << setw(4) << ch << " |" << setw(5) << op1 << " |" << setw(5) << op2 << " | t(" << x << ")" << endl;
x++;
}
}
}

void generateTriple(string pos) {
stack<string> stack;
vector<string> op;
int x = 1;
for (char ch : pos) {
if (OPERATORS.find(ch) == OPERATORS.end()) {
stack.push(string(1, ch));
} else if (ch == '-') {
string op1 = stack.top();
stack.pop();
stack.push("t(" + to_string(x) + ")");
cout << setw(4) << ch << " |" << setw(5) << op1 << " | (-)" << endl;
x++;
if (!stack.empty()) {
string op2 = stack.top();
stack.pop();
string op1 = stack.top();
stack.pop();
cout << setw(4) << "+" << " |" << setw(5) << op1 << " | (-) |" << setw(5) << op2 << endl;
stack.push("t(" + to_string(x) + ")");
x++;
}
} else {
string op2 = stack.top();
stack.pop();
string op1 = stack.top();
stack.pop();
stack.push("t(" + to_string(x) + ")");
cout << setw(4) << ch << " |" << setw(5) << op1 << " | (-) | t(" << x << ")" << endl;
x++;
}
}

}

int main() {
string expression;
cout << "INPUT THE EXPRESSION: ";
getline(cin, expression);
string pos = infix_to_postfix(expression);
string pre = infix_to_prefix(expression);
cout << "The 3 Address code for the given expression" << endl;
generate3AC(pos);
cout << "The Quadriple for the given expression" << endl;
cout << " OP | ARG 1 | ARG 2  | RESULT " << endl;
generateQuadruple(pos);
cout << "The triple for the given expression" << endl;
cout << " OP | ARG 1 | ARG 2" << endl;
generateTriple(pos);
return 0;
}
*/


/*OPERATORS = set(['+', '-', '*', '/', '(', ')'])
PRI = {'+':1, '-':1, '*':2, '/':2}

def infix_to_postfix(formula):
    stack = [] # only pop when the coming op has priority 
    output = ''
    for ch in formula:
        if ch not in OPERATORS:
            output += ch
        elif ch == '(':
            stack.append('(')
        elif ch == ')':
            while stack and stack[-1] != '(':
                output += stack.pop()
            stack.pop() # pop '('
        else:
            while stack and stack[-1] != '(' and PRI[ch] <= PRI[stack[-1]]:
                output += stack.pop()
            stack.append(ch)
    # leftover
    while stack: 
    	output += stack.pop()
    print(f'POSTFIX: {output}')
    return output

### INFIX ===> PREFIX ###
def infix_to_prefix(formula):
    op_stack = []
    exp_stack = []
    for ch in formula:
        if not ch in OPERATORS:
            exp_stack.append(ch)
        elif ch == '(':
            op_stack.append(ch)
        elif ch == ')':
            while op_stack[-1] != '(':
                op = op_stack.pop()
                a = exp_stack.pop()
                b = exp_stack.pop()
                exp_stack.append( op+b+a )
            op_stack.pop() # pop '('
        else:
            while op_stack and op_stack[-1] != '(' and PRI[ch] <= PRI[op_stack[-1]]:
                op = op_stack.pop()
                a = exp_stack.pop()
                b = exp_stack.pop()
                exp_stack.append( op+b+a )
            op_stack.append(ch)
    
    # leftover
    while op_stack:
        op = op_stack.pop()
        a = exp_stack.pop()
        b = exp_stack.pop()
        exp_stack.append( op+b+a )
    print(f'PREFIX: {exp_stack[-1]}')
    return exp_stack[-1]

### THREE ADDRESS CODE GENERATION ###
def generate3AC(pos):
	print("### THREE ADDRESS CODE GENERATION ###")
	exp_stack = []
	t = 1
	
	for i in pos:
		if i not in OPERATORS:
			exp_stack.append(i)
		else:
			print(f't{t} := {exp_stack[-2]} {i} {exp_stack[-1]}')
			exp_stack=exp_stack[:-2]
			exp_stack.append(f't{t}')
			t+=1

expres = input("INPUT THE EXPRESSION: ")
pre = infix_to_prefix(expres)
pos = infix_to_postfix(expres)
generate3AC(pos)
def Quadruple(pos):
  stack = []
  op = []
  x = 1
  for i in pos:
    if i not in OPERATORS:
       stack.append(i)
    elif i == '-':
        op1 = stack.pop()
        stack.append("t(%s)" %x)
        print("{0:^4s} | {1:^4s} | {2:^4s}|{3:4s}".format(i,op1,"(-)"," t(%s)" %x))
        x = x+1
        if stack != []:
          op2 = stack.pop()
          op1 = stack.pop()
          print("{0:^4s} | {1:^4s} | {2:^4s}|{3:4s}".format("+",op1,op2," t(%s)" %x))
          stack.append("t(%s)" %x)
          x = x+1
    elif i == '=':
      op2 = stack.pop()
      op1 = stack.pop()
      print("{0:^4s} | {1:^4s} | {2:^4s}|{3:4s}".format(i,op2,"(-)",op1))
    else:
      op1 = stack.pop()
      op2 = stack.pop()
      print("{0:^4s} | {1:^4s} | {2:^4s}|{3:4s}".format(i,op2,op1," t(%s)" %x))
      stack.append("t(%s)" %x)
      x = x+1
print("The quadruple for the expression ")
print(" OP | ARG 1 |ARG 2 |RESULT  ")
Quadruple(pos)

def Triple(pos):
        stack = []
        op = []
        x = 0
        for i in pos:
          if i not in OPERATORS:
            stack.append(i)
          elif i == '-':
            op1 = stack.pop()
            stack.append("(%s)" %x)
            print("{0:^4s} | {1:^4s} | {2:^4s}".format(i,op1,"(-)"))
            x = x+1
            if stack != []:
              op2 = stack.pop()
              op1 = stack.pop()
              print("{0:^4s} | {1:^4s} | {2:^4s}".format("+",op1,op2))
              stack.append("(%s)" %x)
              x = x+1
          elif i == '=':
            op2 = stack.pop()
            op1 = stack.pop()
            print("{0:^4s} | {1:^4s} | {2:^4s}".format(i,op1,op2))
          else:
            op1 = stack.pop()
            if stack != []:           
              op2 = stack.pop()
              print("{0:^4s} | {1:^4s} | {2:^4s}".format(i,op2,op1))
              stack.append("(%s)" %x)
              x = x+1
print("The triple for given expression")
print("  OP | ARG 1 |ARG 2  ")
Triple(pos)
*/
