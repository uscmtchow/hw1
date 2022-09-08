#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

ULListStr::~ULListStr()
{
    clear();
}

bool ULListStr::empty() const
{
    return size_ == 0;
}

size_t ULListStr::size() const
{
    return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
        throw std::invalid_argument("Bad location");
    }
    *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

void ULListStr::clear()
{
    while(head_ != NULL){
        Item *temp = head_->next;
        delete head_;
        head_ = temp;
    }
    tail_ = NULL;
    size_ = 0;
}

// add item to back of list
void ULListStr::push_back(const std::string &val) {
    // Update number of Items
    this->size_++;

    // create new item to be added
    Item* newItem = new Item();

    // add given value to made item
    newItem->val[newItem->last] = val;

    // update last, first is always equal to 0
    newItem->last++;

    // if list empty
    if (this->head_ == nullptr) {
        // set head_ equal to the new item
        this->head_ = newItem;
        // set tail_ equal to the new item
        this->tail_ = newItem;
        return;
    }

    // update pointers
    this->tail_->next = newItem;
    newItem->prev = this->tail_;
    this->tail_ = newItem;
}

// remove back item
void ULListStr::pop_back() {
    // update size
    this->size_--;

    // get current tail
    Item* curr = this->tail_;
    // update tail
    this->tail_ = this->tail_->prev;

    // if tail_ is not nullptr
    if (this->tail_) this->tail_->next = nullptr; // one or more items
    else head_ = nullptr; // list empty

    // update last
    curr->last--;

    // deallocate last item
    delete curr;
}

// add item to front of list
void ULListStr::push_front(const std::string &val) {
    // update size
    this->size_++;

    // create new item to be added
    Item* newItem = new Item();

    // add given value to made item
    newItem->val[newItem->last] = val;

    // if list empty
    if (this->head_ == nullptr) {
        // set head_ equal to the new item
        this->head_ = newItem;
        // set tail_ equal to the new item
        this->tail_ = newItem;
        return;
    }

    // update pointers
    head_->prev = newItem;
    newItem->next = head_;
    this->head_ = newItem;
}

// remove front item
void ULListStr::pop_front() {
    // update number of items
    this->size_--;

    // get current head
    Item* curr = this->head_;
    // update head
    this->head_ = this->head_->next;

    // if tail_ is not nullptr
    if (!this->head_) {
        head_ = nullptr;
        tail_ = nullptr;
    }

    // deallocate last item
    delete curr;
}

// return last items value
std::string const &ULListStr::back() const {
    // return the last items last value
    return this->tail_->val[this->tail_->last-1];
}

//return first items value
std::string const &ULListStr::front() const {
    // return the first items first value
    return this->head_->val[this->head_->first];
}

// return the value at a certain location (loc)
std::string *ULListStr::getValAtLoc(size_t loc) const {
    // create a pointer to the head item
    Item* curr = this->head_;

    // iterate as many times to get to the correct location
    for (auto i = 0; i < loc; i++) {
        // update pointer
        curr = curr->next;
        // if loc is larger than the number of items
        if (curr) return nullptr;
    }

    // return the item value at the specified location
    return curr->val;
}