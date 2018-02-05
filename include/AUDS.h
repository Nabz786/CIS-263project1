#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>

/*****************************************************************
 * Almost Useless Data Structure (AUDS). This data structure will 
 * hold any type of object, through the use of a class template. 
 *
 * @author Runquan Ye, Nabeel Vali
 * @version Winter 2018
*****************************************************************/

template <typename T>

class AUDS{

	public:		
		/***********************************************************************
		*Generic Constructor used when program is started to intialize our
		*generic array
		*@Author Runquan Ye, Nabeel Vali	
		***********************************************************************/	
		AUDS(){
			currentSize = 0;
			currentMax = 100;
			data = new T[currentMax];
		}

		/************************************************************************
    		 * This is the copy constructor. It will take as a parameter a reference 
		 * to another AUDS object and will perform a DEEP copy of the object.
    		 * @author: Nabeel 
    		 * @return: Deep copy of the another data structure to this one
    		 ***********************************************************************/		
		AUDS(const AUDS &other){
			currentSize = other.currentSize;
			currentMax = other.currentMax;
			data = new T[currentMax];
			
			for(int j = 0; j<currentMax; j++){ 
				data[j] = other.data[j];
			}
		}	
		

		/************************************************************************
    		 * This is the copy operator=. It will perform the copy-and-swap we 
		 * learned about in class to set one object equal to another. It also 
		 * performs a DEEP copy.
    		 * @author: Runquan Ye 
    		 * @return: the newly copyed data structure
    		 ***********************************************************************/
		AUDS& operator = (AUDS other){
			std::swap(currentMax, other.currentMax);
			std::swap(currentSize, other.currentSize);
			std::swap(data, other.data);
			return *this;
		}

		
		/************************************************************************
    		 * This is the destructor. It will give back any memory we borrowed from 
		 * the OS to hold the data we stored.
		 * @author: Runquan Ye
    		 ***********************************************************************/
	        ~AUDS(){
			delete[] data;	
		}
		
		
		/************************************************************************
    		 * Returns the current number of objects we are holding.
    		 * @author: Nabeel Vali
    		 * @return: int the size/number of objects in the structure
    		 **********************************************************************/
		int size(){
			return currentSize;
		}
	
		/************************************************************************
    		 * Adds the generic element to the data structure. If the array is full 
    		 * we recreate the array making it 50% larger
    		 * @author: Nabeel Vali
    		 ***********************************************************************/
		void push(T e){
			if(currentSize == currentMax){
				doubleArraySize();
				data[currentSize] = e;
				currentSize++;
			}
			else{
				data[currentSize] = e;
				currentSize++;
			}
		}
		
		/************************************************************************
    		 * Removes a random item from the list. Moves the last item in the array 
		 * to the spot that was occupied by the element we removed.
		 * @author: Runquan Ye & Nabeel 
		 * @return: T the popped object
    		 ***********************************************************************/
		T pop(){
			if(currentSize == 0){
				throw "No elements are left to pop";
			}
			else{
				T temp;
				int randomIndex = rand()%currentSize;
				temp =  data[randomIndex];
				data[randomIndex] = data[currentSize];
				currentSize -= 1;  
				return temp;
			}
		}
	
	private:
		/** Initial (starting) size of the array **/
		int initialSize;
	
		/** Current size of our array **/
		int currentSize;

		/** Current max size of the array **/
		int currentMax;

		/** Generic pointer to our array **/
		T* data;
		

		/*************************************************************************
		*created a new array 50% larger, and re-points the pointer
		*This method should be private as it should only be called on one
		*condition in the push() method
                *@Author Nabeel
                ************************************************************************/
                void doubleArraySize(){
                        T* newData = new T[(int)(currentMax * 1.5)];
                        for(int i = 0; i < currentMax; i++){
                                newData[i] = data[i];
                        }
                        delete[] data;
                        data = newData;
                        currentMax = (int)(currentMax * 1.5);
                }
};
