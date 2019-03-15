#include<iostream>
using namespace std;
int matrix [9][9];
void s()
{
        matrix[0][2]=4;    matrix[3][0]=2; matrix[3][1]=1; matrix[3][3]=7; matrix[3][4]=3; matrix[3][8]=9; matrix[4][3]=4; matrix[4][5]=1; matrix[4][6]=7; matrix[4][7]=2; matrix[4][8]=8; matrix[5][3]=8; matrix[5][4]=5; matrix[5][5]=2;
          matrix[0][3]=2; matrix[6][0]=8; matrix[6][1]=5; matrix[6][4]=1; matrix[6][7]=6; matrix[7][0]=7; matrix[7][4]=8; matrix[7][6]=3; matrix[7][7]=5;
            matrix[0][7]=8;  matrix[8][0]=3; matrix[8][8]=1;
              matrix[1][2]=3;
                matrix[1][4]=6;
                  matrix[2][0]=5;   matrix[2][1]=7;   matrix[2][2]=2;   matrix[2][6]=9;   matrix[2][8]=6;

                  }
bool show(int matrix[9][9],int r,int s,int e,int check)
{

   for(int i=1;i<=3;i++)
    {
        for(int j=s;j<=e;j++)
        {
            if(matrix[r][j]==check)
                return false;

        }
        r++;
    }
    return true;
}
bool c1(int matrix[9][9])
{ s();
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(matrix[i][j]==0)
                return true;
        }
    }
    return false;
}
bool row(int matrix[9][9],int r,int c,int check)
{
for(int i=0;i<9;i++)
{
   if(i!=c)
    {
        if(matrix[r][i]!=check )
           continue;
        else
        return false;
    }
}
for(int i=0;i<9;i++)
{
    if(i!=r)
    {
        if(matrix[i][c]!=check)
            continue;
        else
            return false;
    }
}
int t1=r/3;
int t2=c/3;

if(t1==0)
{
    if(t2==0)
    {
      bool an=    show(matrix,0,0,2,check);
      if(an==false)
        return false;
    }
    else if(t2==1)
    {
        bool an=    show(matrix,0,3,5,check);
      if(an==false)
        return false;
    }
    else
    {
       bool an=    show(matrix,0,6,8,check);
      if(an==false)
        return false;
    }
}
else if(t1==1)
    {
    if(t2==0)
    {
        bool an=show(matrix,3,0,2,check);
            if(an==false)
            return false;

    }
    else if(t2==1)
    {
        bool an=show(matrix,3,3,5,check);
            if(an==false)
            return false;
    }
    else
    {
        bool an=show(matrix,3,6,8,check);
            if(an==false)
            return false;
    }
}
else
    {
    if(t2==0)
    {
        bool an=show(matrix,6,0,2,check);
        if(an==false)
            return false;
    }
    else if(t2==1)
    {

        bool an=show(matrix,6,3,5,check);
        if(an==false)
            return false;
    }
    else
    {

        bool an=show(matrix,6,6,8,check);
        if(an==false)
            return false;
    }
}
return true;
}
void display()
{s();
for(int i=0,l=1;i<9;i++,l++)
    {        for(int j=0, k=1;j<9;j++,k++)
        {
        cout<<"\t"<< matrix[i][j]<<" ";
        if(k%3==0&&k!=1)
          cout<<"\t";
        }
            cout<<"\t";
        cout<<endl;
        if(l%3==0&&l!=1)
            cout<<"       ------------------------------------------------------------------------------------\n";
}
}
void start()
{
    int g=1;
    bool b;
int r,c;
    display();
    do
    {
        char t;
        g++;
        if(g%10==0)
        {
            cout<<"YOU WANT TO CONTINUE WITH THIS GAME (y/n)" <<endl;
            cin>>t;
            if(t!='y')
                break;
        }
    int num;
    cout<<"Enter row no.( 1-9) and column no.(1-9) :  "<<endl;
    cin>>r>>c;
     r=r-1;
    c=c-1;
    char ans='y';
    int a=0;
    if(matrix[r][c]!=0)
    {
    if( matrix[0][2]==4||    matrix[3][0]==2||  matrix[3][1]==1||  matrix[3][3]==7||  matrix[3][4]==3||  matrix[3][8]==9||  matrix[4][3]==4|| matrix[4][5]==1||  matrix[4][6]==7||  matrix[4][7]==2||  matrix[4][8]==8|| matrix[5][3]==8||  matrix[5][4]==5||  matrix[5][5]==2||
          matrix[0][3]==2||  matrix[6][0]==8||  matrix[6][1]==5||  matrix[6][4]==1||  matrix[6][7]==6||  matrix[7][0]==7||  matrix[7][4]==8||  matrix[7][6]==3||  matrix[7][7]==5||
            matrix[0][7]==8||   matrix[8][0]==3||  matrix[8][8]==1||
              matrix[1][2]==3||
                matrix[1][4]==6||
                  matrix[2][0]==5||    matrix[2][1]==7||    matrix[2][2]==2||   matrix[2][6]==9||    matrix[2][8]==6)
                  {
                      cout<<"---YOU CAN'NT CHANGE INBULIT SUDUKO---"<<endl;
                       a=1;
                  }
else
{
    cout<<"ALREADY FILLED....... WANT TO UPDATE THIS (y/n)"<<endl;
        cin>>ans;
}
    }
 if(a==0)
 {
         if(ans=='y')
        {
    cout<<"Enter number at (" <<r+1<<","<<c+1<<") : "<<endl;
    cin>>num;
if(num==0||num>9)
    cout<<"INVALID NUMBER ";
else
{
    int check=num;

bool a=row(matrix,r,c,check);
if(a==true)
    matrix[r][c]=num;
    else
        cout<<"WRONGLY PLACED .......WHICH IS AGAINST RULES "<<endl;
display();
        }


b=c1(matrix);
}
 }

    }
while(b==true);
}


int main()
{
 cout<<"SO LET'S START THE GAME" <<endl<<endl;
    start();
    bool a=c1(matrix);
    if(a==true)
        cout<<"-----YOU LOSE THIS GAME -----";
    else
        cout<<"!!!!!!!!!CONGRATS YOU WIN !!!!!!!!!!";
}
