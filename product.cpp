cpp
#include<iostream>
#include<string>
using namespace std;

struct Product
{
    int id;
    float price;
    string name;
    int quantity;
    Product* next;
};

Product* head = NULL;

const int SIZE = 10;

struct HashNode
{
    int id;
    Product* product;
    HashNode* next;
};

HashNode* hashTable[SIZE] = {NULL};

int hashFunction(int id)
{
    return id % SIZE;
}

Product* searchProduct(int id)
{
    int index = hashFunction(id);
    HashNode* temp = hashTable[index];

    while(temp != NULL)
    {
        if(temp->id == id)
            return temp->product;

        temp = temp->next;
    }

    return NULL;
}

void addproduct()
{
    Product* newProduct = new Product;

    cout<<"Enter Product ID: ";
    cin>>newProduct->id;

    if(searchProduct(newProduct->id) != NULL)
    {
        cout<<"Product ID already exists!\n";
        delete newProduct;
        return;
    }

    cout<<"Enter product name: ";
    cin.ignore();
    getline(cin, newProduct->name);

    cout<<"Enter Product price: ";
    cin>>newProduct->price;

    cout<<"Enter Quantity: ";
    cin>>newProduct->quantity;

    newProduct->next = head;
    head = newProduct;

    int index = hashFunction(newProduct->id);

    HashNode* newNode = new HashNode;

    newNode->id = newProduct->id;
    newNode->product = newProduct;
    newNode->next = hashTable[index];

    hashTable[index] = newNode;

    cout<<"Product added successfully!\n";
}

void updateProduct()
{
    int id;

    cout<<"Enter product ID: ";
    cin>>id;

    Product* temp = searchProduct(id);

    if(temp == NULL)
    {
        cout<<"Product not found!\n";
        return;
    }

    cout<<"Enter new product name: ";
    cin.ignore();
    getline(cin, temp->name);

    cout<<"Enter new price: ";
    cin>>temp->price;

    cout<<"Enter new quantity: ";
    cin>>temp->quantity;

    cout<<"Product updated successfully!\n";
}

void displayProducts()
{
    Product* temp = head;

    if(temp == NULL)
    {
        cout<<"No products available!\n";
        return;
    }

    cout<<"\n======== Product Catalog ======\n";

    while(temp != NULL)
    {
        cout<<"\nProduct ID: "<<temp->id;
        cout<<"\nProduct Name: "<<temp->name;
        cout<<"\nPrice: "<<temp->price;
        cout<<"\nQuantity: "<<temp->quantity;
        cout<<"\n------------------\n";

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout<<"\n==== E-COMMERCE PRODUCT CATALOG ===\n";
        cout<<"1. Add product\n";
        cout<<"2. Update product\n";
        cout<<"3. Display all products\n";
        cout<<"4. Search product\n";
        cout<<"5. Exit\n";

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                addproduct();
                break;

            case 2:
                updateProduct();
                break;

            case 3:
                displayProducts();
                break;

            case 4:
            {
                int id;

                cout<<"Enter product ID: ";
                cin>>id;

                Product* p = searchProduct(id);

                if(p != NULL)
                {
                    cout<<"\nProduct Found!";
                    cout<<"\nID: "<<p->id;
                    cout<<"\nName: "<<p->name;
                    cout<<"\nPrice: "<<p->price;
                    cout<<"\nQuantity: "<<p->quantity<<endl;
                }
                else
                {
                    cout<<"Product not found!\n";
                }

                break;
            }

            case 5:
                cout<<"Exiting Program\n";
                break;

            default:
                cout<<"Invalid choice!\n";
        }

    }
    while(choice != 5);

    return 0;
}
