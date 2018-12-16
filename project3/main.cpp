//
//  main.cpp
//  project3
//
//  Created by Umut Avin on 15.12.2018.
//  Copyright © 2018 avin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
int size = 17863;

class Element{
public:
    int index;
    string text;
};


int h1(int k, int i){
    return (k+i)%size;
}

int h2a(int k){
    return k%size;
}

int h2b(int k){
    int p=13421;
    return p-(k%size);
}

int h2(int k, int i){
    return (h2a(k)+h2b(k)*i)%size;
}

int h3(int k, int i){
    int sum=0;
    int m=17863;
    int a[3] = {253, 1412,5353};
    for (int r=2; r>-1; r--){
        sum = sum + (k%100)*a[r];
        k = k/100;
    }
    //cout << sum << "    " << a << endl;
    sum = (sum+i)%m;
    return sum;
}

void insertTable1(Element arr[], int k, int i, string v){
    arr[h1(k,i)].text = v;
    arr[h1(k,i)].index = k;
}

void insertTable2(Element arr[], int k, int i, string v){
    arr[h2(k,i)].text = v;
    arr[h2(k,i)].index = k;
}

void insertTable3(Element arr[], int k, int i, string v){
    arr[h3(k,i)].text = v;
    arr[h3(k,i)].index = k;
}
Element* BuildTable1(){
    Element* array = new Element[size];
    int j=0;
    while(j<13423){
        array[j].index = -1;
        j++;
    }
    
    int lineCount=0;
    int i = 0;
    string temp;
    ifstream input("vocab.txt", ifstream::in);
    if (!input.is_open()) {
        cout << endl << "File cannot be loaded!" << endl;
    }
    
    while(!input.eof()){
        getline(input, temp, '\n');
        if(array[h1(lineCount,i)].index != -1){
            i++;
        }
        insertTable1(array, lineCount, i, temp);
        lineCount++;
        
    }
    input.close();
    input.clear();
    j=0;
    
    /*while(j<size){
        cout << array[j].index << " " << array[j].text << endl;
        j++;
    }*/
    
    cout << "Insert collision 1: " << i << endl;

    return array;
}

Element* BuildTable2(){
    Element* array = new Element[size];
    int j=0;
    while(j<13423){
        array[j].index = -1;
        j++;
    }
    
    int lineCount=0;
    int i = 0;
    string temp;
    ifstream input("vocab.txt", ifstream::in);
    if (!input.is_open()) {
        cout << endl << "File cannot be loaded!" << endl;
    }
    
    while(!input.eof()){
        getline(input, temp, '\n');
        if(array[h2(lineCount,i)].index != -1){
            i++;
        }
        insertTable2(array, lineCount, i, temp);
        lineCount++;
        
    }
    input.close();
    input.clear();
    j=0;
    
    /*while(j<size){
        cout << array[j].index << " " << array[j].text << endl;
        j++;
    }*/
    
    cout << "Insert collision 2: " << i << endl;

    return array;
    
}

Element* BuildTable3(){
    Element* array = new Element[size];
    int collision=0;
    int j=0;
    while(j<size){
        array[j].index = -1;
        j++;
    }
    
    int lineCount=0;
    int i = 0;
    string temp;
    ifstream input("vocab.txt", ifstream::in);
    if (!input.is_open()) {
        cout << endl << "File cannot be loaded!" << endl;
    }
    
    while(!input.eof()){
        i=0;
        getline(input, temp, '\n');
        while(array[h3(lineCount, i)].index != -1){
            i++;
            collision++;
            //cout << i << "   " << lineCount << "  " << temp << "   " << array[h3(lineCount, i)].index << endl;
            
        }
        insertTable3(array, lineCount, i, temp);
        lineCount++;
    }
    input.close();
    input.clear();
    j=0;
    
    /*while(j<size){
        cout << array[j].index << " " << array[j].text << endl;
        j++;
    }*/
    
    cout << "Insert collision 3: " << collision << endl;
    return array;
    
    
}

int search1(Element arr[]){
    Element* array = new Element[size];
    array = arr;
    int collision=0;
    int i = 0;
    int lineCount=0;
    
    string temp;
    ifstream searchFile("search.txt", ifstream::in);
    if (!searchFile.is_open()) {
        cout << endl << "File cannot be loaded!" << endl;
    }
    while(!searchFile.eof()){
        i=0;
        getline(searchFile, temp, '\n');
        if(array[h1(lineCount,i)].index != -1){
            i++;
        }
        
        /*if(array[j].text == temp && array[j].index != 0){
            
            //cout << array[j].index << " -- " << array[j].text << endl;
        }*/
        lineCount++;
        
    }
    return collision;
}

int search2(Element arr[]){
    Element* array = new Element[size];
    array = arr;
    int collision=0;
    int i = 0;
    int lineCount=0;
    
    string temp;
    ifstream searchFile("search.txt", ifstream::in);
    if (!searchFile.is_open()) {
        cout << endl << "File cannot be loaded!" << endl;
    }
    while(!searchFile.eof()){
        i=0;
        getline(searchFile, temp, '\n');
        if(array[h2(lineCount,i)].index != -1){
            i++;
        }
        lineCount++;
        
    }
    return collision;
}

int search3(Element arr[]){
    Element* array = new Element[size];
    array = arr;
    int collision=0;
    int j = 0;
    int i = 0;
    int lineCount=0;
    
    string temp;
    ifstream searchFile("search.txt", ifstream::in);
    if (!searchFile.is_open()) {
    cout << endl << "File cannot be loaded!" << endl;
    }
    while(!searchFile.eof()){
        i=0;
        getline(searchFile, temp, '\n');
        while(array[h3(lineCount, i)].text != temp){
            collision++;
            i++;
        }
        if(array[j].text == temp && array[j].index != 0){
            //cout << array[j].index << " -- " << array[j].text << endl;
        }
        lineCount++;
        
    }
    return collision;
}


int main() {
    Element* arr = new Element[size];
    arr = BuildTable1();
    int col = search1(arr);
    cout << "Search 1 Collision: " << col << endl;
    
    arr = BuildTable2();
    col = search2(arr);
    
    cout << "Search 2 Collision: " << col << endl;

    
    arr = BuildTable3();
    col = search3(arr);
    
    cout << "Search 3 Collision: " << col << endl;

    
    return 0;
}
