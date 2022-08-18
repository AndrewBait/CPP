#include <cctype>       //PARA MANIPULAÇÃO DE CARACTERES
#include <cmath>        //PARA CALCULAR OPERACOES E TRANSFORMACOES MATEMATICAS COMUNS
#include <iostream>     // ENTRADA E SAÍDA PADRÃO
#include <cstring>      // PARA USAR strcpy() e strcmp()
#include <fstream>      // MANIPULAR ARQUIVOS
#include <conio.h>      // PARA USAR getch()
#include <ctime>        // PARA PEGAR A DATA ATUAL DO SISTEMA
#include <windows.h>    // PARA TODAS AS FUNCOES DA API DO WINDOWS
using namespace std;

#define black     0 // Preto
#define blue      1 // Azul
#define green     2 // Verde
#define cyan      3 // Ciano
#define red       4 // Vermelho
#define magenta   5 // Magenta
#define brown     6 // Marrom
#define lgray     7 // Cinza claro
#define dgray     8 // Cinza escuro
#define lblue     9 // Azul claro
#define lgreen   10 // Verde claro
#define lcyan    11 // Ciano claro
#define lred     12 // Vermelho claro
#define lmagenta 13 // Magenta claro
#define yellow   14 // Amarelo
#define white    15 // Branco

void color(int COR_FUNDO, int COR_TEXTO)        // ALTERA A COR
{
  HANDLE TELA;
  int COR;
  TELA = GetStdHandle(STD_OUTPUT_HANDLE);

  if (COR_FUNDO<0 and COR_FUNDO>15 and COR_TEXTO<0 and
    COR_TEXTO > 15)
    COR = 15;
  else
    COR = COR_TEXTO + COR_FUNDO * 16;
  SetConsoleTextAttribute(TELA, COR);
  return;
}

void color()
{

}

void limpa(void)                                // LIMPAR TELA
{
  HANDLE TELA;
  DWORD ESCRITA = 0;
  COORD POS;
  TELA = GetStdHandle(STD_OUTPUT_HANDLE);
  POS.X = 0;
  POS.Y = 0;
  FillConsoleOutputCharacter(TELA, 32, 80 * 25, POS,
    &ESCRITA);
  SetConsoleCursorPosition(TELA, POS);
  return;
}

void pausa(short status) {                                          // PARA PAUSAR PROGRAMA E EXIBIR MENSAGEM
   if (status)                                                      // PARA ESCREVER A MENSAGEM ADICIONAL
      cout << endl;
      cout << "Pressione ";                                         // MENSAGEM ADICIONAL
      color(0,4);
      cout << "<";
      color(0,15);
      cout << "Enter";
      color(0,4);
      cout << ">";
      color(0,7);
      cout << " para confirmar...\n";                               // MENSAGEM PADRÃO
      cin.get();                                                    // SOLICITA LEITURA DE CARACTERE PARA PAUSAR EXECUÇÃO
   return;
}

char upper(char e) {
   return (97 <= e && e <= 122) ? e-32 : e;                 // TRANSFORMA CARACTERE MINÚSCULO EM MAIÚSCULO
}                                                           // SE 97 <= CARACTERE <= 122 ENTÃO ELE É MINÚSCULO\
                                                            // DIMINUINDO 32 CARACTERES DELE, É RETORNADA SUA VERSÃO\
                                                            // MAIÚSCULA CORRESPONDENTE NA TABELA ASCII

