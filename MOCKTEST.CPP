//This program is created by Kunal & Gaurang

			   /* MOCK TEST PAPER */

#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

 union REGS i,o;            //b,x,y=mouse cord. T=total time alltd.
 int b,x,y,P=1;               // P= currnt Qno. tq=total no. of Qn.
 int tq,T=0,btn=0;

struct ques
 {
  char q[200];
  char opa[20];
  char opb[20];
  char opc[20];
  char opd[20];
  char can;
 };


char ans[91];                     //get response of attemter


void mouse()                      //fxns for mouse
 {
  i.x.ax=1;
  int86(51,&i,&o);
 }

void pos(int &button,int &x1,int &y1)
 {
  i.x.ax=3;
  button=o.x.bx;
  x1=o.x.cx;
  y1=o.x.dx;
  int86(51,&i,&o);
 }

void inst()                              //data handling
 {
  ques Q;
  fstream a("qus.dat",ios::app|ios::in|ios::binary);
  cout<<"INSERT QUESTION?(y/n)\t";
  char ch;
  cin>>ch;

 while(ch=='y')
  {
	cout<<"enter question\n";
	gets(Q.q);
	cout<<"\nenter opotions\n";
	cout<<"a)\t";
	gets(Q.opa);
	cout<<"b)\t";
	gets(Q.opb);
	cout<<"c)\t";
	gets(Q.opc);
	cout<<"d)\t";
	gets(Q.opd);
	cout<<"correct ams\t";
	cin>>Q.can;
	a.write((char*)&Q,sizeof(Q));
	cout<<"\nenter more\t";
	cin>>ch;
	clrscr();
	setbkcolor(1);
  }

  a.seekg(0,ios::beg);
  while(a.read((char*)&Q,sizeof(Q)))
  tq=a.tellg()/sizeof(Q);
  gotoxy(50,50);
  cout<<"total no. of question=\t"<<tq;
  a.close();
  delay(3000);

 }



void qsdsp(ques W)         //p=question no.
 {
  //ques W;
  setbkcolor(0);
  settextstyle(2,0,5);
  char l1[55],l2[55],l3[55],l4[55];
  l1[0]='\0',l2[0]='\0',l3[0]='\0',l4[0]='\0';

  fstream a("qus.dat",ios::in|ios::binary);
  a.seekg((P-1)*sizeof(W),ios::beg);
  a.read((char*)&W,sizeof(W));

  if(strlen(W.q)<=55){outtextxy(3,115,W.q);}
  else
	{
	for(int i=0;i<=strlen(W.q);i++)
		{
		if(i<54){l1[i]=W.q[i];l1[54]='\0';}
		if((i>54)&&(i<109)){l2[i-55]=W.q[i];l2[109]='\0';}
		if((i>109)&&(i<164)){l3[i-110]=W.q[i];l3[164]='\0';}
		if((i>164)&&(i<219)){l4[i-165]=W.q[i];l4[219]='\0';}

		}
	outtextxy(3,115,l1);
	outtextxy(3,130,l2);
	outtextxy(3,145,l3);
	outtextxy(3,160,l4);

	}

  outtextxy(20,175,W.opa);  outtextxy(5,175,"a)");
  outtextxy(20,205,W.opb);  outtextxy(5,205,"b)");
  outtextxy(20,235,W.opc);  outtextxy(5,235,"c)");
  outtextxy(20,265,W.opd);  outtextxy(5,265,"d)");


  settextstyle(0,0,1);
  //a.close();

 }


