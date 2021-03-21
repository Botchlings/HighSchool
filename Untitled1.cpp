#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char name[1024] = {};
	
	cin.getline(name, 1024);
	
	cout << name;
}
