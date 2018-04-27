#include <iostream>
#include <string>

using namespace std;

struct Node{
    Node *fail;
    Node *next[128];
    int count;

    Node(){
        fail = NULL;
        memset(next, 0, sizeof(next));
        count = 0;
    }
} *q[50001];

int head,tail;

void insert(Node *root, string s){
    Node *p = root;
    for(int i=0;i<s.size();++i){
        if(!p->next[s[i]])
            p->next[s[i]] = new Node();
        p = p->next[s[i]];
    }

    p->count++;
}

void build_AC_automation(Node *root){
    root->fail = NULL;
    for(int i=0;i<128;++i)
        if(root->next[i] != NULL)
            root->next[i]->fail = root;

    q[head++] = root;

    Node *temp;
    Node *p;
    while(head != tail){
        temp = q[tail++];
        p = NULL;
        for(int i=0;i<128;++i){                         // temp 為該節點
            if(temp->next[i] != NULL){                  // temp->next[i] 為該節點的子節點
                p = temp->fail;
                while(p != NULL){
                    if(p->next[i] != NULL){
                        temp->next[i]->fail = p->next[i];
                        break;
                    }
                    p = p->fail;
                }
                if(p == NULL)
                    temp->next[i]->fail = root;
                q[head++] = temp->next[i];
            }
        }
    }

}

int main(){
    Node *root = new Node();

    insert(root, "say");
    insert(root, "she");
    insert(root, "shr");
    insert(root, "he");
    insert(root, "her");

    head = tail = 0;
    build_AC_automation(root);

    return 0;
}
