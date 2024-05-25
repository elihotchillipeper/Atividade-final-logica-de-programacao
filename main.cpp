#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Tarefa {
public:
	string Titulo;
	string ID;
    string Descricao;
    string Vencimento;
    int Status;

	Tarefa(string t, string i, string d, string v, int s) : Titulo(t), ID(i), 
    Descricao(d), Vencimento(v), Status(s) {}
};

//Adiciona tarefa; vector: estrutura de array porem aumenta e diminui automaticamente
void addTarefa(vector<Tarefa>& tarefas, const string& Titulo, const string& ID, const string& Descricao, 
    const string& Vencimento, int Status) {
	tarefas.push_back(Tarefa(Titulo, ID, Descricao, Vencimento, Status));
}


void mostrarTarefas(const vector<Tarefa>& tarefas) {
	for (size_t i = 0; i < tarefas.size(); ++i) {
    	cout << "Tarefa: " << tarefas[i].Titulo << ", ID: " << tarefas[i].ID << ", Descrição: " << tarefas[i].Descricao << 
        ", Vencimento: " << tarefas[i].Vencimento << ", Status: " << tarefas[i].Status << endl;
	}
}


void editTarefa(vector<Tarefa>& tarefas, const string& ID) {
    for (auto& tarefa : tarefas) {
        if (tarefa.ID == ID) {
            cout << "Editar tarefa com o ID: " << ID << endl;

            cout << "Digite o novo título: ";
            string novoTitulo;
            getline(cin, novoTitulo);

            cout << "Digite a nova descrição: ";
            string novaDescricao;
            getline(cin, novaDescricao);

            cout << "Digite o novo prazo: ";
            string novoVencimento;
            getline(cin, novoVencimento);

            cout << "Novo status (1 - Pendente, 2 - Em Progresso, 3 - Concluída: ";
            int novoStatus;
            cin >> novoStatus;
            cin.ignore();
            cout << "Tarefa editada" << endl;
            return;
        }
    }
    cout << "Tarefa " << ID << " não encontrada." << endl;
}








int main() {
	vector<Tarefa> tarefas;
	string Titulo;
	string ID;
    string Descricao;
    string Vencimento;
    int Status;
	int escolha;

	do {
    	cout << "=== MENU ===" << endl;
    	cout << "1. Adicionar tarefa" << endl;
    	cout << "2. Visualizar tarefa" << endl;
    	cout << "3. Editar tarefa" << endl;
        cout << "4. Remover tarefa" << endl;
    	cout << "5. Filtrar por status" << endl;
        cout << "0. Sair" << endl;
    	cout << "Escolha uma opção: ";
    	cin >> escolha;


        if(escolha == 1){
            cout << "Título da tarefa: ";
            cin.ignore();
            getline(cin, Titulo);
            cout << "ID da tarefa: ";
            cin.ignore();
            getline(cin, ID);
            cout << "Descrição da tarefa: ";
            cin.ignore();
            getline(cin, Descricao);
            cout << "Prazo de vencimento da tarefa: ";
            cin.ignore();
            getline(cin, Vencimento);
            cout << "Status da tarefa (1 - Pendente, 2 - Em Progresso, 3 - Concluída): ";
            cin >> Status;

            addTarefa(tarefas,Titulo, ID, Descricao, Vencimento, Status);
            
        } else if(escolha == 2){
            mostrarTarefas(tarefas);
        } else if(escolha == 3){
            cout << "Digite o ID da tarefa a ser editada: ";
            getline(cin, ID);
            editTarefa(tarefas, ID);
        }
    } while (escolha != 0);

	return 0;
}