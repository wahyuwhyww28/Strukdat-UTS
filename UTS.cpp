#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Buku {
    string judul;
    string penulis;
    int thTerbit;
    string isbn;
};

struct Node {
    Buku data;
    Node* next;
};

Node* buatNode(Buku data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void inputNode(Node* &head, Buku data) {
    Node* newNode = buatNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void hapusNode(Node* &head, string isbn) {
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr && temp->data.isbn != isbn) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Buku dengan ISBN " << isbn << " tidak ditemukan." << endl;
        return;
    }
    if (prev == nullptr) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
}

Node* buatNode(Node* head, string isbn) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.isbn == isbn) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void updateNode(Node* head, string isbn) {
    Node* nodeToUpdate = buatNode(head, isbn);
    if (nodeToUpdate != nullptr) {
        cout << "Masukkan informasi baru:" << endl;
        cout << "Judul: ";
        getline(cin >> ws, nodeToUpdate->data.judul);
        cout << "Penulis: ";
        getline(cin >> ws, nodeToUpdate->data.penulis);
        cout << "Tahun Terbit: ";
        cin >> nodeToUpdate->data.thTerbit;
        cout << "ISBN: ";
        cin >> nodeToUpdate->data.isbn;
    } else {
        cout << "Buku dengan ISBN " << isbn << " tidak ditemukan." << endl;
    }
}

void daftarData(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Judul: " << temp->data.judul << endl;
        cout << "Penulis: " << temp->data.penulis << endl;
        cout << "Tahun Terbit: " << temp->data.thTerbit << endl;
        cout << "ISBN: " << temp->data.isbn << endl;
        cout << "=============================" << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = nullptr;
    char pilihan;
    do {
        cout << "Menu Awal:" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Hapus Buku" << endl;
        cout << "3. Update Informasi Buku" << endl;
        cout << "4. Tampilkan Daftar Buku" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case '1': {
                Buku newBook;
                cout << "Masukkan informasi buku:" << endl;
                cout << "Judul: ";
                getline(cin >> ws, newBook.judul);
                cout << "Penulis: ";
                getline(cin >> ws, newBook.penulis);
                cout << "Tahun Terbit: ";
                cin >> newBook.thTerbit;
                cout << "ISBN: ";
                cin >> newBook.isbn;
                inputNode(head, newBook);
                break;
            }
            case '2': {
                string isbnToDelete;
                cout << "Masukkan ISBN buku yang akan dihapus: ";
                cin >> isbnToDelete;
                hapusNode(head, isbnToDelete);
                break;
            }
            case '3': {
                string isbnToUpdate;
                cout << "Masukkan ISBN buku yang akan diupdate: ";
                cin >> isbnToUpdate;
                updateNode(head, isbnToUpdate);
                break;
            }
            case '4': {
                cout << "Daftar Buku:" << endl;
                daftarData(head);
                break;
            }
            case '5':
                cout << "Program berakhir." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != '5');

    return 0;
}
