#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<map>
using namespace std;
#pragma region Define
	typedef struct 
	{
		string mystatename="";
		string nextstatename= "";
		string inputTruth="";
		string OutputTruth="";
		bool deleteState = false;
	}Mealy; //Struct of DataStructure


	struct EquivalentState
	{
		string prsentstate="";
		map<string,string>nextstate;
		map<string,string>output;
		bool isdelete = false;
	}; //Struct of DataStructure

	bool operator==(EquivalentState& _A, EquivalentState& _B) {
		map<string, string>::iterator it1;
		map<string, string>::iterator it2;
		bool isEqual = true;
		for (it1=_A.nextstate.begin(),it2=_B.nextstate.begin(); it1 != _A.nextstate.end()&&it2 != _B.nextstate.end();it1++,it2++)
		{
			if(it1->first==it2->first&&it1->second==it2->second){}
			else {
				isEqual = false;
				break;
			}
		}
		if (isEqual) {
			for (it1 = _A.output.begin(), it2 = _B.output.begin(); it1 != _A.output.end() && it2 != _B.output.end(); it1++, it2++)
			{
				if (it1->first == it2->first&&it1->second == it2->second) {}
				else {
					isEqual = false;
					break;
				}
			}
		}
		return isEqual;
	};


	int HowManyInput = 0; //.i
	int HowmanyOutput = 0;//.o
	int HowmanyState = 0;//.p
	int HowmanyName = 0;//.s
	int OUtname;//.S
	int OUTstate;//.P
	string MyStart="";//.r
	bool giveState = false;
	Mealy *MealyState;
	EquivalentState *EquivalentMealy;
	int inWhereMealyState = 0;
	int whereINEqu = 0;
#pragma endregion

	
void ReadFile(string ReadFileString) {
		
		if (giveState) {
		
			for (int i = 0; i < ReadFileString.length(); i++)
			{
				if (ReadFileString[i] != ' ') {
					//inputTruth
					for (int j = 0; j < HowManyInput; j++)
					{
						MealyState[inWhereMealyState].inputTruth += ReadFileString[i];
						i++;
					}
	
					//space
					while (ReadFileString[i]==' ')
					{
						i++;
					}
					//inputname
					while (ReadFileString[i]!=' ')
					{
						MealyState[inWhereMealyState].mystatename += ReadFileString[i];
						i++;
					}
					//space
					while (ReadFileString[i] == ' ')
					{
						i++;
					}
					//outputname
					while (ReadFileString[i] != ' ')
					{
						MealyState[inWhereMealyState].nextstatename += ReadFileString[i];
						i++;
					}
					//space
					while (ReadFileString[i] == ' ')
					{
						i++;
					}
					//outputTruth
					for (int j = 0; j < HowmanyOutput; j++)
					{
						MealyState[inWhereMealyState].OutputTruth+= ReadFileString[i];
						i++;
					}
					break;
				}
			}
			++inWhereMealyState;
			if (inWhereMealyState >= HowmanyState) giveState=false;
		}
		else {
			if (ReadFileString == ".start_kiss" || ReadFileString == ".end_kiss") return;
			//.input
			else if (ReadFileString[0] == '.'&&ReadFileString[1] == 'i') {
				for (int j = 2; j < ReadFileString.length(); j++)
				{
					if (ReadFileString[j] == ' ')continue;
					else {
						string tem;
						tem.clear();
						tem = "";
						bool in = false;
						while (ReadFileString[j] !=' '||ReadFileString[j]!=0)
						{
							
							tem += ReadFileString[j];
							j++;
							in = true;
							if (j >= ReadFileString.length())break;
						}
						if (in) {
							stringstream ss;
							ss << tem;
							ss >> HowManyInput;
							break;
						}

					}
				}
			}
			//.output
			else if (ReadFileString[0] == '.'&&ReadFileString[1] == 'o') {
				for (int j = 2; j < ReadFileString.length(); j++)
				{
					if (ReadFileString[j] == ' ')continue;
					else {
						string tem;
						tem.clear();
						tem = "";
						bool in = false;
						while (ReadFileString[j] != ' ' || ReadFileString[j] != 0)
						{
							tem += ReadFileString[j];
							j++;
							in = true;
							if (j >= ReadFileString.length())break;
						}
						if (in) {
							stringstream ss;
							ss << tem;
							ss >> HowmanyOutput;
							break;
						}

					}
				}
			}
			//.state
			else if (ReadFileString[0] == '.'&&ReadFileString[1] == 'p') {
				for (int j = 2; j < ReadFileString.length(); j++)
				{
					if (ReadFileString[j] == ' ')continue;
					else {
						string tem;
						tem.clear();
						tem = "";
						bool in = false;
						while (ReadFileString[j] != ' ' || ReadFileString[j] != 0)
						{
							tem += ReadFileString[j];
							j++;
							in = true;
							if (j >= ReadFileString.length())break;
						}
						if (in) {
							stringstream ss;
							ss << tem;
							ss >> HowmanyState;
							OUTstate = HowmanyState;
#pragma region InitialMyData
							MealyState = new Mealy[HowmanyState];
							
							
#pragma endregion
							break;
						}

					}
				}
			}
			//.name
			else if (ReadFileString[0] == '.'&&ReadFileString[1] == 's') {
				for (int j = 2; j < ReadFileString.length(); j++)
				{
					if (ReadFileString[j] == ' ')continue;
					else {
						string tem;
						tem.clear();
						tem = "";
						bool in = false;
						while (ReadFileString[j] != ' ' || ReadFileString[j] != 0)
						{
							tem += ReadFileString[j];
							j++;
							in = true;
							if (j >= ReadFileString.length())break;
						}
						if (in) {
							stringstream ss;
							ss << tem;
							ss >> HowmanyName;
							OUtname = HowmanyName;
							break;
						}

					}
				}
			}
			//.start
			else if (ReadFileString[0] == '.'&&ReadFileString[1] == 'r') {
				for (int j = 2; j < ReadFileString.length(); j++)
				{
					if (ReadFileString[j] == ' ')continue;
					else {
						string tem;
						tem.clear();
						tem = "";
						bool in = false;
						while (ReadFileString[j] != ' ')
						{
							tem += ReadFileString[j];
							j++;
							in = true;
							if (j >= ReadFileString.length())break;
						}
						if (in) {
							MyStart = tem;
							giveState = true;
							break;
						}

					}
				}
			}
			
		}
}


