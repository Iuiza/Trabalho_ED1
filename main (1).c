#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cidade {
  char nomeCidade[20];
  int clientes1, clientes2;
  struct cidade *prox;
} Cidade;

typedef struct pais {
  char nomePais[20];
  struct pais *prox;
  Cidade *cidade;
} Pais;

typedef struct arvore {
  int num;
  char *info;
  struct arvore *sim, *nao;
} Arvore;

void inicializar(Pais **topoPais, Cidade **topoCidade1, Cidade **topoCidade2,
                 Cidade **topoCidade3, Cidade **topoCidade4,
                 Cidade **topoCidade5, Cidade **topoCidade6,
                 Cidade **topoCidade7, Cidade **topoCidade8,
                 Cidade **topoCidade9);
void inserirCidade(Cidade **topoCidade, char nomecidade[20]);
void inserirPais(Pais **topoPais, char nomePais[20]);
void conectar(Cidade **topoCidade, Pais **topoPais, char nomepais[20]);
void addCliente1(Pais **topoCidade, char nomeCidade[20]);
void addCliente2(Pais **topoCidade, char nomeCidade[20]);
void listarPais(Pais *topoPais);
void listarCidade(Cidade *topoCidade);
void listarPaisMais(Pais *topoPais);
int listarPaisMais1(Pais *topoPais);
int listarPaisMais2(Pais *topoPais);
void listarCidadeMais(Pais *topoPais);
Cidade *listarCidadeMaisPorTipo(Pais *topoPais, int tipo);
void decisao(Pais **topoPais);
void listarPaisesVisitados(Pais *topoPais);
void listarPaisesNaoVisitados(Pais *topoPais);
void listarPaisesClientes1(Pais *topoPais);
void listarPaisesClientes2(Pais *topoPais);
bool foiVisitado(Cidade *cidade);

Arvore *inserir(Arvore *raiz, int num);
void exibirArvore(Arvore *raiz, Pais **topoPais, char op);
char *inserirInfo(int num);

void liberarArvore(Arvore *raiz);
void liberarMemoria(Pais **topoPais, Arvore *raiz);

