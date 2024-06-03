#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Tarefa { //"class" facilita o manuseio das tarefas em seu interior
public:   
	string Titulo;
	string ID;
    string Descricao;
    string Vencimento;
    int Status;

	Tarefa(string t, string i, string d, string v, int s) : Titulo(t), ID(i), 
    Descricao(d), Vencimento(v), Status(s) {}
}; //cria objeto tarefa e da valor


void addTarefa(vector<Tarefa>& tarefas, const string& Titulo, const string& ID, const string& Descricao, 
    const string& Vencimento, int Status) {
	tarefas.push_back(Tarefa(Titulo, ID, Descricao, Vencimento, Status));
} // adiciona uma nova tarefa, recebe os indicadores, cria um objeto tarefa, adiciona ao vetor tarefas


void mostrarTarefas(const vector<Tarefa>& tarefas) {
	for (size_t i = 0; i < tarefas.size(); ++i) {
    	cout << "Tarefa: " << tarefas[i].Titulo << ", ID: " << tarefas[i].ID << ", Descrição: " << tarefas[i].Descricao << 
        ", Vencimento: " << tarefas[i].Vencimento << ", Status: " << tarefas[i].Status << endl;
	}
} // exibe todas as tarefas no vetor tarefas 

void editTarefa(vector<Tarefa>& tarefas, const string& ID) {
    for (auto& tarefa : tarefas) { // auto coloca atribui automaticamente uma int, string ou char para a variável
        if (tarefa.ID == ID) {
            cout << "Editar a tarefa com o ID: " << ID << endl;

            cout << "Digite o novo título: ";
            string novoTitulo;
            getline(cin, novoTitulo);
            tarefa.Titulo = novoTitulo; // faz com que o título antigo sej asubstituído pelo título novo

            cout << "Digite a nova descrição: ";
            string novaDescricao;
            getline(cin, novaDescricao);
            tarefa.Descricao = novaDescricao;

            cout << "Digite o novo prazo: ";
            string novoVencimento;
            getline(cin, novoVencimento);
            tarefa.Vencimento = novoVencimento;

            cout << "Novo status (1 - Pendente, 2 - Em Progresso, 3 - Concluída: ";
            int novoStatus;
            cin >> novoStatus;
            cin.ignore();
            tarefa.Status = novoStatus;
            cout << "Tarefa editada" << endl;
            return;
        }
    }
    cout << "ID " << ID << " não encontrado." << endl;
} // edita a tarefa de acordo com o ID digitado

void removerTarefa(vector<Tarefa>& tarefas, const string& ID){
    for (size_t i = 0; i < tarefas.size(); ++i) {
    	if (tarefas[i].ID == ID) {
        	tarefas.erase(tarefas.begin() + i);
        	break;
    	}
	}
    } // remove tarefas com base no ID

void procuraTarefa(vector<Tarefa>& tarefas, const string& Titulo){
    bool encontrada = false;
    for (const auto& tarefa : tarefas) {
    if (tarefa.Titulo == Titulo) {
        encontrada = true;
        cout << "Tarefas encontradas: " <<endl;
        cout << "Título: " <<tarefa.Titulo <<endl;
        cout << "ID: " <<tarefa.ID <<endl;
        cout << "Descriçao: " <<tarefa.Descricao <<endl;
        cout << "Vencimento: " <<tarefa.Vencimento <<endl;
        cout << "Status: " <<tarefa.Status <<endl;
        break;
      } 
    }
        if(!encontrada){
        cout << "Tarefa não encontrada." <<endl;
      }
    } // procura tarefa com base no título


void filtraStatus(vector<Tarefa>& tarefas, int Status){
    bool encontrada = false;
    for (const auto& tarefa : tarefas) {
    if (tarefa.Status == Status) {
        encontrada = true;
        cout << "Tarefas encontradas: " <<endl;
        cout << "Título: " <<tarefa.Titulo <<endl;
        cout << "ID: " <<tarefa.ID <<endl;
        cout << "Descriçao: " <<tarefa.Descricao <<endl;
        cout << "Vencimento: " <<tarefa.Vencimento <<endl;
        cout << "Status: " <<tarefa.Status <<endl;
      } 
    }
        if(!encontrada){
        cout << "Tarefa não encontrada." <<endl;
      }
    } // procura tarefas pelo status






int main() {
	vector<Tarefa> tarefas;
	string Titulo;
	string ID;
    string Descricao;
    string Vencimento;
    int Status;
	int escolha;

	do {
        cout << endl;
    	cout << "=== MENU ===" << endl;
    	cout << "1. Adicionar tarefa" << endl;
    	cout << "2. Visualizar tarefa" << endl;
    	cout << "3. Editar tarefa" << endl;
        cout << "4. Remover tarefa" << endl;
        cout << "5. Buscar tarefa" << endl;
    	cout << "6. Filtrar por status" << endl;
        cout << "0. Sair" << endl;
    	cout << "Escolha uma opção: ";
        cout <<endl;
    	cin >> escolha;


        if(escolha == 1){
            cout << "Título da tarefa: ";
            cin.ignore();
            getline(cin, Titulo);
            cout << "ID da tarefa: ";
            getline(cin, ID);
            cout << "Descrição da tarefa: ";
            getline(cin, Descricao);
            cout << "Prazo de vencimento da tarefa: ";
            getline(cin, Vencimento);
            cout << "Status da tarefa (1 - Pendente, 2 - Em Progresso, 3 - Concluída): ";
            cin >> Status;

            addTarefa(tarefas,Titulo, ID, Descricao, Vencimento, Status);
            
        } else if(escolha == 2){
            mostrarTarefas(tarefas);
        } else if(escolha == 3){
            cout << "Digite o ID da tarefa a ser editada: ";
            cin.ignore();
            getline(cin, ID);
            editTarefa(tarefas, ID);
        } else if(escolha == 4){
            cout << "Digite o ID da tarefa a ser removida: ";
            cin.ignore();
            getline(cin, ID);
            removerTarefa(tarefas, ID);
        }else if(escolha == 5){
            cout << "Digite o nome da tarefa que procura: ";
            cin.ignore();
            getline(cin, Titulo);
            procuraTarefa(tarefas, Titulo);
        }else if(escolha == 6){
            cout << "Digite o status que deseja filtrar: ";
            cin >> Status;
            filtraStatus(tarefas, Status);
        }
    } 
    while (escolha != 0);

	return 0;
}
