#include<iostream>
using namespace std;

void mostraTitulo();
void mostraInstrucoes();
void iniciar(int quadro[][3]);
char preencheBloco(int quadro);
void montaTabuleiro(int quadro[][3]);
void realizaMovimento(int quadro[][3], int);
int checaContinue(int *quadro[3]);
int checaVitoria(int *quadro[3]);
int jogo(int quadro[][3]); 
void placar(int,int &, int &);

int main(){
    int quadro [3][3];
    int contador = 0,jogador1=0,jogador2=0,resultado;
    do
    {
        mostraTitulo();
        mostraInstrucoes();
        iniciar(quadro);
        resultado = jogo(quadro);
        montaTabuleiro(quadro);
        placar(resultado,jogador1,jogador2);
        cout<<"\n Deseja jogar novamente?"<<endl;
        cout<<"0- Nao"<<endl;
        cout<<"1- Jogar novamente"<<endl;
        cin >> contador;
    } while (contador);    
    cout<<"\n Fim de jogo"<<endl;
    return 0;
}

//funcao que mostra o titulo do jogo
void mostraTitulo(){
    //colque o titulo nessa funcao
    // cout<<"Titulo"<<endl;//pode utilizar essa funcao
}

//funcao que mostra as instrucoes do jogo
void mostraInstrucoes(){
    //coloque as instrucoes nesta funcao
    // cout<<"Instrucoes"<<endl;//pode utilizar essa funcao
}

//inicia o tabuleiro colocando 0 em todas as casas
void iniciar(int quadro[][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           quadro[i][j]=0;
        }
    }
}

//coloca ' ' se o valor eh 0, coloca X se o valor eh 1, e se for um valor diferente, coloca O
char preencheBloco(int bloco){
    if(bloco == 0){
        return ' ';
    }else if (bloco==1)
    {
        return 'X';
    } else{
        return 'O';
    }
}

//monta o tabuleiro todo
void montaTabuleiro(int quadro[][3]){
    cout<<endl;
    for (int linha = 0; linha < 3; linha++)
    {
        cout<<" "<< preencheBloco(quadro[linha][0]) <<" |";
        cout<<" "<< preencheBloco(quadro[linha][1]) <<" |";
        cout<<" "<< preencheBloco(quadro[linha][2]) <<endl;
        if (linha!=2)
        {
            cout<<"___ ___ ___\n"<<endl;
        }   
    }   
}

//funcao que realiza as jogadas
void realizaMovimento(int quadro[][3], int jogador){
    int linha, coluna, checa;
    do
    {
        cout<<"Linha: ";
    cin>>linha;
    cout<<"Coluna: ";
    cin>>coluna;
    linha--;coluna--;
    checa = quadro[linha][coluna] || linha<0 || linha>2 || coluna<0 || coluna>2;
    if(checa){
        cout<<"Essa casa nao esta vazia ou esta fora do intervalo 3x3"<<endl;
    }
    } while (checa);
    if (jogador==0)
    {
        quadro[linha][coluna]=1;
    } else{
        quadro[linha][coluna]=-1;
    }
}

//funcao que checa se ainda tem espaco em branco no quadro
int checaContinue(int quadro[][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(quadro[i][j]==0){
                return 1;
            }  
        }
    }
    return 0;
}

int checaVitoria(int quadro[][3]){
    int linha, coluna,soma;
    //verificacao de vitoria em linha
    for(linha=0;linha<3;linha++){
        soma=0;
        for (coluna = 0; coluna<3; coluna++)
        {
            soma += quadro[linha][coluna];
        } 
        if(soma==3){
            return 1;
        }
        if (soma==-3)
        {
            return -1;
        }
    }
    //verificacao de vitoria em coluna
    for (coluna = 0; coluna<3; coluna++)
    {
        soma=0;
        for (linha = 0; linha<3; linha++)
        {
            soma+=quadro[linha][coluna];
            if (soma==3)
            {
                return 1;
            }
            if(soma==-3){
                return -1;
            }
        }
    }
    //verificacao de vitoria em diagonal
    soma=0;
    for(linha = 0;linha<3;linha++){
        soma+= quadro[linha][linha];
    }
    if(soma==3){
        return 1;
    }
    if (soma==-3)
    {
       return -1;
    }
    soma =quadro[0][2]+quadro[1][1]+quadro[2][0];
    if(soma==3){
        return 1;
    }
    if (soma==-3)
    {
       return -1;
    }
    return 0;
}

//funcao que realiza o jogo
int jogo(int quadro[][3]){
    int turno =0, continuar, vitoria;
   do
   {
        montaTabuleiro(quadro);
        cout<<"Vez do Jogador "<<1+turno%2<<endl;
        realizaMovimento(quadro,turno%2);
        turno++;
        continuar = checaContinue(quadro);
        vitoria = checaVitoria(quadro);
   } while (continuar && !vitoria);
    if(vitoria==1){
        cout<<"Jogador 1 ganhou!!!\n"<<endl;
        return 1;
    } else if (vitoria==-1)
    {
        cout<<"Jogador 2 ganhou!!!\n"<<endl;
        return 2;
    } else{
        cout<<"Empate\n"<<endl;
    }
    return 0;
}

//funcao que mostra o placar do jogo
void placar(int resultado, int &jogador1,int &jogador2){
    if(resultado==1){
        jogador1++;
    }
    if (resultado==2)
    {
        jogador2++;
    }
    cout<<"Placar: "<<endl;
    cout<<"Jogador 1| "<<jogador1<<" X "<<jogador2<<" |Jogador 2"<<endl;
}


