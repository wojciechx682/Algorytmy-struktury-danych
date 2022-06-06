// Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

template <class T>
class Node
{
public:
    T field_1;    
    Node* next;
    Node* previous;
};

template <class T>
class Lista
{
public:    
    Node<T>* head; 
    Node<T>* tail;
    int size;

    Lista()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void push_back(T data)
    {
        Node<T>* element = new Node<T>;
        element->field_1 = data;        
        element->next = nullptr;
        element->previous = tail;
        tail = element;        
        if (element->previous != nullptr)
        {
            element->previous->next = element;
        }
        else if (element->previous == nullptr)
        {
            head = element; 
        }      
        size++;
    }    

    void push_front(T data)
    {
        Node<T>* element = new Node<T>;    
        element->field_1 = data;
        element->next = head;
        element->previous = nullptr;
        // element->next
        if (head != nullptr) 
        {
            head->previous = element;
        }
        else if (head == nullptr) 
        { 
            tail = element;
        }     
        head = element;
        size++;
    }

    void PopBack()
    {
        if (head != nullptr)
        {
            Remove(tail);
        }
    }

    void PopFront()
    {
        if (head != nullptr)
        {      
            Remove(head);
        }
    }

    void ShowListElement(int index)
    {
        Node<T>* element = head;

        if (index >= 0 && index < size)
        {
            cout << "Element o indeksie " << index << " ma wartosc: ";
            for (int i = 0; i < index; i++)
            {
                element = element->next;
            }
            cout << element->field_1;
            cout << "  ";
            cout << "\n";
        }
        else if (index >= size) {
            cout << "Index poza zakresem! \n";            
        }
    }
        
    bool ReplacementElement(int index, T data)
    {
        Node<T>* element = head;

        if (index >= 0 && index < size)
        {
            for (int i = 0; i < index; i++)
            {
                element = element->next;
            }
            element->field_1 = data;
            return true;
        }
        return false;
    }

    void Search(T data)
    {
        Node<T>* element = head;
        int index = 0;

        while (element != NULL && element->field_1 != data)
        {
            element = element->next;
            index++;
        }

        if (index < size)
        {
            cout << "Element o wartosci '" << data << "' jest na pozycji o indeksie " << index << endl;            
        }
        else
        {
            cout << "Nie ma takiego elementu na liscie" << endl;            
        }
    }

    bool SearchAndDelete(T data)
    {
        Node<T>* element = head;

        while (element != NULL)
        {
            if (element->field_1 == data)
            {
                Remove(element);
                return true;
            }
            element = element->next;
        }
        return false;
    }   

    void sortedInsert(Node<T>* head, T data)
    {
        Node<T>* element = new Node<T>;
        element->field_1 = data;
        Node<T>* current;
        
        if (head == NULL || (head)->field_1 >= element->field_1) {
            push_front(data);
        }
        else {            
            current = head;
            while (current->next != NULL && current->next->field_1 < element->field_1) {
                current = current->next;
            }
            element->next = current->next;
            current->next = element;
            element->previous = current;
            if (current->next != nullptr)
            {
                current->next->previous = element;
            }            
            size++;
        }
    }
    
    void sortList() {
        Node<T>* current = NULL;
        Node<T>* index = NULL;
        int temp;        
        if (head == NULL) {
            return;
        }
        else {            
            for (current = head; current->next != NULL; current = current->next) {               
                for (index = current->next; index != NULL; index = index->next) {                    
                    if (current->field_1 > index->field_1) {
                        temp = current->field_1;
                        current->field_1 = index->field_1;
                        index->field_1 = temp;
                    }
                }
            }
        }
    }

    /*
    void ShowList()
    {
        Node<T>* element = head;
        
        element = head;
        while (element)
        {
            cout << " " << element->field_1;
            element = element->next;
        }        
    }
    */

    void ShowList()
    {
        Node<T>* element = head;

        cout << "Liczba elementow w liscie: " << size << endl << endl;

        if (size >= 11)
        {
            cout << "Poczatek listy: ";
            for (int i = 0; i < 10; i++)
            {
                cout << element->field_1;
                cout << "  ";
                element = element->next;
            }
            cout << "... ";
            cout << endl << endl;

            Node<T>* element = tail;
            for (int i = 0; i < 9; i++)
            {
                element = element->previous;
            }
            cout << "Koniec listy:   ... ";
            for (int i = 0; i < 10; i++)
            {
                cout << element->field_1;
                cout << "  ";
                element = element->next;
            }
        }

        else if (size < 11)
        {
            cout << "Zawartosc listy: ";
            if (size>0) // ewentualnie tez size > 0
            {
                for (int i = 0; i < size; i++)
                {
                    cout << element->field_1;
                    cout << "  ";
                    element = element->next;
                }
            }
            else cout << "pusta ";
        }
    }

