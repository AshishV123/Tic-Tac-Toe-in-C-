#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
using namespace std;

char values[10];//={'1','2','3','4','5','6','7','8','9'};
void grid();
int turn(int);
int check();
int play ();
void newg();
int player=1;int x1,x2;
int h=0;

int main()
{int l1=0;
    system("cls");
    play();
    char u;
    while(1)
    {
        if(h==2){
            h=0;
            player++;
        }
        player=(player%2)?1:2;
        h=turn(player);
         grid();
        if(h==0)
            continue;
        else if(h==1)
        {
            cout<<endl<<endl<<"         Player "<<player<<" Wins"<<endl<<endl;
            if(player==1)
                x1++;
            else
                x2++;
            cout<<endl<<endl<<"Press y to continue"<<endl<<"Press n to exit"<<endl;
            u=getch();
            if(u=='y')
            {
                h=0;
                main();
            }
            else if(u=='n'){
                    system("cls");
                    cout<<"           Tic-Tac-Toe     "<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
                    if(x1>x2)
                        l1=1;
                    else if(x1<x2)
                        l1=2;
                    else if(x1==x2)
                        l1=0;
                if(l1!=0)
                    cout<<"      Overall winner is Player "<<l1<<endl<<endl<<"      *****CONGRATULATIONS*****"<<endl<<endl;;
                    if(l1==0)
                    {
                         cout<<endl<<"      Overall Match is Drawn       "<<endl<<endl;

                    }
                     exit(1);}
            else
            {
                cout<<endl<<"Invalid Option"<<endl;
                exit(1);
            }
        }
        else if(h==2)
        {//player++;
            cout<<endl<<endl<<"         Match is Drawn"<<endl<<endl;
            cout<<endl<<endl<<"Press y to continue"<<endl<<"Press n to exit"<<endl;
            u=getch();
            if(u=='y')
            {
                main();
            }
            else if(u=='n'){
                    system("cls");
                     cout<<"           Tic-Tac-Toe     "<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;

                    if(x1>x2)
                        l1=1;
                    else if(x1<x2)
                        l1=2;
                    else if(x1==x2)
                        l1=0;
                if(l1!=0)
                     cout<<"      Overall winner is Player "<<l1<<endl<<endl<<"      *****CONGRATULATIONS*****"<<endl<<endl;;
                   if(l1==0)
                    {
                         cout<<endl<<"      Overall Match is Drawn       "<<endl<<endl;

                    }
                     exit(1);}

            else
            {
                cout<<endl<<"Invalid Option"<<endl;
                exit(1);
            }
        }
    }
}
void grid()
{system("cls");
    cout<<"           Tic-Tac-Toe     "<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;//<<endl;
    cout<<"      Player 1 vs Player 2        "<<endl<<endl;
    cout<<"         "<<x1<<"      :    "<<x2<<"            "<<endl<<endl;
    cout<<"          |          |           "<<endl;
    cout<<"    "<<values[0]<<"     |     "<<values[1]<<"    |     "<<values[2]<<"     "<<endl;
    cout<<"          |          |           "<<endl;
    cout<<"---------- ---------- -----------"<<endl;
    cout<<"          |          |           "<<endl;
    cout<<"    "<<values[3]<<"     |     "<<values[4]<<"    |     "<<values[5]<<"     "<<endl;
    cout<<"          |          |           "<<endl;
    cout<<"---------- ---------- -----------"<<endl;
    cout<<"          |          |           "<<endl;
    cout<<"    "<<values[6]<<"     |     "<<values[7]<<"    |     "<<values[8]<<"     "<<endl;
    cout<<"          |          |           "<<endl;

   // turn();
}
int turn(int a)
{int n,i=0;
    cout<<endl<<"Player "<<a<<" Turn:";
    cin>>n;
    if(n>9||n<1)
    {
        cout<<"Invalid Move"<<endl<<endl<<"Press Enter to continue";
        getch();
        system("cls");
        return 0;
    }
    else
    {
        if(values[n-1]=='X'||values[n-1]=='O')
        {
             cout<<"Invalid Move"<<endl<<endl<<"Press Enter to continue";
            getch();
            system("cls");
            return 0;
        }
        else
        {
            if(a==1)
            {
                values[n-1]='O';
                system("cls");
                i=check();
                 if(i==0)
                {
                    player++;
                    return 0;
                }
                return i;


            }
            else if(a==2)
            {
                values[n-1]='X';
                system("cls");
                i=check();

               if(i==0)
                {
                    player++;
                     return 0;
                }
                else if(i==2)
                {
                  //  player++;
                    //cout<<"dd"<<player;
                    return 2;
                }
               return i;

            }
        }
    }
}
int check()
{
    int a,b,c;
    if(values[0]==values[1]&&values[1]==values[2])
    {
        return 1;
    }
    else if(values[3]==values[4]&&values[4]==values[5])
    {
        return 1;
    }
    else if(values[6]==values[7]&&values[7]==values[8])
    {
        return 1;
    }
    else if(values[0]==values[3]&&values[3]==values[6])
    {
        return 1;
    }
    else if(values[1]==values[4]&&values[4]==values[7])
    {
        return 1;
    }
    else if(values[2]==values[5]&&values[5]==values[8])
    {
        return 1;
    }
    else if(values[0]==values[4]&&values[4]==values[8])
    {
        return 1;
    }
    else if(values[2]==values[4]&&values[4]==values[6])
    {
        return 1;
    }
    else if(values[0]!='1'&&values[1]!='2'&&values[2]!='3'&&values[3]!='4'&&values[4]!='5'&&values[5]!='6'&&values[6]!='7'&&values[7]!='8'&&values[8]!='9')
    {
        return 2;

    }
    else
        return 0;


}

int play ()
{
     cout<<"           Tic-Tac-Toe     "<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;//<<endl;
    cout<<"      Player 1 vs Player 2        "<<endl<<endl;
    cout<<"         "<<x1<<"      :    "<<x2<<"            "<<endl<<endl;
    cout<<endl<<endl<<"Press Enter to start game"<<endl;getch();
    newg();
    //main();
 grid();
}
void newg()
{
    for(int j=0;j<9;j++)
    {
        values[j]=(char)(j+49);
    }
}
























