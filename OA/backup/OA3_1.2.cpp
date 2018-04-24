#include <iostream>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <fstream>
#include <locale>
#include <math.h>
#include <stdlib.h>

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

void toArray(int number, char* ch)
    {
        int n = log10(number) + 1;
        int i;
      	//char *numberArray = (char *)calloc(n, sizeof(ch));
        for ( i = 0; i < n; ++i, number /= 10 )
        {
            ch[i] = number % 10;
        }
    }

void tamanhoFixo()
{
	int sizeN = 15;
	int sizeS = 50;
	int sizeE = 70;
	int sizeC = 15;
	int sizeT = 15;
	int cep_i, number_i;
	char nome[sizeN], sobrenome[sizeS], endereco[sizeE], cep[sizeC], telefone[sizeT];
	char arquivo[50];
	char *aux;

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
	fgets(nome, sizeof(nome), stdin);
	fflush(stdin);
    __fpurge(stdin);
    nome[strlen(nome)-1] = '#';
    nome[strlen(nome)] = '#';
    cout << nome << endl;
	registro << nome;

	//-------------------------------------------------------------------------------------------------------------------------------
	cout << "Digite seu sobrenome:\n";
	fgets(sobrenome, sizeof(sobrenome), stdin);
	fflush(stdin);
    __fpurge(stdin);
    sobrenome[strlen(sobrenome)-1] = '#';
    sobrenome[strlen(sobrenome)] = '#';
    cout << sobrenome << endl;
	registro << sobrenome;

	//-------------------------------------------------------------------------------------------------------------------------------
	cout << "Digite seu endereço:\n";
	fgets(endereco, sizeof(endereco), stdin);
	fflush(stdin);
    __fpurge(stdin);
	endereco[strlen(endereco)-1] = '#';
    endereco[strlen(endereco)] = '#';
    cout << endereco << endl;
    registro << endereco;
    //-------------------------------------------------------------------------------------------------------------------------------
	cout << "Digite seu cep:\n";
	cin >> cep_i;
    toArray(cep_i, cep);
	cout << cep << endl;
	cep[strlen(cep)-1] = '#';
	cep[strlen(cep)] = '#';
	registro << cep;

    //-------------------------------------------------------------------------------------------------------------------------------
	/*cout << "Digite seu telefone:\n";
	fgets(telefone, sizeof(telefone), stdin);
	fflush(stdin);
    __fpurge(stdin);
    telefone[strlen(telefone)-1] = '#';
    telefone[strlen(telefone)] = '#';
    cout << telefone << endl;
	registro << telefone;*/
	registro.close();
}

int main(int argc, char const *argv[])
{
	std::locale::global(std::locale("en_US.utf8"));
	std::wcout.imbue(std::locale());
	tamanhoFixo();
	
	return 0;
}