#include <iostream>
#include <vector>
using namespace std;
#include "../include/calcularPipeline.hpp"

void calcularPipeline(std::vector<Assembly*> &instrucoes){
	for(int i=1; i<(int)instrucoes.size(); i++){
		if(instrucoes[i]->getInst2()!=0){
			if(instrucoes[i]->getInicio() - instrucoes[instrucoes[i]->getInst2()-1]->getInicio() < 5){
				instrucoes[i]->setInicio(instrucoes[instrucoes[i]->getInst2()-1]->getFim());
			}
			else{
				instrucoes[i]->setInicio(instrucoes[i-1]->getInicio()+1);
			}
		}
		if(instrucoes[i]->getInst3()!=0){
			if(instrucoes[i]->getInicio() - instrucoes[instrucoes[i]->getInst3()-1]->getInicio() < 5){
				if(instrucoes[instrucoes[i]->getInst3()-1]->getFim() > instrucoes[i]->getInicio()){
					instrucoes[i]->setInicio(instrucoes[instrucoes[i]->getInst3()-1]->getFim());
				}
			}
		}
		if(instrucoes[i]->getInst3()==0 && instrucoes[i]->getInst2()==0){
			instrucoes[i]->setInicio(instrucoes[i-1]->getInicio()+1);
		}
	}
}