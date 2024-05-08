#include <iostream>
#include <ctime>


using namespace std;

//---CREATED THE BINARY SEARCH TREE---//

struct node {
    int data;
    struct node* leftChild, * rightChild;
};
struct node* root = NULL;
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->leftChild = temp->rightChild = NULL;
    return temp;


    //---CREATING THE INSERT METHOD---\\

}
void insert(int data) {
    struct node* tempNode = (struct node*)malloc(sizeof(struct node));
    struct node* current;
    struct node* parent;
    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    //if tree is empty
    if (root == NULL) {
        root = tempNode;
    }
    else {
        current = root;
        parent = NULL;

        while (1) {
            parent = current;

            //go to left of the tree
            if (data < parent->data) {
                current = current->leftChild;

                //insert to the left
                if (current == NULL) {
                    parent->leftChild = tempNode;
                    return;
                }
            }//go to right of the tree
            else {
                current = current->rightChild;

                //insert to the right
                if (current == NULL) {
                    parent->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}
//---SEARCH METHOD: TO LOOK FOR A PARTICULAR NODE---\\

struct node* search(int data) {
    struct node* current = root;
    while (current->data != data) {
        //go to left tree
        if (current->data > data) {
            current = current->leftChild;
        }//else go to right tree
        else {
            current = current->rightChild;
        }

        //not found
        if (current == NULL) {
            return NULL;
        }
    }
    return current; // return the updated bst
}

//---INORDER: TO PRINT THE DATA IN ORDER---\\\ It should rearrange itself the second time it prints. 
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->leftChild);
        cout << root->data << " ->";
        inorder(root->rightChild);
    }
}

//---CODE TO RUN THE PROGRAM & PERFROM INSERTION--\\

int main() {

    int random;
    clock_t start, end;

    for (int i = 0; i < 10; i++)
    {
        random = 1 + rand() % 100;
        start = clock();
        cout << "insertion done" << random << endl;
        end = clock();
        insert(random);

        cout << "insert time (MS)" << (end - start) << endl;
    }

    cout << "\nInorder ";
    inorder(root);
    struct node* k;
    int ele = 35;
    cout << "\nElement to be searched: " << ele;
    k = search(35);
    if (k != NULL)
        cout << "\nElement " << k->data << " found";
    else
        cout << "\nElement not found";
    return 0;
}


/// attempting to create the delete node:

//node* deleteNode(node* root, int data){
// if (root == NULL){
// return root;