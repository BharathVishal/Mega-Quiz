#include<dos.h>
#include <graphics.h>
#include<iostream.h>
#include<iomanip.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<process.h>
#include<string.h>
#include<fstream.h>
class quiz  //quiz
{
private:
int x,t9,q;
public:
char ch5[];
char y;
int k;
int time;
void intro();
void progressbar();
void highscore(char ch5[] ,float t9);
int menu();
int sel1();
void history();
void entertainment();
void sports();
void mythology();
void tech();
void synopsis();
char qtime();
void circl();
void chal();
};
class pas       //pas
{
public:
float x;
char name[50];
char title[60];
};
void quiz::highscore(char ch5[ ],float t9)
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
clrscr();
cleardevice();
setcolor(RED);
setbkcolor(BLUE);
int a[10]={100,100,100,t9};
char s1[]="P.Harish        ";
char s2[]="G.Bharath-vishal";
char s3[]="Xqz             ";
settextstyle(1,0,(5));
outtextxy(170,40,"HIGH SCORES");
cout<<"\n\n\n\n\n\n\t"<<s1;
cout<<"\t\t\t\t\t"<<a[0];
cout<<"\n\n\n\n\t"<<s2;
cout<<"\t\t\t\t\t"<<a[1];
cout<<"\n\n\n\n\t"<<s3;
cout<<"\t\t\t\t\t"<<a[2];
cout<<"\n\n\n\n\t"<<ch5;
cout<<"\t\t\t\t\t\t\t"<<a[3];
rectangle(15,18,620,470);
delay(3000);
clrscr();
//cleardevice();
closegraph();
}
class quest  //quest
{
public:
char topic[60];
char ques[50];
int n;
char ch;
int qno;
void accept();
void output();
};
void hall()
{
clrscr();
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
pas p;
ifstream fin("player.dat",ios::binary);
setbkcolor(RED);
setcolor(YELLOW);
cleardevice();
setcolor(BLUE);
settextstyle(4,0,(5));
outtextxy(10,15,"Hall of fame");
cout<<"\n\n\n\n\n******************************************************************************";
cout<<"\n"<<setw(10)<<"Name"<<setw(30)<<"Topic played"<<setw(38)<<"Score";
cout<<"\n*********************************************************************************";
while(fin.read((char*)&p,sizeof(p)))
{
cout<<"\n";
cout<<"\n"<<setw(10)<<p.name<<setw(30)<<p.title<<setw(38)<<p.x;
cout<<"\n---------------------------------------------------------------------------------";
cout<<"\n";
}
//closegraph();
}
int i=0;
int menu()
{
int ch;
clrscr();
cleardevice();
settextstyle(6,0,(4));
setbkcolor(RED);
setcolor(YELLOW);
outtextxy(40,35,"Menu-");
outtextxy(40,60,"*****");
outtextxy(40,140,"1.Insert a topic");
outtextxy(40,180,"2.Display a set of questions");
outtextxy(40,220,"3.Delete a topic");
settextstyle(5,0,(5));
setcolor(BLUE);
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t";
outtextxy(40,360,"Enter your choice : ");
rectangle(15,18,620,470);
cin>>ch;
return ch;
}
void quest::accept()
{
clrscr();
cleardevice();
settextstyle(6,0,(4));
setbkcolor(RED);
setcolor(YELLOW);
outtextxy(40,35,"Insertion of a topic");
outtextxy(40,60,"********* ** * *****");
rectangle(15,18,620,470);
setbkcolor(RED);
setcolor(YELLOW);
outtextxy(40,90,"Enter the topic name  : ");
cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t";
gets(topic);
cleardevice();
setbkcolor(RED);
setcolor(YELLOW);
settextstyle(6,0,(4));
rectangle(15,18,620,470);
outtextxy(40,90,"Enter the question with choice(s)  : ");
cout<<"n\n\t";
gets(ques);
outtextxy(40,190,"Enter the answer : ") ;
cout<<"\n\n\n\n\n\t";
cin>>ch;
qno=::i;
::i++;
}
void quest::output()
{
static int t=0;
clrscr();
cleardevice();
settextstyle(6,0,(4));
setbkcolor(RED);
setcolor(YELLOW);
outtextxy(40,35,"Displaying a topic");
outtextxy(40,60,"********** * *****");
cout<<"\n\n\tQues.No:-"<<t;
rectangle(15,18,620,470);
outtextxy(40,90,"Question : ");
cout<<"\n\n\n\n\n\n\t\t\t\t";
puts(ques);
outtextxy(40,180,"Answer     : ");
cout<<"\n\n\n\n\n\t\t\t\t";
cout<<ch;
t++;
delay(3000);
}
void dis()
{
//clrscr();
cleardevice();
quest s;
char top[50];
char top1[50];
ifstream fin("quest.dat",ios::binary);
settextstyle(6,0,(4));
setbkcolor(RED);
setcolor(YELLOW);
if(!fin)
cout<<"\nFile does not exist";
else
{
setbkcolor(RED);
setcolor(YELLOW);
outtextxy(40,35,"Displaying a topic");
outtextxy(40,60,"********** * *****");
rectangle(15,18,620,470);
outtextxy(40,90,"Enter the topic name  : ");
cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t";
gets(top);
clrscr();
while(fin.read((char*)&s,sizeof(s)))
{
strcpy(top1,s.topic);
if(strcmpi(top1,top)==0)
{
setbkcolor(RED);
setcolor(YELLOW);
s.output();
}
}
fin.close();
}
}
void ins()
{
int n;
ofstream fout("quest.dat",ios::binary|ios::app);
quest s;
//clrscr();
cleardevice();
settextstyle(6,0,(4));
setbkcolor(RED);
setcolor(YELLOW);
outtextxy(40,35,"Insertion of a topic");
outtextxy(40,60,"********* ** * *****");
rectangle(15,18,620,470);
outtextxy(40,90,"Enter no of questions : ");
cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t";
cin>>n;
for(int i=1;i<=n;i++)
{
s.accept();
fout.write((char*)&s,sizeof(s));
}
fout.close();
}
void del()
{
cleardevice();
char top[50];
int n;
settextstyle(6,0,(4));
setbkcolor(RED);
setcolor(YELLOW);
rectangle(15,18,620,470);
outtextxy(40,35,"Deletion of a topic");
outtextxy(40,60,"******** ** * *****");
outtextxy(40,90,"Enter the topic to be deleted : ");
cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t";
gets(top);
outtextxy(40,140,"Enter the question no. to be deleted : ");
cout<<"\n\n\n\n\n\t";
cin>>n;
ifstream fin("quest.dat",ios::binary);
ofstream fout("n.dat",ios::binary);
quest e;
int i=0;
while(fin.read((char*)&e,sizeof(e)))
{
if(e.qno==n)
i++;
else
fout.write((char*)&e,sizeof(e));
}
fin.close();
fout.close();
remove("quest.dat");
rename("n.dat","quest.dat");
if(!i)
cout<<"\nRecord does not exist";
}
void play()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
clrscr();
quiz p;
pas c;
strcpy(c.title,"Database questions");
char np[50];
c.x=0.00;
quest a;
ifstream fin("quest.dat",ios::binary);
ofstream fout("player.dat",ios::binary|ios::app);
setbkcolor(RED);
setcolor(YELLOW);
cleardevice();
setcolor(BLUE);
settextstyle(6,0,(3));
if(!fin)
{
cout<<"\n\n\n\n\n\n\t\t\tFile does nor exist";
}
else
{
rectangle(15,18,620,470);
outtextxy(50,15,"Play from a set of questions");
int l=0;
char t;
char nv[50];
cout<<"\n\n\n\n\n\tYou have choosed to play this section of mega quiz which"
<<"\n\n\n\ttests you from the question database.The scores you get in"
<<"\n\n\n\tthis section are converted and then placed in the highscore table."
<<"\n\n\n\tGood luck!";
cout<<"\n\n\n\n\n\n\tEnter the player's name :  ";
gets(nv);
strcpy(c.name,nv);
int n=0;
while(fin.read((char*)&a,sizeof(a)))
{
clrscr();
cleardevice();
setbkcolor(RED);
rectangle(15,18,620,470);
cout<<"\n\n\n\n\n\n\tTopic:- "<<a.topic;
cout<<"\n\n\n\n\n\n\n\n\t"<<l+1<<"."<<a.ques<<"\n";
cout<<"\n\n\n\n\n\n\tchoice:\t";
t=p.qtime();
cout<<"\n\t\t\t\t\t\t\t\t"<<t;
rectangle(15,18,620,470);
if(t==a.ch)
{
clrscr();
cleardevice();
setbkcolor(RED);
n=n+10;
outtextxy(140,220,"û Good job.Your score is  :    ");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<n;
getch();
}
else
{
clrscr();
cleardevice();
rectangle(15,18,620,470);
setbkcolor(RED);
outtextxy(40,220,"X Sorry wrong answer.");
getch();
}
clrscr();
l++;
}
float g=l*10;
c.x=n/(g*0.01);
fout.write((char*)&c,sizeof(c));
p.highscore(c.name,c.x);
clrscr();
}
closegraph();
}
void quiz::circl()
 {
 int r=0;
  clrscr();
  int gdriver=DETECT,gmode;
  int i,x,y;
  initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
  while(r!=9)
   {
   settextstyle(3,0,(6));
   delay(150);
   setcolor(4);
   setbkcolor(GREEN);
   outtextxy(150,165,"THE MEGA QUIZ");
   rectangle(140,165,535,250);
   rectangle(135,160,540,255);
   rectangle(130,155,545,260);
    x=random(640);
    y=random(480);
    setcolor(15);
    for(i=1;i<10;i++)
     {
      circle(x,y,i);
      delay(10);
     }
    setfillstyle(1,15);
    line(x+8,y-2,x+40,y);
    line(x+8,y+2,x+40,y);
    floodfill(x+11,y,15);
    line(x-8,y-2,x-40,y);
    line(x-8,y+2,x-40,y);
    floodfill(x-11,y,15);
    line(x-2,y+8,x,y+40);
    line(x+2,y+8,x,y+40);
    floodfill(x,y+11,15);
    line(x-2,y-8,x,y-40);
    line(x+2,y-8,x,y-40);
    floodfill(x,y-11,15);
    line(x+8,y-2,x+20,y-20);
    line(x+2,y-8,x+20,y-20);
    floodfill(x+15,y-15,15);
    line(x+8,y+2,x+20,y+20);
    line(x+2,y+8,x+20,y+20);
    floodfill(x+15,y+15,15);
    line(x-8,y+2,x-20,y+20);
    line(x-2,y+8,x-20,y+20);
    floodfill(x-15,y+15,15);
    line(x-8,y-2,x-20,y-20);
    line(x-2,y-8,x-20,y-20);
    floodfill(x-15,y-15,15);
    setcolor(0);
    for(i=40;i>=10;i--)
     {
      line(x+8,y-2,x+i,y);
      line(x+8,y+2,x+i,y);
     }
    for(i=40;i>=10;i--)
     {
      line(x-8,y-2,x-i,y);
      line(x-8,y+2,x-i,y);
     }
    for(i=40;i>=10;i--)
     {
      line(x-2,y+8,x,y+i);
      line(x+2,y+8,x,y+i);
     }
    for(i=40;i>=10;i--)
     {
      line(x-2,y-8,x,y-i);
      line(x+2,y-8,x,y-i);
     }
    for(i=20;i>=7;i--)
     {
      line(x+8,y-2,x+i,y-i);
      line(x+2,y-8,x+i,y-i);
     }
    for(i=20;i>=7;i--)
     {
      line(x+8,y+2,x+i,y+i);

      line(x+2,y+8,x+i,y+i);
     }
    for(i=20;i>=7;i--)
     {
      line(x-8,y+2,x-i,y+i);
      line(x-2,y+8,x-i,y+i);
     }
    for(i=20;i>=7;i--)
     {
      line(x-8,y-2,x-i,y-i);
      line(x-2,y-8,x-i,y-i);
     }
    for(i=9;i>0;i--)
     {
      circle(x,y,i);
      delay(10);
     }
     r++;

   }
   closegraph();
   }
