#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <string>
#define SIZE 100
using namespace std;

//const int x = 23;//For hashing
const int x = 19;

struct value{
	int cd;//For corresponding code of token
	string var;
};
struct symbol{
	int e_no;//Entry number in symbol table
	string name;
	string type;
	value *val;
	symbol **s_table_ptr;//For returning on successful insertion or lookup say like symbol *sym; s_table_ptr = &sym;
	symbol *next;//For hashing and chaining
};

symbol *s_table[SIZE] = {NULL};//Symbol table initialized

symbol *insert(symbol *s_table[SIZE], int ind, int code, string st, string t)
{
	symbol *newsym = new symbol;
	newsym->e_no = ind;
	newsym->name = t;
	if(code==6)
		newsym->type = "identifier";
	else
		newsym->type = "constant";
	newsym->val = new value;
	newsym->val->cd = code; 
	newsym->val->var = st;
	newsym->s_table_ptr = &newsym;
	newsym->next =  NULL;
	if(s_table[ind]==NULL)
	{
		s_table[ind] = newsym; 
	}
	else
	{
		symbol *s = s_table[ind];
		while(s->next!=NULL)
		{
			s = s->next;
		}
		s->next = newsym;
	}
	return newsym;
} 
symbol *look_up(symbol *s_table[SIZE], int ind, int code, string st, string t)
{
	symbol *sym = NULL;
	if(s_table[ind]!=NULL)
	{
		symbol *s = s_table[ind];
		while(s!=NULL)
		{
			if((s->name==t) && (s->val->cd==code) && (s->val->var==st))
			{
				sym = s;
				break;
			}
			s = s->next;
		}
	}
	return sym;
}
int hashVal(string s)
{
	int n = s.length();
	int h = ((int)s[n-1])%SIZE;
	for(int i=n-2; i>=0; i--)
	{
		h = ((h*x)+s[i])%SIZE;
	}
	return h;
}
int dfa_begin(string s, int n)
{
	int res = 0;
	int s_state = 0, e_state = 5, d_state = 6, c_state = 0, n_state = 0;
	cout<<"In begin DFA\n";
	cout<<"\nStart state no. = "<<s_state<<", end_state = "<<e_state<<" and, dead state = "<<d_state<<"\n";
	int i = 0, f = 0;
	for(i=0; i<n; i++)
	{
		//printf("current state: %d\n", c_state);
		if(c_state==0 && s[i]=='b')
		{
			n_state = 1;
		}
		else if(c_state==1 && s[i]=='e')
		{
			n_state = 2;
		}
		else if(c_state==2 && s[i]=='g')
		{
			n_state = 3;
		}
		else if(c_state==3 && s[i]=='i')
		{
			n_state = 4;
		}
		else if(c_state==4 && s[i]=='n')
		{
			n_state = 5;
		}
		else 
		{
			n_state = 6;
			f = 1;
			//printf("Invalid input reached dead state from state no = %d\n", c_state); 
			break;
		}
		cout<<"Reached state = "<<n_state<<" from current_state = "<<c_state<<"\n";
		c_state = n_state;
	}
	if(f==0)
	{
		res = 1;
		cout<<"Valid input keyword begin!!! with code = "<<res<<"\n";
	}
	else
	{
		cout<<"Not a valid keyword begin!!! reached dead state = "<<n_state<<" from current state = "<<c_state<<"\n";
	}
	return res;
}
int dfa_end(string s, int n)
{
	int res = 0;
	int s_state = 0, e_state = 3, d_state = 4, c_state = 0, n_state = 0;
	cout<<"In end DFA\n";
	cout<<"\nStart state no. = "<<s_state<<", end_state = "<<e_state<<" and, dead state = "<<d_state<<"\n";
	int i = 0, f = 0;
	for(i=0; i<n; i++)
	{
		//printf("current state: %d\n", c_state);
		if(c_state==0 && s[i]=='e')
		{
			n_state = 1;
		}
		else if(c_state==1 && s[i]=='n')
		{
			n_state = 2;
		}
		else if(c_state==2 && s[i]=='d')
		{
			n_state = 3;
		}
		else 
		{
			n_state = 4;
			f = 1;
			//printf("Invalid input reached dead state from state no = %d\n", c_state); 
			break;
		}
		cout<<"Reached state = "<<n_state<<" from current_state = "<<c_state<<"\n";
		c_state = n_state;
	}
	if(f==0)
	{
		res = 2;
		cout<<"Valid input keyword end!!! with code = "<<res<<"\n";
	}
	else
	{
		cout<<"Not a valid keyword end!!! reached dead state = "<<n_state<<" from current state = "<<c_state<<"\n";
	}
	return res;
}
int dfa_if(string s, int n)
{
	int res =  0;
	int s_state = 0, e_state = 2, d_state = 3, c_state = 0, n_state = 0;
	cout<<"In if DFA\n";
	cout<<"\nStart state no. = "<<s_state<<", end_state = "<<e_state<<" and, dead state = "<<d_state<<"\n";
	int i = 0, f = 0;
	for(i=0; i<n; i++)
	{
		//printf("current state: %d\n", c_state);
		if(c_state==0 && s[i]=='i')
		{
			n_state = 1;
		}
		else if(c_state==1 && s[i]=='f')
		{
			n_state = 2;
		}
		else 
		{
			n_state = 3;
			f = 1;
			//printf("Invalid input reached dead state from state no = %d\n", c_state); 
			break;
		}
		cout<<"Reached state = "<<n_state<<" from current_state = "<<c_state<<"\n";
		c_state = n_state;
	}
	if(f==0)
	{
		res = 3;
		cout<<"Valid input keyword if!!! with code = "<<res<<"\n";
	}
	else
	{
		cout<<"Not a valid keyword if!!! reached dead state = "<<n_state<<" from current state = "<<c_state<<"\n";
	}
	return res;
}
int dfa_else(string s, int n)
{
	int res = 0;
	int s_state = 0, e_state = 4, d_state = 5, c_state = 0, n_state = 0;
	cout<<"In else DFA\n";
	cout<<"\nStart state no. = "<<s_state<<", end_state = "<<e_state<<" and, dead state = "<<d_state<<"\n";
	int i = 0, f = 0;
	for(i=0; i<n; i++)
	{
		//printf("current state: %d\n", c_state);
		if(c_state==0 && s[i]=='e')
		{
			n_state = 1;
		}
		else if(c_state==1 && s[i]=='l')
		{
			n_state = 2;
		}
		else if(c_state==2 && s[i]=='s')
		{
			n_state = 3;
		}
		else if(c_state==3 && s[i]=='e')
		{
			n_state = 4;
		}
		else 
		{
			n_state = 5;
			f = 1;
			//printf("Invalid input reached dead state from state no = %d\n", c_state); 
			break;
		}
		cout<<"Reached state = "<<n_state<<" from current_state = "<<c_state<<"\n";
		c_state = n_state;
	}
	if(f==0)
	{
		res = 4;
		cout<<"Valid input keyword else!!! with code = "<<res<<"\n";
	}
	else
	{
		cout<<"Not a valid keyword else!!! reached dead state = "<<n_state<<" from current state = "<<c_state<<"\n";
	}
	return res;
}
int dfa_then(string s, int n)
{
	int res = 0;
	int s_state = 0, e_state = 4, d_state = 5, c_state = 0, n_state = 0;
	cout<<"In then DFA\n";
	cout<<"\nStart state no. = "<<s_state<<", end_state = "<<e_state<<" and, dead state = "<<d_state<<"\n";
	int i = 0, f = 0;
	for(i=0; i<n; i++)
	{
		//printf("current state: %d\n", c_state);
		if(c_state==0 && s[i]=='t')
		{
			n_state = 1;
		}
		else if(c_state==1 && s[i]=='h')
		{
			n_state = 2;
		}
		else if(c_state==2 && s[i]=='e')
		{
			n_state = 3;
		}
		else if(c_state==3 && s[i]=='n')
		{
			n_state = 4;
		}
		else 
		{
			n_state = 5;
			f = 1;
			//printf("Invalid input reached dead state from state no = %d\n", c_state); 
			break;
		}
		cout<<"Reached state = "<<n_state<<" from current_state = "<<c_state<<"\n";
		c_state = n_state;
	}
	if(f==0)
	{
		res = 5;
		cout<<"Valid input keyword then!!! with code = "<<res<<"\n";
	}
	else
	{
		cout<<"Not a valid keyword then!!! reached dead state = "<<n_state<<" from current state = "<<c_state<<"\n";
	}
	return res;
}
int dfa_rel(string s, int n, int &val)
{
	int res = 0;
	int s_state = 0, e_state1 = 2, e_state2 = 3, d_state = 4, c_state = 0, n_state = 0;
	cout<<"In relational operator DFA\n";
	cout<<"\nStart state no. = "<<s_state<<", end_states are = "<<e_state1<<" and "<<e_state2<<", dead state = "<<d_state<<"\n";
	int i = 0, f = 0;
	for(i=0; i<n; i++)
	{
		//printf("current state: %d\n", c_state);
		if(c_state==0)
		{
			if(s[i]=='>')
			{
				n_state = 3;
				val = 6;	
			}
			else if(s[i]=='<')
			{
				n_state = 3;
				val = 5;
			}
			else if(s[i]=='!')
			{
				n_state = 3;
				val = 2;
			}
			else 
			{
				if(s[i]=='=')
				{
					n_state = 1;
					val = 1;
				}
				else
				{
					n_state = 4;
					f = 1;
					val = -1;
					break;
				}
			}
		}
		else if(c_state==1)
		{
			if(s[i]=='=')
				n_state = 2;
			else 
			{
				n_state = 4;
				f = 1;
				val = -1;
				break;
			}
		}
		else if(c_state==2)
		{
			if(i<n)//Means there are still other symbols of string left to be processed
			{
				n_state = 4;
				f = 1;
				val = -1;
				break;	
			}
			else 
			{
				n_state = 2;
				break;
			}
		}
		else if(c_state==3)
		{
			if(s[i]=='=')//Means there are still other symbols of string left to be processed
			{
				n_state = 2;
				if(val==6)
				{
					val = 3;
				}
				else if(val==5)
				{
					val = 4;
				}
			}
			else 
			{
				n_state = 4;
				f = 1;
				val = -1;
				break;
			}
		}
		else 
		{
			n_state = 4;
			f = 1;
			val = -1;
			//printf("Invalid input reached dead state from state no = %d\n", c_state); 
			break;
		}
		cout<<"Reached state = "<<n_state<<" from current_state = "<<c_state<<"\n";
		c_state = n_state;
	}
	if(f==0)
	{
		res = 8;
		cout<<"Valid input relational operator!!! with code = "<<res<<" and value = "<<val<<"\n";
	}
	else
	{
		cout<<"Not a valid relational operator!!! reached dead state = "<<n_state<<" from current state = "<<c_state<<"\n";
	}
	return res;
}
int dfa_iden(string s, int n)
{
	int res = 0;
	vector<char > st;
	//For int
	int s_state = 0, e_state = 5, d_state = 7, c_state = 0, n_state = 0, str = 0;//str used to count no of * symbols 
	cout<<"In int DFA\n";
	cout<<"\nStart state no. = "<<s_state<<", end_state = "<<e_state<<" and, dead state = "<<d_state<<"\n";
	int i = 0, f = 0;
	for(i=0; i<n; i++)
	{
		//printf("current state: %d\n", c_state);
		if(c_state==0)
		{
			if(s[i]=='i')
				n_state = 1;
			else
			{
				n_state = 7;
				f = 1;
				break;
			}
		}
		else if(c_state==1)
		{
			if(s[i]=='n')
				n_state = 2;
			else
			{
				n_state = 7;
				f = 1;
				break;
			}
		}
		else if(c_state==2)
		{
			if(s[i]=='t')
				n_state = 3;
			else
			{
				n_state = 7;
				f = 1;
				break;
			}
		}
		else if(c_state==3)
		{
			if(s[i]==' ')
				n_state = 4;
			else if(s[i]=='*')
			{
				str++;
				//st.push_back(s[i]);
				n_state = 6;
			}
			else
			{
				n_state = 7;
				f = 1;
				break;
			}
		}
		else if(c_state==4)
		{
			if(s[i]==' ')
			{
				n_state = 4;
			}
			else if(s[i]=='*')
			{
				str++;
				//st.push_back(s[i]);
				n_state = 6;
			}
			else if((((int)(s[i])>=65) && ((int)(s[i])<=90)) || (((int)(s[i])>=97) && ((int)(s[i])<=122)) || (s[i]=='_'))
			{
				st.push_back(s[i]);
				n_state = 5;//Reached end state
			}
			else
			{
				n_state = 7;
				f = 1;
				break;
			}
		}
		else if(c_state==5)
		{
			if((((int)(s[i])>=65) && ((int)(s[i])<=90)) || (((int)(s[i])>=97) && ((int)(s[i])<=122)) || (s[i]=='_') || (((int)(s[i])>=48) && ((int)(s[i])<=57)))
			{
				st.push_back(s[i]);
				n_state = 5;//Reached end state
			}
			else
			{
				n_state =7;
				f = 1;
				break;
			}
		}
		else if(c_state==6)
		{
			if(s[i]==' ')
			{
				n_state = 4;
			}
			else if(s[i]=='*')
			{
				str++;
				//st.push_back(s[i]);
				n_state = 6;
			}
			else if((((int)(s[i])>=65) && ((int)(s[i])<=90)) || (((int)(s[i])>=97) && ((int)(s[i])<=122)) || (s[i]=='_'))
			{
				st.push_back(s[i]);
				n_state = 5;//Reached end state
			}
			else
			{
				n_state = 7;
				f = 1;
				break;
			}
		}
		cout<<"Reached state = "<<n_state<<" from current_state = "<<c_state<<"\n";
		c_state = n_state;
	}
	string id1 = "int";
	while(str--)
	{
		id1 += "*";	
	}
	if(f==0)
	{
		if(st.size()==0)//To check if there is any null symbol after int or int * or int***** etc which is invalid input/syntax
		{
			n_state = 7;//Reached dead state
			cout<<"Not a valid identifier of type "<<id1<<". Missing variable name!!! reached dead state = "<<n_state<<" from current state = "<<c_state<<"\n";
			res = -1;
		}
		else
		{
			/*int n = st.size();
			char vr[n+1];
			for(int i=0; i<n; i++)
			{
				vr[i] = st[i]; 
			}
			vr[n] = '\0';*/
			//int sz = n+1;
			string vr(st.begin(), st.end());
			if((vr!="begin")&&(vr!="end")&&(vr!="if")&&(vr!="else")&&(vr!="then")&&((vr!="int") && (vr!="char"))&&((vr!="0")&&(vr!="1")&&(vr!="2")&&(vr!="3")&&(vr!="4")&&(vr!="5")&&(vr!="6")&&(vr!="7")&&(vr!="8")&&(vr!="9"))&&((vr!="==")&&(vr!="!=")&&(vr!="<=")&&(vr!=">=")&&(vr!="<")&&(vr!=">")))
			{
				res = 6;
				cout<<"Valid input identifier "<<vr<<" of type "<<id1<<"!!! with code = "<<res<<"\n";
				//cout<<vr<<"\n";
				//cout<<id1<<"\n";  
				int hint = hashVal(id1);
				int h = (hint+hashVal(vr))%SIZE;
				symbol *sym = look_up(s_table, h, res, vr, id1);
				if(sym!=NULL)
				{
					cout<<"Variable "<<vr<<" already declared at location ("<<"symbol_table_enty_no = "<<sym->e_no<<", symbol_table_ptr_addr = "<<sym->s_table_ptr<<") with name = "<<sym->name<<", type = "<<sym->type<<", and value (code = "<<sym->val->cd<<", variable name = "<<sym->val->var<<")\n";
				}
				else
				{
					//cout<<"Not found\n";
					symbol *ins = insert(s_table, h, res, vr, id1);//res = code for int token here
					cout<<"Variable "<<vr<<" inserted at location ("<<"symbol_table_enty_no = "<<ins->e_no<<", symbol_table_ptr_addr = "<<ins->s_table_ptr<<") with name = "<<ins->name<<", type = "<<ins->type<<", and value (code = "<<ins->val->cd<<", variable name = "<<ins->val->var<<")\n";
				}
			}
			else
			{
				cout<<"Invalid input identifier "<<vr<<" of type "<<id1<<" as "<<vr<<" is a reserved keyword\n";
				res = -1;
			}	
		}
	}
	else
	{
		cout<<"Not a valid identifier of type "<<id1<<"!!! reached dead state = "<<n_state<<" from current state = "<<c_state<<"\n";
		
		/*----------------------- FOR CHAR -------------------------------*/
		//For char
		st.clear();
		s_state = 0, e_state = 6, d_state = 8, c_state = 0, n_state = 0;
		cout<<"In char DFA\n";
		cout<<"\nStart state no. = "<<s_state<<", end_state = "<<e_state<<" and, dead state = "<<d_state<<"\n";
		i = 0, f = 0, str = 0, id1 = "char";
		for(i=0; i<n; i++)
		{
			//printf("current state: %d\n", c_state);
			if(c_state==0)
			{
				if(s[i]=='c')
					n_state = 1;
				else
				{
					n_state = 8;
					f = 1;
					break;
				}
			}
			else if(c_state==1)
			{
				if(s[i]=='h')
					n_state = 2;
				else
				{
					n_state = 8;
					f = 1;
					break;
				}		
			}
			else if(c_state==2)
			{
				if(s[i]=='a')
					n_state = 3;
				else
				{
					n_state = 8;
					f = 1;
					break;
				}
			}	
			else if(c_state==3)
			{
				if(s[i]=='r')
					n_state = 4;
				else
				{	
					n_state = 8;
					f = 1;
					break;
				}
			}
			else if(c_state==4)
			{
				if(s[i]==' ')
					n_state = 5;
				else if(s[i]=='*')
				{
					str++;
					n_state = 7;
				}
				else
				{
					n_state = 8;
					f = 1;
					break;
				}
			}		
			else if(c_state==5)
			{
				if(s[i]==' ')
				{
					n_state = 5;
				}
				else if(s[i]=='*')
				{
					str++;
					n_state = 7;
				}
				else if((((int)(s[i])>=65) && ((int)(s[i])<=90)) || (((int)(s[i])>=97) && ((int)(s[i])<=122)) || (s[i]=='_'))
				{
						st.push_back(s[i]);
						n_state = 6;//Reached end state
				}
				else
				{
					n_state = 8;
					f = 1;
					break;
				}
			}
			else if(c_state==6)
			{
				if((((int)(s[i])>=65) && ((int)(s[i])<=90)) || (((int)(s[i])>=97) && ((int)(s[i])<=122)) || (s[i]=='_') || (((int)(s[i])>=48) && ((int)(s[i])<=57)))
				{
					st.push_back(s[i]);
					n_state = 6;//Reached end state
				}
				else
				{
					n_state =8;
					f = 1;
					break;
				}
			}
			else if(c_state==7)
			{
				if(s[i]==' ')
				{
					n_state = 5;
				}
				else if(s[i]=='*')
				{
					str++;
					n_state = 7;
				}
				else if((((int)(s[i])>=65) && ((int)(s[i])<=90)) || (((int)(s[i])>=97) && ((int)(s[i])<=122)) || (s[i]=='_'))
				{		
					st.push_back(s[i]);
					n_state = 6;//Reached end state
				}
				else
				{
					n_state = 8;
					f = 1;
					break;
				}
			}	
			cout<<"Reached state = "<<n_state<<" from current_state = "<<c_state<<"\n";
			c_state = n_state;
		}
		while(str--)
		{
			id1 += "*";	
		}
		if(f==0)
		{
			if(st.size()==0)
			{
				n_state = 8;
				cout<<"Not a valid identifier of type "<<id1<<". Missing variable name!!! reached dead state = "<<n_state<<" from current state = "<<c_state<<"\n";
				res = -1;	
			}
			else
			{
				string vr(st.begin(), st.end());
				if((vr!="begin")&&(vr!="end")&&(vr!="if")&&(vr!="else")&&(vr!="then")&&((vr!="int") && (vr!="char"))&&((vr!="0")&&(vr!="1")&&(vr!="2")&&(vr!="3")&&(vr!="4")&&(vr!="5")&&(vr!="6")&&(vr!="7")&&(vr!="8")&&(vr!="9"))&&((vr!="==")&&(vr!="!=")&&(vr!="<=")&&(vr!=">=")&&(vr!="<")&&(vr!=">")))
				{
					res = 6;
					cout<<"Valid input identifier "<<vr<<" of type "<<id1<<"!!! with code = "<<res<<"\n";
					//cout<<vr<<"\n";
					//cout<<id1<<"\n";  
					int hchar = hashVal(id1);
					int h = (hchar+hashVal(vr))%SIZE;
					symbol *sym = look_up(s_table, h, res, vr, id1);
					if(sym!=NULL)
					{
						cout<<"Variable "<<vr<<" already declared at location ("<<"symbol_table_enty_no = "<<sym->e_no<<", symbol_table_ptr_addr = "<<sym->s_table_ptr<<") with name = "<<sym->name<<", type = "<<sym->type<<", and value (code = "<<sym->val->cd<<", variable name = "<<sym->val->var<<")\n";
					}
					else
					{
						//cout<<"Not found\n";
						symbol *ins = insert(s_table, h, res, vr, id1);//res = code for int token here
						cout<<"Variable "<<vr<<" inserted at location ("<<"symbol_table_enty_no = "<<ins->e_no<<", symbol_table_ptr_addr = "<<ins->s_table_ptr<<") with name = "<<ins->name<<", type = "<<ins->type<<", and value (code = "<<ins->val->cd<<", variable name = "<<ins->val->var<<")\n";
					}
				}	
				else
				{
					cout<<"Invalid input identifier "<<vr<<" of type "<<id1<<" as "<<vr<<" is a reserved keyword\n";
					res = -1;
				}		
			}
		}
		else
		{
			cout<<"Not a valid identifier of type "<<id1<<"!!! reached dead state = "<<n_state<<" from current state = "<<c_state<<"\n";
		}	
	}
	return res;
}
int dfa_cons(string s, int n)
{
	int res = 0;
	int s_state = 0, e_state = 1, d_state = 2, c_state = 0, n_state = 0;
	cout<<"In constant DFA\n";
	cout<<"\nStart state no. = "<<s_state<<", end_state = "<<e_state<<" and, dead state = "<<d_state<<"\n";
	int i = 0, f = 0;
	string id2 = "number";
	vector<char > st;
	for(i=0; i<n; i++)
	{
		//printf("current state: %d\n", c_state);
		if(c_state==0)
		{
			if(((int)(s[i])>=48) && ((int)(s[i])<=57))
			{
				st.push_back(s[i]);
				n_state = 1;
			}
			else 
			{
				n_state = 2;
				f = 1;
				break;
			}
		}
		else if(c_state==1)
		{
			if(((int)(s[i])>=48) && ((int)(s[i])<=57))
			{
				st.push_back(s[i]);
				n_state = 1;	
			}
			else 
			{
				n_state = 2;
				f = 1;
				break;
			}
		}
		else 
		{
			n_state = 2;
			f = 1;
			//printf("Invalid input reached dead state from state no = %d\n", c_state); 
			break;
		}
		cout<<"Reached state = "<<n_state<<" from current_state = "<<c_state<<"\n";
		c_state = n_state;
	}
	if(f==0)
	{
		if(st.size()==0)
		{
			n_state = 2;
			cout<<"Not a valid identifier of type "<<id2<<". Missing number!!! reached dead state = "<<n_state<<" from current state = "<<c_state<<"\n";
			res = -1;
		}
		else
		{
			res = 7;
			cout<<"Valid input constant of type "<<id2<<"!!! with code = "<<res<<"\n";
			int hcons = hashVal(id2);
			int h = (hcons+hashVal(s))%SIZE;
			symbol *sym = look_up(s_table, h, res, s, id2);
			if(sym!=NULL)
			{
				cout<<"Constant "<<s<<" already declared at location ("<<"symbol_table_enty_no = "<<sym->e_no<<", symbol_table_ptr_addr = "<<sym->s_table_ptr<<") with name = "<<sym->name<<", type = "<<sym->type<<", and value (code = "<<sym->val->cd<<", variable name = "<<sym->val->var<<")\n";
			}
			else
			{
				//cout<<"Not found\n";
				symbol *ins = insert(s_table, h, res, s, id2);//res = code for int token here
				cout<<"Constant "<<s<<" inserted at location ("<<"symbol_table_enty_no = "<<ins->e_no<<", symbol_table_ptr_addr = "<<ins->s_table_ptr<<") with name = "<<ins->name<<", type = "<<ins->type<<", and value (code = "<<ins->val->cd<<", variable name = "<<ins->val->var<<")\n";
			}	
		}
	}
	else
	{
		cout<<"Not a valid constant of type "<<id2<<"!!! reached dead state = "<<n_state<<" from current state = "<<c_state<<"\n";
	}
	return res;
}
void dfa(string s)
{
	int code = 0;//INitialized
	int val = -1;
	int n = s.length();
	if(code==0)
	{
		code = dfa_begin(s, n);
		if(code==0)
		{
			code = dfa_end(s, n);
			if(code==0)
			{
				code = dfa_if(s, n);
				if(code==0)
				{
					code = dfa_else(s, n);
					if(code==0)
					{
						code = dfa_then(s, n);
						if(code==0)
						{
							code = dfa_iden(s, n);
							if(code==0)
							{
								code = dfa_cons(s, n);
								if(code==0)
								{
									code = dfa_rel(s, n, val);
									if(code==0)
									{
										cout<<"Invalid input please enter a valid token and try again!!!\n";
									}			
								}					
							}
						}
					}				
				}
			}		
		}
	}	
}
int main()
{
	string line;
	int Q;
	cout<<"Enter number of queries: ";
	cin>>Q;
	getchar();
	while(Q--)
	{
		cout<<"Enter the tokens \n";
		getline(cin, line);
		cout<<"You entered "<<line<<"\n";
		dfa(line);		
	}
	return 0;
}
