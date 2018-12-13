#include"Function.h"
fstream ifile;
fstream ofile;
int main(int argc, char *argv[]	) {
	//ifile.open(argv[1], ios::in );//¿é¤JÀÉcmd
	//ofile.open(argv[2], ios::out);//¿é¥XÀÉcmd
	ifile.open("input.kiss", ios::in);//input test
	ofile.open("output.kiss", ios::out);//output test
	string ReadFileString;
	while (getline(ifile, ReadFileString))//read a line once again
	{
		ReadFile(ReadFileString);
	}
	Equivalentstates();
		StateReduction();
#pragma region Debug
		/*for (int i = 0; i < HowmanyName; i++)
		{
			if (EquivalentMealy[i].isdelete == false) {
				cout << EquivalentMealy[i].prsentstate << " ";
			map<string, string>::iterator it;
			for (it = EquivalentMealy[i].nextstate.begin(); it != EquivalentMealy[i].nextstate.end(); it++)
			{
				cout << it->first << " " << it->second << " ";
			}
			for (it = EquivalentMealy[i].output.begin(); it != EquivalentMealy[i].output.end(); it++)
			{
				cout << it->first << " " << it->second << " ";
			}
			cout << endl;
		}
}*/
		cout << ".i " << HowManyInput << endl;
		cout << ".o " << HowmanyOutput << endl;
		cout << ".p " << OUTstate << endl;
		cout << ".s " << OUtname << endl;
		cout << ".r " << MyStart << endl;
for (int i = 0; i < HowmanyState; i++)
{
	if(MealyState[i].deleteState==false)
	cout << MealyState[i].inputTruth << " " << MealyState[i].mystatename << " " << MealyState[i].nextstatename << " " << MealyState[i].OutputTruth << endl;
}
#pragma endregion

	system("pause");
}