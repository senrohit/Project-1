/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDataBaseSortableByName.h
 * Author: Justin
 *
 * Created on February 23, 2018, 11:21 AM
 */

#ifndef PETDATABASESORTABLEBYNAME_H
#define PETDATABASESORTABLEBYNAME_H

#include "Pet.h"
#include "PetDatabaseSortable.h"

class PetDatabaseSortableByName: public PetDatabaseSortable {
public:
    //constructor
    PetDatabaseSortableByName(vector<Pet*> petVec) {
        _petVec = petVec;
    }
    //destructor
    ~PetDatabaseSortableByName() {}
    //Display all record
    virtual void DisplayRecords() const {
        for (int i = 0; i < _petVec.size(); ++i) {
            _petVec[i]->print();
        }
    }
    // returns the vector for use in Searchable class
    vector<Pet*> getVector() const{
        return _petVec;
    }
protected:
    //member variable of a vector of pet pointers
    vector<Pet*> _petVec;
    
    //get size of _petVec
    virtual unsigned int getSize() const {
        return _petVec.size();
    }
    //compare two names
    virtual bool smaller(int i, int j) const {
        return _petVec[i]->GetName() < _petVec[j]->GetName();
    }
    //swap two entries
    virtual void swap(int i, int j) {
        Pet* temp = _petVec[i];
        _petVec[i]= _petVec[j];
        _petVec[j] = temp;
    }
};



#endif /* PETDATABASESORTABLEBYNAME_H */

