#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct cadastroVacina {                      

	char nome [999];
	char cpf [999];
	char vacina [999];
	char data [999];
	int lote;	
};


struct cadastroVacina cadastro() {  
	
	struct cadastroVacina cad;
			
			printf ("============CADASTRO DE PACIENTE=========== \n");
			printf ("Nome do Paciente:");
			gets (cad.nome);
			fflush (stdin);
			printf ("CPF do Paciente: ");
			gets (cad.cpf);
			fflush (stdin);
			printf ("Vacina: ");
			gets (cad.vacina);
			fflush (stdin);
			printf ("Data de Aplicação: ");
			gets (cad.data);
			fflush (stdin);
			printf ("Número do Lote: \n");
			scanf ("%d", &cad.lote);
			fflush (stdin);	
			system ("cls");
			return cad;
}

void listarVacinados (struct cadastroVacina cadUsu[500], int qtdUsu) {
	
		int i;
		for (i = 0; i < qtdUsu; i++){

		printf (" Código: %d\n ", i + 1);
		printf ("Nome: %s \n", cadUsu[i].nome, "\n");
		printf (" CPF: %s \n", cadUsu[i].cpf, "\n");
		printf (" Vacina : %s \n", cadUsu[i].vacina, "\n");
		printf (" Data: %s \n", cadUsu[i].data, "\n");
		printf (" Número do lote: %d \n", cadUsu[i].lote,"\n");
		printf (" CADASTRO EFETUADO COM SUCESSO\n");
		printf ("========================\n");
		fflush (stdin);
		}
}
		
void cpfBusca (struct cadastroVacina cadUsu[500], int qtdUsu) {
	
	printf (" Digite o CPF: \n");
	
	int i;
	char cpf[50]; 
	gets ( cpf);
	fflush (stdin);

	
	for (i = 0; i < qtdUsu; i++){
	
	if (strcmp (cpf, cadUsu[i].cpf ) == 0){
		
		printf  ("Código: %d\n ", i + 1);
		printf ("Nome: %s \n", cadUsu[i].nome, "\n");
		printf ("CPF: %s \n", cadUsu[i].cpf, "\n");
		printf ("Vacina : %s \n", cadUsu[i].vacina, "\n");
		printf ("Data: %s \n", cadUsu[i].data, "\n");
		printf ("Número do lote: %d \n", cadUsu[i].lote,"\n");
		printf ("CADASTRO EFETUADO COM SUCESSO\n");
		printf ("========================\n");	
		fflush (stdin);
	}
	else {
		printf ("CPF NÃO ENCONTRADO, DIGITE OUTRO CORRESPONDENTE \n");
		fflush (stdin);
	}
}
	
}

int main () {
	
	setlocale (LC_ALL, "Portuguese");

	struct cadastroVacina cadUsu [500]; 
	int contCad = 0; 
	int op;
	
	do {
		printf ("===========SELECIONE UMA OPÇÃO===========\n");
		printf ("1 - Cadastrar Vacina: \n");
		printf ("2 - Listar Aplicações: \n");
		printf ("3 - Consultar CPF: \n");
		printf ("4 - Sair: \n");
		scanf ("%d", &op);
		fflush (stdin);
		system ("cls");	
				
		switch (op) {
			
			case 1 : {
				cadUsu [contCad] = cadastro();
				contCad++;
				break;
			}
			
			case 2 : {
				listarVacinados(cadUsu, contCad);
				break;
			}
		
			case 3 : {
				cpfBusca (cadUsu, contCad);	
				break;
			}
			
			case 4 : {
				printf ("Finalizando o Programa");	
				break;
			}
			
			default : {
				printf ("Opção Inválida \n");
				printf ("==================\n");
				break;
			}
		}
	
	} while (op !=4);		
	
	return 0;
}
