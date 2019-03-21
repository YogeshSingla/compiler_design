/* basic token identifier for a simple compiler */
#include<stdio.h>
#include<stdbool.h>	//for bool return type

//#define MAX_LENGTH 100
#define INPUT_SYMBOLS_SET_SIZE 68	//ascii values are from 0 to 127.
#define DFA_STATES_SIZE 500	//parser dfa contains states approx max(keywordlength)*number_of_states_connected_to_start_state

//char input_string[MAX_LENGTH];
char ch;
int ch_val;
//each row value is a current state
//each column value is a possible input symbol
bool DFA[DFA_STATES_SIZE][INPUT_SYMBOLS_SET_SIZE];	//declaring the dfa matrix
int i;	//generic loop variable

bool make_connections_in_dfa();	//to fill the dfa matrix 
int char_to_value(char current_input_character);	//reduce ascii values of characters to our dfa columns numbers
bool parse(char ch);	//to identify tokens based on dfa matrix

int main(){

	//input the expression
	ch=getchar();
	while((ch!=EOF)){

		//do something with input character
		ch_val=(int)ch;
		printf("%c %d %d\n",ch,ch_val,char_to_value(ch));
		
		ch=getchar();
	}
	return 0;
}

int char_to_value(char ch){
	/* take accepted characters from the ascii table values and
	put them in a continous array of elements. So 128 characters will be reduced to 67 characters
	*/
	ch_val=(int)ch;
	int reduced_val=0;

	//a-z are from 1-26 in the DFA columns
	if((ch_val>=97)&&(ch_val<=122)){
		reduced_val=ch_val-96;
	}
	if((ch_val>=65)&&(ch_val<=90)){
		reduced_val=ch_val-37;
		//A-Z are from 28-53 in the DFA columns
	}
	if((ch_val>=48)&&(ch_val<=58)){
		reduced_val=ch_val+6;
		//0-9 are from 54-63 in the DFA columns
	}
	switch(ch_val){
		case 61 : reduced_val=ch_val+3;		break;	//= at 64
		case 33 : reduced_val=ch_val+22;	break;	//! at 65
		case 62 : reduced_val=ch_val+4;		break;	//> at 66
		case 60 : reduced_val=ch_val+7;		break;	//< at 67
		case 32 : reduced_val=ch_val+36;	break;	//space at 68
		case 95 : reduced_val=ch_val-68;	break;	//_ at 27
	}

	return reduced_val;
}

bool make_connections_in_dfa(){
	//logic for filling the dfa goes here
	/* DFA matrix contains possible input symbols from column 1 to 68.
	 * Column 0 is not used and reserved for future use.
	 * Each Row is a state in the DFA
	 * Row 0 is the start state
	 * From state #i on seeing input 'k' you reach state #j given by DFA[i][char_to_val(k)] 
	 */

	 for(i=char_to_val('0');i<char_to_val('9');i++){
	 	DFA[0][i] = 
	 }


}

bool parse(char ch){
	//logic for identifying the tokens

}