int main() {
  Pais *topoPais = NULL;
  Cidade *topoCidade1 = NULL, *topoCidade2 = NULL, *topoCidade3 = NULL,
         *topoCidade4 = NULL, *topoCidade5 = NULL, *topoCidade6 = NULL,
         *topoCidade7 = NULL, *topoCidade8 = NULL, *topoCidade9 = NULL;
  Arvore *raiz = NULL;

  setlocale(LC_ALL, "");

  inicializar(&topoPais, &topoCidade1, &topoCidade2, &topoCidade3, &topoCidade4,
              &topoCidade5, &topoCidade6, &topoCidade7, &topoCidade8,
              &topoCidade9);

  raiz = inserir(raiz, 16);
  inserir(raiz, 8);
  inserir(raiz, 24);
  inserir(raiz, 4);
  inserir(raiz, 12);
  inserir(raiz, 20);
  inserir(raiz, 28);
  inserir(raiz, 2);
  inserir(raiz, 6);
  inserir(raiz, 10);
  inserir(raiz, 14);
  inserir(raiz, 18);
  inserir(raiz, 22);
  inserir(raiz, 26);
  inserir(raiz, 30);
  inserir(raiz, 1);
  inserir(raiz, 3);
  inserir(raiz, 5);
  inserir(raiz, 7);
  inserir(raiz, 9);
  inserir(raiz, 11);
  inserir(raiz, 13);
  inserir(raiz, 15);
  inserir(raiz, 17);
  inserir(raiz, 19);
  inserir(raiz, 21);
  inserir(raiz, 23);
  inserir(raiz, 25);
  inserir(raiz, 27);
  inserir(raiz, 29);
  inserir(raiz, 31);

  printf(
      "                                |                                   \n");
  printf(
      "                                |                                   \n");
  printf(
      "                                |                                   \n");
  printf(
      "                               _|_                                  \n");
  printf(
      "                              /___\\                                \n");
  printf(
      "                             /_____\\                               \n");
  printf(
      "          VIAGENS           /oo   oo\\            ED1               \n");
  printf(
      "\\___________________________\\       /___________________________/ \n");
  printf(
      " `-----------|------|--------\\_____/--------|------|-----------    \n");
  printf(
      "            ( )    ( )     O|OOo|oOO|O     ( )    ( )               \n");

  int op, aux = 0;
  while (1) {

    printf("\n1- Agendar viagem\n");
    printf("2- Listar todos os países\n");
    printf("3- Listar países visitados\n");
    printf("4- Listar países não visitados\n");
    printf("5- Listar países visitados pelos clientes do tipo 1\n");
    printf("6- Listar países visitados pelos clientes do tipo 2\n");
    printf("7- Listar países mais visitados\n");
    printf("8- Listar cidades mais visitadas\n");
    printf("0- Sair do programa\n");
    printf("Digite uma opcao: ");
    scanf("%d", &op);

    switch (op) {
    case 1:
      printf("Já sabe para onde quer viajar? (1- sim 2- não)\n");
      scanf("%d", &aux);
      if (aux == 1) {
        decisao(&topoPais);
        printf("\nViagem agendada!\n");
      } else if (aux == 2) {
        exibirArvore(raiz, &topoPais, ' ');
      } else {
        printf("\nOpção inválida!\n");
      }
      break;
    case 2:
      listarPais(topoPais);
      break;
    case 3:
      listarPaisesVisitados(topoPais);
      break;
    case 4:
      listarPaisesNaoVisitados(topoPais);
      break;
    case 5:
      listarPaisesClientes1(topoPais);
      break;
    case 6:
      listarPaisesClientes2(topoPais);
      break;
    case 7:
      listarPaisMais(topoPais);
      break;
    case 8:
      listarCidadeMais(topoPais);
      break;
    case 0:
      liberarMemoria(&topoPais, raiz);
      printf("\nSaindo...");
      exit(1);
      break;
    default:
      printf("\nValor inválido!\n");
      break;
    }
    system("pause");
    system("clear || cls");
  }
  return 0;
}

void inserirCidade(Cidade **topoCidade, char nomecidade[20]) {
  Cidade *novo = (Cidade *)malloc(sizeof(Cidade));

  if (novo == NULL) {
    exit(1);
  }

  strcpy(novo->nomeCidade, nomecidade);
  novo->clientes1 = 0;
  novo->clientes2 = 0;

  novo->prox = *topoCidade;
  *topoCidade = novo;
}

void inserirPais(Pais **topoPais, char nomepais[20]) {
  Pais *novo = (Pais *)malloc(sizeof(Pais));

  if (novo == NULL) {
    exit(1);
  }

  strcpy(novo->nomePais, nomepais);
  novo->cidade = NULL;

  novo->prox = *topoPais;
  *topoPais = novo;
}

void conectar(Cidade **topoCidade, Pais **topoPais, char nomepais[20]) {
  Pais *atual = *topoPais;
  while ((atual != NULL) && (strcmp(atual->nomePais, nomepais) != 0)) {
    atual = atual->prox;
  }

  if (atual == NULL) {
    return;
  } else {
    Cidade *cidadeAtual = *topoCidade;
    while (cidadeAtual != NULL) {
      Cidade *novaCidade = (Cidade *)malloc(sizeof(Cidade));
      strcpy(novaCidade->nomeCidade, cidadeAtual->nomeCidade);
      novaCidade->clientes1 = 0;
      novaCidade->clientes2 = 0;
      novaCidade->prox = atual->cidade;
      atual->cidade = novaCidade;
      cidadeAtual = cidadeAtual->prox;
    }
  }
}

