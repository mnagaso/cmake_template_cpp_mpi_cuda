#include "class_template_wrapper.cuh"


// allocate memory on device
template <typename T>
void allocate_memory_on_device(T*& d_ptr, size_t size)
{
    cudaMalloc(&d_ptr, size * sizeof(T));
}

// deallocate memory on device
template <typename T>
void deallocate_memory_on_device(T*& d_ptr)
{
    cudaFree(d_ptr);
}

// copy memory from host to device
template <typename T>
void copy_host_to_device(T* d_ptr, T* h_ptr, size_t size)
{
    cudaMemcpy(d_ptr, h_ptr, size * sizeof(T), cudaMemcpyHostToDevice);
}

// copy memory from device to host
template <typename T>
void copy_device_to_host(T* h_ptr, T* d_ptr, size_t size)
{
    cudaMemcpy(h_ptr, d_ptr, size * sizeof(T), cudaMemcpyDeviceToHost);
}


// kernel function to add 2 to all elements of a vector
__global__ void add_2_to_all_elements_i_kernel(int* d_ptr, size_t size)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    if (i < size)
        d_ptr[i] += 4;
}

// integer
void add_2_to_all_elements_i(int* d_ptr, size_t size)
{
    add_2_to_all_elements_i_kernel<<<size / BLOCK_SIZE, BLOCK_SIZE>>>(d_ptr, size);
}