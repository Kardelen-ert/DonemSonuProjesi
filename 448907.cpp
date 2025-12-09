#include <iostream>

using namespace std;


// Dynamic Array sınıfı:
class DynamicArray{
    private:
    int* data;
    int size;
    int capacity;

    void resize(){
        capacity *=2;
        int* newdata=new int(capacity);
        for(int i=0; i<size; i++){
            newdata[i]= data[i];
        
        delete[] data;
        data = newdata;
        }

    }

    public:
    DynamicArray(int cap = 2) {
        capacity = cap;
        size = 0;
        data = new int[capacity];
    }

    DynamicArray(const DynamicArray& other){
        capacity=other.capacity;
        size=other.size;
        data=new int(capacity);
        for(int i=0; i<size ;i++){
            data[i]=other.data[i];
        }

    }
    
    ~DynamicArray(){
        delete[] data;
    }

    void push(int value){
        if(size == capacity){
            resize();
        }
        data[size++]=value;
    }

    void pop(){
        if(size == 0){
            cout <<"Dizi bos, hata!"<<endl;
            return;
        }
        size--;
    }

    int get(int index){
        if(index < 0 || index >= size){
            cout << "Hatali index, lütfen düzelt."<< endl;
            return -1;

        }

        return data[index];
    }

    void set(int index, int value){
        if(index < 0 || index >= size){
            cout << "Hatali index, lütfen düzelt."<< endl;
            return;

        }
        value= data[index];
    }

    int getsize(){
        return size;
    }

    int getcapacity(){
        return capacity;
    }
       
    bool isempty(){
        return size == 0;
    }

     void clear(){
         size = 0; 
    }

     void print() {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

//Operatör overloading

 void print() {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    

};

int main(){

    return 0;

}


