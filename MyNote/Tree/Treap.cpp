/*
 * 以 Value 看為 Binary Search Tree
 * 以 Fix 看也同時為 heap
 * 每個節點的結構為：
 *      1. 左右節點的指標
 *      2. Value (Binary Search 的依據)
 *      3. Fix (隨機產生的)
 *      4. Weight (紀錄這個 Value 的個數，因此不用處理重複值的問題)
 *      5. Size (該子樹的大小)
 *      6. 兩個 inline function 用來 return 左子樹和右子樹的大小
 */

struct Treap_Node {
    Treap_Node *left, *right;
    int value;
    int fix;
    int weight;
    int size;
    inline int lsize() {
        return left ? left.size : 0;
    }
    inline int rsize() {
        return right ? right.size : 0;
    }
};


