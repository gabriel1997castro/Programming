#include <iostream>
#include <string.h>
#include <fstream>
#include <locale>

using namespace std;

ofstream registro;


void tamanhoFixo()
{
	int sizeN = 15;
	int sizeS = 50;
	int sizeE = 70;
	int sizeC = 8;
	int sizeT = 15;
	char nome[sizeN], sobrenome[sizeS], endereco[sizeE], cep[sizeC], telefone[sizeT];
	char arquivo[50];
	cout << "Digite o nome do arquivo onde deseja guardar as informações (arquivo.txt):" << endl;
	cin >> arquivo;
	registro.open(arquivo, ofstream::out | ofstream::app);
	while(registro.fail()){
        cout<<"Falha ao abrir arquivo e/ou ao tentar criar arquivo!\n Tente abrir outro ou criar um novo, digite novamente:"<<endl;
        cin >> arquivo;
        registro.open(arquivo, ofstream::out | ofstream::app);
	}
	//-------------------------------------------------------------------------------------------------------------------------------
	registro << endl;

	cin.clear();
	cin.ignore(256, '\n');
	cout << "Digite seu nome:\n";
	cin.getline(nome, sizeN);
	while (cin.fail())
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Nome não válido. Por favor digite novamente com no máximo 15 letras" << endl;
        cin.getline(nome, sizeN);
    }
	registro << nome << '|';
	//-------------------------------------------------------------------------------------------------------------------------------
	cout << "Digite seu sobrenome:\n";
	cin.getline(sobrenome, sizeS);
	while (cin.fail())
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Sobrenome não válido. Por favor digite novamente com no máximo 50 letras" << endl;
		cin.getline(sobrenome, sizeS);
    }
	registro << sobrenome << '|';
	//-------------------------------------------------------------------------------------------------------------------------------
	cout << "Digite seu endereço:\n";
	cin.getline(endereco, sizeE);
	while (cin.fail())
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Endereço não válido. Por favor digite novamente com no máximo 70 letras" << endl;
		cin.getline(endereco, sizeE);
		
    }
	//-------------------------------------------------------------------------------------------------------------------------------
   	registro << endereco << '|';
	cout << "Digite seu CEP:\n";
	cin >> cep;
	while (cin.fail())
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Cep não válido. Por favor digite novamente com no máximo 8 números" << endl;
		cin >> cep;
		
    }
	registro << cep << '|';
	//-------------------------------------------------------------------------------------------------------------------------------
	cout << "Digite seu telefone:\n";
	cin >> telefone;
	while (cin.fail())
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Telefone não válido. Por favor digite novamente com no máximo 15 números" << endl;
		cin >> telefone;
		
    }
	registro << telefone << '|';

	registro.close();
}

int main(int argc, char const *argv[])
{
	std::locale::global(std::locale("en_US.utf8"));
	std::wcout.imbue(std::locale());

	tamanhoFixo();
	return 0;
}