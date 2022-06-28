#include "class_template.h"

Class_template::Class_template()
{
    std::cout << "Class initialized." << std::endl;

    memory_allocation();

    add_2_i();
    add_2_d();

    print();
}

Class_template::~Class_template()
{
    std::cout << "Class destroyed." << std::endl;

    memory_deallocation();
}

void Class_template::print()
{
    // print arr_i and arr_d
    for (int i = 0; i < N; i++) {
        std::cout << arr_i[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < N; i++) {
        std::cout << arr_d[i] << " ";
    }
    std::cout << std::endl;

}

void Class_template::memory_allocation()
{
    // allocate N elements of type int to arr_i
    arr_i = new int[N];
    // allocate N elements of type double to arr_d
    arr_d = new double[N];

#ifdef USE_CUDA
    // allocate memory on device in class_template_wrapper.h
    gpu_data_ = new gpu_data;
    allocate_memory_on_device(gpu_data_->arr_i_device, N);
    allocate_memory_on_device(gpu_data_->arr_d_device, N);
#endif

    std::cout << "Memory allocated." << std::endl;

    // initialize arr_i arr_d
    for (int i = 0; i < N; i++) {
        arr_i[i] = 0;
        arr_d[i] = 0.0;
    }
}

void Class_template::memory_deallocation()
{
    // deallocate arr_i
    delete[] arr_i;
    // deallocate arr_d
    delete[] arr_d;

#ifdef USE_CUDA
    deallocate_memory_on_device(gpu_data_->arr_i_device);
    deallocate_memory_on_device(gpu_data_->arr_d_device);

    delete gpu_data_;
#endif

    std::cout << "Memory deallocated." << std::endl;
}

void Class_template::add_2_i()
{

#ifdef USE_CUDA
    copy_host_to_device(gpu_data_->arr_i_device, arr_i, N);
    add_2_to_all_elements_i(gpu_data_->arr_i_device, N);
    copy_device_to_host(arr_i, gpu_data_->arr_i_device, N);
#else
    for (int i = 0; i < N; i++) {
        arr_i[i] += 2;
    }
#endif

}

void Class_template::add_2_d()
{
    for (int i = 0; i < N; i++) {
        arr_d[i] += 2;
    }
}