int quiz::sel1()
{
int y;
clrscr();
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
setbkcolor(RED);
settextstyle(6,0,(5));
outtextxy(230,25,"*********");
outtextxy(230,50," Topics:");
outtextxy(230,90,"*********");
settextstyle(6,0,(4));
outtextxy(30,160,"1.History-(*New)-(Time based)");
outtextxy(30,200,"2.Sports -(*New)-(Time based");
outtextxy(30,240,"3.Mythology");
outtextxy(30,280,"4.Technology(*New)-(Time based)");
settextstyle(5,0,(4));
outtextxy(30,400,"Enter your choice:");
//window(39,27,60,30);
cin>>y;
closegraph();
return y;
}
char quiz::qtime()
{
char c;
outtextxy(450,30,"Time:-");
setcolor(BLUE);
setfillstyle(1,9);
int gtime=300;
for(double i=360.00;i>=0.00 && gtime!=0;i-=1.30,gtime --)
{
if(kbhit())
{
cin>>c;
goto l;
}
delay(50);
sector(500, 100, 360,i, 30, 40);
}
l:if(gtime==0)
return 'l';
return c;
}
void quiz::intro()
{
int t,j;
clrscr();
for (t=0;t<10;t++)
{
for(j=0;j<50;j++)
cprintf("\n\n*");
cprintf("\r\n");
textcolor(t+1);
textbackground(t);
}
}
void quiz::progressbar()
{
int m1,n1,y1,p=0;
int g=DETECT,d;
       initgraph(&g,&d,"c:\\tc\\bgi");
       cleardevice();
       m1=getmaxx()/2;
       n1=getmaxy()/2;
       settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
       while (p!=9)
       {
       setcolor(rand());
       for (int y1=0;y1<115;y1++)
       circle(m1,n1,y1);
       setcolor(rand());
       outtextxy(289,230,"Loading.");
       for (int j1=105;j1<230;j1++)
       circle(m1,n1,j1);
       setcolor(rand());
       outtextxy(289,230,"Loading.....");
       for (int l=210;l<400;l++)
       circle(m1,n1,l);
       setcolor(rand());
       outtextxy(289,230,"Loading.......");
       delay(200);
       p++;
       }
       closegraph();
}
int quiz::menu()
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
int g,y;
settextstyle(3,0,(4));
setbkcolor(GREEN);
outtextxy(230,25,"*******");
outtextxy(230,50," Menu:");
outtextxy(230,90,"*******");
settextstyle(6,0,(3));
setcolor(4);
outtextxy(30,140,"1.Play mega quiz");
outtextxy(30,180,"2.View project synopsis");
outtextxy(30,220,"3.Highscores");
outtextxy(30,260,"4.Insert a question");
outtextxy(30,300,"5.Manager Mode");
outtextxy(30,340,"6.Hall of fame");
outtextxy(30,380,"7. Exit");
settextstyle(5,0,(4));
outtextxy(30,425,"Enter your choice:");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t";
rectangle(15,18,620,470);
//window(39,29,60,30);
cin>>g;
closegraph();
return g;
}
void quiz::chal()
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
for(int i=0,k=10;i<10&&k!=0;i+=1,k++)
{
settextstyle(3,0,(4));
outtextxy(170,25,"****** ********* *****");
outtextxy(170,50,"About Manager mode:");
outtextxy(170,90,"****** ********* *****");
settextstyle(6,0,(3));
outtextxy(30,150,"The Manager mode allows the player");
outtextxy(30,191,"to create an relevant topic and provides the opportunity");
outtextxy(30,231,"to pop in their favourite questions along with their respectfull choices.");
outtextxy(30,271,"So get ready to MANAGE THE MEGA QUIZ at your fullest freedom!!!" );
outtextxy(30,310,"So will you face them all???.");
delay(500);
setbkcolor(i);
setcolor(k);
}
delay(2500);
closegraph();
}
void quiz::synopsis()
{
int gdriver= DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
settextstyle(4,0,(6));
setcolor(4);
setbkcolor(BLUE);
delay(160);
outtextxy(40,45,"THE MEGA QUIZ");
cout<<"\n\n\n\n\n\n\t\t\t\t\t\t-G.Bharath vishal";
cout<<"\n\n\n\t\t\t\t\t\t-P.Harish";
cout<<"\n\n\n\n\nSynopsis:-";
cout<<"\n========";
cout<<"\n\n\nThis project is titled as \"The Mega quiz\".Though anyone can take up this quiz,";
cout<<"\n\n\nthis is not a walk in the park.There are seven topics to choose from:";
delay(300);
cout<<"\n\n\n\a1.History";
delay(300);
cout<<"\n\n\n\a2.Sports";
delay(300);
cout<<"\n\n\n\a3.Mythology";
delay(300);
cout<<"\n\n\n\a4.";
delay(300);
cout<<"\n\n\n\a5.Sports";
delay(300);
cout<<"\n\n\n\a6.Technology";
delay(300);
cout<<"\n\n\n\a7.Entertainment";
delay(300);
cout<<"\n\n\n\t\t\tSo,All The best!!!!!";
clrscr();
delay(3900);
closegraph();
}
void quiz::history()
{
   pas a;
   a.x=0;
   char q[10];
   ofstream fout("player.dat",ios::binary|ios::app);
   clrscr();
   strcpy(a.title,"History");
   int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
   cleardevice();
setbkcolor(RED);
rectangle(15,18,620,470);
gotoxy(9,10);
cout<<"Please enter Your Name                 :              ";
gets(a.name);
settextstyle(1,0,(3));
clrscr();
cleardevice();
setbkcolor(RED);
rectangle(15,18,620,470);
outtextxy(40,70,"You are now playing the history section of ");
outtextxy(40,120,"mega quiz.Enter your answer in as 'a','b'");
outtextxy(40,170,"or'c'.Register your score in the hall");
outtextxy(40,220,"of fame list.");
outtextxy(40,275,"Loading");
delay(450);
outtextxy(120,275,"**");
delay(450);
outtextxy(140,275,"**");
delay(450);
outtextxy(160,275,"**");
delay(450);
outtextxy(180,275,"**");
delay(450);
outtextxy(200,275,"**");
delay(450);
outtextxy(220,275,"**");
delay(450);
outtextxy(240,275,"**");
delay(450);
outtextxy(260,275,"**");
rectangle(15,18,620,470);
clrscr();
int i1;
randomize();
i1=random(3);
switch(i1)
{
case 0: setbkcolor(RED);
	settextstyle(3,0,(3));
	outtextxy(40,220,"(Q).Which indian emperor is known for introducing coin system?");
	outtextxy(40,260,"a.Akbar b.Alauddin khilji c.Sher shah");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q[1]=qtime();
	if(q[1]=='b')
	{       clrscr();
		cleardevice();
		a.x=a.x+10;
		//setbkcolor(RED);
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a.x;
	}
	else{
	     clrscr();
	      cleardevice;
	      setbkcolor(RED);
	       outtextxy(40,220,"X Sorry wrong answer.");
		}
	getch();
case 1:	clrscr();
	setbkcolor(RED);
	cleardevice();
	outtextxy(40,220,"(Q).This chinese empress is ...... called Dragon lady.");
	outtextxy(40,260,"a.Kaiyse-youho   b.lHE-MU-CHA  c.Cixi");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q[2]=qtime();
	if(q[2]=='c')
	{       clrscr();
		cleardevice();
		a.x=a.x+10;
		setbkcolor(RED);
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a.x;

	}
	else{
	    clrscr();
	    cleardevice();
	    setbkcolor(RED);
	     outtextxy(40,220,"X Sorry wrong answer.");
	      }
	getch();
	clrscr();
 case 2:clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q)Who is the son of 'chengiz khan'");
	outtextxy(40,260,"a.Timur khan  b.kublai khan  c.Amir-ul-khan");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q[3]=qtime();
	if(q[3]=='b')
	{       clrscr();
		cleardevice();
		setbkcolor(RED);
		a.x=a.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a.x;


	}
	else{
	   clrscr();
	    cleardevice();
	    setbkcolor(RED);
	    outtextxy(40,220,"X Sorry wrong answer.");
	     }
	getch();
case 3:	clrscr();
	setbkcolor(RED);
	cleardevice();
	outtextxy(40,220,"(Q)Which emperor built the qutub minar?");
	outtextxy(40,260,"a.Qutub-ud-in aibak  b.Saladdin  c.Muhammad");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q[4]=qtime();
	if(q[4]=='a')
	{
	clrscr();
	cleardevice();
		setbkcolor(RED);
		a.x=a.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a.x;
	}
	else{
		clrscr();
	       cleardevice();
	       setbkcolor(RED);
	      outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 4:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).Martin luther king.Jr war awarded ......");
	outtextxy(40,260,"a.Medal of freedom(u.s)  b.Nobel prize c.U.N.P");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q[5]=qtime();
	if(q[5]=='a')
	{
	clrscr();
	cleardevice();
		setbkcolor(RED);
		a.x=a.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a.x;


	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 5:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).The wonder that is visible from outer space is.....?");
	outtextxy(40,260,"a.Great wall of china  b.Pyramids  c.Taj mahal");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q[6]=qtime();
	if(q[6]=='a')
       {
	clrscr();
	cleardevice();
		 setbkcolor(RED);
		a.x=a.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a.x;

	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 6:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).Who invented the steam engine?");
	outtextxy(40,260,"a.Thomas cook  b.James ruther  c.James watt");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q[7]=qtime();
	if(q[7]=='c')
	{
	clrscr();
	cleardevice();
		 setbkcolor(RED);
		a.x=a.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a.x;


	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");

	}
	getch();
case 7:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).when was the government of india act passed?");
	outtextxy(40,260,"a.1935    b.1939      c.1889");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q[7]=qtime();
	if(q[8]=='a')
	{
	clrscr();
	cleardevice();
		 setbkcolor(RED);
		a.x=a.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a.x;
	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 8:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).When did the 'battle of panipat' take place?");
	outtextxy(40,260,"a.1526    b.1429      c.1600");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q[9]=qtime();
	if(q[9]=='a')
	{
	clrscr();
	cleardevice();

		setbkcolor(RED);
		a.x=a.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a.x;
	}

	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 9:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).The vietnam war ended in.........?");
	outtextxy(40,260,"a.1985  b.1975  c.1990");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q[10]=qtime();
	if(q[10]=='c')
	{
	clrscr();
	cleardevice();
	       setbkcolor(RED);
		a.x=a.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a.x;


	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
		clrscr();
	cleardevice();
	fout.write((char*)&a,sizeof(a));
highscore(a.name,a.x);
clrscr();
closegraph();
//cleardevice;
}
}
void quiz::entertainment()// This Topic was done by HARISH
{
   pas a1;
   a1.x=0;
   char q1[10];
   ofstream fout("player.dat",ios::binary|ios::app);
   clrscr();
   strcpy(a1.title,"History");
   int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
   cleardevice();
setbkcolor(RED);
rectangle(15,18,620,470);
gotoxy(9,10);
cout<<"Please enter Your Name                 :              ";
gets(a1.name);
settextstyle(1,0,(3));
clrscr();
cleardevice();
setbkcolor(RED);
rectangle(15,18,620,470);
outtextxy(40,70,"You are now playing the Entertainement section of ");
outtextxy(40,120,"mega quiz.Enter your answer in as 'a','b'");
outtextxy(40,170,"or'c'.Register your score in the hall");
outtextxy(40,220,"of fame list.");
outtextxy(40,275,"Loading");
delay(450);
outtextxy(120,275,"**");
delay(450);
outtextxy(140,275,"**");
delay(450);
outtextxy(160,275,"**");
delay(450);
outtextxy(180,275,"**");
delay(450);
outtextxy(200,275,"**");
delay(450);
outtextxy(220,275,"**");
delay(450);
outtextxy(240,275,"**");
delay(450);
outtextxy(260,275,"**");
rectangle(15,18,620,470);
clrscr();
int l1;
randomize();
l1=random(3);
switch(l1)
{
case 0: setbkcolor(RED);
	settextstyle(3,0,(3));
	outtextxy(40,220,"(Q).What is the name of Mickey Mouse's Dog?");
	outtextxy(40,260,"a.Pluto b.Sady c.Sniffy");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q1[1]=qtime();
	if(q1[1]=='c')
	{       clrscr();
		cleardevice();
		a1.x=a1.x+10;
		//setbkcolor(RED);
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a1.x;
	}
	else{
	     clrscr();
	      cleardevice;
	      setbkcolor(RED);
	       outtextxy(40,220,"X Sorry wrong answer.");
		}
	getch();
case 1:	clrscr();
	setbkcolor(RED);
	cleardevice();
	outtextxy(40,220,"(Q).Which was the first full length animated cartoon film.");
	outtextxy(40,260,"a.Cinderla   b.Snow white and the Seven Dwarfs  c.Alice in wonderland");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q1[2]=qtime();
	if(q1[2]=='b')
	{       clrscr();
		cleardevice();
		a1.x=a1.x+10;
		setbkcolor(RED);
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a1.x;

	}
	else{
	    clrscr();
	    cleardevice();
	    setbkcolor(RED);
	     outtextxy(40,220,"X Sorry wrong answer.");
	      }
	getch();
	clrscr();
 case 2:clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q)Which is the best selling Xbox 360 game till date?'");
	outtextxy(40,260,"a.Grand Tourismo  b.Halo  c.Call of duty");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q1[3]=qtime();
	if(q1[3]=='b')
	{       clrscr();
		cleardevice();
		setbkcolor(RED);
		a1.x=a1.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a1.x;


	}
	else{
	   clrscr();
	    cleardevice();
	    setbkcolor(RED);
	    outtextxy(40,220,"X Sorry wrong answer.");
	     }
	getch();
case 3:	clrscr();
	setbkcolor(RED);
	cleardevice();
	outtextxy(40,220,"(Q)How many grammy awards as Michael Jackson won?");
	outtextxy(40,260,"a.20  b.40  c.18");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q1[4]=qtime();
	if(q1[4]=='c')
	{
	clrscr();
	cleardevice();
		setbkcolor(RED);
		a1.x=a1.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a1.x;
	}
	else{
		clrscr();
	       cleardevice();
	       setbkcolor(RED);
	      outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 4:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).Who is the founder of Facebook who is also one of the youngest millioaner?");
	outtextxy(40,260,"a.Mark Zuckenberg  b.Zanty Howard c.Chris Matt");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q1[5]=qtime();
	if(q1[5]=='a')
	{
	clrscr();
	cleardevice();
		setbkcolor(RED);
		a1.x=a1.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a1.x;


	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	getch();
case 5:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).How many Black keys are there in a standard Piano?");
	outtextxy(40,260,"a.36  b.37  c.40");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q1[6]=qtime();
	if(q1[6]=='a')
       {
	clrscr();
	cleardevice();
		 setbkcolor(RED);
		a1.x=a1.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a1.x;

	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 6:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).The NAVIs in the film Avatar came from the dream that Cameroon's______ has told him!");
	outtextxy(40,260,"a.Grandfather  b.Mother  c.Father");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q1[7]=qtime();
	if(q1[7]=='b')
	{
	clrscr();
	cleardevice();
		 setbkcolor(RED);
		a1.x=a1.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a1.x;


	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");

	}
	getch();
case 7:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).Who is the Highest Paid actor in Asia?");
	outtextxy(40,260,"a.Jackie Chan    b.Jett Lee      c.Rajnikanth");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q1[7]=qtime();
	if(q1[8]=='c')
	{
	clrscr();
	cleardevice();
		 setbkcolor(RED);
		a1.x=a1.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a1.x;
	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 8:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).Which was the last game developed by the Pandemic Studios?");
	outtextxy(40,260,"a.Velvet Assasin    b.Mafia I      c.The Saboteur");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q1[9]=qtime();
	if(q1[9]=='c')
	{
	clrscr();
	cleardevice();

		setbkcolor(RED);
		a1.x=a1.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a1.x;
	}

	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 9:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).The Best selling consoles till date is?");
	outtextxy(40,260,"a.PS2  b.WII  c.PS3");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q1[10]=qtime();
	if(q1[10]=='a')
	{
	clrscr();
	cleardevice();
	       setbkcolor(RED);
		a1.x=a1.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<a1.x;


	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
		clrscr();
	cleardevice();
	fout.write((char*)&a1,sizeof(a1));
highscore(a1.name,a1.x);
clrscr();
closegraph();
//cleardevice;
}
}
void quiz::sports()
{    int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
   clrscr();
   pas b;
   b.x=0;
   ofstream fout("player.dat",ios::binary||ios::app);
   strcpy(b.title,"Sports");
   char q9[10];
setbkcolor(RED);
rectangle(15,18,620,470);
gotoxy(9,10);
cout<<"Please enter Your Name             :              ";
gets(b.name);
settextstyle(1,0,(3));
clrscr();
cleardevice();
setbkcolor(RED);
randomize();
rectangle(15,18,620,470);
outtextxy(40,70,"You are now playing the sports section of the");
outtextxy(40,120,"mega quiz.Enter your answer in as 'a','b'or 'c'");
outtextxy(40,170,"only.Register your score in the hall of fame");
outtextxy(40,220,"list.");
outtextxy(40,275,"Loading");
delay(450);
outtextxy(120,275,"**");
delay(450);
outtextxy(140,275,"**");
delay(450);
outtextxy(160,275,"**");
delay(450);
outtextxy(180,275,"**");
delay(450);
outtextxy(200,275,"**");
delay(450);
outtextxy(220,275,"**");
delay(450);
outtextxy(240,275,"**");
delay(450);
outtextxy(260,275,"**");
rectangle(15,18,620,470);
clrscr();
setbkcolor(RED);
int i2;
i2=random(5);
switch(i2)
{
case 0: setbkcolor(RED);
       settextstyle(3,0,(3));
	outtextxy(40,220,"(Q).Which indian athelete reached the semi finals?");
	outtextxy(40,260,"a.K.m.beenamol b.v.s hazare c.Kumar");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q9[1]=qtime();
	if(q9[1]=='a')
	{       clrscr();
	setbkcolor(RED);
		cleardevice();
			b.x=b.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<b.x;
	 }
	else{
	     clrscr();
	      cleardevice();
	      setbkcolor(RED);

	       outtextxy(40,220,"X Sorry wrong answer.");
		}
	getch();
case 1:	clrscr();
	 setbkcolor(RED);
	cleardevice();
	outtextxy(40,220,"(Q).Who bowled the first ball of the world cup?'?");
	outtextxy(40,260,"a.Madan lal   b.Kapil dev c.Roger binny");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q9[2]=qtime();
	if(q9[2]=='c')
	{       clrscr();
	       cleardevice();
	       setbkcolor(RED);
			b.x=b.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<b.x;

	}
	else{
	    clrscr();
	    cleardevice();
	   setbkcolor(RED);
	     outtextxy(40,220,"X Sorry wrong answer.");
	      }
	getch();
	clrscr();
 case 2:clrscr();
	  cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q)Remi fernandez is a national champion in.....?");
	outtextxy(40,260,"a.sailing  b.carrom c.chess");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q9[1]=qtime();
	if(q9[3]=='b')
	{       clrscr();
		cleardevice();
		setbkcolor(RED);
			b.x=b.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<b.x;


	}
	else{
	   clrscr();
	   cleardevice();
	   setbkcolor(RED);
	    outtextxy(40,220,"X Sorry wrong answer.");
	     }
	getch();
case 3:	clrscr();
       cleardevice();
       setbkcolor(RED);
	outtextxy(40,220,"(Q)In which year was the first olympics held?");
	outtextxy(40,260,"a.56 A.D. b.886 A.D.  c.1996 A.d.");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q9[4]=qtime();
	if(q9[4]=='b')
	{
	clrscr();
	cleardevice();
	setbkcolor(RED);

			b.x=b.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<b.x;

	}
	else{
		clrscr();
	       cleardevice();
	       setbkcolor(RED);

	      outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 4:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).The olympic logo consists of how many rings?");
	outtextxy(40,260,"a.5  b.4  c.6");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q9[5]=qtime();
	if(q9[5]=='a')
	{
	clrscr();
       cleardevice();
		       setbkcolor(RED);
			b.x=b.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<b.x;


	}
	else{
	clrscr();
       cleardevice();
       setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 5:	clrscr();
       cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).which indian cricketer is known as the wall?");
	outtextxy(40,260,"a.Rahul dravid     b.Sachin   c.Ganguly");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q9[1]=qtime();
	if(q9[6]=='a')
       {
	clrscr();
	cleardevice();

		setbkcolor(RED);
	b.x=b.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<b.x;
	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 6:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).The footballer of the century is........?");
	outtextxy(40,260,"a.Ronaldo  b.Drogba  c.Pele");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q9[7]=qtime();
	if(q9[7]=='c')

	{
	clrscr();
	cleardevice();
		 setbkcolor(RED);
		b.x=b.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<b.x;

	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");

	}
	getch();
case 7:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q)........, is for for excellence in sports?");
	outtextxy(40,260,"a.Arjuna award    b.Bharath ratna   c.Khel ratna");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q9[8]=qtime();
	if(q9[8]=='a')
	{
	clrscr();
	cleardevice();

			setbkcolor(RED);
			b.x=b.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<b.x;
	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 8:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q)....... has the highest first class score ever?");
	outtextxy(40,260,"a.Brian lara  b.Vivian richards   c.Darren ganga");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q9[9]=qtime();
	if(q9[8]=='a')
	{
	clrscr();
	  cleardevice();
	     setbkcolor(RED);


	b.x=b.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<b.x;
	}

	else{
	clrscr();
       cleardevice();
       setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 9:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q)....... has won seven consecutive championships?");
	outtextxy(40,260,"a.Fernandes  b.Alonso  c.Schumacher");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q9[10]=qtime();
	if(q9[10]=='c')
	{
	clrscr();
	cleardevice();
	setbkcolor(RED);

		b.x=b.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<b.x;

	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	clrscr();
	cleardevice();
	setbkcolor(RED);
	fout.write((char*)&b,sizeof(b));
highscore(b.name,b.x);
clrscr();
closegraph();
//cleardevice;
}
}
void quiz::mythology()
{ int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
   clrscr();
   randomize();
   char q51[10];
   pas c;
   ofstream fout("player.dat",ios::binary|ios::app);
   strcpy(c.title,"mythology");
   c.x=0;
setbkcolor(RED);
rectangle(15,18,620,470);
gotoxy(9,10);
cout<<"Please enter Your Name              :           ";
gets(c.name);
settextstyle(1,0,(3));
clrscr();
cleardevice();
setbkcolor(RED);
rectangle(15,18,620,470);
outtextxy(40,70,"You are now playing the mythology section of");
outtextxy(40,120,"mega quiz.Enter your answer in as 'a','b'or'c'");
outtextxy(40,170,"only.Register your score in the hall of fame");
outtextxy(40,220,"list.");
outtextxy(40,275,"Loading");
delay(450);
outtextxy(120,275,"**");
delay(450);
outtextxy(140,275,"**");
delay(450);
outtextxy(160,275,"**");
delay(450);
outtextxy(180,275,"**");
delay(450);
outtextxy(200,275,"**");
delay(450);
outtextxy(220,275,"**");
delay(450);
outtextxy(240,275,"**");
delay(450);
outtextxy(260,275,"**");
rectangle(15,18,620,470);
clrscr();
setbkcolor(RED);
clrscr();
int i51;
i51=random(1);
switch(i51)
{
case 0: clrscr();
	cleardevice();
	setbkcolor(RED);
	settextstyle(3,0,(3));
	outtextxy(40,220,"(Q).The titan ..... is the mother earth in greek myths?");
	outtextxy(40,260,"a.Gaia  b.Artemis  c.Leto");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	cin>>q51[1];
	if(q51[1]=='a')
	{       clrscr();
		cleardevice();
		setbkcolor(RED);
		c.x=c.x+20;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<c.x;

	 }
	else{
	     clrscr();
	      cleardevice();
	      setbkcolor(RED);
	       outtextxy(40,220,"X Sorry wrong answer.");
		}
	getch();
case 1:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).Which god was chained on a rock by zeus?");
	outtextxy(40,260,"a.Helios   b.Poseidon  c.Prometheus");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	cin>>q51[2];
	if(q51[2]=='c')
	{       clrscr();
		cleardevice();
		setbkcolor(RED);
		c.x=c.x+20;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<c.x;


	}
	else{
	    clrscr();
	    cleardevice();
	    setbkcolor(RED);
	     outtextxy(40,220,"X Sorry wrong answer.");
	      }
	getch();
	clrscr();
 case 2:clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q)who is the 'god of war'?");
	outtextxy(40,260,"a.Aprohodite    b.Ares   c.Athena");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	cin>>q51[3];
	if(q51[3]=='b')
	{       clrscr();
	 cleardevice();
	 setbkcolor(RED);
		c.x=c.x+20;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<c.x;



	}
	else{
	   clrscr();
	   cleardevice();
	   setbkcolor(RED);
	    outtextxy(40,220,"X Sorry wrong answer.");
	     }
	getch();
