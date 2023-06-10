# `private`

## `reserve()`

This is a function that reserves a new capacity for a dynamic array, with the use of an allocator.

First, the function checks if the new capacity is less than or equal to the current capacity, in which case it simply returns without doing anything.

If the new capacity is greater than the current capacity, the function allocates memory for the new data using the allocator `_alloc`. It then constructs new objects of type `T` in the new memory using the copy constructor, by iterating through the old data `_data` and calling `construct` on each element of `_data` to initialize the corresponding element of `new_data`.

Next, the function destroys the objects in the old data using `destroy`, again iterating through `_data`. The objects are destroyed in reverse order of their construction, to ensure that any objects with dependencies on other objects are properly destroyed before their dependencies.

After destroying the objects in the old data, the function deallocates the old data using the allocator `_alloc`. It then updates the `_data` pointer to point to the new data, and sets `_capacity` to the new capacity.

Overall, this function ensures that the dynamic array is correctly resized and all objects are properly constructed and destroyed using the allocator.

When resizing a dynamic array using `reserve`, it's often more efficient to allocate a new block of memory and copy the old data to the new memory, rather than just appending new memory after the old data. This is because appending memory to the end of an existing block requires copying all of the old data to the new block, which can be expensive. By allocating a new block of memory and copying the old data to it, we avoid this cost.

Furthermore, the new block of memory might need to be larger than the old block in order to accommodate the new capacity. In this case, it's not possible to simply append memory to the end of the old block, since there may not be enough contiguous memory available. Instead, we need to allocate a new block of memory with the required capacity, and copy the old data to it.

`alloc.construct(&new_data[i], _data[i])` is used to construct a copy of an existing element `_data[i]` at a new memory location `&new_data[i]` using the allocator `alloc`.

This is a placement new operation that constructs an object in pre-allocated memory. The first argument is a pointer to the memory location where the object should be constructed, and the second argument is the value to be used to initialize the object.



# `public`

## `clear()`

The `clear()` function is a member function of a dynamic array class that deallocates all the memory occupied by the array and sets the size and capacity of the array to zero.

In the function, the `destroy()` function of the allocator is called to destruct all the objects in the array by invoking their destructors. Then, the `deallocate()` function of the allocator is used to deallocate the memory that was allocated to the array. Finally, the size and capacity of the array are set to zero and the pointer to the data is set to `nullptr`.

By calling the `destroy()` function, the function ensures that the destructors of all the objects in the array are properly invoked before deallocating the memory. This is necessary to prevent memory leaks and to release any resources that were acquired by the objects.