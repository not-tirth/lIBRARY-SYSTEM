#include <iostream>
using namespace std;

class LibraryItem
{
protected:
    int id, issued;
    string title, author, dueDate;

public:
    LibraryItem(int i, string t, string a, string d)
    {
        id = i;
        title = t;
        author = a;
        dueDate = d;
        issued = 0;
    }

    int getID()
    {
        return id;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem
{
public:
    Book(int i, string t, string a, string d)
        : LibraryItem(i, t, a, d) {}

    void checkOut()
    {
        if (issued == 0)
        {
            issued = 1;
            cout << "Book checked out successfully!\n";
        }
        else
        {
            cout << "Book is already checked out!\n";
        }
    }

    void returnItem()
    {
        if (issued == 1)
        {
            issued = 0;
            cout << "Book returned successfully!\n";
        }
        else
        {
            cout << "Book was not checked out!\n";
        }
    }

    void displayDetails()
    {
        cout << "\n--- Book ---\n";
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Due Date: " << dueDate << endl;

        if (issued == 1)
            cout << "Status: Checked Out\n";
        else
            cout << "Status: Available\n";
    }
};

class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(int i, string t, string a, string d, int dur)
        : LibraryItem(i, t, a, d)
    {
        duration = dur;
    }

    void checkOut()
    {
        if (issued == 0)
        {
            issued = 1;
            cout << "DVD checked out successfully!\n";
        }
        else
        {
            cout << "DVD is already checked out!\n";
        }
    }

    void returnItem()
    {
        if (issued == 1)
        {
            issued = 0;
            cout << "DVD returned successfully!\n";
        }
        else
        {
            cout << "DVD was not checked out!\n";
        }
    }

    void displayDetails()
    {
        cout << "\n--- DVD ---\n";
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Duration: " << duration << " minutes" << endl;

        if (issued == 1)
            cout << "Status: Checked Out\n";
        else
            cout << "Status: Available\n";
    }
};

class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(int i, string t, string a, string d, int issue)
        : LibraryItem(i, t, a, d)
    {
        issueNumber = issue;
    }

    void checkOut()
    {
        if (issued == 0)
        {
            issued = 1;
            cout << "Magazine checked out successfully!\n";
        }
        else
        {
            cout << "Magazine is already checked out!\n";
        }
    }

    void returnItem()
    {
        if (issued == 1)
        {
            issued = 0;
            cout << "Magazine returned successfully!\n";
        }
        else
        {
            cout << "Magazine was not checked out!\n";
        }
    }

    void displayDetails()
    {
        cout << "\n--- Magazine ---\n";
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Issue Number: " << issueNumber << endl;

        if (issued == 1)
            cout << "Status: Checked Out\n";
        else
            cout << "Status: Available\n";
    }
};

int main()
{
    LibraryItem* items[50];

    int count = 0;
    int choice, id;

    while (1)
    {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Check Out Item\n";
        cout << "6. Return Item\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (count >= 50)
            {
                cout << "Library is full!\n";
                break;
            }

            int i, found = 0;
            string t, a, d;

            cout << "Enter ID: ";
            cin >> i;

            for (int j = 0; j < count; j++)
            {
                if (items[j]->getID() == i)
                {
                    found = 1;
                    break;
                }
            }

            if (found == 1)
            {
                cout << "ID already exists!\n";
                break;
            }

            cout << "Enter Title: ";
            cin >> ws;
            getline(cin, t);

            cout << "Enter Author: ";
            getline(cin, a);

            cout << "Enter Due Date: ";
            cin >> d;

            items[count] = new Book(i, t, a, d);
            count++;

            cout << "Book added successfully!\n";
            break;
        }

        case 2:
        {
            if (count >= 50)
            {
                cout << "Library is full!\n";
                break;
            }

            int i, dur, found = 0;
            string t, a, d;

            cout << "Enter ID: ";
            cin >> i;

            for (int j = 0; j < count; j++)
            {
                if (items[j]->getID() == i)
                {
                    found = 1;
                    break;
                }
            }

            if (found == 1)
            {
                cout << "ID already exists!\n";
                break;
            }

            cout << "Enter Title: ";
            cin >> ws;
            getline(cin, t);

            cout << "Enter Author: ";
            getline(cin, a);

            cout << "Enter Due Date: ";
            cin >> d;

            cout << "Enter Duration in minutes: ";
            cin >> dur;

            if (dur <= 0)
            {
                cout << "Invalid duration!\n";
                break;
            }

            items[count] = new DVD(i, t, a, d, dur);
            count++;

            cout << "DVD added successfully!\n";
            break;
        }

        case 3:
        {
            if (count >= 50)
            {
                cout << "Library is full!\n";
                break;
            }

            int i, issue, found = 0;
            string t, a, d;

            cout << "Enter ID: ";
            cin >> i;

            for (int j = 0; j < count; j++)
            {
                if (items[j]->getID() == i)
                {
                    found = 1;
                    break;
                }
            }

            if (found == 1)
            {
                cout << "ID already exists!\n";
                break;
            }

            cout << "Enter Title: ";
            cin >> ws;
            getline(cin, t);

            cout << "Enter Author: ";
            getline(cin, a);

            cout << "Enter Due Date: ";
            cin >> d;

            cout << "Enter Issue Number: ";
            cin >> issue;

            if (issue <= 0)
            {
                cout << "Invalid issue number!\n";
                break;
            }

            items[count] = new Magazine(i, t, a, d, issue);
            count++;

            cout << "Magazine added successfully!\n";
            break;
        }

        case 4:
        {
            if (count == 0)
            {
                cout << "No items in library!\n";
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    items[i]->displayDetails();
                }
            }

            break;
        }

        case 5:
        {
            cout << "Enter Item ID to check out: ";
            cin >> id;

            int found = 0;

            for (int i = 0; i < count; i++)
            {
                if (items[i]->getID() == id)
                {
                    items[i]->checkOut();
                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                cout << "Item not found!\n";
            }

            break;
        }

        case 6:
        {
            cout << "Enter Item ID to return: ";
            cin >> id;

            int found = 0;

            for (int i = 0; i < count; i++)
            {
                if (items[i]->getID() == id)
                {
                    items[i]->returnItem();
                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                cout << "Item not found!\n";
            }

            break;
        }

        case 7:
        {
            for (int i = 0; i < count; i++)
            {
                delete items[i];
            }

            cout << "Program ended.\n";
            return 0;
        }

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
