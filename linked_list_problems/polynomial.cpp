#include <iostream>
using namespace std;

struct Node
{
    int coeff;
    int expo;
    struct Node *link;
} * start, *result;

void create_list(int c, int e)
{
    struct Node *q, *tmp;
    tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->coeff = c;
    tmp->expo = e;
    tmp->link = NULL;

    if (start == NULL)
    {
        start = tmp;
        return;
    }

    if (tmp->expo > start->expo)
    {
        tmp->link = start;
        start = tmp;
        return;
    }

    q = start;

    while ((q->link != NULL) && (q->link->expo > tmp->expo))
    {
        q = q->link;
    }

    if (q->link != NULL)
    {
        tmp->link = q->link;
        q->link = tmp;
        return;
    }

    q->link = tmp;
}

void display()
{
    struct Node *q;
    q = start;

    while (q != NULL)
    {
        cout << "Coefficient, Exponent = " << q->coeff << ", " << q->expo << endl;
        q = q->link;
    }
}

void addSubtract(struct Node *a, struct Node *b, int oper)
{
    struct Node *ptr1, *ptr2, *tmp, *q;
    ptr1 = a;
    ptr2 = b;

    while ((ptr1 != NULL) && (ptr2 != NULL))
    {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->link = NULL;
        if (ptr1->expo == ptr2->expo)
        {
            if (oper == 1)
                tmp->coeff = ptr1->coeff + ptr2->coeff;
            else
                tmp->coeff = ptr1->coeff - ptr2->coeff;
            tmp->expo = ptr1->expo;
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            tmp->coeff = ptr1->coeff;
            tmp->expo = ptr1->expo;
            ptr1 = ptr1->link;
        }
        else
        {
            if (oper == 1)
                tmp->coeff = ptr2->coeff;
            else
                tmp->coeff = -(ptr2->coeff);
            tmp->expo = ptr2->expo;
            ptr2 = ptr2->link;
        }
        if (start == NULL)
        {
            start = tmp;
        }
        else
        {
            q = start;
            while (q->link != NULL)
            {
                q = q->link;
            }
            q->link = tmp;
        }
    }

    if ((ptr1 == NULL) && (ptr2 != NULL))
    {
        q = start;
        while (q->link != NULL)
        {
            q = q->link;
        }
        q->link = ptr2;
    }
    else if ((ptr2 == NULL) && (ptr1 != NULL))
    {
        q = start;
        while (q->link != NULL)
        {
            q = q->link;
        }
        q->link = ptr1;
    }
}

void multiply(struct Node *a, struct Node *b)
{
    struct Node *tmp, *q, *ptr1, *ptr2;

    ptr1 = a;

    while (ptr1 != NULL)
    {
        ptr2 = b;
        while (ptr2 != NULL)
        {
            tmp = (struct Node *)malloc(sizeof(struct Node));
            tmp->link = NULL;

            tmp->coeff = ptr1->coeff * ptr2->coeff;
            tmp->expo = ptr1->expo + ptr2->expo;

            if (result == NULL)
            {
                result = tmp;
            }
            else
            {
                start = NULL;
                addSubtract(result, tmp, 1);
                result = start;
            }
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }

    start = result;
}

void inputPolynomial(int n)
{
    int coeff, expo;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the term (coeff, expo) : ";
        cin >> coeff;
        cin >> expo;
        create_list(coeff, expo);
    }
    display();
}

void decideOperation(int oper, struct Node *eqn1, struct Node *eqn2)
{
    switch (oper)
    {
    case 1:
        addSubtract(eqn1, eqn2, oper);
        cout << "The result is : " << endl;
        display();
        break;
    case 2:
        addSubtract(eqn1, eqn2, oper);
        cout << "The result is : " << endl;
        display();
        break;
    case 3:
        multiply(eqn1, eqn2);
        cout << "The result is : " << endl;
        display();
        break;
    default:
        break;
    }
}

int main()
{
    int n, oper;
    struct Node *eqn1, *eqn2;

    cout << "\nEnter the number of terms in the first polynomial: ";
    cin >> n;
    inputPolynomial(n);

    eqn1 = start;
    start = NULL;

    cout << "\nEnter the number of terms in the second polynomial: ";
    cin >> n;
    inputPolynomial(n);

    eqn2 = start;
    start = NULL;

    cout << "\nEnter the following operation (Add::1, Subtract::2, Multiply::3): ";
    cin >> oper;
    decideOperation(oper, eqn1, eqn2);
}