void Equivalentstates(){	EquivalentMealy = new EquivalentState[HowmanyName];		for (int i = 0; i < HowmanyState; i++)
	{	
		bool isnew = true;
		for (int j = 0; j <whereINEqu; j++)
		{
			if (MealyState[i].mystatename == EquivalentMealy[j].prsentstate){
				EquivalentMealy[j].nextstate.insert(pair<string, string>(MealyState[i].inputTruth, MealyState[i].nextstatename));
				EquivalentMealy[j].output.insert(pair<string, string>(MealyState[i].inputTruth, MealyState[i].OutputTruth));
				isnew = false;
				break;
			}
			
		}
		if (isnew){
			EquivalentMealy[whereINEqu].prsentstate = MealyState[i].mystatename;
			map<string, string>tem;
			tem.insert(pair<string, string>(MealyState[i].inputTruth,MealyState[i].nextstatename));
			EquivalentMealy[whereINEqu].nextstate = tem;
			tem.clear();
			tem.insert(pair<string, string>(MealyState[i].inputTruth, MealyState[i].OutputTruth));
			EquivalentMealy[whereINEqu].output = tem;
			whereINEqu++;
		}
	}}


void StateReduction() {
	map<string, string>::iterator it;
	for (int i = 0; i<HowmanyName; i++)
	{
		if (EquivalentMealy[i].isdelete == false)
		{
			for (int j = 0; j < HowmanyName; j++)
			{
				if (i != j)
					if (EquivalentMealy[j].isdelete==false) {
						if (EquivalentMealy[i] == EquivalentMealy[j]) {
							OUtname -= 1;
							EquivalentMealy[j].isdelete = true;
							for (int k = 0; k < HowmanyName; k++)
							{
								if (j == k) continue;
								for (it = EquivalentMealy[k].nextstate.begin(); it != EquivalentMealy[k].nextstate.end(); it++)
								{
									if (it->second == EquivalentMealy[j].prsentstate) {
										
										it->second = EquivalentMealy[i].prsentstate;
									}
								}

							}

							for (int l = 0; l <HowmanyState; l++)
							{
								if (MealyState[l].mystatename == EquivalentMealy[j].prsentstate) {
									OUTstate -= 1;
									MealyState[l].deleteState = true;
								}
								if (MealyState[l].nextstatename == EquivalentMealy[j].prsentstate) {
									MealyState[l].nextstatename= EquivalentMealy[i].prsentstate;
								}
							}
							if (MyStart == EquivalentMealy[j].prsentstate) {
								MyStart = EquivalentMealy[i].prsentstate;
							}
							StateReduction();
							break;
							
						}
					}
		
				
			}
		}
	}
}