void addCliente1(Pais **topoPais, char nomecidade[20]) {
  Pais *atualPais;
  Cidade *atualCidade;
  atualPais = *topoPais;
  atualCidade = (*topoPais)->cidade;

  while (atualPais != NULL) {
    while (atualCidade != NULL) {
      if (strcmp(atualCidade->nomeCidade, nomecidade) == 0) {
        atualCidade->clientes1 += 1;
        return;
      }
      atualCidade = atualCidade->prox;
    }
    atualPais = atualPais->prox;
    atualCidade = atualPais->cidade;
  }
}

void addCliente2(Pais **topoPais, char nomecidade[20]) {
  Pais *atualPais;
  Cidade *atualCidade;
  atualPais = *topoPais;
  atualCidade = (*topoPais)->cidade;

  while (atualPais != NULL) {
    while (atualCidade != NULL) {
      if (strcmp(atualCidade->nomeCidade, nomecidade) == 0) {
        atualCidade->clientes2 += 1;
        return;
      }
      atualCidade = atualCidade->prox;
    }
    atualPais = atualPais->prox;
    atualCidade = atualPais->cidade;
  }
}

void listarPais(Pais *topo) {
  while (topo != NULL) {
    printf("===============================\n");
    printf("Pais: %s\n", topo->nomePais);
    printf("\n");
    listarCidade(topo->cidade);
    topo = topo->prox;
  }
}

void listarCidade(Cidade *topo) {
  while (topo != NULL) {
    printf("Cidade: %s\n", topo->nomeCidade);
    printf("Clientes tipo 1: %d\n", topo->clientes1);
    printf("Clientes tipo 2: %d\n", topo->clientes2);
    printf("\n");
    topo = topo->prox;
  }
}

Arvore *inserir(Arvore *raiz, int num) {
  if (raiz == NULL) {
    raiz = (Arvore *)malloc(sizeof(Arvore));
    if (raiz == NULL) {
      exit(1);
    }

    raiz->num = num;
    raiz->sim = NULL;
    raiz->nao = NULL;
    raiz->info = inserirInfo(num);
  } else {
    if (num > raiz->num) {
      raiz->nao = inserir(raiz->nao, num);
    } else if (num < raiz->num) {
      raiz->sim = inserir(raiz->sim, num);
    } else {
      printf("\nErro numero repetido!\n");
    }
  }

  return raiz;
}

void listarPaisesVisitados(Pais *topoPais) {
  printf("\nPaíses visitados:\n");
  while (topoPais != NULL) {
    if (foiVisitado(topoPais->cidade)) {
      printf("%s\n", topoPais->nomePais);
    }
    topoPais = topoPais->prox;
  }
}

void listarPaisesNaoVisitados(Pais *topoPais) {
  printf("\nPaíses não visitados:\n");
  while (topoPais != NULL) {
    if (!foiVisitado(topoPais->cidade)) {
      printf("%s\n", topoPais->nomePais);
    }
    topoPais = topoPais->prox;
  }
}

void listarPaisesClientes1(Pais *topoPais) {
  printf("\nPaíses visitados apenas pelos clientes 1:\n");
  while (topoPais != NULL) {
    if (listarPaisMais1(topoPais) > 0 && listarPaisMais2(topoPais) == 0) {
      printf("%s\n", topoPais->nomePais);
    }
    topoPais = topoPais->prox;
  }
}

void listarPaisesClientes2(Pais *topoPais) {
  printf("\nPaíses visitados apenas pelos Clientes 2:\n");
  while (topoPais != NULL) {
    if (listarPaisMais2(topoPais) > 0 && listarPaisMais1(topoPais) == 0) {
      printf("%s\n", topoPais->nomePais);
    }
    topoPais = topoPais->prox;
  }
}

bool foiVisitado(Cidade *cidade) {
  while (cidade != NULL) {
    if (cidade->clientes1 > 0 || cidade->clientes2 > 0) {
      return true;
    }
    cidade = cidade->prox;
  }
  return false;
}

