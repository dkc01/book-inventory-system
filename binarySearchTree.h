 #ifndef H_binarySearchTree
#define H_binarySearchTree

#include "binaryTree.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

template <class elemType>
class bSearchTreeType : public binaryTreeType<elemType> {
public:
    bool search(const elemType& searchItem) const;
      //Function to determine if searchItem is in the binary
      //search tree.
      //Postcondition: Returns true if searchItem is found in
      //               the binary search tree; otherwise,
      //               returns false.

    void insert(const elemType& insertItem);
      //Function to insert insertItem in the binary search tree.
      //Postcondition: If there is no node in the binary search
      //               tree that has the same info as
      //               insertItem, a node with the info
      //               insertItem is created and inserted in the
      //               binary search tree.

    void deleteNode(const elemType& deleteItem);
      //Function to delete deleteItem from the binary search tree
      //Postcondition: If a node with the same info as deleteItem
      //               is found, it is deleted from the binary
      //               search tree.
      //               If the binary tree is empty or deleteItem
      //               is not in the binary tree, an appropriate
      //               message is printed.

    void deleteNodeEntirely(const elemType& deleteItem);
    bool searchWithOptions(const elemType& searchItem, int searchOption) const;
    void findPopularGenre() const;
    void findPopularGenreHelper(nodeType<elemType>* p, vector<string>& genres, vector<int>& counts) const;
    bool searchRetrieval(const elemType& searchItem, elemType& retrievedItem) const;
    void loadInventoryFromFile(bSearchTreeType<elemType>& inventory, const string& filename); 
 
 
private:
    void deleteFromTree(nodeType<elemType>* &p);
      //Function to delete the node to which p points is
      //deleted from the binary search tree.
      //Postcondition: The node to which p points is deleted
      //               from the binary search tree.
    
};


template <class elemType>
bool bSearchTreeType<elemType>::search
                    (const elemType& searchItem) const
{
    nodeType<elemType> *current;
    bool found = false;

    if (this->root == nullptr)
        cout << "Cannot search an empty tree." << endl;
    else
    {
       current = this->root;

       while (current != nullptr && !found)
        {
            if (current->info == searchItem)
                found = true;
            else if (current->info > searchItem)
                current = current->lLink;
            else
                current = current->rLink;
        }//end while
    }//end else

    return found;
}//end search


template <class elemType>
void bSearchTreeType<elemType>::insert
                 (const elemType& insertItem)
{
    nodeType<elemType> *current; //pointer to traverse the tree
    nodeType<elemType> *trailCurrent = nullptr; //pointer
                                              //behind current
    nodeType<elemType> *newNode;  //pointer to create the node

    newNode = new nodeType<elemType>;
    newNode->info = insertItem;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

    if (this->root == nullptr)
        this->root = newNode;
    else
    {
        current = this->root;

        while (current != nullptr)
        {
            trailCurrent = current;

            if (current->info == insertItem)
            {
                cout << "The item to be inserted is already ";
                cout << "in the tree -- duplicates are not "
                     << "allowed." << endl;
                return;
            }
            else if (current->info > insertItem)
                current = current->lLink;
            else
                current = current->rLink;
        }//end while

        if (trailCurrent->info > insertItem)
            trailCurrent->lLink = newNode;
        else
            trailCurrent->rLink = newNode;
    }
}//end insert

template <class elemType>
void bSearchTreeType<elemType>::deleteNode
                                (const elemType& deleteItem)
{
    nodeType<elemType> *current; //pointer to traverse the tree
    nodeType<elemType> *trailCurrent; //pointer behind current
    bool found = false;

    if (this->root == nullptr)
        cout << "Cannot delete from an empty tree."
             << endl;
    else
    {
        current = this->root;
        trailCurrent = this->root;

        while (current != nullptr && !found)
        {
            if (current->info == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;

                if (current->info > deleteItem)
                    current = current->lLink;
                else
                    current = current->rLink;
            }
        }//end while

        if (current == nullptr)
            cout << "The item to be deleted is not in the tree."
                 << endl;
        else if (found)
        {
            if (current == this->root)
                deleteFromTree(this->root);
            else if (trailCurrent->info > deleteItem)
                deleteFromTree(trailCurrent->lLink);
            else
                deleteFromTree(trailCurrent->rLink);
        }
        else
            cout << "The item to be deleted is not in the tree."
                 << endl;
    }
} //end deleteNode

template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree
                                 (nodeType<elemType>* &p)
{
    nodeType<elemType> *current; //pointer to traverse the tree
    nodeType<elemType> *trailCurrent;  //pointer behind current
    nodeType<elemType> *temp;      //pointer to delete the node

    if (p == nullptr)
        cout << "Error: The node to be deleted does not exist."
             << endl;
    else if (p->lLink == nullptr && p->rLink == nullptr)
    {
        temp = p;
        p = nullptr;
        delete temp;
    }
    else if (p->lLink == nullptr)
    {
        temp = p;
        p = temp->rLink;
        delete temp;
    }
    else if (p->rLink == nullptr)
    {
        temp = p;
        p = temp->lLink;
        delete temp;
    }
    else
    {
        current = p->lLink;
        trailCurrent = nullptr;

        while (current->rLink != nullptr)
        {
            trailCurrent = current;
            current = current->rLink;
        }//end while

        p->info = current->info;

        if (trailCurrent == nullptr) //current did not move;
                               //current == p->lLink; adjust p
            p->lLink = current->lLink;
        else
            trailCurrent->rLink = current->lLink;

        delete current;
    }//end else
} //end deleteFromTree