void svans()
 {
  if((x>=0)&&(x<=(getmaxx()-200))&&(y>=170)&&(y<=290))
  {
	if((y>=170)&&(y<=200))
	{
		if(b==1){ans[P-1]='a';}
		else if((ans[P-1]!='a')&&(ans[P-1]!='b')&&(ans[P-1]!='c')&&(ans[P-1]!='d'))
		{
		rectangle(0,170,getmaxx()-250,200);
		}
	}
	else if((y>200)&&(y<=230))
	{
		if(b==1){ans[P-1]='b';rectangle(0,200,getmaxx()-250,230);}
		else if((ans[P-1]!='a')&&(ans[P-1]!='b')&&(ans[P-1]!='c')&&(ans[P-1]!='d'))
		{
			rectangle(0,200,getmaxx()-250,230);
		}
	}
	else if((y>230)&&(y<=260))
	{
		if(b==1){ans[P-1]='c';}
		else if((ans[P-1]!='a')&&(ans[P-1]!='b')&&(ans[P-1]!='c')&&(ans[P-1]!='d'))
		{
			rectangle(0,230,getmaxx()-250,260);
		}
	}
	else if((
	y>260)&&(y<=290))
	{
		if(b==1){ans[P-1]='d';}
		else if((ans[P-1]!='a')&&(ans[P-1]!='b')&&(ans[P-1]!='c')&&(ans[P-1]!='d'))
		{
			rectangle(0,260,getmaxx()-250,290);
		}
	}


  }

  if(ans[P-1]=='a'){rectangle(0,170,getmaxx()-250,200);}
  if(ans[P-1]=='b'){rectangle(0,200,getmaxx()-250,230);}
  if(ans[P-1]=='c'){rectangle(0,230,getmaxx()-250,260);}
  if(ans[P-1]=='d'){rectangle(0,260,getmaxx()-250,290);}

  if((b==1)&&(x>300)&&(x<400)&&(y>getmaxy()-50)&&(y<getmaxy()-25))
	{
	ans[P-1]='\0';
	}

 }


void showcrrctans()
 {
  ques Q;
  fstream a("qus.dat",ios::in|ios::binary);
  a.seekg((P-1)*sizeof(Q),ios::beg);
  a.read((char*)&Q,sizeof(Q));
  char cans[2];cans[1]='\0';
  cans[0]=Q.can;
  outtextxy(0,290,"correct ans");outtextxy(100,290,cans);
  a.close();
 }



int getmarks(int i,ques Q)
 {
  if((ans[i]=='a')||(ans[i]=='b')||(ans[i]=='c')||(ans[i]=='d'))
	{
	if(ans[i]==Q.can)
		return(4);
	else
		return(-1);
	}
  else
  return(0);
 }
					   //graphic fxn

void tpage()           //test page
 {
  rectangle(0,0,getmaxx(),getmaxy());
  line(0,50,getmaxx(),50);

  line(0,100,getmaxx(),100);
  line(getmaxx()-200,100,getmaxx()-200,getmaxy());
  line(0,getmaxy()-50,getmaxx()-200,getmaxy()-50);

  for(int i=0;i<4;i++)
	{
	line(getmaxx()-50*i,100,getmaxx()-50*i,getmaxy());
	}

  for(i=0;i<7;i++)
	{
	line(getmaxx()-200,150+50*i,getmaxx(),150+50*i);
	}


  for(i=0;i<5;i++)
	{
	line(100*i,getmaxy()-25,100*i,getmaxy()-50);
	}

  line(0,getmaxy()-25,400,getmaxy()-25);

  setcolor(LIGHTGRAY);
  outtextxy(305,getmaxy()-45,"CLEAR");

  setcolor(6);
  outtextxy(5,getmaxy()-45,"MARK");

  setcolor(YELLOW);
  settextstyle(1,0,1);
  outtextxy(5,5,"Mock Test Program");

  setcolor(15);
  settextstyle(0,0,1);

 }


void adminpage(int &s)
 {
  setbkcolor(0);
  outtextxy(250,20,"ADMIN PAGE");
  setcolor(3);
  rectangle(100,60,350,90);  outtextxy(105,65,"Insert question");
  setcolor(7);
  rectangle(100,120,350,150);outtextxy(105,125,"Update time limit");
  setcolor(12);
  rectangle(100,180,350,210);outtextxy(105,185,"View question");
  setcolor(5);
  rectangle(100,240,350,270);outtextxy(105,245,"Exit");
  if((b==1)&&(x>100)&&(x<350))
  {
	if((y>60)&&(y<90))
		{s=1;}
	else if((y>120)&&(y<150))
		{s=2;}
	else if((y>180)&&(y<210))
		{s=3;}
	else if((y>240)&&(y<270))

		{s=4;}

  }
 }



