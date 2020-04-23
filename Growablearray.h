#ifndef __GROWABLEARRAY__
#define __GROWABLEARRAY__

#include "Array.h"
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class GrowableArray : public Array<T>{
    public :
            
        GrowableArray(int size):Array<T>(size){}
        
        T& operator[](int i){
            if(i >= this->len){
                int new_len = 2 * this->len;
                
                T *new_data = new T[new_len];
                
                int j;
                for(j = 0; j < new_len; j++){
                    new_data[j] = this->data[j];
                }
                for(j = this->len; j < new_len; j++){
                    new_data[j] = 0;
                }

                this->data = new_data;
                this->len = new_len;
                
                return this->data[i];
            }
            else if(i >= 0 && i < this->len){
                return this->data[i];
            }
            else{
                cout<<"Array bound error!"<<endl;
            }
        }
};



#endif
