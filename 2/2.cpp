#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/***********************************************/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *ans_idx = ans;
        int tmp = 0;
        while(l1 || l2 || tmp) {
            int cur_value = tmp;
            if(l1) cur_value += l1->val, l1 = l1->next;
            if(l2) cur_value += l2->val, l2 = l2->next;
            ans_idx->val = cur_value % 10;
            tmp = cur_value / 10;
            if(!l1 && !l2 && !tmp) {
                break;
            }
            ans_idx->next = new ListNode(0);
            ans_idx = ans_idx->next;
        }
        return ans;
    }
};

/***********************************************/
ListNode* buildList(int *a, int size_a) {
    ListNode *ret = new ListNode(0);
    ListNode *ret_idx = ret;
    for(int i = 0; i < size_a; i++) {
        ret_idx->val = a[i];
        ret_idx->next = i == size_a - 1 ? NULL : new ListNode(0);
        ret_idx = ret_idx->next;
    }
    return ret;
}

void display(ListNode* a){
    for(ListNode *idx = a; idx; idx=idx->next){
        cout << idx->val << (idx->next ? "" : "\n");
    }
}

int main() {
    int a[] = {2, 4, 3, 9};
    int b[] = {5, 6, 6};
    ListNode *l1 = buildList(a, 4);
    ListNode *l2 = buildList(b, 3);
    display(l1);
    display(l2);
    display(Solution().addTwoNumbers(l1, l2));
    return 0;
}