void nvbr()             //navigation bar
 {
  rectangle(100,getmaxy()-50,200,getmaxy()-25);
  rectangle(200,getmaxy()-50,300,getmaxy()-25);

  setcolor(LIGHTGREEN);
  outtextxy(205,getmaxy()-45,"NEXT");
  outtextxy(105,getmaxy()-45,"PREVIOUS");
  setcolor(15);
  if((b==1)&&(y>=(getmaxy()-50))&&(y<=(getmaxy()-25)))
  {
	if((x>=200)&&(x<=300))
		{
		P++;
		cleardevice();
		}
	else if((x>=100)&&(x<=200))
		{
		P--;
		cleardevice();
		}

  }

  if(P>tq)
	{
	P=tq;
	}
  if(P<=0)
	{
	P=1;
	}

 }


void qno()
 {
  char q[5];
  q[0]='Q';q[1]='.';
  q[2]=48+P/10;
  q[3]=48+P%10;
  q[4]='\0';
  outtextxy(0,103,q);
 }



void getI(int &i)
 {

  if((b==1)&&(x>=150)&&(x<=450)&&(y>=150)&&(y<=180))
	{
	i=1;
	}
  if((b==1)&&(x>=150)&&(x<=450)&&(y>=200)&&(y<=230))
	{
	i=2;
	}
  if((b==1)&&(x>=150)&&(x<=450)&&(y>=250)&&(y<=280))
	{
	i=3;
	}

 }



void mark()
 {
  if((b==1)&&(x>0)&&(x<100)&&(y>getmaxy()-50)&&(y<getmaxy()-25))
	{
	ans[P-1]='m';
	}
 }

void instructions()
 {

  int ms=0,tm=4,s=60,bttn=0;
  while((tm>=0)&&(bttn==0))
 {
  pos(b,x,y);
  outtextxy(250,20,"INSTRUCTIONS");
  outtextxy(10,50,"This test is of 2 hours duration");
  outtextxy(10,80,"+4 marks for correct answer, -1 marks for wrong answer");
  outtextxy(10,110,"All questions are compulsory");

  rectangle(450,350,600,390);
  outtextxy(475,360,"START TEST");
  if((b==1)&&(x>450)&&(x<600)&&(y>350)&&(y<390))
	{
	bttn++;
	}

  ms++;
  if(ms==10)
  {
	ms=0;
	s--;
  }
  if(s==0)
  {
	s=60;
	tm--;
  }
					    //for exam timer
  delay(100);
 }

 }



int N=0;

void qstnptr()                   //qustion pointer
 {
  int p=0,q=0,M=0;
  char qn[3];qn[2]='\0';
  for(int j=1+N*30;j<=tq;j++)
  {
   M++;
   if(M<=30)
   {
    qn[0]=(M+N*30)/10+48;
    qn[1]=(M+N*30)%10+48;

    outtextxy(getmaxx()-195+50*p,105+50*q,qn);
    if((ans[M+N*30-1]=='a')||(ans[M+N*30-1]=='b')||(ans[M+N*30-1]=='c')||(ans[M+N*30-1]=='d'))
	{
		setcolor(LIGHTGREEN);
		settextstyle(1,0,2);
		outtextxy(getmaxx()-190+50*p,110+50*q,"A");
		setcolor(15);
		settextstyle(0,0,1);
	}
    if(ans[M+N*30-1]=='m')
	{
		setcolor(6);
		settextstyle(1,0,2);
		outtextxy(getmaxx()-190+50*p,110+50*q,"M");
		setcolor(15);
		settextstyle(0,0,1);
	}

  p++;
  if(p>=4)
	{
	p=0;
	q++;
	}

  if((b==1)&&(y>100+50*q)&&(y<150+50*q)&&(x>getmaxx()-200+50*p)&&(x<getmaxx()-150+50*p))
	{
	P=M+N*30+1;
	cleardevice();
	}

  }            //for if(m<=30)

  }

  rectangle(100,75,200,100);
  outtextxy(140,80,">>");
  if((b==1)&&(x>100)&&(x<200)&&(y>75)&&(y<100))
	{
	N++;
	if(N>=tq/30)
		N=tq/30;
	P=N*30+1;

	}

  rectangle(0,75,100,100);
  outtextxy(40,80,"<<");
  if((b==1)&&(x>0)&&(x<100)&&(y>75)&&(y<100))
	{
	N--;
	if(N<=0)
		N=0;
	P=N*30+1;

	}

 }


