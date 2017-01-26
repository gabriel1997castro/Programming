#include <iostream>

using namespace std;

int main()
{
	int vidas = 10;
	char letra = 'B';
	float decimal = 3.999;
	double decimal2 = 3.2;
	bool vivo = true;
	string nome = "Gabriel";

	cout << vidas << "\n" << letra << "\n";
	cout << decimal <<	"\n";
	cout << decimal2 <<	"\n";
	cout << vivo <<	"\n";
	cout << nome <<	"\n";

	cout << "Digite o número de vidas:\n";
	cin >> vidas;
	cout << "Digite uma letra:\n";
	cin >> letra;
	cout << "Digite um decimal:\n";
	cin >> decimal;
	cout << "Digite outro decimal:\n";
	cin >> decimal2;
	cout << "Digite 1 ou 0:\n";
	cin >> vivo;
	cout << "Digite um  nome:\n";
	cin >> nome;

	cout << "\nNovos valores:\n";
	cout << vidas << "\n" << letra << "\n";
	cout << decimal <<	"\n";
	cout << decimal2 <<	"\n";
	cout << vivo <<	"\n";
	cout << nome <<	"\n";

	return 0;
}