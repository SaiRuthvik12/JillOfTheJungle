#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

using namespace std;
char copymap[18][71];
char ch;
int level=1;
int a=8;
int b=67;
int score=0;
int ent1=1;
int ent2=2;
int ent2a=5;
int ent2b=11;
int ent1a=10;
int ent1b=59;

HANDLE hConsole_c = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD dwBytesWritten = 0;

class Player
{
    public:
    char name[30];
    int finscore;

    Player()
    {
        finscore=0;
    }
}P;

/*void deleterecords(Player R)
{
    Player T;
    fstream fout("ScoresL2.txt",ios::in|ios::out|ios::binary);
    while(fout.read((char*)&T,sizeof(T)))
    {
        if(strcmp(T.name,R.name)==0)
        {
            fout.seekp(-1*sizeof(T),ios::cur);
            T.finscore=0;
            T.fintime=0.0;
            fout.write((char*)&T,sizeof(T));
        }
    }
}
*/

void putscores()
{
    fstream fin("Scores.txt",ios::app|ios::binary);
    fin.write((char*)&P,sizeof(P));
    fin.close();
}

void scoretable()
{
    Player T;
    fstream fout("Scores.txt",ios::in|ios::binary);
    cout<<"Name\t\tMonkey coins"<<endl;
    while(fout.read((char*)&T,sizeof(T)))
    {
        cout<<T.name<<"\t\t"<<T.finscore<<endl;
    }
}

void level1()
{
system("cls");
cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout << "\t\t\t\t\t\t\t  _      _____ _   _ _____ _         __  "<<endl;
cout << "\t\t\t\t\t\t\t | |    |  ___| | | |  ___| |       /  | "<<endl;
cout << "\t\t\t\t\t\t\t | |    | |__ | | | | |__ | |       `| |   "<<endl;
cout << "\t\t\t\t\t\t\t | |    |  __|| | | |  __|| |        | |   "<<endl;
cout << "\t\t\t\t\t\t\t | |____| |___\\ \\_/ / |___| |____   _| |_"<<endl;
cout << "\t\t\t\t\t\t\t \\_____/\\____/ \\___/\\____/\\_____/   \\___/"<<endl<<endl<<endl;
cout << "\t\t\t\t\t\t\t\t PRESS ANY KEY TO CONTINUE"<<endl;
_getch();
system("cls");
}

void level2()
{
system("cls");
cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout << "\t\t\t\t\t\t\t _      _____ _   _ _____ _         _____ "<<endl;
cout << "\t\t\t\t\t\t\t| |    |  ___| | | |  ___| |       / __  \\"<< endl;
cout << "\t\t\t\t\t\t\t| |    | |__ | | | | |__ | |       `' / /' "<<endl;
cout << "\t\t\t\t\t\t\t| |    |  __|| | | |  __|| |         / /  "<<endl;
cout << "\t\t\t\t\t\t\t| |____| |___\\ \\_/ | |__ | |____   ./ /___ "<<endl;
cout << "\t\t\t\t\t\t\t\\_____/\\____/ \\___/\\____/\\_____/   \\_____/"<<endl<<endl;
cout << "\t\t\t\t\t\t\t\t PRESS ANY KEY TO CONTINUE"<<endl;
_getch();
system("cls");
}

void loadingscreen()
{
    cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
   cout << "\t\t\t    ___ _____ _      _       ___________   _____ _   _  _____     ___ _   _ _   _ _____  _      _____ "<<endl;
   cout << "\t\t\t   |_  |_   _| |    | |     |  _  |  ___| |_   _| | | ||  ___|   |_  | | | | \\ | |  __ \\| |    |  ___|"<<endl;
   cout << "\t\t\t     | | | | | |    | |     | | | | |_      | | | |_| || |__       | | | | |  \\| | |  \\/| |    | |__  "<<endl;
   cout << "\t\t\t     | | | | | |    | |     | | | |  _|     | | |  _  ||  __|      | | | | | . ` | | __ | |    |  __| "<<endl;
   cout << "\t\t\t /\\__/ /_| |_| |____| |____ \\ \\_/ / |       | | | | | || |___  /\\__/ / |_| | |\\  | |_\\ \\| |____| |___ "<<endl;
   cout << "\t\t\t \\____/ \\___/\\_____/\\_____/  \\___/\\_|       \\_/ \\_| |_/\\____/  \\____/ \\___/\\_| \\_/\\____/\\_____/\\____/ "<<endl<<endl<<endl;
cout << "\t\t\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE"<<endl;
  _getch();
  system("cls");
}