    void Remove(Node<T>* element)
    {
        size--;
        if (element->previous != nullptr) 
        {
            element->previous->next = element->next;
        }
        else if (element->previous == nullptr)
        {
            head = element->next;
        }           
        if (element->next != nullptr) 
        {
            element->next->previous = element->previous;           
        }        
        else if (element->next == nullptr)
        {
            tail = element->previous;
        }
        delete element;  
    }
    
    ~Lista()
    {
        while (size)
        {            
            PopFront();
        }
    }
};

int main()
{
    srand(time(NULL));
    string data_type;
    int wybor;    
    int index;
    int n = 0;      
  
    cout << "Jaki typ danych przechowywac na liscie ? (wpisz 'char' lub 'int'): ";
    cin >> data_type;

    if (data_type == "char")
    {       
        char data;
        Lista<char>* L1 = new Lista<char>;                     
        cout << endl;
        for (;;)
        {
            system("cls");
            L1->ShowList();
            cout << endl << endl;
            cout << "-------------------------------------------------------------------------------\n" << endl;
            cout << "1. Dodaj element na koniec listy. \n";
            cout << "2. Dodaj element na poczatek listy. \n";
            cout << "3. Usun ostatni element. \n";
            cout << "4. Usun pierwszy element. \n";
            cout << "5. Wyswietl element o podanym indeksie. \n";
            cout << "6. Podmien dane. \n";
            cout << "7. Wyszukaj element \n";
            cout << "8. Wyszukaj i usun element \n";
            cout << "9. Dodaj element z wymuszeniem porzadku \n";
            cout << "10. Usun wszystkie elementy. \n";
            cout << "11. Dodaj 'n' elementow \n";
            cout << "12. Wyszukaj i usun element 'n' razy \n";

            cin >> wybor;           
            
            switch (wybor)
            {           
            case 1:
                cout << "Wpisz znak jaki chcesz dodac: ";
                cin >> data;
                L1->push_back(data);
                break;
            case 2:
                cout << "Wpisz znak jaki chcesz dodac: ";
                cin >> data;
                L1->push_front(data);
                break;
            case 3:
                L1->PopBack();
                break;
            case 4:
                L1->PopFront();
                break;
            case 5:
            {
                cout << "Podaj numer indeksu: ";
                cin >> index;
                clock_t t1 = clock();
                L1->ShowListElement(index);
                clock_t t2 = clock();
                double time_elapsed = double(t2 - t1) / (CLOCKS_PER_SEC / 1000);
                cout << "Operacja zajela: " << time_elapsed << " milisekund." << endl;
                cout << endl;
                system("pause");
            }  
                break;
            case 6:
                cout << "Podaj numer indeksu: ";
                cin >> index;
                if (index >= L1->size) {
                    cout << "Nie istnieje element o podanym indeksie \n";
                    system("pause");
                }
                else
                {
                    cout << "Podaj znak: ";
                    cin >> data;
                    L1->ReplacementElement(index, data) ? cout << "Element zostal podmieniony\n" : cout << "Nie ma elementu o takim indeksie \n";
                }
                break;
            case 7:
            {
                cout << "Podaj znak: ";
                cin >> data;
                clock_t t1 = clock();
                L1->Search(data);
                clock_t t2 = clock();
                double time_elapsed = double(t2 - t1) / (CLOCKS_PER_SEC / 1000);
                cout << "Operacja zajela: " << time_elapsed << " milisekund." << endl;
                cout << endl;
                system("pause");
            }                
                break;
            case 8:
            {
                cout << "Podaj znak: ";
                cin >> data;
                clock_t t1 = clock();
                L1->SearchAndDelete(data) ? cout << "Element o podanej wartosci zostal usuniety z listy \n" : cout << "Nie ma takich elementow na liscie \n";
                clock_t t2 = clock();
                double time_elapsed = double(t2 - t1) / (CLOCKS_PER_SEC / 1000);
                cout << "Operacja zajela: " << time_elapsed << " milisekund." << endl;
                cout << endl;
                system("pause");
            }                                
                break;
            case 9:                             
                L1->sortList();
                cout << "Podaj znak: ";
                cin >> data;               
                L1->sortedInsert(L1->head, data);
                break; 
            case 10:
            {               
                L1->~Lista();
            }
            break;
            case 11:
            {
                cout << "Ile elementow dodac do listy: ";
                cin >> n;
                clock_t t1 = clock();
                for (int i = 0; i < n; i++)        //Dodawanie do listy
                {           
                    L1->push_back('a' + rand() % 26);
                }
                clock_t t2 = clock();
                double time_elapsed = double(t2 - t1) / (CLOCKS_PER_SEC / 1000);
                cout << "Operacja zajela: " << time_elapsed << " milisekund." << endl;
                cout << endl;
                system("pause");
            }
            break;
            case 12:
            {
                cout << "Podaj ilosc prob wyszukania : ";
                cin >> n;
                clock_t t1 = clock();
                for (int i = 0; i < n; i++)        //Wyszukiwanie i usuwanie
                {
                    L1->SearchAndDelete(rand() % 10000 + 1);
                }
                clock_t t2 = clock();
                double time_elapsed = double(t2 - t1) / CLOCKS_PER_SEC;
                cout << "Operacja zajela: " << time_elapsed << " sekund." << endl;
                cout << endl;
                system("pause");
            }
            break;           
            }
        }
        delete L1;
    }

    else if (data_type == "int")
    {
        int data;
        Lista<int>* L1 = new Lista<int>;       
        cout << endl;
        for (;;)
        {
            system("cls");
            L1->ShowList();
            cout << endl << endl;
            cout << "-------------------------------------------------------------------------------\n" << endl;
            cout << "1. Dodaj element na koniec listy. \n";
            cout << "2. Dodaj element na poczatek listy. \n";
            cout << "3. Usun ostatni element. \n";
            cout << "4. Usun pierwszy element. \n";
            cout << "5. Wyswietl element o podanym indeksie. \n";
            cout << "6. Podmien dane. \n";
            cout << "7. Wyszukaj element \n";
            cout << "8. Wyszukaj i usun element \n";
            cout << "9. Dodaj element z wymuszeniem porzadku \n";
            cout << "10. Usun wszystkie elementy. \n";
            cout << "11. Dodaj 'n' elementow \n";
            cout << "12. Wyszukaj i usun element 'n' razy \n";

            cin >> wybor;
            
            switch (wybor)
            {
            case 1:
                cout << "Wpisz liczbe jaka chcesz dodac: ";
                cin >> data;
                L1->push_back(data);
                break;
            case 2:
                cout << "Wpisz liczbe jaka chcesz dodac: ";
                cin >> data;
                L1->push_front(data);
                break;
            case 3:
                L1->PopBack();
                break;
            case 4:
                L1->PopFront();
                break;
            case 5:
            {
                cout << "Podaj numer indeksu: ";
                cin >> index;
                clock_t t1 = clock();
                L1->ShowListElement(index);
                clock_t t2 = clock();
                double time_elapsed = double(t2 - t1) / (CLOCKS_PER_SEC / 1000);
                cout << "Operacja zajela: " << time_elapsed << " milisekund." << endl;
                cout << endl;
                system("pause");
            }
            break;
            case 6:
                cout << "Podaj numer indeksu: ";
                cin >> index;
                if (index >= L1->size) {
                    cout << "Nie istnieje element o podanym indeksie \n";
                    system("pause");
                }
                else
                {
                    cout << "Podaj wartosc liczby: ";
                    cin >> data;
                    L1->ReplacementElement(index, data) ? cout << "Element zostal podmieniony\n" : cout << "Nie ma elementu o takim indeksie \n";
                }
                break;
            case 7:
            {
                cout << "Podaj wartosc liczby: ";
                cin >> data;
                clock_t t1 = clock();
                L1->Search(data);
                clock_t t2 = clock();
                double time_elapsed = double(t2 - t1) / (CLOCKS_PER_SEC / 1000);
                cout << "Operacja zajela: " << time_elapsed << " milisekund." << endl;
                cout << endl;
                system("pause");
            }
            break;
            case 8:
            {
                cout << "Podaj wartosc liczby: ";
                cin >> data;
                clock_t t1 = clock();
                L1->SearchAndDelete(data) ? cout << "Element o podanej wartosci zostal usuniety z listy \n" : cout << "Nie ma takich elementow na liscie \n";
                clock_t t2 = clock();
                double time_elapsed = double(t2 - t1) / (CLOCKS_PER_SEC / 1000);
                cout << "Operacja zajela: " << time_elapsed << " milisekund." << endl;
                cout << endl;
                system("pause");
            }
            break;
            case 9:                
                L1->sortList();               
                cout << "Podaj wartosc liczby: ";
                cin >> data;
                L1->sortedInsert(L1->head, data);
                break;
            case 10:
            {
                L1->~Lista();
            }
            break;
            case 11:
            {
                cout << "Ile elementow dodac do listy: ";
                cin >> n;
                clock_t t1 = clock();
                for (int i = 0; i < n; i++)        //Dodawanie do listy
                {
                    L1->push_back(rand() % 10000 + 1);
                }
                clock_t t2 = clock();
                double time_elapsed = double(t2 - t1) / (CLOCKS_PER_SEC / 1000);
                cout << "Operacja zajela: " << time_elapsed << " milisekund." << endl;
                cout << endl;
                system("pause");
            }
            break;
            case 12:
            {
                cout << "Podaj ilosc prob wyszukania : ";
                cin >> n;
                clock_t t1 = clock();
                for (int i = 0; i < n; i++)        //Wyszukiwanie i usuwanie
                {
                    L1->SearchAndDelete(rand() % 10000 + 1);
                }
                clock_t t2 = clock();
                double time_elapsed = double(t2 - t1) / CLOCKS_PER_SEC;
                cout << "Operacja zajela: " << time_elapsed << " sekund." << endl;
                cout << endl;
                system("pause");
            }
            break;
            }
        }
        delete L1;
    }        
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
