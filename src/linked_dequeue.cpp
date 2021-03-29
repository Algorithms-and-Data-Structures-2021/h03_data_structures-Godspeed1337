#include "linked_dequeue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedDequeue::Enqueue(Element e) {
  // TODO: напишите здесь свой код ...
  auto* node = new DoublyNode(e, nullptr, back_);

  if (size_ == 0){
    front_ = node;
    back_ = node;
  } else {
    back_->previous = node;
    back_ = node;
  }
  size_ ++;
}

void LinkedDequeue::EnqueueFront(Element e) {
  // TODO: напишите здесь свой код ...
  auto* node = new DoublyNode(e, nullptr, back_);

  if (size_ == 0){
    front_ = node;
    back_ = node;
  } else {
    front_->next = node;
    front_ = node;
  }
  size_ ++;
}

void LinkedDequeue::Dequeue() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }
  // TODO: напишите здесь свой код ...
  if (size_ == 1){
    DoublyNode * del_node = front_;
    front_ = nullptr;
    back_ = nullptr;
    delete del_node;
  }
  if (size_ > 1){
    DoublyNode *del_node = front_;
    front_ = front_->previous;
    delete del_node;
    front_->next = nullptr;
  }
  size_ --;
}

void LinkedDequeue::DequeueBack() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }

  // TODO: напишите здесь свой код ...
  if (size_ == 1){
    DoublyNode * del_node = front_;
    front_ = nullptr;
    back_ = nullptr;
    delete del_node;
  }
  if (size_ > 1){
    DoublyNode *del_node = back_;
    back_ = back_->next;
    delete del_node;
    back_->previous = nullptr;
  }
  size_ --;
}

void LinkedDequeue::Clear() {
  // TODO: напишите здесь свой код ...
  for (DoublyNode *curr_node = front_; curr_node != nullptr; ){
    auto delete_node = curr_node;
    curr_node = curr_node->previous;
    delete delete_node;
  }
  front_ = nullptr;
  back_ = nullptr;
  size_ = 0;

}

// === РЕАЛИЗОВАНО ===

LinkedDequeue::~LinkedDequeue() {
  Clear();
}

std::optional<Element> LinkedDequeue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedDequeue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedDequeue::IsEmpty() const {
  return size_ == 0;
}

int LinkedDequeue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedDequeue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->previous) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis
