#include <iostream>

using namespace std;


// Dynamic Array sınıfı:
class DynamicArray{
    private:
    int* data;
    int size;
    int capacity;

    protected:
    void resize();

    public:
    DynamicArray(int cap = 2);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();
    virtual void push(int value);
    void pop();
    int get(int index);
    void set(int index, int value);
    int getSize();
    int getCapacity();
    bool isEmpty();
    void clear();
    void print();

    int& operator[](int index);
    const int& operator[](int index) const;
    DynamicArray operator+(const DynamicArray& other) const;
    DynamicArray& operator=(const DynamicArray& other);
    bool operator==(const DynamicArray& other) const;
    bool operator!=(const DynamicArray& other) const;

    friend ostream& operator<<(ostream& os, const DynamicArray& arr);
};
//Sorted Array tanımı
class SortedArray:public DynamicArray{
    public:
    SortedArray();
    SortedArray(int cap);
    void push(int value) override;
    int binarySearch(int value);
};

//Unique Array tanımı
class UniqueArray:public DynamicArray{
    public:
    UniqueArray();
    UniqueArray(int cap);
    void push(int value) override;
    bool contains(int value);

};

//Operatör overloading
int main(){
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
//Köşeli Parantez Operatörü(diziden doğrudan alınacak)
int& DynamicArray::operator[](int index) {
    if (index < 0 || index >= size)
        throw out_of_range("Hatali indeks");
    return data[index];
}
//Artı Operatörü(iki diziyi birleştiriri)
DynamicArray DynamicArray::operator+(const DynamicArray& other) const {
    DynamicArray temp(size + other.size);
    for (int i = 0; i < size; i++)
        temp.push(data[i]);
    for (int i = 0; i < other.size; i++)
        temp.push(other.data[i]);
    return temp;
}
//Atama operatörü
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

//Eşitlik Kontrolu yapılır.
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

//DynamicArray method kodları

//Dizinin kapasitesi iki katına çıkarır.
void DynamicArray::resize(){
        capacity *=2;
        int* newdata=new int[capacity];
        for(int i=0; i<size; i++){
            newdata[i]= data[i];
        
       
        }
         delete[] data;
        data = newdata;

    }

DynamicArray::DynamicArray(int cap ) {
        capacity = cap;
        size = 0;
        data = new int[capacity];
    }    
//Copy Constructor
DynamicArray::DynamicArray(const DynamicArray& other){
        capacity=other.capacity;
        size=other.size;
        data=new int[capacity];
        for(int i=0; i<size ;i++){
            data[i]=other.data[i];
        }
    }
 
DynamicArray::~DynamicArray(){
        delete[] data;
    }

//Eleman ekleme yapar.
void DynamicArray::push(int value){
        if(size == capacity){
            resize();
        }
        data[size++]=value;
    }   

//Son elemanı siler.
void DynamicArray::pop(){
        if(size == 0){
            cout <<"Dizi bos, hata!"<<endl;
            return;
        }
        size--;
    }

int DynamicArray::get(int index){
        if(index < 0 || index >= size){
            cout << "Hatali index, lütfen düzelt."<< endl;
            return -1;

        }

        return data[index];
    }

void DynamicArray::set(int index, int value){
        if(index < 0 || index >= size){
            cout << "Hatali index, lütfen düzelt."<< endl;
            return;

        }
        data[index]=value;
    }

int DynamicArray::getSize(){
        return size;
    }
    
int DynamicArray::getCapacity(){
        return capacity;
    }
    
bool DynamicArray::isEmpty(){
        return size == 0;
    }    
    
void DynamicArray::clear(){
         size = 0; 
    }

void DynamicArray::print() {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]" << endl;
    } 


//SortedArray method kodları

SortedArray::SortedArray():DynamicArray(){}
SortedArray::SortedArray(int cap):DynamicArray(cap){}

void SortedArray::push(int value){
    
    DynamicArray::push(0);     

    int pos = getSize() - 1;
    while (pos>0 && get(pos-1)>value) {    
        set(pos,get(pos-1));                  //0 yerine ondan önceki eleman yazılıyor
        pos--;
    }
    DynamicArray::set(pos, value);                             // value öncekinden büyük ise yerleştir
}

int SortedArray::binarySearch(int value){
    int left=0;
    int right=getSize()-1; 
    while (left<=right) {
        int mid=(left + right)/2; 
        int midVal=get(mid);
        if (midVal==value){
            return mid;
        }
        if (midVal<value){                 
            left=mid+1;
        }                                     //ortadaki değerden büyükse sağa küçükse sola bak
        if (midVal>value){ 
            right=mid-1;
        }
    }
    return -1; 
}

//UniqueArray method kodları

UniqueArray::UniqueArray():DynamicArray(){}
UniqueArray::UniqueArray(int cap):DynamicArray(cap){}

bool UniqueArray::contains(int value) {
    for (int i=0;i<getSize();i++) {
        if (get(i)==value) {
            return true; 
        }
    }
    return false; 
}

void UniqueArray::push(int value) {
    if (contains(value)) { 
        cout<<value<<" dizide zaten olduğu için eklenemedi."<<endl;
        return;
    }
    DynamicArray::push(value);
}
