#include <iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
enum enGameLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOperation { add = 1, sub = 2, Mul = 3, Div = 4, Mixx = 5 };
enum enResult { resTrue = 1, resfalse = 0 };
struct stRound {
    int NumberRound;
    string level;
    string operation;
    enResult resultTrueOrfalse;
    int number1;
    int number2;
    int ans;
};
struct stgame {
    int NumberRound;
    enGameLevel level;
    enOperation operation;
    int numberTrue;
    int numberfalse;
    string name;

};
int ReadNumberOfRound() {
    int n;
    do {
        cout << "\n how many Question you want to answre ?" << endl;
        cin >> n;
    } while (n < 1 || n > 10);
    return n;
}
int RandomNumber(int from, int to) {
    int random = rand() % (to - from + 1) + from;
    return random;
}
enGameLevel CoichePlayerLevel() {
    int n;
    cout << "\nEnter question level [1]Easy ,[2]Med, [3]hard ,[4]Mix?" << endl;
    cin >> n;

    return (enGameLevel)n;
}
enOperation CoichePlayeroperation() {
    int n;
    cout << "\nEnter operation Type [1]add ,[2]sub, [3]Mul ,[4]div, [5]Mix?" << endl;
    cin >> n;

    return (enOperation)n;
}
void createquesion(enGameLevel Level, enOperation operation, stRound& Round) {
    if (enGameLevel::Mix) {
        Level = (enGameLevel)RandomNumber(1, 3);
    }
    if (Level == enGameLevel::Easy) {
        Round.number1 = RandomNumber(1, 10);
        Round.number2 = RandomNumber(1, 10);
    }
    else if (Level == enGameLevel::Med) {
        Round.number1 = RandomNumber(10, 20);
        Round.number2 = RandomNumber(10, 20);
    }
    else if (Level == enGameLevel::Hard) {
        Round.number1 = RandomNumber(20, 50);
        Round.number2 = RandomNumber(20, 50);
    }
    if (operation == enOperation::Mixx)
    {
        operation = (enOperation)RandomNumber(1, 4);
    }
    if (operation == enOperation::add) {
        Round.operation = "+";
        Round.ans = Round.number1 + Round.number2;
    }
    else if (operation == enOperation::sub) {
        Round.operation = "-";
        Round.ans = Round.number1 - Round.number2;
    }
    else if (operation == enOperation::Mul) {
        Round.operation = "*";
        Round.ans = Round.number1 * Round.number2;
    }
    else if (operation == enOperation::Div) {
        Round.operation = "/";
        Round.ans = Round.number1 / Round.number2;
    }
}

enResult roundInGame(enGameLevel level, enOperation operation) {
    stRound Round;
    int yourAns;
    createquesion(level, operation, Round);

    cout << Round.number1 << endl;
    cout << Round.number2 << " " << Round.operation << endl;
    cout << "___________" << endl;
    cin >> yourAns;
    if (yourAns == Round.ans)
    {

        cout << "Right Answer :-) " << endl;
        system("color 2f");
        return enResult::resTrue;
    }
    else {
        cout << "Rwong Answer :-( " << endl;
        system("color 4f");
        cout << "\a";
        return enResult::resfalse;
    }
}
void RoundsGame(enGameLevel Level, enOperation Operation, stgame& game, int counter) {
    cout << "round [" << counter << "/" << game.NumberRound << "]" << endl;
    enResult  result = roundInGame(Level, Operation);
    game.level = Level;
    game.operation = Operation;
    if (result == enResult::resTrue)
    {
        game.numberTrue++;
    }
    else
    {
        game.numberfalse++;
    }
}
void PrintGameResult(stgame game) {
    cout << "\n\n_________________________\n\n";
    cout << "\n\n Final Result is";
    if (game.numberTrue > game.numberfalse)
    {
        cout << "PASS :-)" << endl;
        system("color 2f");
    }
    else if (game.numberTrue < game.numberfalse)
    {
        cout << "Fault :-(" << endl;
        system("color 4f");
    }
    else
    {
        cout << "Draw :-()" << endl;
        system("color 6f");
    }
    cout << "\n_________________________\n\n";
    cout << "Number of Question is : " << game.NumberRound << endl;
    cout << "Question Level is : ";
    if (game.level == enGameLevel::Easy)
        cout << "EASY" << endl;
    else if (game.level == enGameLevel::Med)
        cout << "MED" << endl;
    else if (game.level == enGameLevel::Hard)
        cout << "HARD" << endl;
    else
        cout << "MIX" << endl;
    cout << "Operation Question is : ";
    if (game.operation == enOperation::add)
        cout << "ADD" << endl;
    else if (game.operation == enOperation::sub)
        cout << "SUB" << endl;
    else if (game.operation == enOperation::Mul)
        cout << "MUL" << endl;
    else if (game.operation == enOperation::Div)
        cout << "DIV" << endl;
    else
        cout << "MIX" << endl;
    cout << "Number of Question is : " << game.NumberRound << endl;
    cout << "Number of Right Answer : " << game.numberTrue << endl;
    cout << "Number of wrong Answer : " << game.numberfalse << endl;
    cout << "\n_________________________\n\n";
}
void RecursionGame() {
    stgame game;
    game.NumberRound = ReadNumberOfRound();
    int counter = 1;
    game.numberTrue = 0;
    enGameLevel Level = CoichePlayerLevel();
    enOperation Operation = CoichePlayeroperation();

    game.numberfalse = 0;
    while (counter <= game.NumberRound) {
        RoundsGame(Level, Operation, game, counter);
        counter++;
    }
    PrintGameResult(game);
}

void startGame()
{
    char res = 'y';
    do {
        system("cls");
        system("color 0f");
        RecursionGame();
        cout << "Do You want  to play again ?Y/N" << endl;
        cin >> res;
    } while (res == 'Y' || res == 'y');

}
int main() {
    srand((signed)time(NULL));
    startGame();
    return 0;
}