#include<ctime>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include<cmath>
#include<string>
#include <stdio.h>
#include<SDL_mixer.h>
#include<fstream>
#include <windows.h>
#include<vector>


using namespace std;

const char * font_address_01="IranNastaliq.ttf";
const char * font_address_02="HARLOWSI.ttf";
const char * font_address_03="MAGNETOB.ttf";
const char * font_address_04="arial.ttf";

typedef enum{
     NONE = 0,
     HORIZENTAL = 1,
     VERTICAL = 2,
     HORVER = 3
}short;

/*struct player
{
    string name;
    int win=0;
    int Lose=0;
    int draw=0;
    int GF=0;
    int GA=0;
    int point=0;
    int game=0;
    int GD=0;

    void RefreshGame()
    {
        game=win+Lose+draw;
    }
    void RefreshGD()
    {
        GD=GF-GA;
    }
    void RefreshPoint()
    {
        point=win*3+draw;
    }

};*/

void texture(SDL_Renderer *m_renderer,int xp,int yp,string addressOfImage,int width,int height);
void write(SDL_Renderer *renderer,int x,int y,string te,const char * font,int font_size,int R,int G,int B, int A,double angle,short flip_num);
void inputText(SDL_Renderer *m_renderer,int x,int y,string &inputText,const char * font,int font_size,int R,int G,int B, int A);
void Sort(string names[],int games[],int wins[],int lose[],int draws [],int GFs[], int GAs[],int points[],int GDs[],int Count);
int Searchplayer(string names[],string name);
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian );

int main( int argc, char * argv[] )
{

    //DEFAULT...Start

    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO;
    Uint32 WND_flags = SDL_WINDOW_SHOWN ;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    SDL_Renderer * m_renderer2;
    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 1280, 800, WND_flags, &m_window, &m_renderer );
    SDL_RaiseWindow(m_window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int W = DM.w;
    int H = DM.h;
    TTF_Init();
    //DEFAULT...End
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,2,2048);
    string Click = "click.wav";
    string championsleaguesong="ChampionsLeagueSong.mp3";
    string brazilworldcup="BrazilWorldCup.mp3";
    string southafricaworldcup="SouthAfricaWorldCup.mp3";
    string erica="erica.mp3";
    string torkishmarsh="torkishmarsh.mp3";
    string Baroon="Baroon.mp3";
    string hello1="hello1.wav";
    string hello2="hello2.wav";
    string whistle="whistle.wav";
    string background="background.mp3";
    string Goall="gol.wav";
    string TOPOLI="topoli.wav";
    string AVAZI="avazi.wav";
    string Winner="winner.wav";
    string Kick="kick.wav";
    Mix_Music *GameSound1 = Mix_LoadMUS(brazilworldcup.c_str());
    Mix_Music *GameSound2= Mix_LoadMUS(erica.c_str());
    Mix_Music *GameSound3 = Mix_LoadMUS(southafricaworldcup.c_str());
    Mix_Music *GameSound4 = Mix_LoadMUS(Baroon.c_str());
    Mix_Music *GameSound5 = Mix_LoadMUS(torkishmarsh.c_str());
    Mix_Music *GameSound6 = Mix_LoadMUS(championsleaguesong.c_str());
    Mix_Music *Background = Mix_LoadMUS(background.c_str());

    Mix_Chunk *click=Mix_LoadWAV(Click.c_str());
    Mix_Chunk *Hello1=Mix_LoadWAV(hello1.c_str());
    Mix_Chunk *Hello2=Mix_LoadWAV(hello2.c_str());
    Mix_Chunk *Whistle = Mix_LoadWAV(whistle.c_str());
    Mix_Chunk *goall = Mix_LoadWAV(Goall.c_str());
    Mix_Chunk *topoli = Mix_LoadWAV(TOPOLI.c_str());
    Mix_Chunk *avazi = Mix_LoadWAV(AVAZI.c_str());
    Mix_Chunk *winnersound = Mix_LoadWAV(Winner.c_str());
    Mix_Chunk *kick = Mix_LoadWAV(Kick.c_str());
    SDL_Event *e = new SDL_Event();

    bool Exit=false;
    int xmouse,ymouse;
    bool backmainmenu=false;
    bool backgamemenu1=false;
    bool chooseplayer1=false;
    bool chooseplayer2=false;
    int x0table=177;
    int y0table=131;
    int time;

    string temptable="";
    string ball="ball1.png";
    string stadium="stadium2.png";
    bool gameend=true;

    string tempchangemusic;
    int channgmmusic=1;
    string temp;
    int numberRplayer=0;
    int numberLplayer=0;
    int CountR=0,CountL=0;
    bool getnamed=false;
    string nameR="";
    string nameL="";
    //loading information
    ifstream filename("name.txt");
    ifstream filewin("win.txt");
    ifstream filelose("lose.txt");
    ifstream filedraw("draw.txt");
    ifstream fileGF("GF.txt");
    ifstream fileGA("GA.txt");

    string names[20];
    int games[20];
    int wins[20];
    int lose[20];
    int draws[20];
    int GFs[20];
    int GAs[20];
    int points[20];
    int GDs[20];
    int Count=0;
    bool choosecarR=false;
    bool choosecarL=false;
    string playerL="";
    string playerR="";
    string headfireballR="headfireballR.png";
    string invisibleballR="invisibleballR.png";
    string kickfireballR="kickfireballR.png";
    string punchR="punchR.png";
    string thiefR="thiefR.png";
    string triplecloneR="triplecloneR.png";
    string headfireballL="headfireballL.png";
    string invisibleballL="invisibleballL.png";
    string kickfireballL="kickfireballL.png";
    string punchL="punchL.png";
    string thiefL="thiefL.png";
    string triplecloneL="triplecloneL.png";
    bool backmainmenu2=false;
    bool pause=false;

  string natije="";


    bool game=true;
    int scoreL,scoreR,start;
    bool powerL;
    bool powerR;

    bool KICKFIREBALLL;
    bool HEADFIREBALLL;
    bool INVISIBLEBALL;
    bool PUNCHL;
    bool THIEFL;
    bool TRIPLECLONEL;

    bool KICKFIREBALLR;
    bool HEADFIREBALLR;
    bool INVISIBLEBALR;
    bool PUNCHR;
    bool THIEFR;
    bool TRIPLECLONER;
    bool  SAKHREL;
    bool SAKHRER;

    int loadpowerL=0;
    int loadpowerR=0;

    string shoeL="shoeL.png";
    string shoeR="shoeR.png";

    bool celebgoalL=false;
    bool celebgoalR=false;

    bool Avazi=true;
    bool Topoli=true;
    bool shootR=false;
    int shootcountR=0;
    int shootcountL=0;
    bool shootL=false;

    while(filename>>temp)
    {
        names[Count++]=temp;
    }
    cout<<"Count="<<Count<<endl;
    for(int i=0;i<Count;i++)
        cout<<names[i]<<endl;
    for(int i=0;i<Count;i++)
    {
        filewin>>wins[i];
        filelose>>lose[i];
        filedraw>>draws[i];
        fileGF>>GFs[i];
        fileGA>>GAs[i];
        games[i]=wins[i]+lose[i]+draws[i];
        GDs[i]=GFs[i]-GAs[i];
        points[i]=3*wins[i]+draws[i];
    }
             /*   for(int i=0;i<Count;i++)
            {
                cout<<"***************"<<endl;
                cout<<names[i]<<endl<<games[i]<<endl<<wins[i]<<endl<<lose[i]<<endl<<draws[i]<<endl<<GFs[i]<<endl<<GAs[i]<<endl<<GDs[i]<<endl<<points[i]<<endl;
            }*/

    filename.close();
    filedraw.close();
    filewin.close();
    filelose.close();
    fileGF.close();
    fileGA.close();

    texture(m_renderer,0,0,"start.png",1280,800);
    SDL_RenderPresent(m_renderer);
    SDL_Delay(5000);
    Mix_PlayMusic(GameSound1,-1);
    texture(m_renderer,0,0,"load1.png",1280,800);
    SDL_RenderPresent(m_renderer);
    SDL_Delay(1000);
    texture(m_renderer,0,0,"load2.png",1280,800);
    SDL_RenderPresent(m_renderer);
    SDL_Delay(2000);
    texture(m_renderer,0,0,"load3.png",1280,800);
    SDL_RenderPresent(m_renderer);
    SDL_Delay(2000);
    texture(m_renderer,0,0,"load4.png",1280,800);
    SDL_RenderPresent(m_renderer);
    SDL_Delay(1000);

    while(!Exit)
    {
    texture(m_renderer,0,0,"mainmenu.png",1280,800);
    SDL_RenderPresent(m_renderer);
    SDL_PollEvent(e);
    if(e->type == SDL_MOUSEBUTTONDOWN)
    {
        xmouse=e->button.x;
        ymouse=e->button.y;
    if(xmouse>=57 && xmouse<=303 && ymouse>=373 && ymouse<=435 )//Exit
    {
        Mix_PlayChannel(-1,click,0);
        cout<<"exit"<<endl;
       Exit=true;
    }
    else if(xmouse>=57 && xmouse<=303 && ymouse>=136 && ymouse<=199 )//League table
    {
        Mix_PlayChannel(-1,click,0);
        cout<<"leagueTable"<<endl;
        cout<<"Sorting..."<<endl;
        cout<<"Count="<<Count<<endl;
        Sort(names,games,wins,lose,draws,GFs,GAs,points,GDs,Count);
        while(!backmainmenu)
        {
            for(int i=0;i<Count;i++)
            {
                cout<<"***************"<<endl;
                cout<<names[i]<<endl<<games[i]<<endl<<wins[i]<<endl<<lose[i]<<endl<<draws[i]<<endl<<GFs[i]<<endl<<GAs[i]<<endl<<GDs[i]<<endl<<points[i]<<endl;
            }
            texture(m_renderer,0,0,"leaguetable.png",1280,800);
            cout<<"Count="<<Count<<endl;
            for(int i=0;i<(min(Count,11));i++)
            {
                write(m_renderer,177,131+i*60,names[i],font_address_04,20,0,0,0,255,0,NONE);
                write(m_renderer,365,131+i*60,to_string(games[i]),font_address_04,20,0,0,0,255,0,NONE);
                write(m_renderer,502,131+i*60,to_string(wins[i]),font_address_04,20,0,0,0,255,0,NONE);
                write(m_renderer,1163,131+i*60,to_string(points[i]),font_address_04,20,0,0,0,255,0,NONE);
                write(m_renderer,1051,131+i*60,to_string(GDs[i]),font_address_04,20,0,0,0,255,0,NONE);
                write(m_renderer,969,131+i*60,to_string(GAs[i]),font_address_04,20,0,0,0,255,0,NONE);
                write(m_renderer,882,131+i*60,to_string(GFs[i]),font_address_04,20,0,0,0,255,0,NONE);
                write(m_renderer,736,131+i*60,to_string(draws[i]),font_address_04,20,0,0,0,255,0,NONE);
                write(m_renderer,605,131+i*60,to_string(lose[i]),font_address_04,20,0,0,0,255,0,NONE);
            }
        SDL_RenderPresent(m_renderer);
        SDL_RenderClear(m_renderer);
        while(!backmainmenu)
        {
            SDL_PollEvent(e);
            if(e->type == SDL_MOUSEBUTTONDOWN)
            {
                xmouse=e->button.x;
                ymouse=e->button.y;
                if(xmouse>=3 && xmouse<=174 && ymouse>=4 && ymouse<=35 )
                {
                    backmainmenu=true;
                    Mix_PlayChannel(-1,click,0);
                }
            }
        }

          /*  if(e->type == SDL_MOUSEBUTTONDOWN)
            {
                xmouse=e->button.x;
                ymouse=e->button.y;
                if(xmouse>=3 && xmouse<=174 && ymouse>=4 && ymouse<=35 )
                {
                    backmainmenu=true;
                    Mix_PlayChannel(-1,click,0);
                }
            }*/


        }
        backmainmenu=false;
        SDL_RenderClear(m_renderer);

    }

    else if(xmouse>=57 && xmouse<=303 && ymouse>=214 && ymouse<=280 )//setting
    {
        Mix_PlayChannel(-1,click,0);
        cout<<"setting"<<endl;
        while(!backmainmenu)
        {
        texture(m_renderer,0,0,"setting.png",1280,800);
        if(channgmmusic==1)
        {
           rect(m_renderer,166,276,346,56,255,255,255,1);
           write(m_renderer,166,304,"BrazilWorldCup",font_address_04,20,0,0,0,255,0,0);
           texture(m_renderer,190,372,"fifa.png",300,260);
           SDL_RenderPresent(m_renderer);
        }
        if(channgmmusic==6)
        {
           rect(m_renderer,166,276,346,56,255,255,255,1);
           write(m_renderer,166,304,"ChampionsLeagueSong",font_address_04,20,0,0,0,255,0,0);
           texture(m_renderer,190,372,"fifa.png",300,260);
           SDL_RenderPresent(m_renderer);
        }
        if(channgmmusic==3)
        {
           rect(m_renderer,166,276,346,56,255,255,255,1);
           write(m_renderer,166,304,"SouthAfricaWorldCup.mp3",font_address_04,20,0,0,0,255,0,0);
           texture(m_renderer,190,372,"fifa.png",300,260);
           SDL_RenderPresent(m_renderer);
        }
        if(channgmmusic==2)
        {
           rect(m_renderer,166,276,346,56,255,255,255,1);
           write(m_renderer,166,304,"Erica",font_address_04,20,0,0,0,255,0,0);
           texture(m_renderer,190,372,"erica.png",300,260);
           SDL_RenderPresent(m_renderer);
        }
        if(channgmmusic==5)
        {
           rect(m_renderer,166,276,346,56,255,255,255,1);
           write(m_renderer,166,304,"torkishmarsh",font_address_04,20,0,0,0,255,0,0);
           texture(m_renderer,190,372,"motzart.png",300,260);
           SDL_RenderPresent(m_renderer);
        }
        if(channgmmusic==4)
        {
           rect(m_renderer,166,276,346,56,255,255,255,1);
           write(m_renderer,166,304,"Baroon",font_address_04,20,0,0,0,255,0,0);
           texture(m_renderer,190,372,"shajarian.jpg",300,260);
           SDL_RenderPresent(m_renderer);
        }
        SDL_RenderPresent(m_renderer);
        SDL_PollEvent(e);
        SDL_Delay(200);
        if(e->type == SDL_MOUSEBUTTONDOWN)
        {
            xmouse=e->button.x;
            ymouse=e->button.y;
            if(xmouse>=14 && xmouse<=217 && ymouse>=16 && ymouse<=71 )//mainmenu
            {
                Mix_PlayChannel(-1,click,0);
                cout<<"backmainmenu"<<endl;
                backmainmenu=true;
            }
            else if(xmouse>=361 && xmouse<=412 && ymouse>=120 && ymouse<=169)//volume up
            {
                Mix_PlayChannel(-1,click,0);
                cout<<"volume UP"<<endl;


            }
            else if(xmouse>=461 && xmouse<=512 && ymouse>=119 && ymouse<=170)//volume down
            {
                Mix_PlayChannel(-1,click,0);
                cout<<"volume DOWN"<<endl;

            }
            else if(xmouse>=624 && xmouse<=685 && ymouse>=274 && ymouse<=331)//pause or resume music
            {
                Mix_PlayChannel(-1,click,0);
                cout<<"pause or resume music"<<endl;
                    if( Mix_PlayingMusic() == 0 )
                    {
                        Mix_PlayMusic(GameSound1, -1 );
                    }
                    else
                    {
                    if( Mix_PausedMusic() == 1 )
                    {
                        Mix_ResumeMusic();
                    }
                    else
                    {
                        Mix_PauseMusic();
                    }
                    }
            }
            else if(xmouse>=700 && xmouse<=763 && ymouse>=267 && ymouse<=336)//next music
            {
                Mix_PlayChannel(-1,click,0);
                cout<<"Next music"<<endl;
            channgmmusic++;
            if(channgmmusic>6)
            {
                channgmmusic=1;
            }
            if(channgmmusic==1)
                Mix_PlayMusic(GameSound1, -1 );
            if(channgmmusic==2)
                Mix_PlayMusic(GameSound2, -1 );
            if(channgmmusic==3)
                Mix_PlayMusic(GameSound3, -1 );
            if(channgmmusic==4)
                Mix_PlayMusic(GameSound4, -1 );
            if(channgmmusic==5)
                Mix_PlayMusic(GameSound5, -1 );
            if(channgmmusic==6)
                Mix_PlayMusic(GameSound6, -1 );
            }
            else if(xmouse>=545 && xmouse<=609 && ymouse>=266 && ymouse<=334)//! next music
            {
                Mix_PlayChannel(-1,click,0);
                cout<<"!Next music"<<endl;
            channgmmusic--;
            if(channgmmusic<1)
            {
                channgmmusic=6;
            }
             if(channgmmusic==1)
                Mix_PlayMusic(GameSound1, -1 );
            if(channgmmusic==2)
                Mix_PlayMusic(GameSound2, -1 );
            if(channgmmusic==3)
                Mix_PlayMusic(GameSound3, -1 );
            if(channgmmusic==4)
                Mix_PlayMusic(GameSound4, -1 );
            if(channgmmusic==5)
                Mix_PlayMusic(GameSound5, -1 );
            if(channgmmusic==6)
                Mix_PlayMusic(GameSound6, -1 );
            }
        }
        }
        backmainmenu=false;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////main part
    else if(xmouse>=57 && xmouse<=303 && ymouse>=55 && ymouse<=119 )//game
    {
        Mix_PlayChannel(-1,click,0);
        cout<<"game"<<endl;
        ///Enter player name
        texture(m_renderer,0,0,"Enterplayer.png",1280,800);
        SDL_RenderPresent(m_renderer);
        if(!getnamed)
        {
            inputText(m_renderer,56,183,nameL,font_address_04,35,0,0,0,255);
            for(int i=0;i<Count;i++)
            {
                if(names[i]==nameL)
                {
                    CountL++;
                    numberLplayer=i;
                    cout<<numberLplayer<<endl;
                    break;
                }
            }
            if(CountL!=0)
            {
                write(m_renderer,291,365,to_string(games[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,291,399,to_string(wins[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,291,440,to_string(lose[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,291,473,to_string(draws[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,291,508,to_string(GFs[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,291,543,to_string(GAs[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,291,572,to_string(GDs[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,291,611,to_string(points[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
            }
            else
            {
                write(m_renderer,156,653,"New Player!",font_address_04,40,0,0,0,255,0,0);
                names[Count]=nameL;
                games[Count]=0;
                wins[Count]=0;
                lose[Count]=0;
                draws[Count]=0;
                GFs[Count]=0;
                GAs[Count]=0;
                points[Count]=0;
                GDs[Count]=0;
                Count++;
            }
             SDL_RenderPresent(m_renderer);
             inputText(m_renderer,720,183,nameR,font_address_04,35,0,0,0,255);
             for(int i=0;i<30;i++)
             {
                 if(names[i]==nameR)
                 {
                     CountR++;
                     numberRplayer=i;
                     cout<<"Count="<<Count<<endl;
                     cout<<numberRplayer<<endl;
                     break;
                 }
             }
            if(CountR!=0)
            {
                write(m_renderer,967,365,to_string(games[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,967,399,to_string(wins[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,967,440,to_string(lose[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,967,473,to_string(draws[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,967,508,to_string(GFs[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,967,543,to_string(GAs[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,967,572,to_string(GDs[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,967,611,to_string(points[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
            }
            else
            {
                write(m_renderer,834,653,"New Player!",font_address_04,40,0,0,0,255,0,0);
                names[Count]=nameR;
                games[Count]=0;
                wins[Count]=0;
                lose[Count]=0;
                draws[Count]=0;
                GFs[Count]=0;
                GAs[Count]=0;
                points[Count]=0;
                GDs[Count]=0;
                Count++;
            }

             getnamed=true;
             chooseplayer1=true;
             chooseplayer2=true;

        }
        else
        {
            numberLplayer=Searchplayer(names,nameL);
            numberRplayer=Searchplayer(names,nameR);
            cout<<"Count="<<Count<<endl;
            cout<<numberLplayer<<endl;
            cout<<numberRplayer<<endl;
            write(m_renderer,56,183,nameL,font_address_04,35,0,0,0,255,0,0);
            write(m_renderer,720,183,nameR,font_address_04,35,0,0,0,255,0,0);
            if(CountL!=0)
            {
                write(m_renderer,291,365,to_string(games[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,291,399,to_string(wins[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,291,440,to_string(lose[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,291,473,to_string(draws[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,291,508,to_string(GFs[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,291,543,to_string(GAs[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,291,572,to_string(GDs[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,291,611,to_string(points[numberLplayer]),font_address_04,20,0,0,0,255,0,0);
                SDL_RenderPresent(m_renderer);
            }
            else
            {
                write(m_renderer,156,653,"New Player!",font_address_04,40,0,0,0,255,0,0);
                SDL_RenderPresent(m_renderer);
            }
            if(CountR!=0)
            {
                write(m_renderer,967,365,to_string(games[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,967,399,to_string(wins[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,967,440,to_string(lose[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,967,473,to_string(draws[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,967,508,to_string(GFs[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,967,543,to_string(GAs[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,967,572,to_string(GDs[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
                write(m_renderer,967,611,to_string(points[numberRplayer]),font_address_04,20,0,0,0,255,0,0);
                SDL_RenderPresent(m_renderer);
            }
            else
            {
                write(m_renderer,834,653,"New Player!",font_address_04,40,0,0,0,255,0,0);
                SDL_RenderPresent(m_renderer);
            }
           SDL_RenderPresent(m_renderer);
        }
        SDL_RenderPresent(m_renderer);
        while(!backmainmenu)
        {

        SDL_PollEvent(e);
        if(e->type == SDL_MOUSEBUTTONDOWN)
        {
            xmouse=e->button.x;
            ymouse=e->button.y;

            if(xmouse>=16 && xmouse<=172 && ymouse>=13 && ymouse<=55 )//backmainmenu
            {
                Mix_PlayChannel(-1,click,0);
                cout<<"backmainmenu"<<endl;
                backmainmenu=true;
            }
            else if(xmouse>=515 && xmouse<=721 && ymouse>=709 && ymouse<=763 && chooseplayer1 && chooseplayer2)//Next
            {
                Mix_PlayChannel(-1,click,0);
                cout<<"next"<<endl;
                texture(m_renderer,0,0,"choosecharacter.png",1280,800);
                SDL_RenderPresent(m_renderer);
                while(!backgamemenu1)
                {

                    SDL_PollEvent(e);
                    if(e->type == SDL_MOUSEBUTTONDOWN)
                    {
                        xmouse=e->button.x;
                        ymouse=e->button.y;
                        if(xmouse>=12 && xmouse<=270 && ymouse>=12 && ymouse<=66 )//backgamemenu1
                        {
                            Mix_PlayChannel(-1,click,0);
                            cout<<"backgamemenu1"<<endl;
                            backgamemenu1=true;

                        }
                        else if(xmouse>=79 && xmouse<=222 && ymouse>=189 && ymouse<=328)
                        {
                            Mix_PlayChannel(-1,click,0);
                            choosecarL=true;
                            playerL=kickfireballL;
                            texture(m_renderer,0,0,"choosecharacter.png",1280,800);
                            rect(m_renderer,79,189,222-79,328-189,0,255,0,0);
                            SDL_RenderPresent(m_renderer);

                        }
                        else if(xmouse>=252&& xmouse<=372 && ymouse>=195 && ymouse<=332)
                        {
                            Mix_PlayChannel(-1,click,0);
                            choosecarL=true;
                            playerL=headfireballL;
                            texture(m_renderer,0,0,"choosecharacter.png",1280,800);
                            rect(m_renderer,252,195,372-252,328-195,0,255,0,0);
                            SDL_RenderPresent(m_renderer);

                        }
                        else if(xmouse>=416 && xmouse<=548 && ymouse>=197 && ymouse<=337)
                        {
                            Mix_PlayChannel(-1,click,0);
                            choosecarL=true;
                            playerL=invisibleballL;
                            texture(m_renderer,0,0,"choosecharacter.png",1280,800);
                            rect(m_renderer,416,197,548-416,328-197,0,255,0,0);
                            SDL_RenderPresent(m_renderer);

                        }
                        else if(xmouse>=584 && xmouse<=714 && ymouse>=196 && ymouse<=337)
                        {
                            Mix_PlayChannel(-1,click,0);
                            choosecarL=true;
                            playerL=punchL;
                            texture(m_renderer,0,0,"choosecharacter.png",1280,800);
                            rect(m_renderer,584,196,714-584,337-196,0,255,0,0);
                            SDL_RenderPresent(m_renderer);

                        }
                        else if(xmouse>=754 && xmouse<=883 && ymouse>=203 && ymouse<=336)
                        {
                            Mix_PlayChannel(-1,click,0);
                            choosecarL=true;
                            playerL=thiefL;
                            texture(m_renderer,0,0,"choosecharacter.png",1280,800);
                            rect(m_renderer,754,203,883-754,336-203,0,255,0,0);
                            SDL_RenderPresent(m_renderer);
                        }
                        else if(xmouse>=919 && xmouse<=1054 && ymouse>=205 && ymouse<=334)
                        {
                            Mix_PlayChannel(-1,click,0);
                            choosecarL=true;
                            playerL=triplecloneL;
                            texture(m_renderer,0,0,"choosecharacter.png",1280,800);
                            rect(m_renderer,919,205,1054-919,334-205,0,255,0,0);
                            SDL_RenderPresent(m_renderer);

                        }
                        ///
                        else if(xmouse>=79 && xmouse<=222 && ymouse>=437 && ymouse<=579)
                        {
                            Mix_PlayChannel(-1,click,0);
                            choosecarR=true;
                            playerR=kickfireballR;
                            texture(m_renderer,0,0,"choosecharacter.png",1280,800);
                            rect(m_renderer,79,437,222-79,579-437,0,255,0,0);
                            SDL_RenderPresent(m_renderer);

                        }
                        else if(xmouse>=252&& xmouse<=370 && ymouse>=437 && ymouse<=579)
                        {
                            Mix_PlayChannel(-1,click,0);
                            choosecarR=true;
                            playerR=headfireballR;
                            texture(m_renderer,0,0,"choosecharacter.png",1280,800);
                            rect(m_renderer,252,437,370-252,579-437,0,255,0,0);
                            SDL_RenderPresent(m_renderer);

                        }
                        else if(xmouse>=416 && xmouse<=548 && ymouse>=437 && ymouse<=579)
                        {
                            Mix_PlayChannel(-1,click,0);
                            choosecarR=true;
                            playerR=invisibleballR;
                            texture(m_renderer,0,0,"choosecharacter.png",1280,800);
                            rect(m_renderer,416,437,548-416,579-437,0,255,0,0);
                            SDL_RenderPresent(m_renderer);

                        }
                        else if(xmouse>=584 && xmouse<=714 && ymouse>=437 && ymouse<=579)
                        {
                            Mix_PlayChannel(-1,click,0);
                            choosecarR=true;
                            playerR=punchR;
                            texture(m_renderer,0,0,"choosecharacter.png",1280,800);
                            rect(m_renderer,584,437,714-584,579-437,0,255,0,0);
                            SDL_RenderPresent(m_renderer);

                        }
                        else if(xmouse>=754 && xmouse<=883 && ymouse>=437 && ymouse<=579)
                        {
                            Mix_PlayChannel(-1,click,0);
                            choosecarR=true;
                            playerR=thiefR;
                            texture(m_renderer,0,0,"choosecharacter.png",1280,800);
                            rect(m_renderer,754,437,883-754,579-437,0,255,0,0);
                            SDL_RenderPresent(m_renderer);
                        }
                        else if(xmouse>=919 && xmouse<=1054 && ymouse>=437 && ymouse<=579)
                        {
                            Mix_PlayChannel(-1,click,0);
                            choosecarR=true;
                            playerR=triplecloneR;
                            texture(m_renderer,0,0,"choosecharacter.png",1280,800);
                            rect(m_renderer,919,437,1054-919,579-437,0,255,0,0);
                            SDL_RenderPresent(m_renderer);

                        }
                        ///
                        else if(xmouse>=1011 && xmouse<=1268 && ymouse>=681 && ymouse<=738 && choosecarR && choosecarL)//start game
                        {
                            Mix_PlayChannel(-1,click,0);
                            texture(m_renderer,0,0,"choosestadium.png",1280,800);
                            SDL_RenderPresent(m_renderer);
                            while(!backmainmenu2)
                            {
                                texture(m_renderer,0,0,"choosestadium.png",1280,800);
                                SDL_RenderPresent(m_renderer);
                                SDL_PollEvent(e);
                                if(e->type == SDL_MOUSEBUTTONDOWN)
                                {
                                xmouse=e->button.x;
                                ymouse=e->button.y;
                                if(xmouse>=4 && xmouse<=193 && ymouse>=7 && ymouse<=58)
                                {
                                    backmainmenu2=true;

                                }
                                else if(xmouse>=98 && xmouse<=597 && ymouse>=119 && ymouse<=531)
                                {
                                    stadium="stadium2.png";
                                    Mix_PlayChannel(-1,click,0);

                                }
                                else if(xmouse>=677 && xmouse<=1179 && ymouse>=118 && ymouse<=530)
                                {
                                    stadium="stadium1.jpg";
                                    Mix_PlayChannel(-1,click,0);

                                }
                                else if(xmouse>=493 && xmouse<=616 && ymouse>=592 && ymouse<=727)
                                {
                                    ball="ball2.png";
                                    Mix_PlayChannel(-1,click,0);
                                }
                                else if(xmouse>=672 && xmouse<=796 && ymouse>=598 && ymouse<=728)
                                {
                                    ball="ball1.png";
                                    Mix_PlayChannel(-1,click,0);
                                }
                                else if(xmouse>=111 && xmouse<=293 && ymouse>=624 && ymouse<=655)
                                {
                                    gameend=true;
                                    Mix_PlayChannel(-1,click,0);
                                }
                                else if(xmouse>=114 && xmouse<=289 && ymouse>=683 && ymouse<=717)
                                {
                                    gameend=false;
                                    Mix_PlayChannel(-1,click,0);
                                }

                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////GAME
                                else if(xmouse>=1103 && xmouse<=1273 && ymouse>=732 && ymouse<=788)
                                {
                                bool ahang=true;

                                cout<<"next"<<endl<<"starting game!"<<endl;
                                Mix_PauseMusic();
                                texture(m_renderer,0,0,"load1.png",1280,800);
                                SDL_RenderPresent(m_renderer);
                                SDL_Delay(10);
                                texture(m_renderer,0,0,"load2.png",1280,800);
                                SDL_RenderPresent(m_renderer);
                                SDL_Delay(20);
                                texture(m_renderer,0,0,"load3.png",1280,800);
                                SDL_RenderPresent(m_renderer);
                                SDL_Delay(20);
                                texture(m_renderer,0,0,"load4.png",1280,800);
                                SDL_RenderPresent(m_renderer);
                                SDL_Delay(10);
                                texture(m_renderer,0,0,"black.png",1280,800);
                                texture(m_renderer,0,100,"help.png",1280,600);
                                SDL_RenderPresent(m_renderer);
                                SDL_Delay(10000);
                                texture(m_renderer,0,0,stadium,1280,800);
                                SDL_RenderPresent(m_renderer);
                                SDL_Delay(100);

                               // SDL_Delay(4000);
                                int x0_L=-160,x0_R=1280+80,y0_L=600,y0_R=600,x_L,x_R,y_L,y_R,dx=40,dy,yGround=700;
                                int xf_R,yf_R,xf_L,yf_L;

                                x_L=x0_L;
                                x_R=x0_R;
                                y_L=y0_L;
                                y_R=y0_R;

                               Mix_PlayChannel(-1,Hello1,0);
                               SDL_RenderClear(m_renderer);
                               //enterance animation part1
                               for(int i=0;i<16;i++)
                                {
                                    yf_R=y_R+80;
                                    yf_L=y_L+80;
                                    xf_L=x_L;
                                    xf_R=x_R;
                                    texture(m_renderer,0,0,stadium,1280,800);
                                    texture(m_renderer,x_L,y0_L,playerL,80,80);
                                    texture(m_renderer,x_R,y0_R,playerR,80,80);
                                    texture(m_renderer,xf_L,yf_L,shoeL,120,20);
                                    texture(m_renderer,xf_R-40,yf_R,shoeR,120,20);
                                    SDL_RenderPresent(m_renderer);
                                    x_L+=dx;
                                    x_R-=dx;
                                    SDL_Delay(1);
                                    cout<<i<<endl;
                                }

                                write(m_renderer,480,800/2,"WELCOME",font_address_03,60,255,0,0,255,0,0);
                                SDL_RenderPresent(m_renderer);
                                SDL_Delay(3000);
                                SDL_RenderClear(m_renderer);
                                Mix_PlayChannel(-1,Hello2,0);

                               for(int i=0;i<10;i++)
                                {
                                    yf_R=y_R+80;
                                    yf_L=y_L+80;
                                    xf_L=x_L;
                                    xf_R=x_R;
                                    texture(m_renderer,0,0,stadium,1280,800);
                                    texture(m_renderer,x_L,y0_L,playerL,80,80);
                                    texture(m_renderer,x_R,y0_R,playerR,80,80);
                                    texture(m_renderer,xf_L,yf_L,shoeL,120,20);
                                    texture(m_renderer,xf_R-40,yf_R,shoeR,120,20);
                                    SDL_RenderPresent(m_renderer);
                                    x_L-=dx;
                                    x_R+=dx;
                                    SDL_Delay(10);
                                    SDL_RenderClear(m_renderer);
                                    cout<<i<<endl;

                                }
                                SDL_Delay(2000);
                                //game main part:
                                SDL_Delay(1000);
                                texture(m_renderer,0,0,stadium,1280,800);
                                texture(m_renderer,x0_L,y0_L,playerL,80,80);
                                texture(m_renderer,x0_R,y0_R,playerR,80,80);
                                texture(m_renderer,xf_L,yf_L,shoeL,120,20);
                                texture(m_renderer,xf_R-40,yf_R,shoeR,120,20);
                                SDL_RenderPresent(m_renderer);
                                start=clock();
                                cout<<clock()/1000;
                                x0_L=80;
                                x0_R=1820-160;
                                x_L=x0_L;
                                x_R=x0_R;
                                y_L=y0_L;
                                y_R=y0_R;

                                scoreL=0;
                                scoreR=0;
                                powerL=false;
                                powerR=false;
                                Mix_PlayMusic(Background,-1);
                                KICKFIREBALLL=false, HEADFIREBALLL=false, INVISIBLEBALL=false, PUNCHL=false,THIEFL=false, TRIPLECLONEL=false,SAKHREL=false;
                                KICKFIREBALLR=false, HEADFIREBALLR=false, INVISIBLEBALR=false, PUNCHR=false,THIEFR=false, TRIPLECLONER=false,SAKHRER=false;
                                loadpowerL=0;
                                loadpowerR=0;
                                int timerpower=clock();
                                bool freezeL=false,freezeR=false;
                                int pausetime=0;
                                int g;
                                x_R=1070;
                                x_L=160;
                                y_R=600;
                                y_L=600;
                                dx=0,dy=10;
                                    yf_R=y_R+80;
                                    yf_L=y_L+80;
                                    xf_L=x_L;
                                    xf_R=x_R;
                                int xb=625,yb=215;
                                    shootcountL=0;
                                    shootcountR=0;
                                    int rockL=0;
                                    int rockR=0;
                                    int countfreezR=0,countfreezL=0;
                                    bool powerrL=false,powerrR=false;
                                    bool visibility=true;
                                    int countvis=0;
                                    bool PUASE= true;
                                    int t=0;
                                    bool Nitro=true;
                                    bool fireballL=false;
                                    int countfireballL=0;
                                    bool fireballR=false;
                                    int countfireballR=0;
                                    bool barkhordR=false;
                                    bool barkhordL=false;
                                    bool TRIPL=false;
                                    bool TRIPR=false;
                                    int counttripl=0;
                                    int counttripr=0;

                                while(game)
                                {
                                    t++;

                                    if(pause)
                                    {
                                        texture(m_renderer,640-250,300,"puasemenu.png",500,200);
                                        SDL_RenderPresent(m_renderer);
                                        g=clock();
                                    while(PUASE)
                                    {
                                      SDL_PollEvent(e);
                                      if(e->type == SDL_MOUSEBUTTONDOWN)
                                      {
                                        xmouse=e->button.x;
                                        ymouse=e->button.y;
                                        if(xmouse>=623 && xmouse<=770 && ymouse>=380 && ymouse<=426)//quit game
                                        {
                                            PUASE=false;
                                            game=false;
                                        }
                                        else if(xmouse>=475 && xmouse<=613 && ymouse>=382 && ymouse<=426)//resume game
                                        {
                                          PUASE=false;
                                        }
                                      }
                                    }
                                    PUASE=true;

                                        pausetime+=(clock()-g)/1000;

                                    }
                                        if(SAKHREL)
                                        {
                                            rockL++;
                                        }
                                        if(rockL>=30)
                                        {
                                            rockL=0;
                                            SAKHREL=false;
                                        }
                                        if(SAKHRER)
                                        {
                                            rockR++;
                                        }
                                        if(rockR>=30)
                                        {
                                            rockR=0;
                                            SAKHRER=false;
                                        }
                                        if(shootL)
                                        {
                                            shootcountL++;

                                        }

                                       if(shootcountL>=6)
                                        {
                                            shootcountL=0;
                                            shootL=false;
                                        }
                                        if(shootR)
                                        {
                                            shootcountR++;
                                        }
                                        if(shootcountR>=6)
                                        {
                                            shootcountR=0;
                                            shootR=false;
                                        }
                                        if(shootL)
                                            shoeL="shoeL_shooting.png";
                                        else
                                            shoeL="shoeL.png";
                                        if(shootR)
                                            shoeR="shoeR_shooting.png";
                                        else
                                            shoeR="shoeR.png";


                                    pause=false;
                                    if(celebgoalL)
                                    {
                                    yf_R=y_R+80;
                                    yf_L=y_L+80;
                                    xf_L=x_L;
                                    xf_R=x_R;
                                        Mix_PlayChannel(-1,goall,0);
                                        for(int i=0;i<10;i++)
                                        {
                                            texture(m_renderer,0,0,stadium,1280,800);
                                            texture(m_renderer,80,600,playerL,80,80);
                                            texture(m_renderer,1280-160,600,playerR,80,80);
                                            texture(m_renderer,0,-400+i*100,"celebration.png",1280,800);
                                            texture(m_renderer,80,680,shoeL,120,20);
                                            texture(m_renderer,1080,680,shoeR,120,20);
                                            texture(m_renderer,390,150,"goal.png",500,500);
                                            SDL_RenderPresent(m_renderer);
                                            SDL_Delay(200);
                                        }
                                        celebgoalL=false;
                                    }
                                    if(celebgoalR)
                                    {
                                        Mix_PlayChannel(-1,goall,0);
                                            for(int i=0;i<10;i++)
                                        {
                                            texture(m_renderer,0,0,stadium,1280,800);
                                            texture(m_renderer,80,600,playerL,80,80);
                                            texture(m_renderer,1280-160,600,playerR,80,80);
                                            texture(m_renderer,0,-400+i*100,"celebration.png",1280,800);
                                            texture(m_renderer,80,680,shoeL,120,20);
                                            texture(m_renderer,1080,680,shoeR,120,20);
                                            texture(m_renderer,390,150,"goal.png",500,500);
                                            SDL_RenderPresent(m_renderer);
                                            SDL_Delay(200);
                                        }
                                        celebgoalR=false;
                                    }

                                    ahang=false;

                                    if(powerL && powerrL)
                                    {
                                    if(playerL==kickfireballL)
                                        KICKFIREBALLL=true;
                                    if(playerL==headfireballL)
                                        HEADFIREBALLL=true;
                                    if(playerL==invisibleballL)
                                        INVISIBLEBALL=true;
                                    if(playerL==punchL)
                                        PUNCHL=true;
                                    if(playerL==thiefL)
                                        THIEFL=true;
                                    if(playerL==triplecloneL)
                                        TRIPLECLONEL=true;
                                        powerL=false;
                                        powerrL=false;


                                    }
                                    if(powerR && powerrR)
                                    {
                                    if(playerR==kickfireballR)
                                        KICKFIREBALLR=true;
                                    if(playerR==headfireballR)
                                        HEADFIREBALLR=true;
                                    if(playerR==invisibleballR)
                                        INVISIBLEBALR=true;
                                    if(playerR==punchR)
                                        PUNCHR=true;
                                    if(playerR==thiefR)
                                        THIEFR=true;
                                    if(playerR==triplecloneR)
                                        TRIPLECLONER=true;
                                        powerR=false;
                                            powerrR=false;

                                    }
                                    if(THIEFL)
                                    {
                                        int t=clock();
                                        if(t%5==0)
                                            KICKFIREBALLL=true;
                                        if(t%5==1)
                                            HEADFIREBALLL=true;
                                        if(t%5==2)
                                            INVISIBLEBALL=true;
                                        if(t%5==3)
                                            PUNCHL=true;
                                        if(t%5==4)
                                            TRIPLECLONEL=true;
                                        THIEFL=false;
                                    }
                                    if(THIEFR)
                                    {
                                        int t=clock();
                                        if(t%5==0)
                                            KICKFIREBALLR=true;
                                        if(t%5==1)
                                            HEADFIREBALLR=true;
                                        if(t%5==2)
                                            INVISIBLEBALR=true;
                                        if(t%5==3)
                                            PUNCHR=true;
                                        if(t%5==4)
                                            TRIPLECLONER=true;
                                        THIEFR=false;
                                    }
                                    ///POWERS!
                                    //punchL
                                        if(PUNCHL && x_R-x_L<=200)
                                    {
                                        freezeR=true;
                                        PUNCHL=false;
                                        loadpowerL=0;
                                    }
                                    if(freezeR)
                                    {
                                        countfreezR++;
                                    if(countfreezR>=50)
                                    {
                                        freezeR=false;
                                        countfreezR=0;
                                    }
                                    }

                                    //punchR
                                    if(PUNCHR && x_R-x_L<=200)
                                    {
                                        freezeL=true;
                                        PUNCHR=false;
                                        loadpowerR=0;

                                    }
                                    if(freezeL)
                                    {
                                        countfreezL++;
                                    if(countfreezL>=50)
                                    {
                                        freezeL=false;
                                        countfreezL=0;
                                    }
                                    }
                                    //invisibleL
                                    if(INVISIBLEBALL && x_L-xb<150 && abs(yb-y_L)<100 )
                                    {
                                        visibility=false;
                                        INVISIBLEBALL=false;
                                        loadpowerL=0;
                                        dy=-20;
                                        dx=50;
                                    }
                                    if(!visibility)
                                    {
                                        countvis++;
                                        if(countvis>=50)
                                        {
                                            visibility=true;
                                            countvis=false;
                                        }
                                    }
                                    //invisibleR
                                    if(INVISIBLEBALR && xb-x_R<150 && abs(yb-y_L)<100)
                                    {
                                        visibility=false;
                                        INVISIBLEBALR=false;
                                        loadpowerR=0;
                                        dy=-20;
                                        dx=-50;
                                    }
                                     if(!visibility)
                                    {
                                        countvis++;
                                        if(countvis>=50)
                                        {
                                            visibility=true;
                                            countvis=false;
                                        }
                                    }
                                    //kick fire ballL
                                    if(KICKFIREBALLL && xb-x_L<150 && abs(yb-y_L)<100)
                                    {
                                        dx=60;
                                        dy=0;
                                        KICKFIREBALLL=false;
                                        fireballL=true;
                                        loadpowerL=0;

                                    }
                                    if(fireballL && xb>=x_R-60 && xb<=x_R+90 /*&& y_R-50<yb && y_R+70>yb*/)
                                    {
                                        x_R+=200;
                                        freezeR=true;
                                        barkhordR=true;
                                        fireballL=false;
                                    }
                                    if(barkhordR)
                                    {
                                        countfireballL++;
                                        if(countfireballL<25)
                                        {
                                            dx-=2;
                                        }
                                        else
                                        {
                                         barkhordR=false;
                                         countfireballL=0;
                                        }
                                    }
                                    if(KICKFIREBALLR && x_R-xb<150 && abs(yb-y_L)<100)
                                    {
                                        dx=-60;
                                        dy=0;
                                        KICKFIREBALLR=false;
                                        fireballR=true;
                                        loadpowerR=0;
                                    }
                                    if(fireballR && xb>x_L-80 && xb<x_L+80 /*&& y_R-50<yb && y_R+70>yb*/)
                                    {
                                        x_L-=200;
                                        freezeL=true;
                                        barkhordL=true;
                                        fireballR=false;
                                    }
                                    if(barkhordL)
                                    {
                                        countfireballR++;
                                        if(countfireballR<25)
                                        {
                                            dx+=2;
                                        }
                                        else
                                        {
                                         barkhordL=false;
                                         countfireballR=0;
                                        }
                                    }
                                    if(fireballL || fireballR)
                                    {
                                        texture(m_renderer,0,750,"fire.png",1280,50);
                                    }
                                    if(TRIPLECLONEL)
                                    {
                                        TRIPLECLONEL=false;
                                        loadpowerL=0;
                                        TRIPL=true;
                                    }
                                    if(TRIPL)
                                    {
                                        counttripl++;
                                        if(counttripl>=50)
                                        {
                                             TRIPL=false;
                                             counttripl=0;
                                        }

                                    }
                                    if(TRIPLECLONER)
                                    {
                                        TRIPLECLONER=false;
                                        loadpowerR=0;
                                        TRIPR=true;
                                    }
                                    if(TRIPR)
                                    {
                                        counttripr++;
                                        if(counttripr>=50)
                                        {
                                            TRIPR=false;
                                            counttripr=0;
                                        }

                                    }
                                    time=(clock()-start)/1000;
                                    //pausetimescore=0;
                                    if(gameend)
                                    {
                                        if(scoreL==scoreR && scoreL==4)
                                        {
                                            game=false;
                                        }
                                        else if(scoreL==5 || scoreR==5)
                                        {
                                            game=false;
                                        }
                                    }
                                    else
                                    {
                                        if(time>=120+pausetime)
                                            game=false;
                                    }
                                    texture(m_renderer,0,0,stadium,1280,800);
                                    texture(m_renderer,0,0,playerL,200,200);
                                    texture(m_renderer,1080,0,playerR,200,200);
                                    texture(m_renderer,545,0,"black.png",190,100);
                                    //show time
                                    int numdigit=2;
                                    int Time=time;
                                    while(Time>0 )
                                    {
                                        if(Time%10==0)
                                        {
                                            texture(m_renderer,565+numdigit*50,0,"noll.png",50,100);
                                            numdigit--;
                                        }
                                        else if(Time%10==1)
                                        {
                                            texture(m_renderer,565+numdigit*50,0,"one.png",50,100);
                                            numdigit--;
                                        }
                                        else if(Time%10==2)
                                        {
                                            texture(m_renderer,565+numdigit*50,0,"two.png",50,100);
                                            numdigit--;
                                        }
                                        else if(Time%10==3)
                                        {
                                            texture(m_renderer,565+numdigit*50,0,"three.png",50,100);
                                            numdigit--;
                                        }
                                        else if(Time%10==4)
                                        {
                                            texture(m_renderer,565+numdigit*50,0,"four.png",50,100);
                                            numdigit--;
                                        }
                                        else if(Time%10==5)
                                        {
                                            texture(m_renderer,565+numdigit*50,0,"five.png",50,100);
                                            numdigit--;
                                        }
                                        else if(Time%10==6)
                                        {
                                            texture(m_renderer,565+numdigit*50,0,"six.png",50,100);
                                            numdigit--;
                                        }
                                        else if(Time%10==7)
                                        {
                                            texture(m_renderer,565+numdigit*50,0,"seven.png",50,100);
                                            numdigit--;
                                        }
                                        else if(Time%10==8)
                                        {
                                            texture(m_renderer,565+numdigit*50,0,"eight.png",50,100);
                                            numdigit--;
                                        }
                                        else if(Time%10==9)
                                        {
                                            texture(m_renderer,565+numdigit*50,0,"nine.png",50,100);
                                            numdigit--;
                                        }
                                          Time/=10;
                                    }
                                    //show time end
                                    //show score
                                    texture(m_renderer,545-50,0,"black2.png",50,100);
                                    texture(m_renderer,545+190,0,"black2.png",50,100);
                                    if(scoreL==0)
                                        texture(m_renderer,545-50,0,"noll.png",50,100);
                                    if(scoreL==1)
                                        texture(m_renderer,545-50,0,"one.png",50,100);
                                    if(scoreL==2)
                                        texture(m_renderer,545-50,0,"two.png",50,100);
                                    if(scoreL==3)
                                        texture(m_renderer,545-50,0,"three.png",50,100);
                                    if(scoreL==4)
                                        texture(m_renderer,545-50,0,"four.png",50,100);
                                    if(scoreL==5)
                                        texture(m_renderer,545-50,0,"five.png",50,100);
                                    if(scoreL==6)
                                        texture(m_renderer,545-50,0,"six.png",50,100);
                                    if(scoreL==7)
                                        texture(m_renderer,545-50,0,"seven.png",50,100);
                                    if(scoreL==8)
                                        texture(m_renderer,545-50,0,"eight.png",50,100);
                                    if(scoreL==9)
                                        texture(m_renderer,545-50,0,"nine.png",50,100);
                                    if(scoreR==0)
                                        texture(m_renderer,545+190,0,"noll.png",50,100);
                                    if(scoreR==1)
                                        texture(m_renderer,545+190,0,"one.png",50,100);
                                    if(scoreR==2)
                                        texture(m_renderer,545+190,0,"two.png",50,100);
                                    if(scoreR==3)
                                        texture(m_renderer,545+190,0,"three.png",50,100);
                                    if(scoreR==4)
                                        texture(m_renderer,545+190,0,"four.png",50,100);
                                    if(scoreR==5)
                                        texture(m_renderer,545+190,0,"five.png",50,100);
                                    if(scoreR==6)
                                        texture(m_renderer,545+190,0,"six.png",50,100);
                                    if(scoreR==7)
                                        texture(m_renderer,545+190,0,"seven.png",50,100);
                                    if(scoreR==8)
                                        texture(m_renderer,545+190,0,"eight.png",50,100);
                                    if(scoreR==9)
                                        texture(m_renderer,545+190,0,"nine.png",50,100);
                                    yf_R=y_R+80;
                                    yf_L=y_L+80;
                                    xf_L=x_L;
                                    xf_R=x_R;
                                    //show score end
                                    texture(m_renderer,0,0,"fan_rest.png",1280,800);
                                    if(visibility)
                                        texture(m_renderer,xb,yb,ball,50,50);
                                    if(t%4==0 || t%4==1)
                                    {
                                        texture(m_renderer,x_L,y_L,playerL,80,80);
                                        if(TRIPL)
                                        {
                                            texture(m_renderer,x_L-100,y_L,playerL,80,80);
                                            texture(m_renderer,x_L+100,y_L,playerL,80,80);
                                        }
                                    }

                                    if(t%4==2 || t%4==3)
                                    {
                                        texture(m_renderer,x_L,y_L-5,playerL,80,80);
                                        if(TRIPL)
                                        {
                                             texture(m_renderer,x_L-100,y_L-5,playerL,80,80);
                                            texture(m_renderer,x_L+100,y_L-5,playerL,80,80);
                                        }
                                    }
                                    if(t%4==0 || t%4==1)
                                    {
                                        texture(m_renderer,x_R,y_R,playerR,80,80);
                                        if(TRIPR)
                                        {
                                         texture(m_renderer,x_R-100,y_R,playerR,80,80);
                                         texture(m_renderer,x_R+100,y_R,playerR,80,80);
                                        }
                                    }
                                    if(t%4==2 || t%4==3)
                                    {
                                        texture(m_renderer,x_R,y_R-5,playerR,80,80);
                                        if(TRIPR)
                                        {
                                          texture(m_renderer,x_R-100,y_R-5,playerR,80,80);
                                         texture(m_renderer,x_R+100,y_R-5,playerR,80,80);
                                        }
                                    }
                                    texture(m_renderer,xf_L,yf_L,shoeL,120,20);
                                    texture(m_renderer,xf_R-40,yf_R,shoeR,120,20);
                                    if(TRIPL)
                                    {
                                    texture(m_renderer,xf_L+100,yf_L,shoeL,120,20);
                                    texture(m_renderer,xf_L-100,yf_L,shoeL,120,20);
                                    }
                                     if(TRIPR)
                                    {
                                    texture(m_renderer,xf_R-100-40,yf_R,shoeR,120,20);
                                    texture(m_renderer,xf_R+100-40,yf_R,shoeR,120,20);
                                    }
                                    //powerloadingStart

                                    loadpowerL+=2;
                                    if(loadpowerL<750)
                                    {
                                        //loadpowerL++;
                                        if(loadpowerL>=0 && loadpowerL<150)
                                            texture(m_renderer,200,0,"0load.png",200,200);
                                        if(loadpowerL>=150 && loadpowerL<300)
                                            texture(m_renderer,200,0,"20load.png",200,200);
                                        if(loadpowerL>=300 && loadpowerL<450)
                                            texture(m_renderer,200,0,"40load.png",200,200);
                                        if(loadpowerL>=450 && loadpowerL<600)
                                            texture(m_renderer,200,0,"60load.png",200,200);
                                        if(loadpowerL>=600 && loadpowerL<750)
                                            texture(m_renderer,200,0,"80load.png",200,200);
                                    }
                                    if(loadpowerL>=750)
                                    {
                                        texture(m_renderer,200,0,"100load.png",200,200);
                                        powerL=true;
                                    }
                                    loadpowerR+=2;
                                    if(loadpowerR<750)
                                    {
                                        //loadpowerL++;
                                        if(loadpowerR>=0 && loadpowerR<150)
                                            texture(m_renderer,880,0,"0load.png",200,200);
                                        if(loadpowerR>=150 && loadpowerR<300)
                                            texture(m_renderer,880,0,"20load.png",200,200);
                                        if(loadpowerR>=300 && loadpowerR<450)
                                            texture(m_renderer,880,0,"40load.png",200,200);
                                        if(loadpowerR>=450 && loadpowerR<600)
                                            texture(m_renderer,880,0,"60load.png",200,200);
                                        if(loadpowerR>=600 && loadpowerR<750)
                                            texture(m_renderer,880,0,"80load.png",200,200);
                                    }
                                    if(loadpowerR>=750)
                                    {
                                        texture(m_renderer,880,0,"100load.png",200,200);
                                        powerR=true;
                                    }
                                    ///gamerules
                                    //jump
                                    if(y_L==595 || y_L==590 || y_L==585 || y_L==580 || y_L==575 || y_L==570 || y_L==565 || y_L==560 || y_L==555 || y_L==550 || y_L==545 || y_L==540 || y_L==535 || y_L==530 || y_L==525 || y_L==520 ||y_L==515 )
                                        y_L-=5;
                                    if(y_L==510)
                                        y_L-=6;
                                    if(y_L==504 || y_L==509 || y_L==514 || y_L==519 || y_L==524 || y_L==529 || y_L==534 || y_L==539 || y_L==544 || y_L==549 || y_L==554 || y_L==559 || y_L==564 || y_L==569 || y_L==574 || y_L==579 || y_L==584 || y_L==589 )
                                        y_L+=5;
                                    if(y_L==594)
                                        y_L+=6;
                                    if(y_R==595 || y_R==590 || y_R==585 || y_R==580 || y_R==575 || y_R==570 || y_R==565 || y_R==560 || y_R==555 || y_R==550 || y_R==545 ||y_R==540|| y_R==535 || y_R==530 || y_R==525 || y_R==520 ||y_R==515 )
                                        y_R-=5;
                                    if(y_R==510)
                                        y_R-=6;
                                    if(y_R==504 || y_R==509 || y_R==514 || y_R==519 || y_R==524 || y_R==529 || y_R==534 || y_R==539 || y_R==544 || y_R==549 || y_R==554 || y_R==559 || y_R==564 || y_R==569 || y_R==574 || y_R==579 || y_R==584 || y_R==589 )
                                        y_R+=5;
                                    if(y_R==594)
                                        y_R+=6;
                                    //jump
                                    //barkhord top ba divarha va tirha
                                    if(xb>55 && xb<170 && yb<400 && yb>340 && dx<0)
                                        dx=-dx;
                                    if(xb>1140 && xb<1255 && yb<400 && yb>340 && dx>0)
                                        dx=-dx;
                                    if(xb<=20 || xb>=1230)
                                        dx=-dx;
                                    if(yb<=100)
                                        dy=-dy;
                                        //barkhord top ba divar va tirha
                                        //balll
                                        yb+=dy;
                                        dy+=1.5;
                                        if (yb>650 && dy!=0)
                                        {
                                        if (dy<=3 && dy>0)
                                        {
                                        dy=0;
                                        }
                                        else dy=(-0.6)*dy;
                                        }
                                        if (yb>700 && dy==0)
                                            yb=650;

                                        xb+=dx;
                                        dx-=1.5;
                                        if ( (dx<=3 && dx>0) || (dx>=-3 && dx<0) )
                                            dx=0;
                                        if( (xb<=40 || xb>=1200) && yb>=460)
                                        dx=0;
                                        if(game==false)
                                        {
                                            dx=0;
                                            dy=0;
                                        }
                                        //ball
                                        //goal
                                        if(xb<=40 && yb>=460)
                                            {
                                                if(SAKHREL==false)
                                                {
                                                Mix_PlayChannel(-1,Whistle,0);
                                                scoreR++;
                                                loadpowerR+=500;
                                                x_L=80;
                                                y_L=600;
                                                x_R=1280-160;
                                                y_L=600;
                                                xb=625;
                                                yb=215;
                                                dy=10;
                                                dx=0;
                                                celebgoalR=true;
                                                }
                                                else
                                                {
                                                    dx=-dx;
                                                    dy=-dy;
                                                }
                                            }
                                            if(xb>=1200 && yb>=460)
                                            {
                                                if(SAKHRER==false)
                                                {
                                                 Mix_PlayChannel(-1,Whistle,0);
                                                scoreL++;
                                                loadpowerL+=500;
                                                x_L=80;
                                                y_L=600;
                                                x_R=1280-160;
                                                y_L=600;
                                                xb=625;
                                                yb=215;
                                                dy=10;
                                                dx=0;
                                                celebgoalR=true;
                                                }
                                                else
                                                {
                                                    dx=-dx;
                                                    dy=-dy;
                                                }

                                            }
                                            if(SAKHREL)
                                            {
                                                texture(m_renderer,33,410,"rock.png",146-33,683-410);
                                            }
                                            if(SAKHRER)
                                            {
                                                texture(m_renderer,1127,417,"rock.png",1238-1127,683-417);
                                            }
                                            //
                                            if(time==45 && Avazi)
                                            {
                                                Mix_PlayChannel(-1,avazi,0);
                                                Avazi=false;
                                            }
                                            if(time==90 && Topoli)
                                            {
                                                Mix_PlayChannel(-1,topoli,0);
                                                Topoli=false;
                                            }

                                            if(xb+50>x_R-10 && xb+50<x_R+20 && yb-45<y_R-10 && yb-45>y_R-120)
                                                {
                                                    dx-=5;
                                                    dx=-dx;
                                                }///barkhord toop ba harif
                                            if(TRIPR)
                                            {
                                            if(xb+50>x_R+100-10 && xb+50<x_R+100+20 && yb-45<y_R+100-10 && yb-45>y_R+100-120)
                                                {
                                                    dx-=5;
                                                    dx=-dx;
                                                }
                                            if(xb+50>x_R-100-10 && xb+50<x_R-100+20 && yb-45<y_R-100-10 && yb-45>y_R-100-120)
                                                {
                                                    dx-=5;
                                                    dx=-dx;
                                                }

                                            }
                                            if(xb-20<x_L+40 && xb-20>x_L+10 && yb-45<y_L-10 && yb-45>y_L-120)
                                                {
                                                    dx+=5;
                                                    dx=-dx;
                                                }///barkhord toop ba harif
                                                if(TRIPL)
                                                {
                                                if(xb-20<x_L+100+40 && xb-20>x_L+100+10 && yb-45<y_L+100-10 && yb-45>y_L+100-120)
                                                {
                                                    dx+=5;
                                                    dx=-dx;
                                                }
                                            if(xb-20<x_L-100+40 && xb-20>x_L-100+10 && yb-45<y_L-100-10 && yb-45>y_L-100-120)
                                                {
                                                    dx+=5;
                                                    dx=-dx;
                                                }
                                                }

                                            if(shootR && x_R-30<xb+70 && x_R-30>xb+20 && yb>600)
                                                {
                                                    dy=-20;
                                                    dx=-50;
                                                }///shootR noke pa
                                            else if(shootR && x_R-30<xb+70 && x_R-30>xb+20 && yb<600)
                                                {
                                                    dy=-20;
                                                    dx=-15;
                                                }///shootR rooye pa
                                            if(TRIPR)
                                            {
                                            if(shootR && x_R+100-30<xb+70 && x_R+100-30>xb+20 && yb>600)
                                                {
                                                    dy=-20;
                                                    dx=-50;
                                                }
                                            else if(shootR && x_R+100-30<xb+70 && x_R+100-30>xb+20 && yb<600)
                                                {
                                                    dy=-20;
                                                    dx=-15;
                                                }
                                            if(shootR && x_R-100-30<xb+70 && x_R-100-30>xb+20 && yb>600)
                                                {
                                                    dy=-20;
                                                    dx=-50;
                                                }
                                            else if(shootR && x_R-100-30<xb+70 && x_R-100-30>xb+20 && yb<600)
                                                {
                                                    dy=-20;
                                                    dx=-15;
                                                }
                                            }
                                            if(shootL && x_L+80>xb-30 && x_L+80<xb && yb>600)
                                                {
                                                    dy=-20;
                                                    dx=50;
                                                }///shootL noke pa
                                            else if(shootL && x_L+80>xb-30 && x_L+80<xb && yb<600)
                                                {
                                                dy=-20;
                                                dx=15;
                                                }///shootL rooye pa
                                                if(TRIPL)
                                                {
                                             if(shootL && x_L+100+80>xb-30 && x_L+100+80<xb && yb>600)
                                                {
                                                    dy=-20;
                                                    dx=50;
                                                }
                                             else if(shootL && x_L+100+80>xb-30 && x_L+100+80<xb && yb<600)
                                                {
                                                dy=-20;
                                                dx=15;
                                                }
                                             if(shootL && x_L-100+80>xb-30 && x_L-100+80<xb && yb>600)
                                                {
                                                    dy=-20;
                                                    dx=50;
                                                }
                                             else if(shootL && x_L-100+80>xb-30 && x_L-100+80<xb && yb<600)
                                                {
                                                dy=-20;
                                                dx=15;
                                                }
                                                }


                                                ///movement of the ball
                                                if(x_R>=xb+65 && x_R<=xb+75 && (xb-15>x_L+80||xb<x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball1.png")
                                                        {
                                                        Mix_PlayChannel(-1,kick,0);
                                                        xb-=15;
                                                        ball="ball3.png";
                                                        }
                                                if(x_R>=xb+65 && x_R<=xb+75 && (xb-15>x_L+80||xb<x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball2.png")
                                                    {
                                                    Mix_PlayChannel(-1,kick,0);
                                                    xb-=15;
                                                    ball="ball4.png";
                                                    }
                                                if(x_R>=xb+65 && x_R<=xb+75 && (xb-15>x_L+80||xb<x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball3.png")
                                                {
                                                    Mix_PlayChannel(-1,kick,0);
                                                    xb-=15;
                                                    ball="ball1.png";
                                                    }
                                                if(x_R>=xb+65 && x_R<=xb+75 && (xb-15>x_L+80||xb<x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball4.png")
                                                {
                                                Mix_PlayChannel(-1,kick,0);
                                                xb-=15;
                                                ball="ball2.png";
                                                }

                                                if(x_R<=xb-55 && x_R>=xb-65 && (xb+15<x_L-50||xb>x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball1.png" && xb!=1210)
                                                    {
                                                        Mix_PlayChannel(-1,kick,0);
                                                    xb+=15;
                                                    ball="ball3.png";
                                                    }
                                                if(x_R<=xb-55 && x_R>=xb-65 && (xb+15<x_L-50||xb>x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball2.png" && xb!=1210)
                                                    {
                                                    Mix_PlayChannel(-1,kick,0);
                                                    xb+=15;
                                                    ball="ball4.png";
                                                    }
                                                if(x_R<=xb-55 && x_R>=xb-65 && (xb+15<x_L-50||xb>x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball3.png" && xb!=1210)
                                                    {
                                                    Mix_PlayChannel(-1,kick,0);
                                                    xb+=15;
                                                    ball="ball1.png";
                                                    }
                                                if(x_R<=xb-55 && x_R>=xb-65 && (xb+15<x_L-50||xb>x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball4.png" && xb!=1210)
                                                {
                                                Mix_PlayChannel(-1,kick,0);
                                                xb+=15;
                                                ball="ball2.png";
                                                }

                                                if(x_L>=xb+45 && x_L<=xb+55 && (xb-15>x_R+60||xb<x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball1.png" && xb!=40)
                                                        {
                                                        Mix_PlayChannel(-1,kick,0);
                                                        xb-=15;
                                                         ball="ball3.png";
                                                         }
                                                if(x_L>=xb+45 && x_L<=xb+55 && (xb-15>x_R+60||xb<x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball2.png" && xb!=40)
                                                {
                                                Mix_PlayChannel(-1,kick,0);
                                                xb-=15;
                                                ball="ball4.png";
                                                }
                                                if(x_L>=xb+45 && x_L<=xb+55 && (xb-15>x_R+60||xb<x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball3.png" && xb!=40)
                                                {
                                                    Mix_PlayChannel(-1,kick,0);
                                                    xb-=15;
                                                     ball="ball1.png";
                                                }
                                                if(x_L>=xb+45 && x_L<=xb+55 && (xb-15>x_R+60||xb<x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball4.png" && xb!=40)
                                                {
                                                Mix_PlayChannel(-1,kick,0);
                                                xb-=15;
                                                ball="ball2.png";
                                                }

                                                if(x_L<=xb-80 && x_L>=xb-90 && (xb+15<x_R-70||xb>x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball1.png")
                                                        {
                                                        Mix_PlayChannel(-1,kick,0);
                                                        xb+=15;
                                                        ball="ball3.png";
                                                        }
                                                if(x_L<=xb-80 && x_L>=xb-90 && (xb+15<x_R-70||xb>x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball2.png")
                                                    {
                                                    Mix_PlayChannel(-1,kick,0);
                                                    xb+=15;
                                                    ball="ball4.png";
                                                    }
                                                if(x_L<=xb-80 && x_L>=xb-90 && (xb+15<x_R-70||xb>x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball3.png")
                                                    {
                                                    Mix_PlayChannel(-1,kick,0);
                                                    xb+=15;
                                                    ball="ball1.png";
                                                    }
                                                if(x_L<=xb-80 && x_L>=xb-90 && (xb+15<x_R-70||xb>x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball4.png")
                                                    {
                                                    Mix_PlayChannel(-1,kick,0);
                                                    xb+=15;
                                                    ball="ball2.png";
                                                    }
                                                ///movment of ball
                                                ///tripleclone R start
                                                if(TRIPR)
                                                {
                                                    //-100
                                                    if(x_R-100>=xb+65 && x_R-100<=xb+75 && (xb-15>x_L+80||xb<x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball1.png")
                                                    {
                                                            Mix_PlayChannel(-1,kick,0);
                                                            xb-=15;
                                                            ball="ball3.png";
                                                    }
                                                    if(x_R-100>=xb+65 && x_R-100<=xb+75 && (xb-15>x_L+80||xb<x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball3.png") {Mix_PlayChannel(-1,kick,0);xb-=15;ball="ball1.png";}
                                                    if(x_R-100>=xb+65 && x_R-100<=xb+75 && (xb-15>x_L+80||xb<x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball4.png") {Mix_PlayChannel(-1,kick,0);xb-=15;ball="ball2.png";}
                                                    if(x_R-100>=xb+65 && x_R-100<=xb+75 && (xb-15>x_L+80||xb<x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball2.png") {Mix_PlayChannel(-1,kick,0);xb-=15;ball="ball4.png";}

                                                    if(x_R-100<=xb-55 && x_R-100>=xb-65 && (xb+15<x_L-50||xb>x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball1.png" && xb!=1210) {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball3.png";}
                                                    if(x_R-100<=xb-55 && x_R-100>=xb-65 && (xb+15<x_L-50||xb>x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball3.png" && xb!=1210) {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball1.png";}
                                                    if(x_R-100<=xb-55 && x_R-100>=xb-65 && (xb+15<x_L-50||xb>x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball2.png" && xb!=1210) {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball4.png";}
                                                    if(x_R-100<=xb-55 && x_R-100>=xb-65 && (xb+15<x_L-50||xb>x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball4.png" && xb!=1210) {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball2.png";}
                                                    //+100
                                                     if(x_R+100>=xb+65 && x_R+100<=xb+75 && (xb-15>x_L+80||xb<x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball1.png") {Mix_PlayChannel(-1,kick,0);xb-=15;ball="ball3.png";}
                                                    if(x_R+100>=xb+65 && x_R+100<=xb+75 && (xb-15>x_L+80||xb<x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball3.png") {Mix_PlayChannel(-1,kick,0);xb-=15;ball="ball1.png";}
                                                    if(x_R+100>=xb+65 && x_R+100<=xb+75 && (xb-15>x_L+80||xb<x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball4.png") {Mix_PlayChannel(-1,kick,0);xb-=15;ball="ball2.png";}
                                                    if(x_R+100>=xb+65 && x_R+100<=xb+75 && (xb-15>x_L+80||xb<x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball2.png") {Mix_PlayChannel(-1,kick,0);xb-=15;ball="ball4.png";}

                                                    if(x_R+100<=xb-55 && x_R+100>=xb-65 && (xb+15<x_L-50||xb>x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball1.png" && xb!=1210) {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball3.png";}
                                                    if(x_R+100<=xb-55 && x_R+100>=xb-65 && (xb+15<x_L-50||xb>x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball3.png" && xb!=1210) {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball1.png";}
                                                    if(x_R+100<=xb-55 && x_R+100>=xb-65 && (xb+15<x_L-50||xb>x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball2.png" && xb!=1210) {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball4.png";}
                                                    if(x_R+100<=xb-55 && x_R+100>=xb-65 && (xb+15<x_L-50||xb>x_L) && y_R<yb-25 && y_R>yb-85 && ball=="ball4.png" && xb!=1210) {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball2.png";}

                                                }
                                                ///triplecloneR end
                                                ///triplecloneL start
                                                if(TRIPL)
                                                {
                                                    //+100
                                                    if(x_L+100>=xb+45 && x_L+100<=xb+55 && (xb-15>x_R+60||xb<x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball1.png" && xb!=40) {Mix_PlayChannel(-1,kick,0);xb-=15; ball="ball3.png";}
                                                    if(x_L+100>=xb+45 && x_L+100<=xb+55 && (xb-15>x_R+60||xb<x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball3.png" && xb!=40) {Mix_PlayChannel(-1,kick,0);xb-=15; ball="ball1.png";}
                                                    if(x_L+100>=xb+45 && x_L+100<=xb+55 && (xb-15>x_R+60||xb<x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball2.png" && xb!=40) {Mix_PlayChannel(-1,kick,0);xb-=15; ball="bal4.png";}
                                                    if(x_L+100>=xb+45 && x_L+100<=xb+55 && (xb-15>x_R+60||xb<x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball4.png" && xb!=40) {Mix_PlayChannel(-1,kick,0);xb-=15; ball="ball2.png";}

                                                    if(x_L+100<=xb-80 && x_L+100>=xb-90 && (xb+15<x_R-70||xb>x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball1.png") {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball3.png";}
                                                    if(x_L+100<=xb-80 && x_L+100>=xb-90 && (xb+15<x_R-70||xb>x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball3.png") {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball1.png";}
                                                    if(x_L+100<=xb-80 && x_L+100>=xb-90 && (xb+15<x_R-70||xb>x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball2.png") {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball4.png";}
                                                    if(x_L+100<=xb-80 && x_L+100>=xb-90 && (xb+15<x_R-70||xb>x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball4.png") {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball2.png";}
                                                    //-100
                                                    if(x_L-100>=xb+45 && x_L-100<=xb+55 && (xb-15>x_R+60||xb<x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball1.png" && xb!=40) {Mix_PlayChannel(-1,kick,0);xb-=15; ball="ball3.png";}
                                                    if(x_L-100>=xb+45 && x_L-100<=xb+55 && (xb-15>x_R+60||xb<x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball3.png" && xb!=40) {Mix_PlayChannel(-1,kick,0);xb-=15; ball="ball1.png";}
                                                    if(x_L-100>=xb+45 && x_L-100<=xb+55 && (xb-15>x_R+60||xb<x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball2.png" && xb!=40) {Mix_PlayChannel(-1,kick,0);xb-=15; ball="bal4.png";}
                                                    if(x_L-100>=xb+45 && x_L-100<=xb+55 && (xb-15>x_R+60||xb<x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball4.png" && xb!=40) {Mix_PlayChannel(-1,kick,0);xb-=15; ball="ball2.png";}

                                                    if(x_L-100<=xb-80 && x_L-100>=xb-90 && (xb+15<x_R-70||xb>x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball1.png") {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball3.png";}
                                                    if(x_L-100<=xb-80 && x_L-100>=xb-90 && (xb+15<x_R-70||xb>x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball3.png") {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball1.png";}
                                                    if(x_L-100<=xb-80 && x_L-100>=xb-90 && (xb+15<x_R-70||xb>x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball2.png") {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball4.png";}
                                                    if(x_L-100<=xb-80 && x_L-100>=xb-90 && (xb+15<x_R-70||xb>x_R) && y_L<yb-25 && y_L>yb-85 && ball=="ball4.png") {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball2.png";}
                                                }
                                                ///triplecloneL end





                                            //setare freez
                                            if(freezeL)
                                            {
                                                if(countfreezL%4==0 || countfreezL%4==1)
                                                {
                                                    texture(m_renderer,x_L,y_L-80,"star2.png",80,40);
                                                }
                                                else
                                                {
                                                    texture(m_renderer,x_L,y_L-80,"star1.png",80,40);
                                                }
                                            }
                                            if(freezeR)
                                            {
                                                if(countfreezR%4==0 || countfreezR%4==1)
                                                {
                                                    texture(m_renderer,x_R,y_R-80,"star2.png",80,40);
                                                }
                                                else
                                                {
                                                    texture(m_renderer,x_R,y_R-80,"star1.png",80,40);
                                                }
                                            }

                                            ///Nitro
                                            if(time>=70 && time<=80 && Nitro)
                                            {
                                                int xnitro=640-15;
                                                int ynitro=700-50;
                                                if(t%2==0)
                                                    texture(m_renderer,xnitro,ynitro,"nitro.png",30,50);
                                                if(t%2==1)
                                                    texture(m_renderer,xnitro,ynitro-2,"nitro.png",30,50);
                                                if(xnitro<=x_L+80 && x_L<=xnitro+30 )
                                                {
                                                    loadpowerL+=300;

                                                    Nitro=false;
                                                }
                                                if(xnitro+30>=x_R && x_R>=xnitro-80 )
                                                {
                                                    loadpowerR+=300;

                                                    Nitro=false;
                                                }
                                            }
                                            if(time>=71 && time<=72)
                                            {
                                                Nitro=true;
                                            }
                                            if(time>=90 && time<=100 && Nitro)
                                            {
                                                int xnitro=640-15-200;
                                                int ynitro=700-50;
                                                if(t%2==0)
                                                    texture(m_renderer,xnitro,ynitro,"nitro.png",30,50);
                                                if(t%2==1)
                                                    texture(m_renderer,xnitro,ynitro-2,"nitro.png",30,50);
                                                if(xnitro<=x_L+80 && x_L<=xnitro+30 )
                                                {
                                                    loadpowerL+=300;

                                                    Nitro=false;
                                                }
                                                if(xnitro+30>=x_R && x_R>=xnitro-80)
                                                {
                                                    loadpowerR+=300;

                                                    Nitro=false;
                                                }
                                            }
                                            if(time>=101 && time<=102)
                                            {
                                                Nitro=true;
                                            }
                                            if(time>=110 && time<=120 && Nitro)
                                            {
                                                int xnitro=640-15+200;
                                                int ynitro=700-50;
                                                if(t%2==0)
                                                    texture(m_renderer,xnitro,ynitro,"nitro.png",30,50);
                                                if(t%2==1)
                                                    texture(m_renderer,xnitro,ynitro-2,"nitro.png",30,50);
                                                if(xnitro<=x_L+80 && x_L<=xnitro+30 )
                                                {
                                                    loadpowerL+=300;

                                                    Nitro=false;
                                                }
                                                if(xnitro+30>=x_R && x_R>=xnitro-80 )
                                                {
                                                    loadpowerR+=300;

                                                    Nitro=false;
                                                }
                                            }
                                            if(time>=121 && time<=122)
                                            {
                                                Nitro=true;
                                            }
                                            if(time>=30 && time<=40 && Nitro)
                                            {
                                                int xnitro=640-15-200;
                                                int ynitro=700-50;
                                                if(t%2==0)
                                                    texture(m_renderer,xnitro,ynitro,"nitro.png",30,50);
                                                if(t%2==1)
                                                    texture(m_renderer,xnitro,ynitro-2,"nitro.png",30,50);
                                                if(xnitro<=x_L+80 && x_L<=xnitro+30 )
                                                {
                                                    loadpowerL+=300;

                                                    Nitro=false;
                                                }
                                                if(xnitro+30>=x_R && x_R>=xnitro-80 )
                                                {
                                                    loadpowerR+=300;

                                                    Nitro=false;
                                                }
                                            }
                                            if(time>=41 && time<=42)
                                            {
                                                Nitro=true;
                                            }
                                             if(time>=43 && time<=53 && Nitro)
                                            {
                                                int xnitro=640-15+200;
                                                int ynitro=700-50;
                                                if(t%2==0)
                                                    texture(m_renderer,xnitro,ynitro,"nitro.png",30,50);
                                                if(t%2==1)
                                                    texture(m_renderer,xnitro,ynitro-2,"nitro.png",30,50);
                                                if(xnitro<=x_L+80 && x_L<=xnitro+30 )
                                                {
                                                    loadpowerL+=300;

                                                    Nitro=false;
                                                }
                                                if(xnitro+30>=x_R && x_R>=xnitro-80 )
                                                {
                                                    loadpowerR+=300;

                                                    Nitro=false;
                                                }
                                            }
                                            if(time>=54 && time<=55)
                                            {
                                                Nitro=true;
                                            }
                                            ///NItro
                                     if(fireballL || fireballR)
                                    {
                                        texture(m_renderer,0,600,"fire.png",1280,200);
                                    }







                                    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
                                    SDL_PollEvent(e);
                                    if(e->type == SDL_KEYDOWN || e->type == SDL_KEYUP)
                                    {
                                        if(keyboard_state_array[SDL_SCANCODE_A] && !freezeL)
                                        {
                                            if( x_L>=-10 )
                                                x_L-=5;

                                        }
                                         if(keyboard_state_array[SDL_SCANCODE_D] && !freezeL)
                                        {
                                            if(x_R+5>=x_L+80 && x_L+80<1290)
                                                x_L+=5;

                                        }
                                        if(keyboard_state_array[SDL_SCANCODE_W] && !freezeL)
                                        {
                                            y_L-=5;

                                        }
                                         if(keyboard_state_array[SDL_SCANCODE_S] && !freezeL)
                                        {
                                            shootL=true;



                                        }
                                        if(keyboard_state_array[SDL_SCANCODE_Q])//power
                                        {
                                            powerrL=true;

                                        }
                                       if(keyboard_state_array[SDL_SCANCODE_B])//TAGHALOB LEFT
                                        {
                                            SAKHREL=true;

                                        }
                                        if(keyboard_state_array[SDL_SCANCODE_UP] && !freezeR)
                                        {
                                            y_R-=5;

                                        }
                                         if(keyboard_state_array[SDL_SCANCODE_DOWN] && !freezeR)
                                        {
                                            shootR=true;


                                        }
                                         if(keyboard_state_array[SDL_SCANCODE_LEFT] && !freezeR)
                                        {
                                            if( x_R>=-9 && x_R-80>=x_L)
                                                x_R-=5;
                                        }
                                         if(keyboard_state_array[SDL_SCANCODE_RIGHT] && !freezeR)
                                        {
                                            if( x_R+80<=1290)
                                                x_R+=5;
                                        }
                                         if(keyboard_state_array[SDL_SCANCODE_P])
                                        {
                                            powerrR=true;

                                        }
                                         if(keyboard_state_array[SDL_SCANCODE_L])///TAGHALOB RIGHT
                                        {
                                            SAKHRER=true;

                                        }
                                         if(keyboard_state_array[SDL_SCANCODE_ESCAPE])///PAUSE!
                                        {
                                            pause=true;
                                        }
                                    }
                                    SDL_RenderPresent(m_renderer);








                                    //powerloadingEnd























                                    if(game==false)
                                    {
                                        Mix_PlayChannel(-1,Whistle,0);

                                        //SABT NATEYEJ
                                        if(gameend)
                                        {
                                            if(scoreL==scoreR)///draw
                                            {
                                                natije="draw";
                                                games[Searchplayer(names,nameL)]++;
                                                draws[Searchplayer(names,nameL)]++;
                                                GAs[Searchplayer(names,nameL)]+=scoreR;
                                                GFs[Searchplayer(names,nameL)]+=scoreL;
                                                points[Searchplayer(names,nameL)]++;
                                                games[Searchplayer(names,nameR)]++;
                                                draws[Searchplayer(names,nameR)]++;
                                                GAs[Searchplayer(names,nameR)]+=scoreL;
                                                GFs[Searchplayer(names,nameR)]+=scoreR;
                                                points[Searchplayer(names,nameR)]++;
                                            }
                                            else if(scoreL==5)///winL
                                            {
                                                natije="winL";
                                                games[Searchplayer(names,nameL)]++;
                                                wins[Searchplayer(names,nameL)]++;
                                                GAs[Searchplayer(names,nameL)]+=scoreR;
                                                GFs[Searchplayer(names,nameL)]+=scoreL;
                                                GDs[Searchplayer(names,nameL)]+=(scoreL-scoreR);
                                                points[Searchplayer(names,nameL)]+=3;
                                                games[Searchplayer(names,nameR)]++;
                                                lose[Searchplayer(names,nameR)]++;
                                                GAs[Searchplayer(names,nameR)]+=scoreL;
                                                GFs[Searchplayer(names,nameR)]+=scoreR;
                                                GDs[Searchplayer(names,nameR)]+=(scoreR-scoreL);


                                            }
                                            else if(scoreR==5)///winR
                                            {
                                                natije="winR";
                                                games[Searchplayer(names,nameR)]++;
                                                wins[Searchplayer(names,nameR)]++;
                                                GAs[Searchplayer(names,nameR)]+=scoreL;
                                                GFs[Searchplayer(names,nameR)]+=scoreR;
                                                GDs[Searchplayer(names,nameR)]+=(scoreR-scoreL);
                                                points[Searchplayer(names,nameR)]+=3;
                                                games[Searchplayer(names,nameL)]++;
                                                lose[Searchplayer(names,nameL)]++;
                                                GAs[Searchplayer(names,nameL)]+=scoreR;
                                                GFs[Searchplayer(names,nameL)]+=scoreL;
                                                GDs[Searchplayer(names,nameL)]+=(scoreL-scoreR);
                                            }
                                        }
                                        else
                                        {
                                            if(scoreL>scoreR)///winL
                                            {
                                                natije="winL";
                                                games[Searchplayer(names,nameL)]++;
                                                wins[Searchplayer(names,nameL)]++;
                                                GAs[Searchplayer(names,nameL)]+=scoreR;
                                                GFs[Searchplayer(names,nameL)]+=scoreL;
                                                GDs[Searchplayer(names,nameL)]+=(scoreL-scoreR);
                                                points[Searchplayer(names,nameL)]+=3;
                                                games[Searchplayer(names,nameR)]++;
                                                lose[Searchplayer(names,nameR)]++;
                                                GAs[Searchplayer(names,nameR)]+=scoreL;
                                                GFs[Searchplayer(names,nameR)]+=scoreR;
                                                GDs[Searchplayer(names,nameR)]+=(scoreR-scoreL);

                                            }
                                            else if(scoreL<scoreR)///winR
                                            {
                                                natije="winR";
                                                games[Searchplayer(names,nameR)]++;
                                                wins[Searchplayer(names,nameR)]++;
                                                GAs[Searchplayer(names,nameR)]+=scoreL;
                                                GFs[Searchplayer(names,nameR)]+=scoreR;
                                                GDs[Searchplayer(names,nameR)]+=(scoreR-scoreL);
                                                points[Searchplayer(names,nameR)]+=3;

                                                games[Searchplayer(names,nameL)]++;
                                                lose[Searchplayer(names,nameL)]++;
                                                GAs[Searchplayer(names,nameL)]+=scoreR;
                                                GFs[Searchplayer(names,nameL)]+=scoreL;
                                                GDs[Searchplayer(names,nameL)]+=(scoreL-scoreR);
                                            }
                                            else if(scoreL==scoreR)
                                            {
                                                natije="draw";
                                                games[Searchplayer(names,nameL)]++;
                                                draws[Searchplayer(names,nameL)]++;
                                                GAs[Searchplayer(names,nameL)]+=scoreR;
                                                GFs[Searchplayer(names,nameL)]+=scoreL;
                                                points[Searchplayer(names,nameL)]++;
                                                games[Searchplayer(names,nameR)]++;
                                                draws[Searchplayer(names,nameR)]++;
                                                GAs[Searchplayer(names,nameR)]+=scoreL;
                                                GFs[Searchplayer(names,nameR)]+=scoreR;
                                                points[Searchplayer(names,nameR)]++;
                                            }
                                        }
                                        if(natije=="draw")
                                        {
                                            texture(m_renderer,0,0,stadium,1280,800);
                                            texture(m_renderer,80,625,playerL,80,80);
                                            texture(m_renderer,1280-160,625,playerR,80,80);
                                            texture(m_renderer,440,300,"Draw.png",400,200);
                                            texture(m_renderer,440,200,playerR,100,100);
                                            texture(m_renderer,740,200,playerL,100,100);
                                            SDL_RenderPresent(m_renderer);
                                            SDL_Delay(3000);


                                        }
                                        else if(natije=="winR")
                                        {
                                            Mix_PlayChannel(-1,winnersound,0);
                                        for(int i=0;i<10;i++)
                                        {
                                            texture(m_renderer,0,0,stadium,1280,800);
                                            texture(m_renderer,80,625,playerL,80,80);
                                            texture(m_renderer,1280-160,625,playerR,80,80);
                                            texture(m_renderer,0,-400+i*100,"celebration.png",1280,800);
                                            texture(m_renderer,440,300,"winright.png",400,200);
                                            texture(m_renderer,590,200,playerR,100,100);
                                            texture(m_renderer,590,150,"crown.png",100,50);
                                            SDL_RenderPresent(m_renderer);
                                            SDL_Delay(300);
                                        }
                                        }
                                        else if(natije=="winL")
                                        {
                                            Mix_PlayChannel(-1,winnersound,0);
                                        for(int i=0;i<10;i++)
                                        {
                                            texture(m_renderer,0,0,stadium,1280,800);
                                            texture(m_renderer,80,625,playerL,80,80);
                                            texture(m_renderer,1280-160,625,playerR,80,80);
                                            texture(m_renderer,0,-400+i*100,"celebration.png",1280,800);
                                            texture(m_renderer,440,300,"winleft.png",400,200);
                                            texture(m_renderer,590,200,playerL,100,100);
                                            texture(m_renderer,590,150,"crown.png",100,50);
                                            SDL_RenderPresent(m_renderer);
                                            SDL_Delay(300);
                                        }
                                        }






                                    }
                                }
                                game=true;
                                Avazi=true;
                                Topoli=true;

                               if(!ahang)
                                {
                                Mix_PlayMusic(GameSound1,-1);
                                Mix_ResumeMusic();
                                channgmmusic=1;
                                }
                                }
                            }
                            }
                            backmainmenu2=false;
                        }
                    }
                }
                texture(m_renderer,0,0,"Enterplayer.png",1280,800);
                SDL_RenderPresent(m_renderer);
                backgamemenu1=false;
            }
        }
        }
        backmainmenu=false;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////main part
    else if(xmouse>=57 && xmouse<=303 && ymouse>=295 && ymouse<=357 )//about us
    {
        Mix_PlayChannel(-1,click,0);
        cout<<"about us"<<endl;
        while(!backmainmenu)
        {
        texture(m_renderer,0,0,"aboutus.png",1280,800);
        SDL_RenderPresent(m_renderer);
        SDL_PollEvent(e);
        if(e->type == SDL_MOUSEBUTTONDOWN)
        {
            xmouse=e->button.x;
            ymouse=e->button.y;
            if(xmouse>=19 && xmouse<=223 && ymouse>=18 && ymouse<=63 )//mainmenu
            {
                Mix_PlayChannel(-1,click,0);
                cout<<"backmainmenu"<<endl;
                backmainmenu=true;
            }
        }
        }
        backmainmenu=false;
    }

    }

    }
    ofstream Filename("name.txt");
    ofstream Filewin("win.txt");
    ofstream Filelose("lose.txt");
    ofstream Filedraw("draw.txt");
    ofstream FileGF("GF.txt");
    ofstream FileGA("GA.txt");
    for(int i=0;i<Count;i++)
    {
        Filename<<names[i];
        Filename<<endl;
        Filewin<<wins[i];
        Filewin<<endl;
        Filelose<<lose[i];
        Filelose<<endl;
        Filedraw<<draws[i];
        Filedraw<<endl;
        FileGF<<GFs[i];
        FileGF<<endl;
        FileGA<<GAs[i];
        FileGA<<endl;

    }
    Filename.close();
    Filedraw.close();
    Filewin.close();
    Filelose.close();
    FileGF.close();
    FileGA.close();






    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	IMG_Quit();
	SDL_Quit();
    return 0;

}
void texture(SDL_Renderer *m_renderer,int xp,int yp,string addressOfImage,int width,int height)
{
        int n = addressOfImage.length();
        char char_array[n+1];

        strcpy(char_array, addressOfImage.c_str());
        SDL_Texture *myTexture;
        myTexture = IMG_LoadTexture( m_renderer, char_array);
        int w1, h1;
        SDL_QueryTexture(myTexture, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xp;
        texr1.y = yp;
        texr1.w = width;
        texr1.h = height;
        SDL_RenderCopy( m_renderer, myTexture, NULL, &texr1);
        SDL_DestroyTexture(myTexture);
}


void write(SDL_Renderer *renderer,int x,int y,string te,const char * font,int font_size,int R,int G,int B, int A,double angle,short flip_num)
{
    //SDL_RenderClear(renderer);
    const char* text=te.c_str();
    SDL_Color text_color = { R, G, B, A};
    int mWidth = 0;
	int mHeight = 0;
    SDL_Rect* clip = NULL;
    TTF_Font *gFont = NULL;
    SDL_Point* center = NULL;
    SDL_RendererFlip flip;
    switch(flip_num)
     {
        case 0:
            flip = SDL_FLIP_NONE;
            break;
        case 1:
            flip = SDL_FLIP_HORIZONTAL;
            break;
        case 2:
            flip = SDL_FLIP_VERTICAL;
            break;
        case 3:
            flip = (SDL_RendererFlip) (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
            break;
        default:
            flip = SDL_FLIP_NONE;
     }
    SDL_Texture* mTexture = NULL;
    gFont = TTF_OpenFont(font, font_size);
    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, text, text_color);
    mWidth = textSurface->w;
    mHeight = textSurface->h;
    mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_Rect renderQuad = {x, y , mWidth, mHeight};
    SDL_RenderCopyEx(renderer, mTexture, clip, &renderQuad, angle, center, flip);
    SDL_DestroyTexture(mTexture);

}

void inputText(SDL_Renderer *m_renderer,int x,int y,string &inputText,const char * font,int font_size,int R,int G,int B, int A)
{
bool flag=false;
SDL_Event ev ;
SDL_StartTextInput();
while( !flag )
{
bool renderText = false;
while( SDL_PollEvent( &ev ) != 0)
{
    if( (ev.type==SDL_MOUSEBUTTONDOWN && ev.button.button==SDL_BUTTON_RIGHT) )
    {
        flag=true;
    }
    else if( ev.type == SDL_KEYDOWN )
    {
        if( ev.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 )
        {
          inputText=inputText.substr(0,inputText.length()-1);
          write(m_renderer,x,y,inputText,font,30,0,0,0,255,0,NONE);
          SDL_RenderPresent(m_renderer);
          renderText = true;
        }
        if( ev.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
        {
            SDL_SetClipboardText( inputText.c_str() );
        }
        else if( ev.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
        {
            inputText = SDL_GetClipboardText();
            renderText = true;
        }
    }
    else if( ev.type == SDL_TEXTINPUT )
    {
        if( !( SDL_GetModState() & KMOD_CTRL && ( ev.text.text[ 0 ] == 'c' || ev.text.text[ 0 ] == 'C' || ev.text.text[ 0 ] == 'v' || ev.text.text[ 0 ] == 'V' ) ) )
        {
            inputText += ev.text.text;
            renderText = true;
        }
    }
}
    if( renderText )
     {
        if( inputText != "" )
        {
               write(m_renderer,x,y,inputText,font,30,0,0,0,255,0,NONE);
               SDL_RenderPresent(m_renderer);
        }
        else
        {
               write(m_renderer,x,y," ",font,30,0,0,0,255,0,NONE);
               SDL_RenderPresent(m_renderer);
        }
     }

}
 SDL_StopTextInput();
}

void Sort(string names[],int games[],int wins[],int lose[],int draws [],int GFs[], int GAs[],int points[],int GDs[],int Count)
{
    for(int i=Count-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(points[j]<points[i])
            {
                swap(names[i],names[j]);
                swap(games[i],games[j]);
                swap(wins[i],wins[j]);
                swap(lose[i],lose[j]);
                swap(names[i],names[j]);
                swap(draws[i],draws[j]);
                swap(GFs[i],GFs[j]);
                swap(GAs[i],GAs[j]);
                swap(points[i],points[j]);
                swap(GDs[i],GDs[j]);
            }
            else if(points[j]==points[i])
            {
                if(GDs[j]<GDs[i])
                {
                swap(names[i],names[j]);
                swap(games[i],games[j]);
                swap(wins[i],wins[j]);
                swap(lose[i],lose[j]);
                swap(names[i],names[j]);
                swap(draws[i],draws[j]);
                swap(GFs[i],GFs[j]);
                swap(GAs[i],GAs[j]);
                swap(points[i],points[j]);
                swap(GDs[i],GDs[j]);
                }
            }
        }
    }
}
int Searchplayer(string names[],string name)
{
    int Count;
    for(int i=0;i<30;i++)
    {
        if(names[i]==name)
        {
            Count=i;
            break;
        }
    }
    return Count;
}
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian )
{

    SDL_Rect rectangle ;

    rectangle.x = x;

    rectangle.y = y;

    rectangle.w = w;

    rectangle.h = h;

    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);

    if (fill_boolian==1)

        SDL_RenderFillRect(Renderer, &rectangle);

    SDL_RenderDrawRect(Renderer, &rectangle);

   // SDL_RenderPresent(Renderer);

}