void print_player(int col,int row,int l_move,int r_move,int u_move,int d_move)
{
    COORD pos = {col+l_move+r_move+40,row+u_move+d_move};
    SetConsoleActiveScreenBuffer(hConsole_c);
    WriteConsoleOutputCharacter(hConsole_c,"o",1,pos,&dwBytesWritten);
    pos = {col+40,row};
     WriteConsoleOutputCharacter(hConsole_c," ",1,pos,&dwBytesWritten);
}

void print_entity(int col,int row,int l_move,int r_move,int u_move,int d_move)
{
    COORD pos = {col+l_move+r_move+40,row+u_move+d_move};
    SetConsoleActiveScreenBuffer(hConsole_c);
    WriteConsoleOutputCharacter(hConsole_c,"M",1,pos,&dwBytesWritten);
    pos = {col+40,row};
     WriteConsoleOutputCharacter(hConsole_c," ",1,pos,&dwBytesWritten);
}

void youwin()
{
cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout << "\t\t\t__   __              _                                               _              _"<<endl;
cout << "\t\t\t\\ \\ / /             | |                                             (_)            | |"<<endl;
cout << "\t\t\t \\ V /___  _   _    | |__   __  __   __ ___      __ _  ___ __ _ _   _ _ _ __ ___  __| |"<<endl;
cout << "\t\t\t  \\ // _ \\| | | |   | '_ \\ / _`\\\\ \\ / / _ \\    / _` |/ __/ _` | | | | | '__/ _\ \/ _` |"<<endl;
cout << "\t\t\t  | | (_) | |_| |   | | | | (_| |\\ V /  __/   | (_| | (_| (_| | |_| | | | |  __/ (_| |"<<endl;
cout << "\t\t\t  \\_/\\___/\\ \__,_|   |_| |_|\\__,_| \\_/\ \___|    \__,_|\\___\\__, |\\__,_|_|_|  \\___|\\__,_|"<<endl;
cout << "\t\t\t                                                            | |"<<endl;
cout << "\t\t\t                                                            |_|"<<endl;
cout << "\t\t\t    ______  ___   _   _   ___   _   _   ___       ____________ ________  ___ _____"<<endl;
cout << "\t\t\t    | ___\ \/ _ \\ | \\ | | / _ \\ | \\ | | / _ \\      | ___ \\ ___ \\_   _|  \\/  ||  ___|"<<endl;
cout << "\t\t\t    | |_/ / /_\ \|  \| |/ /_\ \|  \| |/ /_\ \     | |_/ / |_/ / | | | .  . || |__"<<endl;
cout << "\t\t\t    | ___ \\  _  || . ` ||  _  || . ` ||  _  |     |  __/|    /  | | | |\/| ||  __|"<<endl;
cout << "\t\t\t    | |_/ / | | || |\  || | | || |\  || | | |     | |   | |\\\ \ _| |_| |  | || |___"<<endl;
cout << "\t\t\t    \\____/\\_| |_/\\_| \_/\\_| |_/\\_| \_/\\_| |_/     \\_|   \\_| \\_|\___/\\_|  |_/\\____/"<<endl;

cout << "\t\t\t                  ______ ______"<<endl;
cout << "\t\t\t                 |______|______|"<<endl;
cout << "\t\t\t                   __   __   __"<<endl;
cout << "\t\t\t                  / /  / /  / /"<<endl;
cout << "\t\t\t                 | |  | |  | |"<<endl;
cout << "\t\t\t                 | |  | |  | |"<<endl;
cout << "\t\t\t                 | |  | |  | |"<<endl;
cout << "\t\t\t                 | |  | |  | |"<<endl;
cout << "\t\t\t                  \\_\\  \\_\\  \\_\\"<<endl;
P.finscore=score;
if(level==2)
    {
        putscores();
        scoretable();
    }
}

void endgamewin()
{
    system("cls");
    youwin();
    cout << "Yes"<<endl;
    Sleep(2000);
}

void displaydeath()
{
system("cls");
cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout << "\t\t\t\t\t\t\t__   _______ _   _     ______ _____ ___________ "<<endl;
cout << "\t\t\t\t\t\t\t\\ \\ / /  _  | | | |    |  _  \\_   _|  ___|  _  \\"<<endl;
cout << "\t\t\t\t\t\t\t \\ V /| | | | | | |    | | | | | | | |__ | | | |"<<endl;
cout << "\t\t\t\t\t\t\t  \\ / | | | | | | |    | | | | | | |  __|| | | |"<<endl;
cout << "\t\t\t\t\t\t\t  | | \\ \\_/ / |_| |    | |/ / _| |_| |___| |/ / "<<endl;
cout << "\t\t\t\t\t\t\t  \\_/  \\___/ \\___/     |___/  \\___/\\____/|___/ "<<endl<<endl;
Sleep(3000);
cout << "\t\t\t\t\t\t\t\t\tPRESS ANY KEY TO FINISH"<<endl;
P.finscore=score;
putscores();
scoretable();
_getch();
exit(0);
}