case 3:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).Which god is the patron god of athens?");
	outtextxy(40,260,"a.Apollo  b.Athena   c.Artemis");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	cin>>q51[4];
	if(q51[4]=='b')
	{
	clrscr();
	cleardevice();
		setbkcolor(RED);
		c.x=c.x+20;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<c.x;



	}
	else{
		clrscr();
	       cleardevice();
	      setbkcolor(RED);
	      outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 4:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).Which god is the messenger of all gods?");
	outtextxy(40,260,"a.Hermes    b.Dionosys   c.Apollo");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	cin>>q51[5];
	if(q51[5]=='a')
	{
	clrscr();
	cleardevice();
		setbkcolor(RED);
		c.x=c.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<c.x;



	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 5:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).Which greek hero had slained the Medusa?");
	outtextxy(40,260,"a.Perseus   b.Thesus  c.Hercules");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	cin>>q51[6];
	if(q51[6]=='a')
	{
	clrscr();
	cleardevice();
		setbkcolor(RED);
		c.x=c.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<c.x;

	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
	clrscr();
	cleardevice();
	setbkcolor(RED);
	fout.write((char*)&c,sizeof(c));
highscore(c.name,c.x);
clrscr();
closegraph();
//cleardevice;
}
}
void quiz::tech()
{  int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
   clrscr();
   char q81[10];
   pas d;
   randomize();
   d.x=0;
   ofstream fout("player.dat",ios::binary|ios::app);
   strcpy(d.title,"technology");
   setbkcolor(RED);
rectangle(15,18,620,470);
gotoxy(9,10);
cout<<"Please enter Your Name             :              ";
gets(d.name);
settextstyle(1,0,(3));
clrscr();
cleardevice();
setbkcolor(RED);
rectangle(15,18,620,470);
outtextxy(40,70,"You are now playing the technology section of ");
outtextxy(40,120,"mega quiz.Enter your answer in as 'a','b'or'c'.");
outtextxy(40,170,"only.Register your score in the hall of fame");
outtextxy(40,220,"list.");
outtextxy(40,275,"Loading");
delay(450);
outtextxy(120,275,"**");
delay(450);
outtextxy(140,275,"**");
delay(450);
outtextxy(160,275,"**");
delay(450);
outtextxy(180,275,"**");
delay(450);
outtextxy(200,275,"**");
delay(450);
outtextxy(220,275,"**");
delay(450);
outtextxy(240,275,"**");
delay(450);
outtextxy(260,275,"**");
rectangle(15,18,620,470);
clrscr();
setbkcolor(RED);
clrscr();
setbkcolor(RED);
int i91;
i91=random(1);
switch(i91)
{
case 0: clrscr();
	cleardevice();
	setbkcolor(RED);
	settextstyle(3,0,(3));
	outtextxy(40,220,"(Q).The developer the original apple 1 is.....?");
	outtextxy(40,260,"a.Steve wozniak b.Steve jobbs c.steve ballmer");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q81[1]=qtime();
	if(q81[1]=='a')
	{       clrscr();
		cleardevice();
		setbkcolor(RED);
		d.x=d.x+20;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<d.x;

	 }
	else{
	     clrscr();
	     setbkcolor(RED);
	      cleardevice;
	      outtextxy(40,220,"X Sorry wrong answer.");
		}
	getch();
case 1:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).Solaris(o.s.) is developed by ........?");
	outtextxy(40,260,"a.Red hat b.Microsoft  c.Sun microsystems");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q81[2]=qtime();
	if(q81[2]=='c')
	{       clrscr();
		cleardevice();
		setbkcolor(RED);
		d.x=d.x+20;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<d.x;


	}
	else{
	    clrscr();
	    cleardevice();
	    setbkcolor(RED);
	     outtextxy(40,220,"X Sorry wrong answer.");
	      }
	getch();
	clrscr();
 case 2:clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).Dvd's were first available to home use in.... ");
	outtextxy(40,260,"a.1995    b.1997   c.1999");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q81[3]=qtime();
	if(q81[3]=='b')
	{       clrscr();
	       cleardevice();
	       setbkcolor(RED);
		d.x=d.x+20;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<d.x;



	}
	else{
	   clrscr();
	   cleardevice();
	   setbkcolor(RED);
	    outtextxy(40,220,"X Sorry wrong answer.");
	     }
	getch();
