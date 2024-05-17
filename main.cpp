#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int option;

    cout << "Sistema de Gerenciamento de Tarefas" <<endl;
    cout << "1. Adicionar Tarefa" <<endl;
    cout << "2. Visualizar Tarefas" <<endl;
    cout << "3. Editar Tarefa" <<endl;
    cout << "4. Remover Tarefa" <<endl;
    cout << "5. Buscar Tarefa" <<endl;
    cout << "6. Filtrar Tarefas por Status" <<endl;
    cout << "0. Sair" <<endl;
    cout << "Escolha uma opção: " <<endl;

    cin >>  option;

    //  0. SAIR
    
    if(option == 0){
        cout << endl;
    }


    // GUARDAR INFORMAÇÕES

    int ID[10];
    string title[10];
    string description[10];
    string valid[10];
    int stats[10];

    int i = 0;

    //  1. ADICIONAR TAREFAS

    if(option == 1){
        cout << "Adicionar Nova Tarefa" <<endl;
        cout << "ID da Tarefa: " << endl;
        cin >> ID[i] ;
        cin.ignore();
        cout << "Título: " <<endl;
        getline(cin, title[i]);
        cout << "Descrição: " <<endl;
        getline(cin, description[i]);
        cout << "Data de Vencimento: " <<endl;
        getline(cin, valid[i]);
        cout << "Status (1 - Pendente, 2 - Em Progresso, 3 - Concluída): " <<endl;
        cin >> stats[i];
        cout << "ID da Tarefa:" << ID[i] <<endl;
        cout << "Título: " << title[i] <<endl;
        cout << "Descrição: " << description[i] <<endl;
        cout << "Data de Vencimento: " << valid[i] <<endl;
        cout << "Status (1 - Pendente, 2 - Em Progresso, 3 - Concluída): " << stats[i] <<endl;
        cout << "Tarefa adicionada com sucesso!" <<endl;
        
        i++;
    }

    













    return 0;
}


