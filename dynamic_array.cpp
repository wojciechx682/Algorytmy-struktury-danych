// ALGO2 IS1 222A LAB02
// Jakub Wojciechowski
// wj46693@zut.edu.pl
// 46693.algo2.lab02.main.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.

#include <iostream>
#include <time.h>

using namespace std;

template <class T>
class Dynamic_array
{
public:
    int count; 
    int size; 
    T* array;

    Dynamic_array()
    {
        count = 0;
        size = 1;
        array = new T[1];
    }

    void add(T data) 
    {
        if (size == 0)
        {
            size = 1;
        }
        if (count == size)
        {
            increaseSize();
        }
        array[count] = data; 
        count++;    
    }

    void increaseSize()
    {
        T* temp = new T[size * 2];        

        for (int i = 0; i < size; i++)
        {
            temp[i] = array[i];
        }

        delete array;
        array = temp;
        size = size * 2;
    }

    T return_element(int index) 
    {
        if (index < 0 || index >= count)
        {
            return 0;
        }
        return array[index];
    }

    bool replace_element(int index, T data)
    {
        if (index < 0 || index >= size)
        {
            return false;
        }
        else
        {
            array[index] = data;
            return true;
        }
    }

    void remove_all()
    {
        while (size >0)
        {
            array[size-1] = NULL;                   
            
            size--;            
        }
        count = 0;           
    }

    void show_array()
    {
        cout << "Zawartosc tablicy: ";
        if (count == 0)
        {
            cout << "pusta";
        }
        else if (count < 11)
        {
            for (int i = 0; i < count; i++)
            {
                cout << array[i] << " ";
            }
        }
        else {
            for (int i = 0; i < 11; i++)
            {
                cout << array[i] << " ";
            }
        }
        cout << "\n-------------------------------------------\n";
        cout << "Aktualnty rozmiar tablicy:   " << count;
        cout << "\n-------------------------------------------";
        cout << "\nMaksymalny rozmiar tablicy:  " << size;
        cout << "\n-------------------------------------------\n\n";
    }  

    void Sortowanie()
    {
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count - 1; j++)
            {
                if (array[j] > array[j + 1])
                    swap(array[j], array[j + 1]);
            }
        }
    }
};


int main()
{
    srand(time(NULL));
    Dynamic_array<int>* da = new Dynamic_array<int>;    
    //Dynamic_array<char>* da = new Dynamic_array<char>;    
    
    const int order = 7;
    const int n = pow(10, order);

    clock_t t1 = clock();
    double max_time_per_element = 0.0;

    for (int i = 0; i < n; i++) {        
        clock_t t1_element = clock();
        da->add(rand() % 20);
        clock_t t2_element = clock();
        double time_per_element = double(t2_element - t1_element) / (CLOCKS_PER_SEC / 1000); 
       
            if (time_per_element > max_time_per_element)
            {           
                  cout << "Najgorszy czas dodawania mial miejsce przy indeksie nr: " << i << "\n";
                  // obliczenie czasu pojedynczej operacji dodawania 
            }
    }
    clock_t t2 = clock();
    double time_elapsed = double(t2 - t1) / (CLOCKS_PER_SEC / 1000);
    cout << "\nOperacja zajela: " << time_elapsed << " milisekund.\n" << endl;

    da->show_array();

    da->remove_all();

    int m = 10;

    clock_t t3 = clock();
    for (int i = 0; i < m; i++)
    {
        da->add(rand()%20); //da->add('a' + rand() % 26); <-- W przypadku dodawania charow 'a-z' do tablicy
    }
    clock_t t4 = clock();
    double time_elapsed1 = double(t4 - t3) / (CLOCKS_PER_SEC / 1000);
    cout << "Operacja zajela: " << time_elapsed1 << " milisekund." << endl;

    da->show_array();    
    
    cout << "Element o indeksie 0: \n";
    cout << da->return_element(0) << "\n\n";

    cout << "Element o indeksie 5: \n";
    cout << da->return_element(5) << "\n\n";

    cout << "Podmiana elementu o indeksie 0: \n";    
    da->replace_element(0, 233) ? cout << "Element zostal podmieniony \n\n" : cout << "Element nie zostal podmieniony \n\n";

    da->show_array();   
    
    da->remove_all();
    cout << "Po usunieciu wszystkich elementow: \n";
    da->show_array();    

    for (int i = 0; i < 5; i++)
    {
        da->add(rand() % 20 + 1);
    }
    da->show_array();

    cout << "Po posortowaniu: \n";
    da->Sortowanie();
    da->show_array();

    delete da;

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
