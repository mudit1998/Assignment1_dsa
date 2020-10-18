#include<iostream>
#include<string.h>
#include <cmath>
#include <iomanip> 
using namespace std;

template< class Type> 
class stack{
	struct Node{
		Type data;
		struct Node * next;
	};
 public: 
 
 struct Node * head=NULL;
 void push(Type val)
 {
    struct Node * newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=head;
    head=newNode;
   
 }
 Type pop()
 {
 	if(head==NULL)cout<<"stack is empty";
 	else
 	{
 		
 		head=head->next;
 		
 	}
 }
 Type top()
 {
 	return head->data;
 }
 bool empty()
 {
 	return head==NULL;
 }

};
bool precedence(char a,char b)
{
	if((a=='*'|| a=='/'|| a=='%') && (b=='+'|| b=='-' ))return true;
	else return false;
}
string getpostfix(string s)
{
	string postfix;
	int i;
	stack<char> stack;
	for(i=0;i<s.size();i++)
	{
		if(isdigit(s[i]) || s[i]=='.')
		{
			postfix+=s[i];
		}
		else if(s[i]=='(')
		{
			stack.push(s[i]);
		}
		else if(s[i]=='+'|| s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%')
		{
			postfix+=' ';
			if(stack.empty() || stack.top()=='(')
			{
				stack.push(s[i]);
			}
			else if(precedence(s[i],stack.top()))
			{
				stack.push(s[i]);
			}
			else
			{
				postfix+=stack.top();
				stack.pop();
				i--;
				//stack.push(s[i]);
			}
		}
		else if(s[i]==')')
		{
			while(stack.top()!='(')
			{
				postfix+=stack.top();
				stack.pop();
			}
			if(stack.top()=='(')
			{
				stack.pop();
			}
		}	
	}
		while(!stack.empty())
		{
			postfix+=stack.top();
			stack.pop();
		}
		return postfix;
}
double evaluate(string postfix)
{
  double o1,o2;
  stack<double> stack;
  int i;
  for(i=0;i<postfix.size();i++)
  {
  	if(isdigit(postfix[i]))
  	{
  		string k;
  		while(i<postfix.size() && (isdigit(postfix[i]) || postfix[i]=='.' ))
  		{
  			k+=postfix[i];
  			i++;
  		}
  		i--;
  		stack.push(stod(k));
  	}
  	else if(postfix[i]==' ')continue;
  	else if(postfix[i]=='+')
  	{
  		o1=stack.top();
  		stack.pop();
  		o2=stack.top();
  		stack.pop();
  		stack.push(o2+o1);
  	}
    else if(postfix[i]=='-')
    {
  		o1=stack.top();
  		stack.pop();
  		o2=stack.top();
  		stack.pop();
  		stack.push(o2-o1);
  	}
  	else if(postfix[i]=='*')
  	{
  		o1=stack.top();
  		stack.pop();
  		o2=stack.top();
  		stack.pop();
  		stack.push(o2*o1);
  	}
  	else if(postfix[i]=='/')
  	{
  		o1=stack.top();
  		stack.pop();
  		o2=stack.top();
  		stack.pop();
  		stack.push(o2/o1);
  	}
  	else if(postfix[i]=='%')
  	{
  		o1=stack.top();
  		stack.pop();
  		o2=stack.top();
  		stack.pop();
  		stack.push(fmod(o2,o1));
  	}

  }
  return stack.top(); 
}

int main()
{
	string s,postfix;
	cin>>s;
	postfix=getpostfix(s);
	//cout<<postfix;
   
    cout<<fixed<<setprecision(5)<<evaluate(postfix);
    return 0;
}