// function to delete a node. 
template <class elemType>
void bSearchTreeType<elemType>::deleteNodeEntirely(const elemType& deleteItem) 
{
    deleteNode(deleteItem);
}

// function to allow user to search for either title, author, isbn or genre
template <class elemType>
bool bSearchTreeType<elemType>::searchWithOptions(const elemType& searchItem, int searchOption) const 
{
    
    
    // If the searchOption is 1, it will search on the basis of ISBN. 
    if(searchOption == 1)
    {
        nodeType<elemType>* current = this->root;
        
        while (current != nullptr) 
        {
            // if isbn matches return true and display the node 
            if (current->info.getISBN() == searchItem.getISBN()) 
            { 
                cout << endl;
                cout << "Match found: ";
                cout << current->info;
                cout << endl;
                return true;
            }
            else if(current->info.getISBN() > searchItem.getISBN())
            {
                // search on leftsubtree
                current = current->lLink;
            }
            else
            {
                // search on right sub tree
                current = current->rLink;
            }
        }
        // if the isbn doesn't match simply return false
        return false;
    }
    else
    {
        // initially I tried to check the title, author and genre of the book 
        // by using .getTitle(), .getAuthor and so on getters but as soon as the 
        // we entered the < and > operation, it could only compare the isbn/
        
        // so I search the title, author or genre using the modified inordertraversal function. 
        return this->inorderTraversalforSearch(searchOption, searchItem);
    }
}

// function to traverse through all the nodes and count th
template <class elemType>
void bSearchTreeType<elemType>::findPopularGenre() const {
    if (this->root == nullptr) {
        cout << "The tree is empty. No genres found." << endl;
        return;
    }

    // Vectors to store genres and their counts
    vector<string> genres;
    vector<int> counts;

    // Helper function to traverse and store genres and counts
    findPopularGenreHelper(this->root, genres, counts);

    // Find the genre with the maximum frequency
    string popularGenre;
    int maxCount = 0;
    
    // loop to check the popular genre by checking the maximum quantity of book of each genres
    for (int i = 0; i < genres.size(); ++i) {
        if (counts[i] > maxCount) {
            maxCount = counts[i];
            popularGenre = genres[i];
        }
    }

    if (!popularGenre.empty()) {
        cout << "The most popular genre is: " << popularGenre << " with " << maxCount << " occurrences.\n";
    } else {
        cout << "No genres found in the tree.\n";
    }
}

// Helper function for in-order traversal
template <class elemType>
void bSearchTreeType<elemType>::findPopularGenreHelper(nodeType<elemType>* p, vector<string>& genres, vector<int>& counts) const {
    if (p != nullptr) {
        // traverse right
        findPopularGenreHelper(p->lLink, genres, counts);

        // Get the genre and quantity from the current node
        int quantity = p->info.getQuantity();
        string genre = p->info.getGenre();

        // Check if the genre already exists in the genres vector
        bool found = false;
        for (int i = 0; i < genres.size(); ++i) {
            if (genres[i] == genre) {
                counts[i] += quantity;  // Increment the count by the quantity
                found = true;
                break;
            }
        }

        // if the genre is not found, add it to the vectors
        if (!found) {
            genres.push_back(genre);
            counts.push_back(quantity);
        }
        // traverse left 

        findPopularGenreHelper(p->rLink, genres, counts);
    }
}


// this function checks if a book with particular isbn exist. 
// it retrieve and stores the details of the object. 
template <class elemType>
bool bSearchTreeType<elemType>::searchRetrieval(const elemType& searchItem, elemType& resultItem) const {
    nodeType<elemType>* current = this->root;

    while (current != nullptr) {
        if (current->info == searchItem) {
            // retrieve the info of the actual book 
            resultItem = current->info; 
            return true;
        } else if (current->info > searchItem) {
            current = current->lLink;
        } else {
            current = current->rLink;
        }
    }

    return false; // Item not found
}



    
    
    

// function to load data from a text file 
template <typename elemType>
void loadInventoryFromFile(bSearchTreeType<elemType>& inventory, const string& fileName) {
    //read from a file
    fstream myFile;
    elemType book;
    
    myFile.open(fileName, ios::in); // in
    
    if(myFile.is_open())
    {
        string line;
        while(getline(myFile, line)) // it reads myfile for each line and store in line
        {
            stringstream ss(line);
            ss >> book;
            inventory.insert(book);
        }
        cout << "Inventory successfully loaded from " << fileName << endl;
    }
    else
    {
        cout << "Couldn't load the file. " << endl;
    }
    
    myFile.close();
}





#endif
