#include <iostream>
#include <vector>
using namespace std;

#include <boost/algorithm/string.hpp>
using namespace boost;

#include "../include/manipularString.hpp"

void manipularString(vector<string*> &v, string inst){
	v.push_back(new string());
	vector<string> inicio;

	split(inicio, inst, is_any_of(" "));
	cout << inicio[0];
	//v[0] = inicio[0];
	/*if(inicio[0] != "j" && inicio[0] != "lw" && inicio[0] != "sw" ){
		v.push_back(new string());
		v[1] = inst[4] + inst[5] + inst[6];
		v.push_back(new string());
		v[2] = inst[8] + inst[9] + inst[10];
		v.push_back(new string());
		v[3] = inst[12] + inst[13] + inst[14];
	}*/
}