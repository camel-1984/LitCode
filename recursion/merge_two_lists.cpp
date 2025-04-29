#include <iostream>

using namespace std;



struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;


        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

int main() {

    ListNode a(5);
    ListNode b(1);
    ListNode c(2);
    ListNode d(4);

    a.next = nullptr;
    b.next = &c;
    c.next = &d;
    d.next = nullptr;

    Solution sol;
    sol.mergeTwoLists(&a, &b);



    return 0;
}