void exibirArvore(Arvore *raiz, Pais **topoPais, char op) {
  char confirmar;

  if (raiz->sim == NULL || raiz->nao == NULL) {
    printf("\nSeu destino ideal foi %s", raiz->info);
    printf("\nDeseja confirmar essa viagem? (s/n): ");
    scanf(" %c", &confirmar);

    if (confirmar == 's' || confirmar == 'S') {
      addCliente2(topoPais, raiz->info);
    }

    return;
  }

  printf("\n%s (s/n): ", raiz->info);
  scanf(" %c", &op);

  if (op == 's' || op == 'S') {
    exibirArvore(raiz->sim, topoPais, op);
  } else {
    exibirArvore(raiz->nao, topoPais, op);
  }
}

void listarPaisMais(Pais *topoPais) {
  int maior = 0, nenhum1 = 0, nenhum2 = 0;
  Pais *atual1, *atual2, *aux;

  aux = topoPais;

  while (aux != NULL) {
    if (listarPaisMais1(aux) > maior) {
      atual1 = aux;
      nenhum1 = 1;
    }
    if (listarPaisMais2(aux) > maior) {
      atual2 = aux;
      nenhum2 = 1;
    }
    aux = aux->prox;
  }

  aux = topoPais;

  if (nenhum1 == 0) {
    printf("\nNenhum país foi visitado pelos clientes tipo 1!\n");
  } else {
    printf("\nPaís(es) mais visitado(s) pelos clientes tipo 1:\n");
    while (aux != NULL) {
      if (listarPaisMais1(atual1) == listarPaisMais1(aux)) {
        printf("%s\n", aux->nomePais);
      }
      aux = aux->prox;
    }
  }

  aux = topoPais;

  if (nenhum2 == 0) {
    printf("\nNenhum país foi visitado pelos clientes tipo 2!\n");
  } else {
    printf("\nPaís(es) mais visitado(s) pelos clientes tipo 2:\n");
    while (aux != NULL) {
      if (listarPaisMais2(atual2) == listarPaisMais2(aux)) {
        printf("%s\n", aux->nomePais);
      }
      aux = aux->prox;
    }
  }
}

int listarPaisMais1(Pais *topoPais) {
  int cont1 = 0;
  Cidade *topoCidade;

  topoCidade = topoPais->cidade;

  while (topoCidade != NULL) {
    cont1 = cont1 + topoCidade->clientes1;
    topoCidade = topoCidade->prox;
  }

  return cont1;
}

int listarPaisMais2(Pais *topoPais) {
  int cont2 = 0;
  Cidade *topoCidade;

  topoCidade = topoPais->cidade;

  while (topoCidade != NULL) {
    cont2 = cont2 + topoCidade->clientes2;
    topoCidade = topoCidade->prox;
  }

  return cont2;
}

void listarCidadeMais(Pais *topoPais) {
  Cidade *maisVisitada1 = listarCidadeMaisPorTipo(topoPais, 1);
  Cidade *maisVisitada2 = listarCidadeMaisPorTipo(topoPais, 2);
  Pais *atual = topoPais;

  if (maisVisitada1 == NULL) {
    printf("\nNenhuma cidade foi visitada pelos clientes tipo 1!\n");
  } else {
    printf("\nCidade(s) mais visitada(s) pelos clientes tipo 1:\n");
    while (atual != NULL) {
      Cidade *topoCidade = atual->cidade;

      while (topoCidade != NULL) {
        if (maisVisitada1->clientes1 == topoCidade->clientes1) {
          printf("%s\n", topoCidade->nomeCidade);
        }
        topoCidade = topoCidade->prox;
      }
      atual = atual->prox;
    }
  }

  atual = topoPais;

  if (maisVisitada2 == NULL) {
    printf("\nNenhuma cidade foi visitada pelos clientes tipo 2!\n");
  } else {
    printf("\nCidade(s) mais visitada(s) pelos clientes tipo 2:\n");
    while (atual != NULL) {
      Cidade *topoCidade = atual->cidade;

      while (topoCidade != NULL) {
        if (maisVisitada2->clientes2 == topoCidade->clientes2) {
          printf("%s\n", topoCidade->nomeCidade);
        }
        topoCidade = topoCidade->prox;
      }
      atual = atual->prox;
    }
  }
}

