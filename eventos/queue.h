//
// Created by sebas on 6/10/19.
//

#ifndef FINAL_FIGHT_QUEUE_H
#define FINAL_FIGHT_QUEUE_H

#include <mutex>
#include "semaphore.h"

template<typename T>
class blocking_queue {
public:
    explicit blocking_queue(unsigned int size = 100)
            : m_size(size), m_pushIndex(0), m_popIndex(0), m_count(0),
              m_data((T *) operator new(size * sizeof(T))),
              m_fullSlots(0) {}

    blocking_queue(const blocking_queue &) = delete;

    blocking_queue(blocking_queue &&) = delete;

    blocking_queue &operator=(const blocking_queue &) = delete;

    blocking_queue &operator=(blocking_queue &&) = delete;

    ~blocking_queue() {
        while (m_count--) {
            m_data[m_popIndex].~T();
            m_popIndex = ++m_popIndex % m_size;
        }
        operator delete(m_data);
    }

    void push(const T &item) {
        {
            std::lock_guard<std::mutex> lock(m_cs);
            if(m_count + 1 > m_size) throw std::out_of_range("cola de procesamiento llena");
            new(m_data + m_pushIndex) T(item);
            m_pushIndex = ++m_pushIndex % m_size;
            ++m_count;
        }
        m_fullSlots.post();
    }

    T pop() {
        m_fullSlots.wait();

        T item;
        {
            std::lock_guard<std::mutex> lock(m_cs);
            item = m_data[m_popIndex];
            m_data[m_popIndex].~T();
            m_popIndex = ++m_popIndex % m_size;
            --m_count;
        }

        return item;
    }

    bool empty() {
        std::lock_guard<std::mutex> lock(m_cs);
        return m_count == 0;
    }

private:
    unsigned int m_size;
    unsigned int m_pushIndex;
    unsigned int m_popIndex;
    unsigned int m_count;
    T *m_data;

    semaphore m_fullSlots;
    std::mutex m_cs;
};

#endif //FINAL_FIGHT_QUEUE_H