void lerstr(char *s) {                                      // CORRIGE A ENTRADA PARA CARACTERES MAIÚSCULOS
   char c;                                                  // USADA PARA CADA CARACTERE LIDO
   int pos = 0;                                             // QUANTIDADE DE CARACTERES LIDOS
   do {
      c = upper(getch());                                   // ARMAZENA O CARACTERE LIDO NA VARIÁVEL c
      if (isprint(c)) {                                     // SE c FOR UM CARACTERE QUE PODE SER IMPRESSO
         cout << c;                                         // IMPRIME c NA TELA
         *s++ = c;                                          // ADICIONA c NA POSISÃO ATUAL DO PONTEIRO E VAI PARA PRÓXIMA POSIÇÃO
         ++pos;                                             // AUMENTA A QUANTIDADE DE CARACTERES LIDOS
      }
      else if (c == 8 && pos) {                             // SE c FOR A TECLA <BACKSPACE>
         cout << "\b \b";                                   // APAGA O CARACTERE ANTERIOR
         --pos;                                             // DIMINUI A QUANTIDADE DE CARACTERES LIDOS
         --s;                                               // VOLTA UMA POSIÇÃO DO PONTEIRO
      }
   } while (c != 13);                                       // LER ENQUANTO O <Enter> NÃO FOR ACIONADO
   *s = '\0';                                               // CARACTERE DE FINALIZAÇÃO DE UMA STRING
}



class Cadastro {                                        // DEFINIÇÃO DA CLASSE
   limpa();
   private:
      char status;                                      // PARA SABER SE O CADASTRO ESTÁ OU NÃO ATIVO
      char jogo[41];                                    // NOME DO JOGO
      char plataforma[30];                              // PLATAFORMA
      char categoria[30];                               // CATEGORIA (ESPORTE,MMO,PLUZZE,ETC)
   public:
      void setStatus(char pstatus) {                    // PARA DEFINIR O STATUS
         status = pstatus;                              // DEFINE O CAMPO MEMBRO COM O VALOR DO PARÂMETRO
      }
      char getStatus() {                                // PARA LER O STATUS
         return status;                                 // RETORNA O VALOR ARMAZENADO NO CAMPO MEMBRO
      }
      void setJogo(char *pjogo) {                       // PARA DEFINIR O JOGO
         strcpy(jogo, pjogo);                           // COPIA PARA O CAMPO MEMBRO O VALOR DO PARÂMETRO
      }
      char *getJogo() {                                 // PARA LER O JOGO
         return jogo;                                   // RETORNA O VALOR ARMAZENADO NO CAMPO MEMBRO
      }
      void setPlataforma(char *pplataforma) {           // PARA DEFINIR A PLATAFORMA
         strcpy(plataforma, pplataforma);               // COPIA PARA O CAMPO MEMBRO O VALOR DO PARÂMETRO
      }
      char *getPlataforma() {                           // PARA LER A PLATAFORMA
         return plataforma;                             // RETORNA O VALOR ARMAZENADO NO CAMPO MEMBRO
      }
      void setCategoria(char *pcategoria) {             // PARA DEFINIR O CATEGORIA
         strcpy(categoria, pcategoria);                 // COPIA PARA O CAMPO MEMBRO O VALOR DO PARÂMETRO
      }
      char *getCategoria() {                            // PARA LER O CATEGORIA
         return categoria;                              // RETORNA O VALOR ARMAZENADO NO CAMPO MEMBRO
      }
};

void criarArquivo(void) {                                           // CRIA O ARQUIVO CASO ESSE NÃO EXISTA
    fstream arquivo;                                                // OBJETO PARA MANIPULAR O ARQUIVO
    arquivo.open("banco.ifsp", ios_base::out | ios_base::binary);   // CRIAÇÃO DO ARQUIVO PARA ESCRITA DE DADOS EM BINÁRIO
    arquivo.close();                                                // FECHA O ARQUIVO
}

Cadastro videogame;                                     // INSTANCIAÇÃO DO OBJETO videogame
char pjogo[41], pplataforma[30], pcategoria[30];        // VÁRIAVEIS PARA AUXÍLIO DA LEITURA


