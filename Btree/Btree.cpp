// Btree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX 3
#define MIN 2

struct B_tree {
    int data[MAX + 1], count;
    struct B_tree* link[MAX + 1];
};

struct B_tree* root;
struct B_tree* create_node(int data, struct B_tree* child) {
    struct B_tree* new_node;
    new_node = (struct B_tree*)malloc(sizeof(struct B_tree));
    new_node->data[1] = data;
    new_node->count = 1;
    new_node->link[0] = root;
    new_node->link[1] = child;
    return new_node;
}

void add_node(int data, int pos, struct B_tree* node,
    struct B_tree* child) {
    int j = node->count;
    while (j > pos) {
        node->data[j + 1] = node->data[j];
        node->link[j + 1] = node->link[j];
        j--;
    }
    node->data[j + 1] = data;
    node->link[j + 1] = child;
    node->count++;
}

void divide_node(int data, int* pdata, int pos, struct B_tree* node,
    struct B_tree* child, struct B_tree** new_node) {
    int median, j;

    if (pos > MIN)
        median = MIN + 1;
    else
        median = MIN;

    *new_node = (struct B_tree*)malloc(sizeof(struct B_tree));
    j = median + 1;
    while (j <= MAX) {
        (*new_node)->data[j - median] = node->data[j];
        (*new_node)->link[j - median] = node->link[j];
        j++;
    }
    node->count = median;
    (*new_node)->count = MAX - median;

    if (pos <= MIN) {
        add_node(data, pos, node, child);
    }
    else {
        add_node(data, pos - median, *new_node, child);
    }
    *pdata = node->data[node->count];
    (*new_node)->link[0] = node->link[node->count];
    node->count--;
}

int set_data(int data, int* pdata,
    struct B_tree* node, struct B_tree** child) {
    int pos;
    if (!node) {
        *pdata = data;
        *child = NULL;
        return 1;
    }

    if (data < node->data[1]) {
        pos = 0;
    }
    else {
        for (pos = node->count;
            (data < node->data[pos] && pos > 1); pos--)
            ;
        if (data == node->data[pos]) {
            printf("Khong duoc phep trung lap\n");
            return 0;
        }
    }
    if (set_data(data, pdata, node->link[pos], child)) {
        if (node->count < MAX) {
            add_node(*pdata, pos, node, *child);
        }
        else {
            divide_node(*pdata, pdata, pos, node, *child, child);
            return 1;
        }
    }
    return 0;
}

void add(int data) {
    int flag, i;
    struct B_tree* child;

    flag = set_data(data, &i, root, &child);
    if (flag)
        root = create_node(i, child);
}

void find_node(int data, int* pos, struct B_tree* nod) {
    if (!nod) {
        return;
    }

    if (data < nod->data[1]) {
        *pos = 0;
    }
    else 
    {
        for (*pos = nod->count;
            (data < nod->data[*pos] && *pos > 1); (*pos)--)
            ;
        if (data == nod->data[*pos]) 
        {
            printf("Da tim thay %d", data);
            return;
        }
       
    }
    if (data != nod->data[*pos])
    {
        printf("Khong tim thay %d trong cay ", data);
    }
    find_node(data, pos, nod->link[*pos]);

    return;
}

void traverse(struct B_tree* nod) {
    int i;
    if (nod) {
        for (i = 0; i < nod->count; i++) {
            traverse(nod->link[i]);
            printf("%d ", nod->data[i + 1]);
        }
        traverse(nod->link[i]);
    }
}

int main() {
    int data, ch;
    int n, i,j, k;
    cout << "Nhap so phan tu trong cay: \n";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i <<": \n";
        cin >> j;
        add(j);
    }
    cout << "Nhap phan tu can tim: \n";
    cin >> k;
   /* add(6);
    add(8);
    add(10);
    add(13);
    add(15);
    add(19);
    add(14);
    add(18);
    add(23);
    add(25);*/
    traverse(root);
    printf("\n");
    find_node(k, &ch, root);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
