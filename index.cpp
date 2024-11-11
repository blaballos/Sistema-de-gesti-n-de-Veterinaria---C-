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