case 3:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).Usb 3.0 has speeds of......");
	outtextxy(40,260,"a.480 Mbps b.4.5Gbps   c.990 Mbps");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q81[4]=qtime();
	if(q81[4]=='b')
	{
	clrscr();
	cleardevice();
		setbkcolor(RED);
		d.x=d.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<d.x;



	}
	else{
		clrscr();
	       cleardevice();
	       setbkcolor(RED);
	      outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 4:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).The first computer mouse was made of....");
	outtextxy(40,260,"a.Wood    b.Plastic   c.Iron");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q81[5]=qtime();
	if(q81[5]=='a')
	{
	clrscr();
	cleardevice();
		setbkcolor(RED);
		d.x=d.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<d.x;



	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
case 5:	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"(Q).The first p.c. for home use was developed by......");
	outtextxy(40,260,"a.I.B.M. b.Microsoft  c.Hp");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q81[6]=qtime();
	if(q81[6]=='a')
	{       clrscr();
		cleardevice();
		setbkcolor(RED);
		d.x=d.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<d.x;


	}
	else{
	    clrscr();
	    cleardevice();
	    setbkcolor(RED);
	     outtextxy(40,220,"X Sorry wrong answer.");
	      }
	getch();
	clrscr();
case 6:	clrscr();
       cleardevice();
       setbkcolor(RED);

	outtextxy(40,220,"(Q).The founder of microsoft is.....");
	outtextxy(40,260,"a.Bill gates   b.Mark wright  c.Jim Tyson");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tchoice:\t";
	rectangle(15,18,620,470);
	q81[7]=qtime();
	if(q81[7]=='a')
	{
	clrscr();
	cleardevice();
	     setbkcolor(RED);
		d.x=d.x+10;
		outtextxy(140,220,"û Good job.Your score is  :    ");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t:  "<<d.x;

	}
	else{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	outtextxy(40,220,"X Sorry wrong answer.");
	}
	getch();
	clrscr();
	cleardevice();
	setbkcolor(RED);
	fout.write((char*)&d,sizeof(d));
	highscore(d.name,d.x);
