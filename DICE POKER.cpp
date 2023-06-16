#include <iostream>
#include <random>
#include <string>
#include <windows.h>

// Defines system wait time.
const int DefTime = 180;
// Defines constants for total possible dots per die, dot combos, number of dice and the initial wager.
const int NumbDieDots = 7, NumbDiePatterns = 7, NumbDice = 5, StartingBet = 50;
// Defines the basic scores
const int TwoPair = 1, ThreeKind =3, FourKind =30, FiveKind = 150, Nothing = 0;
// Defines the jackpots, FiveOnes and FiveSixes
const int FiveOnes = 5000, FiveSixes = 1000;
// Defines the feature
const int FullHouse = 6;
// Defines bet values.
const int BetDollar = 1, Bet2Dollars = 2, Bet3Dollars = 3, Bet4Dollars = 4, Bet5Dollars = 5;

// Struct for High Scores.
struct HighScore
{
    std::string name;
    char countryInit[3];
    int highScore;
    int age;
}HS1, HS2, HS3, HS4, HS5, HS6, HS7, HSP;

std::string dicePokie = "DICE POKER v 1.0                 by JD";

/* Function to draw dice, takes two arrays to draw dots on the dice,
dieDots1 and dieDots2, then places them on an ASCII art die. */
void drawDice(char dieDots1[NumbDieDots], char dieDots2[NumbDieDots])
{
    // ascii representation of two dice.
    std::cout 
        << " _______________ " << "    " << " _______________ \n"
        << "|               |" << "    " << "|               |\n"
        << "|  " << dieDots1[0] << "         " << dieDots1[1] << "  |" << "    " 
        << "|  " << dieDots2[0] << "         " << dieDots2[1] << "  |\n"
        << "|               |" << "    " << "|               |\n"
        << "|  " << dieDots1[2] << "    " << dieDots1[3] << "    " << dieDots1[4] << "  |" << "    " 
        << "|  " << dieDots2[2] << "    " << dieDots2[3] << "    " << dieDots2[4] << "  |\n"
        << "|               |" << "    " << "|               |\n"
        << "|  " << dieDots1[5] << "         " << dieDots1[6] << "  |" << "    " 
        << "|  " << dieDots2[5] << "         " << dieDots2[6] << "  |\n"
        << "|_______________|" << "    " << "|_______________|\n";
}

/* Function to draw die, takes array to draw dots on the dice,
dieDots1, then places it on an ASCII art die. */
void drawDie(char dieDots1[NumbDieDots])
{
    // ascii representation of two dice.
    std::cout
        << "           _______________ \n"
        << "          |               |\n"
        << "          |  " << dieDots1[0] << "         " << dieDots1[1] << "  |\n"
        << "          |               |\n"
        << "          |  " << dieDots1[2] << "    " << dieDots1[3] << "    " << dieDots1[4] << "  |\n"
        << "          |               |\n"
        << "          |  " << dieDots1[5] << "         " << dieDots1[6] << "  |\n"
        << "          |_______________|\n";
}