void cadastrar(void) {                                                          // INSERE UM NOVO CADASTRO NO ARQUIVO
   limpa();                                                                     // LIMPA A TELA
   color(1,15);
   cout << " Cadastrar registro\n\n\n";
   color(0,7);
   cout << " Informe o nome do jogo: ";
   lerstr(pjogo);                                                               // ENTRADA FORMATADA PARA CARACTERES MAIÚSCULOS
   cout << endl;
   cout << endl;
   cout << " Informe a plataforma do jogo: ";
   cin.getline(pplataforma, sizeof(pplataforma));                               //ENTRADA DA PLATAFORMA
   cout << endl;
   cout << " Informe a categoria do jogo: ";
   cin.getline(pcategoria, sizeof(pcategoria));                                 //ENTRADA DA CATEGORIA
   cout << endl;
   videogame.setStatus('1');                                                    // DEFINE O ATRIBUTO STATUS COMO ATIVO
   videogame.setJogo(pjogo);                                                    // DEFINE O ATRIBUTO JOGO NO OBJETO
   videogame.setPlataforma(pplataforma);                                        // DEFINE O ATRIBUTO PLATAFORMA NO OBJETO
   videogame.setCategoria(pcategoria);                                          // DEFINE O ATRIBUTO CATEGORIA NO OBJETO

   fstream arquivo;                                                              // OBJETO PARA MANIPULAR ARQUIVO
   arquivo.open("banco.ifsp", ios_base::out | ios_base::app |  ios_base::binary);// ABERTURA DO ARQUIVO PARA ADIÇÃO DE DADOS EM BINÁRIO
   arquivo.seekp(0, ios::end);                                                   // POSICIONA O PONTEIRO NO FINAL DO ARQUIVO
   arquivo.write(reinterpret_cast<char*>(&videogame), sizeof(class Cadastro));   // GRAVA OS DADOS NO ARQUIVO NA POSIÇÃO SELECIONADA
   arquivo.flush();                                                              // ESVAZIA O BUFFER DE SAÍDA PARA O ARQUIVO
   arquivo.close();                                                              // FECHA O ARQUIVO
   cout << "\n\n";                                                               // QUEBRA 2 LINHAS
   cout << "Concluido.\n";
   pausa(0);                                                                     // PAUSA COM MENSAGEM ADICIONAL
}


bool buscaPlataforma(char *pesq) {                                                         // INFORMA DE EXISTE UM PROCESSADOR PESQUISADO
   fstream arquivo("banco.ifsp", ios_base::in | ios_base::binary);                         // ABERTURA DO ARQUIVO PARA LEITURA DE DADOS EM BINÁRIO
   bool acha = false;                                                                      // FLAG LEVANTADA QUANDO O REGISTRO É ENCONTRADO
   while (not arquivo.eof() and not acha) {                                                // ENQUANTO NÃO CHEGOU AO FINAL DO ARQUIVO E NÃO ENCONTROU
      arquivo.read(reinterpret_cast<char*>(&videogame), sizeof(class Cadastro));           // INSERE OS DADOS DE UM REGISTRO NO OBJETO
      if (strcmp(pesq, videogame.getPlataforma()) == 0 and videogame.getStatus() == '1') // SE O PROCESSADOR PROCURADO CORRESPONDE AO REGISTRO E ESSE ESTÁ ATIVO
         acha = true;                                                         //LEVANTA A FLAG POIS ENCONTROU O REGISTRO
   }
   arquivo.flush();                                                           // ESVAZIA O BUFFER DE SAÍDA PARA O ARQUIVO
   arquivo.close();                                                           // FECHA O ARQUIVO
   return acha;                                                               // RETORNA SE ACHOU OU NÃO O REGISTRO PROCURADO
}


bool buscaJogo(char *pesq) {                                                           // INFORMA DE EXISTE UMA MARCA PESQUISADA
   fstream arquivo("banco.ifsp", ios_base::in | ios_base::binary);                     // ABERTURA DO ARQUIVO PARA LEITURA DE DADOS EM BINÁRIO
   bool acha = false;                                                                  // FLAG LEVANTADA QUANDO O REGISTRO É ENCONTRADO
   while (not arquivo.eof() and not acha) {                                            // ENQUANTO NÃO CHEGOU AO FINAL DO ARQUIVO E NÃO ENCONTROU
      arquivo.read(reinterpret_cast<char*>(&videogame), sizeof(class Cadastro));       // INSERE OS DADOS DE UM REGISTRO NO OBJETO
      if (strcmp(pesq, videogame.getJogo()) == 0 and videogame.getStatus() == '1')     // SE A MARCA PROCURADA CORRESPONDE AO REGISTRO E ESSE ESTÁ ATIVO
         acha = true;                                                                  // LEVANTA A FLAG POIS ENCONTROU O REGISTRO
   }
   arquivo.flush();                                                           // ESVAZIA O BUFFER DE SAÍDA PARA O ARQUIVO
   arquivo.close();                                                           // FECHA O ARQUIVO
   return acha;                                                               // RETORNA SE ACHOU OU NÃO O REGISTRO PROCURADO
}

