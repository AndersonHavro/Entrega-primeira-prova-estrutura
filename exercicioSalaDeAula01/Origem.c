#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

#pragma region "Assinaturas"
void PrencheVect();
void Menu();
void Opcoes();
void OrdenarBubble();
void IsertionSort();
void SelectionSort();
void BuscaSequencial(int aux);
void BuscaBinaria(int aux);
int Quick(int vect[], int e, int d);
void Imprimir();

#pragma endregion
#pragma region "Variaveis"
int vect[5];
int tam = sizeof(vect) / sizeof(int);
int opcoes = 0, aux = 0, busca = 0, resultado = 0;
#pragma endregion
int main() {
	setlocale(LC_ALL, "portuguese");
	Menu(); //CHAMA O MENU GERAL
	return 0;
}
void PrencheVect() {


	for (int i = 0; i < tam; i++)
	{
		printf("== DIGITE O %d ELEMENTO DO VETOR :", (i + 1));
		scanf_s("%d", &vect[i]);
	}
}
void Menu() {
	printf("==================== MENU =====================\n");
	printf("");
	PrencheVect();
	printf("");
	do
	{
		system("cls");
		printf("===============================================\n");
		printf("                 = OPÇÕES =                    \n");
		printf("===============================================\n");
		printf("");
		printf("( 1 ) ========== ORDERNAR POR \"BUBBLE SORT\"\n");
		printf("( 2 ) ========== ORDERNAR POR \"INSERTION SORT\"\n");
		printf("( 3 ) ========== ORDERNAR POR \"SELECTION SORT\"\n");
		printf("( 4 ) ========== ORDERNAR POR \"QUICK SORT\"\n");
		printf("( 5 ) ========== BUSCAR VETOR \"SEQUENCIAL\"\n");
		printf("( 7 ) ========== BUSCAR VETOR \"BINÁRIA\"=\n");
		printf("( 8 ) ========== SAIR\n");
		printf("");
		printf("===============================================\n");
		Opcoes();
		system("pause");
	} while (opcoes > 0 && opcoes < 8);
}
void Opcoes() {
	scanf_s("%d", &opcoes);
	switch (opcoes)
	{
	case 8:
		printf("Fim do programa!!!");
		return 0;
	case 1:
		OrdenarBubble();
		break;
	case 2:
		IsertionSort();
		break;
	case 3:
		SelectionSort();
		break;
	case 4:
		Quick(vect, 0, tam - 1);
		break;
	case 5:
		BuscaSequencial(aux);
		break;
	case 7:
		BuscaBinaria(aux);
		break;
	default:
		printf("Opção Inválida!!!");
		break;
	}
	Imprimir();
}
int Quick(int vect[], int e, int d) {
	int i, j, p, y;
	i = e;
	j = d;
	p = vect[d];
	while (i <= j) {
		while (vect[i] < p && i < d) {
			i++;
		}
		while (vect[j] > p && j > e)
		{
			j--;
		}
		if (i <= j)
		{
			y = vect[i];
			vect[i] = vect[j];
			vect[j] = y;
			i++;
			j--;
		}

	}
	if (j > e)
	{
		Quick(vect, e, j);
	}
	if (i < d)
	{
		Quick(vect, i, d);
	}
}
void OrdenarBubble() {

	for (int x = tam - 1; x > 0; x--)
	{
		for (int y = 0; y < x; y++)
		{
			if (vect[y] > vect[y + 1])
			{
				aux = vect[y];
				vect[y] = vect[y + 1];
				vect[y + 1] = aux;
			}
		}
	}

}
void IsertionSort() {
	for (int j = 1; j < tam; j++)
	{
		if (vect[j] < vect[j - 1])
		{
			for (int i = j; i != 0; i--)
			{
				aux = vect[i];
				vect[i] = vect[i - 1];
				vect[i - 1] = aux;
			}
		}
	}
}
void SelectionSort() {
	for (int i = 0; i < tam - 1; i++)
	{
		for (int j = i + 1; j < tam; j++)
		{
			aux = vect[i];
			vect[i] = vect[j];
			vect[j] = aux;
		}
	}
}
void BuscaSequencial(int aux) {
	printf("Informe o numero a ser procurado: ");
	scanf_s("%i", &aux);
	for (int i = 0; i < tam; i++)
	{
		if (vect[i] == aux)
		{
			resultado = i;
			break;
		}
	}
}
void BuscaBinaria(int aux) {
	int inf = 0, sup = (tam - 1), meio;
	printf("Informe o numero a ser procurado: ");
	scanf_s("%d", &aux);
	while (inf <= sup) {
		meio = (inf + sup) / 2;
		if (aux == vect[meio]) {
			resultado = meio;
			return 0;
		}
		if (aux < vect[meio])
			sup = meio - 1;
		else
			inf = meio + 1;
	}
}
void Imprimir() {
	if (opcoes > 0 && opcoes < 5)
	{
		printf("\n\n");
		printf("Vetor: ");
		for (int i = 0; i < tam; i++)
		{
			printf("%d", vect[i]);
		}
		printf("\n\n");
	}
	if (opcoes > 4 && opcoes < 8)
	{
		printf("A posição vetor é: %i\n", resultado);
	}



}


