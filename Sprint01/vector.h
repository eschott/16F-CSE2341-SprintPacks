#ifndef VECTOR
#define VECTOR

#include<iostream>

template<class T>
class Vector{

  public:

      Vector();
      Vector(int);
      Vector(const Vector<T>&);

      void add(T);
      void add(T, int);
      T get(int);

      ~Vector();

      int size();
      void sort();

      T& operator[](int);
      Vector<T>& operator=(Vector<T>&);
      Vector<T>& operator+=(T);

  private:

      void resize();

};

#endif
