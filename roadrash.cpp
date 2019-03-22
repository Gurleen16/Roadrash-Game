#include<vector>
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
char board[50][37];
class car
{
    public:
    int cx,cy;
    char cvalue;
    void make_car()
    {
        cx=45;
        cy=18;
        cvalue='C';
    }
    void put_car()
    {
        board[cx][cy]=cvalue;
    }
    int move_car(char move)
    {
        if(move=='l'&& cy!=6)
            cy=cy-12;
        else if(move=='r' && cy!=30)
            cy=cy+12;
        else if(move=='u' && cx!=1)
            cx=cx-1;
        else if(move=='d' && cx!=49)
            cx=cx+1;
        else if(move=='s')
            cx=cx,cy=cy;
        else
            return 0;
        return 1;
    }

};
class obstacle
{
    public:
    int x,y;
    char value;
    make_obstacle(car &c)
    {
        x=c.cx-25;
        y=c.cy;
        value='@';
    }
    put_obstacle()
    {
        board[x][y]=value;
    }
    move_obstacle()
    {
        x++;
    }
};
void make_board()
{
    int i;
    for(i=0;i<37;i++)
        board[0][i]='*';
    for(i=0;i<37;i++)
        board[49][i]='*';
    for(i=0;i<50;i++)
        board[i][0]='*';
    for(i=0;i<50;i++)
        board[i][36]='*';
    for(i=1;i<49;i++)
        board[i][12]='||';
    for(i=1;i<49;i++)
        board[i][24]='||';
}
void show_board()
{
    int i,j;
    for(i=0;i<50;i++)
    {
        for(j=0;j<37;j++)
            cout<<board[i][j];
        cout<<endl;
    }
}
void makeBoardNull()
{
	for(int i=0;i<50;i++)
	{
		for(int j=0;j<34;j++)
		{
			board[i][j]='\0';
		}
	}
}
int main()
{
    obstacle ob;
    car c;
    char ch;
    cout<<"Welcome!!!"<<endl<<"Press Y for starting game and N for exit"<<endl;
    cin>>ch;
    if(ch=='Y'||ch=='y')
        system("cls");
    else
    {
        cout<<"Thanks for playing!!!"<<endl;
        return 0;
    }
    makeBoardNull();
    make_board();
    c.make_car();
    c.put_car();
    show_board();
    char move;
    cout<<"Press r for right,l for left,u for up, d for down and s for same position"<<endl;
    move=getch();
    int k;
    ob.make_obstacle(c);
    while(!_kbhit())
    {
        cout<<c.cx<<" "<<ob.x<<endl;
        system("cls");
        makeBoardNull();
        make_board();
        k=c.move_car(move);
        if(k==0)
        {
            cout<<"Game over!!!"<<endl<<"You lose!!!"<<endl;
            break;
        }
        if(ob.x==49)
        ob.make_obstacle(c);
        ob.move_obstacle();
        ob.put_obstacle();
        c.put_car();

        if((c.cx==ob.x+1 && c.cy==ob.y)||(c.cx==ob.x&&c.cy==ob.y)||(c.cx==ob.x-1 && c.cy==ob.y))
        {
            cout<<"Game over!!!"<<endl<<"You lose!!!"<<endl;
            break;
        }
        show_board();
        move=getch();
        if((int)move==27)
        {
            cout<<"Game over!!!";
            break;
        }

    }

}
