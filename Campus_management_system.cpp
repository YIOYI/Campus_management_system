// Campus_management_system.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<fstream>
#include<vector>
#include"Event.h"
#include<string>

using namespace std;

int main()
{
   
      Curriculum a;
      a.createcurriculum();
      a.show();
      cout << endl << endl;
      a.sort_time();
      a.search_one_day(3);
        
    return 0;
}