// Function which can be given art to show before the game.
void drawOpeningScreen()
{
    system("color 02");

    std::cout << "             PRESENTED BY\n \n \n \n";
    std::cout << "         ##### ##         ##### ##    \n";
    std::cout << "         ##### ##         ##### ##    \n";
    std::cout << "     /#   /  / ###/ //     /  / ###   \n";
    std::cout << "    /    /  /   ## /      /  /   ###  \n";
    std::cout << "        /  /             /  /     ### \n";
    std::cout << "       ## ##            ## ##      ## \n";
    std::cout << "       ## ##            ## ##      ## \n";
    std::cout << "     /### ##            ## ##      ## \n";
    std::cout << "    / ### ##            ## ##      ## \n";
    std::cout << "       ## ##            ## ##      ## \n";
    std::cout << "       ## ##            #  ##      ## \n";
    std::cout << "       ## ##               /       /  \n";
    std::cout << "       ## ##          /###/       /   \n";
    std::cout << "       #  #          /   ########/    \n";
    std::cout << "   ##     /         /       ####      \n";
    std::cout << "  ####   /          #                 \n";
    std::cout << "  /  # #/            ##               \n";
    std::cout << " /    ##                              \n";
    std::cout << "      #           \n";

    system("pause");
    system("cls");

    system("color 02");
    Beep(523, 90);
    Beep(659, 90);
    Beep(880, 90);

    std::cout << "\n\n\n\n";

    std::cout << "       ____  ____  ___  ____ \n";
    std::cout << "      (  _ \\(_  _)/ __)( ___)\n";
    std::cout << "       )(_) )_)(_( (__  )__) \n";
    std::cout << "      (____/(____)\\___)(____)  \n";
   
    std::cout << "\n\n\n\n\n\n\n\n\n";
    Sleep(DefTime);
    Beep(523, 90);
    Beep(659, 90);
    Beep(880, 90);


    std::cout << "   ____  _____  _  _  ____  ____  \n";
    std::cout << "  (  _ \\(  _  )( )/ )( ___)(  _ \\ \n";
    std::cout << "   )___/ )(_)(  )  (  )__)  )   /\n";
    std::cout << "  (__)  (_____)(_)\\_)(____)(_)\\_)\n";
  
    Sleep(DefTime * 3);
    system("cls");
    system("color 8E");

    // dieDots1 creates arrays to store the dice showing 6 for before they are rolled.
    char dieDots1[NumbDieDots] = { '@', '@', '@', ' ', '@', '@', '@' };


    // Call the function to draw the dice.
    std::cout << dicePokie << "\n";
    drawDice(dieDots1, dieDots1);
    drawDice(dieDots1, dieDots1);
    drawDie(dieDots1);
}

// Function which can be given art to show before a feature.
void drawFeatureScreen()
{
    std::cout << "               FEATURE!\n";
    Sleep(DefTime);
    system("cls");

}

/* Function to roll dice, defines all the dot patterns 
and then picks one using a number generated by random_device. */
std::pair<int, int> rollDice(char dieDots1[NumbDieDots], char dieDots2[NumbDieDots])
{
    //Defines all the posibble dot patterns.
    char dotPatterns[7][7] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '@', ' ', ' ', ' '},
        {'@', ' ', ' ', ' ', ' ', ' ', '@'},
        {'@', ' ', ' ', '@', ' ', ' ', '@'},
        {'@', '@', ' ', ' ', ' ', '@', '@'},
        {'@', '@', ' ', '@', ' ', '@', '@'},
        {'@', '@', '@', ' ', '@', '@', '@'}
    };

    //Create random values for the two dice rolls.
    int dieRoll1, dieRoll2;
    std::random_device diceRoll;
    std::uniform_int_distribution<int> dist1 (1, 6);
    std::uniform_int_distribution<int> dist2 (1, 6);
    dieRoll1 = dist1(diceRoll), dieRoll2 = dist2(diceRoll);

    //Populate arrays with the correct characters to represent the rolls.
    for (int index = 0; index < NumbDieDots; index++)
    {
        dieDots1[index] = dotPatterns[dieRoll1][index];
        dieDots2[index] = dotPatterns[dieRoll2][index];
    }

    return std::make_pair(dieRoll1, dieRoll2);
}

