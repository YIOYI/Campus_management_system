#include<iostream>
using namespace std;
#include"user_interface.h"
const int _Student_[11] = { 2021210, 2021211, 2021212, 2021213,2021214,2021215,2021216,2021217,2021218,2021219,2021220 };
int code_put()
{
    int current_number;
    bool judge = false;
    cout << "ÇëÊäÈëÑ§ºÅ£º";
    cin >> current_number;
    while (judge == false)
    {
        for (int i = 0; i < 11; i++)
       {
            if (current_number == _Student_[i])
            {
                judge = true;
                return judge;
             }
        }
        cout << endl << "Ñ§ºÅ´íÎó£¬ÇëÖØĞÂÊäÈë:";
        cin >> current_number;
    }
    cout << "ÇëÊäÈëÃÜÂë:";
}