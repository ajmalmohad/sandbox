#include <iostream>
using namespace std;

struct node
{
    string key;
    string value;
};

const int capacity = 10;
struct node hash_table[capacity];

int hasher(string str)
{
    int value = 0;
    for (int i = 0; i < str.size(); i++)
        value += (int)str[i];
    return value % capacity;
}

int check(string key)
{
    if (key == "none")
    {
        cout << "none is reserved key\n";
        return 0;
    }
    int hashed = hasher(key);
    int current = hashed;

    if (hash_table[current].key == "")
    {
        cout << "Not Found \n";
        return 0;
    }

    while (hash_table[current].key != key)
    {
        current = (current + 1) % capacity;
        if (hash_table[current].key == key)
        {
            cout << "Found Key Values! \n";
            return 1;
        }
        if (current == hashed || hash_table[current].key == "")
        {
            cout << "Not Found \n";
            return 0;
        }
    }
    cout << "Found Key Values! \n";
    return 1;
}

void add(string key, string value)
{
    if (key == "none")
    {
        cout << "none is reserved key\n";
        return;
    }
    int hashed = hasher(key);
    int current = hashed;
    while (hash_table[current].key != "")
    {
        if (hash_table[current].key == key)
        {
            hash_table[current].value = value;
            cout << "Added Duplicate Key! \n";
            return;
        }
        if (hash_table[current].key == "none")
        {
            if (!check(key))
            {
                hash_table[current].key = key;
                hash_table[current].value = value;
                cout << "Added Successfully in None! \n";
                return;
            }
        }
        current = (current + 1) % capacity;
        if (current == hashed)
        {
            cout << "No space \n";
            return;
        }
    }
    hash_table[current].key = key;
    hash_table[current].value = value;
    cout << "Added Successfully! \n";
}

void get(string key)
{
    if (key == "none")
    {
        cout << "none is reserved key\n";
        return;
    }
    int hashed = hasher(key);
    int current = hashed;

    if (hash_table[current].key == "")
    {
        cout << "Not Found \n";
        return;
    }

    while (hash_table[current].key != key)
    {
        current = (current + 1) % capacity;
        if (hash_table[current].key == key)
        {
            cout << "Found: " << hash_table[current].key << ":" << hash_table[current].value << "\n";
            return;
        }
        if (current == hashed || hash_table[current].key == "")
        {
            cout << "Not Found \n";
            return;
        }
    }
    cout << "Found: " << hash_table[current].key << ":" << hash_table[current].value << "\n";
}

void delete_key(string key)
{
    if (key == "none")
    {
        cout << "none is reserved key\n";
        return;
    }
    int hashed = hasher(key);
    int current = hashed;

    if (hash_table[current].key == "")
    {
        cout << "Not Found \n";
        return;
    }

    while (hash_table[current].key != key)
    {
        current = (current + 1) % capacity;
        if (hash_table[current].key == key)
        {
            hash_table[current].key = "none";
            hash_table[current].value = "none";
            cout << "Deleted Key Values! \n";
            return;
        }
        if (current == hashed || hash_table[current].key == "")
        {
            cout << "Not Found \n";
            return;
        }
    }
    hash_table[current].key = "none";
    hash_table[current].value = "none";
    cout << "Deleted Key Values! \n";
}

void display()
{
    int i = 0;
    cout << "\n";
    for (node current : hash_table)
    {
        cout << i++ << " " << current.key << " " << current.value << '\n';
    }
    cout << "\n";
}

int main()
{
    int option;
    string key, value;
    do
    {
        cout << "\n1. Add\n2. Check\n3. Get\n4. Delete\n5. Display\n6. Exit \n";
        cout << "Enter your Choice: ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter Key and Value :";
            cin >> key >> value;
            add(key, value);
            break;
        case 2:
            cout << "Enter Key to Check :";
            cin >> key;
            check(key);
            break;
        case 3:
            cout << "Enter Key to Get :";
            cin >> key;
            get(key);
            break;
        case 4:
            cout << "Enter Key to Delete :";
            cin >> key;
            delete_key(key);
            break;
        case 5:
            display();
            break;
        default:
            break;
        }
    } while (option != 6);
}