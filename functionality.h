/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//

void bomb_clear(int& colorNum, int& n, bool& bomb_flag, sf::Sprite& sprite, sf::Sprite& temp, sf::Sprite& sprite3);
void fallingPiece(float& timer, float& delay, int& colorNum, float timer2, float delay2, int& n, bool& bomb_flag, sf::Sprite& sprite, sf::Sprite& temp, sf::Sprite& sprite3){

	sprite=temp;
	if (n==0)
    {
         temp = sprite;
         sprite = sprite3;
         bomb_flag=0;
    }	
     	
    if (timer>delay)
    {
        for (int i=0;i<4;i++)
        {
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
        }
        
        if (!anamoly())
        {
			if (n == 0)
       		{
    			bomb_clear(colorNum, n, bomb_flag, sprite, temp, sprite3);   //Clears area around bomb
    		}
    
    		else
    		{
        		for (int i=0; i<4; i++)
        		{
        			gameGrid[point_2[i][1]][point_2[i][0]] = colorNum;
        		}
        		
        		colorNum = 1+rand()%7;
        		n = rand()%8;
        		bomb_flag=0;

        		if (timer2 < 60)
        		{
        			delay = 0.7;
      		    }
            
            	else if (timer2 >= 60 && timer2 < 120)						//Increases speed of falling block as time progresses for difficulty
            	{
            		delay=0.4;
            	}
            
            	else if (timer2 >= 120)
            	{	
            		delay = 0.2;
            	}

           }	

           for (int i=0;i<4;i++)
           {
               point_1[i][0] = BLOCKS[n][i] % 2;
               point_1[i][1] = BLOCKS[n][i] / 2;
           }
 
      }
      timer=0;   
	}
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///


void blockrotate(bool& rotate)
{
 //When press up key rotate=true so execute function to rotate
    if (rotate == 1)
    {  
		for (int i=0; i<4; i++)
		{	
			int orig_y=point_1[i][0] - point_1[1][0];				//Creates temp variable for point
			int orig_x=point_1[i][1] - point_1[1][1];				//Takes centre point
        	point_1[i][1] = orig_y + point_1[1][1]; 				//reflected on y axis for 90 degree rotation
        	point_1[i][0] = -orig_x + point_1[1][0];				//Centre subtracted from original to prevent rotation over origin
		} 
	
		if (!anamoly())
		{
			for (int i=0; i<4; i++)
			{
				point_1[i][0] = point_2[i][0];
				point_1[i][1] = point_2[i][1];
			}
		}
	
	rotate = 0;
	}
}

void move(int& delta_x)  //Function to move blocks left or right
{
	for (int i=0; i<4; i++)
	{	
		point_2[i][0]=point_1[i][0];
        point_2[i][1]=point_1[i][1];
        point_1[i][0]+=delta_x; 					//Changes horizontal position of block
	}
	delta_x=0;
	
	if (!anamoly())
	{
		for (int i=0; i<4; i++)
		{
			point_1[i][0] = point_2[i][0];
			point_1[i][1] = point_2[i][1];
		}
	}
}

void horizontal_line(float& delay, bool& score_flag, int& count) //Checks whether a line is filled and removes it
{
	int test, row=19;
	score_flag=0;
	count = 0;
	
	for (int i=19; i>0; --i)
	{
		test = 0;  					//Acts as a counter to check how many columns in a row are filled
		
		for (int j=0; j<10; j++)
		{
			if (gameGrid[i][j])  		//Checks if a column is filled in a specific row
			{
				test++;
			}
			
			gameGrid[row][j] = gameGrid[i][j];  //Replacing of columns
		}
		
		if (test == 10) 			 //If counter == number of columns, Row on top of it will replace lower one
		{
			count++;				//Counts how many lines have been cleared for scoring
			score_flag = 1;			//Flag activates if line cleared
		}
		else if (test != 10)		//If counter != number of columns, loop will repeat to next row
		{
			row--;
		}
	}
	
}
	
bool gameover()
{
	for (int i=0; i<N; i++)
	{
		if (point_1[i][1] < gameGrid[i][1]*18)               //Checks whether block crosses the top boundary of the game
		{
			return 1;
		}
		else
			return 0;
	}
return 0;
}



int calc_score(bool& score_flag, int& score, int &count, int count2)
{

	if (score_flag == 1)
	{
		if (count == 1)
			score += (10*count2);
		else if (count == 2)								//Scoring mechanism for game
			score += (30*count2);
		else if (count == 3)
			score += (60*count2);
		else if (count == 4)
			score += (100*count2);
		
   
		score_flag == 0, count = 0;
	}
return score;
}
			
void level(float timer2, int &count2)
{
	if (timer2 == 60)
		count2++;
	if (timer2 == 120)									//Marks increase in level as time progresses
		count2++;
}
			

	
	

void shadow(float delay)
{

	for (int i=0; i<4; i++)
	{
	  point_3[i][1] = point_1[i][1];
      point_3[i][0] = point_1[i][0];
    }

	while (anamoly2())                             //While anomaly is present, shadow moves down meaning that we won't see shadow repetitively falling from top
	{
		for (int i=0;i<4;i++)
		{
			point_4[i][0] = point_3[i][0];
			point_4[i][1] = point_3[i][1];	
            point_3[i][1]+=1;   
        }
    }
        
	if (!anamoly2())
	{	
		for (int i=0; i<4; i++)
		{
			point_3[i][0] = point_4[i][0];
			point_3[i][1] = point_4[i][1];
		}
	}
}


void bomb_clear(int& colorNum, int& n, bool& bomb_flag, sf::Sprite& sprite, sf::Sprite& temp, sf::Sprite& sprite3)
{
	bomb_flag=1;
	
	if (colorNum == gameGrid[point_1[0][1]][point_1[0][0]])                     //Checks if bomb is of same color as block (gameGrid stores colour of blocks)
	{
		for (int i=0; i<20; i++)
		{
			for (int j=0; j<10; j++)
			{
				gameGrid[i][j] = 0;												//Removes block by setting colour to zero
			}
		}
	}
	
	else if (gameGrid[point_1[0][1]][point_1[0][0]])
	{
		gameGrid[point_1[0][1]][point_1[0][0]+1] = 0;
		gameGrid[point_1[0][1]+1][point_1[0][0]+1] = 0;						//removes blocks where bomb lands
		gameGrid[point_1[0][1]+1][point_1[0][0]] = 0;
		gameGrid[point_1[0][1]][point_1[0][0]] = 0;
	}
	
  	colorNum = 1+rand()%7;
  	n=rand()%8;
}





///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
