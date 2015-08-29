/*** 
 *     _  __                ___      _                                   
 *     | |/ /___ ___ _ __   / __|__ _| |_ __                              
 *     | ' </ -_) -_) '_ \ | (__/ _` | | '  \
 *     |_|\_\___\___| .__/  \___\__,_|_|_|_|_|                            
 *                  |_|                                                   
 *                   _                                                    
 *      __ _ _ _  __| |                                                   
 *     / _` | ' \/ _` |                                                   
 *     \__,_|_||_\__,_|                                                   
 *                                                                        
 *      _                          _   _              _ _   _             
 *     | |   ___ __ _ _ _ _ _     /_\ | |__ _ ___ _ _(_) |_| |_  _ __  ___
 *     | |__/ -_) _` | '_| ' \   / _ \| / _` / _ \ '_| |  _| ' \| '  \(_-<
 *     |____\___\__,_|_| |_||_| /_/ \_\_\__, \___/_| |_|\__|_||_|_|_|_/__/
 *                                      |___/                             
 *     Yeah! Ravi let's do it! 
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <exception>

namespace algo {
    const int defaultQueueCapacity = 500;

    template <typename T>
        class Queue {
            public:
                Queue( int capacity = defaultQueueCapacity )
                    : _capacity { capacity }, _count { 0 },
                      _head { 0 }, _tail { -1 }, _elements { new T[_capacity] }
                { 
                }

                bool empty() const
                {
                    return ( _count == 0 );
                }

                int count() const
                {
                    return _count;
                }

                int capacity() const
                {
                    return _capacity;
                }

                void pop()
                {
                    if (empty())
                    {
                        return;
                    }
                    else { 
                        --_count;
                        ++_head;
                        if ( _head == _capacity ) {
                            _head = 0;
                        }
                    }
                }

                bool push( const T & obj )
                {
                    if ( _count == _capacity )
                    {
                        return false;
                    }
                    else {
                        ++_count;
                        ++_tail;
                        if ( _tail == _capacity )
                        {
                            _tail = 0;
                        }
                        _elements[_tail]  = obj;
                        return true;
                    }
                }

                const T & front() const
                {
                    if ( empty() ) throw empty_queue_exception;
                    return _elements[_head];
                }

            private:
                class EmptyQueueException : public std::exception {
                    virtual const char * what() const throw()
                    {
                        return "Queue is empty";
                    }
                } empty_queue_exception;

                int _capacity;
                int _count;
                int _head;
                int _tail;

                T * _elements;

                Queue( const Queue & );
                Queue & operator= ( const Queue & );

        }; //end of class queue

} //end of namespace algo

#endif //end of QUEUE_H
