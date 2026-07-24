#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Enums
enum enWinner
{
    PLAYER = 1,
    COMPUTER = 2,
    DRAW = 3,
};
enum enRockPaperScissors
{
    ROCK = 1,
    PAPER = 2,
    SCISSORS = 3
};

// Structs
struct stGameInfo
{
    short RoundsNumber = 0;

    short PlayerWinRoundCounter = 0;
    short ComWinRoundCounter = 0;
    short DrawRoundCounter = 0;

    enWinner Winner = DRAW;
};
struct stRoundInfo
{
    short RoundNumber = 0;

    enRockPaperScissors PlayerChoice = ROCK;
    enRockPaperScissors ComputerChoice = ROCK;

    enWinner Winner = DRAW;
};

// Helper
int ReadPositiveNumberInRange(string Message, int From, int To)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0 || Number < From || Number > To);

    return Number;
}
int GenerateRandomNumberInRange(int From, int To)
{
    return rand() % (To - From + 1) + From;
}
bool ReadYesNo(string Message)
{
    char answer = 'Y';

    cout << Message << endl;
    cin >> answer;

    return tolower(answer) == 'y';
}

// Enum -> String
string GetChoiceString(enRockPaperScissors Choice)
{
    switch (Choice)
    {
    case ROCK:
        return "Rock";
    case PAPER:
        return "Paper";
    case SCISSORS:
        return "Scissors";
    default:
        return "Rock";
    }
}
string GetWinnerString(enWinner Winner)
{
    switch (Winner)
    {
    case PLAYER:
        return "Player";
    case COMPUTER:
        return "Computer";
    case DRAW:
        return "Draw";
    default:
        return "Draw";
    }
}

// Get Choices
enRockPaperScissors ReadPlayerChoice()
{
    short playerChoice = ReadPositiveNumberInRange("[1]ROCK [2]PAPER [3]SCISSORS :", 1, 3);

    return (enRockPaperScissors)playerChoice;
}
enRockPaperScissors GenerateRandomChoice()
{
    return (enRockPaperScissors)GenerateRandomNumberInRange(1, 3);
}

void GetWinnerScreenColor(enWinner Winner)
{
    // Windows-specific console commands
    switch (Winner)
    {
    case PLAYER:
        system("color 2F");
        break;
    case COMPUTER:
        system("color 4F");
        break;
    case DRAW:
        system("color 60");
        break;
    default:
        system("color 0A");
        break;
    }
}

// Round
enWinner CheckRoundWinner(stRoundInfo Round)
{
    if (Round.PlayerChoice == Round.ComputerChoice)
        return DRAW;

    if (
        (Round.PlayerChoice == ROCK && Round.ComputerChoice == SCISSORS) ||
        (Round.PlayerChoice == SCISSORS && Round.ComputerChoice == PAPER) ||
        (Round.PlayerChoice == PAPER && Round.ComputerChoice == ROCK)
        )
        return PLAYER;

    return COMPUTER;
}
void PLayRound(stRoundInfo& Round)
{
    Round.PlayerChoice = ReadPlayerChoice();
    Round.ComputerChoice = GenerateRandomChoice();
    Round.Winner = CheckRoundWinner(Round);
}
void StartRoundScreen(stRoundInfo& Round)
{
    cout << "\nRound [" << Round.RoundNumber << "] begins: \n";
}
void PrintRoundResults(stRoundInfo Round)
{
    cout << "_________" << "Round [" << Round.RoundNumber << "] " << "_________" << endl;
    cout << "Player Choice: " << GetChoiceString(Round.PlayerChoice) << endl;
    cout << "Computer Choice: " << GetChoiceString(Round.ComputerChoice) << endl;
    cout << "Round Winner: " << GetWinnerString(Round.Winner) << endl;
    cout << "___________________________" << endl;
    cout << endl;
}
void EndRoundScreen(stRoundInfo Round)
{
    GetWinnerScreenColor(Round.Winner);
    PrintRoundResults(Round);
}

// Game
enWinner CheckGameWinner(stGameInfo Game)
{
    if (Game.PlayerWinRoundCounter == Game.ComWinRoundCounter)
        return DRAW;
    return Game.PlayerWinRoundCounter > Game.ComWinRoundCounter ? PLAYER : COMPUTER;
}
void IncreaseGameCounters(stGameInfo& Game, enWinner RoundWinner)
{
    if (RoundWinner == DRAW)
        Game.DrawRoundCounter++;
    else
        RoundWinner == PLAYER ? Game.PlayerWinRoundCounter++ : Game.ComWinRoundCounter++;
}
void PrintGameResults(stGameInfo Game)
{
    cout << endl;
    cout << "\t" << "_______________" << " [Game Results] " << "______________" << endl;
    cout << "\t" << "Game Rounds\t\t: " << Game.RoundsNumber << endl;
    cout << "\t" << "Player Won times\t: " << Game.PlayerWinRoundCounter << endl;
    cout << "\t" << "Computer Won times\t: " << Game.ComWinRoundCounter << endl;
    cout << "\t" << "Draw times\t\t: " << Game.DrawRoundCounter << endl;
    cout << "\t" << "Winner\t\t\t: " << GetWinnerString(Game.Winner) << endl;
    cout << "\t" << "_____________________________________________" << endl;
    cout << endl;
}
void GameOverScreen(stGameInfo Game)
{
    GetWinnerScreenColor(Game.Winner);
    cout << "\t" << "_____________________________________________" << endl;
    cout << "\t\t" << "   +++ G a m e O v e r +++" << endl;
    cout << "\t" << "_____________________________________________" << endl;
}
void PlayGame()
{
    stGameInfo game;

    game.RoundsNumber = (short)ReadPositiveNumberInRange("How Many Rounds? [ From (1) to (10) ]", 1, 10);

    for (short i = 1; i <= game.RoundsNumber; i++)
    {
        stRoundInfo round;
        round.RoundNumber = i;

        StartRoundScreen(round);
        PLayRound(round);

        IncreaseGameCounters(game, round.Winner);

        EndRoundScreen(round);
    }
    game.Winner = CheckGameWinner(game);

    GameOverScreen(game);
    PrintGameResults(game);
}

void ResetScreen()
{
    // Windows-specific console commands
    system("cls");
    system("color 0F");
}
int main()
{
    srand((unsigned)time(NULL));

    bool choice = false;
    do
    {
        ResetScreen();

        PlayGame();

        choice = ReadYesNo("Play Again? Y Or N?");

    } while (choice);
}