clrscr();
closegraph();
//cleardevice;
}
}
void main()
{
int l,l1;
clrscr();
quiz a;
int m;
a.intro();
a.circl();
a.progressbar();
char ch;
do
{
m=a.menu();
if(m==1)
{
l1=a.sel1();
if(l1==1)
a.history();
else if(l1==2)
a.sports();
else if(l1==3)
a.mythology();
else
a.tech();
}
else if(m==2)
{
a.synopsis();
}
else if(m==3)
a.highscore("xyz",60);
else if(m==4)
{
clrscr();
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
setbkcolor(RED);
setcolor(YELLOW);
char cha;
do
{
quest l;
int c;
c=menu();
if(c==1)
{
clrscr();
setbkcolor(RED);
setcolor(YELLOW);
ins();
}
else if(c==2)
{
clrscr();
setbkcolor(RED);
setcolor(YELLOW);
dis();
}
else if(c==3)
{
clrscr();
setbkcolor(RED);
setcolor(YELLOW);
del();
}
else
cout<<"\nWrong choice";
cout<<"\n\n\n\n\n\tDo you want to continue  ?  :";
cin>>cha;
}
while(cha=='y'|| cha=='Y');
}
else if(m==5)
{
play();
}
else if(m==6)
{
clrscr();
hall();
delay(3000);
}
else
exit(1);
cout<<"\n\n\n\nDo you want  to continue    ?(y/n):   ";
cin>>ch;
}
while(ch=='y'||ch=='Y');
getch();

}
}
