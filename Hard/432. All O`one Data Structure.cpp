class AllOne {
public:
    struct Node {
        int count;
        set<string> keys;  // Using std::set instead of std::list
        Node* prev;
        Node* next;
        Node(int c) {
            count = c;
            prev = NULL;
            next = NULL;
        }
    };

    Node* addNode(Node* prevNode, int count) {
        Node* newNode = new Node(count);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;

        if (newNode->next != NULL) {
            newNode->next->prev = newNode;
        }

        prevNode->next = newNode;

        if (prevNode == last) {
            last = newNode;
        }

        return newNode;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        if (node->next != NULL) {
            node->next->prev = node->prev;
        }

        if (last == node) {
            last = node->prev;
        }

        delete node;
    }

    unordered_map<string, Node*> mp;
    Node* head;
    Node* last;

    AllOne() {
        head = new Node(0);
        last = head;
    }

    void inc(std::string key) {
        // Key doesn't exist in map
        if (mp.find(key) == mp.end()) {
            if (head->next == NULL || head->next->count != 1) {
                addNode(head, 1);
            }
            head->next->keys.insert(key);  // Use insert for std::set
            mp[key] = head->next;
        }
        // Key exists in map
        else {
            Node* currNode = mp[key];
            int currCount = currNode->count;
            if (currNode->next == NULL || currNode->next->count != currCount + 1) {
                addNode(currNode, currCount + 1);
            }
            currNode->next->keys.insert(key);  // Use insert for std::set
            mp[key] = currNode->next;
            currNode->keys.erase(key);  // Use erase for std::set

            if (currNode->keys.empty()) {
                removeNode(currNode);
            }
        }
    }

    void dec(std::string key) {
        Node* currNode = mp[key];
        int currCount = currNode->count;

        // Remove the key if count becomes zero
        if (currCount == 1) {
            mp.erase(key);
        } 
        else {
            if (currNode->prev->count != currCount - 1) {
                addNode(currNode->prev, currCount - 1);
            }
            currNode->prev->keys.insert(key);  // Use insert for std::set
            mp[key] = currNode->prev;
        }

        currNode->keys.erase(key);  // Use erase for std::set
        if (currNode->keys.empty()) {
            removeNode(currNode);
        }
    }

    std::string getMaxKey() {
        if (last == head) {
            return "";
        }

        return *(last->keys.begin());  // Use * to dereference the first element of the set
    }

    std::string getMinKey() {
        if (head->next == NULL) {
            return "";
        }

        return *(head->next->keys.begin());  // Use * to dereference the first element of the set
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * std::string param_3 = obj->getMaxKey();
 * std::string param_4 = obj->getMinKey();
 */
