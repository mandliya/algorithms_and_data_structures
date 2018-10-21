#include<iostream>
using namespace std;

int size;
class cque
{
    int a[50],front = -1, rear = -1,x;
public:
    void insert();
    void del();
    void show();
};

void cque::insert()
{
    char ch = 'y';
    while(ch == 'y' || ch == 'Y')
    {
        cout<<"\nEnter  Element : ";
        cin>>x;
        if(rear == (size - 1) && front == 0 || rear ==(front-1))
        {
            cout<<"\nOverflow!";
            break;
        }
        else if(front == -1 && rear == -1)
        {
            front = rear = 0;
            a[rear] = x;
        }
        else if(rear == (size -1))
        {
            rear = 0;
            a[rear] = x;
        }
        else
            a[++rear] = x;
        cout<<"\nDo you want to enter more?(y/n)...";
        cin>>ch;
    }
}

void cque::del()
{
    if(front == -1)
        cout<<"\nUnderflow!";
    else if(front == rear)
    {
        cout<<a[front]<<" Deleted Succesfully!";
        front = rear = -1;
    }
    else if(front == (size-1))

    {
        cout<<a[front]<<" Deleted Succesfully!";
        front = 0;
    }
    else
    {
        cout<<a[front]<<" Deleted Succesfully!";
        front++;
    }
}

void cque::show()
{
    if(front == -1 && rear == -1)
        cout<<"\nQueue is empty !";
    else if(rear>front)
    {
        for(int i = front ;i<=rear;i++)
           cout<<a[i]<<"\t"; 
    }
    else
    {
        for(int i = front; i<= size -1; i++)
            cout<<a[i]<<"\t";
        for( int i =0; i<=rear;i++)
            cout<<a[i]<<"\t";
    }
   /* else
        for(int i = front ;i <= rear;i++)
            cout<<a[i]<<"\t";*/
}


int main()
{
    int ch,a = 0;
    cque o;
    cout<<"\nEnter size of queue : ";
    cin>>size;
    while(1)
    {
        cout<<"\nMENU\n1.Insert\n2.Delete\n3.Show\n4.Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1: o.insert();
                    break;
            case 2: o.del();
                    break;
            case 3: o.show();
                    break;
            case 4: exit(0);
            default : cout<<"\nInvalid Choice!";
                    break;
        }
    }
    return 0;
}