/* Function to compare roll and decide score, uses a sequence of if statements to check
for each case in order of odds, then ovverwrites results if a better hand is found. */
int checkDice(int* diceValues, int size = NumbDice)
{
    int result = 0;

    // Sorting of array using sort() function
    std::sort(diceValues, diceValues + size);


    // Create a sum to that will check for FiveOnes and FiveSixes
    int sum =
        diceValues[0] +
        diceValues[1] +
        diceValues[2] +
        diceValues[3] +
        diceValues[4];

    // Check for five ones, and update result if found.
    if (sum == FiveOnes)
    {
        result = FiveOnes;
    }

    // Check for five Sixes, and update result if found.
    else if (sum == FiveSixes)
    {
        result = FiveSixes;
    }

    // Check other cases.
    else
    {
        // Check for five of a kind, and update result if found.
        if (diceValues[0] == diceValues[4])
        {
            result = FiveKind;
        }

        // Check for four of kind, and update result if found.
        else if (result == 0 &&
            (diceValues[0] == diceValues[3] ||
            diceValues[1] == diceValues[4]))
        {
            result = FourKind;
        }

        // Check other cases.
        else
        {
            // Check for full house, and update result if found.
            if (result == 0 && 
                (diceValues[0] == diceValues[2] && diceValues[3] == diceValues[4] ||
                diceValues[0] == diceValues[1] && diceValues[2] == diceValues[4]))
            {
                result = FullHouse;
            }

            // Check for three of a kind, and update result if found.
            else if (result == 0 && 
                (diceValues[0] == diceValues[2] ||
                diceValues[1] == diceValues[3] ||
                diceValues[2] == diceValues[4]))
            {
                result = ThreeKind;
            }

            // Check other cases.
            else
            {
                // Check for two pairs, and update result if found.
                if (result == 0 && 
                    (diceValues[0] == diceValues[1] && diceValues[2] == diceValues[3] ||
                    diceValues[1] == diceValues[2] && diceValues[3] == diceValues[4] ||
                    diceValues[0] == diceValues[1] && diceValues[3] == diceValues[4]))
                {
                    result = TwoPair;
                }

                // Returns nothing if there are no accepted combinations.
                else
                {
                    result = Nothing;
                }

            }
        }
    }
    return result;
}

// Function to return the correct string which tells the player which combination they got.
std::string diceResult(int result)
{
    std::string combination;

    switch (result)
    {

    case FiveOnes:
        combination = "Major Prize";
        break;

    case FiveSixes:
        combination = "Minor Prize";
        break;

    case ThreeKind:
        combination = "Three of a Kind";
        break;

    case FourKind:
        combination = "Four of a Kind";
        break;

    case FiveKind:
        combination = "Five of a Kind";
        break;

    case FullHouse:
        combination = "Large Feature";
        break;

    case TwoPair:
        combination = "Two Pair";
        break;

    case Nothing:
        combination = "Nothing";
        break;

    default:
        combination = "Error";
        break;
    }

    return combination;
}

/* Function that calls on the earlier funcitons to actaully
place the dice and results on the screen and returnt them to main. */
int diceGame()
{
    // dieDots1 and dieDots2 creates arrays to store the results of rollDice.
    char
        dieDots1[NumbDieDots], dieDots2[NumbDieDots],
        dieDots3[NumbDieDots], dieDots4[NumbDieDots],
        dieDots5[NumbDieDots], dieDots6[NumbDieDots];

    // Call the function to roll the dice.
    std::pair<int, int> diceValues1 = rollDice(dieDots1, dieDots2);
    std::pair<int, int> diceValues2 = rollDice(dieDots3, dieDots4);
    std::pair<int, int> diceValues3 = rollDice(dieDots5, dieDots6);

    // Call the function to draw the dice.
    std::cout << dicePokie << "\n";
    drawDice(dieDots1, dieDots2);
    drawDice(dieDots3, dieDots4);
    drawDie(dieDots5);

    // Plays a feedback tone for the player
    Beep(104, 125);

    // Get the dice values and load them in an array.
    int
        dice0 = diceValues1.first, dice1 = diceValues1.second,
        dice2 = diceValues2.first, dice3 = diceValues2.second,
        dice4 = diceValues3.first; int totalDice[NumbDice] = { dice0, dice1, dice2, dice3, dice4 };

    // Call the function to find the combination the player rolled.
    int result = checkDice(totalDice);

    return result;
}

