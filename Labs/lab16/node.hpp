#pragma once

template <typename T>
struct Node {
    T *d1, *d2, *d3;
    Node *n1, *n2, *n3, *n4;

    Node(T* v): d1(v), d2(nullptr), d3(nullptr), n1(nullptr), n2(nullptr), n3(nullptr), n4(nullptr){}
    Node(T* v1, T* v2, T* v3, Node* nd1, Node* nd2, Node* nd3, Node* nd4): 
        d1(v1), d2(v2), d3(v3), n1(nd1), n2(nd2), n3(nd3), n4(nd4){}
    
    bool hasData(const T* d) const{
        if (!d)
            return false;
        return (d1 && *d1 == *d) || (d2 && *d2 == *d) || (d3 && *d3 == *d);
    }

    bool isLeaf() const{
        return !n1 && !n2 && !n3 && !n4;
    }

    unsigned short nAllocatedData() const{
        if (d3) return 3;
        if (d2) return 2;
        if (d1) return 1;
        return 0;
    }
    void deleteData(){
        if (d1) delete d1;
        if (d2) delete d2;
        if (d3) delete d3;
    }
};