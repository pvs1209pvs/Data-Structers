# Data_Structures_C
My personal implementation for the following data structures. 
* Dynmaic Array
* Stack
* Set
* Priority Queue
* Graph
* Map <br/><br/>
Every data structure must be initalized using _data_strucutre_implementation_init(&data_structure, data_type_size, initial_capacity)_<br/><br/>
All the data structure are designed to hold any data type(including user defined). User has to careful as any single data structure can hold different data types as there is no restriction on one data structure being able to hold one single data type. Data type size governs how much memory needs to be allocated on the heap for one single element. <br/><br/>
Elements' address needs to be passed as the argument wherever required as void* is used to hold the address of any data type which lets all the data structure hold any data type as the user desires. 

### Dynamic Array
There are two implmentation for Dyanmic Array
* **Contigous**: Eelements are sorted in an array and the size of the array doubles when the max capacity is reached.
* **Linked**: Elements are malloced before they are added to the list and pointer is maintained for the first element. Size of the list increases by one after each addition.
  
Dynamic Array: linked, array
Priority Queue: tree
Stack: array
Set: array
Map: