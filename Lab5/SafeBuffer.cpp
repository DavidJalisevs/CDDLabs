// Name: Davids Jalisev
// Date: 31/03/2023
// Licence: GNU Public v3.0



#include "SafeBuffer.h"

template <typename T>
SafeBuffer<T>::SafeBuffer(int t_size) : 
    size(t_size),
    m_spaces(t_size),
    m_mutex(1),
    m_items(0)

{
}

//Producer will use this
template <typename T>
void SafeBuffer<T>::put(T item)
{
    // Wait until there is enough place in the Buffer
    m_spaces.Wait();

    // Wait that no one is currently writting to the buffer before continuing
    m_mutex.Wait();

    m_buffer.push_back(item);

    // Writting in buffer finish, we can free the mutex for other threads
    m_mutex.Signal();
    // This event can be free from the Buffer, thus, freeing for another thread
    m_items.Signal();
}

//Consumer will use this
template <typename T>
T SafeBuffer<T>::get()
{
    m_items.Wait();
    m_mutex.Wait();

    T c = m_buffer.front();
    m_buffer.erase(m_buffer.begin());

    m_mutex.Signal();
    m_spaces.Signal();

    return c;
}

template class SafeBuffer<char>;