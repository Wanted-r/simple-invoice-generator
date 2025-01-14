#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct item {
    string nam;
    int quan{};
    int price{};
};

struct customer {
    string name;
    vector<item> items;
};

int main() {
    int a;
    customer c;
    cout << "Enter your name: ";
    cin >> c.name;
    cout << "Enter Number of items: ";
    cin >> a;

    for (int i = 0; i < a; i++) {
        item temp;
        cout << "Enter Name of item= ";
        cin >> temp.nam;


        do {
            cout << "Enter Quantity of Items= ";
            cin >> temp.quan;
            if (temp.quan <= 0) {
                cout << "Error! Quantity must be greater than zero. Please re-enter." << endl;
            }
        } while (temp.quan <= 0);

        do {
            cout << "Enter Price of Item= ";
            cin >> temp.price;
            if (temp.price <= 0) {
                cout << "Error! Price must be greater than zero. Please re-enter." << endl;
            }
        } while (temp.price <= 0);
        c.items.push_back(temp);
    }

    cout << "\nInvoice for " << c.name << ":\n";
    cout << left << setw(20) << "Item Name"
        << setw(10) << "Quantity"
        << setw(10) << "Price"
        << setw(10) << "Total" << endl;

    int grandTotal = 0;
    for (int i = 0; i < c.items.size(); i++) {
        int total = c.items[i].quan * c.items[i].price;
        grandTotal += total;
        cout << left << setw(20) << c.items[i].nam
            << setw(10) << c.items[i].quan
            << setw(10) << c.items[i].price
            << setw(10) << total << endl;
    }
    cout << "--------------------------------------\n";
    cout << "Grand Total: " << grandTotal << endl;
    return 0;
}
