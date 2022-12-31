//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct et
{
	char value;
	et* left, *right;
	
	et(char x){
	    value = x;
	    left = right = NULL;
	}
};

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}

void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

et* constructTree(char []);

int main()
{   
    int t;
    cin>>t;
    while(t--){
    char postfix[25];
	cin>>postfix;
	et* r = constructTree(postfix);
	inorder(r);
	cout<<endl;
}
return 0;
}
// } Driver Code Ends


/*struct et
{
	char value;
	et* left, *right;
};*/

//function to construct expression tree
et* constructTree(char p[])
{
//code here
    stack<et*> s1;
    int i = 0;
    while(p[i] != '\0'){
        if(isOperator(p[i])){
            et *t = new et(p[i]);
            et *t1 = NULL, *t2 = NULL;
            if(!s1.empty()){
                t1 = s1.top();
                s1.pop();
            }
            if(!s1.empty()){
                t2 = s1.top();
                s1.pop();
            }
            t->left = t2;
            t->right = t1;
            s1.push(t);
        }
        else{
            et *t = new et(p[i]);
            s1.push(t);
        }
        i++;
    }
    return s1.top();
}
