#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int value;
        Node *next;
        Node *prev;

        Node(int k, int v)
        {
            key = k;
            value = v;
        }
    };

    int cap = 0;

    map<int, Node *> mp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        else
        {
            Node *address = mp[key];
            int data = address->value;
            mp.erase(key);
            deleteNode(address);
            addNode(address);
            mp[key] = head->next;
            return data;
        }
    }

    void deleteNode(Node *node)
    {
        Node *temp = node->next;
        Node *prevNode = node->prev;

        prevNode->next = temp;
        temp->prev = prevNode;
    }

    void addNode(Node *node)
    {
        Node *temp = head->next;

        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    void put(int key, int value)
    {
        // if value already exist
        if (mp.find(key) != mp.end())
        {
            Node *address = mp[key];
            mp.erase(key);
            deleteNode(address);
            addNode(new Node(key, value));
            mp[key] = head->next;
        }
        else if (mp.size() == cap)
        {
            Node *nodeToRemove = tail->prev;
            int nodeKey = nodeToRemove->key;
            mp.erase(nodeKey);
            deleteNode(nodeToRemove);
            addNode(new Node(key, value));
            mp[key] = head->next;
        }
        else
        {
            addNode(new Node(key, value));
            mp[key] = head->next;
        }
    }
};

// time complexity: O(1) for both get and put operations since we are using a hash map to store the key-value pairs and a doubly linked list to maintain the order of the keys.
// space complexity: O(capacity) since we are storing at most capacity number of key-value