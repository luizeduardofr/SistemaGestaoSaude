#include <iostream>
#include <conio.h>
#include <locale.h>
#include <cstring>
using namespace std;

//Trabalho Segundo Semestre

struct indicePaciente {
	int codigo;
	int ender;
};

struct Paciente {
	int cpf;
	char nomePaciente[30];
	int idadePaciente;
	char sexo[9];
	char telefone[15];
	char endereco[30];
	char cidade[20];
	int idUF;
	int status;
};

struct indiceEspecializacao {
	int codigo;
	int ender;
};

struct Especializacao {
	int codEspecializacao;
	char nomeEspecializacao [30];
	int status;
};

struct indiceMedico {
	int codigo;
	int ender;
};

struct Medico {
	int crm;
	char nomeMedico[30];
	int idade;
	char sexo[9];
	char telefone[15];
	int codEspecializacao;
	float valorConsulta;
	int status;
};

struct indiceConsulta {
	int codigo;
	int ender;
};

struct ConsultaMarcada {
	int cpfPaciente;
	int crmMedico;
	char data[10];
	char horario[5];
	int status;
};

// Funções de Leitura

//Paciente

void leituraPaciente (struct Paciente pac[], int &contadorP){
	int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++){
        cout << "\n\nCPF do Paciente " << (i+1) << ": ";
        cin >> pac[i].cpf;
        if (pac[i].cpf > 0){
            cout << "Nome: ";
            cin >> pac[i].nomePaciente;
            cout << "Idade: ";
            cin >> pac[i].idadePaciente;
            cout << "Sexo: ";
            cin >> pac[i].sexo;
            cout << "Telefone: ";
            cin >> pac[i].telefone;
            cout << "Endereco: ";
            cin >> pac[i].endereco;
            cout << "Cidade: ";
            cin >> pac[i].cidade;
            cout << "Estado: ";
            cin >> pac[i].idUF;
            pac[i].status = 0;
        }
        else saida = 0;
    }
    contadorP = i-1;
}

void leituraIndicePaciente (struct indicePaciente idxP[], int contadorP){
    for (int i = 0; i < contadorP; i++){
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idxP[i].codigo;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idxP[i].ender;
    }
}

//Especialização

void leituraEspecializacao (struct Especializacao esp[], int &contadorE) {
	int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++){
    	cout << "\n\nCódigo da Especialização " << (i+1) << ": ";
    	cin >> esp[i].codEspecializacao;
    	if (esp[i].codEspecializacao > 0){
    		cout << "Nome da Especialização: ";
    		cin >> esp[i].nomeEspecializacao;
    		esp[i].status = 0;
		}
		else saida = 0;
	}
	contadorE = i - 1;
}

void leituraIndiceEspecializacao (struct indiceEspecializacao idxE[], int contadorE){
    for (int i = 0; i < contadorE; i++){
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idxE[i].codigo;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idxE[i].ender;
    }
}

//Médico

void leituraMedico (struct Medico med[], int &contadorM) {
	int i = 0;
	for (int saida = 1; i < 20 && saida != 0; i++){
		cout << "\n\nCRM do Médico: " << (i+1) << ": ";
		cin >> med[i].crm;
		if (med[i].crm > 0){
			cout << "Nome do Médico: ";
			cin >> med[i].nomeMedico;
			cout << "Idade: ";
			cin >> med[i].idade;
			cout << "Sexo: ";
			cin >> med[i].sexo;
			cout << "Telefone: ";
			cin >> med[i].telefone;
			cout << "Código de Especialização: ";
			cin >> med[i].codEspecializacao;
			cout << "Valor da Consulta: ";
			cin >> med[i].valorConsulta;
			med[i].status = 0;
		}
		else saida = 0;
	}
	contadorM = i - 1;
}

void leituraIndiceMedico (struct indiceMedico idxM[], int contadorM) {
	for (int i = 0; i < contadorM; i++){
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idxM[i].codigo;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idxM[i].ender;
    }
}

