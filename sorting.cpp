// Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

template <class T>
class element
{
public:
    string name;
    T key;
};

void heap_sort(int tab[], const int N)
{
    int i, j, k, l, x;

    int* array = new int[N + 1];
    array[0] = 0;

    for (i = 1; i <= N; i++)
    {
        array[i] = tab[i - 1];
    }

    for (i = 2; i <= N; i++)
    {
        j = i;
        k = j / 2;
        x = array[i];
        while ((array[k] < x) && (k > 0))
        {
            array[j] = array[k];
            j = k;
            k = j / 2;
        }
        array[j] = x;
    }

    //cout << "\n----------------------------------------------";
    // cout << "\n\nHeap-sort:\n\n";

    for (int i = 1; i <= 10; i++)
    {
        cout << array[i] << " ";
    }

    for (i = N; i > 1; i--)
    {
        swap(array[1], array[i]);
        j = 1; k = 2;
        while (k < i)
        {
            if ((k + 1 < i) && (array[k + 1] > array[k]))
                l = k + 1;
            else
                l = k;
            if (array[l] <= array[j]) break;
            swap(array[j], array[l]);
            j = l; k = j + j;
        }
    }
    cout << endl << endl;

    for (int i = 1; i <= 10; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;

    delete[] array;
}

/*void heap_sort(int* array, int array_size)
{
    void create_heap(int* array, int array_size);
    //void unfold_heap
}*/

void counting_sort(int* a, int n, int m)  
{                                           
    int* counts = new int[n];      

    for (int i = 0; i < m; i++)
    {
        counts[i] = 0;
    }

    for (int i = 0; i < n; i++)  
    {
        counts[a[i]]++;                                    
    }                           

    int k = 0;
    for (int i = 0; i < m; i++)               
    {
        for (int j = 0; j < counts[i]; j++)   
        {
            a[k++] = i;                       
        }
    }

    delete[] counts;
}

template <class T>
T* counting_sort_objects(T* a, int n, int m)
{
    int* counts = new int[m];

    for (int i = 0; i < m; i++)
    {
        counts[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        counts[a[i].key]++;
    }

    for (int i = 1; i < m; i++)
    {
        counts[i] = counts[i - 1] + counts[i];
    }

    T* out = new T[n];

    for (int i = n - 1; i >= 0; i--)
    {
        out[--counts[a[i].key]] = a[i];  
    }

    delete[] counts;

    return out;
}

void bucket_sort(int N, int WMIN, int WMAX, int lw[], int tab[])
{
    for (int i = WMIN; i <= WMAX; i++)
    {
        lw[i - WMIN] = 0;             
    }

    for (int i = 0; i < N; i++)      
    {
        lw[tab[i] - WMIN]++;            
    }   

    int j = 0;

    for (int i = WMIN; i <= WMAX; i++)
    {
        while (lw[i - WMIN] > 0)        
        {
            tab[j] = i;
            lw[i - WMIN]--;
            j++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << tab[i] << " ";
    }

    return;
}

int main()
{
    srand(time(NULL));
    element<int>* tab = new element<int>[5];

    tab[0].name = { "Robert" };
    //tab[0].key = { 8 };

    tab[1].name = { "Adam" };
    //tab[1].key = { 1 };

    tab[2].name = { "Kamil" };
    //tab[2].key = { 2 };

    tab[3].name = { "Zbigniew" };
    //tab[3].key = { 13 };

    tab[4].name = { "Grzegorz" };
    //tab[4].key = { 1 };

    for (int i = 0; i < 5; i++)
    {
        tab[i].key = ((rand() << 15) + rand()) % 10;
    }

    //const int n = 8; 

    int m = 6;
    int b = 0;
    int a[10];

    for (int i = 0; i < 10; i++)
    {
        b = ((rand() << 15) + rand()) % m;
        a[i] = b;
    }

    size_t a_size = sizeof(a) / sizeof(a[0]); // rozmiar tablicy


    //cout << endl << b << endl;


    cout << "\n----------------------------------------------\n";
    cout << "\nCounting-sort:\n\n";
    //cout << "\nPrzed posortowaniem: \n";
    for (int i = 0; i < a_size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << endl;

    //cout << "\n\nPo posortowaniu: \n";

    clock_t t1 = clock();
    counting_sort(a, a_size, 6);
    clock_t t2 = clock();
    double time_elapsed = double(t2 - t1) / (CLOCKS_PER_SEC / 1000);

    for (int i = 0; i < a_size; i++)
    {
        cout << a[i] << " ";
    }

    cout << "\n\nOperacja zajela: " << time_elapsed << " milisekund.";

    cout << endl;
    cout << "\n----------------------------------------------\n";
    cout << "\nCounting-sort (objects):\n\n";

    for (int i = 0; i < 5; i++)
    {
        cout << tab[i].name << " ";
        cout << tab[i].key;
        if (i != 4) cout << ", ";
    }

    cout << endl << endl;

    clock_t t3 = clock();
    tab = counting_sort_objects(tab, 5, 14);
    clock_t t4 = clock();
    double time_elapsed1 = double(t4 - t3) / (CLOCKS_PER_SEC / 1000);

    for (int i = 0; i < 5; i++)
    {
        cout << tab[i].name << " ";
        cout << tab[i].key;
        if (i != 4) cout << ", ";
    }
    cout << "\n\nOperacja zajela: " << time_elapsed1 << " milisekund.";

    //const int N = 3; // liczba elementów
    //int d[N + 1], i, j, k, m, x;

        //const int N = 3;
        //int tab[N+1] = {1,2,3 };
        //int tab1[3] = {5,5,4};
    //int tab1[10] = {10,9,8,5,6,7,4,1,3,2};
        //const size_t N = sizeof(tab) / sizeof(tab[0]);
    //size_t array_size1 = sizeof(tab1) / sizeof(tab1[0]);

    cout << endl;
    clock_t t5 = clock();
    heap_sort(a, a_size);
    clock_t t6 = clock();
    double time_elapsed2 = double(t6 - t5) / (CLOCKS_PER_SEC / 1000);
    cout << "\nOperacja zajela: " << time_elapsed2 << " milisekund.\n";

    cout << "\n----------------------------------------------";
    cout << "\n\nBucket-sort:\n\n";

    const int WMIN = -10; // najmniejsza wartość ze z.w.
    const int WMAX = 10;  // największa wartość ze z.w.
    //size_t a_size = sizeof(a) / sizeof(a[0]);
    const int N = 10;
    int d[N], lw[WMAX - WMIN + 1], i, j;   //  Liczba liczników: wmax - wmin + 1 (21)
                                           //  lw - tablica liczników wartości o indeksach od wmin do wmax. Każdy licznik przechowuje liczbę całkowitą

    for (int i = 0; i < N; i++)
    {
        d[i] = WMIN + rand() % (WMAX - WMIN + 1);
    }


    // wyświetlamy zawartość zbioru przed sortowaniem


    for (i = 0; i < N; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl << endl;

    clock_t t7 = clock();
    bucket_sort(10, -10, 10, lw, d);
    clock_t t8 = clock();
    double time_elapsed3 = double(t8 - t7) / (CLOCKS_PER_SEC / 1000);
    cout << "\n\nOperacja zajela: " << time_elapsed3 << " milisekund.";


    cout << endl;

    clock_t t9 = clock();
    heap_sort(d, 10);
    clock_t t10 = clock();
    double time_elapsed4 = double(t10 - t9) / (CLOCKS_PER_SEC / 1000);
    cout << "\n\nOperacja zajela: " << time_elapsed4 << " milisekund.\n";

    //array_size--;
    //int* array = &tab[3];

    //tab = { 1,2,3 };

    /*
    cout << "\nPrzed stworzeniem kopca: \n";
    for (int i = 1; i <= N; i++)
    {
        cout << array[i] << " ";
    }

    //heap_sort(array, array_size);
    //create_heap(tab, array_size

    for (int i = 0; i <= N; i++)
    {
        int j, k, x;
        j = i; k = j / 2;
        x = array[i];
        while ((k > 0) && (array[k] < x))
        {
            array[j] = array[k];
            j = k; k = j / 2;
        }
        array[j] = x;
    }
    cout << "\nPo ...: \n";
    for (int i = 1; i <=N; i++)
    {
        cout << array[i] << " ";
    }
    /*
    d[1] = 3;
    d[2] = 1;
    d[3] = 2;

    for (i = 1; i <= N; i++) cout << setw(2) << d[i];
    cout << endl << endl;
    x = (N + 1) / 2; k = 2;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j < x; j++) cout << " ";
        cout << d[i];
        for (j = 1; j <= x; j++) cout << " ";
        if (i + 1 == k)
        {
            k += k; x /= 2; cout << endl;
        }
    }

    // Rozbieramy kopiec

    for (i = N; i > 1; i--)
    {
        swap(d[1], d[i]);
        j = 1; k = 2;
        while (k < i)
        {
            if ((k + 1 < i) && (d[k + 1] > d[k]))
                m = k + 1;
            else
                m = k;
            if (d[m] <= d[j]) break;
            swap(d[j], d[m]);
            j = m; k = j + j;
        }
    }

    cout << endl << "Zbior wyjsciowy po rozbiorze kopca:\n\n";

    for (i = 1; i <= N; i++) cout << setw(2) << d[i];
    cout << endl << endl;*/

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
