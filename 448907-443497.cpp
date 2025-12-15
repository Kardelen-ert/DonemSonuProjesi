#include <iostream>
#include <stdexcept>
using namespace std;



// -------- DynamicArray --------
class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

protected:
    void resize();

public:
    DynamicArray(int cap = 2);
    DynamicArray(const DynamicArray& other);
    virtual ~DynamicArray();

    virtual void push(int value);
    void pop();

    int get(int index) const;
    void set(int index, int value);

    int getSize() const;
    int getCapacity() const;
    bool isEmpty() const;

    void clear();
    void print() const;

    int& operator[](int index);
    DynamicArray operator+(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    bool operator==(const DynamicArray& other) const;
    bool operator!=(const DynamicArray& other) const;

    friend ostream& operator<<(ostream& os, const DynamicArray& arr);
};

// SortedArray Tanımı
class SortedArray : public DynamicArray {
public:
    SortedArray(int cap = 2);
    void push(int value) override;
    int binarySearch(int value) const;
};

// UniqueArray Tanımı
class UniqueArray : public DynamicArray {
public:
    UniqueArray(int cap = 2);
    bool contains(int value) const;
    void push(int value) override;
};


int main() {

    cout << "===== DynamicArray =====" << endl;
    DynamicArray a;
    a.push(15);
    a.push(17);
    a.push(30);
    a.print();

    a[1] = 13;
    cout << "a[1] = " << a[1] << endl;

    DynamicArray b;
    b.push(89);
    b.push(100);

    DynamicArray c = a + b;
    c.print();

    cout << "\n===== SortedArray =====" << endl;
    SortedArray s;
    s.push(100);
    s.push(89);
    s.push(87);
    s.push(40);
    s.print();
    cout << "89 index: " << s.binarySearch(89) << endl;

    cout << "\n===== UniqueArray =====" << endl;
    UniqueArray u;
    u.push(10);
    u.push(28);
    u.push(95);
    u.push(70);
    u.print();
    cout << "95 var mi? ";
    if (u.contains(95)) {
        cout << "Evet";
    } else {
        cout << "Hayir";
    }
        cout << endl;

    return 0;
}



//  DynamicArray Metot Kodları
void DynamicArray::resize() {
    capacity *= 2;
    int* newData = new int[capacity];
    for (int i = 0; i < size; i++)
        newData[i] = data[i];
    delete[] data;
    data = newData;
}

DynamicArray::DynamicArray(int cap) {
    capacity = cap;
    size = 0;
    data = new int[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    capacity = other.capacity;
    size = other.size;
    data = new int[capacity];
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::push(int value) {
    if (size == capacity)
        resize();
    data[size++] = value;
}

void DynamicArray::pop() {
    if (size == 0) {
        cout << "Dizi bos!" << endl;
        return;
    }
    size--;
}

int DynamicArray::get(int index) const {
    if (index < 0 || index >= size)
        throw out_of_range("Hatali indeks");
    return data[index];
}

void DynamicArray::set(int index, int value) {
    if (index < 0 || index >= size)
        throw out_of_range("Hatali indeks");
    data[index] = value;
}

int DynamicArray::getSize() const { return size; }
int DynamicArray::getCapacity() const { return capacity; }
bool DynamicArray::isEmpty() const { return size == 0; }

void DynamicArray::clear() { size = 0; }

void DynamicArray::print() const {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;
}


//Operatörler
int& DynamicArray::operator[](int index) {
    if (index < 0 || index >= size)
        throw out_of_range("Hatali indeks");
    return data[index];
}

DynamicArray DynamicArray::operator+(const DynamicArray& other) {
    DynamicArray temp(size + other.size);
    for (int i = 0; i < size; i++)
        temp.push(data[i]);
    for (int i = 0; i < other.size; i++)
        temp.push(other.data[i]);
    return temp;
}
DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this == &other) return *this;

    delete[] data;
    capacity = other.capacity;
    size = other.size;
    data = new int[capacity];
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];

    return *this;
}

bool DynamicArray::operator==(const DynamicArray& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; i++)
        if (data[i] != other.data[i]) return false;
    return true;
}

bool DynamicArray::operator!=(const DynamicArray& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const DynamicArray& arr) {
    os << "[";
    for (int i = 0; i < arr.size; i++) {
        os << arr.data[i];
        if (i < arr.size - 1) os << ", ";
    }
    os << "]";
    return os;
}

// SortedArray 
SortedArray::SortedArray(int cap) : DynamicArray(cap) {}

void SortedArray::push(int value) {
    DynamicArray::push(value);
    int i = getSize() - 1;
    while (i > 0 && get(i) < get(i - 1)) {
        int temp = get(i);
        set(i, get(i - 1));
        set(i - 1, temp);
        i--;
    }
}

int SortedArray::binarySearch(int value) const {
    int left = 0, right = getSize() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int midVal = get(mid);
        if (midVal == value) return mid;
        else if (midVal < value) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

//  UniqueArray 
UniqueArray::UniqueArray(int cap) : DynamicArray(cap) {}

bool UniqueArray::contains(int value) const {
    for (int i = 0; i < getSize(); i++)
        if (get(i) == value)
            return true;
    return false;
}

void UniqueArray::push(int value) {
    if (contains(value)) {
        cout << value << " zaten dizide, eklenmedi." << endl;
        return;
    }
    DynamicArray::push(value);
}
