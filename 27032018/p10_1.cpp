#include<bits/stdc++.h>

using namespace std;

string output[100];
int sum=0,top=-1;
int stac[50];

void threeAddressCode(){
	int cou=1,it=1;
	for(int i=0;i<sum;i++){
		if(output[i]=="switch"){
			cout<<it<<">>\t";
			it++;
			cout<<"goto(10)"<<"\n";	
		}
		else if(output[i]=="case"){
			cout<<it<<">>\t";
			it++;
			cout<<output[i+3]<<"\n";
			stac[top+1]=it-1;
			top+=1;
			cout<<it<<">>\t";
			it++;
			cout<<"goto NEXT"<<"\n";
			cou++;	
		}
		else if(output[i]=="default"){
			cout<<it<<">>\t";
			it++;
			cout<<output[i+2]<<"\n";
			stac[top+1]=it-1;
			top+=1;
			cout<<it<<">>\t";
			it++;
			cout<<"goto NEXT"<<"\n";
			cou++;
			break;
		}
	}

	int check=0;
	for(int i=0;i<sum;i++){
		if(output[i]=="case"){
			cout<<it<<">>\t";
			it++;
			cout<<"if x="<<output[i+1]<<" goto("<<stac[check]<<")"<<"\n";
			check+=1;
		}
		else if(output[i]=="default"){
			cout<<it<<">>\t";
			it++;
			cout<<"goto("<<stac[check]<<")"<<"\n";
			check+=1;
		}
	}
}

int main(){
	ifstream file;
	file.open("switch_case.txt");
	if(file.is_open())
	{
		while(!file.eof())
		{
			file>>output[sum];
			sum++;	//sum stores the number of words in the file
			//cout<<"\t"<<sum;
		}
	}
	file.close();
	
	cout<<"\tICG for switch case \n--------------------------------------------------------\n";
	cout<<" (refer to switch_case.txt for the statements)\n\n";
	threeAddressCode();

	return 0;
}