int moveleft()
{
    if(copymap[a][b-1]=='M')
        displaydeath();
    if(copymap[a][b-1]=='$')
    {
        score+=10;
        print_player(b,a,-1,0,0,0);
        b=b-1;
        copymap[a][b+1]=' ';
    }
     if(copymap[a][b-1]=='('||copymap[a][b-1]=='_')
     {
        endgamewin();
        return -1;
     }
    if(copymap[a][b-1]==' ')
    {
        print_player(b,a,-1,0,0,0);
        b=b-1;
        copymap[a][b+1]=' ';
    }
    copymap[a][b]='o';
    return 0;
}

int moveright()
{
    if(copymap[a][b+1]=='M')
        displaydeath();
    if(copymap[a][b+1]=='$')
    {
        score+=30;
        print_player(b,a,0,1,0,0);
        b=b+1;
        copymap[a][b-1]=' ';
    }
    if(copymap[a][b+1]=='('||copymap[a][b+1]=='_')
    {
        endgamewin();
        return -1;
    }
    if(copymap[a][b+1]==' ')
    {
        print_player(b,a,0,1,0,0);
        b=b+1;
        copymap[a][b-1]=' ';
    }
    copymap[a][b]='o';
    return 0;
}

int moveup()
{
    if(copymap[a-1][b]=='M')
        displaydeath();
    if(copymap[a-1][b]=='('||copymap[a][b+1]=='_')
    {
        endgamewin();
        return -1;
    }
    if(copymap[a-1][b]=='$')
    {
        score+=30;
        print_player(b,a,0,1,0,0);
        b=b+1;
        copymap[a][b-1]=' ';
    }
    if(copymap[a-1][b]==' ')
    {
        print_player(b,a,0,0,-1,0);
        a=a-1;
        copymap[a+1][b]=' ';
    }
    copymap[a][b]='o';
    return 0;
}

int movedown()
{
    if(copymap[a+1][b]=='M')
        displaydeath();

    if(copymap[a][b-1]=='('||copymap[a][b-1]=='_')
    {
        endgamewin();
        return -1;
    }
    if(copymap[a+1][b]=='$')
    {
        score+=10;
        print_player(b,a,0,0,0,1);
        a=a+1;
        copymap[a-1][b]=' ';
    }
    if(copymap[a+1][b]==' ')
    {
        print_player(b,a,0,0,0,1);
        a=a+1;
        copymap[a-1][b]=' ';
    }
    copymap[a][b]='o';
    return 0;
}

void moveobstacle1()
{
    if(copymap[ent1a+1][ent1b]==' '&&ent1==1)
    {
        print_entity(ent1b,ent1a,0,0,0,1);
        ent1a=ent1a+1;
        copymap[ent1a-1][ent1b]=' ';
        copymap[ent1a][ent1b]='M';
    }
    else if(copymap[ent1a+1][ent1b]=='o'&&ent1==1)
        displaydeath();
    else
        ent1=3;
    if(copymap[ent1a-1][ent1b]==' '&&ent1==3)
    {
        print_entity(ent1b,ent1a,0,0,-1,0);
        ent1a=ent1a-1;
        copymap[ent1a+1][ent1b]=' ';
        copymap[ent1a][ent1b]='M';
    }
    else if(copymap[ent1a-1][ent1b]=='o'&&ent1==3)
        displaydeath();
    else ent1=1;
}

void moveobstacle2()
{
    if(copymap[ent2a][ent2b+1]==' '&&ent2==2)
    {
        print_entity(ent2b,ent2a,0,1,0,0);
        ent2b=ent2b+1;
        copymap[ent2a][ent2b-1]=' ';
        copymap[ent2a][ent2b]='M';
    }
    else if(copymap[ent2a][ent2b+1]=='o'&&ent2==2)
        displaydeath();
    else
        ent2=4;
    if(copymap[ent2a][ent2b-1]==' '&&ent2==4)
    {
        print_entity(ent2b,ent2a,-1,0,0,0);
        ent2b=ent2b-1;
        copymap[ent2a][ent2b+1]=' ';
        copymap[ent2a][ent2b]='M';
    }
    else if(copymap[ent2a][ent2b-1]=='o'&&ent2==4)
        displaydeath();
    else ent2=2;
}

