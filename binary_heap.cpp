#include "dynamic_array.cpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
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
        size = 10;
        array = new T[10];
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


using namespace std;
template <class T>
class binary_heap
{
public:
    int n = 0;
   
    void add_node(T data, T T[])
    {      
        int i, j;                      
        i = n++;                                     
        j = (i - 1) / 2;               

        T[i] = data;
        while (i > 0 && T[j] < data)  
        {                                                           
            T[i] = T[j];              
            T[j] = data;
            i = j;                                            
            j = (i - 1) / 2;          
        }            
    }
    
    void remove_root(T array[])
    {
        int i, j, e;

        int root = array[0];

        if (n)                        
        {
            n--;                                            
            e = array[n];             

            i = 0;                    
            j = 1;                    

            while (j < n)             
            {
                if ((j + 1 < n) && (array[j] < array[j + 1]))
                {
                    j++;              
                }
                if (e >= array[j])    
                {
                    break;
                }
                array[i] = array[j];  
                i = j;                
                j = 2 * j + 1;        
            }

            array[i] = e;
        }
        
        cout << "root = " << root;
       
    }

    void show_heap(int array[])
    {
        cout << endl << "number of elements = " << n << endl;

        cout << "\nbinary_heap: \n";

        for (int i = 0; i < n; i++)
        {
            cout << i << " ";
            cout << array[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    Dynamic_array<int>* da = new Dynamic_array<int>;  
    binary_heap<int> kopiec;

    int i, v;
    srand(time(NULL));
    
    //kopiec.count_a = da->count;
    // kopiec.size_a = da->size;

    //cout << "\narray size = " << kopiec.size_a;
    //cout << "\nnumber of elements = " << kopiec.count_a;
    //cout << endl;

    kopiec.add_node(1, da->array);
    kopiec.add_node(2, da->array);
    kopiec.add_node(3, da->array);

    kopiec.show_heap(da->array);

    kopiec.remove_root(da->array);
    kopiec.show_heap(da->array);

    kopiec.add_node(4, da->array);
    kopiec.add_node(5, da->array);
    kopiec.add_node(6, da->array);
    kopiec.add_node(7, da->array);
    kopiec.add_node(8, da->array);
    kopiec.add_node(9, da->array);
    kopiec.add_node(10, da->array);
    kopiec.add_node(11, da->array);
    kopiec.add_node(12, da->array);
    kopiec.add_node(13, da->array);
    //kopiec.add_node(13, da->array);
    
    

    //kopiec.add_node(2, da->array);
    //kopiec.add_node(3, da->array);
 
    //for (i = 0; i < 15; i++)
    //{ 
    //    //v = (rand() % 10);
    //    //cout << v << " ";
    //    //cout << T[i] << " ";
    //    kopiec.add_node(rand() % 10, da->array);
    //}


    kopiec.show_heap(da->array);
    cout << endl;
    //cout << "\nArray size = " << kopiec.size_a;
    //cout << "\nno elements = " << kopiec.count_a;
    

    //cout << endl;
    //cout << "el n. 10 = " << da->array[10];
    //cout << endl;

    //cout << endl;
    for (int i = 0; i < kopiec.n; i++)
    {
        cout << da->array[i] << " ";
    }

    //cout << endl;
    //for (i = 0; i < 10; i++)
    //{
    //    //v = (rand() % 10);
    //    cout << i << " ";
    //    //heap_push(v);
    //}

    cout << endl << endl;
    kopiec.remove_root(da->array);
    //for (i = 0; i < n; i++)
    //{
    //    //v = (rand() % 10);
    //    //cout << v << " ";
    //    cout << da->array[i] << " ";
    //    //heap_push(i);
    //}
    cout << endl;

    kopiec.show_heap(da->array);


    //for (i = 0; i < 10; i++)
    //{
    //    //v = (rand() % 10);
    //    cout << i << " ";
    //    //heap_push(v);
    //}

    cout << endl << endl;

    // Rozbieramy kopiec

    // REMOVE ALL
    da->remove_all();
    //for (i = 0; i < n; i++)
    //{
    //    //v = (rand() % 10);
    //    //cout << v << " ";
    //    cout << da->array[i] << " ";
    //    //heap_push(i);
    //}
    /*while (n)
    {
        cout << setw(4) << T[0];
        heap_pop();
    }*/

    cout << endl << endl;

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
