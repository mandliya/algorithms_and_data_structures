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

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <exception>
#include <cstdint>

namespace algo {
    const uint32_t defaultCapacity = 500;

    template <typename T = uintptr_t>
    class Stack {
        public:
            Stack( uint32_t capacity = defaultCapacity )
                : _capacity{ capacity }, _size{ 0 }, _elements{ new T[_capacity] }
            {
            }

            Stack( const Stack & st )
                : _capacity{ st.capacity }, _size{ st._size }, _elements{ new T[_capacity] }
            {
                for(uint32_t i = 0; i < _capacity; ++i) {
                    _elements[i] = st._elements[i];
                }
            }

            bool empty()
            {
                return (_size == 0 );
            }

            void pop()
            {
                if (empty())
                    return;
                _size--;
            }

            void push( const T & obj ) {
                if ( _size == _capacity ) 
                    throw stack_out_of_bound_exception;
                _elements[_size++] = obj;
            }
            
            const T & top()
            {
                if (empty())
                    throw stack_empty_exception;
                return _elements[_size - 1];
            }

            uint32_t size()
            {
                return _size;
            }

            void print(std::ostream & out = std::cout)
            {
                for (int i = _size - 1; i >= 0; --i) {
                    out << _elements[i] << " ";
                }
                out << std::endl;
            }

           
        private:
            uint32_t _capacity;
            uint32_t _size;
            T * _elements;
            Stack & operator=(const Stack & st);
            
            class StackEmptyException : public std::exception {
                virtual const char *  what() const throw()
                {
                    return "Stack is empty";
                }
            } stack_empty_exception;

            class StackOutofBoundException : public std::exception {
                virtual const char * what() const throw()
                {
                    return "Stack Index out of bound";
                }
            } stack_out_of_bound_exception ;
            
    }; // end of class stack

} // end of namespace algo
#endif