int main()
{
        int g = 0;
        char mapx[70];
        loadingscreen();
        int choice1,choice2;
        cout<<"Enter your jungle name "<<endl;
        cin.getline(P.name,30);


        int loop1=1;
        while(loop1==1)
        {
            system("cls");
            cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout << "\t\t\t\t\t\t\t _______________________________________"<<endl;
            cout << "\t\t\t\t\t\t\t|\t\t\t\t\t|"<<endl;
            cout << "\t\t\t\t\t\t\t|\t1. Play\t\t\t\t|"<<endl;
            cout << "\t\t\t\t\t\t\t|\t2. Instructions\t\t\t|"<<endl;
            cout << "\t\t\t\t\t\t\t|\t3. Exit\t\t\t\t|"<<endl;
            cout << "\t\t\t\t\t\t\t|_______________________________________|"<<endl;
            cin >> choice1;

            int loop2=1;
            switch(choice1)
            {
            case 1:
            {
                    label:
                    while(loop2==1)
                    {
                        system("cls");
                        cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
                        cout << "\t\t\t\t\t\t\t _______________________________________"<<endl;
                        cout << "\t\t\t\t\t\t\t|\t\t\t\t\t|"<<endl;
                        cout << "\t\t\t\t\t\t\t|\t1. Level 1\t\t\t|"<<endl;
                        cout << "\t\t\t\t\t\t\t|\t2. Level 2\t\t\t|"<<endl;
                        cout << "\t\t\t\t\t\t\t|\t3. Main menu\t\t\t|"<<endl;
                        cout << "\t\t\t\t\t\t\t|_______________________________________|"<<endl;
                        cin >> choice2;
                        switch(choice2)
                        {
                            case 1:
                            {
                                level=1;
                                a=8;
                                g=0;
                                b=67;
                                level1();
                                int x= 0;

                                ifstream finmap("MAP.txt",ios::in);

                                    while( finmap.getline(mapx,71))
                                    {

                                        for(int j = 0; j<71;j++)
                                        {
                                            copymap[x][j]=mapx[j];
                                        }
                                        x++;
                                    }

                                    copymap[a][b]='o';
                                    copymap[ent1a][ent1b]='M';
                                    copymap[ent2a][ent2b]='M';

                                    for(int i = 0; i<x-1;i++)
                                    {
                                        cout<<"\t\t\t\t\t";
                                        for(int j = 0; j<71;j++)
                                        {
                                            cout << copymap[i][j];
                                        }
                                        cout <<endl;
                                    }

                                    while(g==0)
                                    {
                                        moveobstacle1();
                                        moveobstacle2();

                                         if(kbhit())
                                        {
                                            ch=_getch();

                                            switch(ch)
                                            {

                                                case 'a' : g=moveleft(); break;
                                                case 'w' : g=moveup(); break;
                                                case 's' : g=movedown(); break;
                                                case 'd' : g=moveright(); break;
                                            }

                                        }
                                    Sleep(100);
                                    }
                                }

                                case 2:
                                {
                                    level=2;
                                    g=0;
                                    a=8;
                                    b=67;
                                    print_player(b,a,0,0,0,0);
                                    level2();
                                    int x= 0;
                                    ifstream finmap("MAP2.txt",ios::in);

                                    while( finmap.getline(mapx,71))
                                    {

                                        for(int j = 0; j<71;j++)
                                        {
                                            copymap[x][j]=mapx[j];
                                        }
                                        x++;
                                    }
                                    copymap[a][b]='o';
                                    copymap[ent1a][ent1b]='M';
                                    copymap[ent2a][ent2b]='M';

                                    for(int i = 0; i<x-1;i++)
                                    {
                                        cout<<"\t\t\t\t\t";
                                        for(int j = 0; j<71;j++)
                                        {
                                            cout << copymap[i][j];
                                        }
                                        cout <<endl;
                                    }

                                    while(g==0)
                                    {
                                        moveobstacle1();
                                        moveobstacle2();
                                        if(kbhit())
                                            {
                                               ch=_getch();

                                    switch(ch)
                                    {
                                        case 'a' : g=moveleft(); break;
                                        case 'w' : g=moveup(); break;
                                        case 's' : g=movedown(); break;
                                        case 'd' : g=moveright(); break;
                                    }
                                }
                                Sleep(100);
                            }
                            break;
                        }
                        case 3:
                        {
                            cout<<"Returning to menu"<<endl;
                            loop2=0;
                            break;
                        }
                    }
                }
                break;
            }
            case 2:
            {
                    ifstream finins("instr.txt",ios::in);
                    while(finins)
                    {
                        char print[30];
                        finins.getline(print,30);
                        cout<<print<<endl;
                    }
                    system("PAUSE");
                    break;
            }
            case 3:
            {
                cout<<"Exiting game"<<endl;
                exit(0);
                break;
            }
        }
    }
    return 0;
}
