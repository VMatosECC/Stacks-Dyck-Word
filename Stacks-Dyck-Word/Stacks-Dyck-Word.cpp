// Stacks-Dyck-Word.cpp 
/* *****************************************************************************
A Dyck word is a sequence of +1s and-1s with the property that 
the sum of any prefix of the sequence is never negative. 
For example, +1,-1,+1,-1 is a Dyck word, 
but +1,-1,-1,+1 is not a Dyck word since the prefix +1-1-1 < 0.

Write a C++ Boolean function that uses Stack push(x) and pop() operations 
to verify whether a given input is a Dyck word. Assume the input is supplied 
in a vector<int> where each entry is either 1 or -1. The function returns true 
if the input represents a Dyck word, and false otherwise.
(Walter von Dyck -  A Dyck word is a balanced string of square brackets [ and ]. 
The set of Dyck words forms the Dyck language.)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
using namespace std;

bool isDyckWord(vector<int> w);

int main()
{
    //vector<int> w({ +1,-1,+1,-1 });     //Sample 1
    vector<int> w({+1,-1,-1,+1 });       //sample 2

    if (isDyckWord(w))
        cout << " The given input is a Dyck word\n";
    else
        cout << "... The given input is not a Dyck word\n";
}

bool isDyckWord(vector<int> w)
{
    /* 
    Strategy
    Each time an input +1 is seen it is pushed on a stack. Each time a -1 appears, 
    we try to pop the stack. If this is not possible, the string is not a Dyck word.
    If there are no more input symbols and the stack has not reported impossible pops
    the string is a Dyck word.
    */
    stack<int> stk;

    for (int i = 0; i < w.size(); i++)
    {
        cout << w[i] << " ";            //show tokens as they are parsed from the vector

        if (w[i] == 1)              
        {
            stk.push(1);                // If we see a +1 push it on the stack
        }
        else
        {
            if (stk.empty())            // When we see -1 we try to pop. If the stack is empty 
                return false;           // there is no balancing token and the input is NOT a Dyck word

            stk.pop();                  // It is ok to remove
        }
    }
    return true;                        // All symbols scanned. Stack has not misbehaved. It is a Dyck word.
}