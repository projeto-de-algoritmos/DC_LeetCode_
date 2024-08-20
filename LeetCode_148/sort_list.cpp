#include <iostream>

class Solution {
public:
    // Função que ordena a lista encadeada usando Merge Sort
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        // Encontrar o meio da lista para dividi-la em duas metades
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Divide a lista em duas partes
        prev->next = nullptr;
        
        // Ordenar cada metade recursivamente
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        // Mesclar as duas metades ordenadas
        return merge(l1, l2);
    }
    
private:
    // Mesclar duas listas encadeadas ordenadas
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        
        if (l1 != nullptr)
            p->next = l1;
        
        if (l2 != nullptr)
            p->next = l2;
        
        return dummy.next;
    }
};
