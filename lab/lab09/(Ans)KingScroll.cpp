#include <bits/stdc++.h>
using namespace std;

vector<int> kings = {1};
int found=0;

typedef struct _node{
    int george;
    char gender, alive;
    struct _node *left, *mid, *right;
}Node;

Node* newNode(int george,char gender){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->george = george;
    temp->gender = gender;
    temp->alive = 'L' ;
    temp->left = NULL, temp->right = NULL, temp->mid = NULL;
    return temp;

}

Node* root = newNode(1,'M');

Node* searchGeorge(int george,Node* node = root){
    if(node == NULL) return NULL;
    if(node->george==george) return node;
    Node* temp = NULL;
    if((temp = searchGeorge(george,node->left)) != NULL) return temp;
    if((temp = searchGeorge(george,node->mid)) != NULL) return temp;
    if((temp = searchGeorge(george,node->right)) != NULL) return temp;
    
    return NULL;
}

void insertGeorge(int parent,int george,char gender){
    Node* insertFrom = searchGeorge(parent);
    if(insertFrom->left==NULL) insertFrom->left = newNode(george,gender);
    else if(insertFrom->mid==NULL) insertFrom->mid = newNode(george,gender);
    else if(insertFrom->right==NULL) insertFrom->right = newNode(george,gender);
}

void nextgeorge(Node* node = root){
    if(node==NULL) return;
    if(node->gender == 'M' && node->alive=='L' && found==0){
        kings.push_back(node->george);
        found = 1;
    }
    nextgeorge(node->left);
    nextgeorge(node->mid);
    nextgeorge(node->right);
}

void sawannakot(int george){
    Node* temp = searchGeorge(george);
    temp->alive = 'D';
    if(temp->george == kings.back()){
        nextgeorge();
        found=0;
    }
}

int main(){
    int n,a,george=1;
    char b;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        if(b=='D') sawannakot(a);
        else if(b=='M'||b=='F') insertGeorge(a,++george,b);
    }
    
    for(int i=0;i<kings.size();i++) cout << kings[i] << endl;
}