#include<iostream>
using namespace std;

template <class T>
class deque
{
public:
    int front;
    int rear;
    int size;
    int count_element;
    T *arr;

    deque()
    {
        front= -1;
        rear= 0;
        size= 1;
        count_element= 0;
        arr=new T[1];
    }

    deque(int n,T x)
    {
    front=0;
    rear=n;
    size=n;
    count_element=n;
    arr=new T[n];
    for(int i=0;i<n;i++)
        arr[i]=x;
    }

    void resize(int n)
    {
       T *temp=new T[n];
       for (int i=0;i<size;i++)
       temp[i] = arr[(front+i)%size];

       delete[] arr;
       arr = temp;
       front=0;
       rear=count_element-1;
       size=n;
    }

    void push_back(T x)
    {
        if(count_element==size)
        {
            int m=2*size;
            resize(m);
        }
        if(front==-1)
        {
            front=0;rear=0;
        }
        else if(rear==size-1)
        {  
            rear=0;
        }
        else
        {
            rear++;
        }
     arr[rear]=x;
     count_element++;

    }
    void push_front(T x)
    {
         if(count_element==size)
         {
            int m=2*size;
            resize(m);
        }
        if(front==-1)
        {
            front=0;rear=0;
        }
        else if(front==0)
        {
            front=size-1;
        }
        else
        {
            front--;
        }
      arr[front]=x;
      count_element++;  
    }
    
    void pop_back()
    {
        if(empty()=="true")
        {
            return;
        }
        if(rear==front)
        {
            front=-1;
            rear=-1;
        }
        else if(rear==0)
        {
            rear=size-1;
        }
        else
        {
            rear--;
        }
        count_element--;
    }
     void pop_front()
     {
        if(empty()=="true")
        {
            return;
        }
        if(rear==front)
        {
            front=-1;
            rear=-1;
        }
        else if(front==size-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
        count_element--;
    }

     T fronts()
     {
       if(empty()=="true") return -1 ;
       return arr[front];
     }

     T backs()
     {
       if(front==-1 || rear==-1)return -1 ;
       return arr[rear];
     }

    string empty()
    {
        if(front==-1)
            return "true";
        else return "false";
    }
     
    int sizes()
    {
      return count_element;  
    }

    void clear()
    {
        front=rear=-1;
        count_element=0;
    }

    T operator[] (int n)
    {
        if(n>count_element)return -1;
        return arr[(front+n)%size];
    }
    
    void resize(int x, T val)
    {
        if(count_element<x)
        {
           int p=count_element;
           for(int i=0;i<x-p;i++)
                 push_back(val);
        }
        else if(count_element>x)
        {
             rear=(front+x-1)%size;
        }
    }

    void display()
    {
        if(front==-1) return;
        if(front<=rear)
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<" ";
        }
        else
        {
            for(int i=front;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }
            for(int i=0;i<=rear;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
    }
};

int main()
{
    deque <int> d;
    int q,z;
    while(q--)
    {
        cin>>z;
        int x;// depend on our deque 
        int y;//always be int
        if(z==1)
        {
            cin>>x;
            d.push_front(x);
        }
        else if(z==2)
        {
            d.pop_front();
        }
        else if(z==3)
        {
            cin>>x;
            d.push_back(x);
        }
        else if(z==4)
        {
            d.pop_back();
        }
        else if(z==7)
        {
            cout<<d.fronts()<<endl;
        }
        else if(z==8)
        {
            cout<<d.backs()<<endl;
        }
        else if(z==9)
        {
            cout<<d.empty()<<endl;
        }
        else if(z==10)
        {
            cout<<d.sizes()<<endl;
        }
        else if(z==11)
        {
            cin>>y>>x;
            d.resize(y,x);
        }
        else if(z==12)
        {
            d.clear();
        }
        else if(z==13)
        {
            cin>>y;
            cout<<d[y]<<endl;
        }
        else if(z==14)
        {
            d.display();
        }
    }
}    