/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */

#include <SFML/Graphics.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include <iostream>
#include <sstream>
using namespace sf;
int main(){

    srand(time(0));

	Font font;
    font.loadFromFile("franchise_2/Franchise.ttf");
    														//Loading Two fonts here
    Font font2;
    font2.loadFromFile("franchise_2/roman.ttf");

    Text text4;												//Text to be used in menu window
    text4.setFont(font2);
    text4.setCharacterSize(25);
    text4.setString("Tetris\nNew Game: Press Enter\nQuit: Press Escape\nHelp: Press H\n");
    text4.setPosition(0.f, 0.f);
    
    Text text3;												//Text to be used in Help window
    text3.setFont(font2);
    text3.setCharacterSize(25);
    text3.setString("Tetris\n\nThe aim of the game is to\nline up all the tetriminos\nand to gain points.\nIf the tetriminos touch the top\nof the screen it is game over\n\nScoring:\n1 Line = 10 	points x Level\n2 Lines = 30 points x Level\n3 Lines = 60 points x Level\n4 Lines = 100 points x Level");
    text3.setPosition(0.f, 0.f);
    


    RenderWindow window4(VideoMode(320, 480), "Start Menu");								//Menu window rendering
    	while (window4.isOpen())
        {
           	Event e;
           	while (window4.pollEvent(e))
           	{ 
           		if (e.type == Event::Closed)                  
               		window4.close();  
               				
               	else if (e.key.code == Keyboard::Escape)
               		window4.close(); 
               		
               	else if (e.key.code == Keyboard::H)
               	{
               		RenderWindow window3(VideoMode(320, 480), "Help");				//Help window rendering
           			while (window3.isOpen())
           			{
           				Event event3;
           				while (window3.pollEvent(e))
           				{ 
           					if (e.type == Event::Closed)                  
               					window3.close();  
               				
               				else if (e.key.code == Keyboard::Escape)
               					window3.close(); 
               			}
               							
               			window3.draw(text3); 
               			window3.display();  
               		}
               	}
          		
          		else if (e.key.code == Keyboard::Enter)
          		{
    				window4.close();												//Starts the game and closes menu window
    
    RenderWindow window(VideoMode(320, 480), title);
    
    
    //Loading Textures here
    Texture obj1, obj2, obj3, obj4, obj5;
    obj1.loadFromFile("img/tiles.png");
    obj4.loadFromFile("img/tiles2.png");
    obj2.loadFromFile("img/background.png");
    obj3.loadFromFile("img/frame.png");
    obj5.loadFromFile("img/bomb.png");
    
    Sprite sprite(obj1), sprite2(obj4), background(obj2), frame(obj3), sprite3(obj5), temp(obj1);
    
    int delta_x=0, colorNum=1+rand()%7, score=0, count=0, count2=1, n=rand()%8;
    float timer=0, timer2=0, delay=0.7, delay2=0;
    bool rotate=0, score_flag=0, time_flag, bomb_flag=0;
    
	 
    
    Clock clock;
    
   
    

    
    Text text2;
    text2.setFont(font2);
    text2.setCharacterSize(25);            //Text for menu
    text2.setString("Game Paused\nResume: Press Escape\nQuit: Press Delete\nHelp: Press 1\nRestar: Press N");
    text2.setPosition(0.f, 0.f);
    
  
    
   	while (window.isOpen())
   	{
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
        timer2 += time;

        //---Event Listening Part---//
        Event e;
        while (window.pollEvent(e))
        {                                                  //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
                
            
            if (e.type == Event::KeyPressed)
            {                                              //If any other key (not cross) is pressed
                if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
                    rotate = true;                         //Rotation gets on
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                {
                    delta_x = -1;     
                                                          //Change in X-Axis - Negative
                }
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                {
                    delta_x = 1; 
                                                          //Change in X-Axis - Positive
           		}
           		else if (e.key.code == Keyboard::Space)
           		{
           			delay=0;
           		}
           		
           		if (e.key.code == Keyboard::Enter) 
           		{
           			RenderWindow window2(VideoMode(320, 480), "Menu");              //Rendering Menu window
           			while (window2.isOpen())
           			{
           				Event event2;
           				while (window2.pollEvent(e))
           				{ 
           					if (e.type == Event::Closed)                  
               					window2.close();  
               				
               				else if (e.key.code == Keyboard::Escape)
               					window2.close(); 
               				
               				else if (e.key.code == Keyboard::N)
               				{
               					clock.restart();
               					delta_x=0; colorNum=1; score=0;                             //Restarts Game
   								timer=0; delay=0.7;
    							rotate=0; score_flag=0;
    							window2.close();
    							for (int i=0; i<20; i++)
    							{
    								for (int j=0; j<10; j++)
    								{
    									gameGrid[i][j] = 0;                              //Clears game when restart
    								}
    							}
    							
    							
    						}	
               				
               				else if (e.key.code == Keyboard::Delete)
               					{	
               						window2.close();
               						window.close();
               					}
               				else if (e.key.code == Keyboard::H)
               					{
               						RenderWindow window3(VideoMode(320, 480), "Help");              //Rendering Help window
           							while (window3.isOpen())
           							{
           								Event event3;
           								while (window3.pollEvent(e))
           								{ 
           									if (e.type == Event::Closed)                  
               									window3.close();  
               				
               								else if (e.key.code == Keyboard::Escape)
               									window3.close(); 
               							}
               							
               						window3.draw(text3); 
               						window3.display();  
               						}
               					}
               			}
               			
               			window2.draw(text2); 
               			window2.display();  
               		}    
               			
               	}	        
            
            }
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.1;                                    //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05





    //Texts for Game
	Text over;
	over.setFont(font);
    over.setCharacterSize(50);
    over.setString(std::to_string(calc_score(score_flag, score, count, count2)));   //Converting integer to string to display
    over.setPosition(200.f, 200.f);
    
    Text over2;
    over2.setFont(font);
    over2.setCharacterSize(50);
    over2.setString("Score: ");
    over2.setPosition(50.f, 200.f);
    
    Text over3;
    over3.setFont(font);
    over3.setCharacterSize(50);
    over3.setString("Game Over");
    over3.setPosition(50.f, 100.f);
		

        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
         fallingPiece(timer, delay, colorNum, timer2, delay2, n, bomb_flag, sprite, temp, sprite3);               //Example: fallingPiece() function is called here
         move(delta_x);                             //Movement
         blockrotate(rotate);						//Rotation
         horizontal_line(delay, score_flag, count);	//Line Clearing
         calc_score(score_flag, score, count, count2);//Scoring
         level(timer2, count2);							//Level
         shadow(delay);									//shadow
         
  
         if (gameover()==1)							//Game Over
         {
         	window.close();
         	RenderWindow window5(VideoMode(320, 480), "Game Over");                      //Game Over Window
           			while (window5.isOpen())
           			{
           				Event event5;
           				while (window5.pollEvent(e))
           				{ 
           					if (e.type == Event::Closed)                  
               					window5.close();  
               				
               				else if (e.key.code == Keyboard::Escape)
               					window5.close(); 
               				
               				window5.draw(over);
               				window5.draw(over2);
               				window5.draw(over3);
               				window5.display();
               			}
               		}
         }

        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////


	//More Texts
	
    Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setString(std::to_string(calc_score(score_flag, score, count, count2)));
    text.setPosition(75.f, 0.f);
    
    Text score2;
    score2.setFont(font);
    score2.setCharacterSize(20);
    score2.setString("Score: ");
    score2.setPosition(20.f, 0.f);
    
    Text level;
    level.setFont(font);
    level.setCharacterSize(20);
    level.setString(std::to_string(count2));
    level.setPosition(175.f, 0.f);
    
    Text level2;
    level2.setFont(font);
    level2.setCharacterSize(20);
    level2.setString("Level: ");
    level2.setPosition(125.f, 0.f);
    
            
	
    



    window.clear(Color::Black);
    window.draw(background);
    window.draw(text);
    window.draw(score2);
    window.draw(level);
    window.draw(level2);
        
        for (int i=0; i<M; i++)
        {
            for (int j=0; j<N; j++)
            {
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        
        for (int i=0; i<4; i++)
        {
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
          }

        for (int i=0; i<4; i++)
        {
            sprite2.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite2.setPosition(point_3[i][0]*18,point_3[i][1]*18);
            sprite2.move(28,31);
            window.draw(sprite2);
        }
   
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
    }
   }
               							
        window4.draw(text4); 
        window4.display();  
  }
 }
 
return 0;
}


