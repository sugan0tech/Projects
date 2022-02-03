#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

int main()
{

    int choice, n, pos_val, i;
    Node *Head = NULL, *neww, *temp, *pre;
    cout << "1 for creating new Linked List "
         << "\n2 for printing Linked List "
         << "\n3 for adding element to first index "
         << "\n4 for appending"
         << "\n5 for adding element at desired place"
         << "\n6 for deleting an element";
    do
    {
        cout << "\nEnter the option : ";
        /* 1 for creating new LinkedList
           2 for printing LinkedList
           3 for adding a element to the begining of the list
           4 for appending a element to the end of tha list
           5 for adding a node before another node
           6 for deleing an  */
        cin >> choice;
        switch (choice)
        {
        case 1:
            // creation of LinkedList
            cout << "\n Enter the node data :";
            cin >> n;
            while (n != 0)
            {
                neww = new Node(n);
                if (Head == NULL)
                {
                    Head = neww;
                    temp = Head;
                }
                else
                {
                    temp->next = neww;
                    temp = neww;
                }
                cout << " Enter the node data :";
                cin >> n;
            }
            break;

        case 2:
            // Printing the LinkedList
            temp = Head;
            cout << temp->data;
            temp = temp->next;
            while (temp != NULL)
            {
                cout << " -> " << temp->data;
                temp = temp->next;
            }
            cout << " - > NULL";
            break;

        case 3:
            // adding element at the begining
            // getting
            cout << "\n Enter the num to be inserted :";
            cin >> n;
            // assignment
            temp = Head;
            neww = new Node(n);
            neww->next = temp;
            Head = neww;
            break;

        case 4:
            // appending a element
            // getting
            cout << "\n Enter the num to be append :";
            cin >> n;
            // assignment
            temp = Head;
            neww = new Node(n);
            // printing vallues untill Node becomes NULL
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = neww;
            break;

        case 5:
            // adding element at a postion
            // getting
            cout << "\n Enter the num to be inserted :";
            cin >> n;
            cout << "\n Enter the node to be inserted  before :";
            cin >> pos_val;
            // assignments and allocation
            temp = Head;
            neww = new Node(n);
            while (temp != NULL)
            {
                // comparing that pos_val to get access to it's previous
                if (temp->data == pos_val)
                {
                    neww->next = temp;
                    pre->next = neww;
                    break;
                }
                pre = temp;
                temp = temp->next;
            }
            break;

        case 6:
            // removing element
            temp = Head;
            cout << "\n Enter the num to be deleted :";
            cin >> n;
            while (temp != NULL)
            {
                // comparing that pos_val to get access to it's previous
                if (temp->data == n)
                {
                    pre->next = temp->next;
                    break;
                }
                pre = temp;
                temp = temp->next;
            }
            break;

        default:
            break;
        }

    } while (choice > 0);
    cout << "----*----*----*----*----*----"
         << "\nThanks for using this code :)\n"
         << "----*----*----*----*----*----";
    // Done by sugan0tech
    return 0;
}