// Function that plays the game and returns the players win for the round.
int playTheGame(int betModifier)
{
        
        // Calls the function to roll dice, get their results and draw them.
        int gameValue = diceGame();
        int turnWin = 0;
        Sleep(DefTime);
        std::cout << diceResult(gameValue) << "\n";

        if (gameValue == FiveOnes)
        {

            system("color 4E");
            Beep(880, 45);
            Beep(880, 45);
            Beep(880, 45);
            Beep(880, 45);
            Beep(880, 45);
            Beep(880, 90);

            std::cout << "             |MAJOR PRIZE|\n"
                << "     PAYS 5000x bet, you bet: " << betModifier << "x \n";
        }


        if (gameValue == FiveSixes)
        {

            system("color 4E");
            Beep(880, 45);
            Beep(880, 45);
            Beep(880, 45);
            Beep(880, 45);
            Beep(880, 45);
            Beep(880, 90);

            std::cout << "             |MINOR PRIZE|\n"
                << "     PAYS 1000x bet, you bet: " << betModifier << "x \n";
        }

        

        // Check if the player gets free rolls, and uses a for loop to execute them.
        if (gameValue == FullHouse)
        {
            // Set screen and text color and play some music.
            system("color 4E");
            Beep(523, 90);
            Beep(659, 90);
            Beep(880, 90);
            Sleep(90);
            Beep(523, 90);
            Beep(659, 90);
            Beep(880, 90);
            Sleep(90);
            Beep(523, 90);
            Beep(659, 90);
            Beep(880, 180);
            drawFeatureScreen();
            Sleep(DefTime);
            system("cls");

            for (int index = gameValue; index > 0; index--)
            {
                                
                int spinValue = diceGame();     
                std::cout << "FEATURE  |       " << index - 1 << " Free Rolls Remain\n";
                Sleep(DefTime);
                std::cout << diceResult(spinValue) << "\n";

                if (spinValue == FullHouse)
                {
                    index = index + spinValue;
                }

                else
                {
                    turnWin = turnWin + spinValue;
                }

                // Wait a second to let the user see the result the clear screen
                if (index > 1)
                {
                    Sleep(DefTime);
                    system("cls");
                }
            }
        }

        // Sets the turnWin value the function returns
        else
        {
            turnWin = gameValue;
            Sleep(DefTime);
        }
       
        // Reset screen color and return bet value.
        system("color 8E");
        return turnWin * betModifier;
}

// Function for comparing High Score
void highScore(int playerMoney)
{
    // Define the structs for the stock High Scores.
    HS1.name = "ANITA A'SHAUERE", HS1.highScore = 100, HS1.age = 63,
        HS1.countryInit[0] = 'F', HS1.countryInit[1] = 'R', HS1.countryInit[2] = 'A';
    HS2.name = "COSTA PARKYAKARKOS", HS2.highScore = 200, HS2.age = 47,
        HS2.countryInit[0] = 'G', HS2.countryInit[1] = 'R', HS2.countryInit[2] = 'C';
    HS3.name = "HAN MI BONG", HS3.highScore = 500, HS3.age = 77,
        HS3.countryInit[0] = 'C', HS3.countryInit[1] = 'H', HS3.countryInit[2] = 'N';
    HS4.name = "TOBIAS LUNCH", HS4.highScore = 1000, HS4.age = 19,
        HS4.countryInit[0] = 'E', HS4.countryInit[1] = 'N', HS4.countryInit[2] = 'G';
    HS5.name = "VODKA DRUNKINSKI", HS5.highScore = 2500, HS5.age = 33,
        HS5.countryInit[0] = 'R', HS5.countryInit[1] = 'U', HS5.countryInit[2] = 'S';
    HS6.name = "EZEKIEL HAUSYAMAMA", HS6.highScore = 10000, HS6.age = 32,
        HS6.countryInit[0] = 'J', HS6.countryInit[1] = 'A', HS6.countryInit[2] = 'M';
    HS7.name = "AMANDA HUGINKIS", HS7.highScore = 5000, HS7.age = 38,
        HS7.countryInit[0] = 'U', HS7.countryInit[1] = 'S', HS7.countryInit[2] = 'A';

    // Get the player's score
    std::cout << "Enter your name:\n";
    std::cin >> HSP.name;
    std::cout << std::endl;
    std::cout << "Enter your age:\n";
    std::cin >> HSP.age;
    std::cout << std::endl;
    std::cout << "Enter your country initials:\n";
    std::cin >> HSP.countryInit[0] >> HSP.countryInit[1] >> HSP.countryInit[2];
    std::cout << std::endl;
    HSP.highScore = playerMoney;

    // Create an array of pointers to the structs
    HighScore* scores[] = { &HS1, &HS2, &HS3, &HS4, &HS5, &HS6, &HS7, &HSP };

    // Sort the array in descending order of high scores using bubble sort
    for (int index1 = 0; index1 < 8; index1++)
    {
        for (int index2 = 0; index2 < 7 - index1; index2++)
        {
            if (scores[index2]->highScore < scores[index2 + 1]->highScore)
            {
                HighScore* temp = scores[index2];
                scores[index2] = scores[index2 + 1];
                scores[index2 + 1] = temp;
            }
        }
    }

    system("color 4E");
    system("cls");
    Beep(523, 90);
    Beep(659, 90);
    Beep(880, 90);
    Sleep(90);
    Beep(523, 90);
    Beep(659, 90);
    Beep(880, 90);
    Sleep(90);
    Beep(523, 90);
    Beep(659, 90);
    Beep(880, 180);
    // Display the scores in the correct order
    std::cout << "\        HIGH  SCORES\n";
    for (int index3 = 0; index3 < 8; index3++)
    {
        std::cout << "RANK " << index3 + 1 << "\n " << scores[index3]->name 
            << "\n" << "AGE: " << scores[index3]->age << "         "
            << scores[index3]->countryInit[0] << scores[index3]->countryInit[1]
            << scores[index3]->countryInit[2] << "      SCORE: " << scores[index3]->highScore << "\n\n";
    }
}

