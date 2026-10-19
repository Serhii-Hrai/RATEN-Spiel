#include <iostream>
#include <time.h>
using namespace std;

const int Max = 12;

void initGame();
bool playGame(int Zufall, int Eingabe);
void evaluateGame(bool Geraten);

int main()
{
	int Zufall = 0;
	int Eingabe = 0;
	char Wahl = 'j';
	bool Geraten = false;

	initGame();

	while (Wahl != 'n') {
		Geraten = playGame(Zufall, Eingabe);
		evaluateGame(Geraten);
		cout << "Nochmal (j/n)? "; cin >> Wahl;
	}
	cout << "Das wars.\n";
}

void initGame() {
	locale dt("de_DE.utf-8"); locale::global(dt);
	srand(time(NULL));
}
bool playGame(int Zufall, int Eingabe) {
	Zufall = rand() % 1000 + 1;
	for (int Nr = 0; Nr < Max; Nr++) {
		cout << Nr + 1 << ". Rate mal: "; cin >> Eingabe;
		if (Eingabe < Zufall)
			cout << Eingabe << " ist zu klein!\n";
		if (Eingabe > Zufall)
			cout << Eingabe << " ist zu gross!\n";
		if (Eingabe == Zufall) return true;
	}
	return false;
}
void evaluateGame(bool Geraten) {
	if (Geraten)
		cout << "Prima, richtig geraten.\n";
	else
		cout << "Schade, hat nicht geklappt.\n";
}

