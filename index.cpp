#include <iostream>
#include <vector>

using std::cin, std::cout, std::vector, std::string;

struct Pet {
    string namePet;
    string type;

    Pet(string name = "", string t = "") : namePet(name), type(t) {}

    string getInfo() const {return type + " - " + namePet;}
};

class Client {
    private:
        string name;
        string last_name;
        string email;
        int phone;
        Pet pet;
    public:
        Client (const string& n, const string& ln, const string& e, int p) : name(n), last_name(ln), email(e), phone(p), pet() {}

        string getName() const { return name; }
        string getLastName() const { return last_name; }
        string getEmail() const { return email; }
        int getPhone() const { return phone; }
        string getPetInfo() const { return pet.getInfo(); }

        void setName(const string& new_name) { name = new_name; }
        void setLastName(const string& new_lastname) { last_name = new_lastname; }
        void setEmail(const string& new_email) { email = new_email; }
        void setPhone(const int new_phone) { phone = new_phone; }
        void setPetInfo(const string& new_namePet, const string& new_type) {
            pet.namePet = new_namePet;
            pet.type = new_type;
        }
};

vector<Client> client_list{};

void register_client(Client&);
void register_pet();
void remove_client();
void show_client();
Client& get_client_by_index(int);

int main() {
    int option;
    do {
        cout << "1. Registrar cliente\n2. Registrar mascota\n3. Eliminar cliente\n4. Mostrar clientes\n5. Salir\n";
        cout << "Opcion: ";
        cin >> option;

        switch (option) {
            case 1: {
                string name, last_name, email;
                int phone;
                cout << "Nombre, apellido, email y telefono: ";
                cin >> name >> last_name >> email >> phone;
                Client client(name, last_name, email, phone);
                register_client(client);
                break;
            }
            case 2:
                register_pet();
                break;
            case 3:
                remove_client();
                break;
            case 4:
                show_client();
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (option != 5);

    return 0;
}

void register_client(Client& client) {
    client_list.push_back(client);
    cout << client.getName() << " " << client.getLastName() << " fue registrado correctamente.\n";
}

void register_pet() {
    show_client();
    int index;
    cout << "Que usuario desea modificar (ingrese su numero en lista): ";
    cin >> index;

    Client& client = get_client_by_index(index - 1);

    string namePet, type;
    cout << "Nombre y tipo de mascota: ";
    cin >> namePet >> type;
    client.setPetInfo(namePet, type);
    cout << "Tu mascota " << namePet << " fue registrado correctamente.\n";
}

void remove_client() {
    show_client();
    int index;
    cout << "Que usuario desea eliminar (ingrese su numero en lista): ";
    cin >> index;

    if (index - 1 < 0 || index - 1 >= client_list.size()) {
        cout << "Indice de cliente invalido.\n";
    }
    client_list.erase(client_list.begin() + index - 1);
}

void show_client() {
    if (client_list.empty()) {
        cout << "No hay clientes registrados.\n";
    } else {
        int index = 1;
        cout << "Lista de clientes:\n" ;
        for (const auto& client : client_list) {
            cout << index << " " << client.getName() << " - " << client.getLastName()
                    << " - " << client.getEmail() << " - " << client.getPetInfo() << "\n";
            index++;
        }
    }
}

Client& get_client_by_index(int index) {
    if (index < 0 || index  >= client_list.size()) {
        cout << "Indice de cliente invalido.\n";
    }
    return client_list[index];
}