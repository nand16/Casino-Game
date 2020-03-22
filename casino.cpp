#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<dos.h>


using namespace std;

class casino
{
  string playerName;
  int amount;
  int bettingAmount;
  int guess;
  int dice;
  char choice;
 public:
   casino()
  {
    srand(time(0)); // "Seed" the random generator
  }
 // void input1();
  void input();

  void guessing();
  void drawLine(int n,char symbol);
  void rules();
};
void casino::drawLine(int n,char symbol)
{
  for(int i=0; i<n; i++)
        cout << symbol;
        cout << "\n" ;
}
void casino::input()
{
    drawLine(60,'_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
    drawLine(60,'_');


   //srand(time(0));



    cout << "\n\nEnter Your Name : ";
    getline(cin, playerName);

    cout << "\n\nEnter Deposit amount to play game : Rs.";
    cin >> amount;
 }

void casino::rules()
{
 system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}
void casino::guessing()
{
 do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is Rs. " << amount << "\n";

		// Get player's betting amount
        do
        {
            cout <<playerName<<", enter money to bet : Rs. ";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        }while(bettingAmount > amount);

		// Get player's numbers
        do
        {
            cout << "Guess your number to bet between 1 to 10 : ";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "Please check the number!! should be between 1 to 10\n"
                    <<"\nRe-enter data\n ";
        }while(guess <= 0 || guess > 10);

        dice = rand()%10 + 1; // Will hold the randomly generated integer between 1 and 10

        if(dice == guess)
        {
            cout << "\n\nGood Luck!! You won Rs." << bettingAmount * 10;
            amount = amount + bettingAmount * 10;
        }
        else
        {

            cout << "Bad Luck this time !! You lost Rs. "<< bettingAmount <<"\n";
            amount = amount - bettingAmount;
        }

        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have Rs. " << amount << "\n";
        if(amount == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
	cout << "\n\n\n";
       drawLine(70,'=');
       cout << "\n\nThanks for playing game. Your balance amount is Rs. " << amount << "\n\n";
       drawLine(70,'=');
}
int main()
{
	casino c1;
	system("color 0D");
	c1.input();
	c1.guessing();
 return 0;
}