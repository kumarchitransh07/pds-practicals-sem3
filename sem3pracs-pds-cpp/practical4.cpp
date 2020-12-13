#include <iostream>
#include <fstream>

using namespace std;

struct node {
    int data;
    node* left = NULL;
    node* right = NULL;
};

class searchTree {
    
    node* m_root = NULL;
    
    void printPreOrder(node* node) {
        if(node == NULL) {return;}
        cout << node->data << " ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
    
    void printInOrder(node* node) {
        if(node == NULL) {return;}
        printInOrder(node->left);
        cout << node->data << " ";
        printInOrder(node->right);
        
    }
    
    void printPostOrder(node* node) {
        if(node == NULL) {return;}
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout << node->data << " ";
    }
    
public:
    void add(int element) {
        if(m_root == NULL) {
            m_root = new struct node;
            m_root->data = element;
        }else{
            struct node* current = m_root;
            
            moveRight:
            while (element > current->data) {
                if(current->right != NULL) {
                    current = current->right;
                }else{
                    goto addRight;
                    break;
                }
            }
            if(current->left != NULL) {
                goto moveLeft;
            }else{
                goto addLeft;
            }
            
            moveLeft:
            while (element < current->data) {
                if(current->left != NULL) {
                    current = current->left;
                }else{
                    goto addLeft;
                    break;
                }
            }
            if(current->right != NULL) {
                goto moveRight;
            }else{
                goto addRight;
            }
            
            addLeft:
            current->left = new node;
            current->left->data = element;
            return;
            
            addRight:
            current->right = new node;
            current->right->data = element;
            return;
        }
    }
    
    void preOrder() {
        printPreOrder(m_root);
        cout << endl;
    }
    
    void inOrder() {
        printInOrder(m_root);
        cout << endl;
    }
    
    void postOrder() {
        printPostOrder(m_root);
        cout << endl;
    }
};

void setUpTree(searchTree* tree){
    ifstream file;
    string line;
    file.open("C:\Users\Chitransh\Documents\cpprepository\helloworld\input.txt");
    cout << "Reading file..." << endl;
    while (file) {
        getline(file, line);
        if(!file) {break;}
        int element = stoi(line);
        tree->add(element);
    }
    cout << "Closing file..." << endl;
    file.close();
}

int main() {
    searchTree tree;
    setUpTree(&tree);
    
    cout << "Pre-Order traversal: ";
    tree.preOrder();
    cout << "In-Order traversal: ";
    tree.inOrder();
    cout << "Post-Order traversal: ";
    tree.postOrder();
}
