// ALGO2 IS1 222A LAB03
// Jakub Wojciechowski
// wj46693@zut.edu.pl

#include <iostream>
#include <time.h>

using namespace std;

int key = 0;
int i = 0;
int rozmiar_flaga = 0;

template <class T>
class Node
{
public:
    Node* parent;
    Node* left;
    Node* right;
    T data;
    int key;
};

template <class T>
class BST
{
public:
    int size;
    BST* root;

    BST()
    {
        size = 0;
        root = NULL;
    }

    void add_node(Node<T>*& root, T data)
    {
        Node<T>* n = new Node<T>;

        n->left = n->right = NULL;
        n->data = data;
        n->key = key;

        Node<T>* r = root;

        if (root == NULL)
        {
            root = n;
        }
        else
            while (true)
            {
                if (data < r->data)
                {
                    if (r->left == NULL)
                    {
                        r->left = n;
                        break;
                    }
                    else r = r->left;
                }
                else if (data > r->data)
                {
                    if (r->right == NULL)
                    {
                        r->right = n;
                        break;
                    }
                    else r = r->right;
                }
            }
        n->parent = r;
        size++;
        key++;
    }

    Node<T>* find_node(Node<T>* root, T data)
    {
        if (root == NULL || root->data == data)
        {
            return root;
        }
        if (root->data > data)
        {
            return find_node(root->left, data);
        }
        else if (root->data < data)
        {
            return find_node(root->right, data);
        }
    }

