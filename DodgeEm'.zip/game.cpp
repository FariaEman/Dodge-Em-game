//============================================================================
// Name        : game.cpp
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
float a=560,b=750;              //coordinates of player's car
float x=360 ,y=750 ;            //coordinates of opponent car
float x1=460,y1=750;
 int lives=3;                  //number of lives
 bool arr[8][8]={true};
int score=0;
int choice=0;  
int rn;
void level_1();
void level_2();
void level_3();

// set the screen size to given width and height.
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
   
/*
 * Main Canvas drawing function.
 * */
//Board *b;
         
           void GameDisplay()/**/{

    //   show_lives();
 glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
         switch(choice)
             {
           case 0: { DrawString( 400,600 , "1-play game", colors[WHITE]);}
           case 1: { DrawString( 400,550 , "2-pause game", colors[WHITE]);}
           case 2: { DrawString( 400,450 , "3-exit ", colors[WHITE]);  }
            
           case 3:
               { DrawString( 400,400 , "level_1", colors[WHITE]); 
                 level_1();}  
            case 4:
               { DrawString( 400,350 , "level_2", colors[WHITE]); 
                level_2();}
            case 5:
              { DrawString( 400,250 , "level_3", colors[WHITE]); 
                level_3();
               break;}     
            } 
          level_1();
          level_2();
          level_3();

	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
      
}
        
    
    
 
        
    
void level_1() 
{

       
      rn=(rand()%4)+1;                 //random movement of opponent car
          // movement in arena 1
      if(x>=50 && x<=761 && y==750)
         {
           if(x==410 && rn%4==0)
            {
              y=650;
              }
           else
             x-=5;
            }
           if((x==50) && (y<=750 && y>=50))
               y-=5;
           if((x<=760 && x>=50) && (y==50))
               {
              if( x==410 && rn%4==0)
                {
                 y=150;
                 }
              else
                 x+=5; 
                   }
             if((x==760 )&& (y>=50 && y<=750))
                 y+=5;


            // movement in arena 2
              if ((x>=160 && x<=660) && (y==650))
                 {
                 if(x==410 && rn%4==0)
                   {
                     y=550;
                     }
               else if(x==410 && rn%4==0)
                  {
                    y=750;
                     }
                   else
                    x-=5;
                   }
                if((x==160) && (y>=150 && y<=650))
                     y-=5;
                 if((x>=160 && x<=660) && (y==150))
                     {
                    if(x==410 && rn%4==0)
                        {
                           y=250;}
                      else if(x==410 && rn%4==0)
                         {
                           y=50;}
                        else
                    x+=5;}
                  if((y>=150 && y<=650) && (x==660))
                    y+=5;

                 //movement in arena 3

                if ((x>=260 && x<=560) && (y==550))         //for left side motion
                    {
                 if(x==408 && rn%4==0)
                     {
                       y=450;}
                    else if(x==410 && rn%4==0)
                      {
                        y=650;}
                     else
                   x-=5;}

                if ((x==260) && (y>=250 && y<=550))           // for downward motion
                      y-=5;
                  
                if((x>=260 && x<=560) && (y==250))               //for right side motion
                   {
                  if(x==408 && rn%4==0)
                   {
                      y=350;}
                    else if(x==410 && rn%4==0)
                      {
                        y=150;}
                     else
                     x+=5;}

             if((x==560) && (y>=250 && y<=550))                 //for upward motion
                 y+=5;

         //movement in arena 4

              if((x>=360&& x<=460) && (y==450))
                 { 
                if(x==408 && rn%4==0)
                   {
                        y=550;}
                     else
                     x-=5;} 
               if((x==360) && (y>=350 && y<=450)) 
                y-=5;

              if((x>=360 && x<=460) && (y==350))
                {
                  if(x==408 && rn%4==0)
                   {
                        y=250;}
                     else
                   
                 x+=5;}
               if((x==460) && (y>=350 && y<=450))
                y+=5;




    //lives decrease when cars collide

         if(a==x && b==y)
            {
              a=440;b=50;
              x=540;y=50;
              lives--;
            }
      if(lives==3)
         DrawString( 150,900 , "Lives=3", colors[GREEN]);
         else if(lives==2)
          DrawString( 150,900 , "Lives=2", colors[GREEN]);
        else if(lives==1)
          DrawString( 150,900 , "Lives=1", colors[GREEN]);
        else if(lives==0)
 
          {DrawString( 150,900 , "Lives=0", colors[GREEN]);
             exit(1);}
         //print scores
    {DrawString( 700, 900, "Score= " + to_string(score), colors[MISTY_ROSE]);
              }
     
    
   
	// Drawing opponent car
	
	float width = 5; 
	float height = 5;
	float* color = colors[BLUE]; 
	float radius = 2;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect

       
           
        //player's car
	color = colors[WHITE]; 
	DrawRoundRect(a,b,width,height,color,radius); // bottom left tyre
	DrawRoundRect(a+width*3,b,width,height,color,radius); // bottom right tyre
	DrawRoundRect(a+width*3,b+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(a,b+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(a, b+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(a+width, b+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(a+width*3, b+height*2, width, height, color, radius/2); // body right rect


 
           // drawing gift items 
           
           int arr1[8]={50,160,260,360,460,560,660,760};
           int arr2[8]={50,150,250,350,450,550,650,750}; 
          for(int i=0 ; i<8 ; i++)
           {   
             for(int j=0 ; j<8 ; j++)
             {
              if(arr[i][j]==false)
                {
                   DrawSquare( arr1[i] , arr2[j] ,20,colors[RED]); 
                }
                }}  
            // collecting of gift items 
       for(int i=0 ; i<=7 ; i++)
         { 
          if(a==arr1[i] && b==arr2[0])
            {
              arr[i][0]=true;
              DrawSquare( arr1[i] , arr2[0] ,20,colors[BLACK]);
             score+=1;
            }}
      for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[1])
          {
              arr[i][1]=true;
              DrawSquare( arr1[i] , arr2[1] ,20,colors[BLACK]);
           score+=1;
            }}
      for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[2])
          {
              arr[i][2]=true;
              DrawSquare( arr1[i] , arr2[2] ,20,colors[BLACK]);
              score+=1;
            }}
      for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[3])
          {
              arr[i][3]=true;
              DrawSquare( arr1[i] , arr2[3] ,20,colors[BLACK]);
              score+=1;
            }}
     for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[4])
          {
              arr[i][4]=true;
              DrawSquare( arr1[i] , arr2[4] ,20,colors[BLACK]);
               score+=1;
            }}
     for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[5])
          {
              arr[i][5]=true;
              DrawSquare( arr1[i] , arr2[5] ,20,colors[BLACK]);
               score+=1;
            }}
 for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[6])
          {
              arr[i][6]=true;
              DrawSquare( arr1[i] , arr2[6] ,20,colors[BLACK]);
               score+=1;
            }}
 for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[7])
          {
              arr[i][7]=true;
              DrawSquare( arr1[i] , arr2[7] ,20,colors[BLACK]);
              score+=1;
            }}
     if(a>=760 && a<=765 && b==750)
        {DrawSquare( 760 , 750 ,20,colors[BLACK]);}
         



	// Drawing Arena 1
	int gap_turn = 60;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BROWN];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
          DrawSquare( 50 , 50 ,20,colors[RED]); 
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down  
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up         
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right              
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
        DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down

          
             
        // Drawing Arena 2
	gap_turn = 60;
	int sx1 = 120;
	int sy1 = 110;
	swidth = 600/2 - gap_turn/2; // half width
	sheight = 10;
	scolor = colors[GREEN];
	DrawRectangle(sx1, sy1, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx1 + swidth + gap_turn, sy1, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx1+swidth*2+gap_turn, sy1+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx1+swidth*2+gap_turn, sy1+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx1 + swidth + gap_turn, sy+710, swidth, sheight, scolor); // top left
        DrawRectangle(sx1, sy+710, swidth, sheight, scolor); // top right
	DrawRectangle(sx1-sheight*2, sy1+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx1-sheight*2, sy1+sheight, sheight*2, swidth, scolor); // left down
         
        // Drawing Arena 3
	gap_turn = 60;
	int sx2 = 220;
	int sy2 = 210;
	swidth = 400/2 - gap_turn/2; // half width
	sheight = 10;
	scolor = colors[BLUE];
	DrawRectangle(sx2, sy2, swidth, sheight, scolor); // bottom left
     	DrawRectangle(sx2 + swidth + gap_turn, sy2, swidth, sheight, scolor); // bottom right       
	DrawRectangle(sx2+swidth*2+gap_turn, sy2+sheight, sheight*2, swidth, scolor); // right down                  
	DrawRectangle(sx2+swidth*2+gap_turn, sy2+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up                  
	DrawRectangle(sx2 + swidth + gap_turn, sy2+410, swidth, sheight, scolor); // top left       
	DrawRectangle(sx2, sy2+410, swidth, sheight, scolor); // top right        
	DrawRectangle(sx2-sheight*2, sy2+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up         
	DrawRectangle(sx2-sheight*2, sy2+sheight, sheight*2, swidth, scolor); // left down
        
        // Drawing Arena 4
	gap_turn = 40;
	int sx3 = 320;
	int sy3 = 310;
	swidth = 200/2 - gap_turn/2; // half width
	sheight = 10;
	scolor = colors[WHITE];
	DrawRectangle(sx3, sy3, swidth, sheight, scolor); // bottom left         
	DrawRectangle(sx3 + swidth + gap_turn, sy3, swidth, sheight, scolor); // bottom right         
	DrawRectangle(sx3+swidth*2+gap_turn, sy3+sheight, sheight*2, swidth, scolor); // right down         
	DrawRectangle(sx3+swidth*2+gap_turn, sy3+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up          
	DrawRectangle(sx3 + swidth + gap_turn, sy3+220, swidth, sheight, scolor); // top left         
	DrawRectangle(sx3, sy3+220, swidth, sheight, scolor); // top right          
	DrawRectangle(sx3-sheight*2, sy3+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up           
	DrawRectangle(sx3-sheight*2, sy3+sheight, sheight*2, swidth, scolor); // left down
           
        // Drawing Arena 5
	gap_turn = 5;
	int sx4 = 395;
	int sy4 = 380;
	swidth = 50/2 - gap_turn/2; // half width
	sheight = 2;
	scolor = colors[YELLOW];
	DrawRectangle(sx4, sy4, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx4 + swidth + gap_turn, sy4, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx4+swidth*2+gap_turn, sy4+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx4+swidth*2+gap_turn, sy4+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx4 + swidth + gap_turn, sy4+60, swidth, sheight, scolor); // top left
	DrawRectangle(sx4, sy4+60, swidth, sheight, scolor); // top right
	DrawRectangle(sx4-sheight*2, sy4+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx4-sheight*2, sy4+sheight, sheight*2, swidth, scolor); // left down

}
      void level_2()
      {
           
      rn=(rand()%4)+1;                 //random movement of opponent car
  // movement in arena 1

     //for left side movement
      if(x>=50 && x<=761 && y==750)
         {
           if(x==410 && rn%4==0)
            {
              y=650;
              }
           else
             x-=5;
            }
           //for downward movement
           if((x==50) && (y<=750 && y>=50))
              {
               if(y==400 && rn%4==0)
                  {
                    x=160;}
                else
               y-=5;}
                //for right side movement
           if((x<=760 && x>=50) && (y==50))
               {
              if( x==410 && rn%4==0)
                {
                 y=150;
                 }
              else
                 x+=5; 
                   }
                //for upward movement
             if((x==760 )&& (y>=50 && y<=750))
                 {
               if(y==400 && rn%4==0)
                  {
                    x=660;}
                else
                 y+=5;


  // movement in arena 2

             //for left side movement
              if ((x>=160 && x<=660) && (y==650))
                 {
                 if(x==410 && rn%4==0)
                   {
                     y=550;
                     }
               else if(x==410 && rn%4==0)
                  {
                    y=750;
                     }
                   else
                    x-=5;
                   }
             //for downward movement
                if((x==160) && (y>=150 && y<=650))
                      {
               if(y==400 && rn%4==0)
                  {
                    x=260;}
                else if(y==400 && rn%4==0)
                  {
                    x=50;}
                
                else
                     y-=5;}
             //for right side movement
                 if((x>=160 && x<=660) && (y==150))
                     {
                    if(x==410 && rn%4==0)
                        {
                           y=250;}
                      else if(x==410 && rn%4==0)
                         {
                           y=50;}
                        else
                    x+=5;}
             //for upward movement
                  if((y>=150 && y<=650) && (x==660))
                       {
               if(y==400 && rn%4==0)
                  {
                    x=560;}
                else if(y==400 && rn%4==0)
                   {
                      x=760;}
                else
                    y+=5;}
 //movement in arena 3

                //for left side movement
                if ((x>=260 && x<=560) && (y==550))         
                    {
                 if(x==408 && rn%4==0)
                     {
                       y=450;}
                    else if(x==410 && rn%4==0)
                      {
                        y=650;}
                     else
                   x-=5;}
               // for downward movement

                if ((x==260) && (y>=250 && y<=550)) 
                   {          
                   if(y==408 && rn%4==0)
                  {
                    x=360;}
                else if(y==400 && rn%4==0)
                  {
                    x=160;}
                
                else
                      y-=5;}
                   //for right side movement
                if((x>=260 && x<=560) && (y==250))               
                   {
                  if(x==408 && rn%4==0)
                   {
                      y=350;}
                    else if(x==410 && rn%4==0)
                      {
                        y=150;}
                     else
                     x+=5;}

              //for upward movement
             if((x==560) && (y>=250 && y<=550))                 
                 {
               if(y==408 && rn%4==0)
                  {
                    x=460;}
                else if(y==400 && rn%4==0)
                   {
                      x=660;}
                else

                 y+=5;

 //movement in arena 4

         //for left side movement
              if((x>=360&& x<=460) && (y==450))
                 { 
                if(x==408 && rn%4==0)
                   {
                        y=550;}
                     else
                     x-=5;} 
         //for downward movement
               if((x==360) && (y>=350 && y<=450))
                    {
                     if(y==408 && rn%4==0)
                       {
                         x=260; }
                else
                y-=5;}
          //for right side movement
              if((x>=360 && x<=460) && (y==350))
                {
                  if(x==408 && rn%4==0)
                   {
                        y=250;}
                     else
                   
                 x+=5;}
          //for upward movement
               if((x==460) && (y>=350 && y<=450))
                      {
                     if(y==408 && rn%4==0)
                       {
                         x=560; }
                else
                y+=5;}




    //lives decrease when cars collide

         if(a==x && b==y)
            {
              a=440;b=50;
              x=540;y=50;
              lives--;
            }
      if(lives==3)
         DrawString( 150,900 , "Lives=3", colors[GREEN]);
         else if(lives==2)
          DrawString( 150,900 , "Lives=2", colors[GREEN]);
        else if(lives==1)
          DrawString( 150,900 , "Lives=1", colors[GREEN]);
        else if(lives==0)
 
          {DrawString( 150,900 , "Lives=0", colors[GREEN]);
             exit(1);}
         //print scores
            { 
            DrawString( 700, 900, "Score= " + to_string(score), colors[MISTY_ROSE]);
              }
     
    
   
	// Drawing opponent car
	
	float width = 5; 
	float height = 5;
	float* color = colors[BLUE_VIOLET]; 
	float radius = 2;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect

       
            
            
        //player's car
	color = colors[WHITE]; 
	DrawRoundRect(a,b,width,height,color,radius); // bottom left tyre
	DrawRoundRect(a+width*3,b,width,height,color,radius); // bottom right tyre
	DrawRoundRect(a+width*3,b+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(a,b+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(a, b+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(a+width, b+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(a+width*3, b+height*2, width, height, color, radius/2); // body right rect


 
           // drawing gift items 
           
           int arr1[8]={50,160,260,360,460,560,660,760};
           int arr2[8]={50,150,250,350,450,550,650,750}; 
          for(int i=0 ; i<8 ; i++)
           {   
             for(int j=0 ; j<8 ; j++)
             {
              if(arr[i][j]==false)
                {
                   DrawSquare( arr1[i] , arr2[j] ,20,colors[RED]); 
                }
                }}  

           // collecting of gift items 
 
       for(int i=0 ; i<=7 ; i++)
         { 
          if(a==arr1[i] && b==arr2[0])
            {
              arr[i][0]=true;
              DrawSquare( arr1[i] , arr2[0] ,20,colors[BLACK]);
             score+=1;
            }}
      for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[1])
          {
              arr[i][1]=true;
              DrawSquare( arr1[i] , arr2[1] ,20,colors[BLACK]);
           score+=1;
            }}
      for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[2])
          {
              arr[i][2]=true;
              DrawSquare( arr1[i] , arr2[2] ,20,colors[BLACK]);
              score+=1;
            }}
      for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[3])
          {
              arr[i][3]=true;
              DrawSquare( arr1[i] , arr2[3] ,20,colors[BLACK]);
              score+=1;
            }}
     for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[4])
          {
              arr[i][4]=true;
              DrawSquare( arr1[i] , arr2[4] ,20,colors[BLACK]);
               score+=1;
            }}
     for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[5])
          {
              arr[i][5]=true;
              DrawSquare( arr1[i] , arr2[5] ,20,colors[BLACK]);
               score+=1;
            }}
 for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[6])
          {
              arr[i][6]=true;
              DrawSquare( arr1[i] , arr2[6] ,20,colors[BLACK]);
               score+=1;
            }}
 for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[7])
          {
              arr[i][7]=true;
              DrawSquare( arr1[i] , arr2[7] ,20,colors[BLACK]);
              score+=1;
            }}
     if(a>=760 && a<=765 && b==750)
        {DrawSquare( 760 , 750 ,20,colors[BLACK]);}
         



	// Drawing Arena 1
	int gap_turn = 60;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BROWN];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
          DrawSquare( 50 , 50 ,20,colors[RED]); 
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down  
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up         
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right              
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
        DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down

          
             
        // Drawing Arena 2
	gap_turn = 60;
	int sx1 = 120;
	int sy1 = 110;
	swidth = 600/2 - gap_turn/2; // half width
	sheight = 10;
	scolor = colors[GREEN];
	DrawRectangle(sx1, sy1, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx1 + swidth + gap_turn, sy1, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx1+swidth*2+gap_turn, sy1+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx1+swidth*2+gap_turn, sy1+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx1 + swidth + gap_turn, sy+710, swidth, sheight, scolor); // top left
        DrawRectangle(sx1, sy+710, swidth, sheight, scolor); // top right
	DrawRectangle(sx1-sheight*2, sy1+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx1-sheight*2, sy1+sheight, sheight*2, swidth, scolor); // left down
         
        // Drawing Arena 3
	gap_turn = 60;
	int sx2 = 220;
	int sy2 = 210;
	swidth = 400/2 - gap_turn/2; // half width
	sheight = 10;
	scolor = colors[BLUE];
	DrawRectangle(sx2, sy2, swidth, sheight, scolor); // bottom left
     	DrawRectangle(sx2 + swidth + gap_turn, sy2, swidth, sheight, scolor); // bottom right       
	DrawRectangle(sx2+swidth*2+gap_turn, sy2+sheight, sheight*2, swidth, scolor); // right down                  
	DrawRectangle(sx2+swidth*2+gap_turn, sy2+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up                  
	DrawRectangle(sx2 + swidth + gap_turn, sy2+410, swidth, sheight, scolor); // top left       
	DrawRectangle(sx2, sy2+410, swidth, sheight, scolor); // top right        
	DrawRectangle(sx2-sheight*2, sy2+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up         
	DrawRectangle(sx2-sheight*2, sy2+sheight, sheight*2, swidth, scolor); // left down
        
        // Drawing Arena 4
	gap_turn = 40;
	int sx3 = 320;
	int sy3 = 310;
	swidth = 200/2 - gap_turn/2; // half width
	sheight = 10;
	scolor = colors[WHITE];
	DrawRectangle(sx3, sy3, swidth, sheight, scolor); // bottom left         
	DrawRectangle(sx3 + swidth + gap_turn, sy3, swidth, sheight, scolor); // bottom right         
	DrawRectangle(sx3+swidth*2+gap_turn, sy3+sheight, sheight*2, swidth, scolor); // right down         
	DrawRectangle(sx3+swidth*2+gap_turn, sy3+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up          
	DrawRectangle(sx3 + swidth + gap_turn, sy3+220, swidth, sheight, scolor); // top left         
	DrawRectangle(sx3, sy3+220, swidth, sheight, scolor); // top right          
	DrawRectangle(sx3-sheight*2, sy3+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up           
	DrawRectangle(sx3-sheight*2, sy3+sheight, sheight*2, swidth, scolor); // left down
           
        // Drawing Arena 5
	gap_turn = 5;
	int sx4 = 395;
	int sy4 = 380;
	swidth = 50/2 - gap_turn/2; // half width
	sheight = 2;
	scolor = colors[YELLOW];
	DrawRectangle(sx4, sy4, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx4 + swidth + gap_turn, sy4, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx4+swidth*2+gap_turn, sy4+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx4+swidth*2+gap_turn, sy4+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx4 + swidth + gap_turn, sy4+60, swidth, sheight, scolor); // top left
	DrawRectangle(sx4, sy4+60, swidth, sheight, scolor); // top right
	DrawRectangle(sx4-sheight*2, sy4+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx4-sheight*2, sy4+sheight, sheight*2, swidth, scolor); // left down

}
  void level_3()
  {

          rn=(rand()%4)+1;                 //random movement of opponent car
  // movement in arena 1

     //for left side movement
      if(x>=50 && x<=761 && y==750)
         {
           if(x==410 && rn%4==0)
            {
              y=650;
              }
           else
             x-=10;
            }
           //for downward movement
           if((x==50) && (y<=750 && y>=50))
              {
               if(y==400 && rn%4==0)
                  {
                    x=160;}
                else
               y-=10;}
                //for right side movement
           if((x<=760 && x>=50) && (y==50))
               {
              if( x==410 && rn%4==0)
                {
                 y=150;
                 }
              else
                 x+=10; 
                   }
                //for upward movement
             if((x==760 )&& (y>=50 && y<=750))
                 {
               if(y==400 && rn%4==0)
                  {
                    x=660;}
                else
                 y+=10;


  // movement in arena 2

             //for left side movement
              if ((x>=160 && x<=660) && (y==650))
                 {
                 if(x==410 && rn%4==0)
                   {
                     y=550;
                     }
               else if(x==410 && rn%4==0)
                  {
                    y=750;
                     }
                   else
                    x-=10;
                   }
             //for downward movement
                if((x==160) && (y>=150 && y<=650))
                      {
               if(y==400 && rn%4==0)
                  {
                    x=260;}
                else if(y==400 && rn%4==0)
                  {
                    x=50;}
                
                else
                     y-=10;}
             //for right side movement
                 if((x>=160 && x<=660) && (y==150))
                     {
                    if(x==410 && rn%4==0)
                        {
                           y=250;}
                      else if(x==410 && rn%4==0)
                         {
                           y=50;}
                        else
                    x+=10;}
             //for upward movement
                  if((y>=150 && y<=650) && (x==660))
                       {
               if(y==400 && rn%4==0)
                  {
                    x=560;}
                else if(y==400 && rn%4==0)
                   {
                      x=760;}
                else
                    y+=10;}
 //movement in arena 3

                //for left side movement
                if ((x>=260 && x<=560) && (y==550))         
                    {
                 if(x==408 && rn%4==0)
                     {
                       y=450;}
                    else if(x==410 && rn%4==0)
                      {
                        y=650;}
                     else
                   x-=10;}
               // for downward movement

                if ((x==260) && (y>=250 && y<=550)) 
                   {          
                   if(y==408 && rn%4==0)
                  {
                    x=360;}
                else if(y==400 && rn%4==0)
                  {
                    x=160;}
                
                else
                      y-=10;}
                   //for right side movement
                if((x>=260 && x<=560) && (y==250))               
                   {
                  if(x==408 && rn%4==0)
                   {
                      y=350;}
                    else if(x==410 && rn%4==0)
                      {
                        y=150;}
                     else
                     x+=10;}

              //for upward movement
             if((x==560) && (y>=250 && y<=550))                 
                 {
               if(y==408 && rn%4==0)
                  {
                    x=460;}
                else if(y==400 && rn%4==0)
                   {
                      x=660;}
                else

                 y+=10;

 //movement in arena 4

         //for left side movement
              if((x>=360&& x<=460) && (y==450))
                 { 
                if(x==408 && rn%4==0)
                   {
                        y=550;}
                     else
                     x-=10;} 
         //for downward movement
               if((x==360) && (y>=350 && y<=450))
                    {
                     if(y==408 && rn%4==0)
                       {
                         x=260; }
                else
                y-=10;}
          //for right side movement
              if((x>=360 && x<=460) && (y==350))
                {
                  if(x==408 && rn%4==0)
                   {
                        y=250;}
                     else
                   
                 x+=10;}
          //for upward movement
               if((x==460) && (y>=350 && y<=450))
                      {
                     if(y==408 && rn%4==0)
                       {
                         x=560; }
                else
                y+=10;}

           //clockwise movement of player's car
        if(((a>=50 && a<=760) && (b==750))||((a>=160 && a<=660) && (b==650))||((a>=260 && a<=560) && (b==550))||((a>=360 && a<=460) && (b==450)))
         {a+=10;}
        if(((a==760) && (b<=750 && b>=50))||((a==660) && (b>=150 && b<=650))||((a==560) && (b>=250 && b<=550))||((a==460) && (b>=350 && b<=450))) 
        {b-=10;}
        if(((a<=760 && a>=50) && (b==50)) ||((a>=160 && a<=660) && (b==150))||((a>=260 && a<=560) && (b==250))||((a>=360 && a<=460) && (b==350)))
        {a-=10;}
        if(((a==50 )&& (b>=50 && b<=750)) ||((a==160) && (b>=150&&b<=650))||((a==260) && (b>=250 && b<=550))||((a==360) && (b>=350 && b<=450)))
         {b+=10;}


    //lives decrease when cars collide

         if(a==x && b==y)                     //condition
            {
              a=440;b=50;                        //reset axis
              x=540;y=50;
              lives--;
            }
      if(lives==3)
         DrawString( 150,900 , "Lives=3", colors[GREEN]);
         else if(lives==2)
          DrawString( 150,900 , "Lives=2", colors[GREEN]);
        else if(lives==1)
          DrawString( 150,900 , "Lives=1", colors[GREEN]);
        else if(lives==0)
 
          {DrawString( 150,900 , "Lives=0", colors[GREEN]);
             exit(1);}
         //print scores
            { 
            DrawString( 700, 900, "Score= " + to_string(score), colors[MISTY_ROSE]);
              }
     
    
   
	// Drawing opponent car
	
	float width = 5; 
	float height = 5;
	float* color = colors[GREEN]; 
	float radius = 2;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect

       
            
            
        //player's car
	color = colors[BROWN]; 
	DrawRoundRect(a,b,width,height,color,radius); // bottom left tyre
	DrawRoundRect(a+width*3,b,width,height,color,radius); // bottom right tyre
	DrawRoundRect(a+width*3,b+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(a,b+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(a, b+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(a+width, b+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(a+width*3, b+height*2, width, height, color, radius/2); // body right rect


 
           // drawing gift items 
           
           int arr1[8]={50,160,260,360,460,560,660,760};
           int arr2[8]={50,150,250,350,450,550,650,750}; 
          for(int i=0 ; i<8 ; i++)
           {   
             for(int j=0 ; j<8 ; j++)
             {
              if(arr[i][j]==false)
                {
                   DrawSquare( arr1[i] , arr2[j] ,20,colors[RED]); 
                }
                }}  

           // collecting of gift items 
 
       for(int i=0 ; i<=7 ; i++)
         { 
          if(a==arr1[i] && b==arr2[0])
            {
              arr[i][0]=true;
              DrawSquare( arr1[i] , arr2[0] ,20,colors[BLACK]);
             score+=1;
            }}
      for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[1])
          {
              arr[i][1]=true;
              DrawSquare( arr1[i] , arr2[1] ,20,colors[BLACK]);
           score+=1;
            }}
      for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[2])
          {
              arr[i][2]=true;
              DrawSquare( arr1[i] , arr2[2] ,20,colors[BLACK]);
              score+=1;
            }}
      for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[3])
          {
              arr[i][3]=true;
              DrawSquare( arr1[i] , arr2[3] ,20,colors[BLACK]);
              score+=1;
            }}
     for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[4])
          {
              arr[i][4]=true;
              DrawSquare( arr1[i] , arr2[4] ,20,colors[BLACK]);
               score+=1;
            }}
     for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[5])
          {
              arr[i][5]=true;
              DrawSquare( arr1[i] , arr2[5] ,20,colors[BLACK]);
               score+=1;
            }}
 for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[6])
          {
              arr[i][6]=true;
              DrawSquare( arr1[i] , arr2[6] ,20,colors[BLACK]);
               score+=1;
            }}
 for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[7])
          {
              arr[i][7]=true;
              DrawSquare( arr1[i] , arr2[7] ,20,colors[BLACK]);
              score+=1;
            }}
     if(a>=760 && a<=765 && b==750)
        {DrawSquare( 760 , 750 ,20,colors[BLACK]);}
         



	// Drawing Arena 1
	int gap_turn = 60;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BROWN];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
          DrawSquare( 50 , 50 ,20,colors[RED]); 
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down  
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up         
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right              
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
        DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down

          
             
        // Drawing Arena 2
	gap_turn = 60;
	int sx1 = 120;
	int sy1 = 110;
	swidth = 600/2 - gap_turn/2; // half width
	sheight = 10;
	scolor = colors[GREEN];
	DrawRectangle(sx1, sy1, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx1 + swidth + gap_turn, sy1, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx1+swidth*2+gap_turn, sy1+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx1+swidth*2+gap_turn, sy1+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx1 + swidth + gap_turn, sy+710, swidth, sheight, scolor); // top left
        DrawRectangle(sx1, sy+710, swidth, sheight, scolor); // top right
	DrawRectangle(sx1-sheight*2, sy1+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx1-sheight*2, sy1+sheight, sheight*2, swidth, scolor); // left down
         
        // Drawing Arena 3
	gap_turn = 60;
	int sx2 = 220;
	int sy2 = 210;
	swidth = 400/2 - gap_turn/2; // half width
	sheight = 10;
	scolor = colors[BLUE];
	DrawRectangle(sx2, sy2, swidth, sheight, scolor); // bottom left
     	DrawRectangle(sx2 + swidth + gap_turn, sy2, swidth, sheight, scolor); // bottom right       
	DrawRectangle(sx2+swidth*2+gap_turn, sy2+sheight, sheight*2, swidth, scolor); // right down                  
	DrawRectangle(sx2+swidth*2+gap_turn, sy2+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up                  
	DrawRectangle(sx2 + swidth + gap_turn, sy2+410, swidth, sheight, scolor); // top left       
	DrawRectangle(sx2, sy2+410, swidth, sheight, scolor); // top right        
	DrawRectangle(sx2-sheight*2, sy2+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up         
	DrawRectangle(sx2-sheight*2, sy2+sheight, sheight*2, swidth, scolor); // left down
        
        // Drawing Arena 4
	gap_turn = 40;
	int sx3 = 320;
	int sy3 = 310;
	swidth = 200/2 - gap_turn/2; // half width
	sheight = 10;
	scolor = colors[WHITE];
	DrawRectangle(sx3, sy3, swidth, sheight, scolor); // bottom left         
	DrawRectangle(sx3 + swidth + gap_turn, sy3, swidth, sheight, scolor); // bottom right         
	DrawRectangle(sx3+swidth*2+gap_turn, sy3+sheight, sheight*2, swidth, scolor); // right down         
	DrawRectangle(sx3+swidth*2+gap_turn, sy3+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up          
	DrawRectangle(sx3 + swidth + gap_turn, sy3+220, swidth, sheight, scolor); // top left         
	DrawRectangle(sx3, sy3+220, swidth, sheight, scolor); // top right          
	DrawRectangle(sx3-sheight*2, sy3+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up           
	DrawRectangle(sx3-sheight*2, sy3+sheight, sheight*2, swidth, scolor); // left down
           
        // Drawing Arena 5
	gap_turn = 5;
	int sx4 = 395;
	int sy4 = 380;
	swidth = 50/2 - gap_turn/2; // half width
	sheight = 2;
	scolor = colors[YELLOW];
	DrawRectangle(sx4, sy4, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx4 + swidth + gap_turn, sy4, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx4+swidth*2+gap_turn, sy4+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx4+swidth*2+gap_turn, sy4+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx4 + swidth + gap_turn, sy4+60, swidth, sheight, scolor); // top left
	DrawRectangle(sx4, sy4+60, swidth, sheight, scolor); // top right
	DrawRectangle(sx4-sheight*2, sy4+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx4-sheight*2, sy4+sheight, sheight*2, swidth, scolor); // left down
}
       void level_4()
  {

          rn=(rand()%4)+1;                 //random movement of opponent car1
  // movement in arena 1

     //for left side movement
      if(x>=50 && x<=761 && y==750)
         {
           if(x==410 && rn%4==0)
            {
              y=650;
              }
           else
             x-=10;
            }
           //for downward movement
           if((x==50) && (y<=750 && y>=50))
              {
               if(y==400 && rn%4==0)
                  {
                    x=160;}
                else
               y-=10;}
                //for right side movement
           if((x<=760 && x>=50) && (y==50))
               {
              if( x==410 && rn%4==0)
                {
                 y=150;
                 }
              else
                 x+=10; 
                   }
                //for upward movement
             if((x==760 )&& (y>=50 && y<=750))
                 {
               if(y==400 && rn%4==0)
                  {
                    x=660;}
                else
                 y+=10;


  // movement in arena 2

             //for left side movement
              if ((x>=160 && x<=660) && (y==650))
                 {
                 if(x==410 && rn%4==0)
                   {
                     y=550;
                     }
               else if(x==410 && rn%4==0)
                  {
                    y=750;
                     }
                   else
                    x-=10;
                   }
             //for downward movement
                if((x==160) && (y>=150 && y<=650))
                      {
               if(y==400 && rn%4==0)
                  {
                    x=260;}
                else if(y==400 && rn%4==0)
                  {
                    x=50;}
                
                else
                     y-=10;}
             //for right side movement
                 if((x>=160 && x<=660) && (y==150))
                     {
                    if(x==410 && rn%4==0)
                        {
                           y=250;}
                      else if(x==410 && rn%4==0)
                         {
                           y=50;}
                        else
                    x+=10;}
             //for upward movement
                  if((y>=150 && y<=650) && (x==660))
                       {
               if(y==400 && rn%4==0)
                  {
                    x=560;}
                else if(y==400 && rn%4==0)
                   {
                      x=760;}
                else
                    y+=10;}
 //movement in arena 3

                //for left side movement
                if ((x>=260 && x<=560) && (y==550))         
                    {
                 if(x==408 && rn%4==0)
                     {
                       y=450;}
                    else if(x==410 && rn%4==0)
                      {
                        y=650;}
                     else
                   x-=10;}
               // for downward movement

                if ((x==260) && (y>=250 && y<=550)) 
                   {          
                   if(y==408 && rn%4==0)
                  {
                    x=360;}
                else if(y==400 && rn%4==0)
                  {
                    x=160;}
                
                else
                      y-=10;}
                   //for right side movement
                if((x>=260 && x<=560) && (y==250))               
                   {
                  if(x==408 && rn%4==0)
                   {
                      y=350;}
                    else if(x==410 && rn%4==0)
                      {
                        y=150;}
                     else
                     x+=10;}

              //for upward movement
             if((x==560) && (y>=250 && y<=550))                 
                 {
               if(y==408 && rn%4==0)
                  {
                    x=460;}
                else if(y==400 && rn%4==0)
                   {
                      x=660;}
                else

                 y+=10;

 //movement in arena 4

         //for left side movement
              if((x>=360&& x<=460) && (y==450))
                 { 
                if(x==408 && rn%4==0)
                   {
                        y=550;}
                     else
                     x-=10;} 
         //for downward movement
               if((x==360) && (y>=350 && y<=450))
                    {
                     if(y==408 && rn%4==0)
                       {
                         x=260; }
                else
                y-=10;}
          //for right side movement
              if((x>=360 && x<=460) && (y==350))
                {
                  if(x==408 && rn%4==0)
                   {
                        y=250;}
                     else
                   
                 x+=10;}
          //for upward movement
               if((x==460) && (y>=350 && y<=450))
                      {
                     if(y==408 && rn%4==0)
                       {
                         x=560; }
                else
                y+=10;}

                    //anticlockwise movement of opponent's car2
       /if(((x1>=50 && x1<=760) && (y1==750))||((x1>=160 && x1<=660) && (y1==650))||((x1>=260 && x1<=560) && (y1==550))||((x1>=360&& x1<=460) && (y1==450)))
         {x1-=5;}
        if(((x1==50) && (y1<=750 && y1>=50))||((x1==160) && (y1>=150 && y1<=650))||((x1==260) && (y1>=250 && y1<=550))||((x1==360) && (y1>=350 && y1<=450))) 
        {y1-=5;}
        if(((x1<=760 && x1>=50) && (y1==50)) ||((x1>=160 && x1<=660) && (y1==150))||((x1>=260 && x1<=560) && (y1==250))||((x1>=360 && x1<=460) && (y1==350)))
        {x1+=5;}
        if(((x1==760 )&& (y1>=50 && y1<=750)) ||((y1>=150 && y1<=650) && (x1==660))||((x1==560) && (y1>=250 && y1<=550))||((x1==460) && (y1>=350 && y1<=450)))
         {y1+=5;}


 //clockwise movement of player's car
        if(((a>=50 && a<=760) && (b==750))||((a>=160 && a<=660) && (b==650))||((a>=260 && a<=560) && (b==550))||((a>=360 && a<=460) && (b==450)))
         {a+=10;}
        if(((a==760) && (b<=750 && b>=50))||((a==660) && (b>=150 && b<=650))||((a==560) && (b>=250 && b<=550))||((a==460) && (b>=350 && b<=450))) 
        {b-=10;}
        if(((a<=760 && a>=50) && (b==50)) ||((a>=160 && a<=660) && (b==150))||((a>=260 && a<=560) && (b==250))||((a>=360 && a<=460) && (b==350)))
        {a-=10;}
        if(((a==50 )&& (b>=50 && b<=750)) ||((a==160) && (b>=150&&b<=650))||((a==260) && (b>=250 && b<=550))||((a==360) && (b>=350 && b<=450)))
         {b+=10;}


    //lives decrease when cars collide

         if(a==x && b==y)                     //condition
            {
              a=440;b=50;                        //reset axis
              x=540;y=50;
              lives--;
            }
      if(lives==3)
         DrawString( 150,900 , "Lives=3", colors[GREEN]);
         else if(lives==2)
          DrawString( 150,900 , "Lives=2", colors[GREEN]);
        else if(lives==1)
          DrawString( 150,900 , "Lives=1", colors[GREEN]);
        else if(lives==0)
 
          {DrawString( 150,900 , "Lives=0", colors[GREEN]);
             exit(1);}
         //print scores
            { 
            DrawString( 700, 900, "Score= " + to_string(score), colors[MISTY_ROSE]);
              }
     
    
   
	// Drawing opponent car1
	
	float width = 5; 
	float height = 5;
	float* color = colors[GREEN]; 
	float radius = 2;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect

       // Drawing opponent car2
	
	float width = 5; 
	float height = 5;
	float* color = colors[RED]; 
	float radius = 2;
	DrawRoundRect(x1,y1,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x1+width*3,y1,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x1+width*3,y1+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x1,y1+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x1, y1+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x1+width, y1+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x1+width*3, y1+height*2, width, height, color, radius/2); // body right rect

       
            
            
            
        //player's car
	color = colors[BROWN]; 
	DrawRoundRect(a,b,width,height,color,radius); // bottom left tyre
	DrawRoundRect(a+width*3,b,width,height,color,radius); // bottom right tyre
	DrawRoundRect(a+width*3,b+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(a,b+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(a, b+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(a+width, b+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(a+width*3, b+height*2, width, height, color, radius/2); // body right rect


 
           // drawing gift items 
           
           int arr1[8]={50,160,260,360,460,560,660,760};
           int arr2[8]={50,150,250,350,450,550,650,750}; 
          for(int i=0 ; i<8 ; i++)
           {   
             for(int j=0 ; j<8 ; j++)
             {
              if(arr[i][j]==false)
                {
                   DrawSquare( arr1[i] , arr2[j] ,20,colors[RED]); 
                }
                }}  

           // collecting of gift items 
 
       for(int i=0 ; i<=7 ; i++)
         { 
          if(a==arr1[i] && b==arr2[0])
            {
              arr[i][0]=true;
              DrawSquare( arr1[i] , arr2[0] ,20,colors[BLACK]);
             score+=1;
            }}
      for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[1])
          {
              arr[i][1]=true;
              DrawSquare( arr1[i] , arr2[1] ,20,colors[BLACK]);
           score+=1;
            }}
      for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[2])
          {
              arr[i][2]=true;
              DrawSquare( arr1[i] , arr2[2] ,20,colors[BLACK]);
              score+=1;
            }}
      for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[3])
          {
              arr[i][3]=true;
              DrawSquare( arr1[i] , arr2[3] ,20,colors[BLACK]);
              score+=1;
            }}
     for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[4])
          {
              arr[i][4]=true;
              DrawSquare( arr1[i] , arr2[4] ,20,colors[BLACK]);
               score+=1;
            }}
     for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[5])
          {
              arr[i][5]=true;
              DrawSquare( arr1[i] , arr2[5] ,20,colors[BLACK]);
               score+=1;
            }}
 for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[6])
          {
              arr[i][6]=true;
              DrawSquare( arr1[i] , arr2[6] ,20,colors[BLACK]);
               score+=1;
            }}
 for(int i=0 ; i<=7 ; i++)
         {
           if(a==arr1[i] && b==arr2[7])
          {
              arr[i][7]=true;
              DrawSquare( arr1[i] , arr2[7] ,20,colors[BLACK]);
              score+=1;
            }}
     if(a>=760 && a<=765 && b==750)
        {DrawSquare( 760 , 750 ,20,colors[BLACK]);}
         



	// Drawing Arena 1
	int gap_turn = 60;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BROWN];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
          DrawSquare( 50 , 50 ,20,colors[RED]); 
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down  
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up         
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right              
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
        DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down

          
             
        // Drawing Arena 2
	gap_turn = 60;
	int sx1 = 120;
	int sy1 = 110;
	swidth = 600/2 - gap_turn/2; // half width
	sheight = 10;
	scolor = colors[GREEN];
	DrawRectangle(sx1, sy1, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx1 + swidth + gap_turn, sy1, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx1+swidth*2+gap_turn, sy1+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx1+swidth*2+gap_turn, sy1+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx1 + swidth + gap_turn, sy+710, swidth, sheight, scolor); // top left
        DrawRectangle(sx1, sy+710, swidth, sheight, scolor); // top right
	DrawRectangle(sx1-sheight*2, sy1+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx1-sheight*2, sy1+sheight, sheight*2, swidth, scolor); // left down
         
        // Drawing Arena 3
	gap_turn = 60;
	int sx2 = 220;
	int sy2 = 210;
	swidth = 400/2 - gap_turn/2; // half width
	sheight = 10;
	scolor = colors[BLUE];
	DrawRectangle(sx2, sy2, swidth, sheight, scolor); // bottom left
     	DrawRectangle(sx2 + swidth + gap_turn, sy2, swidth, sheight, scolor); // bottom right       
	DrawRectangle(sx2+swidth*2+gap_turn, sy2+sheight, sheight*2, swidth, scolor); // right down                  
	DrawRectangle(sx2+swidth*2+gap_turn, sy2+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up                  
	DrawRectangle(sx2 + swidth + gap_turn, sy2+410, swidth, sheight, scolor); // top left       
	DrawRectangle(sx2, sy2+410, swidth, sheight, scolor); // top right        
	DrawRectangle(sx2-sheight*2, sy2+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up         
	DrawRectangle(sx2-sheight*2, sy2+sheight, sheight*2, swidth, scolor); // left down
        
        // Drawing Arena 4
	gap_turn = 40;
	int sx3 = 320;
	int sy3 = 310;
	swidth = 200/2 - gap_turn/2; // half width
	sheight = 10;
	scolor = colors[WHITE];
	DrawRectangle(sx3, sy3, swidth, sheight, scolor); // bottom left         
	DrawRectangle(sx3 + swidth + gap_turn, sy3, swidth, sheight, scolor); // bottom right         
	DrawRectangle(sx3+swidth*2+gap_turn, sy3+sheight, sheight*2, swidth, scolor); // right down         
	DrawRectangle(sx3+swidth*2+gap_turn, sy3+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up          
	DrawRectangle(sx3 + swidth + gap_turn, sy3+220, swidth, sheight, scolor); // top left         
	DrawRectangle(sx3, sy3+220, swidth, sheight, scolor); // top right          
	DrawRectangle(sx3-sheight*2, sy3+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up           
	DrawRectangle(sx3-sheight*2, sy3+sheight, sheight*2, swidth, scolor); // left down
           
        // Drawing Arena 5
	gap_turn = 5;
	int sx4 = 395;
	int sy4 = 380;
	swidth = 50/2 - gap_turn/2; // half width
	sheight = 2;
	scolor = colors[YELLOW];
	DrawRectangle(sx4, sy4, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx4 + swidth + gap_turn, sy4, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx4+swidth*2+gap_turn, sy4+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx4+swidth*2+gap_turn, sy4+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx4 + swidth + gap_turn, sy4+60, swidth, sheight, scolor); // top left
	DrawRectangle(sx4, sy4+60, swidth, sheight, scolor); // top right
	DrawRectangle(sx4-sheight*2, sy4+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx4-sheight*2, sy4+sheight, sheight*2, swidth, scolor); // left down
}
           
/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard*/
 

void NonPrintableKeys(int  key,int x,int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
           if(((b>=390 && b<=420) && (a==760))||((b>=390 && b<=425) && (a==660))||((b>=400 &&b<=415) && (a==560))||(b>=400 && b<=415 && x==360))
            {a-=100;}
            
             
             if((b>=390 && b<=425) && (a==160))
               {a-=110;}
             if((b>=400 &&b<=415) && (a==260))
              {a-=100;}
            
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

             if(((b>=390 && b<=420) && (a==760))||((b>=390 && b<=425) && (a==660))||((b>=400 &&b<=415) && (a==560))||((b>=400 &&b<=415) && (a==460)))
                 {a+=100;}

            if((b>=390 && b<=420) && (a==50))  
             {a+=110;}
             if((b>=390 && b<=425) && (a==160))
               {a+=100;}
             if((b>=400 &&b<=415) && (a==260))
              {a+=100;}
            
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

          if(((a>=390 && a<=430) && (b==50)) || ((a>=390 && a<=430) && (b==150)) || ((a>=400 && a<=420) && (b==250)))
           { b+=100;}
            if(((a>=390 && a<=430) && (b==750)) || ((a>=390 && a<=430) && (b==650)) || ((a>=400 && a<=420) && (b==550))||(a>=400 && a<=420 && b==450))
         { b+=100;}
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

           if(((a>=390 && a<=430) && (b==750)) || ((a>=390 && a<=430) && (b==650)) || ((a>=400 && a<=420) && (b==550))||(x>=400 && x<=420 && y==350))
         { b-=100;}
           if(((a>=390 && a<=430) && (b==50)) || ((a>=390 && a<=430) && (b==150)) || ((a>=400 && a<=420) && (b==250))||(x>=400 && x<=420 && y==350))
           { b-=100;}
            
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}


/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 is pressed from the keyboard*/
 
void PrintableKeys(unsigned char key, int x, int y) {
        
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B')
          {   
        cout << "back to menu" << endl;
           }
        if(key == '1')
          {
            choice=3;
          }
         if(key == '2')
          {
            choice=4;
           }
        if(key == '5')
            {
              choice=5;
             }
        if(key == 'p' || key == 'P')
          { cout<< "pause game"<<endl;
            choice=1;}
	glutPostRedisplay();
}


void Timer(int m) {
                
              

           //clockwise movement of player's car
        if(((a>=50 && a<=760) && (b==750))||((a>=160 && a<=660) && (b==650))||((a>=260 && a<=560) && (b==550))||((a>=360 && a<=460) && (b==450)))
         {a+=5;}
        if(((a==760) && (b<=750 && b>=50))||((a==660) && (b>=150 && b<=650))||((a==560) && (b>=250 && b<=550))||((a==460) && (b>=350 && b<=450))) 
        {b-=5;}
        if(((a<=760 && a>=50) && (b==50)) ||((a>=160 && a<=660) && (b==150))||((a>=260 && a<=560) && (b==250))||((a>=360 && a<=460) && (b==350)))
        {a-=5;}
        if(((a==50 )&& (b>=50 && b<=750)) ||((a==160) && (b>=150&&b<=650))||((a==260) && (b>=250 && b<=550))||((a==360) && (b>=350 && b<=450)))
         {b+=5;}
       
        
        
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(2.5, Timer, 2.5);
       
glutPostRedisplay();
}
  
//This function is called (automatically) whenever your mouse moves witin inside the game window
 
 
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
            
	glutPostRedisplay();
}

//This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

         
	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 1000; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(0, 0); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Dodge_em"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(2.5, Timer, 2.5);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
        
	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