Cidade *listarCidadeMaisPorTipo(Pais *topoPais, int tipo) {
  Cidade *maisVisitada = NULL;
  int maior = 0;

  while (topoPais != NULL) {
    Cidade *topoCidade = topoPais->cidade;

    while (topoCidade != NULL) {
      int clientes;

      if (tipo == 1) {
        clientes = topoCidade->clientes1;
      } else {
        clientes = topoCidade->clientes2;
      }

      if (clientes > maior) {
        maior = clientes;
        maisVisitada = topoCidade;
      }

      topoCidade = topoCidade->prox;
    }

    topoPais = topoPais->prox;
  }

  return maisVisitada;
}

void liberarMemoria(Pais **topoPais, Arvore *raiz) {

  while (*topoPais != NULL) {
    Cidade *cidadeAtual = (*topoPais)->cidade;
    while (cidadeAtual != NULL) {
      Cidade *proximaCidade = cidadeAtual->prox;
      free(cidadeAtual);
      cidadeAtual = proximaCidade;
    }
    Pais *proximoPais = (*topoPais)->prox;
    free(*topoPais);
    *topoPais = proximoPais;
  }

  liberarArvore(raiz);
}

void liberarArvore(Arvore *raiz) {
  if (raiz != NULL) {
    liberarArvore(raiz->sim);
    liberarArvore(raiz->nao);
    free(raiz);
  }
  return;
}

void decisao(Pais **topoPais) {
  int op;
  printf("Para qual dessas cidades você quer ir?\n");
  printf(
      "1- Gramado\n2- São Paulo\n3- Rio de Janeiro\n4- Lençóis\n5- Orlando\n6- "
      "Las Vegas\n7- Munique\n8- Berlim\n9- Porto\n10- Coimbra\n11- Roma\n12- "
      "Veneza\n13- Paris\n14- Londres\n15- Santiago\n16- Buenos Aires\n");
  scanf("%d", &op);

  switch (op) {
  case 1:
    addCliente1(topoPais, "Gramado");
    break;
  case 2:
    addCliente1(topoPais, "São Paulo");
    break;
  case 3:
    addCliente1(topoPais, "Rio de Janeiro");
    break;
  case 4:
    addCliente1(topoPais, "Lençóis");
    break;
  case 5:
    addCliente1(topoPais, "Orlando");
    break;
  case 6:
    addCliente1(topoPais, "Las Vegas");
    break;
  case 7:
    addCliente1(topoPais, "Munique");
    break;
  case 8:
    addCliente1(topoPais, "Berlim");
    break;
  case 9:
    addCliente1(topoPais, "Porto");
    break;
  case 10:
    addCliente1(topoPais, "Coimbra");
    break;
  case 11:
    addCliente1(topoPais, "Roma");
    break;
  case 12:
    addCliente1(topoPais, "Veneza");
    break;
  case 13:
    addCliente1(topoPais, "Paris");
    break;
  case 14:
    addCliente1(topoPais, "Londres");
    break;
  case 15:
    addCliente1(topoPais, "Santiago");
    break;
  case 16:
    addCliente1(topoPais, "Buenos Aires");
    break;
  default:
    printf("Valor inválido!");
    break;
  }
  return;
}

