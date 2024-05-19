#include <bits/stdc++.h>
using namespace std;

class Calc
{
    float x, y;
    char op;
    friend void result(Calc);

public:
    Calc(float a, char c, float b)
    {
        x = a;
        y = b;
        op = c;
    }

    Calc(char a, float b)
    {
        op = a;
        x = b;
    }
};

void result(Calc a)
{

    if (a.op == '+')
        cout << a.x + a.y;
    if (a.op == '-')
        cout << a.x - a.y;
    if (a.op == '*')
        cout << a.x * a.y;
    if (a.op == '/')
        cout << a.x / a.y;
    if (a.op == '%')
        cout << int(a.x) % int(a.y);

    if (a.op == 's')
        cout << sin(a.x);
    if (a.op == 'c')
        cout << cos(a.x);
    if (a.op == 'C')
        cout << (float)1 / sin(a.x);
    if (a.op == 'S')
        cout << (float)1 / cos(a.x);
    if (a.op == 't')
        cout << sin(a.x) / cos(a.x);
    if (a.op == 'T')
        cout << cos(a.x) / sin(a.x);
}

int main()
{
    float a, b;
    char c;
    cout << "Enter valid Operator: " << endl;
    cout << "+ - * / % " << endl;
    cout << "s = sin" << endl
         << "c = cos" << endl
         << "S = sec" << endl
         << "C = Cosec" << endl
         << "t = tan" << endl
         << "T = cot";
    cin >> c;
    cout << "Enter First_Number and Second_Number";
    cin >> a >> b;
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
    {
        Calc user(a, c, b);
        result(user);
    }
    else
    {
        Calc user(c, a);
        result(user);
    }
    return 0;
}