    Node<T>* delete_node(Node<T>* root, T data)
    {
        if (rozmiar_flaga == 0)
        {
            size--;
        }
        rozmiar_flaga++;

        if (root == NULL)
        {
            return root;
        }

        if (data < root->data)
            root->left = delete_node(root->left, data);

        else if (data > root->data)
            root->right = delete_node(root->right, data);

        else
        {
            if (root->left == NULL)
            {
                Node<T>* temp = root->right;
                delete(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                Node<T>* temp = root->left;
                delete(root);
                return temp;
            }

            Node<T>* temp = find_min(root->right);

            root->data = temp->data;

            root->right = delete_node(root->right, temp->data);
        }
        return root;
    }

    void preorder(Node<T>* root)
    {
        if (root)
        {
            cout << root->data << " -> ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(Node<T>* root)
    {
        if (root)
        {
            inorder(root->left);
            cout << root->data << " -> ";
            inorder(root->right);
        }
    }

    void remove_all(Node<T>* root)
    {
        if (root)
        {
            remove_all(root->left);
            remove_all(root->right);
            delete root;
        }
    }

    void printBST(Node<T>* root)
    {
        if (root)
        {
            cout << "(";
            if (root->key > -1)
            {
                cout << root->key;
            }
            cout << ": [p: ";

            if (root->parent)
            {
                cout << root->parent->key;
            }
            else cout << "NULL";

            cout << ", l: ";
            if (root->left)
            {
                cout << root->left->key;
            }
            else cout << "NULL";

            cout << ", r: ";
            if (root->right)
            {
                cout << root->right->key;
            }
            else cout << "NULL";

            cout << "], ";
            cout << "data: ";
            cout << root->data;
            cout << "), ";
            cout << endl;

            printBST(root->left);
            printBST(root->right);
        }
    }

    Node<T>* find_min(Node<T>* node)
    {
        Node<T>* p = node;

        while (p && p->left != NULL)
        {
            p = p->left;
        }
        return p;
    }

    Node<T>* find_max(Node<T>* node)
    {
        Node<T>* p = node;

        while (p && p->right != NULL)
        {
            p = p->right;
        }
        return p;
    }

    T findMax(T a, T b) {
        if (a >= b)
            return a;
        else
            return b;
    }

    T findHeight(Node<T>* root) {
        if (root == NULL)
        {
            return 0;
        }

        T left_height = findHeight(root->left);
        T right_height = findHeight(root->right);

        return findMax(left_height, right_height) + 1;
    }
};

int main()
{
    Node<int>* root = NULL;
    BST<int>* drzewo = new BST<int>;
    srand(time(NULL));

    cout << "Dodawanie elementow: \n";

    clock_t t1 = clock();
    for (int i = 0; i < 100; i++)
    {       
        drzewo->add_node(root, rand() % 10000);
    }
    clock_t t2 = clock();
    double time = double(t2 - t1) / (CLOCKS_PER_SEC);   
    
    clock_t t3 = clock();
    int hits = 0;
    for (int i = 0; i < 10000; i++)
    {
        Node<int>* result = drzewo->find_node(root, rand() % 10000);
        if (result != NULL)
        {
            hits++;
        }
    }
    clock_t t4 = clock();
    double time1 = double(t4 - t3) / (CLOCKS_PER_SEC);

    

    cout << "\nbinary search tree :\n\n";
    drzewo->printBST(root);
    cout << endl;
    cout << "Czas dodawania: " << time << " ms" << endl;
    cout << endl;
    cout << "Liczba poprawnych prob wyszukania: " << hits;
    cout << endl;
    cout << "Rozmiar drzewa = " << drzewo->size;
    cout << endl;
    cout << "Wysokosc drzewa: " << drzewo->findHeight(root) - 1;
    cout << endl;
    cout << "min = " << drzewo->find_min(root)->data;
    cout << endl;
    cout << "max = " << drzewo->find_max(root)->data;
    cout << endl;
    cout << "root = ";
    cout << root << endl;
    cout << "root->data = " << root->data;
    cout << endl;    cout << endl;

    cout << "\nPo usunieciu wartosci 10: \n\n";
    rozmiar_flaga = 0;
    drzewo->delete_node(root, 10);

    drzewo->printBST(root);
    cout << endl;
    cout << "Czas dodawania: " << time << " ms" << endl;
    cout << endl;
    cout << "Liczba poprawnych prob wyszukania: " << hits;
    cout << endl;
    cout << "Rozmiar drzewa = " << drzewo->size;
    cout << endl;
    cout << "Wysokosc drzewa: " << drzewo->findHeight(root) - 1;
    cout << endl;
    cout << "min = " << drzewo->find_min(root)->data;
    cout << endl;
    cout << "max = " << drzewo->find_max(root)->data;
    cout << endl;
    cout << "root = ";
    cout << root << endl;
    cout << "root->data = " << root->data;
    cout << endl;    cout << endl;

    cout << "\nPo usunieciu wartosci 33: \n\n";
    rozmiar_flaga = 0;
    drzewo->delete_node(root, 33);

    drzewo->printBST(root);
    cout << endl;
    cout << "Czas dodawania: " << time << " ms";
    cout << endl;
    cout << "Liczba poprawnych prob wyszukania: " << hits;
    cout << endl;
    cout << "Rozmiar drzewa = " << drzewo->size;
    cout << endl;
    cout << "Wysokosc drzewa: " << drzewo->findHeight(root) - 1;
    cout << endl;
    cout << "min = " << drzewo->find_min(root)->data;
    cout << endl;
    cout << "max = " << drzewo->find_max(root)->data;
    cout << endl;
    cout << "root = ";
    cout << root << endl;
    cout << "root->data = " << root->data;
    cout << endl;    cout << endl;

    cout << "\nPo wyszukanie wartosci 12: \n";
    drzewo->find_node(root, 12) ? cout << "Ten element znajduje sie w drzewie BST" : cout << "Nie ma takiego elementu w drzewie BST ";
    cout << endl; cout << endl;

    cout << "\nPo wyszukanie wartosci 66: \n";
    drzewo->find_node(root, 66) ? cout << "Ten element znajduje sie w drzewie BST" : cout << "Nie ma takiego elementu w drzewie BST ";
    cout << endl; cout << endl;

    drzewo->remove_all(root);
    delete drzewo;

    return 0;

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