int encontraPosicao(char *pesq) {                                                   // RETORNA A POSIÇÃO DO REGISTRO NO ARQUIVO
   fstream arquivo("banco.ifsp", ios_base::in | ios_base::binary);                  // ABERTURA DO ARQUIVO PARA LEITURA DE DADOS EM BINÁRIO
   unsigned int pos = -1, contador = 0;                                             // POSIÇÃO DO REGISTRO PROCURADO E QUANTIDADE DE REGISTROS NO ARQUIVO
   bool acha = false;                                                               // FLAG LEVANTADA QUANDO O REGISTRO É ENCONTRADO
   while (not arquivo.eof() and not acha) {                                         // ENQUANTO NÃO CHEGOU AO FINAL DO ARQUIVO E NÃO ENCONTROU
      arquivo.read(reinterpret_cast<char*>(&videogame), sizeof(class Cadastro));    // INSERE OS DADOS DE UM REGISTRO NO OBJETO
      if (strcmp(pesq, videogame.getJogo()) == 0 and videogame.getStatus() == '1') {// SE A MARCA PROCURADA CORRESPONDE AO REGISTRO E ESSE ESTÁ ATIVO
         acha = true;                                                               // LEVANTA A FLAG POIS ENCONTROU O REGISTRO
         pos = contador;                                                            // ARMAZENA A POSICAO DO REGISTRO
      }
      contador++;                                                                   // INCREMENTA A QUANTIDADE DE REGISTROS
   }
   arquivo.flush();                                                                 // ESVAZIA O BUFFER DE SAÍDA PARA O ARQUIVO
   arquivo.close();                                                                 // FECHA O ARQUIVO
   return pos;                                                                      // RETORNA A POSIÇÃO NA QUAL O REGISTRO ESTÁ LOCALIZADO
}

void alteraPlataforma(int pos) {                                                   // ALTERA PROCESSADOR DE UM REGISTRO
    cin.getline(pplataforma, sizeof(pplataforma));                                // ENTRADA DO PROCESSADOR
    videogame.setPlataforma(pplataforma);                                        // DEFINE O ATRIBUTO PROCESSADOR NO OBJETO
    fstream arquivo("banco.ifsp",ios_base::in | ios_base::out | ios_base::binary);  // ABERTURA DO ARQUIVO PARA LEITURA E ESCRITA DE DADOS EM BINÁRIO
    arquivo.seekp(pos * sizeof(videogame));                                        // POSICIONA O PONTEIRO NA POSICAO DO REGISTRO SOLICITADO
    arquivo.write(reinterpret_cast<char*>(&videogame), sizeof(class Cadastro));    // GRAVA OS DADOS NO ARQUIVO NA POSIÇÃO SELECIONADA
    arquivo.flush();                                                                // ESVAZIA O BUFFER DE SAÍDA PARA O ARQUIVO
    arquivo.close();                                                                // FECHA O ARQUIVO
}

void alteraCategoria(int pos) {                                                       // ALTERA MEMORIA DE UM REGISTRO
    cin.getline(pcategoria, sizeof(pcategoria));                                        // ENTRADA DA MEMORIA
    videogame.setCategoria(pcategoria);                                                // DEFINE O ATRIBUTO MEMORIA NO OBJETO
    fstream arquivo("banco.ifsp",ios_base::in | ios_base::out | ios_base::binary);  // ABERTURA DO ARQUIVO PARA LEITURA E ESCRITA DE DADOS EM BINÁRIO
    arquivo.seekp(pos * sizeof(videogame));                                        // POSICIONA O PONTEIRO NA POSICAO DO REGISTRO SOLICITADO
    arquivo.write(reinterpret_cast<char*>(&videogame), sizeof(class Cadastro));    // GRAVA OS DADOS NO ARQUIVO NA POSIÇÃO SELECIONADA
    arquivo.flush();                                                                // ESVAZIA O BUFFER DE SAÍDA PARA O ARQUIVO
    arquivo.close();                                                                // FECHA O ARQUIVO
}


