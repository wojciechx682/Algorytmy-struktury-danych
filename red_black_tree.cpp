#include <iostream>
#include <time.h>

using namespace std;

int index = 0;
//int i = 1;
int C = 1;

template <class T>
class Node  
{           
public:
    Node* parent;
    Node* left;
    Node* right;
    T data;
    int index;
    bool color;
};

template <class T>
class RBT
{
public:
    Node<T>* root;   
    Node<T>* TNULL; 
    int size = 0;

    RBT() 
    {
        TNULL = new Node<T>;
        TNULL->color = 0;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
        size = 0;
    }

    Node<T>* find_node(T data)
    {
        Node<T>* n;

        n = root;

        while ((n != TNULL) && (n->data != data))
        {
            if (data < n->data)
            {
                n = n->left;
            }
            else if(data > n->data)
            {
                n = n->right;
            }   
            else
            {                
                return n;
            }           
        }    
        return NULL;
    }

    void add_node(T data)
    {
        Node<T>* node = new Node<T>;

        node->parent = nullptr;
        node->data = data;
        node->left = TNULL;
        node->right = TNULL;
        node->color = 1;
        node->index = index;

        Node<T>* y = nullptr;
        Node<T>* x = this->root;

        while (x != TNULL)               
        {
            y = x;                       
            if (node->data < x->data)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }

        node->parent = y;

        if (y == nullptr)
        {
            root = node;
            index++;
            size++;
        }
        else if (node->data < y->data)
        {
            y->left = node;
            index++;
            size++;
        }
        else {
            y->right = node;
            index++;
            size++;
        }

        if (node->parent == nullptr) {
            node->color = 0;
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        add_fix(node);
    }

    void add_fix(Node<T>* n)
    {       
        Node<T>* u;
      
        while (n->parent->color == 1)                     
        {
            if (n->parent == n->parent->parent->left) 
            {
                u = n->parent->parent->right;             

                if (u->color == 1)                       
                {
                    u->color = 0;                         
                    n->parent->color = 0;                   
                    n->parent->parent->color = 1;        
                    n = n->parent->parent;                
                }
                else if (u->color == 0)                   
                {
                    if (n == n->parent->right)               
                    {
                        n = n->parent;                     
                        left_rotate(n);                    
                    }
                    n->parent->color = 0;                
                    n->parent->parent->color = 1;         
                    right_rotate(n->parent->parent);       
                }
            }
           
            else if (n->parent == n->parent->parent->right)     
            {
                u = n->parent->parent->left;               
                if (u->color == 1)                         
                {
                    u->color = 0;                         
                    n->parent->color = 0;                  
                    n->parent->parent->color = 1;          
                    n = n->parent->parent;                 
                }
                else if (u->color == 0)                     
                {
                    if (n == n->parent->left)              
                    {
                        n = n->parent;
                        right_rotate(n);                    
                    }                                     
                    n->parent->color = 0;                  
                    n->parent->parent->color = 1;          
                    left_rotate(n->parent->parent);        
                }
            }
            if (n == root) {                              
                break;                                   
            }
        }
        root->color = 0;                                 
    }

    void preorder(Node<T>* node) {       
        if (node != TNULL) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(Node<T>* node) {       
        if (node != TNULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void printRBT_short(Node<T>* root)
    {
        if (C > 20)
        {
            return;
        }
        C++;      

        if (root != TNULL)
        {

            cout << "(";
            if (root->data > -1)
            {
                cout << root->index;
            }
            cout << ": [";

            if (root->color == 1)
            {
                cout << "red, ";
            }
            else cout << "black, ";

            cout << " p: ";

            if (root->parent)
            {
                cout << root->parent->index;
            }
            else cout << "NULL";

            cout << ", l: ";
            if (root->left)
            {
                if (root->left->index < 0)
                {
                    cout << "NULL";
                }
                else cout << root->left->index;
            }

            cout << ", r: ";
            if (root->right)
            {
                if (root->right->index < 0)
                {
                    cout << "NULL";
                }
                else cout << root->right->index;
            }

            cout << "], ";
            cout << "data: ";
            cout << root->data;
            cout << "), ";
            cout << endl;

            printRBT_short(root->left);
            printRBT_short(root->right);
        }
    }

    void printRBT(Node<T>* root)
    {      
        if (root != TNULL)
        {
            cout << "(";
            if (root->data > -1)
            {
                cout << root->index;
            }
            cout << ": [";

            if (root->color == 1)
            {
                cout << "red, ";
            }
            else cout << "black, ";

            cout << " p: ";

            if (root->parent)
            {
                cout << root->parent->index;
            }
            else cout << "NULL";

            cout << ", l: ";
            if (root->left)
            {
                if (root->left->index < 0)
                {
                    cout << "NULL";
                }
                else cout << root->left->index;
            }

            cout << ", r: ";
            if (root->right)
            {
                if (root->right->index < 0)
                {
                    cout << "NULL";
                }
                else cout << root->right->index;
            }

            cout << "], ";
            cout << "data: ";
            cout << root->data;
            cout << "), ";
            cout << endl;

            printRBT(root->left);
            printRBT(root->right);
        }
    }

    void left_rotate(Node<T>* x)
    {
        Node<T>* y = x->right;       
        x->right = y->left;             

        if (y->left != TNULL)       
        {
            y->left->parent = x;     
        }

        y->parent = x->parent;       

        if (x->parent == nullptr)    
        {
            this->root = y;          
        }
        else if (x == x->parent->left) 
        {
            x->parent->left = y;       
        }
        else {
            x->parent->right = y;     
        }

        y->left = x;                 
        x->parent = y;                
    }

    void right_rotate(Node<T>* x)
    {
        Node<T>* y = x->left;           
        x->left = y->right;          

        if (y->right != TNULL)       
        {
            y->right->parent = x;    
        }

        y->parent = x->parent;        

        if (x->parent == nullptr)    
        {
            this->root = y;
        }
        else if (x == x->parent->right)
        {
            x->parent->right = y;       
        }
        else                            
        {
            x->parent->left = y;       
        }

        y->right = x;                   
        x->parent = y;                 
    }

    Node<T>* getRoot() {
        return this->root;
    }

    ~RBT()
    {
        remove_RBT(root);      
    }

    void remove_RBT(Node<T>* root)
    {
        if (root != TNULL)
        {
            remove_RBT(root->left);  
            remove_RBT(root->right); 
            delete root;               
        }
    }

    T find_max(T a, T b) {
        if (a >= b)
            return a;
        else
            return b;
    }

    T find_height(Node<T>* root) {
        if (root == NULL)
        {
            return 0;
        }
        T left_height = find_height(root->left);
        T right_height = find_height(root->right);

        return find_max(left_height, right_height) + 1;
    }
};

int main()
{
    RBT<int>* drzewo = new RBT<int>;

    srand(time(NULL));

    const int MAX_ORDER = 7;

    for (int o = 1; o <= MAX_ORDER; o++)
    {
        C = 0;
        const int n = pow(10, o); // rozmiar danych

        // dodawanie do drzewa

        clock_t t1 = clock();

        cout << "\n\nDodawanie elementow: \n";
        for (int i = 0; i < n; i++)
        {
            drzewo->add_node(rand() % 4000000);
        }

        clock_t t2 = clock();

        double time = double(t2 - t1) / (CLOCKS_PER_SEC);
        cout << "Operacja zajela: " << time << " ms" << endl;        // wypis na ekran aktualnej postaci drzewa ( skrotowej ) wraz z wysokoscia oraz pomiarow czasowych

        cout << "size: " << drzewo->size << endl;
        /* if (drzewo->size > 10)
         {
             drzewo->printRBT_short(drzewo->root);
         }
         else
         {
             drzewo->printRBT(drzewo->root);
         }*/
        drzewo->printRBT_short(drzewo->root);

        cout << "Wysokosc RBT: " << drzewo->find_height(drzewo->root) - 1 << endl;

        //wyszukiwanie

        const int m = pow(10, 2);

        int hits = 0; // liczba trafien

        clock_t t3 = clock();
        cout << "Wyszukiwanie elementow: \n";
        for (int i = 0; i < m; i++)
        {
            Node<int>* result = drzewo->find_node(rand() % 4000000);

            if (result != NULL)
            {
                hits++;
            }
        }
        clock_t t4 = clock();
        double time2 = double(t4 - t3) / (CLOCKS_PER_SEC);
        // wypis na ekran pomiarow czasowych i liczby trafien
        cout << "Operacja zajela: " << time << " ms" << endl;
        cout << "Ilosc trafien: " << hits << endl;
    }

    drzewo->remove_RBT(drzewo->root);
    delete drzewo;
    return 0;    
}