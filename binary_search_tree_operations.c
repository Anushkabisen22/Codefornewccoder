# include <stdio.h>
# include <stdlib.h>
# include <string.h>
// create a structure
struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
};
//create a node
struct tree* create(int data){
    struct tree* p;
    p=(struct tree*)malloc(sizeof(struct tree));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    return p;
}
// insert a element
struct tree* insert(struct tree *root,int data){
    if (root==NULL){
        return create(data);
    }
    if (data <root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}
// search a element
int search(struct tree* root,int val){
    while (root!=NULL)
    {
        if (val>root->data){
            root=root->right;
        }
        else if (val<root->data){
            root=root->left;
        }
        else{
            return root->data;
        }
    }
    return -1;
}
// prnt inorder series
void inorder(struct tree* root){
    if (root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

// find max element
int maximum(struct tree* root,int k){
    int i=1;
    while(root->right!=NULL){
        root=root->right;
        i++;
    }
}
struct tree* minimum(struct tree* root){
    while(root->left!= NULL){
        root=root->left;
    }
    return root;
}
// successor node
int successor(struct tree* node){
    if (node->right==NULL){
        return 0;
    }
    else{
        return minimum(node->right)->data;
    }
}


int main(){
    int n;
    printf("enter the number of element:");
    scanf("%d",&n);
    struct tree* root=create(n);
    printf("enter the elements:");
    for (int i=0;i<n;i++){
        int c;
        scanf("%d",&c);
        insert(root,c);

    }
    int r;
    printf("element to search:");
    scanf("%d",&r);
    int ans=search(root,r);
    printf("object found or not: ");
    printf("%d\n",ans);
    printf("inorder series: ");
    inorder(root);
    printf("successor node :");
    int l=successor(root);
    printf("%d\n",l);
    
    }
    


    

