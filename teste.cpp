#include <string>
#include <iostream>

using namespace std;

int main(){
	Nullable<int> eu;
	eu = NULL;
	Nullable<string> masoq;
	masoq = NULL;
	cout << "Nulo " << eu << " " << masoq;
	return 0;
}