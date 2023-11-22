#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cstdlib>

using namespace std;

struct Item
{
    int itemCode;
    string itemName;
    string companyName;
    int numberOfItems;
    float price_unit;
    float total_price;
};

class StockPortfolio
{
private:
    struct StockArea
    {
        string label;
        stack<Item> items;
    };
    vector<StockArea> stockAreas;

public:
    void createNewStack(const string &stackLabel)
    {
        StockArea newArea;
        newArea.label = stackLabel;
        stockAreas.push_back(newArea);
        cout << "New stack created with label: " << stackLabel << endl;
    }

    void addSecurities(const string &stackLabel, int code, const string &name, const string &company, int count, float price)
    {
        for (int i = 0; i < stockAreas.size(); ++i)
        {
            if (stockAreas[i].label == stackLabel)
            {
                Item newItem;
                newItem.itemCode = code;
                newItem.itemName = name;
                newItem.companyName = company;
                newItem.numberOfItems = count;
                newItem.price_unit = price;
                newItem.total_price = count * price;

                stockAreas[i].items.push(newItem);
                cout << "Item added to stack: " << stackLabel << " successfully." << endl;
                return;
            }
        }
        cout << "No stack available with label: " << stackLabel << ". Create a new stack first." << endl;
    }

    void displaySecurities(const string &stackLabel)
    {
        for (int i = 0; i < stockAreas.size(); ++i)
        {
            if (stockAreas[i].label == stackLabel)
            {
                stack<Item> tempStack = stockAreas[i].items;
                if (tempStack.empty())
                {
                    cout << "No items in the stack: " << stackLabel << endl;
                }
                else
                {
                    cout << "Item Code--------|--------Item Name--------|--------Company--------|--------No. of Items--------|--------Price per unit--------|--------Total Amount of Stock" << endl;
                    while (!tempStack.empty())
                    {
                        Item item = tempStack.top();
                        tempStack.pop();
                        cout << item.itemCode << "--------------|--------" << item.itemName << "--------|--------" << item.companyName << "--------|--------" << item.numberOfItems << "--------|--------" << item.price_unit << "--------|--------" << item.total_price << endl;
                    }
                }
                return;
            }
        }
        cout << "No stack available with label: " << stackLabel << endl;
    }