void loading(char A[],int g,int f)                      //delay=5
 {

  cleardevice();
  rectangle(0,200,getmaxx(),230);
  settextstyle(1,0,4);
  for(int y=2;y<getmaxx()-2;y++)
	{
	setcolor(LIGHTGREEN);
	line(y,202,y,228);
	if(y%20<=10)
	setcolor(15);

	else
	setcolor(f);             // 0 for black
				  //9 for l.blue
	outtextxy(g,125,A);

	delay(5);
	}
  setcolor(15);
  settextstyle(0,0,1);
  cleardevice();

 }


void endtest()
 {
  rectangle(getmaxx()-100,70,getmaxx()-10,95);
  outtextxy(getmaxx()-90,75,"END TEST");
  if((b==1)&&(x>getmaxx()-100)&&(x<getmaxx()-10)&&(y>70)&&(y<95))
  btn++;

 }





///////////////////VOID MAIN////////////////////////////


void main()
 {
  clrscr();
  fstream a("qus.dat",ios::in|ios::binary);
  ques Q;
  a.seekg(0,ios::end);
  tq=a.tellg()/sizeof(Q);
  T=tq*2-1;

  int gd=DETECT,gb;
  initgraph(&gd,&gb,"C:\\turboc3\\bgi");

  i.x.ax=0;
  int86(51,&i,&o);

  mouse();


///////////////////////////////////////////////////////////////
  loading("WELCOME",225,1);

  while(P==1)
   {
    int I=0;

    while(I==0)
    {

     pos(b,x,y);
     setbkcolor(LIGHTGREEN);
     setcolor(2);
     settextstyle(1,0,4);
     outtextxy(150,10,"PRACTICE TEST PROGRAM");
     settextstyle(0,0,1);
     setcolor(63);

     ellipse(getmaxx()/2,140,0,180,getmaxx()/2,60);
     setfillstyle(SOLID_FILL,15);
     floodfill(10,10,15);

     rectangle(150,150,450,180);
     rectangle(150,200,450,230);
     rectangle(150,250,450,280);

     setcolor(LIGHTBLUE);
     outtextxy(160,155,"Take test");
     outtextxy(160,205,"Admin page");
     outtextxy(160,255,"Exit program");
     setcolor(15);

     getI(I);
     delay(100);

    }
   setbkcolor(0);

   cleardevice();

   switch(I)
   {
	case 2:
	int A=0;
	gotoxy(200,50);
	cout<<"Password(5 character)\n";
	char psswd[6];
	gets(psswd);
	cleardevice();
	if(!strcmp(psswd,"*****"))
	{
	while(A==0)
	{
	while(A==0)
		{
		pos(b,x,y);
		adminpage(A);
		delay(100);
		}
	cleardevice();
	switch(A)
		{
		case 1:
		inst();
		cleardevice();
		A=0;
		break;

		case 2:
		cleardevice();
		gotoxy(50,100);
		cout<<"current time limit\t"<<T+1<<"\n";
		gotoxy(50,120);
		cout<<"update time limit\t";
		gotoxy(50,140);
		cin>>T;
		T--;
		cleardevice();
		A=0;
		break;

		case 3:
		fstream a("qus.dat",ios::binary|ios::in);
		while((b!=2)&&(btn==0))
		{
		a.seekg((P-1)*sizeof(Q),ios::beg);
		a.read((char*)&Q,sizeof(Q));
		pos(b,x,y);
		qsdsp(Q);
		qno();
		nvbr();
		showcrrctans();
		endtest();
		delay(100);
		//cleardevice();
		}
		a.close();
		A=0;
		btn=0;
		cleardevice();
		delay(1000);
		break;

		case 4:
		loading("SAVING",250,0);
		A=1;
		break;
		}       //for switch
	}       //for while
	}       //for if
	cleardevice();
	P=1;
	break;


	case 1:
	setbkcolor(LIGHTBLUE);
	int s=60,m=T,ms=0;
	char ch[7];
	strcpy(ch,"000:00");
	instructions();
	setbkcolor(BLUE);
	///////////////////
	O:
	fstream a("qus.dat",ios::in|ios::binary);
	while((m>=0)&&(b!=2)&&(btn==0))
	{
		a.seekg((P-1)*sizeof(Q),ios::beg);
		a.read((char*)&Q,sizeof(Q));
		tpage();
		pos(b,x,y);
		qno();
		nvbr();
		mark();
		qstnptr();
		qsdsp(Q);
		svans();
		endtest();
		outtextxy(getmaxx()-160,25,"TIME:");
		outtextxy(getmaxx()-100,25,ch);
		delay(100);
		ms++;
		if(ms==10)
		{ms=0; s--;  }
		if(s==0)
		{s=60;  m--;  }
		ch[0]=48+m/100;
		ch[1]=48+m/10;
		ch[2]=48+m%10;
		ch[3]=':';
		ch[4]=48+s/10;
		ch[5]=48+s%10;
		ch[6]='\0';
		cleardevice();


	}
	a.close();

	cleardevice();
	btn=0;

	while(m>=0)
	{
		pos(b,x,y);
		int p=0,q=0;char shw[6];shw[5]='\0',shw[2]=')',shw[3]=' ';
		for(int i=1;i<=tq;i++)
		{
			shw[0]=48+i/10,shw[1]=48+i%10,shw[4]=ans[i-1];
			outtextxy(30+100*q,30+30*p,shw);
			p++;
			if(p==29)
			{
				p=0;
				q++;
			}

		}

		rectangle(500,320,600,340);
		outtextxy(505,325,"GO BACK");
		if((b==1)&&(x>500)&&(x<600)&&(y>320)&&(y<340))
			{ goto O; }

		rectangle(500,350,600,370);
		outtextxy(505,355,"SUBMIT");
		if((b==1)&&(x>500)&&(x<600)&&(y>350)&&(y<370))
			{
			m=-1;
			delay(1000);
			}

		delay(50);

	}

	setbkcolor(LIGHTBLUE);
	loading("Submiting your responses",100,9);
	pos(b,x,y);

	setbkcolor(BLUE);
	while(m<=0)
	{

	pos(b,x,y);
	char cns[2];
	cns[1]='\0';
	int p=0,q=0,ttmrk=0;
	fstream a("qus.dat",ios::in|ios::binary);

		for(int i=0;i<3;i++)
		{
		setcolor(LIGHTGREEN);
		outtextxy(5+150*i,5,"correct");
		outtextxy(5+150*i,15,"answer");

		setcolor(YELLOW);
		outtextxy(55+150*i,5,"your");
		outtextxy(55+150*i,15,"answer");

		setcolor(15);
		for(int j=0;j<3;j++)
			{
			line(0+150*i+50*j,0,0+150*i+50*j,getmaxy());
			}
		}

	for(i=0;i<tq;i++)
		{

		a.read((char*)&Q,sizeof(Q));
		cns[0]=Q.can;
		outtextxy(5+150*q,30+30*p,cns);
		cns[0]=ans[i];
		outtextxy(55+150*q,30+30*p,cns);
		p++;
		if(p==30)
			{
			p=0;
			q++;
			}
		ttmrk+=getmarks(i,Q);

		}

	if(ttmrk>=0)
	{
		char tmrk[4];
		tmrk[0]=48+ttmrk/100;
		tmrk[1]=48+ttmrk/10;
		tmrk[2]=48+ttmrk%10;
		tmrk[3]='\0';
		outtextxy(500,100,"Total marks");
		outtextxy(550,125,tmrk);
	}
	else
	outtextxy(470,100,"Your marks are in -ve");

	rectangle(500,350,600,370);
	outtextxy(505,355,"EXIT");
	if((b==1)&&(x>500)&&(x<600)&&(y>350)&&(y<370))
		{ break; }
	}

	for(int i=0;i<tq;i++)
	{
	ans[i]='\0';
	}

	cleardevice();
	setbkcolor(0);
	P=1;
	break;

	case 3:
	settextstyle(1,0,4);
	outtextxy(100,100,"THANK YOU");
	settextstyle(3,0,1);
	outtextxy(110,200,"PRESS ANY KEY TO EXIT");
	P++;
	break;

   }    //for switch
  }    //for while



getch();
closegraph();
}









