struct TrieNode{
       struct TrieNode *children[2];
};

TrieNode *getNode(){
        TrieNode *pnode= new TrieNode();      
        pnode->children[0]=NULL;
        pnode->children[1]=NULL;
        return pnode;
}
    
void insert(int a,TrieNode* node){
    
   for(int i=31;i>=0;i--){       
       int check = (a>>i)&1;
       if(node->children[check]==NULL){
           node->children[check]= getNode();
       }
       node=node->children[check];  
   }   
}
int maxXor(int num,TrieNode* node){   
    int maxi=0;
    for(int i=31;i>=0;i--){
         int check = (num>>i)&1;
        if(node->children[1-check]!=NULL){
          maxi= (1<<i)|maxi; 
            node=node->children[1-check];
        }else{
            node=node->children[check];
        }
    }
    return maxi;
}
