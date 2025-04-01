class ListNode {
public:
    int val;
    ListNode* next;

};
ListNode* head;

// ListNode* current = head;
// ListNode* previous = nullptr;
// ListNode* next = nullptr;

// ListNode* reverseListRecursive(ListNode* head) {
//     if (head == nullptr || head->next == nullptr) {
//         return head;
//     }
//
//     ListNode* reversedRest = reverseListRecursive(head->next);
//
//     head->next->next = head;
//     head->next = nullptr;
//
//     return reversedRest;
// }

ListNode* main() {

    // ListNode* current = head;
    // ListNode* previous = nullptr;
    // ListNode* next = nullptr;
    // while (current != nullptr) {
    //     next = current->next;
    //     current->next = previous;
    //     previous = current;
    //     current = next;
    // }
    // return current;

    if (head == nullptr) {
        return nullptr;
    }

    ListNode* current = head;
    ListNode* previous = nullptr;

    ListNode* new_head = nullptr;

    while(current->next != nullptr) {
        current = current->next;
    }
    new_head = current;

    current = head;
    previous = nullptr;

    while (head->next != nullptr) {
        previous = current;
        current = current->next;

        if (current->next == nullptr) {
            current->next = previous;
            previous->next = nullptr;
            current = head;
            previous = nullptr;
        }
    }
    return new_head;
}
