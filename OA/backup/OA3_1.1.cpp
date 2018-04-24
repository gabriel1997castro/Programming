#include <iostream>
#include <cstdio>
#include <stdio_ext.h>
#include <string.h>
#include <fstream>
#include <locale>

using namespace std;

ofstream registro;

//preencher as variáveis com hashes
void fillSpaces(char *nome, int size)
{
	for (int i = 0; i < size; ++i)
	{
		nome[i] = '#';
	}
}

void tamanhoFixo()
{
	int sizeN = 15;
	int sizeS = 50;
	int sizeE = 70;
	int sizeC = 15;
	int sizeT = 15;
	char nome[sizeN], sobrenome[sizeS], endereco[sizeE], cep[sizeC], telefone[sizeT];
	char arquivo[50];

	fillSpaces(nome, sizeN);
	fillSpaces(sobrenome, sizeS);
	fillSpaces(endereco, sizeE);
	fillSpaces(cep, sizeC);
	fillSpaces(telefone, sizeT);

	cout << "Digite o nome do arquivo onde deseja guardar as informações (arquivo.txt):" << endl;
	cin >> arquivo;
	registro.open(arquivo, ofstream::out | ofstream::app);
	while(registro.fail()){
        cout<<"Falha ao abrir arquivo e/ou ao tentar criar arquivo!\n Tente abrir outro ou criar um novo, digite novamente:"<<endl;
        cin >> arquivo;
        registro.open(arquivo, ofstream::out | ofstream::app);
	}

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
    nome[strlen(nome)] = '#';
    cout << nome << endl;
	registro << nome;

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
    sobrenome[strlen(sobrenome)] = '#';
    cout << sobrenome << endl;
	registro << sobrenome;

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
    endereco[strlen(endereco)] = '#';
    cout << endereco << endl;
    registro << endereco;

    cin.clear();
    //-------------------------------------------------------------------------------------------------------------------------------
	cout << "Digite seu cep:\n";
	scanf("%s", cep);
	cep[strlen(cep)] = '#';
	cout << cep << endl;
	registro << cep;

    //-------------------------------------------------------------------------------------------------------------------------------
	cout << "Digite seu telefone:\n";
	fgets(telefone, sizeof(telefone), stdin);
	fflush(stdin);
    telefone[strlen(telefone)] = '#';
    cout << telefone << endl;
	registro << telefone;
	registro.close();
}

int main(int argc, char const *argv[])
{
	std::locale::global(std::locale("en_US.utf8"));
	std::wcout.imbue(std::locale());
	tamanhoFixo();
	
	return 0;
}