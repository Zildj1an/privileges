#include<iostream>
#include<string>
using namespace std;

int privileges(const string &author, const string &group, const string &others);
void errMsg(const char &a);


int main(){
	int answer;
	string author,group,others;
	cout << "Example of use: Root = r-x" << endl;
	cout << "Author = ";
	cin >> author;
	cout << "Group = ";
	cin >> group;
	cout << "Others = ";
	cin >> others;
	answer = privileges(author,group,others);

	if(answer < 100)
		cout << "0";
	if(answer < 10)
		cout << "0";
	cout << answer << endl;
 return 0;
}


int privileges(const string &author, const string &group, const string &others){
int final = 0;
	//Root privileges
	if(author[0] == 'r'){final += 400;}
		else errMsg(author[0]);
	if(author[1] == 'w') final += 200;
		else errMsg(author[1]);
	if(author[2] == 'x') final += 100;
		else errMsg(author[2]);
	//Author privileges
	if(group[0] == 'r') final += 40;
		else errMsg(group[0]);
	if(group[1] == 'w')final += 20;
        	else errMsg(group[1]);
	if(group[2] == 'x') final += 10;
        	else errMsg(group[2]);	
	//Group privileges
	 if(others[0] == 'r') final += 4;
        	else errMsg(others[0]);
         if(others[1] == 'w') final += 2;
                else errMsg(others[0]);
         if(others[2] == 'x') final += 1;
                else errMsg(others[0]);
return final;
}


void errMsg(const char &a){
	if (a != '-' && a != 'r' && a != 'w' && a != 'x') cerr << "Wrong format with " << a  << endl; 
}
