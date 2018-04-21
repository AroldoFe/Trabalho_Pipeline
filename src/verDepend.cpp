#include <iostream>
#include <vector>
using namespace std;
#include "../include/verDepend.hpp"

void verDepend(std::vector<Assembly*> &instrucoes){
	for(int i=1; i<(int) instrucoes.size(); i++){
		for(int j=0; j<i; j++){
			// Fazendo dependendicas do ADD e SUB
			if(instrucoes[i]->getInst() == "add" || instrucoes[i]->getInst() == "sub"){ 
				// ADD SUB LW
				if(instrucoes[j]->getInst() == "add" || instrucoes[j]->getInst() == "sub" || instrucoes[j]->getInst() == "lw"){
					if(instrucoes[i]->getOp2() == instrucoes[j]->getOp1()){
						instrucoes[i]->setDep2(instrucoes[j]->getOp1());
						instrucoes[i]->setInst2(instrucoes[j]->getId());
					}
					if(instrucoes[i]->getOp3() == instrucoes[j]->getOp1()){
						instrucoes[i]->setDep3(instrucoes[j]->getOp1());
						instrucoes[i]->setInst3(instrucoes[j]->getId());
					}
				}
				// SW
				else if(instrucoes[j]->getInst() == "sw"){
					if(instrucoes[i]->getOp2() == instrucoes[j]->getOp2()){
						instrucoes[i]->setDep2(instrucoes[j]->getOp2());
						instrucoes[i]->setInst2(instrucoes[j]->getId());
					}
					if(instrucoes[i]->getOp3() == instrucoes[j]->getOp2()){
						instrucoes[i]->setDep3(instrucoes[j]->getOp2());
						instrucoes[i]->setInst3(instrucoes[j]->getId());
					}
				}
			}
			// Fazendo dependencia do BEQ e BNQ
			if(instrucoes[i]->getInst() == "beq" || instrucoes[i]->getInst() == "bnq"){
				// ADD SUB LW
				if(instrucoes[j]->getInst() == "add" || instrucoes[j]->getInst() == "sub" || instrucoes[j]->getInst() == "lw"){
					if(instrucoes[i]->getOp1() == instrucoes[j]->getOp1()){
						instrucoes[i]->setDep2(instrucoes[j]->getOp1());
						instrucoes[i]->setInst2(instrucoes[j]->getId());
					}
					if(instrucoes[i]->getOp2() == instrucoes[j]->getOp1()){
						instrucoes[i]->setDep3(instrucoes[j]->getOp1());
						instrucoes[i]->setInst3(instrucoes[j]->getId());
					}
				}
				// SW
				if(instrucoes[j]->getInst() == "sw"){
					if(instrucoes[i]->getOp1() == instrucoes[j]->getOp2()){
						instrucoes[i]->setDep2(instrucoes[j]->getOp2());
						instrucoes[i]->setInst2(instrucoes[j]->getId());
					}
					if(instrucoes[i]->getOp2() == instrucoes[j]->getOp2()){
						instrucoes[i]->setDep3(instrucoes[j]->getOp2());
						instrucoes[i]->setInst3(instrucoes[j]->getId());
					}
				}
			}
			// Fazendo dependencia do LW
			if(instrucoes[i]->getInst() == "lw"){
				// ADD SUB LW
				if(instrucoes[j]->getInst() == "add" || instrucoes[j]->getInst() == "sub" || instrucoes[j]->getInst() == "lw"){
					if(instrucoes[i]->getOp2() == instrucoes[j]->getOp1()){
						instrucoes[i]->setDep2(instrucoes[j]->getOp1());
						instrucoes[i]->setInst2(instrucoes[j]->getId());
					}
				}
				// SW
				if(instrucoes[j]->getInst() == "sw"){
					if(instrucoes[i]->getOp2() == instrucoes[j]->getOp2()){
						instrucoes[i]->setDep2(instrucoes[j]->getOp2());
						instrucoes[i]->setInst2(instrucoes[j]->getId());
					}
				}
			}
			// Fazendo dependencia do SW
			if(instrucoes[i]->getInst() == "sw"){
				// ADD SUB LW
				if(instrucoes[j]->getInst() == "add" || instrucoes[j]->getInst() == "sub" || instrucoes[j]->getInst() == "lw"){
					if(instrucoes[i]->getOp1() == instrucoes[j]->getOp1()){
						instrucoes[i]->setDep2(instrucoes[j]->getOp1());
						instrucoes[i]->setInst2(instrucoes[j]->getId());
					}
				}
				// SW
				if(instrucoes[j]->getInst() == "sw"){
					if(instrucoes[i]->getOp1() == instrucoes[j]->getOp2()){
						instrucoes[i]->setDep2(instrucoes[j]->getOp2());
						instrucoes[i]->setInst2(instrucoes[j]->getId());
					}
				}
			}
		}
	}
}