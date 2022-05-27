#ifndef RING_H_
#define RING_H_


using namespace std;


template<class T>
class ring{

    private:

    size_t m_size;
    int pos;
    T *list;

    public:

    class iterator;

    ring(size_t size):m_size(size),pos(0){
        list = new T[m_size];
    }

    ~ring(){
        delete []list;
    }

    void add(T value){
        list[pos++] = value;
        if(pos>=m_size)
            pos=0;
    }

    T& get(int index){
        //if(index<0 || index>=m_size)
            //return T();
        return list[index];
    }

    size_t size(){
        return m_size;    
    }

    iterator begin(){
        return iterator(0,*this);
    }

    iterator end(){
        return iterator(m_size,*this);
    }


};

template<class T>
class ring<T>::iterator{

    private:

    int index;
    ring &m_ring;

    public:

    iterator(int index,ring &own):index(index),m_ring(own){
        
    }

    iterator & operator++(int){
        index++;
        return (*this);
    }
    iterator & operator++(){
        ++index;
        return (*this);
    }

    bool operator!=(iterator other){
        return index!=other.index;
    }

    T &operator*(){
        return m_ring.get(index);
    }

    private:



};




#endif RING_H_