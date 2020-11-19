#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty; 
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC; 
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print CodeSum and CodeProduct to the terminal
    std:: cout << "\nThere are 3 numbers in the code";
    std:: cout << "\nThe codes add-up to: "<< CodeSum;
    std:: cout << "\nThe codes multiply to give: " << CodeProduct << std::endl;

    //Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    
    std::cout << "You entered: " << GuessA << GuessB << GuessC << std:: endl;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the players guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ****";
        return true;
    }
    else 
    {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
}

int main()
{
    srand(time(NULL)); //create a new random sequence based on the time of day
    
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while(LevelDifficulty <= MaxDifficulty)
    { 
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if(bLevelComplete) 
        {
            //increase the level difficulty
            ++LevelDifficulty;
        }
    }
    std::cout << "\n*** Great work Agent! you got all the files! Now get out of there! ***\n";
    return 0;
}