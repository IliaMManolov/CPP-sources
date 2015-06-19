#include <iostream>
using namespace std;


struct node
{
    int value, count;
    node *left, *right;
    node *parent;

    node(node *p, int x, int y)
    {
        left = NULL;
        right = NULL;
        parent = p;

        value = x;
        count = y;
    }
};

node* root = NULL;


node* insert(node *parent, node *current, int value)
{
    if (current==NULL)
    {
        return new node(parent, value, 1);
    }

    if (current->value>value)
    {
        current->left = insert(current, current->left, value);
    }
    else if (current->value<value)
    {
        current->right = insert(current, current->right, value);
    }
    else
    {
        return NULL;
    }
    current->count++;

    return current;
}

void insert(int val)
{
    root = insert(NULL, root, val);

}


int kth(node *current, int count, int k)
{
    if (current==NULL) return 0;
    int leftCount = current-> left == NULL ? 0 : current->left->count;

    if (count+leftCount<k) return kth(current->right, count+leftCount+1, k);
    else if (count+leftCount>k) return kth(current->left, count, k);

    return current->value;
}

int kth(int k)
{
    //cout<<root->count<<endl;
    return kth(root, 0, k);
}



int cnt(node *current, int count, int x)
{
    if (current==NULL) return 0;
    int leftCount = current-> left == NULL ? 0 : current->left->count;

    if (x>current->value) return cnt(current->right, count+leftCount+1, x);
    else if (x<current->value) return cnt(current->left, count, x);

    return count+leftCount+1;
}

int cnt(int x)
{
    return cnt(root, 0, x);
}


void display(node* current)
{
    if (current==NULL) return;

    display(current->left);
    cout<<current->value<<' '<<current->count<<endl;
    display(current->right);
}




int main()
{
    insert (2);
    insert (1);
    insert (5);
    insert (3);
    insert (4);
    insert (-1);


    while (true)
    {
        string hue;
        int x;
        cin>>hue>>x;

        if (hue=="insert")
        {
            insert(x);
        }
        else if (hue=="kth")
        {
            cout<<kth(x)<<endl;
        }
        else if (hue=="delete")
        {
            del(x);
        }
        else if (hue=="count")
        {
            cout<<cnt(x)<<endl;
        }
        else if (hue=="display")
        {
            display(root);
        }
        else
        {
            cout<<"Invalid command"<<endl;
        }
    }

    return 0;
}
