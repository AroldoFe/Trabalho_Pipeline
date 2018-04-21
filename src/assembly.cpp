#include <string>
#include <iostream>
#include <ostream>
using namespace std;
#include "../include/assembly.hpp"

Assembly::Assembly(){

}
Assembly::Assembly(int iden, string ins, string ope1, string ope2, string ope3){
	id = iden;;
	inst = ins;
	op1 = ope1;
	op2 = ope2;
	op3 = ope3;
	dep2 = "\0";
	inst2 = 0;
	dep3 = "\0";
	inst3 = 0;
	if(ins == "j"){
		jumpInst = stoi(ope1);
	}
	else{
		jumpInst = 0;
	}
	inicio = id;
	ciclo = 1;
	fim = inicio + 4;
}
Assembly::~Assembly(){}

int Assembly::getId(){
	return id;
}
void Assembly::setId(int val){
	id = val;
}

string Assembly::getInst(){
	return inst;
}
void Assembly::setInst(string val){
	inst = val;
}

string Assembly::getOp1(){
	return op1;
}
void Assembly::setOp1(string val){
	op1 = val;
}

string Assembly::getOp2(){
	return op2;
}
void Assembly::setOp2(string val){
	op2 = val;
}

string Assembly::getOp3(){
	return op3;
}
void Assembly::setOp3(string val){
	op3 = val;
}

string Assembly::getDep2(){
	return dep2;
}
void Assembly::setDep2(string val){
	dep2 = val;
}

int Assembly::getInst2(){
	return inst2;
}
void Assembly::setInst2(int val){
	inst2 = val;
}

string Assembly::getDep3(){
	return dep3;
}
void Assembly::setDep3(string val){
	dep3 = val;
}

int Assembly::getInst3(){
	return inst3;
}
void Assembly::setInst3(int val){
	inst3 = val;
}

int Assembly::getJumpInst(){
	return jumpInst;
}
void Assembly::setJumpInst(int val){
	jumpInst = val;
}

void Assembly::copy(Assembly r){
	id = r.getId();
	inst = r.getInst();
	op1 = r.getOp1();
	op2 = r.getOp2();
	op3 = r.getOp3();
	dep2 = r.getDep2();
	inst2 = r.getInst2();
	dep3 = r.getDep3();
	inst3 = r.getInst3();
	jumpInst = r.getJumpInst();
	inicio = r.getInicio();
	ciclo = r.getCiclo();
	fim = inicio+4;
}

int Assembly::getInicio(){
	return inicio;
}
void Assembly::setInicio(int in){
	inicio = in;
	fim = in + 4;
}

int Assembly::getCiclo(){
	return ciclo;
}
void Assembly::setCiclo(int ci){
	ciclo = ci;
}

int Assembly::getFim(){
	return fim;
}

ostream& operator<< (ostream &o, Assembly const &ass){
	o << ass.inst + " " + ass.op1 + " " + ass.op2 + " " + ass.op3;
	return o;
}
