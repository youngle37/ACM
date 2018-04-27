/*
 * Trie：
 * 每個節點存有所有字母的指標 next[]
 * 紀錄該節點是否為一個單詞 count
 *
 * 記得初始化節點 Node()
 */

#include <iostream>
#include <string>

using namespace std;

struct Node{
    Node *next[128];
    int count;

    Node(){
        memset(next, 0, sizeof(next));
        count = 0;
    }
};

Node* lookup(Node *root, string s){
    Node *p = root;
    for(int i=0;i<s.size();++i){
        if(!p->next[s[i]])
            return NULL;
        p = p->next[s[i]];
    }
    
    return p;
}

void Insert(Node *root, string s){
    Node *p = root;
    for(int i=0;i<s.size();++i){
        if(!p->next[s[i]])
            p->next[s[i]] = new Node();
        p = p->next[s[i]];
    }

    p->count++;
}

void release(Node *root){
    for(int i=0;i<128;++i){
        if(root->next[i])
            release(root->next[i]);
    }
    delete root;
}

int main(){
    Node *root = new Node();
    Insert(root, "XD");
    release(root);
    cout << lookup(root, "XD")->count;

    return 0;
}
