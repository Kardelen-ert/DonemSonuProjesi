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
};
//Sorted Array tanımı
class SortedArray:public DynamicArray{
    public:
    SortedArray();
    SortedArray(int cap);
    ~SortedArray();
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

    return 0;
}

//DynamicArray method kodları
void DynamicArray::resize(){
        capacity *=2;
        int* newdata=new int(capacity);
        for(int i=0; i<size; i++){
            newdata[i]= data[i];
        
        delete[] data;
        data = newdata;
        }

    }

DynamicArray::DynamicArray(int cap = 2) {
        capacity = cap;
        size = 0;
        data = new int[capacity];
    }    

DynamicArray::DynamicArray(const DynamicArray& other){
        capacity=other.capacity;
        size=other.size;
        data=new int(capacity);
        for(int i=0; i<size ;i++){
            data[i]=other.data[i];
        }
    }
 
DynamicArray::~DynamicArray(){
        delete[] data;
    }
 
void DynamicArray::push(int value){
        if(size == capacity){
            resize();
        }
        data[size++]=value;
    }   

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
        value= data[index];
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
    
    if (getSize() >= getCapacity()) {   //size ve cap priv olduğu için fonksiyonları kullanıyoruz
        resize();                        
    }

    DynamicArray::push(0);     

    int pos = getSize() - 1;
    while (pos>0 && get(pos-1)>value) {    
        set(pos,get(pos-1));                  //0 yerine ondan önceki eleman yazılıyor
        pos--;
    }
    set(pos, value);                             // value öncekinden büyük ise yerleştir
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
        }                                     //oratdaki değerden büyükse sağa küçükse sola bak
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