void alteraJogo(int pos) {                                                         // ALTERA A MARCA DE UM REGISTRO
    lerstr(pjogo);                                                                 // ENTRADA FORMATADA PARA CARACTERES MAIÚSCULOS
    videogame.setJogo(pjogo);                                                    // DEFINE O ATRIBUTO MARCA NO OBJETO
    fstream arquivo("banco.ifsp",ios_base::in | ios_base::out | ios_base::binary);  // ABERTURA DO ARQUIVO PARA LEITURA E ESCRITA DE DADOS EM BINÁRIO
    arquivo.seekp(pos * sizeof(videogame));                                        // POSICIONA O PONTEIRO NA POSICAO DO REGISTRO SOLICITADO
    arquivo.write(reinterpret_cast<char*>(&videogame), sizeof(class Cadastro));    // GRAVA OS DADOS NO ARQUIVO NA POSIÇÃO SELECIONADA
    arquivo.flush();                                                                // ESVAZIA O BUFFER DE SAÍDA PARA O ARQUIVO
    arquivo.close();                                                                // FECHA O ARQUIVO
}

void excluirVideogame(int pos) {                                                       // "EXCLUI" UM REGISTRO - ALTERADO O STATUS
   videogame.setStatus('0');                                                           // O CARACTERE '0' INDICA QUE ESTÁ INATIVO
   fstream arquivo("banco.ifsp",ios_base::in | ios_base::out | ios_base::binary);      // ABERTURA DO ARQUIVO PARA LEITURA E ESCRITA DE DADOS EM BINÁRIO
   arquivo.seekp(pos * sizeof(videogame));                                             // POSICIONA O PONTEIRO NA POSICAO DO REGISTRO SOLICITADO
   arquivo.write(reinterpret_cast<char*>(&videogame), sizeof(class Cadastro));         // GRAVA OS DADOS NO ARQUIVO NA POSIÇÃO SELECIONADA
   arquivo.flush();                                                                    // ESVAZIA O BUFFER DE SAÍDA PARA O ARQUIVO
   arquivo.close();                                                                    // FECHA O ARQUIVO
}


void pesquisarPlataforma(void) {                                    // PESQUISA POR DATA E EXIBE O REGISTRO
   limpa();                                                         // LIMPA A TELA
   color(1,15);
   cout << " Pesquisar por plataforma do jogo\n\n\n";
   color(0,7);
   cout << " Entre com o nome da plataforma: ";
   cin.getline(pplataforma, sizeof(pplataforma));                   // ENTRADA FORMATADA PARA CARACTERES MAIÚSCULOS
   cout << "\n\n";
   if (buscaPlataforma(pplataforma)) {                              // SE ENCONTROU O REGISTRO
      cout << " Jogo: " << videogame.getJogo();                     // ESCREVE O NOME DO JOGO
      cout << "\n\n";
      cout << " Categoria: " << videogame.getCategoria();           // ESCREVE A CATEGORIA
      cout << "\n\n\n\n ";
   }
   else                                                             // SE NÃO ENCONTROU O REGISTRO
      cout << "\n\n Jogo nao encontrado. ";
   pausa(0);                                                        // PAUSA SEM MENSAGEM ADICIONAL
}

void pesquisarJogo(void) {                                          // PESQUISA POR NOME DO JOGO E EXIBE O REGISTRO
   limpa();                                                         // LIMPA A TELA
   color(1,15);
   cout << " Pesquisar por nome do jogo\n\n\n";
   color(0,7);
   cout << " Entre com o nome do jogo: ";
   lerstr(pjogo);                                                   // ENTRADA FORMATADA PARA CARACTERES MAIÚSCULOS
   cout << "\n\n";
   if (buscaJogo(pjogo)) {                                          // SE ENCONTROU O REGISTRO
      cout << " Plataforma: " << videogame.getPlataforma();         // ESCREVE A PLATAFORMA
      cout << "\n\n";
      cout << " Categoria: " << videogame.getCategoria();           // ESCREVE A CATEGORIA
      cout << "\n\n\n\n ";
   }
   else                                                             // SE NÃO ENCONTROU O REGISTRO
      cout << "\n\n Jogo nao encontrado. ";
   pausa(0);                                                        // PAUSA SEM MENSAGEM ADICIONAL
}