//Consulta

void leituraConsulta (struct ConsultaMarcada con[], int &contadorC) {
	int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++){
        cout << "\nCPF do Paciente: ";
        cin >> con[i].cpfPaciente;
        cout << "CRM do Médico: ";
        cin >> con[i].crmMedico;
        if (con[i].cpfPaciente > 0 && con[i].crmMedico > 0){
        	cout << "Data da consulta: ";
        	cin >> con[i].data;
        	cout << "Horário: ";
        	cin >> con[i].horario;
        	con[i].status = 0;
		}
		else saida = 0;
	}
	contadorC = i - 1;
}

void leituraIndiceConsulta (struct indiceConsulta idxC[], int contadorC) {
	for (int i = 0; i < contadorC; i++){
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idxC[i].codigo;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idxC[i].ender;
    }
}

// Fim das Funções de Leitura

//Inclusão de Pacientes

void inclusaoPaciente (struct indicePaciente idxP[], struct Paciente pac[], int &contadorP, int codP){
    contadorP++;
    // inclusao do novo registro na area de dados
    pac[contadorP].cpf = codP;
    cout << "Nome: ";
    cin >> pac[contadorP].nomePaciente;
    cout << "Idade: ";
    cin >> pac[contadorP].idadePaciente;
    cout << "Sexo: ";
    cin >> pac[contadorP].sexo;
    cout << "Telefone: ";
    cin >> pac[contadorP].telefone;
    cout << "Endereco: ";
    cin >> pac[contadorP].endereco;
    cout << "Cidade: ";
    cin >> pac[contadorP].cidade;
    cout << "Estado: ";
    cin >> pac[contadorP].idUF;
    // inclusao na area de indices
    int i;
    for (i = contadorP - 1; idxP[i].codigo > codP; i--){
        idxP[i+1].codigo = idxP[i].codigo;
        idxP[i+1].ender = idxP[i].ender;
    }
    idxP[i+1].codigo = codP;
    idxP[i+1].ender = contadorP;
    cout << "\n\nInclusão realizada com Sucesso";
    getch();
}

