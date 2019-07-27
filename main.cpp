#include <iostream>
#include<map>
#include<conio.h>
#include<ctime>
#include<Windows.h>
#include<cstdlib>
#include<string>
#include <sstream>
using namespace std;
map<int,int>Snakes;
map<int,int>Ladders;
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

void printdice(int &dc)
{
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
}
void GRAPHICS(int &p1_pos,int &p2_pos)
{
   for(int i=100;i>=1;i--)
   {
     string s,t1;
              if(i%10==0)
                cout<<endl;
            t1=  to_string(i);
            if (i == p1_pos)
            {
                    s = "X" ;

            }
            else if (i == p2_pos)
            {
                    s = "O" ;
            }
            else
            {
                    s=t1;
            }

                        cout << "\t" << s;
   }
    Snake_Ladder_pos();
        
}
int main()
{
   
    string Player1,Player2;
    cout<<"Enter Player 1's NAME "<<endl;
    cin>>Player1;
    cout<<"Enter Player 2's NAME "<<endl;
    cin>>Player2;
    srand(time(0));
    int Player1_pos=1;
    int Player2_pos=1;
    int dc=0;

 
    //All the snakes at to the destiny
    Snakes.insert(pair<int,int>(97,75));
    Snakes.insert(pair<int,int>(66,52));
    Snakes.insert(pair<int,int>(63,60));
    Snakes.insert(pair<int,int>(47,25));
    Snakes.insert(pair<int,int>(31,4));
    Snakes.insert(pair<int,int>(16,8));
    //All the ladders at to the destiny
    Ladders.insert(pair<int,int>(3,39));
    Ladders.insert(pair<int,int>(10,12));
    Ladders.insert(pair<int,int>(27,53));
    Ladders.insert(pair<int,int>(56,84));
    Ladders.insert(pair<int,int>(72,90));
    Ladders.insert(pair<int,int>(61,99));
    map<int,int>::iterator sp=Snakes.begin();
    map<int,int>::iterator lp=Ladders.begin();
/*     while(sp!=Snakes.end())
    {
        cout<<"\t"<<sp->first<<" = "<<sp->second<<endl;
        sp++;
    }
        while(lp!=Ladders.end())
    {
        cout<<"\t"<<lp->first<<" = "<<lp->second<<endl;
        lp++; 
    } */
//...........Print Snakes and Ladders to destination

do
{
        GRAPHICS(Player1_pos,Player2_pos);
   int d;
     cout<<"\tNOW , Its PLAYER 1's Turn >>>"<<endl;
    cin>>d;
    if(d==7)
    {
            //Random dice count
            dc = (rand() % 6) + 1;
            printdice(dc);//cout << "Dice Count " << dc << endl;
            Player1_pos += dc;
            //Printing current position of the Player...
            cout << "\t  CURRENT POSITION OF PLAYER 1 : \t" << Player1_pos << endl;
            //Handling Snakes and Ladders
        
            for(sp=Snakes.begin();sp !=Snakes.end();sp++)
            {
                if(Player1_pos==sp->first)
                {
                    Player1_pos=sp->second;
                    cout<<"\t  SNAKE EATEN  : \t"<< Player1_pos<<endl;
                    break;
                }
            }
          for(lp=Ladders.begin();lp !=Ladders.end();lp++)
            {
              if(Player1_pos==lp->first)
                {
                Player1_pos=lp->second;
                cout<<"\t  GOT LADDER : \t"<< Player1_pos<<endl;
                break;
                }
            }     
    }
        cout<<"\tNOW , Its PLAYER 2's Turn >>>"<<endl;
            //PLAYER 2 CONFIGURATION....
    cin>>d;
    if(d==7)
    {
            //Random dice count
            dc = (rand() % 6) + 1;
            printdice(dc); //cout << "Dice Count " << dc << endl;
            Player2_pos += dc;
            //Printing current position of the Player...
            cout << "\t  CURRENT POSITION OF PLAYER 2 : \t" << Player2_pos << endl;
            //Handling Snakes and Ladders
        
            for(sp=Snakes.begin();sp !=Snakes.end();sp++)
            {
                if(Player2_pos==sp->first)
                {
                    Player2_pos=sp->second;
                    cout<<"\t  SNAKE EATEN  : \t"<< Player2_pos<<endl;
                    break;
                }
            }
          for(lp=Ladders.begin();lp !=Ladders.end();lp++)
            {
              if(Player2_pos==lp->first)
                {
                Player2_pos=lp->second;
                cout<<"\t  GOT LADDER : \t"<< Player2_pos<<endl;
                break;
                }
            }     
    }
     
}while(Player1_pos<100 && Player2_pos<100);
string winner;
winner=(Player1_pos>=100)?Player1:Player2;
cout<<" ************* "<<winner<< " WIN"<<"  ************"<<endl;

    return 0; 
}
