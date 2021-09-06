#include "conversorbases.h"

ConversorBases::ConversorBases()
{

}

double ConversorBases::converteParaDecimal(char *V, int a)
{
    double nTotal = 0;
    int X = strlen(V);
    int i = 0;//contador
    std::vector <int> inteiros;//guarda todas as posicoes em decimal para conversao da parte inteira
    std::vector <int> partFlutuante;//guarda todas as posicoes em decimal para conversao da parte real
    inteiros.push_back(0);
    partFlutuante.push_back(0);
    while( X>i && V[i]!='.')//parte inteira
    {
        if(V[i] >= '0' && V[i]<= '9')
        {
            double aux = V[i] - '0';
            i++;
            inteiros.push_back(aux);//transforma em double
        }
        if(V[i] >='A' && V[i]<='Z')
        {
            int guarda = i;//para guardar a posicao
            i++;
            int contFormula=0;
            while(V[i] >='a' && V[i] <='z')
            {
                i++;
                contFormula++;
            }
            int formula = 9 + (contFormula*26) + (V[guarda] -64);//o numero atual da base esta em decimal
            inteiros.push_back(formula);
        }
    }
    if(V[i] =='.')
    {
        i++;
        int auxConta = 0;
        while( auxConta<5)
        {
            if(V[i] >= '0' && V[i]<= '9')
            {
                double aux = V[i] - '0'; //transforma em double
                i++;
                partFlutuante.push_back(aux);
            }
            else
            {
                if(V[i] >='A' && V[i]<='Z')
                {
                    int guarda = i;//para guardar a posicao
                    i++;
                    int contFormula=0;
                    while(V[i] >='a' && V[i] <='z')
                    {
                        i++;
                        contFormula++;
                    }
                    int formula = 9 + (contFormula*26) + V[guarda] -64;//o numero atual da base esta em decimal
                    partFlutuante.push_back(formula);
                }
            }
            auxConta++;
        }

    }
    int partInteiros = inteiros.size()-1;
    int contAux=0;
    for(int i = partInteiros; i > 0;i--)
    {
        nTotal += inteiros[i]*(pow(a,contAux));
        contAux++;
    }
    int partDouble = partFlutuante.size()-1;
    for(int i = 1; i <= partDouble;i++)
    {
        nTotal += partFlutuante[i]*(pow(a,-i));
    }
    return nTotal;
}
std::string ConversorBases::converteParaBaseDesejada(double numero, int base)
{
    //parte inteira
    std::vector<int> resto;
    std::vector <char> convertido;
    int restoDivisao;
    int parteInteira= (int)numero;

    //variaveis parte decimal
    double parteReal = numero - (int)numero;
    std::vector<int> restoReal;
    std::vector <char> convertidoReal;
    int restoDivisaoReal;

    while(parteInteira>=1)
    {
        restoDivisao = parteInteira % base;
        parteInteira = parteInteira/base;
        resto.push_back(restoDivisao);//guarda todo resto da divisao
    }
    int tamanhoVector= resto.size()-1;
    for(int i = tamanhoVector; i >=0;i--)
    {
        if(resto[i] >=0 && resto[i]<=9)
        {
            convertido.push_back(resto[i]+'0');//convertendo para char
        }
        else
        {
            int guardaQtdLmin = (resto[i]-9)/26;//guarda quantidade de letras minusculas
            int aux = (resto[i]-9)%26;//guarda a posicao dentro do alfabeto
            convertido.push_back(aux+64);
            for(int i = 0;i < guardaQtdLmin;i++)
            {
                convertido.push_back(aux+96);
            }
        }
    }
    std::string s(convertido.begin(),convertido.end());
    if(numero-int(numero) >0)
    {
        for(int i =0; i<6;i++)
        {
            restoDivisaoReal = parteReal * base;
            parteReal = parteReal*base - restoDivisaoReal;
            restoReal.push_back(restoDivisaoReal);//guarda todo resto da divisao
        }
        int tamanhoVectorReal= restoReal.size()-1;
        for(int i = 0; i < tamanhoVectorReal;i++)
        {
            if(restoReal[i] >=0 && restoReal[i]<=9)
            {
                convertidoReal.push_back(restoReal[i]+'0');//convertendo para char
            }
            else
            {
                int guardaQtdLmin = (restoReal[i]-9)/26;//guarda quantidade de letras minusculas
                int aux = (restoReal[i]-9)%26;//guarda a posicao dentro do alfabeto
                convertido.push_back(aux+64);
                for(int i = 0;i < guardaQtdLmin;i++)
                {
                    convertido.push_back(aux+96);
                }
            }
        }
        std::string sReal(convertidoReal.begin(),convertidoReal.end());
        s = s+"."+sReal;
    }
    return s;
}
