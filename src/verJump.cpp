#include <iostream>
#include <vector>
using namespace std;
#include "../include/verJump.hpp"

void verJump(std::vector<Assembly*> &instrucoes){
	for(int i=0; i<(int)instrucoes.size(); i++){
		string inst = instrucoes[i]->getInst();
		if ( inst == "j"){
			for(int j=i; j<(int)instrucoes.size(); j++){
				if(instrucoes[i]->getOp1() == instrucoes[j]->getId()){
					
				}
			}
		}
		else if(inst == "beq" || inst == "bne"){

		}
	}
}