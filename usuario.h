#define inicioArranjo 1
#define maxTam 100

typedef struct { 		//struct de identificação de cada usuário
	int id;
}p;

typedef struct { 		//struct de interesses de cada usuário
	int interesses;
}l;

typedef struct { 		//struct usuario com suas informações
	char nome[10];
	char estado[3];
	char sexo[2];
	char sexo_int[2];
	int numeroareas;
	l like[100]; 		//chamada da struct de interesses
	p potencial_companheiro[100]; //chamada da struct de ids
	int numerocompanheiros;
	int posicao;
	int i;
	int id;
}u;

typedef struct v{
	u item[maxTam];
	int primeiro, ultimo;
} TipoLista;


void fLVazia(TipoLista *lista); //função que cria lista vazia

int vazia(TipoLista *lista); //função que esvazia lista

void imprime(TipoLista *lista); //função que imprime a lista

void insere(u x, TipoLista *lista); //função que realiza a inserção dos dados na lista

void achar_pessoa(TipoLista *lista, int a); //função utilizada para realizar a opção 1 do MENU para o usuário

int Verifica_Potencial_Companheiro(u a, u b); //função utilizada para realizar as comparações necessárias para ser par perfeito

void Insere_Potencial_Companheiro (u a, u b, TipoLista *lista); //função para inserir o potencial companheiro na lista do outro usuário

void Imprime_Lista_Companheiros(u d); //função que imprime a lista de companheiros de um certo usuário

void Imprime_Numero_Companheiros(u d); //função que imprime o número de companheiros que certo usuário possui

void Reside (TipoLista *lista, char sigla[]); //função que verifica quais usuários moram em tal estado

void Tem_interesse (TipoLista *lista, int cod); //função que verifica se um certo usuário possui certo interesse

void percorre(TipoLista *lista);  //função que percorre a lista 

void sem_companheiro (TipoLista *lista); //função para verificar se algum usuário não tem nenhum possível companheiro

void insertionSort(TipoLista *lista, int k); //algoritmo para organizar os companheiros com maiores companheiros a ser usado no menu opção 2

