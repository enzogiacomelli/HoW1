#include <iostream>
#include <math.h>


using namespace std;


string converteDecimalBinario(int decimal) { //convers�o de decimal para bin�rio
    string binario = ""; //cria a string que ir� armazenar o valor convertido
    if (decimal == 0) //se o usu�rio entrar com o valor 0, o retorno ser� 0, sem necessidade de convers�o
    {
        return "0";
    }
    while (decimal > 0) //enquanto decimal for maior que 0 a convers�o ser� feita por partes e ser� armazenada na string 'binario'
    {
        if (decimal % 2 == 1) //se o resto da divis�o de 'decimal' por 2 for igual a 1, ser� adicionado o valor 1 na primeira posi��o da string
        {
            binario.insert(0,"1");
            decimal = decimal / 2; //divide decimal por 2 para a pr�xima parte do loop
        }
        else
        {
            binario.insert(0, "0"); //se o resto da divis�o de 'decimal' por 2 n�o for 1, ser� adicionado o valor 0 na primeira posi��o da string
            decimal = decimal / 2; //divide decimal por 2 para a pr�xima parte do loop
        }
    }
    return binario; //retorna a string 'binario', que contem o valor convertido
}

int converteBinarioDecimal(int binario) { //convers�o de bin�rio para decimal
    int decimal = 0; //cria o inteiro 'decimal', que ir� armazenar o valor convertido
    for (int i = 0; binario > 0; i++) //estrutura de repeti��o para rodar todas as etapas da convers�o
    {
        decimal = decimal + pow(2, i) * (binario % 10); //decimal ir� receber, a cada repeti��o, a potencia de base 2 de cada casa do n�mero bin�rio vezes o resto da divis�o de bin�rio por 10
        binario = binario / 10;                         //bin�rio � dividido por 10 para a pr�xima repeti��o
    }
    return decimal; //retorna o inteiro decimal, contendo o valor convertido
}



int main()
{
    setlocale(LC_ALL, "Portuguese"); //permite caracteres com acentua��o para print no console
    int sel = 0; //declara a vari�vel de sele��o para navega��o pelo menu
    int num = 0; //delcara a vari�vel num, que receber� o valor a ser convertido


    while (sel != 3) { //estrutura de repeti��o para o programa n�o fechar at� ser selecionada a op��o de sa�da

        cout << "\tConversor de Bases:\n\n"; //Menu
        cout << "Selecione a convers�o desejada:\n (1)Decimal para bin�rio\n (2)Bin�rio para decimal\n\n Para sair pressione 3\n\n";
        cin >> sel; //usu�rio entra com a op��o desejada de convers�o, ou a op��o de fechar o programa
        system("CLS"); //limpa o console para manter a tela mais limpa

        switch (sel) { //switch de sele��o das op��es do menu
            case 3:
                exit(0); //op��o de sa�da

            case 1: //menu de convers�o decimal para bin�rio
                cout << "Informe o decimal para a convers�o:\n"; 
                cin >> num; //o usu�rio entra com o valor decimal para convers�o
                system("CLS");
                cout << "O valor decimal: "<< num <<" corresponde ao binario: " << converteDecimalBinario(num) << "\n"; //printa na tela o retorno da fun��o de convers�o
                system("PAUSE"); //pause para manter o valor na tela sem nenhum novo texto sendo inserido no console
                system("CLS");
                break;

            case 2: //menu de convers�o bin�rio para decimal
                cout << "Informe o bin�rio para a convers�o:\n";
                cin >> num; //o usu�rio entra com o valor bin�rio para convers�o
                system("CLS");
                cout << "O valor binario: "<< num <<" corresponde ao decimal: " << converteBinarioDecimal(num) << "\n"; //printa na tela o retorno da fun��o de convers�o
                system("PAUSE"); //pause para manter o valor na tela sem nenhum novo texto sendo inserido no console
                system("CLS");
                break;

            default: //caso o usu�rio entre com qualquer valor diferente dos apresentados no menu inicial, � informado que � necess�rio selecionar uma op��o valida
                cout << "Selecione uma op��o v�lida...\n\n";
                system("PAUSE");
                system("CLS");
                break;
        }
    }
}
