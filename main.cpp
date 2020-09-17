#include <iostream>
#include "EBUrlParser.h"
#include <chrono>
int main() {
	   using namespace std::chrono;
	milliseconds foo (1000);
	foo*=60;
//	for(int i = 0;i<100000000;++i)
	{
		
		
		std::cout << "Hello, World!" << std::endl;
		{
			std::string s = "https://www.baidu.com:443/";
			printf("=============>url is %s\n", s.c_str());
			EBUrlParser p;
			p.Parse(s);
			p.PrintResult();
		}
		
		{
			std::string s = "https://www.baidu.com:443/my/demo";
			printf("=============>url is %s\n", s.c_str());
			EBUrlParser p;
			p.Parse(s);
			p.PrintResult();
		}
		
		{
			std::string s = "www.baidu.com:443/my/demo?aa=bb&cc=dd";
			printf("=============>url is %s\n", s.c_str());
			EBUrlParser p;
			p.Parse(s);
			p.PrintResult();
		}
		
		{
			std::string s = "https://www.baidu.com/my/demo?aa=bb&cc=dd";
			printf("=============>url is %s\n", s.c_str());
			EBUrlParser p;
			p.Parse(s);
			p.PrintResult();
		}
		
		{
			std::string s = "https://www.baidu.com:443/my/demo?aa=bb&cc=dd";
			printf("=============>url is %s\n", s.c_str());
			EBUrlParser p;
			p.Parse(s);
			p.PrintResult();
		}
	}
	
	
	return 0;
}