void alterar(void) {                                                // MENU DE ALTERAÇÃO DE JOGO, PLATAFORMA OU CATEGORIA COM EXIBIÇÃO DE REGISTRO
   short opcao;                                                     // ARMAZENA A OPCAO DO MENU
   string selecao;                                                  // PARA PERSONALIZAÇÃO DE TEXTO NO MENU
   do {
      limpa();
      color(1,15);                                                  // LIMPA A TELA E POSICIONA O CURSOR
      cout << " Alterar registro\n\n\n";
      cout << " Selecione a opcao:\n\n";
      color(0,7);
      cout << " [1] - Alterar jogo.\n\n";
      cout << " [2] - Alterar plataforma.\n\n";
      cout << " [3] - Alterar categoria.\n\n";
      cout << " Entre a opcao desejada: ";
      cin >> opcao;                                                  // LEITURA DA OPÇÃO DESEJADA
      cin.ignore(80, '\n');                                          // LIMPA BUFFER DO TECLADO
   } while (opcao != 1 and opcao != 2 and opcao != 3);               // EVITA OPCÃO INEXISTENTE
   if (opcao == 1) selecao = "Jogo";                                 // PERSONALIZA OPÇÃO PARA ALTERAÇÃO DO JOGO
   if (opcao == 2) selecao = "Plataforma";                           // PERSONALIZA OPÇÃO PARA ALTERAÇÃO DA PLATAFORMA
   if (opcao == 3) selecao = "Categoria";                            // PERSONALIZA OPÇÃO PARA ALTERAÇÃO DA CATEGORIA
   else
   {
       cout << "Opcao invalida, tente novamente...";
   }
   limpa();                                                          // LIMPA A TELA
   cout << " Alterar " << selecao << " do registro\n\n\n";
   cout << endl;
   cout << " Entre com nome do jogo: ";
   lerstr(pjogo);                                                    // ENTRADA FORMATADA PARA CARACTERES MAIÚSCULOS
   cout << "\n\n";
   if (buscaJogo(pjogo)) {                                           // SE ENCONTROU O REGISTRO

      if (opcao == 1) {                                              // SE FOI SOLICITADA A ALTERAÇÃO DO NOME DO JOGO
         cout << " Jogo atual: ";
         cout << videogame.getJogo() << "\n\n";                      // EXIBE O NOME DO JOGO
         cout << " Entre um novo jogo: ";
         alteraJogo(encontraPosicao(pjogo));                         // EFETUA A ALTERAÇÃO DO NOME DO JOGO
      }if (opcao == 2) {                                             // SE FOI SOLICITADA A ALTERAÇÃO DE PROCESSADOR
         cout << " Plataforma atual: ";
         cout << videogame.getPlataforma() << "\n\n";                // EXIBE A PLATAFORMA
         cout << " Entre uma nova plataforma: ";
         alteraPlataforma(encontraPosicao(pplataforma));             // EFETUA A ALTERAÇÃO DA PLATAFORMA
      } if (opcao == 3) {                                                       // SE FOI SOLICITADA A ALTERAÇÃO DA CATEGORIA
         cout << " Categoria altual: ";
         cout << videogame.getCategoria() << "\n\n";                 // EXIBE A CATEGORIA
         cout << " Entre uma nova categoria: ";
         alteraCategoria(encontraPosicao(pcategoria));               // EFETUA A ALTERAÇÃO DA CATEGORIA
      }
      cout << "\n\n\n\n";
      cout << "Concluido.\n";
      pausa(0);                                                      // PAUSA COM MENSAGEM ADICIONAL
   }
   else {                                                            // SE NÃO ENCONTROU O REGISTRO
      cout << endl << "\n Jogo nao encontrado. ";
      pausa(0);                                                      // PAUSA SEM MENSAGEM ADICIONAL
   }
}

