#include <iostream>
#include<map>
#include<conio.h>
#include<ctime>
#include <vector>
#include<Windows.h>
#include<cstdlib>
#include<string>
#include <sstream>
#include<graphics.h>
#include <fstream>
using namespace std;
map<int, int> Snakes;
map<int, int> Ladders;
map<int, int>::iterator sp = Snakes.begin();
map<int, int>::iterator lp = Ladders.begin();

void draw_line(int n, char ch)
{
    for (int i = 0; i < n; i++)
        cout << ch;
}
void Snake_Ladder_pos()
{

    cout << "\n\n";
    draw_line(50, '-');
    cout << "\n\t\tSNAKE AT POSITION\n";
    draw_line(50, '-');
    cout << "\n\tFrom 98 to 28 \n\tFrom 95 to 24\n\tFrom 92 to 51\n\tFrom 83 to 19\n\tFrom 73 to 1\n\tFrom 69 to 33\n\tFrom 64 to 36\n\tFrom 59 to 17\n\tFrom 55 to 7\n\tFrom 52 to 11\n\tFrom 48 to 9\n\tFrom 46 to 5\n\tFrom 44 to 22\n\n";
    draw_line(50, '-');
    cout << "\n\t\t LADDER AT POSITION\n";
    draw_line(50, '-');
    cout << "\n\tFrom 8 to 26\n\tFrom 21 to 82\n\tFrom 43 to 77\n\tFrom 50 to 91\n\tFrom 62 to 96\n\tFrom 66 to 87\n\tFrom 80 to 100\n";
    draw_line(50, '-');
    cout << endl;


}
void Record_file(string winner)
{

    ofstream  rec;
    rec.open("Winner.txt",ios::app);
    rec<<"\n"<<winner;
    rec.close();

}
void Display_Winners()
{
    char pow[757];
    ifstream dis("Winner.txt");
    dis.getline(pow,757);
    cout<<"\t====  WINNERS ===="<<endl;
    cout<<pow<<endl;
    dis.close();
}
void printdice(int &dc)
{
    //draw_line(20,'=');
        if(dc==1)
        {
                cout<<"\n * "<<endl;
        }
        else if(dc==2)
        {
                cout<<"\n *  * "<<endl;
        }
        else if(dc==3)
        {
                cout<<" *     *"<<endl;
                cout<<"    *   "<<endl;
        }
        else if(dc==4)
        {
                cout<<"\n*   *"<<endl;
                cout<<"*   *"<<endl;
        }
        else if(dc==5)
        {
                cout << "*    *" << endl;
                cout << "   *   " << endl;
                cout << "*    *" << endl;
        }
        else if(dc==6)
        {
                cout << "*   *" << endl;
                cout << "*   *" << endl;
                cout << "*   *" << endl;
        }
        //draw_line(20, '=');
}
void GRAPHICS(int &p1_pos,int &p2_pos)
{
    Snake_Ladder_pos();
    for (int i = 100; i >= 1; i--)
    {
        string s, t1;
        if (i % 10 == 0)
            cout << endl;
        t1 = to_string(i);
        if (i == p1_pos)
        {
            s = "X";
        }
        else if (i == p2_pos)
        {
            s = "O";
        }
        else
        {
            s = t1;
        }

        cout << "\t" << s;
   }


}
class Player
{
    int pos = 1, dc;

public:
    void dine()
    {
        //Random dice count
        dc = (rand() % 25) + 1;
        printdice(dc);
        pos += dc;
        //Printing current position of the Player...
        cout << "\t  CURRENT POSITION OF PLAYER 1 : \t" << pos << endl;
        //Handling Snakes and Ladders

        for (sp = Snakes.begin(); sp != Snakes.end(); sp++)
        {
            if (pos == sp->first)
            {
                pos = sp->second;
                cout << "\t  SNAKE EATEN  : \t" << pos << endl;
                break;
            }
        }
        for (lp = Ladders.begin(); lp != Ladders.end(); lp++)
        {
            if (pos == lp->first)
            {
                pos = lp->second;
                cout << "\t  GOT LADDER : \t" << pos << endl;
                break;
            }
        }
    }
   int pass_pp()
    {
        return pos;
    }
};

int main()
{


    system("COLOR DF");
        int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setbkcolor(WHITEONBLACK);
    int x = 10;
    int y = 70;
    int font = 6;
    int direction = 0;
    int font_size = 5;
    settextstyle(font, direction, font_size);
    outtextxy(x, y, "Snake AND Ladder");
      settextstyle(font, direction, 1);
    outtextxy(170, 150, " MADE BY :-");
    outtextxy(170, 200, "OMKAR S SAWANT");
    outtextxy(170, 250, "ADITI KADAM");
    outtextxy(170, 300, "VAISHANAVI LADGE");
    outtextxy(270, 350, "PRESS ENTER TO CONTINUE");
    getch();


    closegraph();
    Player p1,p2;
    string Player1,Player2;
    cout<<endl<<"Enter Player 1's NAME "<<endl;
    cin>>Player1;
    cout<<endl<<"Enter Player 2's NAME "<<endl;
    cin>>Player2;
    srand(time(0));
    int Player1_pos=1;
    int Player2_pos=1;
    int dc=0;

    //All the snakes at to the destiny
    Snakes.insert(pair<int, int>(97, 75));
    Snakes.insert(pair<int, int>(66, 52));
    Snakes.insert(pair<int, int>(63, 60));
    Snakes.insert(pair<int, int>(47, 25));
    Snakes.insert(pair<int, int>(31, 4));
    Snakes.insert(pair<int, int>(16, 8));
    //All the ladders at to the destiny
    Ladders.insert(pair<int, int>(3, 39));
    Ladders.insert(pair<int, int>(10, 12));
    Ladders.insert(pair<int, int>(27, 53));
    Ladders.insert(pair<int, int>(56, 84));
    Ladders.insert(pair<int, int>(72, 90));
    Ladders.insert(pair<int, int>(61, 99));

    do
    {
        GRAPHICS(Player1_pos,Player2_pos);

     cout<<"\n\tNOW , Its PAYER 1's Turn >>>"<<endl;
     int d;
     cin >> d;
     if (d == 7)
     {
        p1.dine();
    }
        cout<<endl<<"\n\ttNOW , Its PLAYER 2's Turn >>>"<<endl;
            //PLAYER 2 CONFIGURATION....
    cin>>d;
    if(d==7)
    {
            p2.dine();
    }
     Player1_pos=p1.pass_pp();
     Player2_pos=p2.pass_pp();
}while(Player1_pos<100 && Player2_pos<100);
string winner;
winner=(Player1_pos>=100)?Player1:Player2;
cout<<" ************* "<<winner<< " WIN"<<"  ************"<<endl;
Record_file(winner);
Display_Winners();
return 0;
}
