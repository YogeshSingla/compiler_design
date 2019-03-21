#include<bits/stdc++.h>

using namespace std;

struct bin_tree{
	char data;
	int label;
	struct bin_tree *right, *left;
};

typedef struct bin_tree node;

int num,top;
char last;
map<char,string> m;
int R[10];
char *op;

void getCode(){
	cout<<"Number of three address codes : ";
	cin>>num;
	cout<<"Enter the address in teh format T=A+B"<<endl;
	for(int i=0;i<num;i++){
		char s;
		cin>>s;
		string s1;
		cin>>s1;
		m.insert(pair<char,string> (s,s1));
		last = s; 
	}
}

void insertnode(node **tree,char val){
	node *temp = NULL;
	
	if(m.find(val)!=m.end()){
		string s;
		s = m[val];
		val = s[2];
	}
	
	if(!(*tree)){
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        temp->label=-1;
        *tree = temp;
    }
}

void insert(node **tree,char val)
{
    char l,r;
    int numofchildren;
	
	string s;
	s = m[val];
    numofchildren = s.length();
	
    insertnode(tree, s[2]);

  	if(numofchildren==4){
    	insertnode(&(*tree)->left,s[1]);
    	insertnode(&(*tree)->right,s[3]);
  
    	insert(&(*tree)->left,s[1]);
    	insert(&(*tree)->right,s[3]);
   	}
}

void findleafnodelabel(node *tree,int val){
	if(tree->left != NULL && tree->right !=NULL){
		findleafnodelabel(tree->left,1);
		findleafnodelabel(tree->right,0);
	}
	else{
		tree->label=val;
	}
}


void findinteriornodelabel(node *tree){
	if(tree->left->label==-1){
		findinteriornodelabel(tree->left);
	}
	else if(tree->right->label==-1){
		findinteriornodelabel(tree->right);
	}
	else{

		if(tree->left != NULL && tree->right !=NULL){
			if(tree->left->label == tree->right->label){
				tree->label=(tree->left->label)+1;
			}
			else{
				if(tree->left->label > tree->right->label){
					tree->label=tree->left->label;
				}
				else{
					tree->label=tree->right->label;
				}
			}
		}
	}
}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%c with Label %d\n",tree->data,tree->label);
        print_inorder(tree->right);
    }
}

void swap(){
	int temp;
	temp=R[0];
	R[0]=R[1];
	R[1]=temp;
}

int pop(){
	int temp=R[top];
	top--;
	return temp;
}

void push(int temp){	
	top++;
	R[top]=temp;
}

char* nameofoperation(char temp){	
	switch(temp){
		case '+': return "ADD"; break;
		case '-': return "SUB"; break;
		case '*': return "MUL"; break;
		case '/': return "DIV"; break;
	}
}

void gencode(node * tree){	
	if(tree->left != NULL && tree->right != NULL){
		if(tree->left->label == 1 && tree->right->label == 0 && tree->left->left==NULL && tree->left->right==NULL && tree->right->left==NULL && tree->right->right==NULL){
			printf("MOV %c,R[%d]\n",tree->left->data,R[top]);
			op=nameofoperation(tree->data);
			printf("%s %c,R[%d]\n",op,tree->right->data,R[top]);
		}

		else if(tree->left->label >= 1 && tree->right->label == 0){
			gencode(tree->left);
			op=nameofoperation(tree->data);
			printf("%s %c,R[%d]\n",op,tree->right->data,R[top]);
		}

		else if(tree->left->label < tree->right->label){		
			int temp;
			swap();
			gencode(tree->right);
			temp=pop();
			gencode(tree->left);
			push(temp);
			swap();
			op=nameofoperation(tree->data);
			printf("%s R[%d],R[%d]\n",op,R[top-1],R[top]);
		}

		else if(tree->left->label >= tree->right->label){
			int temp;
			gencode(tree->left);
			temp=pop();
			gencode(tree->right);
			push(temp);
			op=nameofoperation(tree->data);
			printf("%s R[%d],R[%d]\n",op,R[top-1],R[top]);
		}

	}

	else if(tree->left == NULL && tree->right == NULL && tree->label == 1){
		printf("MOV %c,R[%d]\n",tree->data,R[top]);
	}

}

int main(){
	getCode();
	node *root;
    root = NULL;
    node *tmp;
    char val;
    int i,temp;
    
    insert(&root,last);
    
    findleafnodelabel(root,1);
    
    while(root->label == -1)
       findinteriornodelabel(root);
       
    top=root->label - 1;
    
    temp=top;
    for(i=0;i<=top;i++){
		R[i]=temp;
        temp--;
    }
    
    printf("\nInorder Display:\n");
    print_inorder(root);
   
   	printf("\nAssembly Code:\n");
    gencode(root);
    
	return 0;
}