    void checkSpecificSecurities(const string &stackLabel, int code)
    {
        for (int i = 0; i < stockAreas.size(); ++i)
        {
            if (stockAreas[i].label == stackLabel)
            {
                stack<Item> tempStack = stockAreas[i].items;
                bool found = false;
                while (!tempStack.empty())
                {
                    Item item = tempStack.top();
                    tempStack.pop();
                    if (item.itemCode == code)
                    {
                        cout << "Item found in stack: " << stackLabel << endl;
                        cout << "Item Code: " << item.itemCode << ", Item Name: " << item.itemName << ", Company: " << item.companyName << ", No. of Items: " << item.numberOfItems << ", Price per unit: " << item.price_unit << ", Total Amount of Stock: " << item.total_price << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Item not found in stack: " << stackLabel << endl;
                }
                return;
            }
        }
        cout << "No stack available with label: " << stackLabel << endl;
    }

    void updateSecurities(const string &stackLabel, int code)
    {
        for (int i = 0; i < stockAreas.size(); ++i)
        {
            if (stockAreas[i].label == stackLabel)
            {
                stack<Item> &tempStack = stockAreas[i].items;
                stack<Item> updatedStack;
                bool found = false;

                while (!tempStack.empty())
                {
                    Item item = tempStack.top();
                    tempStack.pop();
                    if (item.itemCode == code)
                    {
                        cout << "Enter new details for the item:" << endl;
                        int newCount;
                        float newPrice;
                        cout << "Enter updated Number of Units: ";
                        cin >> newCount;
                        cout << "Enter updated Price per unit: ";
                        cin >> newPrice;

                        item.numberOfItems = newCount;
                        item.price_unit = newPrice;
                        item.total_price = newCount * newPrice;

                        updatedStack.push(item);
                        found = true;
                    }
                    else
                    {
                        updatedStack.push(item);
                    }
                }
                while (!updatedStack.empty())
                {
                    tempStack.push(updatedStack.top());
                    updatedStack.pop();
                }

                if (found)
                {
                    cout << "Item updated successfully in stack: " << stackLabel << endl;
                }
                else
                {
                    cout << "Item not found in stack: " << stackLabel << endl;
                }
                return;
            }
        }
        cout << "No stack available with label: " << stackLabel << endl;
    }

    void sellSecurities(const string &stackLabel, int code)
    {
        for (int i = 0; i < stockAreas.size(); ++i)
        {
            if (stockAreas[i].label == stackLabel)
            {
                stack<Item> &tempStack = stockAreas[i].items;
                stack<Item> updatedStack;
                bool found = false;

                while (!tempStack.empty())
                {
                    Item item = tempStack.top();
                    tempStack.pop();
                    if (item.itemCode == code)
                    {
                        found = true;
                        cout << "Item sold from stack: " << stackLabel << endl;
                    }
                    else
                    {
                        updatedStack.push(item);
                    }
                }

                while (!updatedStack.empty())
                {
                    tempStack.push(updatedStack.top());
                    updatedStack.pop();
                }

                if (!found)
                {
                    cout << "Item not found in stack: " << stackLabel << endl;
                }
                return;
            }
        }
        cout << "No stack available with label: " << stackLabel << endl;
    }
};

int main()
{
    system("color 0A");

    StockPortfolio portfolio;

    while (true)
    {
        cout << "\n1. Create New Stack (Area of Stock)" << endl;
        cout << "2. Add Securities" << endl;
        cout << "3. Display Securities" << endl;
        cout << "4. Check Specific Securities" << endl;
        cout << "5. Update Securities" << endl;
        cout << "6. Sell Securities" << endl;
        cout << "7. Exit" << endl;

        int choice;
        cout << "\nYour Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string stackLabel;
            cout << "Name the Area of stock (e.g Hydro Sector, Finance Sector, etc): ";
            cin >> stackLabel;
            portfolio.createNewStack(stackLabel);
            break;
        }
        case 2:
        {
            string stackLabel;
            cout << "Enter the Area of Stock (e.g Hydro Sector, Finance Sector, etc): ";
            cin >> stackLabel;
            int code, count;
            float price;
            string name, company;
            cout << "Enter Item Code: ";
            cin >> code;
            cout << "Enter Item Name: ";
            cin >> name;
            cout << "Enter Company Name: ";
            cin >> company;
            cout << "Enter Number of Units: ";
            cin >> count;
            cout << "Enter Current value: ";
            cin >> price;
            portfolio.addSecurities(stackLabel, code, name, company, count, price);
            break;
        }
        case 3:
        {
            string stackLabel;
            cout << "Enter the label of the stack to display items: ";
            cin >> stackLabel;
            portfolio.displaySecurities(stackLabel);
            break;
        }
        case 4:
        {
            string stackLabel;
            cout << "Enter the label of the stack to check specific securities: ";
            cin >> stackLabel;
            int code;
            cout << "Enter Item Code to Check: ";
            cin >> code;
            portfolio.checkSpecificSecurities(stackLabel, code);
            break;
        }
        case 5:
        {
            string stackLabel;
            cout << "Enter the label of the stack to update securities: ";
            cin >> stackLabel;
            int code;
            cout << "Enter Item Code to Update: ";
            cin >> code;
            portfolio.updateSecurities(stackLabel, code);
            break;
        }
        case 6:
        {
            string stackLabel;
            cout << "Enter the label of the stack to sell securities: ";
            cin >> stackLabel;
            int code;
            cout << "Enter Item Code to Sell: ";
            cin >> code;
            portfolio.sellSecurities(stackLabel, code);
            break;
        }
        case 7:
            exit(0);
        default:
            cout << "Invalid Value. Please try again." << endl;
        }
    }

    return 0;
}
