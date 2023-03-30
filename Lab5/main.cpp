// Name: Davids Jalisev
// Date: 31/03/2023
// Licence: GNU Public v3.0
// Huge help from Adam Mcguigan

#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <memory>
#include "SafeBuffer.h"

static const int num_threads = 10;
const int buffer_size = 20;

int char_count = 0;

std::random_device rd; // random used to seed the generator
std::mt19937 gen(rd());  // 
std::uniform_int_distribution<int> char_dist(0, 25); 
std::uniform_real_distribution<double> delay_dist(0, 1); 

// function to produce chars and add the to the buffer
void producer(std::shared_ptr<SafeBuffer<char>> buffer, int num_loops){
    for(int i = 0; i < num_loops; ++i) {
        char c = 'a' + char_dist(gen);
        
        {
            buffer->put(c); // add char to the buffer
        }

        std::cout << "Produced character: " << c << std::endl;

        std::this_thread::sleep_for(std::chrono::duration<double>(delay_dist(gen))); 
    }

    {
        buffer->put('X'); // add a terminating char to the buffer
    }
}

// func to consume the char from the buffer
void consumer(std::shared_ptr<SafeBuffer<char>> buffer)
{
    int count = 0; // keep track of num of char consumed
    while (true)
    {
        char c;
        {
            c = buffer->get(); // get from the buffer
        }

        std::cout << "Consumed character: " << c << std::endl;
        count++;

        if (c == 'X')
        {
            std::cout << "Reached end of buffer, exiting thread." << std::endl;
            char_count += count;
            break;
        }

        std::this_thread::sleep_for(std::chrono::duration<double>(delay_dist(gen)));
    }
}

int main(void)
{
    std::vector<std::thread> producer_threads(num_threads);
    std::vector<std::thread> consumer_threads(num_threads);

    std::shared_ptr<SafeBuffer<char>> buffer(new SafeBuffer<char>(buffer_size));

    // Launch the threads
    for(int i = 0; i < num_threads; i++)
    {
        producer_threads[i] = std::thread(producer, buffer, 10);
        consumer_threads[i] = std::thread(consumer, buffer);
    }

    // Join the threads with the main thread
    for (int i = 0; i < num_threads; i++)
    {
        producer_threads[i].join();
        consumer_threads[i].join();
    }

    std::cout << "Character count: " << char_count << std::endl;
    return 0;
}