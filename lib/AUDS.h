template <typename T>
#include <stdlib.h> 

/*****************************************************************
 * Almost Useless Data Structure (AUDS). This data structure will 
 * hold any type of object, through the use of a class template. 
 *
 * @author Runquan Ye, Nabeel Vali
 * @version Winter 2018
*****************************************************************/

class AUDS{

	public:
	
		
		/***********************************************************************
		*Generic Constructor used when program is started to intialize our
		*generic array
		*@Author Jerry Ye	
		***********************************************************************/	
		AUDS(){
			initialSize = 100;
			currentSize = 0;
			currentMax = 100;
			data = new T[initialSize];
		}


		/************************************************************************
    		 * This is the copy constructor. It will take as a parameter a reference 
		 * to another AUDS object and will perform a DEEP copy of the object.
    		 * @author: Nabeel 
    		 ***********************************************************************/		
		AUDS(const AUDS &other){
			currentSize = other.currentSize;
			currentMax = other.currentMax;
			initialSize = other.currentSize;
			data = new std::string[currentMax]
			
			for(int i=0; i<currentMax; i++){ //figure out whether currentMAX or initialSize updates first so that we can get the new array size.
				data[i] = other.data[i];
			}
		}	
		

		/************************************************************************
    		 * This is the copy operator=. It will perform the copy-and-swap we 
		 * learned about in class to set one object equal to another. It also 
		 * performs a DEEP copy.
    		 * @author: Runquan Ye 
    		 ***********************************************************************/
		AUDS& operator = (AUDS other){
			std::swap(currentMax, other.currentMax);
			std::swap(currentSize, other.currentSize);
			std::swap(initialSize, other.initialSize);
			std::swap(data, other.data);
			return *this;
		};

		
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
    		 ***********************************************************************/
		int size(){
			int numItems = 0;
			for(int i=0; i<currentMax; i++){
				if(data[i] != null){//this condition may be invalid
					numItems++;
				}
			}
			return numItems;
		}
		

		/************************************************************************
    		 * Adds the generic element to the data structure.
    		 * @author: Nabeel Vali
    		 ***********************************************************************/
		void push(T e){

		}
		
		/************************************************************************
    		 * Removes a random item from the list. Moves the last item in the array 
		 * to the spot that was occupied by the element we removed.
		 * @author: Runquan Ye
    		 ***********************************************************************/
		T pop(){
			int ram = rand() %currentMax;
			delete data[ram];
			data[ram] = &data[currentMax - 1];
			data[currentMax - 1] = &data[currentMax - 2];  
		}
	
	private:
		/** Initial (starting) size of the array **/
		int initialSize;
	
		/** Current size of our array **/
		int currentSize;

		/** Current max size of the array **/
		int currentMax;

		/** Generic pointer to our array **/
		std::T* data;
}