void buscaaleatPaciente (struct indicePaciente idxP[], struct Paciente pac[], int &contadorP, int codP){
    int i = 0, f = contadorP;
    int m = (i + f) / 2;
    for (; f >= i && codP != idxP[m].codigo; m = (i + f) / 2){
        if (codP > idxP[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codP == idxP[m].codigo){
        cout << "\n\nPaciente já Cadastrado - não pode ser cadastrado novamente!" << endl;
        i = idxP[m].ender;
        cout << "\nCPF do Cliente: " << pac[i].cpf;
        cout << "\nNome: " << pac[i].nomePaciente;
        cout << "\nIdade: " << pac[i].idadePaciente;
        cout << "\nSexo: " << pac[i].sexo;
        cout << "\nTelefone: " << pac[i].telefone;
        cout << "\nEndereco: " << pac[i].endereco;
        cout << "\nCidade: " << pac[i].cidade;
        cout << "\nEstado: " << pac[i].idUF << endl;
    }
    else
        inclusaoPaciente (idxP, pac, contadorP, codP);
    getch();
}

//Fim inclusão Pacientes

//Inclusao Medico

int buscaaleatEspec (struct indiceEspecializacao idxE[], struct Especializacao esp[], int codM, int contadorE){
	int i = 0, f = contadorE;
	int m = (i + f) / 2;
	for (; f >= i && codM != idxE[m].codigo; m = (i + f) / 2){
		if (codM > idxE[m].codigo){
			i = m + 1;
		} else {
			f = m - 1;
		}
	}
	if (codM == idxE[m].codigo){
		return idxE[m].ender;
	} else {
		return -1;
	}
}

void inclusaoMedico (struct indiceMedico idxM[], struct Medico med[], struct indiceEspecializacao idxE[], struct Especializacao esp[], int &contadorM, int &contadorE, int codM){
    contadorM++;
    // inclusao do novo registro na area de dados
    med[contadorM].crm = codM;
    cout << "Nome do Médico: ";
    cin >> med[contadorM].nomeMedico;
    cout << "Idade: ";
    cin >> med[contadorM].idade;
    cout << "Sexo: ";
    cin >> med[contadorM].sexo;
    cout << "Telefone: ";
    cin >> med[contadorM].telefone;
    cout << "Valor da Consulta: ";
    cin >> med[contadorM].valorConsulta;
    cout << "Código de Especialização: ";
    cin >> med[contadorM].codEspecializacao;
    int enderEspec = buscaaleatEspec(idxE, esp, med[contadorM].codEspecializacao, contadorE);
    while (enderEspec == -1){
    	cout << "\nEspecialidade não encontrada! Digite novamente: ";
    	cin >> med[contadorM].codEspecializacao;
    	enderEspec = buscaaleatEspec(idxE, esp, med[contadorM].codEspecializacao, contadorE);
	}
	cout << "Especialidade encontrada: " << esp[enderEspec].nomeEspecializacao << endl;
	med[contadorM].status = 0;
    // inclusao na area de indices
    int i;
    for (i = contadorM - 1; idxM[i].codigo > codM; i--){
        idxM[i+1].codigo = idxM[i].codigo;
        idxM[i+1].ender = idxM[i].ender;
    }
    idxM[i+1].codigo = codM;
    idxM[i+1].ender = contadorM;
    cout << "\nInclusão realizada com Sucesso" << endl;
}

void buscaaleatMedico (struct indiceMedico idxM[], struct Medico med[], struct indiceEspecializacao idxE[], struct Especializacao esp[], int &contadorM, int &contadorE, int codM){
	int i = 0, f = contadorM;
	int m = (i + f) /2;
	for (; f >= i && codM != idxM[m].codigo; m = (i + f) / 2){
		if (codM > idxM[m].codigo){
			i = m + 1;
		} else {
			f = m - 1;
		}
	}
	if (codM == idxM[m].codigo){
		cout << "\n\nMédico já cadastrado, não pode ser cadastrado novamente";
		i = idxM[m].ender;
		cout << "\nCRM do Médico: " << med[i].crm;
		cout << "\nNome: " << med[i].nomeMedico;
		cout << "\nIdade: " << med[i].idade;
		cout << "\nSexo: " << med[i].sexo;
		cout << "\nTelefone: " << med[i].telefone;
		cout << "\nCódigo de Especializacão: " << med[i].codEspecializacao;
		cout << "\nValor da Consulta: " << med[i].valorConsulta << endl;
	}
	else 
		inclusaoMedico (idxM, med, idxE, esp, contadorM, contadorE, codM);
	getch();
}

//Fim inclusao Medico

// Buscar Medico por Especializacão

void buscaaleatEsp (struct indiceEspecializacao idxE[], struct Especializacao esp[], struct indiceMedico idxM[], struct Medico med[], int &contadorM, int &contadorE, int codE){
	cout << "\nLista de Médicos com a Especialização em " << esp[codE - 1].nomeEspecializacao << " :" << endl;
	for (int i = 0; i < contadorM; i++){
		int enderM = idxM[i].ender;
		if (codE == med[enderM].codEspecializacao){
			cout << "\n\nCRM: " << med[enderM].crm;
			cout << "\nNome: " << med[enderM].nomeMedico;
 		} else {
 			cout << "\nEspecialização não cadastrada!" << endl;
		 }
	}
	getch();
}

// Fim da busca

// Inclusao Consulta

int buscaaleatMed2 (struct indiceMedico idxM[], struct Medico med[], int codM, int contadorM){
	int i = 0, f = contadorM;
	int m = (i + f) / 2;
	for (; f >= i && codM != idxM[m].codigo; m = (i + f) / 2){
		if (codM > idxM[m].codigo){
			i = m + 1;
		} else {
			f = m - 1;
		}
	}
	if (codM == idxM[m].codigo && med[idxM[m].ender].status == 0){
		return idxM[m].ender;
	} else{
		return -1;
	}
}

void buscaaleatCons (struct indiceMedico idxM[], struct Medico med[], struct Paciente pac[], struct indiceConsulta idxC[], struct ConsultaMarcada con[], int &contadorM, int &contadorC, int codC){
	contadorC++;
    // inclusao do novo registro na area de dados
    con[contadorC].cpfPaciente = codC;
    cout << "Data da Consulta: ";
    cin >> con[contadorC].data;
    cout << "Horário: ";
    cin >> con[contadorC].horario;
    cout << "CRM: ";
    cin >> con[contadorC].crmMedico;
    int enderMed = buscaaleatMed2(idxM, med, con[contadorC].crmMedico, contadorM);
    while (enderMed == -1){
    	cout << "\nMédico não encontrado! Digite novamente: ";
    	cin >> con[contadorC].crmMedico;
    	enderMed = buscaaleatMed2(idxM, med, con[contadorC].crmMedico, contadorM);
	}
	cout << "Médico encontrado: " << med[enderMed].nomeMedico << endl;
    // inclusao na area de indices
    int i;
    for (i = contadorC - 1; idxM[i].codigo > codC; i--){
        idxC[i+1].codigo = idxC[i].codigo;
        idxC[i+1].ender = idxC[i].ender;
    }
    idxC[i+1].codigo = codC;
    idxC[i+1].ender = contadorC;
    cout << "\nInclusão realizada com Sucesso" << endl;
}

// Fim inclusao consulta

//Exlusao Medico

void exclusaoMedico (struct indiceMedico idxM[], struct Medico med[], int &contadorM, int codM){
	int busca = buscaaleatMed2 (idxM, med, codM, contadorM);
	
	if (busca != -1){
		med[busca].status = 1;
		cout << "\nMédico " << med[busca].nomeMedico << " Excluido com sucesso!!";
	} else {
		cout << "\nMédico não cadastrado.";
	}
	getch();
}

//Fim da Exclusao

//Reorganizar Medico

void reorganizacaoMedico (struct Medico med[], struct indiceMedico idxM[], int &contadorM, struct Medico novoMed[]){
    int j = 0;
    for (int k = 0; k <= contadorM; k++)
    {
        int i = idxM[k].ender;
        if (med[i].status == 0)
        {
            idxM[j].codigo = med[i].crm;
            idxM[j].ender = j;
            novoMed[j] = med[i];
            j++;
        }
    }

    for (int i = 0; i <= j; i++)
    {
        int k = idxM[i].ender;
        med[i] = novoMed[k];
    }
    contadorM = j;
    cout << "Reorganização concluída com sucesso!\n\n";
}

// Fim reorganizar

// Faturamento da Clinica

void faturamentoClinica (struct ConsultaMarcada con[], struct Medico med[], int &contadorC, int &contadorM){
	int soma = 0, total = 0;
	int crMed;
	
	for (int i = 0; i <= contadorC; i++){
		crMed = con[i].crmMedico;
		for (int j = 0; j <= contadorM; j++){
			if (crMed == med[j].crm){
				soma += med[j].valorConsulta;
			}
		}
	}
	total = soma * 0.05;
	cout << "\nO Faturamento da Clinica foi de: " << total << " reais." << endl;
	getch();
}

// Fim faturamento

// Consulta mais cara e mais barata

void valorConsulta (struct indiceMedico idxM[], struct Medico med[], int &contadorM){
	struct Medico menor = med[0];
	struct Medico maior = med[0];
	
	for (int i = 0; i < contadorM; i++){
		if (med[i].valorConsulta < menor.valorConsulta){
			menor = med[i];
		}
		if (med[i].valorConsulta > maior.valorConsulta){
			maior = med[i];
		}
	}
	cout << "\nValor da Consulta mais barata: " << menor.valorConsulta;
	cout << "\nNome do Médico: " << menor.nomeMedico << endl;
	cout << "-----------------------------------------" << endl;
	cout << "\nValor da Consulta mais cara: " << maior.valorConsulta;
	cout << "\nNome do Médico: " << maior.nomeMedico;
	getch();
}

// Fim da consulta


int main() {
	setlocale(LC_ALL,"");
	
	struct Paciente arqPac[4];
	struct indicePaciente idxPac[4];
	
	struct Especializacao arqEspec[4];
	struct indiceEspecializacao idxEspec[4];
	
	struct Medico arqMed[4];
	struct Medico arqNovoMed[4];
	struct indiceMedico idxMed[4];
	
	struct ConsultaMarcada arqCons[4];
	struct indiceConsulta idxCons[4];
	
	int contPac = 0, contEsp = 0, contMed = 0, contCons = 0;
	
	int al = 0;
	
	while (al != 8){
	system("cls");
		cout << "\t\t\t---Menu de Opções---\n\n\n";
		
		cout << "\t\t1 - Cadastrar\n" << endl;
		cout << "\t\t2 - Inserir\n" << endl;
		cout << "\t\t3 - Buscar\n" << endl;
		cout << "\t\t4 - Remover\n" << endl;
		cout << "\t\t5 - Reorganizar\n" << endl;
		cout << "\t\t6 - Calcular\n" << endl;
		cout << "\t\t7 - Mostrar Valores\n" << endl;
		cout << "\t\t8 - Sair" << endl;
	
		cout << "\n\nEscolha a opção: ";
		cin >> al;
		
		switch (al)
		{
			case 1:
				system("cls");

				int al1;
				while(al1 != 9)
				{
					system("cls");
					cout << "\t\t\tFunção de Cadastros\n\n";
					cout << "\t1 - Paciente" << endl;
					cout << "\t2 - Indice Paciente" << endl;
					cout << "\t3 - Especialização" << endl;
					cout << "\t4 - Indice Especialização" << endl;
					cout << "\t5 - Médico" << endl;
					cout << "\t6 - Indice Médico" << endl;
					cout << "\t7 - Consulta Marcada" << endl;
					cout << "\t8 - Indice Consulta" << endl;

					cout << "\n\t9 - Voltar";

					cout << "\n\n\tEscolha uma opção: ";
					cin >> al1;

					switch (al1)
					{
					case 1:
						system("cls");
						cout << "\tPaciente\n\n";
						leituraPaciente(arqPac, contPac);
						system("pause");
						break;

					case 2:
						system("cls");
						cout << "\tIndice Paciente\n\n";
						leituraIndicePaciente(idxPac, contPac);
						system("pause");
						break;

					case 3:
						system("cls");
						cout << "\tEspecialização\n\n";
						leituraEspecializacao(arqEspec, contEsp);
						system("pause");
						break;
					
					case 4:
						system("cls");
						cout << "\tIndice Especialização\n\n";
						leituraIndiceEspecializacao(idxEspec, contEsp);
						system("pause");
						break;
						
					case 5:
						system("cls");
						cout << "\tMédico\n\n";
						leituraMedico(arqMed, contMed);
						system("pause");
						break;
					
					case 6:
						system("cls");
						cout << "\tIndice Médico\n\n";
						leituraIndiceMedico(idxMed, contMed);
						system("pause");
						break;
						
					case 7:
						system("cls");
						cout << "\tConsulta Marcada\n\n";
						leituraConsulta(arqCons, contCons);
						system("pause");
						break;
						
					case 8:
						system("cls");
						cout << "\tIndice Consulta\n\n";
						leituraIndiceConsulta(idxCons, contCons);
						system("pause");
						break;

					case 9:
						system("cls");
						cout << "Voltando...\n\n\n";
						break;
					
					default:
						system("cls");
						cout << "Opção inválida! Informe um valor entre 1 e 9.\n\n\n";
						system("pause");
						al1 = 0;
						break;
					}
				}
				al1 = 0;
			    break; 
			    
			
			case 2:
				system("cls");
				
				int al2;
				while (al2 != 4)
				{
					system("cls");
					cout << "\t\t\tFunção para a Inclusão de novos Registros\n\n";
					cout << "\t\t1 - Pacientes" << endl;
					cout << "\t\t2 - Médicos" << endl;
					cout << "\t\t3 - Consultas" << endl;

					cout << "\n\t\t4 - Voltar";

					cout << "\n\n\tEscolha uma opção: ";
					cin >> al2;
				
					switch (al2)
					{
						case 1:
							system("cls");
							cout << "\nInclusão de Paciente\n" << endl;
							for (int codpesq = 9; codpesq != 0;){
								cout << "\nInforme o CPF do Paciente a ser Incluido (0 para Encerrar): ";
								cin >> codpesq;
								if (codpesq != 0)
									buscaaleatPaciente (idxPac, arqPac, contPac, codpesq);
							}
							system("pause");
							break;
							
						case 2:
							system("cls");
							cout << "\nInclusão de Médico\n" << endl;
							for (int codpesq = 9; codpesq != 0;){
								cout << "\nInforme o CRM do Médico a ser Incluido (0 para Encerrar): ";
								cin >> codpesq;
								if (codpesq != 0)
									buscaaleatMedico (idxMed, arqMed, idxEspec, arqEspec, contEsp, contMed, codpesq);
							}
							system("pause");
							break;
							
						case 3:
							system("cls");
							cout << "\nInclusão de Consulta\n" << endl;
							for (int codpesq = 9; codpesq != 0;){
								cout << "\nInforme o CPF do Paciente a ser consultado (0 para Encerrar): ";
								cin >> codpesq;
								if (codpesq != 0)
									buscaaleatCons (idxMed, arqMed, arqPac, idxCons, arqCons, contMed, contCons, codpesq);
							}
							system("pause");
							break;
							
						case 4:
							system("cls");
							cout << "Voltando...\n\n\n";
							break;
						
						default:
							system("cls");
							cout << "Opção inválida! Informe um valor entre 1 e 3.\n\n\n";
							system("pause");
							al2 = 0;
							break;
					}				
				}
				al2 = 0;
				break;
			
			case 3:
				system("cls");
				
				int al3;
				while (al3 != 2)
				{
					system("cls");
					cout << "\t\t\tFunção de Busca\n\n";
					cout << "\t\t1 - Buscar Médico por Especialização" << endl;
					
					cout << "\n\t\t2 - Voltar";
					
					cout << "\n\n\tEscolha uma opção: ";
					cin >> al3;
					
					switch (al3)
					{
						case 1:
							system("cls");
							cout << "\nBusca de Médicos por Especialização\n" << endl;
							for (int codpesq = 9; codpesq != 0;){
								cout << "\nInforme o código da Especialização (0 para encerrar): ";
								cin >> codpesq;
								if (codpesq != 0)
									buscaaleatEsp (idxEspec, arqEspec, idxMed, arqMed, contMed, contEsp, codpesq);
							}
							system("pause");
							break;
							
						case 2:
							system("cls");
							cout << "Voltando...\n\n\n";
							break;
					
						default:
							system("cls");
							cout << "Opção inválida! Informe um valor entre 1 e 2.\n\n\n";
							system("pause");
							al3 = 0;
							break;
				   }
			    }
				al3 = 0;
				break;
				
			case 4:
				system("cls");
				
				int al4;
				while(al4 != 2)
				{
					system("cls");
					cout << "\t\t\tFunção para a Remoção de Registros\n\n";
					cout << "\t1 - Remover Médico" << endl;
					
					cout << "\n\t2 - Voltar";
					
					cout << "\n\n\tEscolha uma opção: ";
					cin >> al4;
					
					switch (al4)
					{
						case 1:
							system("cls");
							cout << "\nRemoção de Médico\n" << endl;
							for (int codpesq = 9; codpesq != 0;){
								cout << "\nInforme o CRM do Médico a ser Removido (0 para Encerrar): ";
								cin >> codpesq;
								if (codpesq != 0)
									exclusaoMedico (idxMed, arqMed, contMed, codpesq);
							}
							system("pause");
							break;
							
						case 2:
							system("cls");
							cout << "Voltando...\n\n\n";
							break;
					
						default:
							system("cls");
							cout << "Opção inválida! Informe um valor entre 1 e 2.\n\n\n";
							system("pause");
							al4 = 0;
							break;
					}
				}
				al4 = 0;
				break;
				
			case 5:
				system("cls");
				
				int al5;
				while (al5 != 2)
				{
					system("cls");
					cout << "\t\t\tFunção para a Reorganização de Registros\n\n";
					cout << "\t1 - Reorganizar a tabela Médico" << endl;
					
					cout << "\n\t2 - Voltar";
					
					cout << "\n\n\tEscolha uma opção: ";
					cin >> al5;
					
					switch (al5)
					{
						case 1:
							system("cls");
							cout << "\nReorganização da tabela Médico\n" << endl;
							reorganizacaoMedico (arqMed, idxMed, contMed, arqNovoMed);
							system("pause");
							break;
							
						case 2:
							system("cls");
							cout << "Voltando...\n\n\n";
							break;
					
						default:
							system("cls");
							cout << "Opção inválida! Informe um valor entre 1 e 2.\n\n\n";
							system("pause");
							al5 = 0;
							break;
					}
				}
				al5 = 0;
				break;
				
			case 6:
				system("cls");
				int al6;
				while (al6 != 2)
				{
					system("cls");
					cout << "\t\t\tFunção de Faturamento\n\n";
					cout << "\t1 - Mostrar Faturamento da Clinica" << endl;
					
					cout << "\n\t2 - Voltar";
					
					cout << "\n\n\tEscolha uma opção: ";
					cin >> al6;
					
					switch (al6)
					{
						case 1:
							system("cls");
							cout << "\tFaturamento da Clinica\n\n";
							faturamentoClinica (arqCons, arqMed, contCons, contMed);
							system("pause");
							break;
							
						case 2:
							system("cls");
							cout << "Voltando...\n\n\n";
							break;
							
						default:
							system("cls");
							cout << "Opção inválida! Informe um valor entre 1 e 2.\n\n\n";
						    system("pause");
						    al6 = 0;
						    break;
							
					}
				}
				al6 = 0;
				break;
				
			case 7:
				system("cls");
				
				int al7;
				while(al7 != 2)
				{
					system("cls");
					cout << "\t\t\tFunção dos Valores das Consultas mais Cara/Barata\n\n";
					cout << "\t1 - Mostrar Valor" << endl;
					
					cout << "\n\t2 - Voltar";
					
					cout << "\n\n\tEscolha uma opção: ";
					cin >> al7;
					
					switch (al7)
					{
						case 1:
							system("cls");
							cout << "\tConsulta mais cara e mais barata\n\n";
							valorConsulta (idxMed, arqMed, contMed);
							system("pause");
							break;
						
						case 2:
							system("cls");
							cout << "Voltando...\n\n\n";
							break;
							
						default:
							system("cls");
							cout << "Opção inválida! Informe um valor entre 1 e 2.\n\n\n";
						    system("pause");
						    al7 = 0;
						    break;
					}
				}
				al7 = 0;
				break;
			    
			case 8:  
			   system("cls");
			   cout << "Saindo.\n\n";
			   break; 
						
			
			default:
				system("cls");
			    cout << "\nOpção inválida. Informe um número entre 1 e 8\n\n\n";
			    system("pause");
			    al = 0;
				break;
		}
	}	
}