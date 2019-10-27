//
// Created by sebas on 6/10/19.
//
#pragma once

#ifndef FINAL_FIGHT_SEMAPHORE_H
#define FINAL_FIGHT_SEMAPHORE_H

#include <mutex>
#include <condition_variable>

class semaphore
{
public:
    explicit semaphore(unsigned int count) : m_count(count) {}
    semaphore(const semaphore&&) = delete;
    semaphore(semaphore&&) = delete;
    semaphore& operator = (const semaphore&) = delete;
    semaphore& operator = (semaphore&&) = delete;
    ~semaphore() = default;

    void post()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        ++m_count;
        m_cv.notify_one();
    }

    void wait()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cv.wait(lock, [&]{ return m_count > 0; });
        --m_count;
    }

private:
    std::mutex m_mutex;
    std::condition_variable m_cv;
    int m_count;
};

#endif //FINAL_FIGHT_SEMAPHORE_H
