class MyLinkedList {
public:

struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = nullptr;
        }
    };

    Node* head;
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        Node* node = head;
        if(node == nullptr) return -1;
        int cnt = 0;
        while(node!=nullptr && cnt!=index){
            cnt++;
            node = node->next;
        }
        if(node == nullptr) return -1;
        return node->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        Node* temp = head;
        if(temp == nullptr) temp = head;
        node->next = temp;
        head = node;
        return;
    }
    
    void addAtTail(int val) {
        Node* temp = head;
        Node* node = new Node(val);
        if(temp == nullptr){
            head = node;
            return;
        }
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = node;
        return;
    }
    
    void addAtIndex(int index, int val) {
    if (index == 0) {
        addAtHead(val);
        return;
    }

    Node* temp = head;

    for (int i = 0; i < index - 1; i++) {
        if (temp == nullptr) return;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    Node* newNode = new Node(val);

    newNode->next = temp->next;
    temp->next = newNode;
}
    
    void deleteAtIndex(int index) {
    if (head == nullptr) return;

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    for (int i = 0; i < index - 1; i++) {
        if (temp == nullptr) return;
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) return;

    Node* toDelete = temp->next;

    temp->next = toDelete->next;

    delete toDelete;
}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */