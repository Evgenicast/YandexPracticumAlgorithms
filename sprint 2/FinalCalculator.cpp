#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <cmath>

// ID 90693774 //

/*
-- ЗАДАЧА --
Написать код Калькулятора для арифметических выражений, которые подаются на вход в формате польской/постфиксной нотации.

-- ПРИНЦИП РАБОТЫ --

Калькулятор реализован на базе stl::stack. Для обработки строки используется стандартный набор методов парсинга библиотеки stl std::string: substr(), find(), erase(), stoi().
Также для варианта, когда встречается строка типа "-4", "-20"... т.е. содержащая информацию об отрицательном числе, используется метод isdigit().
Числовые значения кладутся на стек и извлекаются, если при обработке строки встречаются арифметические выражения (+ - * /).
Далее следует вычисление арифметического выражения и добавления результата на стек. Для такой реализации удобнее всего использовать конструкцию
switch/case. В качестве цикла используется while, так как работа методов не подразумевает последовательного итерирования и зависит от обработки строки,
а не последовательности символов и размера.

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --

При обработке строки все символы разбиваются на числовые и строковые значения. Первые по порядку кладутся на Стек. Вторые содержат арифметические выражения и 
при их выявлении извлекаются два последних числовых значения, присваиваются локальным переменным для дальнейшего вычисления значения выражения. 
Результат кладется на Стек и выводится на экран пользователя. 

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --

Добавление и извлечение элементов осуществляется за константное время О(1). Парсинг строки в лучшем случае является линейным, т.е. зависит от количества 
обрабатываемых символов n. Суммарно, с учетом парсинга, операций со Стеком (добавления/извлечения), а также использования методов stl библиотеки(время исполнения некоторых из них неизвестна), 
асимптотика алгоритма является амортизированной О(n). 

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --

Пространственная сложность (input space) завист от длины строки и равна O(n). 
*/

using namespace std;

int main(int argc, char **argv)
{
    ifstream f(argv[1]);

    if(!f)
    {
        cout << "Error ! File is not open";
        return 1;
    }

    string line;
    stack<int> expressions;

    getline(f, line);
    line += ' ';

    while (line.begin() != line.end())
    {
        
		const char * chr;
        int pos = line.find(' ');         
        string sub = line.substr(0, pos);
        chr = sub.c_str();
        line.erase(0, pos + 1);
        
		switch (*chr)
        {
            case '+':
            {
                int b = expressions.top();
                expressions.pop();
                int a = expressions.top();
                expressions.pop();
                expressions.push(a + b);
            }
            break;
            case '-':
            {
                if(chr[0] == '-' && isdigit(chr[1]))
                {
                    int dig = stoi(chr);
                    expressions.push(dig);
                    break;
                }
                int b = expressions.top();
                expressions.pop();
                int a = expressions.top();
                expressions.pop();
                expressions.push(a - b);
                break;
            }
            case '*':
            {
                int b = expressions.top();
                expressions.pop();
                int a = expressions.top();
                expressions.pop();
                expressions.push(a * b);
            }
            break;
            case '/':
            {
                int b = expressions.top();
                expressions.pop();
                int a = expressions.top();
                expressions.pop();
				int k = a % b < 0 ? -1 : 0;
				expressions.push(a / b + k);
            }
            break;
            case '\n':
                break;
			default:
			{
				int dig = stoi(sub);
				expressions.push(dig);
			}
		}
    }
	
    std::cout << expressions.top() << endl;
    return 0;
}
