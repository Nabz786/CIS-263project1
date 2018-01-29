template <typename T>

/*****************************************************************
 * Almost Useless Data Structure (AUDS). This data structure will 
 * hold any type of object, through the use of a class template. 
 *
 * @author Runquan Ye, Nabeel Vali
 * @version Winter 2018
*****************************************************************/

class AUDS{

	public:
		
		/************************************************************************
    		 * This is the copy constructor. It will take as a parameter a reference 
		 * to another AUDS object and will perform a DEEP copy of the object.
    		 * @author: Runquan Ye 
    		 ***********************************************************************/		
		AUDS(const AUDS &other){
			initialSize = 100;
			currentSize = 0;
			currentMax = 100;
			data  = new T [initialSize]; 
		}	
		

		/************************************************************************
    		 * This is the copy operator=. It will perform the copy-and-swap we 
		 * learned about in class to set one object equal to another. It also 
		 * performs a DEEP copy.
    		 * @author: Nabeel Vali 
    		 ***********************************************************************/
		AUDS& operator = (AUDS other){
			

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
		
		}
	
	private:
		int initialSize;
		int currentSize;
		int currentMax;

		T* data;
};
