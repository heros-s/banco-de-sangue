#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#define MAX_DOADORES 100
#define MAX_NOME     50

struct doador
{
    char nome[MAX_NOME + 1];
    int idade;
    float peso;
    bool estaNutrido;
    bool estaResfriado;
    bool consumiuAlcool;
    bool relacaoSexual;
};

typedef struct doador doador;

void to_lower(char * opcao)
{
    for(int i = 0; opcao[i] != '\0'; i++)
    {
        if(opcao[i] >= 'A' && opcao[i] <= 'Z')
        {
            opcao[i] += ('a' - 'A');
        }
    }
}

bool pegaResposta()
{
    char opcao[4];
    while(1)
    {
        scanf(" %3[^\n]s", opcao);
        to_lower(opcao);
        if(strcmp(opcao, "sim") == 0)
            return true;
        if(strcmp(opcao, "nao") == 0)
            return false;
        printf("As opcoes sao 'sim' ou 'nao'...\n");
    }
}

doador pegaDoador()
{
    doador x;
    
    printf("Nome completo (max %i caracteres): ", MAX_NOME);
    scanf(" %100[^\n]s", x.nome);

    printf("Idade: ");
    scanf("%i", &(x.idade));
    
    printf("Peso: ");
    scanf("%f", &(x.peso));

    printf("Esta bem alimentado? (sim/nao) ");
    x.estaNutrido = pegaResposta();
    
    printf("Esta resfriado? (s/n)");
    x.estaResfriado = pegaResposta();
    
    printf("Consumiu alcool nas ultimas 24h? (s/n) ");
    x.consumiuAlcool = pegaResposta();
    
    printf("Mantem relacoes sexuais com multipl@s parceir@s? (s/n) ");
    x.relacaoSexual = pegaResposta();
    
    return x;
}

bool estaApto(doador x)
{
    return x.idade >= 16
        && x.idade <= 69
        && x.peso >= 50
        && x.estaNutrido
        && !x.estaResfriado
        && !x.consumiuAlcool
        && !x.relacaoSexual;
}


int main()
{
    while
    system(CLEAR);

    printf("Bem vindo ao Hemobanco!\n");
    
    printf("Quantos doadores voce quer cadastrar (max %i)? ", MAX_DOADORES);
    int num_doadores;
    scanf("%i", &num_doadores);

    doador doadores[MAX_DOADORES];

    for(int i = 0; i < num_doadores; i++)
    {
        printf("Dados do doador %i:\n", i + 1);
        doadores[i] = pegaDoador();
    }

    for(int i = 0; i < num_doadores; i++)
    {
        if(estaApto(doadores[i]))
        {
            printf("doador %i - %s: esta apto!\n", i + 1, doadores[i].nome);
        }
        else
        {
            printf("doador %i - %s: nao esta apto!\n", i + 1, doadores[i].nome);
        }
    }
    
    return 0;
}