void remover(void) {                                                    // REMOVE UM REGISTRO
   limpa();                                                             // LIMPA A TELA
   char opcao;                                                          // ARMAZENA A OPCAO DO MENU
   color(1,15);
   cout << " Remover o jogo\n\n\n";
   color(0,7);
   cout << " Entre com a nome do jogo: ";
   lerstr(pjogo);                                                       // ENTRADA FORMATADA PARA CARACTERES MAIÚSCULOS
   cout << "\n\n";
   if (buscaJogo(pjogo)) {                                              // SE ENCONTROU O REGISTRO
      cout << " Plataforma: " << videogame.getPlataforma() << "\n\n\n"; // ESCREVE A PLATAFORMA
      cout << " Remover este jogo [S]im ou [N]ao: ";
      cin >> opcao;                                                     // LEITURA DA OPÇÃO DESEJADA
      cin.ignore(80, '\n');                                             // LIMPA BUFFER DO TECLADO
      if (opcao == 'S' or opcao == 's') {                               // SE FOR SIM
         excluirVideogame(encontraPosicao(pjogo));                      // CHAMADA DA SUB-ROTINA PARA EXCLUSÃO
         cout << "\n\n Jogo removido. ";
      }
      else                                                              // SE FOR QUALQUER OUTRO CARACTERE
         cout << "\n\n\n Jogo nao removido. ";
   }
   else                                                                 // SE NÃO ENCONTROU O REGISTRO
      cout << "\n\n Jogo nao encontrado. ";
   pausa(0);                                                            // PAUSA SEM MENSAGEM ADICIONAL
}



short menu(void) {                                                     // MENU PRINCIPAL COM TODAS AS OPÇÕES
   limpa();                                                            // LIMPA A TELA
   short opcao;                                                        // ARMAZENA A OPCAO DO MENU
   do {
      limpa();                                                         // LIMPA A TELA
      color(1,15);
      cout << "CADASTRO DE GAMES\n\n\n";
      color(0,7);
      cout << " [1] - Cadastrar um jogo no banco de dados.\n";
      cout << " [2] - Procurar Cadastro(s) por jogo.\n";
      cout << " [3] - Procurar Cadastro(s) por plataforma.\n";
      cout << " [4] - Editar um jogo no banco de dados.\n";
      cout << " [5] - Remover um jogo no banco de dados.\n";
      cout << " [0] - Sair.\n";
      cout << " Entre a opcao desejada: ";
      cin >> opcao;                                                    // LEITURA DA OPÇÃO DESEJADA
      cout << endl << endl;
      cin.ignore(80, '\n');                                            // LIMPA BUFFER DO TECLADO
   } while (opcao < 0 or 5 < opcao);                                   // EVITA OPCÃO INEXISTENTE
   return opcao;                                                       // RETORNA O NÚMERO DA OPÇÃO
}

int main(void) {
   limpa();
   short opcao;                                                   // ARMAZENA A OPCAO DO MENU

   fstream arquivo("banco.ifsp", ios_base::in | ios_base::binary);// ABERTURA DO ARQUIVO EM MODO LEITURA BINÁRIA:

   if(arquivo.fail())                                             // SE O ARQUIVO NÃO EXISTIR
      criarArquivo();                                             // CRIA O ARQUIVO

   do {
      opcao = menu();                                             // menu() RETORNA UMA OPCAO TRATADA VALIDA
      switch(opcao) {                                             // CHAMA A SUB-ROTINA CORRESPONDENTE:
         case 1: cadastrar();           break;
         case 2: pesquisarJogo();       break;
         case 3: pesquisarPlataforma(); break;
         case 4: alterar();             break;
         case 5: remover();             break;
      }
   } while (opcao);                                               // ENQUANTO A OPCAO FOR DIFERENTE DE ZERO

   arquivo.close();                                               // FECHA O ARQUIVO
   return 0;
}


