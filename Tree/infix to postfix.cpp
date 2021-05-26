//infix to postfix
#include<bits/stdc++.h>
using namespace std;

int prec(char c)
{
if(c == '^')
return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}
 

string convert(string infix) {
stack<char> s;
int l = infix.length();
string ns = "";
s.push('\0');
for(int i=0; i<l; i++) {
if(infix[i] >= 'a' && infix[i] <= 'z')
ns += infix[i];

else if(infix[i] == '(')
        s.push('(');
         
    else if(infix[i] == ')')
        {
            while(s.top() != '\0' && s.top() != '(') {
            ns += s.top();
            s.pop();
}
            if(s.top() == '(')
            s.pop();
        }
         
else {
while(s.top() != '\0' && prec(infix[i]) <= prec(s.top())) {
ns += s.top();
s.pop();
}
s.push(infix[i]);
}
}

while(s.top() != '\0') {
ns += s.top();
s.pop();
}

return ns;
}

int main () {
string infix;
cin >> infix;
string postfix;
postfix = convert(infix);
cout << postfix << endl;
}