char *inserirInfo(int num) {
  char *info;
  info = (char *)malloc(50 * sizeof(char));

  if (info == NULL) {
    exit(1);
  }

  switch (num) {
  case 1:
    strcpy(info, "Roma");
    break;
  case 2:
    strcpy(info, "Gosta de história?");
    break;
  case 3:
    strcpy(info, "Veneza");
    break;
  case 4:
    strcpy(info, "Quer uma viagem gastronômica?");
    break;
  case 5:
    strcpy(info, "Porto");
    break;
  case 6:
    strcpy(info, "Gosta de futebol?");
    break;
  case 7:
    strcpy(info, "Coimbra");
    break;
  case 8:
    strcpy(info, "Se interessa pela cultura mediterrânea?");
    break;
  case 9:
    strcpy(info, "Londres");
    break;
  case 10:
    strcpy(info, "Se interessa pela realeza?");
    break;
  case 11:
    strcpy(info, "Paris");
    break;
  case 12:
    strcpy(info, "Quer uma viagem romântica?");
    break;
  case 13:
    strcpy(info, "Munique");
    break;
  case 14:
    strcpy(info, "Gosta de cerveja?");
    break;
  case 15:
    strcpy(info, "Berlim");
    break;
  case 16:
    strcpy(info, "Quer visitar outro continente?");
    break;
  case 17:
    strcpy(info, "Orlando");
    break;
  case 18:
    strcpy(info, "Viagem em família?");
    break;
  case 19:
    strcpy(info, "Las Vegas");
    break;
  case 20:
    strcpy(info, "Tem visto americano?");
    break;
  case 21:
    strcpy(info, "Santiago");
    break;
  case 22:
    strcpy(info, "Gostaria de esquiar?");
    break;
  case 23:
    strcpy(info, "Buenos Aires");
    break;
  case 24:
    strcpy(info, "Quer sair do brasil?");
    break;
  case 25:
    strcpy(info, "Gramado");
    break;
  case 26:
    strcpy(info, "Gosta de Chocolate?");
    break;
  case 27:
    strcpy(info, "São Paulo");
    break;
  case 28:
    strcpy(info, "Gosta de frio?");
    break;
  case 29:
    strcpy(info, "Rio de Janeiro");
    break;
  case 30:
    strcpy(info, "Gosta de praia?");
    break;
  case 31:
    strcpy(info, "Lençóis");
    break;
  default:
    break;
  }

  return info;
}

void inicializar(Pais **topoPais, Cidade **topoCidade1, Cidade **topoCidade2,
                 Cidade **topoCidade3, Cidade **topoCidade4,
                 Cidade **topoCidade5, Cidade **topoCidade6,
                 Cidade **topoCidade7, Cidade **topoCidade8,
                 Cidade **topoCidade9) {
  inserirPais(topoPais, "Brasil");
  inserirCidade(topoCidade1, "Gramado");
  inserirCidade(topoCidade1, "São Paulo");
  inserirCidade(topoCidade1, "Rio de Janeiro");
  inserirCidade(topoCidade1, "Lençóis");
  conectar(topoCidade1, topoPais, "Brasil");

  inserirPais(topoPais, "Estados Unidos");
  inserirCidade(topoCidade2, "Orlando");
  inserirCidade(topoCidade2, "Las Vegas");
  conectar(topoCidade2, topoPais, "Estados Unidos");

  inserirPais(topoPais, "Alemanha");
  inserirCidade(topoCidade3, "Munique");
  inserirCidade(topoCidade3, "Berlim");
  conectar(topoCidade3, topoPais, "Alemanha");

  inserirPais(topoPais, "Portugal");
  inserirCidade(topoCidade4, "Porto");
  inserirCidade(topoCidade4, "Coimbra");
  conectar(topoCidade4, topoPais, "Portugal");

  inserirPais(topoPais, "Itália");
  inserirCidade(topoCidade5, "Roma");
  inserirCidade(topoCidade5, "Veneza");
  conectar(topoCidade5, topoPais, "Itália");

  inserirPais(topoPais, "França");
  inserirCidade(topoCidade6, "Paris");
  conectar(topoCidade6, topoPais, "França");

  inserirPais(topoPais, "Inglaterra");
  inserirCidade(topoCidade7, "Londres");
  conectar(topoCidade7, topoPais, "Inglaterra");

  inserirPais(topoPais, "Chile");
  inserirCidade(topoCidade8, "Santiago");
  conectar(topoCidade8, topoPais, "Chile");

  inserirPais(topoPais, "Argentina");
  inserirCidade(topoCidade9, "Buenos Aires");
  conectar(topoCidade9, topoPais, "Argentina");
}