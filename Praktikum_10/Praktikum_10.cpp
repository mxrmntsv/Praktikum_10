﻿#include <iostream>
#include "Header.h"
using namespace std;


Deque::Deque()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

Deque:: ~Deque()
{
    while (size_)
        PopFront();
}
class NoElementsException :public exception {
public:
    NoElementsException(const char *msg) :exception(msg) {
   
}

};
bool Deque::PushFront(const int& data)
{
    head_ = new Node(data, head_, NULL);
    size_++;
    return true;
}

bool Deque::PushBack(const int& data)
{
    if (head_ == NULL)
    {
        head_ = new Node(data);
        tail_ = head_;
    }
    else
    {
        tail_->pNext_ = new Node(data, NULL, tail_);
        tail_ = tail_->pNext_;
    }

    size_++;
    return true;
}


bool Deque::PopFront()
{
   if (size_ > 0) {
        Node* temp = head_;
        head_ = head_->pNext_;
        delete temp;
        size_--;
        return true;
    }
    else 
       throw NoElementsException("Deck is Empty!");
        
}


bool Deque::PopBack()
{
    if (size_ > 0) {
        Node* temp = tail_;
        tail_ = tail_->pPrev_;
        delete temp;

        return true;
    }
    else  throw NoElementsException("Deck is Empty!");
}

int main() {
    int action = 0;
    int count;
    Deque dec;
    cout << "Push Back[1]" << endl;
    cout << "Push Front[2]" << endl;
    cout << "PopFront [5]" << endl;
    cout << "PopBack [6]" << endl;
    cout << "Size [3]" << endl;
    cout << "Exit [4]" << endl;
    while (action != 4) {

        cout << "Your action:";
        cin >> action;
        if (action != 4 && action != 3) {
            cout << "Value:";
            cin >> count;
        }
        switch (action)
        {
        case (1): {
            dec.PushBack(count);
            break;
        }
        case (2): {
            dec.PushFront(count);
            break;
        }
        case (3): {
            cout << dec.GetSize() << endl;
            break;
        }
        case (5): {
            try {
                cout << dec.PopFront() << endl;
            }
            catch (NoElementsException ex) {
                cout << ex.what() << endl;
            }
            break;
        }
        }

    }
}

