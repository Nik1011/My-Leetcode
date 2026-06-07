#include <iostream>
#include <stack>
#include <string>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        return nullptr;
    }
};
 int main() {
    // 1. Input
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // 2. input
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // erstellen 2er Stacks
    std::stack<int> s1;
    std::stack<int> s2;

    // Liste durchiterieren
    ListNode *cur = l1;
    ListNode *cur2 = l2;
    while (cur) {
        std::cout << cur->val << " -> ";
        s1.push(cur->val);
        cur = cur->next;

    }
    std::cout << "nullptr\n";

    while (cur2) {
        std::cout << cur2->val << " -> ";
        s2.push(cur2->val);
        cur2 = cur2->next;
    }      
    std::cout << "nullptr\n";

    std::string erste_zahl_als_String;
    std::string zweite_zahl_als_String;

    // beide schleifen muessen getrennt sein, weil die stacks (zahlen unterschiedlich lang sein koennen)
    while(!s1.empty()) {
    erste_zahl_als_String += std::to_string(s1.top());
    s1.pop();
    }
    while(!s2.empty()) {
        zweite_zahl_als_String += std::to_string(s2.top());
        s2.pop();
    }

    int input_1zahl_rw = std::stoi(erste_zahl_als_String);
    int input_2zahl_rw = std::stoi(zweite_zahl_als_String);
    int sum = input_1zahl_rw + input_2zahl_rw;
    std::string sum_string = std::to_string(sum);

    
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    
    // std::string ist intern einfach ein Array aus char
    // string rueckwerts durchgehen
    for(int i = sum_string.length() -1; i >= 0; i--){
        int cur_val = sum_string[i] - '0';
        ListNode* node = new ListNode(cur_val);

        if(!head){
            head = node;
            tail = node;
        }else{
            tail->next = node;
            tail = node;
        }
    }
    

    std::cout << "Ergebnis: " << sum << std::endl;
    std::cout << "Summe als String: " << sum_string << std::endl;
    

    ListNode* result = head;
    std::cout << "Die neue Liste: " << std::endl;
    while (result) {
        std::cout << result->val << " -> ";
        result = result->next;
    }
    std::cout << "nullptr\n";


    // Speicher freigeben
    while (l1) {
    ListNode *tmp = l1;
    l1 = l1->next;
    delete tmp;
    }
    while (l2) {
        ListNode *tmp = l2;
        l2 = l2->next;
        delete tmp;
    }
    while (head) {
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
    }


    return 0;
}
