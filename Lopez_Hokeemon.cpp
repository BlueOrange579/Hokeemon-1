//Lopez_Hokeemon.cpp
// Luis Lopez, CISP 400
// 4/6/2018
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;


//Specification 6 - Create Creature class
class Creature{
private:
	int hunger;
	int boredom;
public:
	string name;
//Specification 3 - Set Hunger & Boredom to random numbers
	Creature(int starving, int bored) {
		hunger = starving;
		boredom = bored;
	}
	int menu();
	void Listen();
	void Play();
	void Feed();
	void PassTime();
	bool DeathStarvation();
	bool CatatonicState();
};



int main() {
	Creature hokeemon((rand() % 5) + 1, (rand() % 5) + 1);
	srand(time(nullptr));
	bool exit = false;
	bool exit2 = false;
	int choice;

	cout << "Welcome to the Magical Land where you can raise your own Hokeemon!\n";
	cout << "Hello, I'm a Hekeemon. Can I get a name? ";
//Feature 1- Name Hokeemon
	getline(cin, hokeemon.name);
	cout << "Thank You!. My name now is " << hokeemon.name << "!\n";

//Feature 2 - Play with Hokeemon till press 4
	while (exit != true && exit2 != true) {
		choice = hokeemon.menu();
		switch (choice) {
		case 1: hokeemon.Listen();
				exit = hokeemon.DeathStarvation();
				exit2 = hokeemon.CatatonicState();
				break;
		case 2: hokeemon.Play();
				exit = hokeemon.DeathStarvation();
				exit2 = hokeemon.CatatonicState();
				break;
		case 3: hokeemon.Feed();
				exit = hokeemon.DeathStarvation();
				exit2 = hokeemon.CatatonicState();
				break;
		case 4: cout << "Quitting..." << endl;
			exit = true;
		}
	}
	return 0;
}

//Specification 2 - Create numberic Menu
int Creature::menu() {
	int choice;
	cout << "1.Listen\n2.Play\n3.Feed\n4.Quit\n";
	cout << "Select an Activity: ";
	cin >> choice;

//Feature 3 - Input Validation
	while (choice > 4 || choice < 1) {
		cout << "Invalid Input. Try Again.\n";
		cin >> choice;
	}
	return choice;
}

//Specification 1- Implement PassTime() method
void Creature::PassTime() {
	hunger++;
	boredom++;
//Feature 4 - Prevents negative levels
	if (hunger < 0)
		hunger = 0;
	if (boredom < 0)
		boredom = 0;
}


void Creature::Listen() {
	cout << "THe Hunger level of " << name << " is " << hunger << "!\n";
	cout << "The Boredom level of " << name << " is " << boredom << "!\n";
	PassTime();
	cin.get();
	cin.get();
}

void Creature::Play() {
	cout << "You played with " << name << "!\n";
		boredom -= 4;
		PassTime();
		cin.get();
		cin.get();
}

void Creature::Feed() {
	cout << "You fed " << name << "!\n";
	hunger -= 4;
	PassTime();
	cin.get();
	cin.get();
}

//Specfication 4 - Death by starvation
bool Creature::DeathStarvation() {
	bool stop = false;
	if (hunger > 10) {
		cout << name << " died of starvation. You Lose.\n";
		cout << "Quitting...\n";
		stop = true;
	}
	return stop;
}

//Specification 5 - Catatonic State if boredom above 20
bool Creature::CatatonicState() {
	bool stop = false;
	if (boredom > 20) {
		cout << name << " is on  unresponsive catatonin state caused by boredom. You Lose.\n";
		cout << "Quitting...\n";
		stop = true;
	}
	return stop;
}
