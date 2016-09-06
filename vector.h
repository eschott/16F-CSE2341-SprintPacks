#ifndef VECTOR
#define VECTOR

#include<iostream>

template<class T>
class Vector{

  public:

      Vector();                         //default constructor
      Vector(int);                      //constructor given a specific size
      Vector(const Vector<T>&);         //copy constructor

      void add(T);                      //adds the object to the end of the vector
      void add(T, int);                 //adds the object to the position specified
      void remove(int);                 //removes element from position specified
      T get(int);                       //returns the object in the location given


      ~Vector();

      int size();                       //returns the number of elements in the vector
      void sort();                      //sorts numecically using > operator
      void revSort();                   //sorts revers numerically using > operator

      T& operator[](int);               //retrives a certain element in the vector
      Vector<T>& operator=(Vector<T>&); //asigns the vector to the values of another
      Vector<T>& operator+=(T);         //adds an element to the vector

      bool operator== (Vector<T>&);     //compares two vectors and their elements
      bool operator!= (Vector<T>&);

  private:

      void resize();                    //returns unused memory
      void resize(int);                 //changes size to a specific amount

      T** data;                         //pointer to array of data
      int len;                         //number of elements in vector
      int cap;                          //capacity of the vector in it's current state

};

#endif