int main()
{ 
    // Set screen and text color and play some music.
    system("mode con cols=38 lines=45");
    system("color 8E");
    Beep(440, 90);
    Beep(784, 90);
    Beep(659, 90);
    Beep(523, 90);
    drawOpeningScreen();

    // Start winnings with startingBet value
    int winnings = StartingBet;
    // bool for constant loop.
    bool gameLoop = true;

    // If player runs out of money game ends
   
   
    while (gameLoop)
    {
        if (winnings < 1)
        {
            gameLoop = false;

            system("cls");
            Beep(415, 90);
            Beep(329, 90);
            Beep(262, 90);
            Beep(220, 180);
            std::cout << "Uh-Oh, I hope that wasn't all your money.\n";
            system("pause");
            break;
        }

        // Get player input to choose bet value or collect.
        char betOrCollect;
        int betModifier = 0;
        std::cout << "\nBet [1 - 5] or [C]ollect | TOTAL: $" << winnings << "\n";
        std::cin >> betOrCollect;
        std::cout << std::endl;
        system("cls");

        // Take appropriate money from player and change char to int for bet.
        switch (betOrCollect)
        {
        case '1':
            betModifier = BetDollar;
            winnings = winnings - BetDollar;
            break;

        case '2':
            betModifier = Bet2Dollars;
            winnings = winnings - Bet2Dollars;
            break;
            break;

        case '3':
            betModifier = Bet3Dollars;
            winnings = winnings - Bet3Dollars;
            break;

        case '4':
            betModifier = Bet4Dollars;
            winnings = winnings - Bet4Dollars;
            break;
            break;

        case '5':
            betModifier = Bet5Dollars;
            winnings = winnings - Bet5Dollars;
            break;
            break;

        default:
            break;
        }

        // Calls on the necessary function to play the game, show how much you made on the roll, keep track of your total money 
        if (betModifier >= BetDollar && betModifier <= Bet5Dollars)
        {
            int betReturn = playTheGame(betModifier);
            winnings = winnings + betReturn;

            if (betReturn > 0)
            {
                // Play feedback tones for a win and write how much the player won.
                Beep(523, 90);
                Beep(659, 90);  
                Beep(880, 90);
                std::cout << "You win: $" << betReturn << std::endl;
            }

            else
            {
                // Play feedback tone for no win.
                Beep(659, 90);
                Beep(523, 90);              
            }

            Sleep(DefTime);
            continue;
        }

        if (betOrCollect == 'c' || betOrCollect == 'C')
        {
            // Clear the screen, play some music, tell player total winnings and go to high score function
            system("cls");
            Beep(784, 90);
            Beep(659, 90);
            Beep(523, 90);
            Beep(440, 180);
            std::cout << "You walk away with a total of: " << winnings << "\n Enter your details for High Score\n";
            system("pause");
            system("cls");

            // Run high score function.
            highScore(winnings);

            gameLoop = false;
            break;
        }
       
        else
        {
            // Plays a feedback tone for incorrect input and tells the player to put in expected input.
            Beep(104, 250);
            Beep(104, 250);
            std::cout << "Invalid input. Try again.\n";
            Sleep(DefTime);
            system("cls");
            continue;  
        }

    }
    return 0;
}