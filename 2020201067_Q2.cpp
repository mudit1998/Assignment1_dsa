#include<bits/stdc++.h>
using namespace std;
class bigint{
	

 public:
     string s;

    bool equal(string a,string b)
    {
    	if(a.length()!=b.length())return false;
    	for(int i=a.length()-1;i>=0;i--)
    	{
    		if(a[i]!=b[i])return false;
    	}
    	return true;
    }

    bool greater(string a,string b)
    {
    	if(a.length()>b.length())return true;
    	else if(a.length()<b.length())return false;
    	else
    	{
    		for(int i=0;i<a.length();i++)
    		{
    			if(a[i]>b[i])return true;
    			else if(a[i]<b[i])return false;
    		}
    	}
    	return false;
    }

    string add(string a,string b)
    {
    	string ans;
    	if(a.length()<b.length())a.swap(b);
    	ans=a;
    	char carry='0';
    	int length_diff=(int)(a.size()-b.size());
    	b.insert(0,length_diff,'0');
    	for(int i=a.length()-1;i>=0;i--)
    	{
          ans[i]=((carry-'0')+(a[i]-'0')+(b[i]-'0'))+'0';
          if(i!=0)
          {
          if(ans[i]>'9')
          {
            ans[i]-=10;
            carry='1';
          }
          else carry='0';  
    	  }
        }
     if(ans[0]>'9')
     {
     	ans[0]-=10;
     	ans.insert(0,1,'1');
     }
 return ans;
    }

    string sub(string a,string b)
    {
    	string ans=a;
        int length_diff=(int)(a.size()-b.size());
        	b.insert(0,length_diff,'0');
   
        for(int i=a.length();i>=0;i--)
        {
        	if(a[i]<b[i])
        	{
        		a[i]+=10;
        		a[i-1]--;
            }
        	ans[i]=(a[i]-'0')-(b[i]-'0')+'0';

        }
        while(ans[0]=='0' && ans.length()!=1)
        {
        	ans.erase(0,1);
        }
        return ans;
    }

    string multiply(string a,string b)
    {
    	string ans="0";
        if(a.length()>b.length())a.swap(b);
        for(int i=(a.length()-1);i>=0;i--)
        {
        	string temp=b;
        	int num = a[i]-'0';
        	int carry=0;
        	for(int j=(temp.length()-1);j>=0;j--)
        	{
        		temp[j]=(temp[j]-'0')*num+carry;
        		if(temp[j]>9)
        		{
        			carry=temp[j]/10;
        			temp[j]-=(carry*10);
        	    }
        		else carry=0;
        		temp[j]+= '0';
        	}
        	if(carry>0)temp.insert(0,1,(carry+'0'));
            temp.append((a.length()-(i+1)),'0');
            ans=add(ans,temp);
        }
        while(ans[0]=='0' && ans.length()!=1)
        {
        	ans.erase(0,1);
        }
      return ans;
    }

  string longDivision(string number, int div) 
  { 
    
    string ans; 
    int i=0; 
    int temp=number[i]-'0'; 
    while(temp<div) 
        temp=temp*10+(number[++i]-'0');  
    while(number.size()>i) 
    { 
        ans +=(temp/div)+'0'; 
        temp=(temp%div)*10+number[++i]-'0'; 
    } 
    if(ans.length()==0) 
        return "0"; 
    return ans; 
} 
    
};

string factorial(int x)
{
   if(x==0)return "1";
   bigint b;
   return b.multiply(to_string(x),factorial(x-1));
}

string exponent(string s,int x)
{
	if(x==0)return "1";
	if(s=="0")return "0";
	string res;
	bigint b;
	if(x%2==1)
	{
		return b.multiply(s,exponent(s,x-1));
	}
	else
	{
		string s1=exponent(s,x/2);
        return b.multiply(s1,s1);
	}
}

string gcd(string a,string b)
 {
 	bigint c;
 	while(a[0]=='0' && a.length()!=1)
        {
        	a.erase(0,1);
        }
    while(b[0]=='0' && b.length()!=1)
        {
        	b.erase(0,1);
        }
      if(a=="0")return b;
      if(b=="0")return a;  
 	string ans="1";
 	//int count;
 	if(c.equal(a,b))
 	  return a;
    
    while(!c.equal(a,b))
    { if(((int)a[a.length()-1])&1 && ((int)b[b.length()-1])&1)
 	   {

 		if(c.greater(a,b))
 		{
 			a=c.sub(a,b);
 		}
 		else
 		{
 			b=c.sub(b,a);
 		}
 	   }
 	 else if(((int)a[a.length()-1])&1)
 	 {
         b=c.longDivision(b,2);
 	 }
 	 else if(((int)b[b.length()-1])&1)
 	 {
         a=c.longDivision(a,2);
 	 }
 	 else
 	 {
         ans=c.multiply(ans,"2");
         a=c.longDivision(a,2);
         b=c.longDivision(b,2);
 	 }
    }
 	return c.multiply(a,ans);
 }

int main()
{
 string s,s1;
 int x,q,z;
 cin>>q;
 while(q--)
 {
  cin>>z;
  if(z==1)
  {
   cin>>s>>x;
   cout<<exponent(s,x);
  }
  else if(z==2)
  {
   cin>>s>>s1;
   cout<<gcd(s,s1);
  }
  else if(z==3)
  {
   cin>>x;
   cout<<factorial(x);
  }
 }
}