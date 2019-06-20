#include<iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
     std::cout <<  "\nYou are a secret agent breaking into a a Level " << Difficulty;
     
     std::cout <<  " secure server room.\n\nYou need to enter the correct codes to continue...\n\n";
     std::cout << "-----------------------------------------------------------\n";

}

 bool PlayGame(int Difficulty)
{
     PrintIntroduction(Difficulty);
    
     const int CodeA = rand()% Difficulty + Difficulty;
     const int CodeB = rand()% Difficulty + Difficulty;
     const int CodeC = rand()% Difficulty + Difficulty;

     

      const int CodeSum = CodeA + CodeB+ CodeC;
      const int CodeProduct = CodeA*CodeB*CodeC;

    
     std::cout<<std::endl; 
     std::cout<<"\n+ There are 3 numbers in the code\n" ;
     std::cout<<"\n+ The codes add up to: "<< CodeSum <<std::endl;
     std::cout<<"\n+ The codes multiply to give: "<< CodeProduct << std::endl;

     int GuessA, GuessB, GuessC;
     std::cin >> GuessA;
     std::cin >> GuessB;
     std::cin >> GuessC;
     

     int GuessSum = GuessA + GuessB + GuessC;
     int GuessProduct = GuessA *GuessB * GuessC;

     if(GuessSum == CodeSum && GuessProduct == CodeProduct)
     {
         std::cout<<"\n ** well done agent you havce extracted a file! Keep Going!!!\n";
         std::cout<<"------------------------------------";
         return true;
     }
     else
     {
      std::cout<<"\nYou entered the wrong code.  Careful Agent!  try again!!!***\n";
      std::cout<<"-------------------------------";

      return false;
     }
       
}

int main()
{ 
   
   srand(time(NULL));

    
    
    int LevelDifficulty =1;
    const int MaxDifficulty=10;
   
      
    while(LevelDifficulty <= MaxDifficulty)
    {
        
     bool bLevelComplete = PlayGame(LevelDifficulty);  
     
      std::cin.clear();
      std::cin.ignore();

      if (bLevelComplete)
      {
        ++LevelDifficulty;
      }
      
    }
    
   
    std::cout << "\n *** Great Work Agent! You got all the files! Npow get out there!**\n";
    return 0;
    


}

