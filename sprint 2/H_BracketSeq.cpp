#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std; 

int main()
{
	ifstream f("input.txt");
    if(!f)
    {
        cout << "file not open";
        return 0;
    }

    string line;
    getline(f, line);

    stack<char> st;

    for(char ch: line)
    {
        switch(ch)
        {
        case '{': st.push('}'); break;
        case '[': st.push(']'); break;
        case '(': st.push(')'); break;
        case '}':
            if(!st.empty() && st.top() == '}')
            {
                st.pop();
                break;
            }
            else
            {
                cout << "False";
                return 0;
            }
        case ']':
            if(!st.empty() && st.top() == ']')
            {
                st.pop();
                break;
            }
            else
            {
                cout << "False";
                return 0;
            }
        case ')':
            if(!st.empty() && st.top() == ')')
            {
                st.pop();
                break;
            }
            else
            {
                cout << "False";
                return 0;
            }
        }
    }

    if(st.empty())
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
	return 0;
}