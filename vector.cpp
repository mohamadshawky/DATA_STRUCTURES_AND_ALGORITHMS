//main.cpp

#include "iostream"

#include <vector>
#include <string>

#define VECTOR					0
#define CODE_GEN_FN_LIKE_MACRO	0
#define CODE_GEN_STL			0

/************* Function like MACRO *************/
//code generation:
	// 1. Not safe: no type check by complier (no safety), all is text replacement by pre-processor
	// 2. Manual coding	so very error promotion
#define _add(TYPE)\
TYPE 	add(TYPE a, TYPE b)\
{\
return a+b;\
}

_add(int)
_add(std::string)

/************** Template ***************/
template <typename TYPE>
TYPE add(TYPE a, TYPE b)
{
return a+b;
}

template <typename TYPE, int SIZE>
class cArray{
	private:
		TYPE array[SIZE];
	public:
		TYPE& operator [](int index){
			return array[index];
		}
		
};
int main(){
	
#if VECTOR
	std::vector<int> v (5);
	
	// for (int i = 0; i < 10; i++){
		// v.push_back((i+1) * (i+1));			// = append in smart array
	// }
	
	// for(int i = 0; i < v.size(); i++){
		// std::cout << v[i] << ' ';
	// }
	// std::cout << std::endl;
	// for (int i = 0; i < 5; i++){
		// v.at(i) = ((i+1) * (i+1));			// at() check on capacity and throw an exception.
	// }
	// for(int i = 0; i < v.size(); i++){
		// std::cout << v[i] << ' ';
	// }
	
	
	// for i in renge (5):			//in python
	
	// for (std::vector<int>::iterator it = v.begin(); it <v.begin()+5 ; it++){	//iterator object is pointer instead of index
		// it = v.insert(it, 200);
	// }
		
	// for (std::vector<int>::iterator it = v.begin(); it <v.end() ; it++){	//iterator object is pointer instead of index
		// std::cout << *it << std::endl;
	// }

#endif

#if CODE_GEN_FN_LIKE_MACRO
	int x = add(5,6);
	std::string z = add("Mohamed", "Shawky");

	std::cout << x << std::endl;
	std::cout << z << std::endl;
#endif

#if CODE_GEN_STL
	/* Function Template */
	// std::cout << add(5,6) << std::endl	
				// << add(5.5, 3.25) << std::endl	
				// //<< add ("Mohamed ", "Shawky")																		// ERROR
				// << add (static_cast<std::string>("Mohamed "), static_cast<std::string>("Shawky")) << std::endl		//casting
				// <<add<std::string>("Mohamed ", "Shawky");															//specified type tp template
	/* Array Template */			
	cArray<int, 10> arr;
	for (int i = 0; i < 10 ; i++){
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++){
		std::cout << arr[i] << ' ';
	}	
		
#endif 
}