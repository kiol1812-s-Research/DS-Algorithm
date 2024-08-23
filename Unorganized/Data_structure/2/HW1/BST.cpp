/* 2024/03/14 binary search tree
*/
#include <iostream>
#include <random>
using namespace std;

// binary search tree node structure
template <class K, class E>
class TreeNode{
public:
    TreeNode* left;
    TreeNode* right;
    pair<K, E> data;
    TreeNode(pair<K, E> e){
        this->data.first = e.first;
        this->data.second= e.second;
        this->left = NULL;
        this->right = NULL;
    }
};


// binary search tree (dictionary) ADT
template <class K, class E> // key & Element
class Dictionary{
private:
    TreeNode<K, E>* root;
public:
    Dictionary(){
        root = NULL;
    }
    bool IsEmpty() const { return root==NULL; }
    pair<K, E>* Get(const K& k) const;
    void Insert(const pair<K, E>& e);
    TreeNode<K, E>* findMin(TreeNode<K, E>* node);
    TreeNode<K, E>* Delete(TreeNode<K, E> *e, const K& k);
    TreeNode<K, E>* getRoot(){ return root; }
};
template <class K, class E>
pair<K, E>* Dictionary<K, E>::Get(const K& k) const {
    TreeNode<K, E>* current = root;
    while(current){
        if(k>current->data.first) current=current->right;
        else if(k<current->data.first) current = current->left;
        else return &current->data;
    }
    return 0;
}
template <class K, class E>
void Dictionary<K, E>::Insert(const pair<K, E>& e){
    TreeNode<K, E> *p=root, *dp=0;
    while(p!=NULL){
        dp = p;
        if(e.first<p->data.first) p=p->left;
        else if(e.first>p->data.first) p=p->right;
        else{
            p->data.second=e.second;
            return;
        }
    }
    p = new TreeNode<K, E>(e);
    if(root!=NULL){
        if(e.first<dp->data.first) dp->left=p;
        else dp->right=p;
    }else root=p;
}
template <class K, class E>
TreeNode<K, E>* Dictionary<K, E>::findMin(TreeNode<K, E>* node){
    if(node->left==NULL) return node;
    else return findMin(node->left);
}
template <class K, class E>
TreeNode<K, E>* Dictionary<K, E>::Delete(TreeNode<K, E> *now, const K& k){
    if(now==NULL) return now;   
    if(k>now->data.first) now->right=Delete(now->right, k);
    else if(k<now->data.first) now->left=Delete(now->left, k);
    else{
        if(now->right==NULL){
            TreeNode<K, E>* tmpNode=now->left;
            free(now);
            now=NULL;
            return tmpNode;
        }else if(now->left==NULL){
            TreeNode<K, E>* tmpNode=now->right;
            free(now);
            now=NULL;
            return tmpNode;
        }else{
            TreeNode<K, E>* tmpNode=findMin(now->right);
            now->data.first=tmpNode->data.first;
            now->right = Delete(now->right, tmpNode->data.first);
        }
    }
    return now;
}


// inorder traverse for show trees
template <class K, class E>
int inorderTraverse(TreeNode<K, E>* node, int Level, bool print){
    int leftLevel=0, rightLevel=0;
    if(node!=NULL){
        leftLevel = inorderTraverse(node->left, Level+1, print);
        if(print) cout<<node->data.first<<" "<<node->data.second<<"\n";
        rightLevel = inorderTraverse(node->right, Level+1, print);
    }
    if(leftLevel>=rightLevel&&leftLevel>=Level) return leftLevel;
    else if(rightLevel>=leftLevel&&rightLevel>=Level) return rightLevel;
    return Level;
}

// A, the radio height/log2(n) should be approximately constant (around 2)
void RatioTest(){
    const int range_from = 0, range_to = 10000;
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> uniform(range_from, range_to);
    int arr[10000], n[]={100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    for(auto &ni:n){
        Dictionary<int, int> BST;
        for(int i=0; i<ni; i++){
            arr[i] = uniform(generator);
            BST.Insert(make_pair(arr[i], arr[i]));
        }
        double height = (double)inorderTraverse(BST.getRoot(), 0, false);
        double ratio = height/(log(ni)/log(2));
        cout<<ratio<<"\n";
    }
}
//B, delete the pair with key k from a binary search tree, O(log2(n))
void DeleteTest(){
    int arr[]={100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    Dictionary<int, int> BST;
    for(auto &ai:arr){
        BST.Insert(make_pair(ai, ai));
    }
    BST.Delete(BST.getRoot(), 5000);
    inorderTraverse(BST.getRoot(), 0, true);
}



int main(){
    cout<<"\nRadio test:\n";
    RatioTest();
    cout<<"\n\nDelete test:\n";
    DeleteTest();
    return 0;
}