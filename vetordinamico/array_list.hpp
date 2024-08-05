#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__

class array_list {
private:
  int *data;
  unsigned int size_, capacity_;
  void increase_capacity() {
    capacity_+= capacity_ * 2;
    int *novo = new int[capacity_];
    for (int i = 0; i < size_; i++){
      novo[i] = data[i];
    }
    data = novo;
    delete[] novo;
  }

public:
  array_list() {
    data = new int[0];
    this->size_ = 0;
    this->capacity_ = 0;
  }

  ~array_list() { delete[] data; }

  unsigned int size() { return this->size_; }

  unsigned int capacity() { return this->capacity_; }

  double percent_occupied() {
    if (this->capacity_ == 0)
      return 0.0;
    return (static_cast<double>(size_) / this->capacity_) * 100.0;
  }

  bool insert_at(unsigned int index, int value) {
    int retorno = -1;
    if (index > size_) {
      return retorno;
    }
    if (size_ == capacity_) {
      increase_capacity();
    }
    // Move os elementos a partir do índice para a direita
    for (unsigned int i = size_; i > index; --i) {
      data[i] = data[i - 1];
    }
    // Insere o novo elemento
    data[index] = value;
    ++size_;
    return true;
  }

  bool remove_at(unsigned int index) {    // 1 2 3 4 5
    if (index >= this->size_)
      return false; // NÃ£o removeu
    for (unsigned int i = index + 1; i < this->size_; ++i) {
      this->data[i - 1] = this->data[i];
    }
    this->size_--;
    return true; // Removeu
  }

  int get_at(unsigned int index) {
    // TODO: Check if index is valid
    return this->data[index];
    if (index >= 0 && index < size_) {
      return data[index];
    }
  }

  void clear() {
    this->size_ = 0;
    this->capacity_ = 0;
    delete[] data;
    this->data = new int[capacity_];
  }

  void push_back(int value) {
    if (this->size_ == this->capacity_)
      increase_capacity();
    this->data[size_++] = value;
  }

  void push_front(int value) {
    if (this->size_ == this->capacity_) {
      increase_capacity();
    }
    for (unsigned int i = this->size_; i > 0; --i) {
      data[i] = data[i - 1];
    }
    data[0] = value;
    size_++; // this->size_++;
  }

  bool pop_back() {
    if (size_ == 0) {
      return false;
    }
    --size_;
    return true;
  }

  bool pop_front() {
    if (size_ == 0) {
      return false;
    }
    for (unsigned int i = 0; i < this->size_ - 1; ++i) {
      data[i] = data[i + 1];
    }
    --size_;
    return true;
  }

  int front() {
    int retorno = -1;
    if (size_ > 0) {
      retorno = data[0];
    }
    return retorno;
  }

  int back() {
    int retorno = -1;
    if (size_ > 0) {
      retorno = data[size_ - 1];
    }
    return retorno;
  }

  bool remove(int value) {
    int index = find(value);
    if (index == -1) {
      return false;
    }
    for (unsigned int i = index; i < size_ - 1; ++i) {
      data[i] = data[i + 1];
    }
    --size_;
    return true;
  }

  int find(int value) {
    for (unsigned int i = 0; i < this->size_; i++) {
      if (this->data[i] == value) {
        return i;
      }
    }
    return -1;
  }

  int count(int value) { // Conta quantos valores se tem dentro da array
    int count = 0;
    for (unsigned int i = 0; i < this->size_; i++) {
      if (data[i] == value) {
        count++;
      }
    }
    return count;
  }

  int sum() { // Soma todos os valores dentro da array
    int sum = 0;
    for (unsigned int i = 0; i < this->size_; i++) {
      sum = sum + this->data[i];
    }
    return sum;
  }
};

#endif // __ARRAY_LIST_IFRN__