#include <iostream>
#include <math.h>


using namespace std;


string converteDecimalBinario(int decimal) { //conversão de decimal para binário
    string binario = ""; //cria a string que irá armazenar o valor convertido
    if (decimal == 0) //se o usuário entrar com o valor 0, o retorno será 0, sem necessidade de conversão
    {
        return "0";
    }
    while (decimal > 0) //enquanto decimal for maior que 0 a conversão será feita por partes e será armazenada na string 'binario'
    {
        if (decimal % 2 == 1) //se o resto da divisão de 'decimal' por 2 for igual a 1, será adicionado o valor 1 na primeira posição da string
        {
            binario.insert(0,"1");
            decimal = decimal / 2; //divide decimal por 2 para a próxima parte do loop
        }
        else
        {
            binario.insert(0, "0"); //se o resto da divisão de 'decimal' por 2 não for 1, será adicionado o valor 0 na primeira posição da string
            decimal = decimal / 2; //divide decimal por 2 para a próxima parte do loop
        }
    }
    return binario; //retorna a string 'binario', que contem o valor convertido
}

int converteBinarioDecimal(int binario) { //conversão de binário para decimal
    int decimal = 0; //cria o inteiro 'decimal', que irá armazenar o valor convertido
    for (int i = 0; binario > 0; i++) //estrutura de repetição para rodar todas as etapas da conversão
    {
        decimal = decimal + pow(2, i) * (binario % 10); //decimal irá receber, a cada repetição, a potencia de base 2 de cada casa do número binário vezes o resto da divisão de binário por 10
        binario = binario / 10;                         //binário é dividido por 10 para a próxima repetição
    }
    return decimal; //retorna o inteiro decimal, contendo o valor convertido
}



int main()
{
    setlocale(LC_ALL, "Portuguese"); //permite caracteres com acentuação para print no console
    int sel = 0; //declara a variável de seleção para navegação pelo menu
    int num = 0; //delcara a variável num, que receberá o valor a ser convertido


    while (sel != 3) { //estrutura de repetição para o programa não fechar até ser selecionada a opção de saída

        cout << "\tConversor de Bases:\n\n"; //Menu
        cout << "Selecione a conversão desejada:\n (1)Decimal para binário\n (2)Binário para decimal\n\n Para sair pressione 3\n\n";
        cin >> sel; //usuário entra com a opção desejada de conversão, ou a opção de fechar o programa
        system("CLS"); //limpa o console para manter a tela mais limpa

        switch (sel) { //switch de seleção das opções do menu
            case 3:
                exit(0); //opção de saída

            case 1: //menu de conversão decimal para binário
                cout << "Informe o decimal para a conversão:\n"; 
                cin >> num; //o usuário entra com o valor decimal para conversão
                system("CLS");
                cout << "O valor decimal: "<< num <<" corresponde ao binario: " << converteDecimalBinario(num) << "\n"; //printa na tela o retorno da função de conversão
                system("PAUSE"); //pause para manter o valor na tela sem nenhum novo texto sendo inserido no console
                system("CLS");
                break;

            case 2: //menu de conversão binário para decimal
                cout << "Informe o binário para a conversão:\n";
                cin >> num; //o usuário entra com o valor binário para conversão
                system("CLS");
                cout << "O valor binario: "<< num <<" corresponde ao decimal: " << converteBinarioDecimal(num) << "\n"; //printa na tela o retorno da função de conversão
                system("PAUSE"); //pause para manter o valor na tela sem nenhum novo texto sendo inserido no console
                system("CLS");
                break;

            default: //caso o usuário entre com qualquer valor diferente dos apresentados no menu inicial, é informado que é necessário selecionar uma opção valida
                cout << "Selecione uma opção válida...\n\n";
                system("PAUSE");
                system("CLS");
                break;
        }
    }
}
