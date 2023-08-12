#include<iostream>
using namespace std;
// for class
template <class T>
class Arithmetic
{
private:
    /* data */
    T a;
    T b;
public:
    Arithmetic(T a1, T b1);
    T add();
    T sub();
    // ~Arithmetic();
};

template <class T>
Arithmetic<T> :: Arithmetic(T a1, T b1)
{
    this->a = a1;
    this->b = b1;
}

template<class T>
T Arithmetic<T> :: add(){
    T c = a+b;
    return c;
}

template<class T>
T Arithmetic<T> :: sub(){
    T c = a-b;
    return c;
}

// template <class T>
// Arithmetic<T> :: ~Arithmetic()
// {
//     cout<<"Destructor of template class is called";
// }


// for function : for single datatype argument
template<class datatype>
datatype Add(datatype a, datatype b){
    return a+b;
}

// for function : for double datatype argument
template<class first, class second>
first Max(first a, second b){
    return a>b ? a:b;
}


// template class
template<class Temp>
class charFinder{
    public:
    charFinder(Temp a){
        cout<<a<<" is a not valid char"<<endl;
    }
};

// specialized class of above template class
template<>
class charFinder<char>{
    public:
    charFinder(char a){
        cout<<a<<" is a valid char"<<endl;
    }
};



int main(){
    Arithmetic<int> a(10,5);
    cout<<"Sum: "<<a.add()<<endl;
    cout<<"Substraction: "<<a.sub()<<endl;

    Arithmetic<float> a1(10.5,5.6);
    cout<<"Sum: "<<a1.add()<<endl;
    cout<<"Substraction: "<<a1.sub()<<endl;


    // for function
    double x = 5.5, y = 4.55;
    cout<<"Addition of x & y : "<<Add(x,y)<<endl;

    // for function having different typed parameters
    double x1 = 5.5;
    int y1 = 6;
    cout<<"max in of x1 & y1 : "<<Max(x1,y1)<<endl;

    // template class & specialized class
    charFinder<char> ch('a');
    charFinder<int> i(23);
    charFinder<float> f(33.11);
}