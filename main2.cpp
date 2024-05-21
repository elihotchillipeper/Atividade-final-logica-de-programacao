#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estrutura para armazenar informações de uma tarefa
struct Task {
    int id;
    string title;
    string description;
    string dueDate;
    string status;
};

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\nMenu:\n1. Adicionar Tarefa\n2. Visualizar Tarefas\n0. Sair\nEscolha: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                Task newTask;
                cout << "ID da Tarefa: ";
                cin >> newTask.id;
                cout << "Título: ";
                cin.ignore();
                getline(cin, newTask.title);
                cout << "Descrição: ";
                getline(cin, newTask.description);
                cout << "Data de Vencimento: ";
                getline(cin, newTask.dueDate);
                cout << "Status (Pendente, Em Progresso, Concluída): ";
                getline(cin, newTask.status);
                tasks.push_back(newTask);
                cout << "Tarefa adicionada com sucesso!" << endl;
                break;
            }
            case 2: {
                if (tasks.empty()) {
                    cout << "Nenhuma tarefa cadastrada." << endl;
                } else {
                    cout << "Listagem de Tarefas:" << endl;
                    for (const auto &task : tasks) {
                        cout << "ID: " << task.id << endl;
                        cout << "Título: " << task.title << endl;
                        cout << "Descrição: " << task.description << endl;
                        cout << "Data de Vencimento: " << task.dueDate << endl;
                        cout << "Status: " << task.status << endl;
                        cout << "-----------------------------" << endl;
                    }
                }
                break;
            }
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opção inválida. Por favor, escolha novamente." << endl;
        }
    } while(choice != 0);

    return 0;
}
