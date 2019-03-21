#include<bits/stdc++.h>
#include<string>

using namespace std;

char stac[20],val1[20],sym[20];	//stacks for sdt
int val[20];
int top1=-1,top2=-1,top3=-1;	//top of each stack
string input;

//prints syntax rules stack
void print_stac(){
	for(int i=0;i<=top1;i++){
		cout<<stac[i];
	}
}

//prints value stack
void print_val(){
	for(int i=0;i<=top2;i++){
		cout<<val[i]<<" ";
	}
}

//prints symbol stack
void print_val1(){
	for(int i=0;i<=top2;i++){
		cout<<val1[i];
	}
}

void sdt(){
	stac[0] = '$';top1=0;
	input[input.length()]='$';
	cout<<"Stack\tValue\n---------------\n";
	for(int i=0;i<input.length();i++){
		//push d to symbol stack and its value to value stack
		if(input[i]>='0' && input[i]<='9'){
			stac[top1++] = 'd';
			val[top2++] = int(input[i])-48;
			print_stac();	cout<<"\t";		
			print_val();	cout<<endl;
		}
		else{
			//only push the non-terminal to parse stack
			stac[top1++] = input[i];
			print_stac();	cout<<"\t";
			print_val();	cout<<endl;
		}
		
		//if I -> I digit reduction is encountered
		if(stac[top1]=='d' && stac[top1-1]=='I'){
			stac[top1--] = 'I';
			val[top2-1] = 10*val[top2-1] + val[top2];
			top2-=1;
			print_stac();	cout<<"\t";
			print_val();	cout<<endl;
		}
		
		if(stac[top1]=='d'){
			stac[top1]='I';
			
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		
		if(stac[top1]=='I' && (input[i+1]<'0' || input[i+1]>'9')){
			stac[top1] = 'E';
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		
		if(stac[top1]==')' && stac[top1-1]=='E' && stac[top1-2]=='('){
			stac[top1-2]='E';
			top1-=2;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		
		//Reduction using E->E+E
		if(stac[top1]=='E' && stac[top1-1]=='+' && stac[top1-2]=='E'){
			stac[top1-2]='E';
			top1-=2;
			val[top2-1] = val[top2]+val[top2-1];
			top2-=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		
		//Reduction using E->E*E
		if(stac[top1]=='E' && stac[top1-1]=='*' && stac[top1-2]=='E'){
			stac[top1-2]='E';
			top1-=2;
			val[top2-1] = val[top2]*val[top2-1];
			top2-=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		
		//Reduction using S->E$
		if(stac[top1]=='$' && stac[top1-1]=='E'){
			stac[top1-1]='S';
			top1-=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
	}
	cout<<val[top2]<<endl;
}

void convert(){
	stac[0] = '$';top1=0;top2=-1;
	input[input.length()]='$';
	cout<<"Stack\tPost-fix\n---------------\n";
	for(int i=0;i<input.length();i++){
		if(input[i]>='0' && input[i]<='9'){
			stac[top1+1] = 'd';
			top1+=1;
			val1[top2+1] = input[i];
			top2+=1;
			print_stac();
			cout<<"\t";
			print_val1();
			cout<<endl;
		}
		else{
			stac[top1+1] = input[i];
			if(input[i]=='*' || input[i]=='+'){
				sym[top3+1]=input[i];
				top3+=1;
			}
			top1+=1;
			print_stac();
			cout<<"\t";
			print_val1();
			cout<<endl;
		}
		if(stac[top1]=='d' && stac[top1-1]=='I'){
			stac[top1-1] = 'I';
			top1-=1;
			print_stac();
			cout<<"\t";
			print_val1();
			cout<<endl;
		}
		if(stac[top1]=='d'){
			stac[top1]='I';
			
			print_stac();
			cout<<"\t";
			print_val1();
			cout<<endl;
		}
		if(stac[top1]=='I' && (input[i+1]<'0' || input[i+1]>'9')){
			stac[top1] = 'E';
			print_stac();
			cout<<"\t";
			print_val1();
			cout<<endl;
		}
		if(stac[top1]==')' && stac[top1-1]=='E' && stac[top1-2]=='('){
			stac[top1-2]='E';
			top1-=2;
			val1[top2+1]=sym[top3];
			top3-=1;top2+=1;
			print_stac();
			cout<<"\t";
			print_val1();
			cout<<endl;
		}
		if(stac[top1]=='E' && stac[top1-1]=='+' && stac[top1-2]=='E'){
			stac[top1-2]='E';
			top1-=2;
			// val1[top2+1] = '+';
			// top2+=1;
			print_stac();
			cout<<"\t";
			print_val1();
			cout<<endl;
		}
		if(stac[top1]=='E' && stac[top1-1]=='*' && stac[top1-2]=='E'){
			stac[top1-2]='E';
			top1-=2;
			// val1[top2+1] = '*';
			// top2+=1;
			print_stac();
			cout<<"\t";
			print_val1();
			cout<<endl;
		}
		if(stac[top1]=='$' && stac[top1-1]=='E'){
			stac[top1-1]='S';
			top1-=1;
			print_stac();
			cout<<"\t";
			print_val1();
			cout<<endl;
		}
		
	}	
	print_stac();
	cout<<"\t";
	print_val1();
	while(top3!=-1){
		cout<<sym[top3];
		top3-=1;
	}
	cout<<endl;

}

void threeAddressCode(){
	stac[0] = '$';top1=0;top2=-1;
	int x=1;
	vector<vector<string> > v;
	input[input.length()]='$';
	cout<<"Stack\tPlace\tGenerated Code\n---------------------------------\n";
	for(int i=0;i<input.length();i++){
		if(input[i]>='0' && input[i]<='9'){
			stac[top1+1] = 'd';
			top1+=1;
			val[top2+1] = int(input[i])-48;
			top2+=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		else{
			stac[top1+1] = input[i];
			top1+=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='d' && stac[top1-1]=='I'){
			stac[top1-1] = 'I';
			top1-=1;
			val[top2-1] = 10*val[top2-1] + val[top2];
			top2-=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='d'){
			stac[top1]='I';
			
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='I' && (input[i+1]<'0' || input[i+1]>'9')){
			stac[top1] = 'E';
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]==')' && stac[top1-1]=='E' && stac[top1-2]=='('){
			stac[top1-2]='E';
			top1-=2;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='E' && stac[top1-1]=='+' && stac[top1-2]=='E'){
			print_stac();
			cout<<"\t";
			print_val();
			if(x>1)
				cout<<"\tT"<<x<<" := "<<val[top2-1]<<" + T"<<x-1;
			else
				cout<<"\tT"<<x<<" := "<<val[top2-1]<<" + "<<val[top2];
			x++;
			cout<<endl;
			stac[top1-2]='E';
			top1-=2;
			val[top2-1] = val[top2]+val[top2-1];
			top2-=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='E' && stac[top1-1]=='*' && stac[top1-2]=='E'){
			print_stac();
			cout<<"\t";
			print_val();
			if(x>1)
				cout<<"\tT"<<x<<" := "<<val[top2-1]<<" * T"<<x-1;
			else
				cout<<"\tT"<<x<<" := "<<val[top2-1]<<" * "<<val[top2];
			x++;
			cout<<endl;
			stac[top1-2]='E';
			top1-=2;
			val[top2-1] = val[top2]*val[top2-1];
			top2-=1;
			print_stac();
			cout<<"\t";
			print_val();
			
			cout<<endl;
		}
		if(stac[top1]=='$' && stac[top1-1]=='E'){
			stac[top1-1]='S';
			top1-=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}	
	}
}

int main(){
	cout<<"Enter the input e.g 2+3*(4+5)  : ";
	cin>>input;
	cout<<"\n\nSyntax Directed Translation";
	cout<<"\n================================\n\n";
	sdt();
	cout<<"\n\n\nInfix to postfix";
	cout<<"\n================================\n\n";
	convert();
	cout<<"\n\n\nThree Address Code";
	cout<<"\n================================\n\n";
	threeAddressCode();
	return 0;
}
